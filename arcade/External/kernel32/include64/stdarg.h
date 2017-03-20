#ifndef __stdarg_h__
#define __stdarg_h__
#pragma once
struct __va_list {
        unsigned long long gp_offset;
        unsigned long long fp_offset;
        void *overflow_arg_area;
        void *reg_save_area;
};
typedef struct __va_list *va_list;
typedef struct tagRegisterSaveArea {
        long long rcx;
        long long rdx;
        long long r8;
        long long r9;
	long long xmm0;
	long long xmm1;
	long long xmm2;
	long long xmm3;
} __REGISTER_SAVE_AREA;
void *__builtin_va_arg(va_list  ,int);
void *__builtin_va_start(va_list *,void *);
#define va_start(ap,v)  (  __builtin_va_start(&ap,&v))
#define va_arg(ap,t)    ( *(t *)(__builtin_va_arg(ap,t)))
extern void *alloca(unsigned long long);
#define va_copy(dest,src) (dest = alloca(sizeof(struct __va_list)),*dest=*src)
#define va_end(ap)
#endif
