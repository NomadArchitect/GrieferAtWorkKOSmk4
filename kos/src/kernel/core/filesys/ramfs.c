/* Copyright (c) 2019-2021 Griefer@Work                                       *
 *                                                                            *
 * This software is provided 'as-is', without any express or implied          *
 * warranty. In no event will the authors be held liable for any damages      *
 * arising from the use of this software.                                     *
 *                                                                            *
 * Permission is granted to anyone to use this software for any purpose,      *
 * including commercial applications, and to alter it and redistribute it     *
 * freely, subject to the following restrictions:                             *
 *                                                                            *
 * 1. The origin of this software must not be misrepresented; you must not    *
 *    claim that you wrote the original software. If you use this software    *
 *    in a product, an acknowledgement (see the following) in the product     *
 *    documentation is required:                                              *
 *    Portions Copyright (c) 2019-2021 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef GUARD_KERNEL_CORE_FILESYS_RAMFS_C
#define GUARD_KERNEL_CORE_FILESYS_RAMFS_C 1
#define _KOS_SOURCE 1
#define _GNU_SOURCE 1

#include <kernel/compiler.h>

#include <kernel/driver.h>
#include <kernel/fs/allnodes.h>
#include <kernel/fs/clnknode.h>
#include <kernel/fs/devfs.h>
#include <kernel/fs/filesys.h>
#include <kernel/fs/node.h>
#include <kernel/fs/ramfs.h>
#include <kernel/fs/super.h>
#include <kernel/paging.h>
#include <kernel/user.h>
#include <sched/task.h>

#include <hybrid/atomic.h>

#include <kos/except.h>
#include <kos/except/reason/fs.h>
#include <kos/except/reason/inval.h>
#include <linux/magic.h>

#include <assert.h>
#include <stddef.h>
#include <string.h>

#undef RBTREE_LEFT_LEANING
#define RBTREE_WANT_PREV_NEXT_NODE
#define RBTREE_OMIT_LOCATE
#define RBTREE_OMIT_REMOVE
#define RBTREE(name)               ramfs_direnttree_##name
#define RBTREE_T                   struct ramfs_dirent
#define RBTREE_Tkey                USER CHECKED char const *
#define RBTREE_GETNODE(self)       (self)->rde_treenode
#define RBTREE_GETKEY(self)        (self)->rde_ent.fd_name
#define RBTREE_ISRED(self)         (self)->rde_isred
#define RBTREE_SETRED(self)        (void)((self)->rde_isred = 1)
#define RBTREE_SETBLACK(self)      (void)((self)->rde_isred = 0)
#define RBTREE_FLIPCOLOR(self)     (void)((self)->rde_isred ^= -1)
#define RBTREE_COPYCOLOR(dst, src) (void)((dst)->rde_isred = (src)->rde_isred)
#define RBTREE_CC                  FCALL
#define RBTREE_NOTHROW             NOTHROW
#define RBTREE_DECL                FUNDEF
#define RBTREE_IMPL                PUBLIC
#define RBTREE_KEY_EQ(a, b)        (strcmp(a, b) == 0)
#define RBTREE_KEY_NE(a, b)        (strcmp(a, b) != 0)
#define RBTREE_KEY_LO(a, b)        (strcmp(a, b) < 0)
#define RBTREE_KEY_LE(a, b)        (strcmp(a, b) <= 0)
#define RBTREE_KEY_GR(a, b)        (strcmp(a, b) > 0)
#define RBTREE_KEY_GE(a, b)        (strcmp(a, b) >= 0)
#include <hybrid/sequence/rbtree-abi.h>

DECL_BEGIN


PUBLIC struct flnknode_ops const ramfs_lnknode_ops = {
	.lno_node = {
		.no_file = {
			.mo_destroy = &ramfs_lnknode_v_destroy,
			.mo_changed = &fnode_v_changed,
		},
		.no_wrattr = &ramfs_lnknode_v_wrattr,
	},
	.lno_readlink = &ramfs_lnknode_v_readlink,
	.lno_linkstr  = &ramfs_lnknode_v_linkstr,
};

PUBLIC struct fregnode_ops const ramfs_regnode_ops = {
	.rno_node = {
		.no_file = {
			.mo_destroy = &ramfs_regnode_v_destroy,
			.mo_changed = &fnode_v_changed,
		},
		.no_wrattr = &ramfs_regnode_v_wrattr,
	},
};

PRIVATE struct mfile_stream_ops const ramfs_devnode_stream_ops = {
	.mso_open = &ramfs_devnode_v_open,
};
PUBLIC struct fdevnode_ops const ramfs_devnode_ops = {
	.dno_node = {
		.no_file = {
			.mo_destroy = &ramfs_devnode_v_destroy,
			.mo_changed = &fnode_v_changed,
			.mo_stream  = &ramfs_devnode_stream_ops,
		},
		.no_wrattr = &ramfs_devnode_v_wrattr,
	},
};


PRIVATE struct mfile_stream_ops const ramfs_fifonode_stream_ops = {
	.mso_open     = &ramfs_fifonode_v_open,
	.mso_read     = &ramfs_fifonode_v_read,
	.mso_readv    = &ramfs_fifonode_v_readv,
	.mso_write    = &ramfs_fifonode_v_write,
	.mso_writev   = &ramfs_fifonode_v_writev,
	.mso_truncate = &ramfs_fifonode_v_truncate,
	.mso_stat     = &ramfs_fifonode_v_stat,
	.mso_hop      = &ramfs_fifonode_v_hop,
};
PUBLIC struct ffifonode_ops const ramfs_fifonode_ops = {
	.fno_node = {
		.no_file = {
			.mo_destroy = &ramfs_fifonode_v_destroy,
			.mo_changed = &fnode_v_changed,
			.mo_stream  = &ramfs_fifonode_stream_ops,
		},
		.no_wrattr = &ramfs_fifonode_v_wrattr,
	},
};


PRIVATE struct mfile_stream_ops const ramfs_socknode_stream_ops = {
	.mso_open = &ramfs_socknode_v_open,
};
PUBLIC struct fsocknode_ops const ramfs_socknode_ops = {
	.suno_node = {
		.no_file = {
			.mo_destroy = &ramfs_socknode_v_destroy,
			.mo_changed = &fnode_v_changed,
			.mo_stream  = &ramfs_socknode_stream_ops,
		},
		.no_wrattr = &ramfs_socknode_v_wrattr,
	},
};



/* Directory entry operators for instances of `ramfs_dirent' */
PUBLIC struct fdirent_ops const ramfs_dirent_ops = {
	.fdo_destroy  = &ramfs_dirent_v_destroy,
	.fdo_opennode = &ramfs_dirent_v_opennode,
};

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL ramfs_dirent_v_destroy)(struct fdirent *__restrict self) {
	struct ramfs_dirent *me;
	me = container_of(self, struct ramfs_dirent, rde_ent);
	decref(me->rde_node);
	kfree(me);
}

