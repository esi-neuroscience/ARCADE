#ifndef _WINBASE_
#define _WINBASE_
#pragma once
#ifdef _MAC
#include <macwin32.h>
#endif 
#if !defined(_ADVAPI32_)
#define WINADVAPI DECLSPEC_IMPORT
#else
#define WINADVAPI
#endif
//#if !defined(_KERNEL32_)
//#define WINBASEAPI DECLSPEC_IMPORT
//#else
#define WINBASEAPI
//#endif
#if !defined(_ZAWPROXY_)
#define ZAWPROXYAPI DECLSPEC_IMPORT
#else
#define ZAWPROXYAPI
#endif
#define DefineHandleTable(w)((w),TRUE)
#define LimitEmsPages(dw)
#define SetSwapAreaSize(w)(w)
#define LockSegment(w) GlobalFix((HANDLE)(w))
#define UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#define GetCurrentTime() GetTickCount()
#define Yield()
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)
#define FILE_BEGIN 0
#define FILE_CURRENT 1
#define FILE_END 2
#define TIME_ZONE_ID_INVALID ((DWORD)0xFFFFFFFF)
#define WAIT_FAILED ((DWORD)0xFFFFFFFF)
#define WAIT_OBJECT_0 ((STATUS_WAIT_0 ) + 0 )
#define WAIT_ABANDONED ((STATUS_ABANDONED_WAIT_0 ) + 0 )
#define WAIT_ABANDONED_0 ((STATUS_ABANDONED_WAIT_0 ) + 0 )
#define WAIT_IO_COMPLETION STATUS_USER_APC
#define STILL_ACTIVE STATUS_PENDING
#define EXCEPTION_ACCESS_VIOLATION STATUS_ACCESS_VIOLATION
#define EXCEPTION_DATATYPE_MISALIGNMENT STATUS_DATATYPE_MISALIGNMENT
#define EXCEPTION_BREAKPOINT STATUS_BREAKPOINT
#define EXCEPTION_SINGLE_STEP STATUS_SINGLE_STEP
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED STATUS_ARRAY_BOUNDS_EXCEEDED
#define EXCEPTION_FLT_DENORMAL_OPERAND STATUS_FLOAT_DENORMAL_OPERAND
#define EXCEPTION_FLT_DIVIDE_BY_ZERO STATUS_FLOAT_DIVIDE_BY_ZERO
#define EXCEPTION_FLT_INEXACT_RESULT STATUS_FLOAT_INEXACT_RESULT
#define EXCEPTION_FLT_INVALID_OPERATION STATUS_FLOAT_INVALID_OPERATION
#define EXCEPTION_FLT_OVERFLOW STATUS_FLOAT_OVERFLOW
#define EXCEPTION_FLT_STACK_CHECK STATUS_FLOAT_STACK_CHECK
#define EXCEPTION_FLT_UNDERFLOW STATUS_FLOAT_UNDERFLOW
#define EXCEPTION_INT_DIVIDE_BY_ZERO STATUS_INTEGER_DIVIDE_BY_ZERO
#define EXCEPTION_INT_OVERFLOW STATUS_INTEGER_OVERFLOW
#define EXCEPTION_PRIV_INSTRUCTION STATUS_PRIVILEGED_INSTRUCTION
#define EXCEPTION_IN_PAGE_ERROR STATUS_IN_PAGE_ERROR
#define EXCEPTION_ILLEGAL_INSTRUCTION STATUS_ILLEGAL_INSTRUCTION
#define EXCEPTION_NONCONTINUABLE_EXCEPTION STATUS_NONCONTINUABLE_EXCEPTION
#define EXCEPTION_STACK_OVERFLOW STATUS_STACK_OVERFLOW
#define EXCEPTION_INVALID_DISPOSITION STATUS_INVALID_DISPOSITION
#define EXCEPTION_GUARD_PAGE STATUS_GUARD_PAGE_VIOLATION
#define EXCEPTION_INVALID_HANDLE STATUS_INVALID_HANDLE
#define EXCEPTION_POSSIBLE_DEADLOCK STATUS_POSSIBLE_DEADLOCK
#define CONTROL_C_EXIT STATUS_CONTROL_C_EXIT
#define MoveMemory RtlMoveMemory
#define CopyMemory RtlCopyMemory
#define FillMemory RtlFillMemory
#define ZeroMemory RtlZeroMemory
#define SecureZeroMemory RtlSecureZeroMemory
#define FILE_FLAG_WRITE_THROUGH 0x80000000
#define FILE_FLAG_OVERLAPPED 0x40000000
#define FILE_FLAG_NO_BUFFERING 0x20000000
#define FILE_FLAG_RANDOM_ACCESS 0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN 0x8000000
#define FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#define FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#define FILE_FLAG_POSIX_SEMANTICS 0x1000000
#define FILE_FLAG_OPEN_REPARSE_POINT 0x200000
#define FILE_FLAG_OPEN_NO_RECALL 0x100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE 0x80000
#define CREATE_NEW 1
#define CREATE_ALWAYS 2
#define OPEN_EXISTING 3
#define OPEN_ALWAYS 4
#define TRUNCATE_EXISTING 5
#if(_WIN32_WINNT >=0x0400)
#define PROGRESS_CONTINUE 0
#define PROGRESS_CANCEL 1
#define PROGRESS_STOP 2
#define PROGRESS_QUIET 3
#define CALLBACK_CHUNK_FINISHED 0
#define CALLBACK_STREAM_SWITCH 1
#define COPY_FILE_FAIL_IF_EXISTS 1
#define COPY_FILE_RESTARTABLE 2
#define COPY_FILE_OPEN_SOURCE_FOR_WRITE 4
#define COPY_FILE_ALLOW_DECRYPTED_DESTINATION 8
#endif 
#if (_WIN32_WINNT >=0x0500)
#define REPLACEFILE_WRITE_THROUGH 1
#define REPLACEFILE_IGNORE_MERGE_ERRORS 2
#endif 
#define PIPE_ACCESS_INBOUND 1
#define PIPE_ACCESS_OUTBOUND 2
#define PIPE_ACCESS_DUPLEX 3
#define PIPE_CLIENT_END 0
#define PIPE_SERVER_END 1
#define PIPE_WAIT 0
#define PIPE_NOWAIT 1
#define PIPE_READMODE_BYTE 0
#define PIPE_READMODE_MESSAGE 2
#define PIPE_TYPE_BYTE 0
#define PIPE_TYPE_MESSAGE 4
#define PIPE_UNLIMITED_INSTANCES 255
#define SECURITY_ANONYMOUS (SecurityAnonymous << 16 )
#define SECURITY_IDENTIFICATION (SecurityIdentification << 16 )
#define SECURITY_IMPERSONATION (SecurityImpersonation << 16 )
#define SECURITY_DELEGATION (SecurityDelegation << 16 )
#define SECURITY_CONTEXT_TRACKING 0x40000
#define SECURITY_EFFECTIVE_ONLY 0x80000
#define SECURITY_SQOS_PRESENT 0x100000
#define SECURITY_VALID_SQOS_FLAGS 0x1f0000
typedef struct _OVERLAPPED {
	ULONG_PTR Internal;
	ULONG_PTR InternalHigh;
//	union {
//		struct {
//			DWORD Offset;
//			DWORD OffsetHigh;
//		};
		PVOID Pointer;
//	};
	HANDLE hEvent;
} OVERLAPPED,*LPOVERLAPPED;
typedef struct _SECURITY_ATTRIBUTES {
	DWORD nLength;
	LPVOID lpSecurityDescriptor;
	BOOL bInheritHandle;
} SECURITY_ATTRIBUTES,*PSECURITY_ATTRIBUTES,*LPSECURITY_ATTRIBUTES;
typedef struct _PROCESS_INFORMATION {
	HANDLE hProcess;
	HANDLE hThread;
	DWORD dwProcessId;
	DWORD dwThreadId;
} PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;
#ifndef _FILETIME_
#define _FILETIME_
typedef struct _FILETIME {
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;
} FILETIME,*PFILETIME,*LPFILETIME;
#endif
typedef struct _SYSTEMTIME {
	WORD wYear;
	WORD wMonth;
	WORD wDayOfWeek;
	WORD wDay;
	WORD wHour;
	WORD wMinute;
	WORD wSecond;
	WORD wMilliseconds;
} SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;
// typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
// typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
#if(_WIN32_WINNT >=0x0400)
typedef VOID (WINAPI *PFIBER_START_ROUTINE)(LPVOID lpFiberParameter);
typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;
#endif 
/*
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
typedef RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;
WINBASEAPI PVOID WINAPI EncodePointer (PVOID Ptr);
WINBASEAPI PVOID WINAPI DecodePointer (PVOID Ptr);
WINBASEAPI PVOID WINAPI EncodeSystemPointer (PVOID Ptr);
WINBASEAPI PVOID WINAPI DecodeSystemPointer (PVOID Ptr);
#if defined(_X86_)
typedef PLDT_ENTRY LPLDT_ENTRY;
#else
typedef LPVOID LPLDT_ENTRY;
#endif
*/
#define MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#define MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS
#define SP_SERIALCOMM ((DWORD)0x00000001)
#define PST_UNSPECIFIED ((DWORD)0x00000000)
#define PST_RS232 ((DWORD)0x00000001)
#define PST_PARALLELPORT ((DWORD)0x00000002)
#define PST_RS422 ((DWORD)0x00000003)
#define PST_RS423 ((DWORD)0x00000004)
#define PST_RS449 ((DWORD)0x00000005)
#define PST_MODEM ((DWORD)0x00000006)
#define PST_FAX ((DWORD)0x00000021)
#define PST_SCANNER ((DWORD)0x00000022)
#define PST_NETWORK_BRIDGE ((DWORD)0x00000100)
#define PST_LAT ((DWORD)0x00000101)
#define PST_TCPIP_TELNET ((DWORD)0x00000102)
#define PST_X25 ((DWORD)0x00000103)
#define PCF_DTRDSR ((DWORD)0x0001)
#define PCF_RTSCTS ((DWORD)0x0002)
#define PCF_RLSD ((DWORD)0x0004)
#define PCF_PARITY_CHECK ((DWORD)0x0008)
#define PCF_XONXOFF ((DWORD)0x0010)
#define PCF_SETXCHAR ((DWORD)0x0020)
#define PCF_TOTALTIMEOUTS ((DWORD)0x0040)
#define PCF_INTTIMEOUTS ((DWORD)0x0080)
#define PCF_SPECIALCHARS ((DWORD)0x0100)
#define PCF_16BITMODE ((DWORD)0x0200)
#define SP_PARITY ((DWORD)0x0001)
#define SP_BAUD ((DWORD)0x0002)
#define SP_DATABITS ((DWORD)0x0004)
#define SP_STOPBITS ((DWORD)0x0008)
#define SP_HANDSHAKING ((DWORD)0x0010)
#define SP_PARITY_CHECK ((DWORD)0x0020)
#define SP_RLSD ((DWORD)0x0040)
#define BAUD_075 ((DWORD)0x00000001)
#define BAUD_110 ((DWORD)0x00000002)
#define BAUD_134_5 ((DWORD)0x00000004)
#define BAUD_150 ((DWORD)0x00000008)
#define BAUD_300 ((DWORD)0x00000010)
#define BAUD_600 ((DWORD)0x00000020)
#define BAUD_1200 ((DWORD)0x00000040)
#define BAUD_1800 ((DWORD)0x00000080)
#define BAUD_2400 ((DWORD)0x00000100)
#define BAUD_4800 ((DWORD)0x00000200)
#define BAUD_7200 ((DWORD)0x00000400)
#define BAUD_9600 ((DWORD)0x00000800)
#define BAUD_14400 ((DWORD)0x00001000)
#define BAUD_19200 ((DWORD)0x00002000)
#define BAUD_38400 ((DWORD)0x00004000)
#define BAUD_56K ((DWORD)0x00008000)
#define BAUD_128K ((DWORD)0x00010000)
#define BAUD_115200 ((DWORD)0x00020000)
#define BAUD_57600 ((DWORD)0x00040000)
#define BAUD_USER ((DWORD)0x10000000)
#define DATABITS_5 ((WORD)0x0001)
#define DATABITS_6 ((WORD)0x0002)
#define DATABITS_7 ((WORD)0x0004)
#define DATABITS_8 ((WORD)0x0008)
#define DATABITS_16 ((WORD)0x0010)
#define DATABITS_16X ((WORD)0x0020)
#define STOPBITS_10 ((WORD)0x0001)
#define STOPBITS_15 ((WORD)0x0002)
#define STOPBITS_20 ((WORD)0x0004)
#define PARITY_NONE ((WORD)0x0100)
#define PARITY_ODD ((WORD)0x0200)
#define PARITY_EVEN ((WORD)0x0400)
#define PARITY_MARK ((WORD)0x0800)
#define PARITY_SPACE ((WORD)0x1000)
typedef struct _COMMPROP {
	WORD wPacketLength;
	WORD wPacketVersion;
	DWORD dwServiceMask;
	DWORD dwReserved1;
	DWORD dwMaxTxQueue;
	DWORD dwMaxRxQueue;
	DWORD dwMaxBaud;
	DWORD dwProvSubType;
	DWORD dwProvCapabilities;
	DWORD dwSettableParams;
	DWORD dwSettableBaud;
	WORD wSettableData;
	WORD wSettableStopParity;
	DWORD dwCurrentTxQueue;
	DWORD dwCurrentRxQueue;
	DWORD dwProvSpec1;
	DWORD dwProvSpec2;
	WCHAR wcProvChar[1];
} COMMPROP,*LPCOMMPROP;
#define COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)
/*
typedef struct _COMSTAT {
	DWORD fCtsHold : 1;
	DWORD fDsrHold : 1;
	DWORD fRlsdHold : 1;
	DWORD fXoffHold : 1;
	DWORD fXoffSent : 1;
	DWORD fEof : 1;
	DWORD fTxim : 1;
	DWORD fReserved : 25;
	DWORD cbInQue;
	DWORD cbOutQue;
} COMSTAT,*LPCOMSTAT;
*/
#define DTR_CONTROL_DISABLE 0
#define DTR_CONTROL_ENABLE 1
#define DTR_CONTROL_HANDSHAKE 2
#define RTS_CONTROL_DISABLE 0
#define RTS_CONTROL_ENABLE 1
#define RTS_CONTROL_HANDSHAKE 2
#define RTS_CONTROL_TOGGLE 3
typedef struct _DCB {
	DWORD DCBlength; 
	DWORD BaudRate; 
	DWORD fBinary: 1; 
	DWORD fParity: 1; 
	DWORD fOutxCtsFlow:1; 
	DWORD fOutxDsrFlow:1; 
	DWORD fDtrControl:2; 
	DWORD fDsrSensitivity:1; 
	DWORD fTXContinueOnXoff: 1; 
	DWORD fOutX: 1; 
	DWORD fInX: 1; 
	DWORD fErrorChar: 1; 
	DWORD fNull: 1; 
	DWORD fRtsControl:2; 
	DWORD fAbortOnError:1; 
	DWORD fDummy2:17; 
	WORD wReserved; 
	WORD XonLim; 
	WORD XoffLim; 
	BYTE ByteSize; 
	BYTE Parity; 
	BYTE StopBits; 
	char XonChar; 
	char XoffChar; 
	char ErrorChar; 
	char EofChar; 
	char EvtChar; 
	WORD wReserved1; 
} DCB,*LPDCB;
typedef struct _COMMTIMEOUTS {
	DWORD ReadIntervalTimeout; 
	DWORD ReadTotalTimeoutMultiplier; 
	DWORD ReadTotalTimeoutConstant; 
	DWORD WriteTotalTimeoutMultiplier; 
	DWORD WriteTotalTimeoutConstant; 
} COMMTIMEOUTS,*LPCOMMTIMEOUTS;
/*
typedef struct _COMMCONFIG {
	DWORD dwSize; 
	WORD wVersion; 
	WORD wReserved; 
	DCB dcb; 
	DWORD dwProviderSubType; 
	DWORD dwProviderOffset; 
	DWORD dwProviderSize; 
	WCHAR wcProviderData[1]; 
} COMMCONFIG,*LPCOMMCONFIG;

typedef struct _SYSTEM_INFO {
	union {
		DWORD dwOemId; 
		struct {
			WORD wProcessorArchitecture;
			WORD wReserved;
		};
	};
	DWORD dwPageSize;
	LPVOID lpMinimumApplicationAddress;
	LPVOID lpMaximumApplicationAddress;
	DWORD_PTR dwActiveProcessorMask;
	DWORD dwNumberOfProcessors;
	DWORD dwProcessorType;
	DWORD dwAllocationGranularity;
	WORD wProcessorLevel;
	WORD wProcessorRevision;
} SYSTEM_INFO,*LPSYSTEM_INFO;
*/
#define FreeModule(hLibModule) FreeLibrary((hLibModule))
#define MakeProcInstance(lpProc,hInstance) (lpProc)
#define FreeProcInstance(lpProc) (lpProc)
#define GMEM_FIXED 0
#define GMEM_MOVEABLE 2
#define GMEM_NOCOMPACT 16
#define GMEM_NODISCARD 32
#define GMEM_ZEROINIT 64
#define GMEM_MODIFY 128
#define GMEM_DISCARDABLE 256
#define GMEM_NOT_BANKED 0x1000
#define GMEM_SHARE 0x2000
#define GMEM_DDESHARE 0x2000
#define GMEM_NOTIFY 0x4000
#define GMEM_LOWER GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS 0x7f72
#define GMEM_INVALID_HANDLE 0x8000
#define GHND (GMEM_MOVEABLE|GMEM_ZEROINIT)
#define GPTR (GMEM_FIXED|GMEM_ZEROINIT)
#define GlobalLRUNewest(h )((HANDLE)(h))
#define GlobalLRUOldest(h )((HANDLE)(h))
#define GlobalDiscard(h ) GlobalReAlloc((h),0,GMEM_MOVEABLE )
#define GMEM_DISCARDED 0x4000
#define GMEM_LOCKCOUNT 255
typedef struct _MEMORYSTATUS {
	DWORD dwLength;
	DWORD dwMemoryLoad;
	SIZE_T dwTotalPhys;
	SIZE_T dwAvailPhys;
	SIZE_T dwTotalPageFile;
	SIZE_T dwAvailPageFile;
	SIZE_T dwTotalVirtual;
	SIZE_T dwAvailVirtual;
} MEMORYSTATUS,*LPMEMORYSTATUS;
#define LMEM_FIXED 0
#define LMEM_MOVEABLE 2
#define LMEM_NOCOMPACT 16
#define LMEM_NODISCARD 32
#define LMEM_ZEROINIT 64
#define LMEM_MODIFY 128
#define LMEM_DISCARDABLE 3840
#define LMEM_VALID_FLAGS 3954
#define LMEM_INVALID_HANDLE 0x8000
#define LHND (LMEM_MOVEABLE|LMEM_ZEROINIT)
#define LPTR (LMEM_FIXED|LMEM_ZEROINIT)
#define NONZEROLHND (LMEM_MOVEABLE)
#define NONZEROLPTR (LMEM_FIXED)
#define LocalDiscard(h ) LocalReAlloc((h),0,LMEM_MOVEABLE )
#define LMEM_DISCARDED 0x4000
#define LMEM_LOCKCOUNT 255
#define DEBUG_PROCESS 1
#define DEBUG_ONLY_THIS_PROCESS 2
#define CREATE_SUSPENDED 4
#define DETACHED_PROCESS 8
#define CREATE_NEW_CONSOLE 16
#define NORMAL_PRIORITY_CLASS 32
#define IDLE_PRIORITY_CLASS 64
#define HIGH_PRIORITY_CLASS 128
#define REALTIME_PRIORITY_CLASS 256
#define CREATE_NEW_PROCESS_GROUP 512
#define CREATE_UNICODE_ENVIRONMENT 1024
#define CREATE_SEPARATE_WOW_VDM 2048
#define CREATE_SHARED_WOW_VDM 0x1000
#define CREATE_FORCEDOS 0x2000
#define BELOW_NORMAL_PRIORITY_CLASS 0x4000
#define ABOVE_NORMAL_PRIORITY_CLASS 0x8000
#define STACK_SIZE_PARAM_IS_A_RESERVATION 0x10000
#define CREATE_BREAKAWAY_FROM_JOB 0x1000000
#define CREATE_PRESERVE_CODE_AUTHZ_LEVEL 0x2000000
#define CREATE_DEFAULT_ERROR_MODE 0x4000000
#define CREATE_NO_WINDOW 0x8000000
#define PROFILE_USER 0x10000000
#define PROFILE_KERNEL 0x20000000
#define PROFILE_SERVER 0x40000000
#define CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000
#define THREAD_PRIORITY_LOWEST THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL 0
#define THREAD_PRIORITY_HIGHEST THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN (MAXLONG)
#define THREAD_PRIORITY_TIME_CRITICAL THREAD_BASE_PRIORITY_LOWRT
#define THREAD_PRIORITY_IDLE THREAD_BASE_PRIORITY_IDLE
#define EXCEPTION_DEBUG_EVENT 1
#define CREATE_THREAD_DEBUG_EVENT 2
#define CREATE_PROCESS_DEBUG_EVENT 3
#define EXIT_THREAD_DEBUG_EVENT 4
#define EXIT_PROCESS_DEBUG_EVENT 5
#define LOAD_DLL_DEBUG_EVENT 6
#define UNLOAD_DLL_DEBUG_EVENT 7
#define OUTPUT_DEBUG_STRING_EVENT 8
#define RIP_EVENT 9
typedef struct _EXCEPTION_DEBUG_INFO {
	EXCEPTION_RECORD ExceptionRecord;
	DWORD dwFirstChance;
} EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;
/*
typedef struct _CREATE_THREAD_DEBUG_INFO {
	HANDLE hThread;
	LPVOID lpThreadLocalBase;
	LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

typedef struct _CREATE_PROCESS_DEBUG_INFO {
	HANDLE hFile;
	HANDLE hProcess;
	HANDLE hThread;
	LPVOID lpBaseOfImage;
	DWORD dwDebugInfoFileOffset;
	DWORD nDebugInfoSize;
	LPVOID lpThreadLocalBase;
	LPTHREAD_START_ROUTINE lpStartAddress;
	LPVOID lpImageName;
	WORD fUnicode;
} CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;
*/
typedef struct _EXIT_THREAD_DEBUG_INFO {
	DWORD dwExitCode;
} EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;
typedef struct _EXIT_PROCESS_DEBUG_INFO {
	DWORD dwExitCode;
} EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;
typedef struct _LOAD_DLL_DEBUG_INFO {
	HANDLE hFile;
	LPVOID lpBaseOfDll;
	DWORD dwDebugInfoFileOffset;
	DWORD nDebugInfoSize;
	LPVOID lpImageName;
	WORD fUnicode;
} LOAD_DLL_DEBUG_INFO,*LPLOAD_DLL_DEBUG_INFO;
typedef struct _UNLOAD_DLL_DEBUG_INFO {
	LPVOID lpBaseOfDll;
} UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;
typedef struct _OUTPUT_DEBUG_STRING_INFO {
	LPSTR lpDebugStringData;
	WORD fUnicode;
	WORD nDebugStringLength;
} OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;
typedef struct _RIP_INFO {
	DWORD dwError;
	DWORD dwType;
} RIP_INFO,*LPRIP_INFO;
/*
typedef struct _DEBUG_EVENT {
	DWORD dwDebugEventCode;
	DWORD dwProcessId;
	DWORD dwThreadId;
	union {
		EXCEPTION_DEBUG_INFO Exception;
		CREATE_THREAD_DEBUG_INFO CreateThread;
		CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
		EXIT_THREAD_DEBUG_INFO ExitThread;
		EXIT_PROCESS_DEBUG_INFO ExitProcess;
		LOAD_DLL_DEBUG_INFO LoadDll;
		UNLOAD_DLL_DEBUG_INFO UnloadDll;
		OUTPUT_DEBUG_STRING_INFO DebugString;
		RIP_INFO RipInfo;
	} u;
} DEBUG_EVENT,*LPDEBUG_EVENT;
*/

