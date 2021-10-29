PUBLIC NONNULL((1)) void
NOTHROW(KCALL fnode_v_changed)(struct mfile *__restrict self,
                                                   struct fsuper *__restrict UNUSED(obj)) {
NOTHROW(KCALL fnode_v_destroy)(struct mfile *__restrict self) {
	struct fnode *me = mfile_asnode(self);
	assertf(!(me->mf_flags & MFILE_FN_GLOBAL_REF),
	if (fnode_issuper(me)) {
		struct fsuper *super = fnode_assuper(me);
		if (LIST_ISBOUND(super, fs_root.fn_allsuper)) {
				assert(super->fs_root._fn_alllop.lo_func != &fnode_addtoall_lop);
				if (LIST_ISBOUND(super, fs_root.fn_allsuper))
					LIST_REMOVE(super, fs_root.fn_allsuper);
				DBG_memset(super->fs_root._mf_lopX, 0xcc, sizeof(super->fs_root._mf_lopX));
				super->fs_root._mf_lop.lo_func = &fnode_v_destroy_rmallsuper_lop;
				lockop_enqueue(&fallsuper_lockops, &super->fs_root._mf_lop);
		REF struct fsuper *super = me->fn_super;
		if (ATOMIC_READ(me->fn_supent.rb_rhs) != FSUPER_NODES_DELETED) {
				if (me->fn_supent.rb_rhs != FSUPER_NODES_DELETED) {
					assertf(me->_fn_suplop.olo_func != &fnode_add2sup_lop,
					fsuper_nodes_removenode(super, me);
				me->_mf_fsuperlop.olo_func = &fnode_v_destroy_rmsuper_lop;
				oblockop_enqueue(&super->fs_nodeslockops, &me->_mf_fsuperlop);
		if (LIST_ISBOUND(me, fn_allnodes)) {
				if unlikely(me->_fn_alllop.lo_func == &fnode_addtoall_lop) {
				if (LIST_ISBOUND(me, fn_allnodes))
					LIST_REMOVE(me, fn_allnodes);
				DBG_memset(me->_mf_lopX, 0xcc, sizeof(me->_mf_lopX));
				me->_mf_lop.lo_func = &fnode_v_destroy_rmallnodes_lop;
				lockop_enqueue(&fallnodes_lockops, &me->_mf_lop);
	fnode_free(me);
                                                   struct fsuper *__restrict UNUSED(obj)) {
 * @throw: E_FSERROR_READONLY:    The `MFILE_FN_ATTRREADONLY' flag is (or was) set.
	if unlikely(self->mf_flags & MFILE_FN_ATTRREADONLY)
 * @throw: E_FSERROR_READONLY:    The `MFILE_FN_ATTRREADONLY' flag is (or was) set.
	if unlikely(self->mf_flags & MFILE_FN_ATTRREADONLY)
 * @throw: E_FSERROR_READONLY: The `MFILE_FN_ATTRREADONLY' flag is (or was) set. */
	if unlikely(self->mf_flags & MFILE_FN_ATTRREADONLY)
	                           MFILE_F_DELETED | MFILE_F_NOATIME | MFILE_FN_NODIRATIME |
	                           MFILE_F_NOMTIME | MFILE_F_CHANGED | MFILE_F_ATTRCHANGED |
	                           MFILE_F_FIXEDFILESIZE | MFILE_FN_ATTRREADONLY |
	                           MFILE_F_NOUSRMMAP | MFILE_F_NOUSRIO | MFILE_F_READONLY);
PUBLIC NOBLOCK NOPREEMPT WUNUSED NONNULL((1)) __BOOL
NOTHROW(FCALL fnode_delete_strt_with_tslock)(struct fnode *__restrict self) {
	uintptr_t old_flags;

	/* Delete global reference to the file-node. */
	if (ATOMIC_FETCHAND(self->mf_flags, ~(MFILE_FN_GLOBAL_REF |
	                                      MFILE_F_PERSISTENT)) &
	    MFILE_FN_GLOBAL_REF) {
		decref_nokill(self);
	}

	/* Mark the file as deleted (and make available use of the timestamp fields) */
	old_flags = ATOMIC_FETCHOR(self->mf_flags,
	                           MFILE_F_DELETED | MFILE_F_NOATIME | MFILE_FN_NODIRATIME |
	                           MFILE_F_NOMTIME | MFILE_F_CHANGED | MFILE_F_ATTRCHANGED |
	                           MFILE_F_FIXEDFILESIZE | MFILE_FN_ATTRREADONLY |
	                           MFILE_F_NOUSRMMAP | MFILE_F_NOUSRIO | MFILE_F_READONLY);
	if (old_flags & MFILE_F_PERSISTENT)
		ATOMIC_AND(self->mf_flags, ~MFILE_F_PERSISTENT); /* Also clear the PERSISTENT flag */
	return !(old_flags & MFILE_F_DELETED);
}


 *  - Set flags: MFILE_F_DELETED | MFILE_F_NOATIME | MFILE_FN_NODIRATIME |
 *               MFILE_F_NOMTIME | MFILE_F_CHANGED | MFILE_F_ATTRCHANGED |
 *               MFILE_F_FIXEDFILESIZE    |    MFILE_FN_ATTRREADONLY     |
 *               MFILE_F_NOUSRMMAP |  MFILE_F_NOUSRIO  |  MFILE_F_READONLY