PUBLIC ATTR_RETNONNULL WUNUSED NONNULL((1, 2)) REF struct fnode *
NOTHROW(KCALL ramfs_dirent_v_opennode)(struct fdirent *__restrict self,
                                       struct fdirnode *__restrict UNUSED(dir)) {
	struct ramfs_dirent *me;
	me = container_of(self, struct ramfs_dirent, rde_ent);
	return (REF struct fnode *)incref(me->rde_node);
}



/* Directory enumeration operators for `struct ramfs_direnum' */
PUBLIC struct fdirenum_ops const ramfs_direnum_ops = {
	.deo_fini    = &ramfs_direnum_v_fini,
	.deo_getdir  = &ramfs_direnum_v_getdir,
	.deo_readdir = &ramfs_direnum_v_readdir,
	.deo_seekdir = &ramfs_direnum_v_seekdir,
};

PUBLIC NOBLOCK NONNULL((1)) void
NOTHROW(KCALL ramfs_direnum_v_fini)(struct fdirenum *__restrict self) {
	struct ramfs_direnum *me = (struct ramfs_direnum *)self;
	axref_fini(&me->rde_next);
	decref(me->rde_dir);
}

PUBLIC ATTR_RETNONNULL WUNUSED NONNULL((1)) REF struct fdirnode *
NOTHROW(KCALL ramfs_direnum_v_getdir)(struct fdirenum *__restrict self) {
	struct ramfs_direnum *me = (struct ramfs_direnum *)self;
	return mfile_asdir(incref(me->rde_dir));
}



/* Given a dirent `self' that has been deleted (RAMFS_DIRENT_TREENODE_DELETED),
 * return a pointer  to the first  dirent in `dir'  that has a  lexicographical
 * order `>= self'. The caller must be holding `dir->rdn_dat.rdd_treelock' */
PUBLIC NOBLOCK WUNUSED NONNULL((1, 2)) struct ramfs_dirent *
NOTHROW(FCALL ramfs_dirent_fixdeleted)(struct ramfs_dirent *__restrict self,
                                       struct ramfs_dirnode *__restrict dir) {
	struct ramfs_dirent *result = NULL;
	struct ramfs_dirent *root;
	assert(self->rde_treenode.rb_lhs == RAMFS_DIRENT_TREENODE_DELETED);
	root = dir->rdn_dat.rdd_tree;
	/* Check for special case: directory has been deleted. */
	if likely(root != RAMFS_DIRDATA_TREE_DELETED) {
		while (root) {
			int cmp = strcmpz(root->rde_ent.fd_name,
			                  self->rde_ent.fd_name,
			                  self->rde_ent.fd_namelen);
			if (cmp >= 0) {
				result = root;
				root   = root->rde_treenode.rb_lhs;
			} else {
				root = root->rde_treenode.rb_rhs;
			}
		}
	}
	return result;
}

/* Returns `NULL' if there is no next node */
PRIVATE WUNUSED NONNULL((1, 2)) REF struct ramfs_dirent *KCALL
ramfs_dirent_next(struct ramfs_dirent *__restrict self,
                  struct ramfs_dirnode *__restrict dir)
		THROWS(...) {
	REF struct ramfs_dirent *result;
	shared_rwlock_read(&dir->rdn_dat.rdd_treelock);
	COMPILER_READ_BARRIER();
	/* Check for special case: `self' was deleted. */
	if unlikely(self->rde_treenode.rb_lhs == RAMFS_DIRENT_TREENODE_DELETED) {
		/* Next node is the closest life entry with a name `>= self' */
		result = ramfs_dirent_fixdeleted(self, dir);
	} else {
		assert(dir->rdn_dat.rdd_tree != RAMFS_DIRDATA_TREE_DELETED);
		/* Return a reference to the next node within the tree. */
		result = ramfs_direnttree_nextnode(self);
	}
	xincref(result);
	shared_rwlock_endread(&dir->rdn_dat.rdd_treelock);
	return result;
}

