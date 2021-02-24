#ifndef SD_COMMON_REGS_H
#define SD_COMMON_REGS_H

#ifdef __i386__
#define REG_ID orig_eax;
#define REG_ARG1 ebx;
#define REG_ARG2 ecx;
#define REG_ARG3 edx;
#define REG_ARG4 esi;
#define REG_ARG5 edi;
#define REG_ARG6 ebp;
#define REG_RET eax;
#endif

#ifdef __amd64__
#define REG_ID orig_eax;
#define REG_ARG1 rdi;
#define REG_ARG2 rsi;
#define REG_ARG3 rdx;
#define REG_ARG4 r10;
#define REG_ARG5 r8;
#define REG_ARG6 r9;
#define REG_RET eax;
#endif


#endif // final