#define MIDL_PASS

#if !defined(MIDL_PASS)
typedef PCONTEXT LPCONTEXT;
typedef PEXCEPTION_RECORD LPEXCEPTION_RECORD;
typedef PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;
#endif
#define DRIVE_UNKNOWN 0
#define DRIVE_NO_ROOT_DIR 1
#define DRIVE_REMOVABLE 2
#define DRIVE_FIXED 3
#define DRIVE_REMOTE 4
#define DRIVE_CDROM 5
#define DRIVE_RAMDISK 6
#ifndef _MAC
#define GetFreeSpace(w)(0x100000L)
#else
WINBASEAPI DWORD WINAPI GetFreeSpace(UINT);
#endif
#define FILE_TYPE_UNKNOWN 0
#define FILE_TYPE_DISK 1
#define FILE_TYPE_CHAR 2
#define FILE_TYPE_PIPE 3
#define FILE_TYPE_REMOTE 0x8000
#define STD_INPUT_HANDLE ((DWORD)-10)
#define STD_OUTPUT_HANDLE ((DWORD)-11)
#define STD_ERROR_HANDLE ((DWORD)-12)
#define NOPARITY 0
#define ODDPARITY 1
#define EVENPARITY 2
#define MARKPARITY 3
#define SPACEPARITY 4
#define ONESTOPBIT 0
#define ONE5STOPBITS 1
#define TWOSTOPBITS 2
#define IGNORE 0 
#define INFINITE 0xffffffff 
#define CBR_110 110
#define CBR_300 300
#define CBR_600 600
#define CBR_1200 1200
#define CBR_2400 2400
#define CBR_4800 4800
#define CBR_9600 9600
#define CBR_14400 14400
#define CBR_19200 19200
#define CBR_38400 38400
#define CBR_56000 56000
#define CBR_57600 57600
#define CBR_115200 115200
#define CBR_128000 128000
#define CBR_256000 256000
#define CE_RXOVER 1 
#define CE_OVERRUN 2 
#define CE_RXPARITY 4 
#define CE_FRAME 8 
#define CE_BREAK 16 
#define CE_TXFULL 256 
#define CE_PTO 512 
#define CE_IOE 1024 
#define CE_DNS 2048 
#define CE_OOP 0x1000 
#define CE_MODE 0x8000 
#define IE_BADID (-1) 
#define IE_OPEN (-2) 
#define IE_NOPEN (-3) 
#define IE_MEMORY (-4) 
#define IE_DEFAULT (-5) 
#define IE_HARDWARE (-10) 
#define IE_BYTESIZE (-11) 
#define IE_BAUDRATE (-12) 
#define EV_RXCHAR 1 
#define EV_RXFLAG 2 
#define EV_TXEMPTY 4 
#define EV_CTS 8 
#define EV_DSR 16 
#define EV_RLSD 32 
#define EV_BREAK 64 
#define EV_ERR 128 
#define EV_RING 256 
#define EV_PERR 512 
#define EV_RX80FULL 1024 
#define EV_EVENT1 2048 
#define EV_EVENT2 0x1000 
#define SETXOFF 1 
#define SETXON 2 
#define SETRTS 3 
#define CLRRTS 4 
#define SETDTR 5 
#define CLRDTR 6 
#define RESETDEV 7 
#define SETBREAK 8 
#define CLRBREAK 9 
#define PURGE_TXABORT 1 
#define PURGE_RXABORT 2 
#define PURGE_TXCLEAR 4 
#define PURGE_RXCLEAR 8 
#define LPTx 128 
#define MS_CTS_ON ((DWORD)0x0010)
#define MS_DSR_ON ((DWORD)0x0020)
#define MS_RING_ON ((DWORD)0x0040)
#define MS_RLSD_ON ((DWORD)0x0080)
#define S_QUEUEEMPTY 0
#define S_THRESHOLD 1
#define S_ALLTHRESHOLD 2
#define S_NORMAL 0
#define S_LEGATO 1
#define S_STACCATO 2
#define S_PERIOD512 0 
#define S_PERIOD1024 1 
#define S_PERIOD2048 2 
#define S_PERIODVOICE 3 
#define S_WHITE512 4 
#define S_WHITE1024 5 
#define S_WHITE2048 6 
#define S_WHITEVOICE 7 
#define S_SERDVNA (-1) 
#define S_SEROFM (-2) 
#define S_SERMACT (-3) 
#define S_SERQFUL (-4) 
#define S_SERBDNT (-5) 
#define S_SERDLN (-6) 
#define S_SERDCC (-7) 
#define S_SERDTP (-8) 
#define S_SERDVL (-9) 
#define S_SERDMD (-10) 
#define S_SERDSH (-11) 
#define S_SERDPT (-12) 
#define S_SERDFQ (-13) 
#define S_SERDDR (-14) 
#define S_SERDSR (-15) 
#define S_SERDST (-16) 
#define NMPWAIT_WAIT_FOREVER 0xffffffff
#define NMPWAIT_NOWAIT 1
#define NMPWAIT_USE_DEFAULT_WAIT 0
#define FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_NAMES
#define FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_SEARCH
#define FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#define FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#define FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#define FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#define FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION
#define FILE_MAP_COPY SECTION_QUERY
#define FILE_MAP_WRITE SECTION_MAP_WRITE
#define FILE_MAP_READ SECTION_MAP_READ
#define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#define FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT 
#define OF_READ 0
#define OF_WRITE 1
#define OF_READWRITE 2
#define OF_SHARE_COMPAT 0
#define OF_SHARE_EXCLUSIVE 16
#define OF_SHARE_DENY_WRITE 32
#define OF_SHARE_DENY_READ 48
#define OF_SHARE_DENY_NONE 64
#define OF_PARSE 256
#define OF_DELETE 512
#define OF_VERIFY 1024
#define OF_CANCEL 2048
#define OF_CREATE 0x1000
#define OF_PROMPT 0x2000
#define OF_EXIST 0x4000
#define OF_REOPEN 0x8000
#define OFS_MAXPATHNAME 128
typedef struct _OFSTRUCT {
	BYTE cBytes;
	BYTE fFixedDisk;
	WORD nErrCode;
	WORD Reserved1;
	WORD Reserved2;
	CHAR szPathName[OFS_MAXPATHNAME];
} OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;
#ifndef NOWINBASEINTERLOCK
#ifndef _NTOS_
#if defined(_M_IA64) && !defined(RC_INVOKED)
/*
#define InterlockedIncrement _InterlockedIncrement
#define InterlockedIncrementAcquire _InterlockedIncrement_acq
#define InterlockedIncrementRelease _InterlockedIncrement_rel
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedDecrementAcquire _InterlockedDecrement_acq
#define InterlockedDecrementRelease _InterlockedDecrement_rel
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#define InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#define InterlockedExchangePointer _InterlockedExchangePointer
#define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer_rel
#define InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer_acq
#define InterlockedIncrement64 _InterlockedIncrement64
#define InterlockedDecrement64 _InterlockedDecrement64
#define InterlockedExchange64 _InterlockedExchange64
#define InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#define InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#define InterlockedCompareExchange64 _InterlockedCompareExchange64
#define InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#define InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel
LONGLONG InterlockedIncrement64 (LONGLONG volatile *Addend);
LONGLONG InterlockedDecrement64 (LONGLONG volatile *Addend);
LONG InterlockedIncrementAcquire (LONG volatile *Addend);
LONG InterlockedDecrementAcquire (LONG volatile *Addend);
LONG InterlockedIncrementRelease (LONG volatile *Addend);
LONG InterlockedDecrementRelease (LONG volatile *Addend);
LONGLONG InterlockedExchange64 (LONGLONG volatile *Target,LONGLONG Value);
LONGLONG InterlockedExchangeAcquire64 (LONGLONG volatile *Target,LONGLONG Value);
LONGLONG InterlockedExchangeAdd64 (LONGLONG volatile *Addend,LONGLONG Value);
LONGLONG InterlockedCompareExchange64 (LONGLONG volatile *Destination,LONGLONG ExChange,LONGLONG Comperand);
LONGLONG InterlockedCompareExchangeAcquire64 (LONGLONG volatile *Destination,LONGLONG ExChange,LONGLONG Comperand);
LONGLONG InterlockedCompareExchangeRelease64 (LONGLONG volatile *Destination,LONGLONG ExChange,LONGLONG Comperand);
LONG InterlockedIncrement (LONG volatile *lpAddend);
LONG InterlockedDecrement (LONG volatile *lpAddend);
LONG InterlockedExchange (LONG volatile *Target,LONG Value);
LONG InterlockedExchangeAdd (LONG volatile *Addend,LONG Value);
LONG InterlockedCompareExchange (LONG volatile *Destination,LONG ExChange,LONG Comperand);
LONG InterlockedCompareExchangeRelease (LONG volatile *Destination,LONG ExChange,LONG Comperand);
LONG InterlockedCompareExchangeAcquire (LONG volatile *Destination,LONG ExChange,LONG Comperand);
PVOID InterlockedExchangePointer (PVOID volatile *Target,PVOID Value);
PVOID InterlockedCompareExchangePointer (PVOID volatile *Destination,PVOID ExChange,PVOID Comperand);
PVOID InterlockedCompareExchangePointerAcquire (PVOID volatile *Destination,PVOID Exchange,PVOID Comperand);
PVOID InterlockedCompareExchangePointerRelease (PVOID volatile *Destination,PVOID Exchange,PVOID Comperand);
#if !defined(MIDL_PASS)
#if !defined (InterlockedAnd)
#define InterlockedAnd InterlockedAnd_Inline
LONG FORCEINLINE InterlockedAnd_Inline (LONG volatile *Target,LONG Set) {
	LONG i;
	LONG j;
	j=*Target;
	do {
		i=j;
		j=InterlockedCompareExchange(Target,i & Set,i);
	} while (i !=j);
	return j;
}
#endif
#if !defined (InterlockedOr)
#define InterlockedOr InterlockedOr_Inline
LONG FORCEINLINE InterlockedOr_Inline (LONG volatile *Target,LONG Set) {
	LONG i;
	LONG j;
	j=*Target;
	do {
		i=j;
		j=InterlockedCompareExchange(Target,i|Set,i);
	} while (i !=j);
	return j;
}
#endif
#if !defined (InterlockedXor)
#define InterlockedXor InterlockedXor_Inline
LONG FORCEINLINE InterlockedXor_Inline (LONG volatile *Target,LONG Set) {
	LONG i;
	LONG j;
	j=*Target;
	do {
		i=j;
		j=InterlockedCompareExchange(Target,i ^ Set,i);
	} while (i !=j);
	return j;
}
#endif
#if !defined (InterlockedAnd64)
#define InterlockedAnd64 InterlockedAnd64_Inline
LONGLONG FORCEINLINE InterlockedAnd64_Inline (LONGLONG volatile *Destination,LONGLONG Value) {
	LONGLONG Old;
	do {
		Old=*Destination;
	} while (InterlockedCompareExchange64(Destination,Old & Value,Old) !=Old);
	return Old;
}
#endif
#if !defined (InterlockedOr64)
#define InterlockedOr64 InterlockedOr64_Inline
LONGLONG FORCEINLINE InterlockedOr64_Inline (LONGLONG volatile *Destination,LONGLONG Value) {
	LONGLONG Old;
	do {
		Old=*Destination;
	} while (InterlockedCompareExchange64(Destination,Old|Value,Old) !=Old);
	return Old;
}
#endif
#if !defined (InterlockedXor64)
#define InterlockedXor64 InterlockedXor64_Inline
LONGLONG FORCEINLINE InterlockedXor64_Inline (LONGLONG volatile *Destination,LONGLONG Value) {
	LONGLONG Old;
	do {
		Old=*Destination;
	} while (InterlockedCompareExchange64(Destination,Old ^ Value,Old) !=Old);
	return Old;
}
#endif
#if !defined (InterlockedBitTestAndSet)
#define InterlockedBitTestAndSet InterlockedBitTestAndSet_Inline
BOOLEAN FORCEINLINE InterlockedBitTestAndSet_Inline (LONG *Base,LONG Bit) {
	LONG tBit;
	tBit=1<<(Bit & (sizeof (*Base)*8-1));
	return (BOOLEAN)((InterlockedOr(&Base[Bit/(sizeof(*Base)*8)],tBit)&tBit) !=0);
}
#endif
#if !defined (InterlockedBitTestAndReset)
#define InterlockedBitTestAndReset InterlockedBitTestAndReset_Inline
BOOLEAN FORCEINLINE InterlockedBitTestAndReset_Inline (LONG *Base,LONG Bit) {
	LONG tBit;
	tBit=1<<(Bit & (sizeof (*Base)*8-1));
	return (BOOLEAN)((InterlockedAnd(&Base[Bit/(sizeof(*Base)*8)],~tBit)&tBit) !=0);
}
#endif
#if !defined (InterlockedBitTestAndComplement)
#define InterlockedBitTestAndComplement InterlockedBitTestAndComplement_Inline
BOOLEAN FORCEINLINE InterlockedBitTestAndComplement_Inline (LONG *Base,LONG Bit) {
	LONG tBit;
	tBit=1<<(Bit & (sizeof (*Base)*8-1));
	return (BOOLEAN)((InterlockedXor(&Base[Bit/(sizeof(*Base)*8)],tBit)&tBit) !=0);
}
#endif
#endif

#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedIncrement_acq)
#pragma intrinsic(_InterlockedIncrement_rel)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedDecrement_acq)
#pragma intrinsic(_InterlockedDecrement_rel)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedCompareExchange_acq)
#pragma intrinsic(_InterlockedCompareExchange_rel)
#pragma intrinsic(_InterlockedExchangePointer)
#pragma intrinsic(_InterlockedCompareExchangePointer)
#pragma intrinsic(_InterlockedCompareExchangePointer_acq)
#pragma intrinsic(_InterlockedCompareExchangePointer_rel)
#pragma intrinsic(_InterlockedIncrement64)
#pragma intrinsic(_InterlockedDecrement64)
#pragma intrinsic(_InterlockedExchange64)
#pragma intrinsic(_InterlockedExchange64_acq)
#pragma intrinsic(_InterlockedCompareExchange64)
#pragma intrinsic(_InterlockedCompareExchange64_acq)
#pragma intrinsic(_InterlockedCompareExchange64_rel)
#pragma intrinsic(_InterlockedExchangeAdd64)
#elif defined(_M_AMD64) && !defined(RC_INVOKED)
#define InterlockedIncrement _InterlockedIncrement
#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedDecrementAcquire InterlockedDecrement
#define InterlockedDecrementRelease InterlockedDecrement
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire InterlockedCompareExchange
#define InterlockedCompareExchangeRelease InterlockedCompareExchange
#define InterlockedExchangePointer _InterlockedExchangePointer
#define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer
#define InterlockedAnd64 _InterlockedAnd64
#define InterlockedOr64 _InterlockedOr64
#define InterlockedXor64 _InterlockedXor64
#define InterlockedIncrement64 _InterlockedIncrement64
#define InterlockedDecrement64 _InterlockedDecrement64
#define InterlockedExchange64 _InterlockedExchange64
#define InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#define InterlockedCompareExchange64 _InterlockedCompareExchange64
#define InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#define InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
LONG InterlockedIncrement (LONG volatile *Addend);
LONG InterlockedDecrement (LONG volatile *Addend);
LONG InterlockedExchange (LONG volatile *Target,LONG Value);
LONG InterlockedExchangeAdd (LONG volatile *Addend,LONG Value);
LONG InterlockedCompareExchange (LONG volatile *Destination,LONG ExChange,LONG Comperand);
PVOID InterlockedCompareExchangePointer (PVOID volatile *Destination,PVOID Exchange,PVOID Comperand);
PVOID InterlockedExchangePointer (PVOID volatile *Target,PVOID Value);
LONG64 InterlockedAnd64 (LONG64 volatile *Destination,LONG64 Value);
LONG64 InterlockedOr64 (LONG64 volatile *Destination,LONG64 Value);
LONG64 InterlockedXor64 (LONG64 volatile *Destination,LONG64 Value);
LONG64 InterlockedIncrement64 (LONG64 volatile *Addend);
LONG64 InterlockedDecrement64 (LONG64 volatile *Addend);
LONG64 InterlockedExchange64 (LONG64 volatile *Target,LONG64 Value);
LONG64 InterlockedExchangeAdd64 (LONG64 volatile *Addend,LONG64 Value);
LONG64 InterlockedCompareExchange64 (LONG64 volatile *Destination,LONG64 ExChange,LONG64 Comperand);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedExchangePointer)
#pragma intrinsic(_InterlockedCompareExchangePointer)
#else 
WINBASEAPI LONG WINAPI InterlockedIncrement (LONG volatile *lpAddend);
WINBASEAPI LONG WINAPI InterlockedDecrement (LONG volatile *lpAddend);
WINBASEAPI LONG WINAPI InterlockedExchange (LONG volatile *Target,LONG Value);
#define InterlockedExchangePointer(Target,Value)(PVOID)InterlockedExchange((PLONG)(Target),(LONG)(Value))
WINBASEAPI LONG WINAPI InterlockedExchangeAdd (LONG volatile *Addend,LONG Value);
WINBASEAPI LONG WINAPI InterlockedCompareExchange (LONG volatile *Destination,LONG Exchange,LONG Comperand);
#if (_WIN32_WINNT >=0x0502)
WINBASEAPI LONGLONG WINAPI InterlockedCompareExchange64 (LONGLONG volatile *Destination,LONGLONG Exchange,LONGLONG Comperand);
#endif 
#if !defined(MIDL_PASS)
#if (_WIN32_WINNT >=0x0502)
LONGLONG FORCEINLINE InterlockedAnd64 (LONGLONG volatile *Destination,LONGLONG Value) {
	LONGLONG Old;
	do {
		Old=*Destination;
	} while (InterlockedCompareExchange64(Destination,Old & Value,Old) !=Old);
	return Old;
}
LONGLONG FORCEINLINE InterlockedOr64 (LONGLONG volatile *Destination,LONGLONG Value) {
	LONGLONG Old;
	do {
		Old=*Destination;
	} while (InterlockedCompareExchange64(Destination,Old|Value,Old) !=Old);
	return Old;
}
LONGLONG FORCEINLINE InterlockedXor64 (LONGLONG volatile *Destination,LONGLONG Value) {
	LONGLONG Old;
	do {
		Old=*Destination;
	} while (InterlockedCompareExchange64(Destination,Old ^ Value,Old) !=Old);
	return Old;
}
LONGLONG FORCEINLINE InterlockedIncrement64 (LONGLONG volatile *Addend) {
	LONGLONG Old;
	do {
		Old=*Addend;
	} while (InterlockedCompareExchange64(Addend,Old + 1,Old) !=Old);
	return Old + 1;
}
LONGLONG FORCEINLINE InterlockedDecrement64 (LONGLONG volatile *Addend) {
	LONGLONG Old;
	do {
		Old=*Addend;
	} while (InterlockedCompareExchange64(Addend,Old - 1,Old) !=Old);
	return Old - 1;
}
LONGLONG FORCEINLINE InterlockedExchange64 (LONGLONG volatile *Target,LONGLONG Value) {
	LONGLONG Old;
	do {
		Old=*Target;
	} while (InterlockedCompareExchange64(Target,Value,Old) !=Old);
	return Old;
}
LONGLONG FORCEINLINE InterlockedExchangeAdd64(LONGLONG volatile *Addend,LONGLONG Value) {
	LONGLONG Old;
	do {
		Old=*Addend;
	} while (InterlockedCompareExchange64(Addend,Old + Value,Old) !=Old);
	return Old;
}
#endif 
#endif
#ifdef __cplusplus
FORCEINLINE PVOID 
#if !defined(_M_CEE_PURE)
#endif
__InlineInterlockedCompareExchangePointer (PVOID volatile *Destination,PVOID ExChange,PVOID Comperand) {
	return((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG volatile *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
}
#define InterlockedCompareExchangePointer __InlineInterlockedCompareExchangePointer
#else
#define InterlockedCompareExchangePointer(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG volatile *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#endif 
#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedDecrementAcquire InterlockedDecrement
#define InterlockedDecrementRelease InterlockedDecrement
#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedCompareExchangeAcquire InterlockedCompareExchange
#define InterlockedCompareExchangeRelease InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#define InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#define InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer
#endif 
#if defined(_SLIST_HEADER_) && !defined(_NTOSP_)
WINBASEAPI VOID WINAPI InitializeSListHead (PSLIST_HEADER ListHead);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPopEntrySList (PSLIST_HEADER ListHead);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushEntrySList (PSLIST_HEADER ListHead,PSLIST_ENTRY ListEntry);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedFlushSList (PSLIST_HEADER ListHead);
WINBASEAPI USHORT WINAPI QueryDepthSList (PSLIST_HEADER ListHead);
*/
#endif 
#endif 
#endif 
/*
WINBASEAPI BOOL WINAPI FreeResource(HGLOBAL hResData);
WINBASEAPI LPVOID WINAPI LockResource(HGLOBAL hResData);
*/
#define UnlockResource(hResData) ((hResData),0)
#define MAXINTATOM 0xc000
#define MAKEINTATOM(i)(LPTSTR)((ULONG_PTR)((WORD)(i)))
#define INVALID_ATOM ((ATOM)0)
// int WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd);
/*
WINBASEAPI BOOL WINAPI FreeLibrary (HMODULE hLibModule);
WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread (HMODULE hLibModule,DWORD dwExitCode);
WINBASEAPI BOOL WINAPI DisableThreadLibraryCalls (HMODULE hLibModule);
WINBASEAPI FARPROC WINAPI GetProcAddress (HMODULE hModule,LPCSTR lpProcName);
WINBASEAPI DWORD WINAPI GetVersion (VOID);
WINBASEAPI HGLOBAL WINAPI GlobalAlloc (UINT uFlags,SIZE_T dwBytes);
WINBASEAPI HGLOBAL WINAPI GlobalReAlloc (HGLOBAL hMem,SIZE_T dwBytes,UINT uFlags);
WINBASEAPI SIZE_T WINAPI GlobalSize (HGLOBAL hMem);
WINBASEAPI UINT WINAPI GlobalFlags (HGLOBAL hMem);
WINBASEAPI LPVOID WINAPI GlobalLock (HGLOBAL hMem);
WINBASEAPI HGLOBAL WINAPI GlobalHandle (LPCVOID pMem);
WINBASEAPI BOOL WINAPI GlobalUnlock(HGLOBAL hMem);
WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
WINBASEAPI SIZE_T WINAPI GlobalCompact(DWORD dwMinFree);
WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
WINBASEAPI BOOL WINAPI GlobalUnWire(HGLOBAL hMem);
WINBASEAPI VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);
*/
typedef struct _MEMORYSTATUSEX {
	DWORD dwLength;
	DWORD dwMemoryLoad;
	DWORDLONG ullTotalPhys;
	DWORDLONG ullAvailPhys;
	DWORDLONG ullTotalPageFile;
	DWORDLONG ullAvailPageFile;
	DWORDLONG ullTotalVirtual;
	DWORDLONG ullAvailVirtual;
	DWORDLONG ullAvailExtendedVirtual;
} MEMORYSTATUSEX,*LPMEMORYSTATUSEX;
WINBASEAPI BOOL WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer);
WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,SIZE_T uBytes);
WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,SIZE_T uBytes,UINT uFlags);
WINBASEAPI LPVOID WINAPI LocalLock(HLOCAL hMem);
WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
WINBASEAPI BOOL WINAPI LocalUnlock(HLOCAL hMem);
WINBASEAPI SIZE_T WINAPI LocalSize(HLOCAL hMem);
WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
WINBASEAPI SIZE_T WINAPI LocalShrink(HLOCAL hMem,UINT cbNewSize);
WINBASEAPI SIZE_T WINAPI LocalCompact(UINT uMinFree);
WINBASEAPI BOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lpBaseAddress,SIZE_T dwSize);
WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect);
WINBASEAPI BOOL WINAPI VirtualFree(LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
WINBASEAPI BOOL WINAPI VirtualProtect(LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
// WINBASEAPI SIZE_T WINAPI VirtualQuery(LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,SIZE_T dwLength);
WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect);
WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lpBaseAddress,SIZE_T dwRegionSize,PVOID *lpAddresses,ULONG_PTR *lpdwCount,PULONG lpdwGranularity);
WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lpBaseAddress,SIZE_T dwRegionSize);
WINBASEAPI SIZE_T WINAPI GetLargePageMinimum(VOID);
WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD FirmwareTableProviderSignature,PVOID pFirmwareTableEnumBuffer,DWORD BufferSize);
WINBASEAPI UINT WINAPI GetSystemFirmwareTable(DWORD FirmwareTableProviderSignature,DWORD FirmwareTableID,PVOID pFirmwareTableBuffer,DWORD BufferSize);
WINBASEAPI BOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
WINBASEAPI BOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
// WINBASEAPI SIZE_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,SIZE_T dwLength);
WINBASEAPI HANDLE WINAPI HeapCreate(DWORD flOptions,SIZE_T dwInitialSize,SIZE_T dwMaximumSize);
WINBASEAPI BOOL WINAPI HeapDestroy(HANDLE hHeap);
WINBASEAPI LPVOID WINAPI HeapAlloc(HANDLE hHeap,DWORD dwFlags,SIZE_T dwBytes);
WINBASEAPI LPVOID WINAPI HeapReAlloc(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem,SIZE_T dwBytes);
WINBASEAPI BOOL WINAPI HeapFree(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem);
WINBASEAPI SIZE_T WINAPI HeapSize(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
WINBASEAPI BOOL WINAPI HeapValidate(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
WINBASEAPI SIZE_T WINAPI HeapCompact(HANDLE hHeap,DWORD dwFlags);
WINBASEAPI HANDLE WINAPI GetProcessHeap(VOID );
WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD NumberOfHeaps,PHANDLE ProcessHeaps);
/*
typedef struct _PROCESS_HEAP_ENTRY {
	PVOID lpData;
	DWORD cbData;
	BYTE cbOverhead;
	BYTE iRegionIndex;
	WORD wFlags;
	union {
		struct {
			HANDLE hMem;
			DWORD dwReserved[ 3 ];
		} Block;
		struct {
			DWORD dwCommittedSize;
			DWORD dwUnCommittedSize;
			LPVOID lpFirstBlock;
			LPVOID lpLastBlock;
		} Region;
	};
} PROCESS_HEAP_ENTRY,*LPPROCESS_HEAP_ENTRY,*PPROCESS_HEAP_ENTRY;
#define PROCESS_HEAP_REGION 1
#define PROCESS_HEAP_UNCOMMITTED_RANGE 2
#define PROCESS_HEAP_ENTRY_BUSY 4
#define PROCESS_HEAP_ENTRY_MOVEABLE 16
#define PROCESS_HEAP_ENTRY_DDESHARE 32
WINBASEAPI BOOL WINAPI HeapLock(HANDLE hHeap);
WINBASEAPI BOOL WINAPI HeapUnlock(HANDLE hHeap);
WINBASEAPI BOOL WINAPI HeapWalk(HANDLE hHeap,LPPROCESS_HEAP_ENTRY lpEntry);
WINBASEAPI BOOL WINAPI HeapSetInformation (HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,SIZE_T HeapInformationLength);
WINBASEAPI BOOL WINAPI HeapQueryInformation (HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,SIZE_T HeapInformationLength,PSIZE_T ReturnLength);
*/
#define SCS_32BIT_BINARY 0
#define SCS_DOS_BINARY 1
#define SCS_WOW_BINARY 2
#define SCS_PIF_BINARY 3
#define SCS_POSIX_BINARY 4
#define SCS_OS216_BINARY 5
#define SCS_64BIT_BINARY 6
#if defined(_WIN64)
# define SCS_THIS_PLATFORM_BINARY SCS_64BIT_BINARY
#else
# define SCS_THIS_PLATFORM_BINARY SCS_32BIT_BINARY
#endif
WINBASEAPI BOOL WINAPI GetBinaryTypeA(LPCSTR lpApplicationName,LPDWORD lpBinaryType);
WINBASEAPI BOOL WINAPI GetBinaryTypeW(LPCWSTR lpApplicationName,LPDWORD lpBinaryType);
#ifdef UNICODE
#define GetBinaryType GetBinaryTypeW
#else
#define GetBinaryType GetBinaryTypeA
#endif 
WINBASEAPI DWORD WINAPI GetShortPathNameA(LPCSTR lpszLongPath,LPSTR lpszShortPath,DWORD cchBuffer);
WINBASEAPI DWORD WINAPI GetShortPathNameW(LPCWSTR lpszLongPath,LPWSTR lpszShortPath,DWORD cchBuffer);
#ifdef UNICODE
#define GetShortPathName GetShortPathNameW
#else
#define GetShortPathName GetShortPathNameA
#endif 
WINBASEAPI DWORD WINAPI GetLongPathNameA(LPCSTR lpszShortPath,LPSTR lpszLongPath,DWORD cchBuffer);
WINBASEAPI DWORD WINAPI GetLongPathNameW(LPCWSTR lpszShortPath,LPWSTR lpszLongPath,DWORD cchBuffer);
#ifdef UNICODE
#define GetLongPathName GetLongPathNameW
#else
#define GetLongPathName GetLongPathNameA
#endif 
WINBASEAPI BOOL WINAPI GetProcessAffinityMask(HANDLE hProcess,PDWORD_PTR lpProcessAffinityMask,PDWORD_PTR lpSystemAffinityMask);
WINBASEAPI BOOL WINAPI SetProcessAffinityMask(HANDLE hProcess,DWORD_PTR dwProcessAffinityMask);
#if _WIN32_WINNT >=0x0501
WINBASEAPI BOOL WINAPI GetProcessHandleCount(HANDLE hProcess,PDWORD pdwHandleCount);
#endif 
WINBASEAPI BOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
WINBASEAPI BOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
WINBASEAPI BOOL WINAPI GetProcessWorkingSetSize(HANDLE hProcess,PSIZE_T lpMinimumWorkingSetSize,PSIZE_T lpMaximumWorkingSetSize);
WINBASEAPI BOOL WINAPI GetProcessWorkingSetSizeEx(HANDLE hProcess,PSIZE_T lpMinimumWorkingSetSize,PSIZE_T lpMaximumWorkingSetSize,PDWORD Flags);
WINBASEAPI BOOL WINAPI SetProcessWorkingSetSize(HANDLE hProcess,SIZE_T dwMinimumWorkingSetSize,SIZE_T dwMaximumWorkingSetSize);
WINBASEAPI BOOL WINAPI SetProcessWorkingSetSizeEx(HANDLE hProcess,SIZE_T dwMinimumWorkingSetSize,SIZE_T dwMaximumWorkingSetSize,DWORD Flags);
WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,BOOL bInheritHandle,DWORD dwProcessId);
WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
// WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT uExitCode);
WINBASEAPI BOOL WINAPI TerminateProcess(HANDLE hProcess,UINT uExitCode);
WINBASEAPI BOOL WINAPI GetExitCodeProcess(HANDLE hProcess,LPDWORD lpExitCode);
WINBASEAPI VOID WINAPI FatalExit(int ExitCode);
WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID);
WINBASEAPI LPWCH WINAPI GetEnvironmentStringsW(VOID);
#ifdef UNICODE
#define GetEnvironmentStrings GetEnvironmentStringsW
#else
#define GetEnvironmentStringsA GetEnvironmentStrings
#endif 
WINBASEAPI BOOL WINAPI SetEnvironmentStringsA(LPCH NewEnvironment);
WINBASEAPI BOOL WINAPI SetEnvironmentStringsW(LPWCH NewEnvironment);
#ifdef UNICODE
#define SetEnvironmentStrings SetEnvironmentStringsW
#else
#define SetEnvironmentStrings SetEnvironmentStringsA
#endif 
WINBASEAPI BOOL WINAPI FreeEnvironmentStringsA(LPCH);
WINBASEAPI BOOL WINAPI FreeEnvironmentStringsW(LPWCH);
#ifdef UNICODE
#define FreeEnvironmentStrings FreeEnvironmentStringsW
#else
#define FreeEnvironmentStrings FreeEnvironmentStringsA
#endif 
WINBASEAPI VOID WINAPI RaiseException(DWORD dwExceptionCode,DWORD dwExceptionFlags,DWORD nNumberOfArguments,CONST ULONG_PTR *lpArguments);
__callback WINBASEAPI LONG WINAPI UnhandledExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo);
/*
typedef LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(struct _EXCEPTION_POINTERS *ExceptionInfo);
typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;
WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
*/
#if(_WIN32_WINNT >=0x0400)
#define FIBER_FLAG_FLOAT_SWITCH 1 
WINBASEAPI LPVOID WINAPI CreateFiber(SIZE_T dwStackSize,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
WINBASEAPI LPVOID WINAPI CreateFiberEx(SIZE_T dwStackCommitSize,SIZE_T dwStackReserveSize,DWORD dwFlags,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
WINBASEAPI LPVOID WINAPI ConvertThreadToFiber(LPVOID lpParameter);
WINBASEAPI LPVOID WINAPI ConvertThreadToFiberEx(LPVOID lpParameter,DWORD dwFlags);
WINBASEAPI BOOL WINAPI ConvertFiberToThread(VOID);
WINBASEAPI VOID WINAPI SwitchToFiber(LPVOID lpFiber);
WINBASEAPI BOOL WINAPI SwitchToThread(VOID);
#endif 
/*
WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,SIZE_T dwStackSize,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_ATTRIBUTES lpThreadAttributes,SIZE_T dwStackSize,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
WINBASEAPI BOOL WINAPI SetThreadStackGuarantee (PULONG StackSizeInBytes);
WINBASEAPI DWORD WINAPI GetProcessIdOfThread(HANDLE Thread);
WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
*/
WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
WINBASEAPI DWORD WINAPI GetCurrentProcessorNumber(VOID);
WINBASEAPI DWORD_PTR WINAPI SetThreadAffinityMask(HANDLE hThread,DWORD_PTR dwThreadAffinityMask);
#if(_WIN32_WINNT >=0x0400)
WINBASEAPI DWORD WINAPI SetThreadIdealProcessor(HANDLE hThread,DWORD dwIdealProcessor);
#endif 
WINBASEAPI BOOL WINAPI SetProcessPriorityBoost(HANDLE hProcess,BOOL bDisablePriorityBoost);
WINBASEAPI BOOL WINAPI GetProcessPriorityBoost(HANDLE hProcess,PBOOL pDisablePriorityBoost);
WINBASEAPI BOOL WINAPI RequestWakeupLatency(LATENCY_TIME latency);
WINBASEAPI BOOL WINAPI IsSystemResumeAutomatic(VOID);
WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,BOOL bInheritHandle,DWORD dwThreadId);
WINBASEAPI BOOL WINAPI SetThreadPriority(HANDLE hThread,int nPriority);
WINBASEAPI BOOL WINAPI SetThreadPriorityBoost(HANDLE hThread,BOOL bDisablePriorityBoost);
WINBASEAPI BOOL WINAPI GetThreadPriorityBoost(HANDLE hThread,PBOOL pDisablePriorityBoost);
WINBASEAPI int WINAPI GetThreadPriority(HANDLE hThread);
WINBASEAPI BOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
#if _WIN32_WINNT >=0x0501
WINBASEAPI BOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
#endif 
// WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dwExitCode);
WINBASEAPI BOOL WINAPI TerminateThread(HANDLE hThread,DWORD dwExitCode);
WINBASEAPI BOOL WINAPI GetExitCodeThread(HANDLE hThread,LPDWORD lpExitCode);
// WINBASEAPI BOOL WINAPI GetThreadSelectorEntry(HANDLE hThread,DWORD dwSelector,LPLDT_ENTRY lpSelectorEntry);
WINBASEAPI EXECUTION_STATE WINAPI SetThreadExecutionState(EXECUTION_STATE esFlags);
WINBASEAPI DWORD WINAPI GetLastError(VOID);
WINBASEAPI VOID WINAPI SetLastError(DWORD dwErrCode);
#if !defined(RC_INVOKED) 
#if defined(WINBASE_DECLARE_RESTORE_LAST_ERROR)
WINBASEAPI VOID WINAPI RestoreLastError(DWORD dwErrCode);
typedef VOID (WINAPI* PRESTORE_LAST_ERROR)(DWORD);
#define RESTORE_LAST_ERROR_NAME_A "RestoreLastError"
#define RESTORE_LAST_ERROR_NAME_W L"RestoreLastError"
#define RESTORE_LAST_ERROR_NAME TEXT("RestoreLastError")
#endif
#endif
#define HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->Internal) !=STATUS_PENDING)
WINBASEAPI BOOL WINAPI GetOverlappedResult(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lpNumberOfBytesTransferred,BOOL bWait);
WINBASEAPI HANDLE WINAPI CreateIoCompletionPort(HANDLE FileHandle,HANDLE ExistingCompletionPort,ULONG_PTR CompletionKey,DWORD NumberOfConcurrentThreads);
WINBASEAPI BOOL WINAPI GetQueuedCompletionStatus(HANDLE CompletionPort,LPDWORD lpNumberOfBytesTransferred,PULONG_PTR lpCompletionKey,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
WINBASEAPI BOOL WINAPI PostQueuedCompletionStatus(HANDLE CompletionPort,DWORD dwNumberOfBytesTransferred,ULONG_PTR dwCompletionKey,LPOVERLAPPED lpOverlapped);
#define SEM_FAILCRITICALERRORS 1
#define SEM_NOGPFAULTERRORBOX 2
#define SEM_NOALIGNMENTFAULTEXCEPT 4
#define SEM_NOOPENFILEERRORBOX 0x8000
WINBASEAPI UINT WINAPI SetErrorMode(UINT uMode);
WINBASEAPI BOOL WINAPI ReadProcessMemory(HANDLE hProcess,LPCVOID lpBaseAddress,LPVOID lpBuffer,SIZE_T nSize,SIZE_T * lpNumberOfBytesRead);
WINBASEAPI BOOL WINAPI WriteProcessMemory(HANDLE hProcess,LPVOID lpBaseAddress,LPCVOID lpBuffer,SIZE_T nSize,SIZE_T * lpNumberOfBytesWritten);
#if !defined(MIDL_PASS)
WINBASEAPI BOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
WINBASEAPI BOOL WINAPI SetThreadContext(HANDLE hThread,CONST CONTEXT *lpContext);
#endif
WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);
#if(_WIN32_WINNT >=0x0400)||(_WIN32_WINDOWS > 0x0400)
typedef VOID 
(APIENTRY *PAPCFUNC)(ULONG_PTR dwParam);
WINBASEAPI DWORD WINAPI QueueUserAPC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dwData);
#endif 
#if (_WIN32_WINNT >=0x0400)||(_WIN32_WINDOWS > 0x0400)
WINBASEAPI BOOL WINAPI IsDebuggerPresent(VOID);
#endif
#if _WIN32_WINNT >=0x0501
WINBASEAPI BOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
#endif 
WINBASEAPI VOID WINAPI DebugBreak(VOID);
// WINBASEAPI BOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
WINBASEAPI BOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dwContinueStatus);
WINBASEAPI BOOL WINAPI DebugActiveProcess(DWORD dwProcessId);
WINBASEAPI BOOL WINAPI DebugActiveProcessStop(DWORD dwProcessId);
WINBASEAPI BOOL WINAPI DebugSetProcessKillOnExit(BOOL KillOnExit);
WINBASEAPI BOOL WINAPI DebugBreakProcess (HANDLE Process);
/*
WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
#if (_WIN32_WINNT >=0x0403)
WINBASEAPI BOOL WINAPI InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount);
WINBASEAPI DWORD WINAPI SetCriticalSectionSpinCount(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount);
#endif
#if(_WIN32_WINNT >=0x0400)
WINBASEAPI BOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
#endif 
WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
*/
WINBASEAPI BOOL WINAPI SetEvent(HANDLE hEvent);
WINBASEAPI BOOL WINAPI ResetEvent(HANDLE hEvent);
WINBASEAPI BOOL WINAPI PulseEvent(HANDLE hEvent);
WINBASEAPI BOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG lReleaseCount,LPLONG lpPreviousCount);
WINBASEAPI BOOL WINAPI ReleaseMutex(HANDLE hMutex);
WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
WINBASEAPI DWORD WINAPI WaitForMultipleObjects(DWORD nCount,CONST HANDLE *lpHandles,BOOL bWaitAll,DWORD dwMilliseconds);
WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
/*
WINBASEAPI HGLOBAL WINAPI LoadResource(HMODULE hModule,HRSRC hResInfo);
WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
*/
WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
WINBASEAPI BOOL WINAPI InitAtomTable(DWORD nSize);
WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
WINBASEAPI UINT WINAPI SetHandleCount(UINT uNumber);
WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
WINBASEAPI BOOL WINAPI LockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh);
WINBASEAPI BOOL WINAPI UnlockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToUnlockLow,DWORD nNumberOfBytesToUnlockHigh);
WINBASEAPI BOOL WINAPI LockFileEx(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh,LPOVERLAPPED lpOverlapped);
#define LOCKFILE_FAIL_IMMEDIATELY 1
#define LOCKFILE_EXCLUSIVE_LOCK 2
WINBASEAPI BOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD nNumberOfBytesToUnlockLow,DWORD nNumberOfBytesToUnlockHigh,LPOVERLAPPED lpOverlapped);
typedef struct _BY_HANDLE_FILE_INFORMATION {
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD dwVolumeSerialNumber;
	DWORD nFileSizeHigh;
	DWORD nFileSizeLow;
	DWORD nNumberOfLinks;
	DWORD nFileIndexHigh;
	DWORD nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;
WINBASEAPI BOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
WINBASEAPI DWORD WINAPI GetFileSize(HANDLE hFile,LPDWORD lpFileSizeHigh);
WINBASEAPI BOOL WINAPI GetFileSizeEx(HANDLE hFile,PLARGE_INTEGER lpFileSize);
WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
WINBASEAPI BOOL WINAPI SetStdHandle(DWORD nStdHandle,HANDLE hHandle);
WINBASEAPI BOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped);
WINBASEAPI BOOL WINAPI ReadFile(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,LPOVERLAPPED lpOverlapped);
WINBASEAPI BOOL WINAPI FlushFileBuffers(HANDLE hFile);
WINBASEAPI BOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dwIoControlCode,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped);
WINBASEAPI BOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
WINBASEAPI BOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
WINBASEAPI BOOL WINAPI GetDevicePowerState(HANDLE hDevice,BOOL *pfOn);
WINBASEAPI BOOL WINAPI SetMessageWaitingIndicator(HANDLE hMsgIndicator,ULONG ulMsgCount);
WINBASEAPI BOOL WINAPI SetEndOfFile(HANDLE hFile);
WINBASEAPI DWORD WINAPI SetFilePointer(HANDLE hFile,LONG lDistanceToMove,PLONG lpDistanceToMoveHigh,DWORD dwMoveMethod);
WINBASEAPI BOOL WINAPI SetFilePointerEx(HANDLE hFile,LARGE_INTEGER liDistanceToMove,PLARGE_INTEGER lpNewFilePointer,DWORD dwMoveMethod);
WINBASEAPI BOOL WINAPI FindClose(HANDLE hFindFile);
WINBASEAPI BOOL WINAPI GetFileTime(HANDLE hFile,LPFILETIME lpCreationTime,LPFILETIME lpLastAccessTime,LPFILETIME lpLastWriteTime);
WINBASEAPI BOOL WINAPI SetFileTime(HANDLE hFile,CONST FILETIME *lpCreationTime,CONST FILETIME *lpLastAccessTime,CONST FILETIME *lpLastWriteTime);
WINBASEAPI BOOL WINAPI SetFileValidData(HANDLE hFile,LONGLONG ValidDataLength);
WINBASEAPI BOOL WINAPI SetFileShortNameA(HANDLE hFile,LPCSTR lpShortName);
WINBASEAPI BOOL WINAPI SetFileShortNameW(HANDLE hFile,LPCWSTR lpShortName);
#ifdef UNICODE
#define SetFileShortName SetFileShortNameW
#else
#define SetFileShortName SetFileShortNameA
#endif 
WINBASEAPI BOOL WINAPI CloseHandle(HANDLE hObject);
WINBASEAPI BOOL WINAPI DuplicateHandle(HANDLE hSourceProcessHandle,HANDLE hSourceHandle,HANDLE hTargetProcessHandle,LPHANDLE lpTargetHandle,DWORD dwDesiredAccess,BOOL bInheritHandle,DWORD dwOptions);
WINBASEAPI BOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
WINBASEAPI BOOL WINAPI SetHandleInformation(HANDLE hObject,DWORD dwMask,DWORD dwFlags);
#define HANDLE_FLAG_INHERIT 1
#define HANDLE_FLAG_PROTECT_FROM_CLOSE 2
#define HINSTANCE_ERROR 32
WINBASEAPI DWORD WINAPI LoadModule(LPCSTR lpModuleName,LPVOID lpParameterBlock);
WINBASEAPI UINT WINAPI WinExec(LPCSTR lpCmdLine,UINT uCmdShow);
/*
WINBASEAPI BOOL WINAPI ClearCommBreak(HANDLE hFile);
// WINBASEAPI BOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
WINBASEAPI BOOL WINAPI SetupComm(HANDLE hFile,DWORD dwInQueue,DWORD dwOutQueue);
WINBASEAPI BOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
// WINBASEAPI BOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
WINBASEAPI BOOL WINAPI GetCommMask(HANDLE hFile,LPDWORD lpEvtMask);
WINBASEAPI BOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
WINBASEAPI BOOL WINAPI GetCommModemStatus(HANDLE hFile,LPDWORD lpModemStat);
WINBASEAPI BOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
WINBASEAPI BOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
WINBASEAPI BOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
WINBASEAPI BOOL WINAPI SetCommBreak(HANDLE hFile);
// WINBASEAPI BOOL WINAPI SetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dwSize);
WINBASEAPI BOOL WINAPI SetCommMask(HANDLE hFile,DWORD dwEvtMask);
WINBASEAPI BOOL WINAPI SetCommState(HANDLE hFile,LPDCB lpDCB);
WINBASEAPI BOOL WINAPI SetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
WINBASEAPI BOOL WINAPI TransmitCommChar(HANDLE hFile,char cChar);
WINBASEAPI BOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lpEvtMask,LPOVERLAPPED lpOverlapped);
*/
WINBASEAPI DWORD WINAPI SetTapePosition(HANDLE hDevice,DWORD dwPositionMethod,DWORD dwPartition,DWORD dwOffsetLow,DWORD dwOffsetHigh,BOOL bImmediate);
WINBASEAPI DWORD WINAPI GetTapePosition(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdwPartition,LPDWORD lpdwOffsetLow,LPDWORD lpdwOffsetHigh);
WINBASEAPI DWORD WINAPI PrepareTape(HANDLE hDevice,DWORD dwOperation,BOOL bImmediate);
WINBASEAPI DWORD WINAPI EraseTape(HANDLE hDevice,DWORD dwEraseType,BOOL bImmediate);
WINBASEAPI DWORD WINAPI CreateTapePartition(HANDLE hDevice,DWORD dwPartitionMethod,DWORD dwCount,DWORD dwSize);
WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dwTapemarkCount,BOOL bImmediate);
WINBASEAPI DWORD WINAPI GetTapeStatus(HANDLE hDevice);
WINBASEAPI DWORD WINAPI GetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdwSize,LPVOID lpTapeInformation);
#define GET_TAPE_MEDIA_INFORMATION 0
#define GET_TAPE_DRIVE_INFORMATION 1
WINBASEAPI DWORD WINAPI SetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPVOID lpTapeInformation);
#define SET_TAPE_MEDIA_INFORMATION 0
#define SET_TAPE_DRIVE_INFORMATION 1
WINBASEAPI BOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
WINBASEAPI int WINAPI MulDiv(int nNumber,int nNumerator,int nDenominator);
WINBASEAPI VOID WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime);
WINBASEAPI VOID WINAPI GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);
WINBASEAPI BOOL WINAPI SetSystemTime(CONST SYSTEMTIME *lpSystemTime);
WINBASEAPI VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
WINBASEAPI BOOL WINAPI SetLocalTime(CONST SYSTEMTIME *lpSystemTime);
// WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
#if _WIN32_WINNT >=0x0501
WINBASEAPI BOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdwQuotaUsed);
BOOL WINAPI GetSystemTimes(LPFILETIME lpIdleTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
#endif 
#if _WIN32_WINNT >=0x0501
// WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
#endif
WINBASEAPI BOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);
typedef struct _TIME_ZONE_INFORMATION {
	LONG Bias;
	WCHAR StandardName[ 32 ];
	SYSTEMTIME StandardDate;
	LONG StandardBias;
	WCHAR DaylightName[ 32 ];
	SYSTEMTIME DaylightDate;
	LONG DaylightBias;
} TIME_ZONE_INFORMATION,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;
WINBASEAPI BOOL WINAPI SystemTimeToTzSpecificLocalTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpUniversalTime,LPSYSTEMTIME lpLocalTime);
WINBASEAPI BOOL WINAPI TzSpecificLocalTimeToSystemTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpLocalTime,LPSYSTEMTIME lpUniversalTime);
WINBASEAPI DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
WINBASEAPI BOOL WINAPI SetTimeZoneInformation(CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation);
WINBASEAPI BOOL WINAPI SystemTimeToFileTime(CONST SYSTEMTIME *lpSystemTime,LPFILETIME lpFileTime);
WINBASEAPI BOOL WINAPI FileTimeToLocalFileTime(CONST FILETIME *lpFileTime,LPFILETIME lpLocalFileTime);
WINBASEAPI BOOL WINAPI LocalFileTimeToFileTime(CONST FILETIME *lpLocalFileTime,LPFILETIME lpFileTime);
WINBASEAPI BOOL WINAPI FileTimeToSystemTime(CONST FILETIME *lpFileTime,LPSYSTEMTIME lpSystemTime);
WINBASEAPI LONG WINAPI CompareFileTime(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
WINBASEAPI BOOL WINAPI FileTimeToDosDateTime(CONST FILETIME *lpFileTime,LPWORD lpFatDate,LPWORD lpFatTime);
WINBASEAPI BOOL WINAPI DosDateTimeToFileTime(WORD wFatDate,WORD wFatTime,LPFILETIME lpFileTime);
WINBASEAPI DWORD WINAPI GetTickCount(VOID);
WINBASEAPI BOOL WINAPI SetSystemTimeAdjustment(DWORD dwTimeAdjustment,BOOL bTimeAdjustmentDisabled);
WINBASEAPI BOOL WINAPI GetSystemTimeAdjustment(PDWORD lpTimeAdjustment,PDWORD lpTimeIncrement,PBOOL lpTimeAdjustmentDisabled);
// #if !defined(MIDL_PASS)
WINBASEAPI DWORD WINAPI FormatMessageA(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPSTR lpBuffer,DWORD nSize,va_list *Arguments);
WINBASEAPI DWORD WINAPI FormatMessageW(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPWSTR lpBuffer,DWORD nSize,va_list *Arguments);
#ifdef UNICODE
#define FormatMessage FormatMessageW
#else
#define FormatMessage FormatMessageA
#endif 
// #endif
#define FORMAT_MESSAGE_ALLOCATE_BUFFER 256
#define FORMAT_MESSAGE_IGNORE_INSERTS 512
#define FORMAT_MESSAGE_FROM_STRING 1024
#define FORMAT_MESSAGE_FROM_HMODULE 2048
#define FORMAT_MESSAGE_FROM_SYSTEM 0x1000
#define FORMAT_MESSAGE_ARGUMENT_ARRAY 0x2000
#define FORMAT_MESSAGE_MAX_WIDTH_MASK 255
WINBASEAPI BOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_ATTRIBUTES lpPipeAttributes,DWORD nSize);
WINBASEAPI BOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
WINBASEAPI BOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
WINBASEAPI BOOL WINAPI SetNamedPipeHandleState(HANDLE hNamedPipe,LPDWORD lpMode,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout);
WINBASEAPI BOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lpOutBufferSize,LPDWORD lpInBufferSize,LPDWORD lpMaxInstances);
WINBASEAPI BOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lpBuffer,DWORD nBufferSize,LPDWORD lpBytesRead,LPDWORD lpTotalBytesAvail,LPDWORD lpBytesLeftThisMessage);
WINBASEAPI BOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,LPOVERLAPPED lpOverlapped);
WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD nMaxMessageSize,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD nMaxMessageSize,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#ifdef UNICODE
#define CreateMailslot CreateMailslotW
#else
#define CreateMailslot CreateMailslotA
#endif 
WINBASEAPI BOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lpMaxMessageSize,LPDWORD lpNextSize,LPDWORD lpMessageCount,LPDWORD lpReadTimeout);
WINBASEAPI BOOL WINAPI SetMailslotInfo(HANDLE hMailslot,DWORD lReadTimeout);
WINBASEAPI LPVOID WINAPI MapViewOfFile(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dwFileOffsetHigh,DWORD dwFileOffsetLow,SIZE_T dwNumberOfBytesToMap);
WINBASEAPI BOOL WINAPI FlushViewOfFile(LPCVOID lpBaseAddress,SIZE_T dwNumberOfBytesToFlush);
WINBASEAPI BOOL WINAPI UnmapViewOfFile(LPCVOID lpBaseAddress);
/*
WINADVAPI BOOL WINAPI EncryptFileA(LPCSTR lpFileName);
WINADVAPI BOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
#ifdef UNICODE
#define EncryptFile EncryptFileW
#else
#define EncryptFile EncryptFileA
#endif 
WINADVAPI BOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
WINADVAPI BOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);
#ifdef UNICODE
#define DecryptFile DecryptFileW
#else
#define DecryptFile DecryptFileA
#endif 
#define FILE_ENCRYPTABLE 0
#define FILE_IS_ENCRYPTED 1
#define FILE_SYSTEM_ATTR 2
#define FILE_ROOT_DIR 3
#define FILE_SYSTEM_DIR 4
#define FILE_UNKNOWN 5
#define FILE_SYSTEM_NOT_SUPPORT 6
#define FILE_USER_DISALLOWED 7
#define FILE_READ_ONLY 8
#define FILE_DIR_DISALLOWED 9
WINADVAPI BOOL WINAPI FileEncryptionStatusA(LPCSTR lpFileName,LPDWORD lpStatus);
WINADVAPI BOOL WINAPI FileEncryptionStatusW(LPCWSTR lpFileName,LPDWORD lpStatus);
#ifdef UNICODE
#define FileEncryptionStatus FileEncryptionStatusW
#else
#define FileEncryptionStatus FileEncryptionStatusA
#endif 
#define EFS_USE_RECOVERY_KEYS 1
typedef DWORD 
(WINAPI *PFE_EXPORT_FUNC)(PBYTE pbData,PVOID pvCallbackContext,ULONG ulLength);
typedef DWORD 
(WINAPI *PFE_IMPORT_FUNC)(PBYTE pbData,PVOID pvCallbackContext,PULONG ulLength);
#define CREATE_FOR_IMPORT (1)
#define CREATE_FOR_DIR (2)
#define OVERWRITE_HIDDEN (4)
WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
#ifdef UNICODE
#define OpenEncryptedFileRaw OpenEncryptedFileRawW
#else
#define OpenEncryptedFileRaw OpenEncryptedFileRawA
#endif 
WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
*/
WINBASEAPI int WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
WINBASEAPI int WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
#ifdef UNICODE
#define lstrcmp lstrcmpW
#else
#define lstrcmp lstrcmpA
#endif 
WINBASEAPI int WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
WINBASEAPI int WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
#ifdef UNICODE
#define lstrcmpi lstrcmpiW
#else
#define lstrcmpi lstrcmpiA
#endif 
WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,int iMaxLength);
WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,int iMaxLength);
#ifdef UNICODE
#define lstrcpyn lstrcpynW
#else
#define lstrcpyn lstrcpynA
#endif 
WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
#ifdef UNICODE
#define lstrcpy lstrcpyW
#else
#define lstrcpy lstrcpyA
#endif 
WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
#ifdef UNICODE
#define lstrcat lstrcatW
#else
#define lstrcat lstrcatA
#endif 
WINBASEAPI int WINAPI lstrlenA(LPCSTR lpString);
WINBASEAPI int WINAPI lstrlenW(LPCWSTR lpString);
#ifdef UNICODE
#define lstrlen lstrlenW
#else
#define lstrlen lstrlenA
#endif 
WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
WINBASEAPI HFILE WINAPI _lopen(LPCSTR lpPathName,int iReadWrite);
WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lpPathName,int iAttribute);
WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lpBuffer,UINT uBytes);
WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lpBuffer,UINT uBytes);
WINBASEAPI long WINAPI _hread(HFILE hFile,LPVOID lpBuffer,long lBytes);
WINBASEAPI long WINAPI _hwrite(HFILE hFile,LPCCH lpBuffer,long lBytes);
WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG lOffset,int iOrigin);
// WINADVAPI BOOL WINAPI IsTextUnicode(CONST VOID* lpv,int iSize,LPINT lpiResult);
#define FLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)
WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
WINBASEAPI PVOID WINAPI FlsGetValue(DWORD dwFlsIndex);
WINBASEAPI BOOL WINAPI FlsSetValue(DWORD dwFlsIndex,PVOID lpFlsData);
WINBASEAPI BOOL WINAPI FlsFree(DWORD dwFlsIndex);
#define TLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)
WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
WINBASEAPI LPVOID WINAPI TlsGetValue(DWORD dwTlsIndex);
WINBASEAPI BOOL WINAPI TlsSetValue(DWORD dwTlsIndex,LPVOID lpTlsValue);
WINBASEAPI BOOL WINAPI TlsFree(DWORD dwTlsIndex);
// typedef VOID 
// (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwErrorCode,DWORD dwNumberOfBytesTransfered,LPOVERLAPPED lpOverlapped);
WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,BOOL bAlertable);
WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,BOOL bAlertable);
WINBASEAPI DWORD WINAPI WaitForMultipleObjectsEx(DWORD nCount,CONST HANDLE *lpHandles,BOOL bWaitAll,DWORD dwMilliseconds,BOOL bAlertable);
#if(_WIN32_WINNT >=0x0400)
WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE hObjectToSignal,HANDLE hObjectToWaitOn,DWORD dwMilliseconds,BOOL bAlertable);
#endif 
/*
WINBASEAPI BOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
WINBASEAPI BOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
WINBASEAPI BOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,BOOL bAbort,BOOL bProcessSecurity,LPVOID *lpContext);
WINBASEAPI BOOL WINAPI BackupSeek(HANDLE hFile,DWORD dwLowBytesToSeek,DWORD dwHighBytesToSeek,LPDWORD lpdwLowByteSeeked,LPDWORD lpdwHighByteSeeked,LPVOID *lpContext);
WINBASEAPI BOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,BOOL bAbort,BOOL bProcessSecurity,LPVOID *lpContext);
*/
typedef struct _WIN32_STREAM_ID {
		DWORD dwStreamId ;
		DWORD dwStreamAttributes ;
		LARGE_INTEGER Size ;
		DWORD dwStreamNameSize ;
		WCHAR cStreamName[ ANYSIZE_ARRAY ] ;
} WIN32_STREAM_ID,*LPWIN32_STREAM_ID ;
#define BACKUP_INVALID 0
#define BACKUP_DATA 1
#define BACKUP_EA_DATA 2
#define BACKUP_SECURITY_DATA 3
#define BACKUP_ALTERNATE_DATA 4
#define BACKUP_LINK 5
#define BACKUP_PROPERTY_DATA 6
#define BACKUP_OBJECT_ID 7
#define BACKUP_REPARSE_DATA 8
#define BACKUP_SPARSE_BLOCK 9
#define STREAM_NORMAL_ATTRIBUTE 0
#define STREAM_MODIFIED_WHEN_READ 1
#define STREAM_CONTAINS_SECURITY 2
#define STREAM_CONTAINS_PROPERTIES 4
#define STREAM_SPARSE_ATTRIBUTE 8
/*
WINBASEAPI BOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD nNumberOfBytesToRead,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
WINBASEAPI BOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD nNumberOfBytesToWrite,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
*/
#define STARTF_USESHOWWINDOW 1
#define STARTF_USESIZE 2
#define STARTF_USEPOSITION 4
#define STARTF_USECOUNTCHARS 8
#define STARTF_USEFILLATTRIBUTE 16
#define STARTF_RUNFULLSCREEN 32 
#define STARTF_FORCEONFEEDBACK 64
#define STARTF_FORCEOFFFEEDBACK 128
#define STARTF_USESTDHANDLES 256
#if(WINVER >=0x0400)
#define STARTF_USEHOTKEY 512
#endif 
typedef struct _STARTUPINFOA {
	DWORD cb;
	LPSTR lpReserved;
	LPSTR lpDesktop;
	LPSTR lpTitle;
	DWORD dwX;
	DWORD dwY;
	DWORD dwXSize;
	DWORD dwYSize;
	DWORD dwXCountChars;
	DWORD dwYCountChars;
	DWORD dwFillAttribute;
	DWORD dwFlags;
	WORD wShowWindow;
	WORD cbReserved2;
	LPBYTE lpReserved2;
	HANDLE hStdInput;
	HANDLE hStdOutput;
	HANDLE hStdError;
} STARTUPINFOA,*LPSTARTUPINFOA;
typedef struct _STARTUPINFOW {
	DWORD cb;
	LPWSTR lpReserved;
	LPWSTR lpDesktop;
	LPWSTR lpTitle;
	DWORD dwX;
	DWORD dwY;
	DWORD dwXSize;
	DWORD dwYSize;
	DWORD dwXCountChars;
	DWORD dwYCountChars;
	DWORD dwFillAttribute;
	DWORD dwFlags;
	WORD wShowWindow;
	WORD cbReserved2;
	LPBYTE lpReserved2;
	HANDLE hStdInput;
	HANDLE hStdOutput;
	HANDLE hStdError;
} STARTUPINFOW,*LPSTARTUPINFOW;
#ifdef UNICODE
typedef STARTUPINFOW STARTUPINFO;
typedef LPSTARTUPINFOW LPSTARTUPINFO;
#else
typedef STARTUPINFOA STARTUPINFO;
typedef LPSTARTUPINFOA LPSTARTUPINFO;
#endif 
#define SHUTDOWN_NORETRY 1
typedef struct _WIN32_FIND_DATAA {
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD nFileSizeHigh;
	DWORD nFileSizeLow;
	DWORD dwReserved0;
	DWORD dwReserved1;
	CHAR cFileName[ MAX_PATH ];
	CHAR cAlternateFileName[ 14 ];
#ifdef _MAC
	DWORD dwFileType;
	DWORD dwCreatorType;
	WORD wFinderFlags;
#endif
} WIN32_FIND_DATAA,*PWIN32_FIND_DATAA,*LPWIN32_FIND_DATAA;
typedef struct _WIN32_FIND_DATAW {
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD nFileSizeHigh;
	DWORD nFileSizeLow;
	DWORD dwReserved0;
	DWORD dwReserved1;
	WCHAR cFileName[ MAX_PATH ];
	WCHAR cAlternateFileName[ 14 ];
#ifdef _MAC
	DWORD dwFileType;
	DWORD dwCreatorType;
	WORD wFinderFlags;
#endif
} WIN32_FIND_DATAW,*PWIN32_FIND_DATAW,*LPWIN32_FIND_DATAW;
#ifdef UNICODE
typedef WIN32_FIND_DATAW WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAW PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAW LPWIN32_FIND_DATA;
#else
typedef WIN32_FIND_DATAA WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAA PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;
#endif 
typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD nFileSizeHigh;
	DWORD nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA,*LPWIN32_FILE_ATTRIBUTE_DATA;
WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,BOOL bInitialOwner,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes,BOOL bInitialOwner,LPCWSTR lpName);
#ifdef UNICODE
#define CreateMutex CreateMutexW
#else
#define CreateMutex CreateMutexA
#endif 
WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCWSTR lpName);
#ifdef UNICODE
#define OpenMutex OpenMutexW
#else
#define OpenMutex OpenMutexA
#endif 
WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,BOOL bManualReset,BOOL bInitialState,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes,BOOL bManualReset,BOOL bInitialState,LPCWSTR lpName);
#ifdef UNICODE
#define CreateEvent CreateEventW
#else
#define CreateEvent CreateEventA
#endif 
WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCWSTR lpName);
#ifdef UNICODE
#define OpenEvent OpenEventW
#else
#define OpenEvent OpenEventA
#endif 
WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCWSTR lpName);
#ifdef UNICODE
#define CreateSemaphore CreateSemaphoreW
#else
#define CreateSemaphore CreateSemaphoreA
#endif 
WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCWSTR lpName);
#ifdef UNICODE
#define OpenSemaphore OpenSemaphoreW
#else
#define OpenSemaphore OpenSemaphoreA
#endif 
#if (_WIN32_WINNT >=0x0400)||(_WIN32_WINDOWS > 0x0400)
typedef VOID 
(APIENTRY *PTIMERAPCROUTINE)(LPVOID lpArgToCompletionRoutine,DWORD dwTimerLowValue,DWORD dwTimerHighValue);
WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES lpTimerAttributes,BOOL bManualReset,LPCSTR lpTimerName);
WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES lpTimerAttributes,BOOL bManualReset,LPCWSTR lpTimerName);
#ifdef UNICODE
#define CreateWaitableTimer CreateWaitableTimerW
#else
#define CreateWaitableTimer CreateWaitableTimerA
#endif 
WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCSTR lpTimerName);
WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCWSTR lpTimerName);
#ifdef UNICODE
#define OpenWaitableTimer OpenWaitableTimerW
#else
#define OpenWaitableTimer OpenWaitableTimerA
#endif 
WINBASEAPI BOOL WINAPI SetWaitableTimer(HANDLE hTimer,const LARGE_INTEGER *lpDueTime,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lpArgToCompletionRoutine,BOOL fResume);
WINBASEAPI BOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
#endif 
WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCWSTR lpName);
#ifdef UNICODE
#define CreateFileMapping CreateFileMappingW
#else
#define CreateFileMapping CreateFileMappingA
#endif 
WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCWSTR lpName);
#ifdef UNICODE
#define OpenFileMapping OpenFileMappingW
#else
#define OpenFileMapping OpenFileMappingA
#endif 
WINBASEAPI DWORD WINAPI GetLogicalDriveStringsA(DWORD nBufferLength,LPSTR lpBuffer);
WINBASEAPI DWORD WINAPI GetLogicalDriveStringsW(DWORD nBufferLength,LPWSTR lpBuffer);
#ifdef UNICODE
#define GetLogicalDriveStrings GetLogicalDriveStringsW
#else
#define GetLogicalDriveStrings GetLogicalDriveStringsA
#endif 
#if _WIN32_WINNT >=0x0501
typedef enum _MEMORY_RESOURCE_NOTIFICATION_TYPE {
	LowMemoryResourceNotification,HighMemoryResourceNotification
} MEMORY_RESOURCE_NOTIFICATION_TYPE;
WINBASEAPI HANDLE WINAPI CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType);
WINBASEAPI BOOL WINAPI QueryMemoryResourceNotification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
#endif 
WINBASEAPI HMODULE WINAPI LoadLibraryA(LPCSTR lpLibFileName);
WINBASEAPI HMODULE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
#ifdef UNICODE
#define LoadLibrary LoadLibraryW
#else
#define LoadLibrary LoadLibraryA
#endif 
WINBASEAPI HMODULE WINAPI LoadLibraryExA(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
WINBASEAPI HMODULE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
#ifdef UNICODE
#define LoadLibraryEx LoadLibraryExW
#else
#define LoadLibraryEx LoadLibraryExA
#endif 
#define DONT_RESOLVE_DLL_REFERENCES 1
#define LOAD_LIBRARY_AS_DATAFILE 2
#define LOAD_WITH_ALTERED_SEARCH_PATH 8
#define LOAD_IGNORE_CODE_AUTHZ_LEVEL 16
WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD nSize);
WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD nSize);
#ifdef UNICODE
#define GetModuleFileName GetModuleFileNameW
#else
#define GetModuleFileName GetModuleFileNameA
#endif 
WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);
#ifdef UNICODE
#define GetModuleHandle GetModuleHandleW
#else
#define GetModuleHandle GetModuleHandleA
#endif 
#if !defined(RC_INVOKED)
#if _WIN32_WINNT > 0x0500||defined(WINBASE_DECLARE_GET_MODULE_HANDLE_EX)||ISOLATION_AWARE_ENABLED
#define GET_MODULE_HANDLE_EX_FLAG_PIN 1
#define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT 2
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS 4
typedef BOOL 
(WINAPI*
PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE* phModule);
typedef BOOL 
(WINAPI*
PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE* phModule);
#ifdef UNICODE
#define PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#else
#define PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#endif 
WINBASEAPI BOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE* phModule);
WINBASEAPI BOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE* phModule);
#ifdef UNICODE
#define GetModuleHandleEx GetModuleHandleExW
#else
#define GetModuleHandleEx GetModuleHandleExA
#endif 
#endif
#endif
#if _WIN32_WINNT >=0x0502
WINBASEAPI BOOL WINAPI NeedCurrentDirectoryForExePathA(LPCSTR ExeName);
WINBASEAPI BOOL WINAPI NeedCurrentDirectoryForExePathW(LPCWSTR ExeName);
#ifdef UNICODE
#define NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathW
#else
#define NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathA
#endif 
#endif
WINBASEAPI BOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,
	LPPROCESS_INFORMATION lpProcessInformation);