PUBLIC NONNULL((1)) size_t KCALL
ramfs_direnum_v_readdir(struct fdirenum *__restrict self, USER CHECKED struct dirent *buf,
                        size_t bufsize, readdir_mode_t readdir_mode, iomode_t mode)
		THROWS(...) {
	ssize_t result;
	REF struct ramfs_dirent *ent;
	struct ramfs_direnum *me = (struct ramfs_direnum *)self;
again:
	ent = axref_get(&me->rde_next);
	if (!ent)
		return 0; /* End of directory */
	{
		REF struct ramfs_dirent *next;
		FINALLY_DECREF_UNLIKELY(ent);
		/* Feed the entry to the user-buffer */
		result = fdirenum_feedent(buf, bufsize, readdir_mode,
		                          ent->rde_ent.fd_ino,
		                          ent->rde_ent.fd_type,
		                          ent->rde_ent.fd_namelen,
		                          ent->rde_ent.fd_name);
		if (result < 0)
			return (size_t)~result; /* Don't advance directory position. */

		/* Advance the enumerator to the next entry. */
		next = ramfs_dirent_next(ent, me->rde_dir);
		if (!axref_cmpxch_inherit_new(&me->rde_next, ent, next)) {
			/* Race condition: some other thread modified our `rde_next' before
			 * we were able to modify it. As such, we must re-attempt the read. */
			xdecref_unlikely(next); /* Reference _NOT_ inherited by `axref_cmpxch_inherit_new()' */
			goto again;
		}
	}
	return (size_t)result;
}

PRIVATE ATTR_PURE WUNUSED NONNULL((1)) size_t
NOTHROW(FCALL ramfs_dirent_tree_count)(struct ramfs_dirent const *__restrict self) {
	size_t result = 0;
again:
	++result;
	if (self->rde_treenode.rb_lhs) {
		if (self->rde_treenode.rb_rhs)
			result += ramfs_dirent_tree_count(self->rde_treenode.rb_rhs);
		self = self->rde_treenode.rb_lhs;
		goto again;
	}
	if (self->rde_treenode.rb_rhs) {
		self = self->rde_treenode.rb_rhs;
		goto again;
	}
	return result;
}

/* Return the # of directory entries within `self'. Caller must be holding the lock. */
PRIVATE ATTR_PURE WUNUSED NONNULL((1)) size_t
NOTHROW(FCALL ramfs_dir_count_entries)(struct ramfs_dirnode const *__restrict self) {
	size_t result = 0;
	struct ramfs_dirent const *root;
	root = self->rdn_dat.rdd_tree;
	if (root != NULL && root != RAMFS_DIRDATA_TREE_DELETED)
		result = ramfs_dirent_tree_count(root);
	return result;
}

PUBLIC NONNULL((1)) pos_t KCALL
ramfs_direnum_v_seekdir(struct fdirenum *__restrict self,
                        off_t offset, unsigned int whence)
		THROWS(...) {
	pos_t result;
	REF struct ramfs_dirent *oldent;
	REF struct ramfs_dirent *newent;
	struct ramfs_direnum *me  = (struct ramfs_direnum *)self;
	struct ramfs_dirnode *dir = me->rde_dir;
again:
	oldent = axref_get(&me->rde_next);
	TRY {
		shared_rwlock_write(&dir->rdn_dat.rdd_treelock);
	} EXCEPT {
		xdecref_unlikely(oldent);
		RETHROW();
	}
	switch (whence) {

	case SEEK_SET: {
		result = 0;
		newent = dir->rdn_dat.rdd_tree;
		if unlikely(newent == RAMFS_DIRDATA_TREE_DELETED) {
			newent = NULL;
		} else if (newent != NULL) {
			pos_t delta = (pos_t)offset;
			while (newent->rde_treenode.rb_lhs)
				newent = newent->rde_treenode.rb_lhs;
			while (delta--) {
				newent = ramfs_direnttree_nextnode(newent);
				++result;
				if (!newent)
					break;
			}
		}
	}	break;

	case SEEK_CUR: {
		newent = oldent;
		/* Fix deleted nodes. */
		if (newent->rde_treenode.rb_lhs == RAMFS_DIRENT_TREENODE_DELETED)
			newent = ramfs_dirent_fixdeleted(newent, dir);
do_seek_cur:
		if (offset <= 0) {
			struct ramfs_dirent *pred;
			pos_t delta = (pos_t)-offset;
			if (!newent) {
				/* Old position is at the end of the directory. */
				if (delta == 0)
					goto do_seek_end; /* Stay at end of directory. */
				newent = dir->rdn_dat.rdd_tree;
				if unlikely(newent == NULL ||
				            newent == RAMFS_DIRDATA_TREE_DELETED) {
					/* Directory is empty (or was deleted) */
					newent = NULL;
					result = 0;
					break;
				}
				while (newent->rde_treenode.rb_rhs)
					newent = newent->rde_treenode.rb_rhs;
				--delta; /* Because `newent' currently points at the last entry (rather than at the end) */
			}
			/* Seek backwards */
			while (delta--) {
				pred = ramfs_direnttree_prevnode(newent);
				if (!pred)
					break;
				newent = pred;
			}

			/* Set `result = NUMBER_OF_NODES_BEFORE(newent)' */
			for (result = 0, pred = newent;;) {
				pred = ramfs_direnttree_prevnode(pred);
				if (!pred)
					break;
				++result;
			}
		} else {
			struct ramfs_dirent *pred;
			pos_t delta = (pos_t)offset;
			/* Positive seek offset.
			 * Start by counting the # of nodes leading up to `newent' */
			for (result = 0, pred = newent;;) {
				pred = ramfs_direnttree_prevnode(pred);
				if (!pred)
					break;
				++result;
			}

			/* Now advance `delta' times (but stop if we reach the end) */
			do {
				++result;
				newent = ramfs_direnttree_nextnode(newent);
			} while (newent && --delta);
		}
	}	break;

do_seek_end:
	case SEEK_END: {
		if (offset >= 0) {
			/* Set `newent = NULL' and count the # of entries in the directory. */
			newent = NULL;
			result = (pos_t)ramfs_dir_count_entries(dir);
		} else {
			/* Seek relative to the end of the directory. */
			newent = NULL;
			goto do_seek_cur;
		}
	}	break;

	default:
		shared_rwlock_endwrite(&dir->rdn_dat.rdd_treelock);
		xdecref_unlikely(oldent);
		THROW(E_INVALID_ARGUMENT_UNKNOWN_COMMAND,
		      E_INVALID_ARGUMENT_CONTEXT_LSEEK_WHENCE,
		      whence);
		break;
	}
	xincref(newent);
	shared_rwlock_endwrite(&dir->rdn_dat.rdd_treelock);
	xdecref_unlikely(oldent); /* Returned by `axref_get()' */
	if (!axref_cmpxch_inherit_new(&me->rde_next, oldent, newent)) {
		xdecref_unlikely(newent); /* Not inherited on cmpxch failure. */
		goto again;
	}
	return result;
}


