#ifndef __win32_h__
#define __win32_h__
/*---------------------------------------------------------------------------*/
/* win32.h - WINDOWS 32 bit API functions header file                        */
/*---------------------------------------------------------------------------*/
#include <winerr.h>

/* Define windows basic data types */
#define CONST              const

typedef long               ISIZE;
typedef unsigned long      LSIZE;
typedef unsigned long      USIZE;

typedef unsigned long      DWORD;
typedef int                BOOL;
typedef unsigned char      BYTE;
typedef unsigned short     WORD;
typedef int                INT;
typedef char               CHAR;
typedef unsigned short     WCHAR;
typedef unsigned int       UINT;
typedef short              SHORT;
typedef long               LONG;
typedef void               VOID;
typedef void *             HANDLE;
typedef HANDLE             HGLOBAL;
typedef BYTE              *LPBYTE;
typedef long              *PLONG;
typedef unsigned int      *PUINT;
typedef DWORD             *LPDWORD;
typedef char              *LPSTR;
typedef const char        *LPCSTR;
typedef void              *PVOID;
typedef void              *LPVOID;
typedef CONST void        *LPCVOID;
typedef HANDLE            *LPHANDLE;

/* File system constants */
#define CREATE_NEW         1
#define CREATE_ALWAYS      2
#define OPEN_EXISTING      3
#define OPEN_ALWAYS        4
#define TRUNCATE_EXISTING  5

#define FILE_SHARE_READ                 0x00000001
#define FILE_SHARE_WRITE                0x00000002

#define FILE_ATTRIBUTE_READONLY         0x00000001
#define FILE_ATTRIBUTE_HIDDEN           0x00000002
#define FILE_ATTRIBUTE_SYSTEM           0x00000004
#define FILE_ATTRIBUTE_DIRECTORY        0x00000010
#define FILE_ATTRIBUTE_ARCHIVE          0x00000020
#define FILE_ATTRIBUTE_NORMAL           0x00000080
#define FILE_ATTRIBUTE_TEMPORARY        0x00000100
#define FILE_ATTRIBUTE_COMPRESSED       0x00000800

#define GENERIC_READ                    (0x80000000L)
#define GENERIC_WRITE                   (0x40000000L)

/* Invalid handle value */
#define INVALID_HANDLE_VALUE (HANDLE)-1

/* Standard handle constants */
#define STD_INPUT_HANDLE    (DWORD)-10
#define STD_OUTPUT_HANDLE   (DWORD)-11
#define STD_ERROR_HANDLE    (DWORD)-12

/* DuplicateHandle constants */
#define DUPLICATE_CLOSE_SOURCE      0x00000001
#define DUPLICATE_SAME_ACCESS       0x00000002

#define MB_PRECOMPOSED            0x00000001  // use precomposed chars
#define MB_ERR_INVALID_CHARS      0x00000008
#define ERROR_INSUFFICIENT_BUFFER        122L

/* Global Memory Flags */
#define GMEM_FIXED          0x0000
#define GMEM_MOVEABLE       0x0002
#define GMEM_NOCOMPACT      0x0010
#define GMEM_NODISCARD      0x0020
#define GMEM_ZEROINIT       0x0040
#define GMEM_MODIFY         0x0080
#define GMEM_DISCARDABLE    0x0100
#define GMEM_NOT_BANKED     0x1000
#define GMEM_SHARE          0x2000
#define GMEM_DDESHARE       0x2000
#define GMEM_NOTIFY         0x4000
#define GMEM_LOWER          GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS    0x7F72
#define GMEM_INVALID_HANDLE 0x8000

/* Infinite timeout value */
#define INFINITE            0xFFFFFFFF

/*
   System time is represented with the following structure:
*/
typedef struct DATETIME {
    WORD year;
    WORD month;
    WORD weekday;
    WORD day;
    WORD hours;
    WORD minutes;
    WORD seconds;
    WORD hundredths;
};
typedef struct DATETIME SYSTEMTIME;
typedef SYSTEMTIME *LPSYSTEMTIME;

/* Time zone information structure */
typedef struct TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[ 32 ];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[ 32 ];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
};
typedef struct TIME_ZONE_INFORMATION *LPTIME_ZONE_INFORMATION;

/*
   File structures
*/

