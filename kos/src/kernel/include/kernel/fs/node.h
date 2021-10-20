 *             |                  +-----> chrdev  (S_IFCHR)  (TODO: replacement for `struct chrdev')
            USER CHECKED uid_t *pold_owner DFL(__NULLPTR),
            USER CHECKED gid_t *pold_group DFL(__NULLPTR),
/* Change all non-NULL the timestamp that are given.
 * @throw: E_FSERROR_DELETED:E_FILESYSTEM_DELETED_FILE: The `MFILE_F_DELETED' is set.
 * @throw: E_FSERROR_READONLY: The `MFILE_FM_ATTRREADONLY' flag is set. */
PUBLIC NONNULL((1)) void KCALL
mfile_chtime(struct mfile *__restrict self,
             struct timespec const *new_atime,
             struct timespec const *new_mtime,
             struct timespec const *new_ctime)
		THROWS(E_FSERROR_READONLY);


/* Check if the calling thread is allowed to access `self' as described by `type'
 * @param: type:   Set of `R_OK | W_OK | X_OK' (all specified types must be allowed)
 * @return: true:  Access granted
 * @return: false: Access denied. */
FUNDEF ATTR_PURE WUNUSED NONNULL((1)) __BOOL FCALL
fnode_mayaccess(struct fnode *__restrict self,
                unsigned int type)
		THROWS(E_WOULDBLOCK);

/* Helper wrapper for `fnode_mayaccess()' that asserts access
 * and throws `E_FSERROR_ACCESS_DENIED' is access was denied.
 * @param: type: Set of `R_OK | W_OK | X_OK' (all specified types must be allowed)
 * @return:                         Access granted
 * @throw: E_FSERROR_ACCESS_DENIED: Access denied. */
FUNDEF NONNULL((1)) void FCALL
fnode_access(struct fnode *__restrict self, unsigned int type)
		THROWS(E_WOULDBLOCK, E_FSERROR_ACCESS_DENIED);


#define fnode_ischrdev(self)  (S_ISCHR((self)->fn_mode) && (self)->fn_super == _ramfs_super_assuper(&devfs) && (self)->_fnode_file_ mf_ops != &ramfs_devnode_ops.dno_node.no_file)
#define fnode_isblkdev(self)  (S_ISBLK((self)->fn_mode) && (self)->fn_super == _ramfs_super_assuper(&devfs) && (self)->_fnode_file_ mf_ops != &ramfs_devnode_ops.dno_node.no_file)