WINBASEAPI BOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,
	LPPROCESS_INFORMATION lpProcessInformation);
#ifdef UNICODE
#define CreateProcess CreateProcessW
#else
#define CreateProcess CreateProcessA
#endif 
WINBASEAPI BOOL WINAPI SetProcessShutdownParameters(DWORD dwLevel,DWORD dwFlags);
WINBASEAPI BOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
WINBASEAPI DWORD WINAPI GetProcessVersion(DWORD ProcessId);
WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lpMessageText);
WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lpMessageText);
#ifdef UNICODE
#define FatalAppExit FatalAppExitW
#else
#define FatalAppExit FatalAppExitA
#endif 
WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
#ifdef UNICODE
#define GetStartupInfo GetStartupInfoW
#else
#define GetStartupInfo GetStartupInfoA
#endif 
WINBASEAPI LPSTR WINAPI GetCommandLineA(VOID);
WINBASEAPI LPWSTR WINAPI GetCommandLineW(VOID);
#ifdef UNICODE
#define GetCommandLine GetCommandLineW
#else
#define GetCommandLine GetCommandLineA
#endif 
WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lpBuffer,DWORD nSize);
WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lpBuffer,DWORD nSize);
#ifdef UNICODE
#define GetEnvironmentVariable GetEnvironmentVariableW
#else
#define GetEnvironmentVariable GetEnvironmentVariableA
#endif 
WINBASEAPI BOOL WINAPI SetEnvironmentVariableA(LPCSTR lpName,LPCSTR lpValue);
WINBASEAPI BOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpValue);
#ifdef UNICODE
#define SetEnvironmentVariable SetEnvironmentVariableW
#else
#define SetEnvironmentVariable SetEnvironmentVariableA
#endif 
WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsA(LPCSTR lpSrc,LPSTR lpDst,DWORD nSize);
WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsW(LPCWSTR lpSrc,LPWSTR lpDst,DWORD nSize);
#ifdef UNICODE
#define ExpandEnvironmentStrings ExpandEnvironmentStringsW
#else
#define ExpandEnvironmentStrings ExpandEnvironmentStringsA
#endif 
WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID pBuffer,DWORD nSize);
WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID pBuffer,DWORD nSize);
#ifdef UNICODE
#define GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#else
#define GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#endif 
WINBASEAPI BOOL WINAPI SetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID pValue,DWORD nSize);
WINBASEAPI BOOL WINAPI SetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID pValue,DWORD nSize);
#ifdef UNICODE
#define SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableW
#else
#define SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableA
#endif 
WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
#ifdef UNICODE
#define OutputDebugString OutputDebugStringW
#else
#define OutputDebugString OutputDebugStringA
#endif 
WINBASEAPI HRSRC WINAPI FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
WINBASEAPI HRSRC WINAPI FindResourceW(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
#ifdef UNICODE
#define FindResource FindResourceW
#else
#define FindResource FindResourceA
#endif 
WINBASEAPI HRSRC WINAPI FindResourceExA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage);
WINBASEAPI HRSRC WINAPI FindResourceExW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage);
#ifdef UNICODE
#define FindResourceEx FindResourceExW
#else
#define FindResourceEx FindResourceExA
#endif 
#ifdef STRICT
typedef BOOL (CALLBACK* ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
typedef BOOL (CALLBACK* ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
#ifdef UNICODE
#define ENUMRESTYPEPROC ENUMRESTYPEPROCW
#else
#define ENUMRESTYPEPROC ENUMRESTYPEPROCA
#endif 
typedef BOOL (CALLBACK* ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
typedef BOOL (CALLBACK* ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
#ifdef UNICODE
#define ENUMRESNAMEPROC ENUMRESNAMEPROCW
#else
#define ENUMRESNAMEPROC ENUMRESNAMEPROCA
#endif 
typedef BOOL (CALLBACK* ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LONG_PTR lParam);
typedef BOOL (CALLBACK* ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LONG_PTR lParam);
#ifdef UNICODE
#define ENUMRESLANGPROC ENUMRESLANGPROCW
#else
#define ENUMRESLANGPROC ENUMRESLANGPROCA
#endif 
#else
typedef FARPROC ENUMRESTYPEPROCA;
typedef FARPROC ENUMRESTYPEPROCW;
#ifdef UNICODE
typedef ENUMRESTYPEPROCW ENUMRESTYPEPROC;
#else
typedef ENUMRESTYPEPROCA ENUMRESTYPEPROC;
#endif 
typedef FARPROC ENUMRESNAMEPROCA;
typedef FARPROC ENUMRESNAMEPROCW;
#ifdef UNICODE
typedef ENUMRESNAMEPROCW ENUMRESNAMEPROC;
#else
typedef ENUMRESNAMEPROCA ENUMRESNAMEPROC;
#endif 
typedef FARPROC ENUMRESLANGPROCA;
typedef FARPROC ENUMRESLANGPROCW;
#ifdef UNICODE
typedef ENUMRESLANGPROCW ENUMRESLANGPROC;
#else
typedef ENUMRESLANGPROCA ENUMRESLANGPROC;
#endif 
#endif
WINBASEAPI BOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
WINBASEAPI BOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
#ifdef UNICODE
#define EnumResourceTypes EnumResourceTypesW
#else
#define EnumResourceTypes EnumResourceTypesA
#endif 
WINBASEAPI BOOL WINAPI EnumResourceNamesA(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
WINBASEAPI BOOL WINAPI EnumResourceNamesW(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
#ifdef UNICODE
#define EnumResourceNames EnumResourceNamesW
#else
#define EnumResourceNames EnumResourceNamesA
#endif 
WINBASEAPI BOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
WINBASEAPI BOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
#ifdef UNICODE
#define EnumResourceLanguages EnumResourceLanguagesW
#else
#define EnumResourceLanguages EnumResourceLanguagesA
#endif 
WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,BOOL bDeleteExistingResources);
WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,BOOL bDeleteExistingResources);
#ifdef UNICODE
#define BeginUpdateResource BeginUpdateResourceW
#else
#define BeginUpdateResource BeginUpdateResourceA
#endif 
WINBASEAPI BOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LPVOID lpData,DWORD cb);
WINBASEAPI BOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LPVOID lpData,DWORD cb);
#ifdef UNICODE
#define UpdateResource UpdateResourceW
#else
#define UpdateResource UpdateResourceA
#endif 
WINBASEAPI BOOL WINAPI EndUpdateResourceA(HANDLE hUpdate,BOOL fDiscard);
WINBASEAPI BOOL WINAPI EndUpdateResourceW(HANDLE hUpdate,BOOL fDiscard);
#ifdef UNICODE
#define EndUpdateResource EndUpdateResourceW
#else
#define EndUpdateResource EndUpdateResourceA
#endif 
WINBASEAPI ATOM WINAPI GlobalAddAtomA(LPCSTR lpString);
WINBASEAPI ATOM WINAPI GlobalAddAtomW(LPCWSTR lpString);
#ifdef UNICODE
#define GlobalAddAtom GlobalAddAtomW
#else
#define GlobalAddAtom GlobalAddAtomA
#endif 
WINBASEAPI ATOM WINAPI GlobalFindAtomA(LPCSTR lpString);
WINBASEAPI ATOM WINAPI GlobalFindAtomW(LPCWSTR lpString);
#ifdef UNICODE
#define GlobalFindAtom GlobalFindAtomW
#else
#define GlobalFindAtom GlobalFindAtomA
#endif 
WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lpBuffer,int nSize);
WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lpBuffer,int nSize);
#ifdef UNICODE
#define GlobalGetAtomName GlobalGetAtomNameW
#else
#define GlobalGetAtomName GlobalGetAtomNameA
#endif 
WINBASEAPI ATOM WINAPI AddAtomA(LPCSTR lpString);
WINBASEAPI ATOM WINAPI AddAtomW(LPCWSTR lpString);
#ifdef UNICODE
#define AddAtom AddAtomW
#else
#define AddAtom AddAtomA
#endif 
WINBASEAPI ATOM WINAPI FindAtomA(LPCSTR lpString);
WINBASEAPI ATOM WINAPI FindAtomW(LPCWSTR lpString);
#ifdef UNICODE
#define FindAtom FindAtomW
#else
#define FindAtom FindAtomA
#endif 
WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lpBuffer,int nSize);
WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lpBuffer,int nSize);
#ifdef UNICODE
#define GetAtomName GetAtomNameW
#else
#define GetAtomName GetAtomNameA
#endif 
WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault);
WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lpKeyName,INT nDefault);
#ifdef UNICODE
#define GetProfileInt GetProfileIntW
#else
#define GetProfileInt GetProfileIntA
#endif 
WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize);
WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD nSize);
#ifdef UNICODE
#define GetProfileString GetProfileStringW
#else
#define GetProfileString GetProfileStringA
#endif 
WINBASEAPI BOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString);
WINBASEAPI BOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpString);
#ifdef UNICODE
#define WriteProfileString WriteProfileStringW
#else
#define WriteProfileString WriteProfileStringA
#endif 
WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD nSize);
WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD nSize);
#ifdef UNICODE
#define GetProfileSection GetProfileSectionW
#else
#define GetProfileSection GetProfileSectionA
#endif 
WINBASEAPI BOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
WINBASEAPI BOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
#ifdef UNICODE
#define WriteProfileSection WriteProfileSectionW
#else
#define WriteProfileSection WriteProfileSectionA
#endif 
WINBASEAPI UINT WINAPI GetPrivateProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault,LPCSTR lpFileName);
WINBASEAPI UINT WINAPI GetPrivateProfileIntW(LPCWSTR lpAppName,LPCWSTR lpKeyName,INT nDefault,LPCWSTR lpFileName);
#ifdef UNICODE
#define GetPrivateProfileInt GetPrivateProfileIntW
#else
#define GetPrivateProfileInt GetPrivateProfileIntA
#endif 
WINBASEAPI DWORD WINAPI GetPrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
WINBASEAPI DWORD WINAPI GetPrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName);
#ifdef UNICODE
#define GetPrivateProfileString GetPrivateProfileStringW
#else
#define GetPrivateProfileString GetPrivateProfileStringA
#endif 
WINBASEAPI BOOL WINAPI WritePrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString,LPCSTR lpFileName);
WINBASEAPI BOOL WINAPI WritePrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpString,LPCWSTR lpFileName);
#ifdef UNICODE
#define WritePrivateProfileString WritePrivateProfileStringW
#else
#define WritePrivateProfileString WritePrivateProfileStringA
#endif 
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName);
#ifdef UNICODE
#define GetPrivateProfileSection GetPrivateProfileSectionW
#else
#define GetPrivateProfileSection GetPrivateProfileSectionA
#endif 
WINBASEAPI BOOL WINAPI WritePrivateProfileSectionA(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
WINBASEAPI BOOL WINAPI WritePrivateProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
#ifdef UNICODE
#define WritePrivateProfileSection WritePrivateProfileSectionW
#else
#define WritePrivateProfileSection WritePrivateProfileSectionA
#endif 
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR lpszReturnBuffer,DWORD nSize,LPCSTR lpFileName);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR lpszReturnBuffer,DWORD nSize,LPCWSTR lpFileName);
#ifdef UNICODE
#define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
#else
#define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
#endif 
WINBASEAPI BOOL WINAPI GetPrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCSTR szFile);
WINBASEAPI BOOL WINAPI GetPrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCWSTR szFile);
#ifdef UNICODE
#define GetPrivateProfileStruct GetPrivateProfileStructW
#else
#define GetPrivateProfileStruct GetPrivateProfileStructA
#endif 
WINBASEAPI BOOL WINAPI WritePrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCSTR szFile);
WINBASEAPI BOOL WINAPI WritePrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCWSTR szFile);
#ifdef UNICODE
#define WritePrivateProfileStruct WritePrivateProfileStructW
#else
#define WritePrivateProfileStruct WritePrivateProfileStructA
#endif 
WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lpRootPathName);
WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lpRootPathName);
#ifdef UNICODE
#define GetDriveType GetDriveTypeW
#else
#define GetDriveType GetDriveTypeA
#endif 
WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lpBuffer,UINT uSize);
WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lpBuffer,UINT uSize);
#ifdef UNICODE
#define GetSystemDirectory GetSystemDirectoryW
#else
#define GetSystemDirectory GetSystemDirectoryA
#endif 
WINBASEAPI DWORD WINAPI GetTempPathA(DWORD nBufferLength,LPSTR lpBuffer);
WINBASEAPI DWORD WINAPI GetTempPathW(DWORD nBufferLength,LPWSTR lpBuffer);
#ifdef UNICODE
#define GetTempPath GetTempPathW
#else
#define GetTempPath GetTempPathA
#endif 
WINBASEAPI UINT WINAPI GetTempFileNameA(LPCSTR lpPathName,LPCSTR lpPrefixString,UINT uUnique,LPSTR lpTempFileName);
WINBASEAPI UINT WINAPI GetTempFileNameW(LPCWSTR lpPathName,LPCWSTR lpPrefixString,UINT uUnique,LPWSTR lpTempFileName);
#ifdef UNICODE
#define GetTempFileName GetTempFileNameW
#else
#define GetTempFileName GetTempFileNameA
#endif 
WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lpBuffer,UINT uSize);
WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lpBuffer,UINT uSize);
#ifdef UNICODE
#define GetWindowsDirectory GetWindowsDirectoryW
#else
#define GetWindowsDirectory GetWindowsDirectoryA
#endif 
WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lpBuffer,UINT uSize);
WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lpBuffer,UINT uSize);
#ifdef UNICODE
#define GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#else
#define GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#endif 
#if !defined(RC_INVOKED) 
#if _WIN32_WINNT >=0x0501||defined(WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY)
WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lpBuffer,UINT uSize);
WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lpBuffer,UINT uSize);
#ifdef UNICODE
#define GetSystemWow64Directory GetSystemWow64DirectoryW
#else
#define GetSystemWow64Directory GetSystemWow64DirectoryA
#endif 
WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection (BOOLEAN Wow64FsEnableRedirection);
WINBASEAPI BOOL WINAPI Wow64DisableWow64FsRedirection (PVOID *OldValue);
WINBASEAPI BOOL WINAPI Wow64RevertWow64FsRedirection (PVOID OlValue);
typedef UINT (WINAPI* PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lpBuffer,UINT uSize);
typedef UINT (WINAPI* PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lpBuffer,UINT uSize);
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")
#ifdef UNICODE
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#else
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#endif
#endif 
#endif
WINBASEAPI BOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName);
WINBASEAPI BOOL WINAPI SetCurrentDirectoryW(LPCWSTR lpPathName);
#ifdef UNICODE
#define SetCurrentDirectory SetCurrentDirectoryW
#else
#define SetCurrentDirectory SetCurrentDirectoryA
#endif 
WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);
WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD nBufferLength,LPWSTR lpBuffer);
#ifdef UNICODE
#define GetCurrentDirectory GetCurrentDirectoryW
#else
#define GetCurrentDirectory GetCurrentDirectoryA
#endif 
#if _WIN32_WINNT >=0x0502
WINBASEAPI BOOL WINAPI SetDllDirectoryA(LPCSTR lpPathName);
WINBASEAPI BOOL WINAPI SetDllDirectoryW(LPCWSTR lpPathName);
#ifdef UNICODE
#define SetDllDirectory SetDllDirectoryW
#else
#define SetDllDirectory SetDllDirectoryA
#endif 
WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);
WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD nBufferLength,LPWSTR lpBuffer);
#ifdef UNICODE
#define GetDllDirectory GetDllDirectoryW
#else
#define GetDllDirectory GetDllDirectoryA
#endif 
#endif 
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceA(LPCSTR lpRootPathName,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lpNumberOfFreeClusters,LPDWORD lpTotalNumberOfClusters);
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lpRootPathName,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lpNumberOfFreeClusters,LPDWORD lpTotalNumberOfClusters);
#ifdef UNICODE
#define GetDiskFreeSpace GetDiskFreeSpaceW
#else
#define GetDiskFreeSpace GetDiskFreeSpaceA
#endif 
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lpTotalNumberOfBytes,PULARGE_INTEGER lpTotalNumberOfFreeBytes);
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lpTotalNumberOfBytes,PULARGE_INTEGER lpTotalNumberOfFreeBytes);
#ifdef UNICODE
#define GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#else
#define GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#endif 
WINBASEAPI BOOL WINAPI CreateDirectoryA(LPCSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINBASEAPI BOOL WINAPI CreateDirectoryW(LPCWSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#ifdef UNICODE
#define CreateDirectory CreateDirectoryW
#else
#define CreateDirectory CreateDirectoryA
#endif 
WINBASEAPI BOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINBASEAPI BOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#ifdef UNICODE
#define CreateDirectoryEx CreateDirectoryExW
#else
#define CreateDirectoryEx CreateDirectoryExA
#endif 
WINBASEAPI BOOL WINAPI RemoveDirectoryA(LPCSTR lpPathName);
WINBASEAPI BOOL WINAPI RemoveDirectoryW(LPCWSTR lpPathName);
#ifdef UNICODE
#define RemoveDirectory RemoveDirectoryW
#else
#define RemoveDirectory RemoveDirectoryA
#endif 
WINBASEAPI DWORD WINAPI GetFullPathNameA(LPCSTR lpFileName,DWORD nBufferLength,LPSTR lpBuffer,LPSTR *lpFilePart);
WINBASEAPI DWORD WINAPI GetFullPathNameW(LPCWSTR lpFileName,DWORD nBufferLength,LPWSTR lpBuffer,LPWSTR *lpFilePart);
#ifdef UNICODE
#define GetFullPathName GetFullPathNameW
#else
#define GetFullPathName GetFullPathNameA
#endif 
#define DDD_RAW_TARGET_PATH 1
#define DDD_REMOVE_DEFINITION 2
#define DDD_EXACT_MATCH_ON_REMOVE 4
#define DDD_NO_BROADCAST_SYSTEM 8
#define DDD_LUID_BROADCAST_DRIVE 16
WINBASEAPI BOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lpTargetPath);
WINBASEAPI BOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lpTargetPath);
#ifdef UNICODE
#define DefineDosDevice DefineDosDeviceW
#else
#define DefineDosDevice DefineDosDeviceA
#endif 
WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lpTargetPath,DWORD ucchMax);
WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lpTargetPath,DWORD ucchMax);
#ifdef UNICODE
#define QueryDosDevice QueryDosDeviceW
#else
#define QueryDosDevice QueryDosDeviceA
#endif 
#define EXPAND_LOCAL_DRIVES
WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
#ifdef UNICODE
#define CreateFile CreateFileW
#else
#define CreateFile CreateFileA
#endif 
#if _WIN32_WINNT >=0x0502
WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dwShareMode,DWORD dwFlagsAndAttributes);
#endif 
WINBASEAPI BOOL WINAPI SetFileAttributesA(LPCSTR lpFileName,DWORD dwFileAttributes);
WINBASEAPI BOOL WINAPI SetFileAttributesW(LPCWSTR lpFileName,DWORD dwFileAttributes);
#ifdef UNICODE
#define SetFileAttributes SetFileAttributesW
#else
#define SetFileAttributes SetFileAttributesA
#endif 
WINBASEAPI DWORD WINAPI GetFileAttributesA(LPCSTR lpFileName);
WINBASEAPI DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName);
#ifdef UNICODE
#define GetFileAttributes GetFileAttributesW
#else
#define GetFileAttributes GetFileAttributesA
#endif 
typedef enum _GET_FILEEX_INFO_LEVELS {
	GetFileExInfoStandard,GetFileExMaxInfoLevel
} GET_FILEEX_INFO_LEVELS;
WINBASEAPI BOOL WINAPI GetFileAttributesExA(LPCSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation);
WINBASEAPI BOOL WINAPI GetFileAttributesExW(LPCWSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation);
#ifdef UNICODE
#define GetFileAttributesEx GetFileAttributesExW
#else
#define GetFileAttributesEx GetFileAttributesExA
#endif 
WINBASEAPI DWORD WINAPI GetCompressedFileSizeA(LPCSTR lpFileName,LPDWORD lpFileSizeHigh);
WINBASEAPI DWORD WINAPI GetCompressedFileSizeW(LPCWSTR lpFileName,LPDWORD lpFileSizeHigh);
#ifdef UNICODE
#define GetCompressedFileSize GetCompressedFileSizeW
#else
#define GetCompressedFileSize GetCompressedFileSizeA
#endif 
WINBASEAPI BOOL WINAPI DeleteFileA(LPCSTR lpFileName);
WINBASEAPI BOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
#ifdef UNICODE
#define DeleteFile DeleteFileW
#else
#define DeleteFile DeleteFileA
#endif 
#if _WIN32_WINNT >=0x0501
WINBASEAPI BOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD OemNameSize,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);
WINBASEAPI BOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD OemNameSize,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);
#ifdef UNICODE
#define CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#else
#define CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#endif 
#endif 
#if(_WIN32_WINNT >=0x0400)
typedef enum _FINDEX_INFO_LEVELS {
	FindExInfoStandard,FindExInfoMaxInfoLevel
} FINDEX_INFO_LEVELS;
typedef enum _FINDEX_SEARCH_OPS {
	FindExSearchNameMatch,FindExSearchLimitToDirectories,FindExSearchLimitToDevices,FindExSearchMaxSearchOp
} FINDEX_SEARCH_OPS;
#define FIND_FIRST_EX_CASE_SENSITIVE 1
WINBASEAPI HANDLE WINAPI FindFirstFileExA(LPCSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp,LPVOID lpSearchFilter,DWORD dwAdditionalFlags);
WINBASEAPI HANDLE WINAPI FindFirstFileExW(LPCWSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp,LPVOID lpSearchFilter,DWORD dwAdditionalFlags);
#ifdef UNICODE
#define FindFirstFileEx FindFirstFileExW
#else
#define FindFirstFileEx FindFirstFileExA
#endif 
#endif 
WINBASEAPI HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName,LPWIN32_FIND_DATAA lpFindFileData);
WINBASEAPI HANDLE WINAPI FindFirstFileW(LPCWSTR lpFileName,LPWIN32_FIND_DATAW lpFindFileData);
#ifdef UNICODE
#define FindFirstFile FindFirstFileW
#else
#define FindFirstFile FindFirstFileA
#endif 
WINBASEAPI BOOL WINAPI FindNextFileA(HANDLE hFindFile,LPWIN32_FIND_DATAA lpFindFileData);
WINBASEAPI BOOL WINAPI FindNextFileW(HANDLE hFindFile,LPWIN32_FIND_DATAW lpFindFileData);
#ifdef UNICODE
#define FindNextFile FindNextFileW
#else
#define FindNextFile FindNextFileA
#endif 
WINBASEAPI DWORD WINAPI SearchPathA(LPCSTR lpPath,LPCSTR lpFileName,LPCSTR lpExtension,DWORD nBufferLength,LPSTR lpBuffer,LPSTR *lpFilePart);
WINBASEAPI DWORD WINAPI SearchPathW(LPCWSTR lpPath,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD nBufferLength,LPWSTR lpBuffer,LPWSTR *lpFilePart);
#ifdef UNICODE
#define SearchPath SearchPathW
#else
#define SearchPath SearchPathA
#endif 
WINBASEAPI BOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,BOOL bFailIfExists);
WINBASEAPI BOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,BOOL bFailIfExists);
#ifdef UNICODE
#define CopyFile CopyFileW
#else
#define CopyFile CopyFileA
#endif 
#if(_WIN32_WINNT >=0x0400)
typedef DWORD 
(WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER TotalFileSize,LARGE_INTEGER TotalBytesTransferred,LARGE_INTEGER StreamSize,LARGE_INTEGER StreamBytesTransferred,DWORD dwStreamNumber,DWORD dwCallbackReason,HANDLE hSourceFile,HANDLE hDestinationFile,
	LPVOID lpData);