typedef struct OVERLAPPED {
    DWORD   Internal;
    DWORD   InternalHigh;
    DWORD   Offset;
    DWORD   OffsetHigh;
    HANDLE  hEvent;
};
typedef struct OVERLAPPED *LPOVERLAPPED;

typedef struct SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};
typedef struct SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

/* Startup info structure */
typedef struct STARTUPINFOA {
    DWORD   cb;
    LPSTR   lpReserved;
    LPSTR   lpDesktop;
    LPSTR   lpTitle;
    DWORD   dwX;
    DWORD   dwY;
    DWORD   dwXSize;
    DWORD   dwYSize;
    DWORD   dwXCountChars;
    DWORD   dwYCountChars;
    DWORD   dwFillAttribute;
    DWORD   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    LPBYTE  lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
};
typedef struct STARTUPINFOA *LPSTARTUPINFOA;

/* Process information structure */
typedef struct PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
};
typedef struct PROCESS_INFORMATION *LPPROCESS_INFORMATION;

/*
   typedef for ctrl-c handler routines
*/

// typedef BOOL (__declspec(dllimport) *PHANDLER_ROUTINE)(DWORD CtrlType);

#define CTRL_C_EVENT        0
#define CTRL_BREAK_EVENT    1
#define CTRL_CLOSE_EVENT    2
/* 3 is reserved */
/* 4 is reserved */
#define CTRL_LOGOFF_EVENT   5
#define CTRL_SHUTDOWN_EVENT 6

/*
   definitions for console events
*/
typedef struct _COORD {
    SHORT X;
    SHORT Y;
} COORD, *PCOORD;

typedef struct _KEY_EVENT_RECORD {
    BOOL bKeyDown;
    WORD wRepeatCount;
    WORD wVirtualKeyCode;
    WORD wVirtualScanCode;
    CHAR AsciiChar;
    DWORD dwControlKeyState;
} KEY_EVENT_RECORD, *PKEY_EVENT_RECORD;

/*
   ControlKeyState flags
*/

#define RIGHT_ALT_PRESSED     0x0001
#define LEFT_ALT_PRESSED      0x0002
#define RIGHT_CTRL_PRESSED    0x0004
#define LEFT_CTRL_PRESSED     0x0008
#define SHIFT_PRESSED         0x0010
#define NUMLOCK_ON            0x0020
#define SCROLLLOCK_ON         0x0040
#define CAPSLOCK_ON           0x0080
#define ENHANCED_KEY          0x0100

typedef struct _MOUSE_EVENT_RECORD {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dwControlKeyState;
    DWORD dwEventFlags;
} MOUSE_EVENT_RECORD, *PMOUSE_EVENT_RECORD;


typedef struct _WINDOW_BUFFER_SIZE_RECORD {
    COORD dwSize;
} WINDOW_BUFFER_SIZE_RECORD, *PWINDOW_BUFFER_SIZE_RECORD;

typedef struct _MENU_EVENT_RECORD {
    UINT dwCommandId;
} MENU_EVENT_RECORD, *PMENU_EVENT_RECORD;

typedef struct _FOCUS_EVENT_RECORD {
    BOOL bSetFocus;
} FOCUS_EVENT_RECORD, *PFOCUS_EVENT_RECORD;

typedef struct tagINPUT_RECORD {
    WORD EventType;
//    union {
//        KEY_EVENT_RECORD KeyEvent;
        MOUSE_EVENT_RECORD MouseEvent;
//        WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
//        MENU_EVENT_RECORD MenuEvent;
//        FOCUS_EVENT_RECORD FocusEvent;
//    } Event;
} INPUT_RECORD; 

typedef INPUT_RECORD *PINPUT_RECORD;

/*
    EventType flags:
*/

#define KEY_EVENT                0x0001
#define MOUSE_EVENT              0x0002
#define WINDOW_BUFFER_SIZE_EVENT 0x0004
#define MENU_EVENT               0x0008
#define FOCUS_EVENT              0x0010

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
BOOL __declspec(dllimport) CloseHandle(HANDLE hObject);

HANDLE __declspec(dllimport) CreateFileA(LPCSTR lpFileName,
                          DWORD dwDesiredAccess,
                          DWORD dwShareMode,
                          LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                          DWORD dwCreationDisposition,
                          DWORD dwFlagsAndAttributes,
                          HANDLE hTemplateFile);