PUBLIC ATTR_PURE WUNUSED struct ramfs_dirent *FCALL
ramfs_direnttree_locate(/*nullable*/ struct ramfs_dirent *root,
                        USER CHECKED char const *key,
                        size_t keylen) THROWS(E_SEGFAULT) {
	while (root) {
		int cmp = strcmpz(root->rde_ent.fd_name, key, keylen);
		if (cmp > 0) {
			root = root->rde_treenode.rb_lhs;
			continue;
		}
		if (cmp < 0) {
			root = root->rde_treenode.rb_rhs;
			continue;
		}
		break;
	}
	return root;
}

PUBLIC ATTR_PURE WUNUSED NONNULL((1)) struct ramfs_dirent *FCALL
_ramfs_direnttree_caselocate(struct ramfs_dirent *__restrict root,
                             USER CHECKED char const *key, size_t keylen)
		THROWS(E_SEGFAULT) {
again:
	if (root->rde_ent.fd_namelen == keylen &&
	    memcasecmp(root->rde_ent.fd_name, key, keylen * sizeof(char)) == 0)
		return root;

	if (root->rde_treenode.rb_lhs) {
		if (root->rde_treenode.rb_rhs) {
			struct ramfs_dirent *result;
			result = _ramfs_direnttree_caselocate(root->rde_treenode.rb_rhs,
			                                      key, keylen);
			if (result)
				return result;
		}
		root = root->rde_treenode.rb_lhs;
		goto again;
	}
	if (root->rde_treenode.rb_rhs) {
		root = root->rde_treenode.rb_rhs;
		goto again;
	}
}


/* Directory operators for `struct ramfs_dirnode' */
PUBLIC struct fdirnode_ops const ramfs_dirnode_ops = {
	.dno_node = {
		.no_file = {
			.mo_destroy = &ramfs_dirnode_v_destroy,
			.mo_changed = &fnode_v_changed,
		},
		.no_wrattr = &ramfs_dirnode_v_wrattr,
	},
	.dno_lookup       = &ramfs_dirnode_v_lookup,
	.dno_lookup_fnode = &ramfs_dirnode_v_lookup_fnode,
	.dno_enum         = &ramfs_dirnode_v_enum,
	.dno_mkfile       = &ramfs_dirnode_v_mkfile,
	.dno_unlink       = &ramfs_dirnode_v_unlink,
	.dno_rename       = &ramfs_dirnode_v_rename,
};

PRIVATE WUNUSED NONNULL((1, 2)) struct ramfs_dirent *KCALL
ramfs_dirdata_lookup(struct ramfs_dirnode *__restrict self,
                     struct flookup_info *__restrict info) {
	struct ramfs_dirent *result;
	assert(self->rdn_dat.rdd_tree != RAMFS_DIRDATA_TREE_DELETED);
	result = ramfs_direnttree_locate(self->rdn_dat.rdd_tree,
	                                 info->flu_name,
	                                 info->flu_namelen);
	if (!result) {
		if ((info->flu_flags & FS_MODE_FDOSPATH) && self->rdn_dat.rdd_tree) {
			/* Do a case-insensitive search */
			result = _ramfs_direnttree_caselocate(self->rdn_dat.rdd_tree,
			                                      info->flu_name,
			                                      info->flu_namelen);
		}
	}
	return result;
}

PUBLIC WUNUSED NONNULL((1, 2)) REF struct fdirent *KCALL
ramfs_dirnode_v_lookup(struct fdirnode *__restrict self,
                       struct flookup_info *__restrict info) {
	struct ramfs_dirent *result;
	struct ramfs_dirnode *me;
	me = (struct ramfs_dirnode *)self;
	shared_rwlock_read(&me->rdn_dat.rdd_treelock);
	FINALLY_ENDREAD(&me->rdn_dat.rdd_treelock);
	if (me->rdn_dat.rdd_tree == RAMFS_DIRDATA_TREE_DELETED)
		return NULL; /* Directory was deleted. */
	result = ramfs_dirdata_lookup(me, info);
	return xincref(&result->rde_ent);
}

PUBLIC NONNULL((1, 2)) void KCALL
ramfs_dirnode_v_enum(struct fdirnode *__restrict self,
                     struct fdirenum *__restrict result) {
	struct ramfs_dirdata *me;
	struct ramfs_direnum *rt;
	me = &((struct ramfs_dirnode *)self)->rdn_dat;
	rt = (struct ramfs_direnum *)result;
	/* Fill in information */
	shared_rwlock_read(&me->rdd_treelock);
	if (me->rdd_tree != NULL &&
	    me->rdd_tree != RAMFS_DIRDATA_TREE_DELETED) {
		struct ramfs_dirent *ent;
		/* Start enumeration at the left-most node */
		ent = me->rdd_tree;
		while (ent->rde_treenode.rb_lhs)
			ent = ent->rde_treenode.rb_lhs;
		incref(ent);
		shared_rwlock_endread(&me->rdd_treelock);
		axref_init(&rt->rde_next, ent);
	} else {
		shared_rwlock_endread(&me->rdd_treelock);
		axref_init(&rt->rde_next, NULL);
	}
	rt->rde_ops = &ramfs_direnum_ops;
	rt->rde_dir = (REF struct ramfs_dirnode *)incref(self);
}


