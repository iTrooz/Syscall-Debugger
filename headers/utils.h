//#include <alpm.h>
#include "debugwindow.h"
#include "configFile.h"

#include <asm-generic/int-ll64.h>


extern DebugWindow* mainWindow;
extern unordered_map<int, string> syscalls;


struct ptrace_syscall_info {
	__u8 op;        /* Type of system call stop */
	__u32 arch;     /* AUDIT_ARCH_* value; see seccomp(2) */
	__u64 instruction_pointer; /* CPU instruction pointer */
	__u64 stack_pointer;    /* CPU stack pointer */
	union {
		struct {    /* op == PTRACE_SYSCALL_INFO_ENTRY */
			__u64 nr;       /* System call number */
			__u64 args[6];  /* System call arguments */
		} entry;
		struct {    /* op == PTRACE_SYSCALL_INFO_EXIT */
			__s64 rval;     /* System call return value */
			__u8 is_error;  /* System call error flag;
                                                 Boolean: does rval contain
                                                 an error value (-ERRCODE) or
                                                 a nonerror return value? */
		} exit;
		struct {    /* op == PTRACE_SYSCALL_INFO_SECCOMP */
			__u64 nr;       /* System call number */
			__u64 args[6];  /* System call arguments */
			__u32 ret_data; /* SECCOMP_RET_DATA portion
                                                 of SECCOMP_RET_TRACE
                                                 return value */
		} seccomp;
	};
};