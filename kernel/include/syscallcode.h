#ifndef SYSCALL_CODE_H
#define SYSCALL_CODE_H

typedef enum {
	SYSCALL_DEV_INFO,
	SYSCALL_DEV_CHAR_READ,
	SYSCALL_DEV_CHAR_WRITE,
	SYSCALL_DEV_BLOCK_READ,
	SYSCALL_DEV_BLOCK_READ_DONE,
	SYSCALL_DEV_BLOCK_WRITE,
	SYSCALL_DEV_BLOCK_WRITE_DONE,

	SYSCALL_SHM_ALLOC,
	SYSCALL_SHM_FREE,
	SYSCALL_SHM_MAP,
	SYSCALL_SHM_UNMAP,

	SYSCALL_FORK,
	SYSCALL_GETPID,
	SYSCALL_EXEC_ELF,
	SYSCALL_WAIT,
	SYSCALL_EXIT,
	SYSCALL_SLEEP_MSEC,
	
	SYSCALL_GET_ENV,
	SYSCALL_GET_ENV_NAME,
	SYSCALL_GET_ENV_VALUE,
	SYSCALL_SET_ENV,

	SYSCALL_THREAD,

	SYSCALL_PMALLOC,
	SYSCALL_PFREE,

	SYSCALL_GET_CMD,

	SYSCALL_IPC_OPEN,
	SYSCALL_IPC_CLOSE,
	SYSCALL_IPC_WRITE,
	SYSCALL_IPC_READY,
	SYSCALL_IPC_READ,
	SYSCALL_IPC_RING,
	SYSCALL_IPC_PEER,

	SYSCALL_PFILE_GET_SEEK,
	SYSCALL_PFILE_SEEK,
	SYSCALL_PFILE_OPEN,
	SYSCALL_PFILE_CLOSE,
	SYSCALL_PFILE_DUP2,
	SYSCALL_PFILE_NODE_BY_FD,
	SYSCALL_PFILE_NODE_BY_PID_FD,
	SYSCALL_PFILE_NODE_BY_ADDR,
	SYSCALL_PFILE_NODE_UPDATE,
	SYSCALL_PFILE_GET_REF,

	SYSCALL_KSERV_REG,
	SYSCALL_KSERV_READY,
	SYSCALL_KSERV_GET_BY_NAME,
	SYSCALL_KSERV_GET_BY_PID,

	SYSCALL_GET_CWD,
	SYSCALL_SET_CWD,

	SYSCALL_SET_UID,
	SYSCALL_GET_UID,

	SYSCALL_SEMAPHORE_LOCK,
	SYSCALL_SEMAPHORE_UNLOCK,
	SYSCALL_SEMAPHORE_INIT,
	SYSCALL_SEMAPHORE_CLOSE,

	SYSCALL_SYSTEM_CMD
} syscall_code_t;

#endif