WINBASEAPI BOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,LPBOOL pbCancel,DWORD dwCopyFlags);
WINBASEAPI BOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,LPBOOL pbCancel,DWORD dwCopyFlags);
#ifdef UNICODE
#define CopyFileEx CopyFileExW
#else
#define CopyFileEx CopyFileExA
#endif 
#endif 
WINBASEAPI BOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
WINBASEAPI BOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
#ifdef UNICODE
#define MoveFile MoveFileW
#else
#define MoveFile MoveFileA
#endif 
WINBASEAPI BOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
WINBASEAPI BOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
#ifdef UNICODE
#define MoveFileEx MoveFileExW
#else
#define MoveFileEx MoveFileExA
#endif 
#if (_WIN32_WINNT >=0x0500)
WINBASEAPI BOOL WINAPI MoveFileWithProgressA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,DWORD dwFlags);
WINBASEAPI BOOL WINAPI MoveFileWithProgressW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,DWORD dwFlags);
#ifdef UNICODE
#define MoveFileWithProgress MoveFileWithProgressW
#else
#define MoveFileWithProgress MoveFileWithProgressA
#endif 
#endif 
#define MOVEFILE_REPLACE_EXISTING 1
#define MOVEFILE_COPY_ALLOWED 2
#define MOVEFILE_DELAY_UNTIL_REBOOT 4
#define MOVEFILE_WRITE_THROUGH 8
#if (_WIN32_WINNT >=0x0500)
#define MOVEFILE_CREATE_HARDLINK 16
#define MOVEFILE_FAIL_IF_NOT_TRACKABLE 32
#endif 
#if (_WIN32_WINNT >=0x0500)
WINBASEAPI BOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
WINBASEAPI BOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
#ifdef UNICODE
#define ReplaceFile ReplaceFileW
#else
#define ReplaceFile ReplaceFileA
#endif 
#endif 
#if (_WIN32_WINNT >=0x0500)
WINBASEAPI BOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINBASEAPI BOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#ifdef UNICODE
#define CreateHardLink CreateHardLinkW
#else
#define CreateHardLink CreateHardLinkA
#endif 
#endif 
#if (_WIN32_WINNT >=0x0501)
typedef enum _STREAM_INFO_LEVELS {
	FindStreamInfoStandard,FindStreamInfoMaxInfoLevel
} STREAM_INFO_LEVELS;
typedef struct _WIN32_FIND_STREAM_DATA {
	LARGE_INTEGER StreamSize;
	WCHAR cStreamName[ MAX_PATH + 36 ]; 
} WIN32_FIND_STREAM_DATA,*PWIN32_FIND_STREAM_DATA; 
HANDLE WINAPI FindFirstStreamW(LPCWSTR lpFileName,STREAM_INFO_LEVELS InfoLevel,LPVOID lpFindStreamData,DWORD dwFlags);
BOOL APIENTRY FindNextStreamW(HANDLE hFindStream,LPVOID lpFindStreamData);
#endif 
WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD nOutBufferSize,DWORD nInBufferSize,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD nOutBufferSize,DWORD nInBufferSize,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#ifdef UNICODE
#define CreateNamedPipe CreateNamedPipeW
#else
#define CreateNamedPipe CreateNamedPipeA
#endif 
WINBASEAPI BOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout,LPSTR lpUserName,DWORD nMaxUserNameSize);
WINBASEAPI BOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout,LPWSTR lpUserName,DWORD nMaxUserNameSize);
#ifdef UNICODE
#define GetNamedPipeHandleState GetNamedPipeHandleStateW
#else
#define GetNamedPipeHandleState GetNamedPipeHandleStateA
#endif 
WINBASEAPI BOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,DWORD nTimeOut);
WINBASEAPI BOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,DWORD nTimeOut);
#ifdef UNICODE
#define CallNamedPipe CallNamedPipeW
#else
#define CallNamedPipe CallNamedPipeA
#endif 
WINBASEAPI BOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD nTimeOut);
WINBASEAPI BOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD nTimeOut);
#ifdef UNICODE
#define WaitNamedPipe WaitNamedPipeW
#else
#define WaitNamedPipe WaitNamedPipeA
#endif 
WINBASEAPI BOOL WINAPI SetVolumeLabelA(LPCSTR lpRootPathName,LPCSTR lpVolumeName);
WINBASEAPI BOOL WINAPI SetVolumeLabelW(LPCWSTR lpRootPathName,LPCWSTR lpVolumeName);
#ifdef UNICODE
#define SetVolumeLabel SetVolumeLabelW
#else
#define SetVolumeLabel SetVolumeLabelA
#endif 
WINBASEAPI VOID WINAPI SetFileApisToOEM(VOID );
WINBASEAPI VOID WINAPI SetFileApisToANSI(VOID );
WINBASEAPI BOOL WINAPI AreFileApisANSI(VOID );
WINBASEAPI BOOL WINAPI GetVolumeInformationA(LPCSTR lpRootPathName,LPSTR lpVolumeNameBuffer,DWORD nVolumeNameSize,LPDWORD lpVolumeSerialNumber,LPDWORD lpMaximumComponentLength,LPDWORD lpFileSystemFlags,LPSTR lpFileSystemNameBuffer,DWORD nFileSystemNameSize);
WINBASEAPI BOOL WINAPI GetVolumeInformationW(LPCWSTR lpRootPathName,LPWSTR lpVolumeNameBuffer,DWORD nVolumeNameSize,LPDWORD lpVolumeSerialNumber,LPDWORD lpMaximumComponentLength,LPDWORD lpFileSystemFlags,LPWSTR lpFileSystemNameBuffer,DWORD nFileSystemNameSize);
#ifdef UNICODE
#define GetVolumeInformation GetVolumeInformationW
#else
#define GetVolumeInformation GetVolumeInformationA
#endif 
WINBASEAPI BOOL WINAPI CancelIo(HANDLE hFile);
/*
WINADVAPI BOOL WINAPI ClearEventLogA (HANDLE hEventLog,LPCSTR lpBackupFileName);
WINADVAPI BOOL WINAPI ClearEventLogW (HANDLE hEventLog,LPCWSTR lpBackupFileName);
#ifdef UNICODE
#define ClearEventLog ClearEventLogW
#else
#define ClearEventLog ClearEventLogA
#endif 
WINADVAPI BOOL WINAPI BackupEventLogA (HANDLE hEventLog,LPCSTR lpBackupFileName);
WINADVAPI BOOL WINAPI BackupEventLogW (HANDLE hEventLog,LPCWSTR lpBackupFileName);
#ifdef UNICODE
#define BackupEventLog BackupEventLogW
#else
#define BackupEventLog BackupEventLogA
#endif 
WINADVAPI BOOL WINAPI CloseEventLog (HANDLE hEventLog);
WINADVAPI BOOL WINAPI DeregisterEventSource (HANDLE hEventLog);
WINADVAPI BOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
WINADVAPI BOOL WINAPI GetNumberOfEventLogRecords (HANDLE hEventLog,PDWORD NumberOfRecords);
WINADVAPI BOOL WINAPI GetOldestEventLogRecord (HANDLE hEventLog,PDWORD OldestRecord);
WINADVAPI HANDLE WINAPI OpenEventLogA (LPCSTR lpUNCServerName,LPCSTR lpSourceName);
WINADVAPI HANDLE WINAPI OpenEventLogW (LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
#ifdef UNICODE
#define OpenEventLog OpenEventLogW
#else
#define OpenEventLog OpenEventLogA
#endif 
WINADVAPI HANDLE WINAPI RegisterEventSourceA (LPCSTR lpUNCServerName,LPCSTR lpSourceName);
WINADVAPI HANDLE WINAPI RegisterEventSourceW (LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
#ifdef UNICODE
#define RegisterEventSource RegisterEventSourceW
#else
#define RegisterEventSource RegisterEventSourceA
#endif 
WINADVAPI HANDLE WINAPI OpenBackupEventLogA (LPCSTR lpUNCServerName,LPCSTR lpFileName);
WINADVAPI HANDLE WINAPI OpenBackupEventLogW (LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
#ifdef UNICODE
#define OpenBackupEventLog OpenBackupEventLogW
#else
#define OpenBackupEventLog OpenBackupEventLogA
#endif 
WINADVAPI BOOL WINAPI ReadEventLogA (HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,DWORD *pnBytesRead,DWORD *pnMinNumberOfBytesNeeded);
WINADVAPI BOOL WINAPI ReadEventLogW (HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,DWORD *pnBytesRead,DWORD *pnMinNumberOfBytesNeeded);
#ifdef UNICODE
#define ReadEventLog ReadEventLogW
#else
#define ReadEventLog ReadEventLogA
#endif 
WINADVAPI BOOL WINAPI ReportEventA (HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD wNumStrings,DWORD dwDataSize,LPCSTR *lpStrings,LPVOID lpRawData);
WINADVAPI BOOL WINAPI ReportEventW (HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD wNumStrings,DWORD dwDataSize,LPCWSTR *lpStrings,LPVOID lpRawData);
#ifdef UNICODE
#define ReportEvent ReportEventW
#else
#define ReportEvent ReportEventA
#endif 
#define EVENTLOG_FULL_INFO 0
typedef struct _EVENTLOG_FULL_INFORMATION {
	DWORD dwFull;
}
EVENTLOG_FULL_INFORMATION,*LPEVENTLOG_FULL_INFORMATION;
WINADVAPI BOOL WINAPI GetEventLogInformation (HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lpBuffer,DWORD cbBufSize,LPDWORD pcbBytesNeeded);
WINADVAPI BOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
WINADVAPI BOOL WINAPI GetKernelObjectSecurity (HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
WINADVAPI BOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
WINADVAPI BOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
WINADVAPI BOOL WINAPI RevertToSelf (VOID);
WINADVAPI BOOL APIENTRY SetThreadToken (PHANDLE Thread,HANDLE Token);
WINADVAPI BOOL WINAPI AccessCheck (PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD PrivilegeSetLength,LPDWORD GrantedAccess,LPBOOL AccessStatus);
#if(_WIN32_WINNT >=0x0500)
WINADVAPI BOOL WINAPI AccessCheckByType (PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,
	LPDWORD PrivilegeSetLength,LPDWORD GrantedAccess,LPBOOL AccessStatus);
WINADVAPI BOOL WINAPI AccessCheckByTypeResultList (PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,
	LPDWORD PrivilegeSetLength,LPDWORD GrantedAccessList,LPDWORD AccessStatusList);
#endif 
WINADVAPI BOOL WINAPI OpenProcessToken (HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
WINADVAPI BOOL WINAPI OpenThreadToken (HANDLE ThreadHandle,DWORD DesiredAccess,BOOL OpenAsSelf,PHANDLE TokenHandle);
WINADVAPI BOOL WINAPI GetTokenInformation (HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD TokenInformationLength,PDWORD ReturnLength);
WINADVAPI BOOL WINAPI SetTokenInformation (HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD TokenInformationLength);
WINADVAPI BOOL WINAPI AdjustTokenPrivileges (HANDLE TokenHandle,BOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD BufferLength,PTOKEN_PRIVILEGES PreviousState,PDWORD ReturnLength);
WINADVAPI BOOL WINAPI AdjustTokenGroups (HANDLE TokenHandle,BOOL ResetToDefault,PTOKEN_GROUPS NewState,DWORD BufferLength,PTOKEN_GROUPS PreviousState,PDWORD ReturnLength);
WINADVAPI BOOL WINAPI PrivilegeCheck (HANDLE ClientToken,PPRIVILEGE_SET RequiredPrivileges,LPBOOL pfResult);
WINADVAPI BOOL WINAPI AccessCheckAndAuditAlarmA (LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,BOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,
	LPBOOL pfGenerateOnClose);
WINADVAPI BOOL WINAPI AccessCheckAndAuditAlarmW (LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,BOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,
	LPBOOL pfGenerateOnClose);
#ifdef UNICODE
#define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#else
#define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#endif 
#if(_WIN32_WINNT >=0x0500)
WINADVAPI BOOL WINAPI AccessCheckByTypeAndAuditAlarmA (LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,
	DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,BOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
WINADVAPI BOOL WINAPI AccessCheckByTypeAndAuditAlarmW (LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,
	DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,BOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
#ifdef UNICODE
#define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#else
#define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#endif 
WINADVAPI BOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmA (LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,
	POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,BOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
WINADVAPI BOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmW (LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,
	POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,BOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
#ifdef UNICODE
#define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmW
#else
#define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmA
#endif 
WINADVAPI BOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleA (LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,
	DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,BOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
WINADVAPI BOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleW (LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,
	DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,BOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
#ifdef UNICODE
#define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleW
#else
#define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleA
#endif 
#endif 
WINADVAPI BOOL WINAPI ObjectOpenAuditAlarmA (LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,BOOL ObjectCreation,
	BOOL AccessGranted,LPBOOL GenerateOnClose);
WINADVAPI BOOL WINAPI ObjectOpenAuditAlarmW (LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,BOOL ObjectCreation,
	BOOL AccessGranted,LPBOOL GenerateOnClose);
#ifdef UNICODE
#define ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#else
#define ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#endif 
WINADVAPI BOOL WINAPI ObjectPrivilegeAuditAlarmA (LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,BOOL AccessGranted);
WINADVAPI BOOL WINAPI ObjectPrivilegeAuditAlarmW (LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,BOOL AccessGranted);
#ifdef UNICODE
#define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#else
#define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#endif 
WINADVAPI BOOL WINAPI ObjectCloseAuditAlarmA (LPCSTR SubsystemName,LPVOID HandleId,BOOL GenerateOnClose);
WINADVAPI BOOL WINAPI ObjectCloseAuditAlarmW (LPCWSTR SubsystemName,LPVOID HandleId,BOOL GenerateOnClose);
#ifdef UNICODE
#define ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#else
#define ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#endif 
WINADVAPI BOOL WINAPI ObjectDeleteAuditAlarmA (LPCSTR SubsystemName,LPVOID HandleId,BOOL GenerateOnClose);
WINADVAPI BOOL WINAPI ObjectDeleteAuditAlarmW (LPCWSTR SubsystemName,LPVOID HandleId,BOOL GenerateOnClose);
#ifdef UNICODE
#define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#else
#define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#endif 
WINADVAPI BOOL WINAPI PrivilegedServiceAuditAlarmA (LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,BOOL AccessGranted);
WINADVAPI BOOL WINAPI PrivilegedServiceAuditAlarmW (LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,BOOL AccessGranted);
#ifdef UNICODE
#define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#else
#define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#endif 
#if(_WIN32_WINNT >=0x0501)
WINADVAPI BOOL WINAPI IsWellKnownSid (PSID pSid,WELL_KNOWN_SID_TYPE WellKnownSidType);
WINADVAPI BOOL WINAPI CreateWellKnownSid(WELL_KNOWN_SID_TYPE WellKnownSidType,PSID DomainSid,PSID pSid,DWORD *cbSid);
WINADVAPI BOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,BOOL *pfEqual);
WINADVAPI BOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD* cbDomainSid);
#endif 
WINADVAPI BOOL WINAPI IsValidSid (PSID pSid);
WINADVAPI BOOL WINAPI EqualSid (PSID pSid1,PSID pSid2);
WINADVAPI BOOL WINAPI EqualPrefixSid (PSID pSid1,PSID pSid2);
WINADVAPI DWORD WINAPI GetSidLengthRequired (UCHAR nSubAuthorityCount);
WINADVAPI BOOL WINAPI AllocateAndInitializeSid (PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE nSubAuthorityCount,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,
	DWORD nSubAuthority7,PSID *pSid);
WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
WINADVAPI BOOL WINAPI InitializeSid (PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE nSubAuthorityCount);
WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority (PSID pSid);
WINADVAPI PDWORD WINAPI GetSidSubAuthority (PSID pSid,DWORD nSubAuthority);
WINADVAPI PUCHAR WINAPI GetSidSubAuthorityCount (PSID pSid);
WINADVAPI DWORD WINAPI GetLengthSid (PSID pSid);
WINADVAPI BOOL WINAPI CopySid (DWORD nDestinationSidLength,PSID pDestinationSid,PSID pSourceSid);
WINADVAPI BOOL WINAPI AreAllAccessesGranted (DWORD GrantedAccess,DWORD DesiredAccess);
WINADVAPI BOOL WINAPI AreAnyAccessesGranted (DWORD GrantedAccess,DWORD DesiredAccess);
WINADVAPI VOID WINAPI MapGenericMask (PDWORD AccessMask,PGENERIC_MAPPING GenericMapping);
WINADVAPI BOOL WINAPI IsValidAcl (PACL pAcl);
WINADVAPI BOOL WINAPI InitializeAcl (PACL pAcl,DWORD nAclLength,DWORD dwAclRevision);
WINADVAPI BOOL WINAPI GetAclInformation (PACL pAcl,LPVOID pAclInformation,DWORD nAclInformationLength,ACL_INFORMATION_CLASS dwAclInformationClass);
WINADVAPI BOOL WINAPI SetAclInformation (PACL pAcl,LPVOID pAclInformation,DWORD nAclInformationLength,ACL_INFORMATION_CLASS dwAclInformationClass);
WINADVAPI BOOL WINAPI AddAce (PACL pAcl,DWORD dwAceRevision,DWORD dwStartingAceIndex,LPVOID pAceList,DWORD nAceListLength);
WINADVAPI BOOL WINAPI DeleteAce (PACL pAcl,DWORD dwAceIndex);
WINADVAPI BOOL WINAPI GetAce (PACL pAcl,DWORD dwAceIndex,LPVOID *pAce);
WINADVAPI BOOL WINAPI AddAccessAllowedAce (PACL pAcl,DWORD dwAceRevision,DWORD AccessMask,PSID pSid);
#if(_WIN32_WINNT >=0x0500)
WINADVAPI BOOL WINAPI AddAccessAllowedAceEx (PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,PSID pSid);
#endif 
WINADVAPI BOOL WINAPI AddAccessDeniedAce (PACL pAcl,DWORD dwAceRevision,DWORD AccessMask,PSID pSid);
#if(_WIN32_WINNT >=0x0500)
WINADVAPI BOOL WINAPI AddAccessDeniedAceEx (PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,PSID pSid);
#endif 
WINADVAPI BOOL WINAPI AddAuditAccessAce(PACL pAcl,DWORD dwAceRevision,DWORD dwAccessMask,PSID pSid,BOOL bAuditSuccess,BOOL bAuditFailure);
#if(_WIN32_WINNT >=0x0500)
WINADVAPI BOOL WINAPI AddAuditAccessAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dwAccessMask,PSID pSid,BOOL bAuditSuccess,BOOL bAuditFailure);
WINADVAPI BOOL WINAPI AddAccessAllowedObjectAce (PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
WINADVAPI BOOL WINAPI AddAccessDeniedObjectAce (PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
WINADVAPI BOOL WINAPI AddAuditAccessObjectAce (PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,BOOL bAuditSuccess,BOOL bAuditFailure);
#endif 
WINADVAPI BOOL WINAPI FindFirstFreeAce (PACL pAcl,LPVOID *pAce);
WINADVAPI BOOL WINAPI InitializeSecurityDescriptor (PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
WINADVAPI BOOL WINAPI IsValidSecurityDescriptor (PSECURITY_DESCRIPTOR pSecurityDescriptor);
WINADVAPI DWORD WINAPI GetSecurityDescriptorLength (PSECURITY_DESCRIPTOR pSecurityDescriptor);
WINADVAPI BOOL WINAPI GetSecurityDescriptorControl (PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
#if(_WIN32_WINNT >=0x0500)
WINADVAPI BOOL WINAPI SetSecurityDescriptorControl (PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet);
#endif 
WINADVAPI BOOL WINAPI SetSecurityDescriptorDacl (PSECURITY_DESCRIPTOR pSecurityDescriptor,BOOL bDaclPresent,PACL pDacl,BOOL bDaclDefaulted);
WINADVAPI BOOL WINAPI GetSecurityDescriptorDacl (PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
WINADVAPI BOOL WINAPI SetSecurityDescriptorSacl (PSECURITY_DESCRIPTOR pSecurityDescriptor,BOOL bSaclPresent,PACL pSacl,BOOL bSaclDefaulted);
WINADVAPI BOOL WINAPI GetSecurityDescriptorSacl (PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
WINADVAPI BOOL WINAPI SetSecurityDescriptorOwner (PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,BOOL bOwnerDefaulted);
WINADVAPI BOOL WINAPI GetSecurityDescriptorOwner (PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
WINADVAPI BOOL WINAPI SetSecurityDescriptorGroup (PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pGroup,BOOL bGroupDefaulted);
WINADVAPI BOOL WINAPI GetSecurityDescriptorGroup (PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pGroup,LPBOOL lpbGroupDefaulted);
WINADVAPI DWORD WINAPI SetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
WINADVAPI BOOL WINAPI CreatePrivateObjectSecurity (PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR * NewDescriptor,BOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
#if(_WIN32_WINNT >=0x0500)
WINADVAPI BOOL WINAPI ConvertToAutoInheritPrivateObjectSecurity(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
WINADVAPI BOOL WINAPI CreatePrivateObjectSecurityEx (PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR * NewDescriptor,GUID *ObjectType,BOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
WINADVAPI BOOL WINAPI CreatePrivateObjectSecurityWithMultipleInheritance (PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR * NewDescriptor,GUID **ObjectTypes,ULONG GuidCount,BOOL IsContainerObject,ULONG AutoInheritFlags,
	HANDLE Token,PGENERIC_MAPPING GenericMapping);
#endif 
WINADVAPI BOOL WINAPI SetPrivateObjectSecurity (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
#if(_WIN32_WINNT >=0x0500)
WINADVAPI BOOL WINAPI SetPrivateObjectSecurityEx (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
#endif 
WINADVAPI BOOL WINAPI GetPrivateObjectSecurity (PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD DescriptorLength,PDWORD ReturnLength);
WINADVAPI BOOL WINAPI DestroyPrivateObjectSecurity (PSECURITY_DESCRIPTOR * ObjectDescriptor);
WINADVAPI BOOL WINAPI MakeSelfRelativeSD (PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdwBufferLength);
WINADVAPI BOOL WINAPI MakeAbsoluteSD (PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdwAbsoluteSecurityDescriptorSize,PACL pDacl,LPDWORD lpdwDaclSize,PACL pSacl,LPDWORD lpdwSaclSize,PSID pOwner,LPDWORD lpdwOwnerSize,
	PSID pPrimaryGroup,LPDWORD lpdwPrimaryGroupSize);
WINADVAPI BOOL WINAPI MakeAbsoluteSD2 (PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdwBufferSize);
WINADVAPI BOOL WINAPI SetFileSecurityA (LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
WINADVAPI BOOL WINAPI SetFileSecurityW (LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
#ifdef UNICODE
#define SetFileSecurity SetFileSecurityW
#else
#define SetFileSecurity SetFileSecurityA
#endif 
WINADVAPI BOOL WINAPI GetFileSecurityA (LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
WINADVAPI BOOL WINAPI GetFileSecurityW (LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
#ifdef UNICODE
#define GetFileSecurity GetFileSecurityW
#else
#define GetFileSecurity GetFileSecurityA
#endif 
WINADVAPI BOOL WINAPI SetKernelObjectSecurity (HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationA(LPCSTR lpPathName,BOOL bWatchSubtree,DWORD dwNotifyFilter);
WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationW(LPCWSTR lpPathName,BOOL bWatchSubtree,DWORD dwNotifyFilter);
#ifdef UNICODE
#define FindFirstChangeNotification FindFirstChangeNotificationW
#else
#define FindFirstChangeNotification FindFirstChangeNotificationA
#endif 
WINBASEAPI BOOL WINAPI FindNextChangeNotification(HANDLE hChangeHandle);
WINBASEAPI BOOL WINAPI FindCloseChangeNotification(HANDLE hChangeHandle);
#if(_WIN32_WINNT >=0x0400)
WINBASEAPI BOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lpBuffer,DWORD nBufferLength,BOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
WINBASEAPI BOOL WINAPI VirtualLock(LPVOID lpAddress,SIZE_T dwSize);
WINBASEAPI BOOL WINAPI VirtualUnlock(LPVOID lpAddress,SIZE_T dwSize);
WINBASEAPI LPVOID WINAPI MapViewOfFileEx(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dwFileOffsetHigh,DWORD dwFileOffsetLow,SIZE_T dwNumberOfBytesToMap,LPVOID lpBaseAddress);
WINBASEAPI BOOL WINAPI SetPriorityClass(HANDLE hProcess,DWORD dwPriorityClass);
WINBASEAPI DWORD WINAPI GetPriorityClass(HANDLE hProcess);
WINBASEAPI BOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
WINBASEAPI BOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
WINBASEAPI BOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
WINBASEAPI BOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
WINBASEAPI BOOL WINAPI IsBadCodePtr(FARPROC lpfn);
WINBASEAPI BOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
WINBASEAPI BOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
#ifdef UNICODE
#define IsBadStringPtr IsBadStringPtrW
#else
#define IsBadStringPtr IsBadStringPtrA
#endif 
WINADVAPI BOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
WINADVAPI BOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
#ifdef UNICODE
#define LookupAccountSid LookupAccountSidW
#else
#define LookupAccountSid LookupAccountSidA
#endif 
WINADVAPI BOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
WINADVAPI BOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
#ifdef UNICODE
#define LookupAccountName LookupAccountNameW
#else
#define LookupAccountName LookupAccountNameA
#endif 
WINADVAPI BOOL WINAPI LookupPrivilegeValueA(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
WINADVAPI BOOL WINAPI LookupPrivilegeValueW(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
#ifdef UNICODE
#define LookupPrivilegeValue LookupPrivilegeValueW
#else
#define LookupPrivilegeValue LookupPrivilegeValueA
#endif 
WINADVAPI BOOL WINAPI LookupPrivilegeNameA(LPCSTR lpSystemName,PLUID lpLuid,LPSTR lpName,LPDWORD cchName);
WINADVAPI BOOL WINAPI LookupPrivilegeNameW(LPCWSTR lpSystemName,PLUID lpLuid,LPWSTR lpName,LPDWORD cchName);
#ifdef UNICODE
#define LookupPrivilegeName LookupPrivilegeNameW
#else
#define LookupPrivilegeName LookupPrivilegeNameA
#endif 
WINADVAPI BOOL WINAPI LookupPrivilegeDisplayNameA(LPCSTR lpSystemName,LPCSTR lpName,LPSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
WINADVAPI BOOL WINAPI LookupPrivilegeDisplayNameW(LPCWSTR lpSystemName,LPCWSTR lpName,LPWSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
#ifdef UNICODE
#define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#else
#define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#endif 
WINADVAPI BOOL WINAPI AllocateLocallyUniqueId(PLUID Luid);
WINBASEAPI BOOL WINAPI BuildCommDCBA(LPCSTR lpDef,LPDCB lpDCB);
WINBASEAPI BOOL WINAPI BuildCommDCBW(LPCWSTR lpDef,LPDCB lpDCB);
#ifdef UNICODE
#define BuildCommDCB BuildCommDCBW
#else
#define BuildCommDCB BuildCommDCBA
#endif 
WINBASEAPI BOOL WINAPI BuildCommDCBAndTimeoutsA(LPCSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
WINBASEAPI BOOL WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
#ifdef UNICODE
#define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#else
#define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#endif 

WINBASEAPI BOOL WINAPI CommConfigDialogA(LPCSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
WINBASEAPI BOOL WINAPI CommConfigDialogW(LPCWSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
#ifdef UNICODE
#define CommConfigDialog CommConfigDialogW
#else
#define CommConfigDialog CommConfigDialogA
#endif 
WINBASEAPI BOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
WINBASEAPI BOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
#ifdef UNICODE
#define GetDefaultCommConfig GetDefaultCommConfigW
#else
#define GetDefaultCommConfig GetDefaultCommConfigA
#endif 
WINBASEAPI BOOL WINAPI SetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dwSize);
WINBASEAPI BOOL WINAPI SetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dwSize);
#ifdef UNICODE
#define SetDefaultCommConfig SetDefaultCommConfigW
#else
#define SetDefaultCommConfig SetDefaultCommConfigA
#endif 
*/
#ifndef _MAC
#define MAX_COMPUTERNAME_LENGTH 15
#else
#define MAX_COMPUTERNAME_LENGTH 31
#endif
WINBASEAPI BOOL WINAPI GetComputerNameA (LPSTR lpBuffer,LPDWORD nSize);
WINBASEAPI BOOL WINAPI GetComputerNameW (LPWSTR lpBuffer,LPDWORD nSize);
#ifdef UNICODE
#define GetComputerName GetComputerNameW
#else
#define GetComputerName GetComputerNameA
#endif 
WINBASEAPI BOOL WINAPI SetComputerNameA (LPCSTR lpComputerName);
WINBASEAPI BOOL WINAPI SetComputerNameW (LPCWSTR lpComputerName);
#ifdef UNICODE
#define SetComputerName SetComputerNameW
#else
#define SetComputerName SetComputerNameA
#endif 
#if (_WIN32_WINNT >=0x0500)
typedef enum _COMPUTER_NAME_FORMAT {
	ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
} COMPUTER_NAME_FORMAT ;
WINBASEAPI BOOL WINAPI GetComputerNameExA (COMPUTER_NAME_FORMAT NameType,LPSTR lpBuffer,LPDWORD nSize);
WINBASEAPI BOOL WINAPI GetComputerNameExW (COMPUTER_NAME_FORMAT NameType,LPWSTR lpBuffer,LPDWORD nSize);
#ifdef UNICODE
#define GetComputerNameEx GetComputerNameExW
#else
#define GetComputerNameEx GetComputerNameExA
#endif 
WINBASEAPI BOOL WINAPI SetComputerNameExA (COMPUTER_NAME_FORMAT NameType,LPCSTR lpBuffer);
WINBASEAPI BOOL WINAPI SetComputerNameExW (COMPUTER_NAME_FORMAT NameType,LPCWSTR lpBuffer);
#ifdef UNICODE
#define SetComputerNameEx SetComputerNameExW
#else
#define SetComputerNameEx SetComputerNameExA
#endif 
WINBASEAPI BOOL WINAPI DnsHostnameToComputerNameA (LPCSTR Hostname,LPSTR ComputerName,LPDWORD nSize);
WINBASEAPI BOOL WINAPI DnsHostnameToComputerNameW (LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD nSize);
#ifdef UNICODE
#define DnsHostnameToComputerName DnsHostnameToComputerNameW
#else
#define DnsHostnameToComputerName DnsHostnameToComputerNameA
#endif 
#endif 
/*
WINADVAPI BOOL WINAPI GetUserNameA (LPSTR lpBuffer,LPDWORD pcbBuffer);
WINADVAPI BOOL WINAPI GetUserNameW (LPWSTR lpBuffer,LPDWORD pcbBuffer);
#ifdef UNICODE
#define GetUserName GetUserNameW
#else
#define GetUserName GetUserNameA
#endif 
#define LOGON32_LOGON_INTERACTIVE 2
#define LOGON32_LOGON_NETWORK 3
#define LOGON32_LOGON_BATCH 4
#define LOGON32_LOGON_SERVICE 5
#define LOGON32_LOGON_UNLOCK 7
#if(_WIN32_WINNT >=0x0500)
#define LOGON32_LOGON_NETWORK_CLEARTEXT 8
#define LOGON32_LOGON_NEW_CREDENTIALS 9
#endif 
#define LOGON32_PROVIDER_DEFAULT 0
#define LOGON32_PROVIDER_WINNT35 1
#if(_WIN32_WINNT >=0x0400)
#define LOGON32_PROVIDER_WINNT40 2
#endif 
#if(_WIN32_WINNT >=0x0500)
#define LOGON32_PROVIDER_WINNT50 3
#endif 
WINADVAPI BOOL WINAPI LogonUserA (LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
WINADVAPI BOOL WINAPI LogonUserW (LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
#ifdef UNICODE
#define LogonUser LogonUserW
#else
#define LogonUser LogonUserA
#endif 
WINADVAPI BOOL WINAPI LogonUserExA (LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *ppProfileBuffer,LPDWORD pdwProfileLength,PQUOTA_LIMITS pQuotaLimits);
WINADVAPI BOOL WINAPI LogonUserExW (LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *ppProfileBuffer,LPDWORD pdwProfileLength,PQUOTA_LIMITS pQuotaLimits);
#ifdef UNICODE
#define LogonUserEx LogonUserExW
#else
#define LogonUserEx LogonUserExA
#endif 
WINADVAPI BOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
WINADVAPI BOOL WINAPI CreateProcessAsUserA (HANDLE hToken,LPCSTR lpApplicationName,LPSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,
	LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
WINADVAPI BOOL WINAPI CreateProcessAsUserW (HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,
	LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
#ifdef UNICODE
#define CreateProcessAsUser CreateProcessAsUserW
#else
#define CreateProcessAsUser CreateProcessAsUserA
#endif 
#if(_WIN32_WINNT >=0x0500)
#define LOGON_WITH_PROFILE 1
#define LOGON_NETCREDENTIALS_ONLY 2
#define LOGON_ZERO_PASSWORD_BUFFER 0x80000000
WINADVAPI BOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,
	LPPROCESS_INFORMATION lpProcessInformation);
WINADVAPI BOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
#endif 
WINADVAPI BOOL APIENTRY ImpersonateAnonymousToken(HANDLE ThreadHandle);
WINADVAPI BOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_ATTRIBUTES lpTokenAttributes,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
WINADVAPI BOOL APIENTRY CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD DisableSidCount,PSID_AND_ATTRIBUTES SidsToDisable,DWORD DeletePrivilegeCount,PLUID_AND_ATTRIBUTES PrivilegesToDelete,DWORD RestrictedSidCount,PSID_AND_ATTRIBUTES SidsToRestrict,
	PHANDLE NewTokenHandle);
WINADVAPI BOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
WINADVAPI BOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
WINADVAPI BOOL APIENTRY CheckTokenMembership(HANDLE TokenHandle,PSID SidToCheck,PBOOL IsMember);
*/
#if (_WIN32_WINNT >=0x0500)
typedef WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK ;
WINBASEAPI BOOL WINAPI RegisterWaitForSingleObject(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
WINBASEAPI HANDLE WINAPI RegisterWaitForSingleObjectEx(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
WINBASEAPI  BOOL WINAPI UnregisterWait(HANDLE WaitHandle);
WINBASEAPI  BOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
WINBASEAPI BOOL WINAPI QueueUserWorkItem(LPTHREAD_START_ROUTINE Function,PVOID Context,ULONG Flags);
WINBASEAPI BOOL WINAPI BindIoCompletionCallback (HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
WINBASEAPI HANDLE WINAPI CreateTimerQueue(VOID);
WINBASEAPI BOOL WINAPI CreateTimerQueueTimer(PHANDLE phNewTimer,HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,ULONG Flags) ;
WINBASEAPI  BOOL WINAPI ChangeTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,ULONG DueTime,ULONG Period);
WINBASEAPI  BOOL WINAPI DeleteTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,HANDLE CompletionEvent);
WINBASEAPI  BOOL WINAPI DeleteTimerQueueEx(HANDLE TimerQueue,HANDLE CompletionEvent);
WINBASEAPI HANDLE WINAPI SetTimerQueueTimer(HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,BOOL PreferIo);
WINBASEAPI  BOOL WINAPI CancelTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer);
WINBASEAPI  BOOL WINAPI DeleteTimerQueue(HANDLE TimerQueue);
#endif 
#if(_WIN32_WINNT >=0x0400)
#define HW_PROFILE_GUIDLEN 39 
#define MAX_PROFILE_LEN 80
#define DOCKINFO_UNDOCKED 1
#define DOCKINFO_DOCKED 2
#define DOCKINFO_USER_SUPPLIED 4
#define DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED|DOCKINFO_UNDOCKED)
#define DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED|DOCKINFO_DOCKED)
typedef struct tagHW_PROFILE_INFOA {
	DWORD dwDockInfo;
	CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
	CHAR szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;
typedef struct tagHW_PROFILE_INFOW {
	DWORD dwDockInfo;
	WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
	WCHAR szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;
#ifdef UNICODE
typedef HW_PROFILE_INFOW HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#else
typedef HW_PROFILE_INFOA HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#endif 
WINADVAPI BOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
WINADVAPI BOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
#ifdef UNICODE
#define GetCurrentHwProfile GetCurrentHwProfileW
#else
#define GetCurrentHwProfile GetCurrentHwProfileA
#endif 
#endif 
WINBASEAPI BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount);
WINBASEAPI BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
WINBASEAPI BOOL WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
WINBASEAPI BOOL WINAPI GetVersionExW(LPOSVERSIONINFOW lpVersionInformation);
#ifdef UNICODE
#define GetVersionEx GetVersionExW
#else
#define GetVersionEx GetVersionExA
#endif 
WINBASEAPI BOOL WINAPI VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);
WINBASEAPI BOOL WINAPI VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);
#ifdef UNICODE
#define VerifyVersionInfo VerifyVersionInfoW
#else
#define VerifyVersionInfo VerifyVersionInfoA
#endif 
#include <winerror.h>
#define TC_NORMAL 0
#define TC_HARDERR 1
#define TC_GP_TRAP 2
#define TC_SIGNAL 3
#if(WINVER >=0x0400)
#define AC_LINE_OFFLINE 0
#define AC_LINE_ONLINE 1
#define AC_LINE_BACKUP_POWER 2
#define AC_LINE_UNKNOWN 255
#define BATTERY_FLAG_HIGH 1
#define BATTERY_FLAG_LOW 2
#define BATTERY_FLAG_CRITICAL 4
#define BATTERY_FLAG_CHARGING 8
#define BATTERY_FLAG_NO_BATTERY 128
#define BATTERY_FLAG_UNKNOWN 255
#define BATTERY_PERCENTAGE_UNKNOWN 255
#define BATTERY_LIFE_UNKNOWN 0xffffffff
typedef struct _SYSTEM_POWER_STATUS {
	BYTE ACLineStatus;
	BYTE BatteryFlag;
	BYTE BatteryLifePercent;
	BYTE Reserved1;
	DWORD BatteryLifeTime;
	DWORD BatteryFullLifeTime;
} SYSTEM_POWER_STATUS,*LPSYSTEM_POWER_STATUS;
BOOL WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS lpSystemPowerStatus);
BOOL WINAPI SetSystemPowerState(BOOL fSuspend,BOOL fForce);
#endif 
#if (_WIN32_WINNT >=0x0500)
WINBASEAPI BOOL WINAPI AllocateUserPhysicalPages(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray);
WINBASEAPI BOOL WINAPI FreeUserPhysicalPages(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray);
WINBASEAPI BOOL WINAPI MapUserPhysicalPages(PVOID VirtualAddress,ULONG_PTR NumberOfPages,PULONG_PTR PageArray);
WINBASEAPI BOOL WINAPI MapUserPhysicalPagesScatter(PVOID *VirtualAddresses,ULONG_PTR NumberOfPages,PULONG_PTR PageArray);
WINBASEAPI HANDLE WINAPI CreateJobObjectA(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCWSTR lpName);
#ifdef UNICODE
#define CreateJobObject CreateJobObjectW
#else
#define CreateJobObject CreateJobObjectA
#endif 
WINBASEAPI HANDLE WINAPI OpenJobObjectA(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCSTR lpName);
WINBASEAPI HANDLE WINAPI OpenJobObjectW(DWORD dwDesiredAccess,BOOL bInheritHandle,LPCWSTR lpName);
#ifdef UNICODE
#define OpenJobObject OpenJobObjectW
#else
#define OpenJobObject OpenJobObjectA
#endif 
WINBASEAPI BOOL WINAPI AssignProcessToJobObject(HANDLE hJob,HANDLE hProcess);
WINBASEAPI BOOL WINAPI TerminateJobObject(HANDLE hJob,UINT uExitCode);
WINBASEAPI BOOL WINAPI QueryInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cbJobObjectInformationLength,LPDWORD lpReturnLength);
WINBASEAPI BOOL WINAPI SetInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cbJobObjectInformationLength);
WINBASEAPI BOOL WINAPI IsProcessInJob (HANDLE ProcessHandle,HANDLE JobHandle,PBOOL Result);
WINBASEAPI BOOL WINAPI CreateJobSet (ULONG NumJob,PJOB_SET_ARRAY UserJobSet,ULONG Flags);
WINBASEAPI PVOID WINAPI AddVectoredExceptionHandler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler (PVOID Handle);
WINBASEAPI PVOID WINAPI AddVectoredContinueHandler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler (PVOID Handle);
WINBASEAPI HANDLE WINAPI FindFirstVolumeA(LPSTR lpszVolumeName,DWORD cchBufferLength);
WINBASEAPI HANDLE WINAPI FindFirstVolumeW(LPWSTR lpszVolumeName,DWORD cchBufferLength);
#ifdef UNICODE
#define FindFirstVolume FindFirstVolumeW
#else
#define FindFirstVolume FindFirstVolumeA
#endif 
WINBASEAPI BOOL WINAPI FindNextVolumeA(HANDLE hFindVolume,LPSTR lpszVolumeName,DWORD cchBufferLength);
WINBASEAPI BOOL WINAPI FindNextVolumeW(HANDLE hFindVolume,LPWSTR lpszVolumeName,DWORD cchBufferLength);
#ifdef UNICODE
#define FindNextVolume FindNextVolumeW
#else
#define FindNextVolume FindNextVolumeA
#endif 
WINBASEAPI BOOL WINAPI FindVolumeClose(HANDLE hFindVolume);
WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointA(LPCSTR lpszRootPathName,LPSTR lpszVolumeMountPoint,DWORD cchBufferLength);
WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointW(LPCWSTR lpszRootPathName,LPWSTR lpszVolumeMountPoint,DWORD cchBufferLength);
#ifdef UNICODE
#define FindFirstVolumeMountPoint FindFirstVolumeMountPointW
#else
#define FindFirstVolumeMountPoint FindFirstVolumeMountPointA
#endif 
WINBASEAPI BOOL WINAPI FindNextVolumeMountPointA(HANDLE hFindVolumeMountPoint,LPSTR lpszVolumeMountPoint,DWORD cchBufferLength);
WINBASEAPI BOOL WINAPI FindNextVolumeMountPointW(HANDLE hFindVolumeMountPoint,LPWSTR lpszVolumeMountPoint,DWORD cchBufferLength);
#ifdef UNICODE
#define FindNextVolumeMountPoint FindNextVolumeMountPointW
#else
#define FindNextVolumeMountPoint FindNextVolumeMountPointA
#endif 
WINBASEAPI BOOL WINAPI FindVolumeMountPointClose(HANDLE hFindVolumeMountPoint);
WINBASEAPI BOOL WINAPI SetVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPCSTR lpszVolumeName);
WINBASEAPI BOOL WINAPI SetVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPCWSTR lpszVolumeName);
#ifdef UNICODE
#define SetVolumeMountPoint SetVolumeMountPointW
#else
#define SetVolumeMountPoint SetVolumeMountPointA
#endif 
WINBASEAPI BOOL WINAPI DeleteVolumeMountPointA(LPCSTR lpszVolumeMountPoint);
WINBASEAPI BOOL WINAPI DeleteVolumeMountPointW(LPCWSTR lpszVolumeMountPoint);
#ifdef UNICODE
#define DeleteVolumeMountPoint DeleteVolumeMountPointW
#else
#define DeleteVolumeMountPoint DeleteVolumeMountPointA
#endif 
WINBASEAPI BOOL WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPSTR lpszVolumeName,DWORD cchBufferLength);
WINBASEAPI BOOL WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPWSTR lpszVolumeName,DWORD cchBufferLength);
#ifdef UNICODE
#define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
#else
#define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
#endif 
WINBASEAPI BOOL WINAPI GetVolumePathNameA(LPCSTR lpszFileName,LPSTR lpszVolumePathName,DWORD cchBufferLength);
WINBASEAPI BOOL WINAPI GetVolumePathNameW(LPCWSTR lpszFileName,LPWSTR lpszVolumePathName,DWORD cchBufferLength);
#ifdef UNICODE
#define GetVolumePathName GetVolumePathNameW
#else
#define GetVolumePathName GetVolumePathNameA
#endif 
WINBASEAPI BOOL WINAPI GetVolumePathNamesForVolumeNameA(LPCSTR lpszVolumeName,LPCH lpszVolumePathNames,DWORD cchBufferLength,PDWORD lpcchReturnLength);
WINBASEAPI BOOL WINAPI GetVolumePathNamesForVolumeNameW(LPCWSTR lpszVolumeName,LPWCH lpszVolumePathNames,DWORD cchBufferLength,PDWORD lpcchReturnLength);
#ifdef UNICODE
#define GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameW
#else
#define GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameA
#endif 
#endif
#if (_WIN32_WINNT >=0x0500)||(_WIN32_FUSION >=0x0100)||ISOLATION_AWARE_ENABLED
#define ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 1
#define ACTCTX_FLAG_LANGID_VALID 2
#define ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 4
#define ACTCTX_FLAG_RESOURCE_NAME_VALID 8
#define ACTCTX_FLAG_SET_PROCESS_DEFAULT 16
#define ACTCTX_FLAG_APPLICATION_NAME_VALID 32
#define ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF 64
#define ACTCTX_FLAG_HMODULE_VALID 128
typedef struct tagACTCTXA {
	ULONG cbSize;
	DWORD dwFlags;
	LPCSTR lpSource;
	USHORT wProcessorArchitecture;
	LANGID wLangId;
	LPCSTR lpAssemblyDirectory;
	LPCSTR lpResourceName;
	LPCSTR lpApplicationName;
	HMODULE hModule;
} ACTCTXA,*PACTCTXA;
typedef struct tagACTCTXW {
	ULONG cbSize;
	DWORD dwFlags;
	LPCWSTR lpSource;
	USHORT wProcessorArchitecture;
	LANGID wLangId;
	LPCWSTR lpAssemblyDirectory;
	LPCWSTR lpResourceName;
	LPCWSTR lpApplicationName;
	HMODULE hModule;
} ACTCTXW,*PACTCTXW;
#ifdef UNICODE
typedef ACTCTXW ACTCTX;
typedef PACTCTXW PACTCTX;
#else
typedef ACTCTXA ACTCTX;
typedef PACTCTXA PACTCTX;
#endif 
typedef const ACTCTXA *PCACTCTXA;
typedef const ACTCTXW *PCACTCTXW;
#ifdef UNICODE
typedef ACTCTXW ACTCTX;
typedef PCACTCTXW PCACTCTX;
#else
typedef ACTCTXA ACTCTX;
typedef PCACTCTXA PCACTCTX;
#endif 
#endif
#if (_WIN32_WINNT >=0x0500)||(_WIN32_FUSION >=0x0100)
WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
#ifdef UNICODE
#define CreateActCtx CreateActCtxW
#else
#define CreateActCtx CreateActCtxA
#endif 
WINBASEAPI VOID WINAPI AddRefActCtx(HANDLE hActCtx);
WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
WINBASEAPI BOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
WINBASEAPI BOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);
#define DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION 1
WINBASEAPI BOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
WINBASEAPI BOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);
#endif
#if (_WIN32_WINNT >=0x0500)||(_WIN32_FUSION >=0x0100)||ISOLATION_AWARE_ENABLED
typedef struct tagACTCTX_SECTION_KEYED_DATA_2600 {
	ULONG cbSize;
	ULONG ulDataFormatVersion;
	PVOID lpData;
	ULONG ulLength;
	PVOID lpSectionGlobalData;
	ULONG ulSectionGlobalDataLength;
	PVOID lpSectionBase;
	ULONG ulSectionTotalLength;
	HANDLE hActCtx;
	ULONG ulAssemblyRosterIndex;
} ACTCTX_SECTION_KEYED_DATA_2600,*PACTCTX_SECTION_KEYED_DATA_2600;
typedef const ACTCTX_SECTION_KEYED_DATA_2600 * PCACTCTX_SECTION_KEYED_DATA_2600;
typedef struct tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA {
	PVOID lpInformation;
	PVOID lpSectionBase;
	ULONG ulSectionLength;
	PVOID lpSectionGlobalDataBase;
	ULONG ulSectionGlobalDataLength;
} ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;
typedef const ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;
typedef struct tagACTCTX_SECTION_KEYED_DATA {
	ULONG cbSize;
	ULONG ulDataFormatVersion;
	PVOID lpData;
	ULONG ulLength;
	PVOID lpSectionGlobalData;
	ULONG ulSectionGlobalDataLength;
	PVOID lpSectionBase;
	ULONG ulSectionTotalLength;
	HANDLE hActCtx;
	ULONG ulAssemblyRosterIndex;
	ULONG ulFlags;
	ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata;
} ACTCTX_SECTION_KEYED_DATA,*PACTCTX_SECTION_KEYED_DATA;
typedef const ACTCTX_SECTION_KEYED_DATA * PCACTCTX_SECTION_KEYED_DATA;
#define FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX 1
#define FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS 2
#define FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA 4
#endif
#if (_WIN32_WINNT >=0x0500)||(_WIN32_FUSION >=0x0100)
WINBASEAPI BOOL WINAPI FindActCtxSectionStringA(DWORD dwFlags,const GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
WINBASEAPI BOOL WINAPI FindActCtxSectionStringW(DWORD dwFlags,const GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
#ifdef UNICODE
#define FindActCtxSectionString FindActCtxSectionStringW
#else
#define FindActCtxSectionString FindActCtxSectionStringA
#endif 
WINBASEAPI BOOL WINAPI FindActCtxSectionGuid(DWORD dwFlags,const GUID *lpExtensionGuid,ULONG ulSectionId,const GUID *lpGuidToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
#endif
#if (_WIN32_WINNT >=0x0500)||(_WIN32_FUSION >=0x0100)||ISOLATION_AWARE_ENABLED
#if !defined(RC_INVOKED) 
#if !defined(ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED)
typedef struct _ACTIVATION_CONTEXT_BASIC_INFORMATION {
	HANDLE hActCtx;
	DWORD dwFlags;
} ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;
typedef const struct _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;
#define ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#endif 
#endif
#define QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX 4
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 8
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS 16
#define QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000
#endif
#if (_WIN32_WINNT >=0x0500)||(_WIN32_FUSION >=0x0100)
WINBASEAPI BOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T *pcbWrittenOrRequired);
typedef BOOL (WINAPI * PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T *pcbWrittenOrRequired);
#endif 
WINBASEAPI BOOL WINAPI ProcessIdToSessionId(DWORD dwProcessId,DWORD *pSessionId);
#if _WIN32_WINNT >=0x0501
WINBASEAPI DWORD WINAPI WTSGetActiveConsoleSessionId();
WINBASEAPI BOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
#endif 
// WINBASEAPI BOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,PDWORD ReturnedLength);
WINBASEAPI BOOL WINAPI GetNumaHighestNodeNumber(PULONG HighestNodeNumber);
WINBASEAPI BOOL WINAPI GetNumaProcessorNode(UCHAR Processor,PUCHAR NodeNumber);
WINBASEAPI BOOL WINAPI GetNumaNodeProcessorMask(UCHAR Node,PULONGLONG ProcessorMask);
WINBASEAPI BOOL WINAPI GetNumaAvailableMemoryNode(UCHAR Node,PULONGLONG AvailableBytes);
#if !defined(RC_INVOKED) 
#if defined(ISOLATION_AWARE_ENABLED) && (ISOLATION_AWARE_ENABLED !=0)
#include "winbase.inl"
#endif 
#endif 
#endif 