BOOL __declspec(dllimport) CreateProcessA(LPCSTR lpApplicationName,
                           LPSTR lpCommandLine,
                           LPSECURITY_ATTRIBUTES lpProcessAttributes,
                           LPSECURITY_ATTRIBUTES lpThreadAttributes,
                           BOOL bInheritHandles,
                           DWORD dwCreationFlags,
                           LPVOID lpEnvironment,
                           LPCSTR lpCurrentDirectory,
                           LPSTARTUPINFOA lpStartupInfo,
                           LPPROCESS_INFORMATION lpProcessInformation);

BOOL __declspec(dllimport) DeleteFileA(LPCSTR lpFileName);

BOOL __declspec(dllimport) DuplicateHandle(HANDLE hSourceProcessHandle,
                            HANDLE hSourceHandle,
                            HANDLE hTargetProcessHandle,
                            LPHANDLE lpTargetHandle,
                            DWORD dwDesiredAccess,
                            BOOL bInheritHandle,
                            DWORD dwOptions);

VOID __declspec(dllimport) ExitProcess(UINT uExitCode);

BOOL __declspec(dllimport) FlushConsoleInputBuffer(HANDLE hConsoleInput);

LPSTR __declspec(dllimport) GetCommandLineA(VOID);

int __declspec(dllimport) MultiByteToWideChar(unsigned CodePage,DWORD dwFlags, char *lpMultiByteStr,
     int      cbMultiByte, short * lpWideCharStr,int cchWideChar);

HANDLE __declspec(dllimport) GetCurrentProcess(VOID);

DWORD __declspec(dllimport) GetCurrentDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);

DWORD __declspec(dllimport) GetEnvironmentVariableA(LPCSTR lpName,
                                     LPSTR lpBuffer,
                                     DWORD nSize);

BOOL __declspec(dllimport) GetExitCodeProcess(HANDLE hProcess, LPDWORD lpExitCode);

DWORD __declspec(dllimport) GetFileAttributesA(LPCSTR lpFileName);

DWORD __declspec(dllimport) GetLastError(VOID);

VOID __declspec(dllimport) GetLocalTime(LPSYSTEMTIME lpSystemTime);

HANDLE __declspec(dllimport) GetStdHandle(DWORD nStdHandle);

DWORD __declspec(dllimport) GetTimeZoneInformation(
                LPTIME_ZONE_INFORMATION lpTimeZoneInformation);

HGLOBAL __declspec(dllimport) GlobalAlloc(UINT uFlags, DWORD dwBytes);

HGLOBAL __declspec(dllimport) GlobalFree(HGLOBAL hMem);

HGLOBAL __declspec(dllimport) GlobalReAlloc(HGLOBAL hMem, DWORD dwBytes, UINT uFlags);

BOOL __declspec(dllimport) MoveFileA(LPCSTR lpExistingFileName, LPCSTR lpNewFileName);

BOOL __declspec(dllimport) ReadConsoleInputA(HANDLE hConsoleInput,
                              PINPUT_RECORD lpBuffer,
                              DWORD nLength,
                              LPDWORD lpNumberOfEventsRead);

BOOL __declspec(dllimport) ReadFile(HANDLE hFile,
                     LPVOID lpBuffer,
                     DWORD nNumberOfBytesToRead,
                     LPDWORD lpNumberOfBytesRead,
                     LPOVERLAPPED lpOverlapped);

//BOOL __declspec(dllimport) SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,
//                                  BOOL Add);

BOOL __declspec(dllimport) SetEnvironmentVariableA(LPCSTR lpName, LPCSTR lpValue);

DWORD __declspec(dllimport) SetFilePointer(HANDLE hFile,
                            LONG lDistanceToMove,
                            PLONG lpDistanceToMoveHigh,
                            DWORD dwMoveMethod);

DWORD __declspec(dllimport) WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);

BOOL __declspec(dllimport) WriteFile(HANDLE hFile,
                      LPCVOID lpBuffer,
                      DWORD nNumberOfBytesToWrite,
                      LPDWORD lpNumberOfBytesWritten,
                      LPOVERLAPPED lpOverlapped);

BOOL __declspec(dllimport) SetFileAttributesA(char * lpFileName, DWORD dwFileAttributes );
BOOL __declspec(dllimport) CreateDirectoryA(LPCSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BOOL __declspec(dllimport) GetHandleInformation(void *Handle, DWORD *info);
#endif