/* Construct a new fully initialized, but not globally visible, as in:
 *   - return->fn_supent.rb_lhs == FSUPER_NODES_DELETED;
 *   - !LIST_ISBOUND(return, fn_allnodes);
 * ... node for use by ramfs file systems and return it.
 * When `(info->mkf_fmode & S_IFMT) == 0', blindly re-return `info->mkf_hrdlnk.hl_node'
 *
 * The  caller can always  assume that the  returned file-node can be
 * decref'd normally for the  purpose of (possible) destruction,  and
 * that `(info->mkf_fmode & S_IFMT) != 0' implies `!isshared(return)' */
PUBLIC ATTR_RETNONNULL WUNUSED NONNULL((1, 2)) REF struct fnode *KCALL
ramfs_dirnode_mknode_frominfo(struct fdirnode *__restrict self,
                              struct fmkfile_info *__restrict info)
		THROWS(E_FSERROR_UNSUPPORTED_OPERATION) {
	REF struct fnode *result;

	/* Allocate the new file-node */
	switch (info->mkf_fmode & S_IFMT) {

	case 0: /* Special case: hard-link */
		return (REF struct fnode *)incref(info->mkf_hrdlnk.hl_node);

	case S_IFDIR: {
		struct ramfs_dirnode *node;
		node = (struct ramfs_dirnode *)kmalloc(sizeof(struct ramfs_dirnode), GFP_NORMAL);
		_fdirnode_init(node, &ramfs_dirnode_ops, self);
		shared_rwlock_init(&node->rdn_dat.rdd_treelock);
		node->rdn_dat.rdd_tree = NULL;
		result               = node;
	}	break;

	case S_IFCHR:
	case S_IFBLK: {
		struct fdevnode *node;
		node = (struct fdevnode *)kmalloc(sizeof(struct fdevnode), GFP_NORMAL);
		_fdevnode_init(node, &ramfs_devnode_ops, self->fn_super);
		node->dn_devno = info->mkf_creat.c_rdev;
		result = node;
	}	break;

	case S_IFREG: {
		struct fregnode *node;
		node = (struct fregnode *)kmalloc(sizeof(struct fregnode), GFP_NORMAL);
		_fregnode_init(node, &ramfs_regnode_ops, self->fn_super);
		atomic64_init(&node->mf_filesize, 0);
		result = node;
	}	break;

	case S_IFLNK:
		result = _fclnknode_new(self->fn_super,
		                          info->mkf_creat.c_symlink.s_text,
		                          info->mkf_creat.c_symlink.s_size);
		result->mf_ops = &ramfs_lnknode_ops.lno_node.no_file;
		break;

	case S_IFIFO: {
		struct ffifonode *node;
		node = (struct ffifonode *)kmalloc(sizeof(struct ffifonode), GFP_NORMAL);
		_ffifonode_init(node, &ramfs_fifonode_ops, self->fn_super);
		result = node;
	}	break;

	case S_IFSOCK: {
		struct fsocknode *node;
		node = (struct fsocknode *)kmalloc(sizeof(struct fsocknode), GFP_NORMAL);
		_fsocknode_init(node, &ramfs_socknode_ops, self->fn_super);
		result = node;
	}	break;

	default:
		THROW(E_FSERROR_UNSUPPORTED_OPERATION);
		break;
	}

	/* skew_kernel_pointer() guaranties  that the  least significant  3 bits  are
	 * unmodified, and `devfs_devnode_makeino()' is designed to set those 3  bits
	 * to all 1s. This way we prevent possible collisions between the  namespaces
	 * within devfs (following the assumption that at least the least significant
	 * bit should be `0' for `new_node' as the result of alignment). */
	result->fn_ino = (ino_t)skew_kernel_pointer(result);
	assertf(((uintptr_t)result->fn_ino & 7) != 7, "%p", result);

	/* Fill in generic file-creation information. */
	result->fn_mode  = info->mkf_fmode;
	result->mf_atime = info->mkf_creat.c_atime;
	result->mf_mtime = info->mkf_creat.c_mtime;
	result->mf_ctime = info->mkf_creat.c_ctime;
	result->fn_uid   = info->mkf_creat.c_owner;
	result->fn_gid   = info->mkf_creat.c_group;
	result->fn_nlink = 1;
	LIST_ENTRY_UNBOUND_INIT(&result->fn_allnodes);
	result->fn_supent.rb_lhs = FSUPER_NODES_DELETED;
	return result;
}



