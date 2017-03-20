#pragma once
#ifndef _INC_EXCPT
#define _INC_EXCPT
#if !defined(_WIN32)
#error ERROR: Only Win32 target supported!
#endif
#ifdef _MSC_VER
#pragma pack(push,8)
#endif 
#ifndef _CRTIMP
#ifdef _DLL
#define _CRTIMP __declspec(dllimport)
#else 
#define _CRTIMP
#endif 
#endif 
#if(!defined(_MSC_VER) && !defined(__cdecl) )
#define 
#endif
typedef enum _EXCEPTION_DISPOSITION {
	ExceptionContinueExecution,ExceptionContinueSearch,ExceptionNestedException,ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;
struct _EXCEPTION_RECORD;
struct _CONTEXT;
typedef struct _EXCEPTION_POINTERS *Exception_info_ptr;
struct _DISPATCHER_CONTEXT;
#ifdef _M_IX86
EXCEPTION_DISPOSITION _except_handler (struct _EXCEPTION_RECORD *ExceptionRecord,void * EstablisherFrame,struct _CONTEXT *ContextRecord,void * DispatcherContext);
#elif defined(_M_IA64)
_CRTIMP EXCEPTION_DISPOSITION __C_specific_handler (struct _EXCEPTION_RECORD *ExceptionRecord,unsigned __int64 MemoryStackFp,unsigned __int64 BackingStoreFp,struct _CONTEXT *ContextRecord,struct _DISPATCHER_CONTEXT *DispatcherContext,unsigned __int64 GlobalPointer);
#elif defined(_M_AMD64)
_CRTIMP EXCEPTION_DISPOSITION __C_specific_handler (struct _EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,struct _CONTEXT *ContextRecord,struct _DISPATCHER_CONTEXT *DispatcherContext);
#endif
#ifdef _MSC_VER
#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (struct _EXCEPTION_POINTERS *)_exception_info
#define exception_info (struct _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination
unsigned long _exception_code(void);
void * _exception_info(void);
int _abnormal_termination(void);
#endif
#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_SEARCH 0
#define EXCEPTION_CONTINUE_EXECUTION -1
#ifdef _MSC_VER
#pragma pack(pop)
#endif 
#endif 