PUBLIC NONNULL((1, 2)) void KCALL
ramfs_dirnode_v_mkfile(struct fdirnode *__restrict self,
                       struct fmkfile_info *__restrict info)
		THROWS(E_FSERROR_ILLEGAL_PATH, E_FSERROR_DISK_FULL,
		       E_FSERROR_READONLY, E_FSERROR_TOO_MANY_HARD_LINKS,
		       E_FSERROR_UNSUPPORTED_OPERATION, E_FSERROR_DELETED) {
	struct ramfs_dirent *old_dirent;
	REF struct ramfs_dirent *new_dirent;
	REF struct fnode *new_node;
	struct ramfs_dirnode *me;
	me = (struct ramfs_dirnode *)self;

#ifndef __OPTIMIZE_SIZE__
	shared_rwlock_read(&me->rdn_dat.rdd_treelock);
	/* Check for an existing file before doing any allocations */
	TRY {
		if unlikely(me->rdn_dat.rdd_tree == RAMFS_DIRDATA_TREE_DELETED)
			THROW(E_FSERROR_DELETED, E_FILESYSTEM_DELETED_PATH);
		old_dirent = ramfs_dirdata_lookup(me, &info->mkf_lookup_info);
	} EXCEPT {
		shared_rwlock_endread(&me->rdn_dat.rdd_treelock);
		RETHROW();
	}
	if unlikely(old_dirent) {
		info->mkf_dent = incref(&old_dirent->rde_ent);
		shared_rwlock_endread(&me->rdn_dat.rdd_treelock);
		info->mkf_rnode = (REF struct fnode *)incref(old_dirent->rde_node);
		info->mkf_flags |= FMKFILE_F_EXISTS;
		return;
	}
	shared_rwlock_endread(&me->rdn_dat.rdd_treelock);
#endif /* !__OPTIMIZE_SIZE__ */

	/* Allocate the new file-node */
	new_node = ramfs_dirnode_mknode_frominfo(self, info);

	/* Construct the new directory entry. */
	TRY {
		new_dirent = (REF struct ramfs_dirent *)kmalloc(offsetof(struct ramfs_dirent, rde_ent.fd_name) +
		                                                (info->mkf_namelen + 1) * sizeof(char),
		                                                GFP_NORMAL);
		TRY {
			/* Fill in the new directory entry. */
			*(char *)mempcpy(new_dirent->rde_ent.fd_name, info->mkf_name,
			                 info->mkf_namelen, sizeof(char)) = '\0';

			/* Fill in other fields of the new directory entry. */
			if (info->mkf_hash == FLOOKUP_INFO_HASH_UNSET) {
				info->mkf_hash = fdirent_hash(new_dirent->rde_ent.fd_name,
				                              new_dirent->rde_ent.fd_namelen);
			}
			new_dirent->rde_ent.fd_refcnt  = 2; /* +1: info->mkf_dent, +1: me->rdn_dat.rdd_tree */
			new_dirent->rde_ent.fd_ops     = &ramfs_dirent_ops;
			new_dirent->rde_ent.fd_hash    = info->mkf_hash;
			new_dirent->rde_ent.fd_ino     = new_node->fn_ino;
			new_dirent->rde_ent.fd_namelen = info->mkf_namelen;
			new_dirent->rde_ent.fd_type    = IFTODT(info->mkf_fmode);
			new_dirent->rde_node           = new_node;

			/* Insert the new file */
again_acquire_lock_for_insert:
			shared_rwlock_write(&me->rdn_dat.rdd_treelock);
			if unlikely(ATOMIC_READ(me->rdn_dat.rdd_tree) == RAMFS_DIRDATA_TREE_DELETED)
				THROW(E_FSERROR_DELETED, E_FILESYSTEM_DELETED_PATH);
			old_dirent = ramfs_direnttree_locate(me->rdn_dat.rdd_tree,
			                                       new_dirent->rde_ent.fd_name,
			                                       new_dirent->rde_ent.fd_namelen);
			if (!old_dirent && (info->mkf_flags & FMKFILE_F_NOCASE) && me->rdn_dat.rdd_tree) {
				/* Do a case-insensitive search */
				old_dirent = _ramfs_direnttree_caselocate(me->rdn_dat.rdd_tree,
				                                           new_dirent->rde_ent.fd_name,
				                                           new_dirent->rde_ent.fd_namelen);
			}
			if unlikely(old_dirent) {
				/* Special case: file already exists. */
				incref(&old_dirent->rde_ent);
				shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
				kfree(new_dirent);
				decref_likely(new_node);
				info->mkf_dent  = &old_dirent->rde_ent;
				info->mkf_rnode = (REF struct fnode *)incref(old_dirent->rde_node);
				info->mkf_flags |= FMKFILE_F_EXISTS;
				return;
			}

			if ((info->mkf_fmode & S_IFMT) != 0) {
				struct fsuper *super = self->fn_super;
				/* At this point, the following fields of `new_node' are still unbound:
				 *  - new_node->fn_allnodes
				 *  - new_node->fn_supent */
				assert(!LIST_ISBOUND(new_node, fn_allnodes));
				assert(new_node->fn_supent.rb_lhs == FSUPER_NODES_DELETED);
				assert(!(new_node->mf_flags & MFILE_FN_GLOBAL_REF));
				assert(new_node->mf_flags & MFILE_F_PERSISTENT);
				assert(new_node->mf_refcnt == 1);
				if (!fsuper_nodes_trywrite(super)) {
					shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
					while (!fsuper_nodes_canwrite(super))
						task_yield();
					goto again_acquire_lock_for_insert;
				}
				if (!fallnodes_tryacquire()) {
					fsuper_nodes_endwrite(super);
					shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
					while (!fallnodes_available())
						task_yield();
					goto again_acquire_lock_for_insert;
				}
				new_node->mf_flags |= MFILE_FN_GLOBAL_REF;
				new_node->mf_refcnt += 1; /* For `MFILE_FN_GLOBAL_REF' */
				COMPILER_BARRIER();

				/* Make the newly created node globally visible. */
				fsuper_nodes_insert(super, new_node);
				LIST_INSERT_HEAD(&fallnodes_list, new_node, fn_allnodes);

				/* Release locks. */
				fallnodes_release();
				fsuper_nodes_endwrite(super);
			} else {
				/* Hard link -> increment the nlink counter */
				mfile_tslock_acquire(new_node);
				ATOMIC_INC(new_node->fn_nlink);
				mfile_tslock_release(new_node);
			}

			/* Construct missing references for `new_dirent' */
			incref(new_node); /* For `new_dirent->rde_node' (or `info->mkf_rnode', depending on view) */

			/* Insert the new directory entry. */
			ramfs_direnttree_insert(&me->rdn_dat.rdd_tree, new_dirent); /* Inherit reference */

			/* And with that, the "file" has been created! */
			shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
		} EXCEPT {
			kfree(new_dirent);
			RETHROW();
		}
	} EXCEPT {
		decref_likely(new_node);
		RETHROW();
	}
	info->mkf_dent  = &new_dirent->rde_ent; /* Inherit reference */
	info->mkf_rnode = new_node;             /* Inherit reference */
}

PUBLIC NONNULL((1, 2, 3)) void KCALL
ramfs_dirnode_v_unlink(struct fdirnode *__restrict self,
                       struct fdirent *__restrict entry,
                       struct fnode *__restrict file)
		THROWS(E_FSERROR_DIRECTORY_NOT_EMPTY,
		       E_FSERROR_READONLY, E_FSERROR_DELETED) {
	struct ramfs_dirent *known_entry;
	struct ramfs_dirnode *me = (struct ramfs_dirnode *)self;
again:
	shared_rwlock_write(&me->rdn_dat.rdd_treelock);
	if unlikely(me->rdn_dat.rdd_tree == RAMFS_DIRDATA_TREE_DELETED) {
		shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
		THROW(E_FSERROR_DELETED, E_FILESYSTEM_DELETED_PATH);
	}
	/* Check that `entry' is still correct. */
	known_entry = ramfs_direnttree_locate(me->rdn_dat.rdd_tree,
	                                      entry->fd_name,
	                                      entry->fd_namelen);
	if unlikely(&known_entry->rde_ent != entry) {
		shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
		THROW(E_FSERROR_DELETED, E_FILESYSTEM_DELETED_FILE);
	}
	/* When `file' is a directory, we must interlock setting its tree
	 * to `RAMFS_DIRDATA_TREE_DELETED' with the removal of its entry. */
	if (fnode_isdir(file)) {
		struct ramfs_dirnode *filedir;
		assert(mfile_isanon(file));
		assert(file->fn_nlink == 1);
		assert(file->mf_ops == &ramfs_dirnode_ops.dno_node.no_file);
		filedir = (struct ramfs_dirnode *)mfile_asdir(file);
		assert(filedir != self);
		if (!shared_rwlock_trywrite(&filedir->rdn_dat.rdd_treelock)) {
			shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
			shared_rwlock_write(&filedir->rdn_dat.rdd_treelock);
			shared_rwlock_endwrite(&filedir->rdn_dat.rdd_treelock);
			goto again;
		}
		/* Assert that `file' is an empty directory. */
		if (filedir->rdn_dat.rdd_tree != NULL) {
			shared_rwlock_endwrite(&filedir->rdn_dat.rdd_treelock);
			shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
			/* Non-empty directory! */
			THROW(E_FSERROR_DIRECTORY_NOT_EMPTY);
		}

		/* Mark the directory as deleted. */
		filedir->rdn_dat.rdd_tree = RAMFS_DIRDATA_TREE_DELETED;
		shared_rwlock_endwrite(&filedir->rdn_dat.rdd_treelock);

		/* Remove entry from our directory tree. */
		ramfs_direnttree_removenode(&me->rdn_dat.rdd_tree, known_entry);
		known_entry->rde_treenode.rb_lhs = RAMFS_DIRENT_TREENODE_DELETED; /* Mark as deleted. */

		shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
	} else {
		bool last_link_went_away;
		ramfs_direnttree_removenode(&me->rdn_dat.rdd_tree, known_entry);
		known_entry->rde_treenode.rb_lhs = RAMFS_DIRENT_TREENODE_DELETED; /* Mark as deleted. */
		shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
		decref_nokill(known_entry); /* From `me->rdn_dat.rdd_tree' */

		/* For non-directory files, must decrement the NLINK counter. */
		mfile_tslock_acquire(file);
		assert(file->fn_nlink >= 1);
		ATOMIC_DEC(file->fn_nlink);
		last_link_went_away = file->fn_nlink == 0;
		mfile_tslock_release(file);

		/* Delete the file (make all mem-parts anonymous)
		 * NOTE: This will */
		if (last_link_went_away)
			mfile_delete(file);
	}
}


PUBLIC NONNULL((1, 2)) void KCALL
ramfs_dirnode_v_rename(struct fdirnode *__restrict self,
                       struct frename_info *__restrict info)
		THROWS(E_FSERROR_ILLEGAL_PATH, E_FSERROR_DISK_FULL,
		       E_FSERROR_READONLY, E_FSERROR_FILE_ALREADY_EXISTS,
		       E_FSERROR_DELETED) {
	struct ramfs_dirent *new_dirent;
	struct ramfs_dirnode *me     = (struct ramfs_dirnode *)self;
	struct ramfs_dirnode *olddir = (struct ramfs_dirnode *)info->frn_olddir;
	struct ramfs_dirent *old_dirent;
	assert(info->frn_dent->fd_ops == &ramfs_dirent_ops);
#ifndef __OPTIMIZE_SIZE__
	/* Check for an existing file before doing any allocations */
	shared_rwlock_read(&me->rdn_dat.rdd_treelock);
	TRY {
		if unlikely(me->rdn_dat.rdd_tree == RAMFS_DIRDATA_TREE_DELETED)
			THROW(E_FSERROR_DELETED, E_FILESYSTEM_DELETED_PATH);
		if unlikely(ramfs_dirdata_lookup(me, &info->frn_lookup_info))
			THROW(E_FSERROR_FILE_ALREADY_EXISTS);
	} EXCEPT {
		shared_rwlock_endread(&me->rdn_dat.rdd_treelock);
		RETHROW();
	}
	shared_rwlock_endread(&me->rdn_dat.rdd_treelock);
#endif /* !__OPTIMIZE_SIZE__ */

	/* Allocate the new directory entry. */
	new_dirent = (REF struct ramfs_dirent *)kmalloc(offsetof(struct ramfs_dirent, rde_ent.fd_name) +
	                                                (info->frn_namelen + 1) * sizeof(char),
	                                                GFP_NORMAL);
	TRY {
		/* Fill in the new directory entry. */
		*(char *)mempcpy(new_dirent->rde_ent.fd_name, info->frn_name,
		                 info->frn_namelen, sizeof(char)) = '\0';

		/* Fill in other fields of the new directory entry. */
		if (info->frn_hash == FLOOKUP_INFO_HASH_UNSET) {
			info->frn_hash = fdirent_hash(new_dirent->rde_ent.fd_name,
			                              new_dirent->rde_ent.fd_namelen);
		}
		new_dirent->rde_ent.fd_refcnt  = 2; /* +1: info->mkf_dent, +1: me->rdn_dat.rdd_tree */
		new_dirent->rde_ent.fd_ops     = &ramfs_dirent_ops;
		new_dirent->rde_ent.fd_hash    = info->frn_hash;
		new_dirent->rde_ent.fd_ino     = info->frn_file->fn_ino; /* INO numbers are constant here. */
		new_dirent->rde_ent.fd_namelen = info->frn_namelen;
		new_dirent->rde_ent.fd_type    = IFTODT(info->frn_file->fn_mode);
		new_dirent->rde_node           = info->frn_file; /* incref'd later! */
	} EXCEPT {
		kfree(new_dirent);
		RETHROW();
	}

	/* Acquire locks. */
again_acquire_locks:
	TRY {
		shared_rwlock_write(&me->rdn_dat.rdd_treelock);
	} EXCEPT {
		kfree(new_dirent);
		RETHROW();
	}
	if unlikely(me->rdn_dat.rdd_tree == RAMFS_DIRDATA_TREE_DELETED) {
		shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
		kfree(new_dirent);
		THROW(E_FSERROR_DELETED, E_FILESYSTEM_DELETED_PATH);
	}

	/* Check if the file already exists. */
	if (ramfs_direnttree_locate(me->rdn_dat.rdd_tree,
	                            new_dirent->rde_ent.fd_name,
	                            new_dirent->rde_ent.fd_namelen) ||
	    ((info->frn_flags & FS_MODE_FDOSPATH) && me->rdn_dat.rdd_tree &&
	     _ramfs_direnttree_caselocate(me->rdn_dat.rdd_tree,
	                                  new_dirent->rde_ent.fd_name,
	                                  new_dirent->rde_ent.fd_namelen))) {
		shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
		kfree(new_dirent);
		THROW(E_FSERROR_FILE_ALREADY_EXISTS);
	}

	/* Acquire a lock to the old directory. */
	if (me != olddir) {
		if (!shared_rwlock_trywrite(&olddir->rdn_dat.rdd_treelock)) {
			shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
			TRY {
				shared_rwlock_write(&olddir->rdn_dat.rdd_treelock);
			} EXCEPT {
				kfree(new_dirent);
				RETHROW();
			}
			shared_rwlock_endwrite(&olddir->rdn_dat.rdd_treelock);
			goto again_acquire_locks;
		}
	
		/* Check if the old directory has already been deleted. */
		if unlikely(olddir->rdn_dat.rdd_tree == RAMFS_DIRDATA_TREE_DELETED) {
			shared_rwlock_endwrite(&olddir->rdn_dat.rdd_treelock);
			shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
			kfree(new_dirent);
			THROW(E_FSERROR_DELETED, E_FILESYSTEM_DELETED_PATH);
		}
	}

	/* Check if the file still exists within the  old
	 * directory, and if so, remove it from said dir. */
	old_dirent = container_of(info->frn_oldent, struct ramfs_dirent, rde_ent);
	if (ramfs_direnttree_locate(olddir->rdn_dat.rdd_tree,
	                            old_dirent->rde_ent.fd_name,
	                            old_dirent->rde_ent.fd_namelen) != old_dirent) {
		if (me != olddir)
			shared_rwlock_endwrite(&olddir->rdn_dat.rdd_treelock);
		shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);
		kfree(new_dirent);
		THROW(E_FSERROR_DELETED, E_FILESYSTEM_DELETED_FILE);
	}

	/* Remove `old_dirent' from its tree. */
	ramfs_direnttree_removenode(&olddir->rdn_dat.rdd_tree, old_dirent);
	old_dirent->rde_treenode.rb_lhs = RAMFS_DIRENT_TREENODE_DELETED; /* Mark as deleted. */

	/* Insert the new directory entry into the new folder. */
	ramfs_direnttree_insert(&me->rdn_dat.rdd_tree, new_dirent);

	/* For `new_dirent->rde_node' */
	incref(info->frn_file);

	/* Release locks */
	if (me != olddir)
		shared_rwlock_endwrite(&olddir->rdn_dat.rdd_treelock);
	shared_rwlock_endwrite(&me->rdn_dat.rdd_treelock);

	/* Inherited   from   `olddir->rdn_dat.rdd_tree'
	 * (nokill because caller still has a reference) */
	decref_nokill(old_dirent);

	/* Write-back results. */
	info->frn_dent = &new_dirent->rde_ent; /* Inherit reference */
}



DECL_END

#endif /* !GUARD_KERNEL_CORE_FILESYS_RAMFS_C */