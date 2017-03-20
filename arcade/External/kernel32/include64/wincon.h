#ifndef _WINCON_
#define _WINCON_
typedef struct _COORD {
	SHORT X;
	SHORT Y;
} COORD,*PCOORD;
typedef struct _SMALL_RECT {
	SHORT Left;
	SHORT Top;
	SHORT Right;
	SHORT Bottom;
} SMALL_RECT,*PSMALL_RECT;
typedef struct _KEY_EVENT_RECORD {
	BOOL bKeyDown;
	WORD wRepeatCount;
	WORD wVirtualKeyCode;
	WORD wVirtualScanCode;
	union {
		WCHAR UnicodeChar;
		CHAR AsciiChar;
	} uChar;
	DWORD dwControlKeyState;
} KEY_EVENT_RECORD,*PKEY_EVENT_RECORD;
#define RIGHT_ALT_PRESSED 1 
#define LEFT_ALT_PRESSED 2 
#define RIGHT_CTRL_PRESSED 4 
#define LEFT_CTRL_PRESSED 8 
#define SHIFT_PRESSED 16 
#define NUMLOCK_ON 32 
#define SCROLLLOCK_ON 64 
#define CAPSLOCK_ON 128 
#define ENHANCED_KEY 256 
#define NLS_DBCSCHAR 0x10000 
#define NLS_ALPHANUMERIC 0 
#define NLS_KATAKANA 0x20000 
#define NLS_HIRAGANA 0x40000 
#define NLS_ROMAN 0x400000 
#define NLS_IME_CONVERSION 0x800000 
#define NLS_IME_DISABLE 0x20000000 
typedef struct _MOUSE_EVENT_RECORD {
	COORD dwMousePosition;
	DWORD dwButtonState;
	DWORD dwControlKeyState;
	DWORD dwEventFlags;
} MOUSE_EVENT_RECORD,*PMOUSE_EVENT_RECORD;
#define FROM_LEFT_1ST_BUTTON_PRESSED 1
#define RIGHTMOST_BUTTON_PRESSED 2
#define FROM_LEFT_2ND_BUTTON_PRESSED 4
#define FROM_LEFT_3RD_BUTTON_PRESSED 8
#define FROM_LEFT_4TH_BUTTON_PRESSED 16
#define MOUSE_MOVED 1
#define DOUBLE_CLICK 2
#define MOUSE_WHEELED 4
typedef struct _WINDOW_BUFFER_SIZE_RECORD {
	COORD dwSize;
} WINDOW_BUFFER_SIZE_RECORD,*PWINDOW_BUFFER_SIZE_RECORD;
typedef struct _MENU_EVENT_RECORD {
	UINT dwCommandId;
} MENU_EVENT_RECORD,*PMENU_EVENT_RECORD;
typedef struct _FOCUS_EVENT_RECORD {
	BOOL bSetFocus;
} FOCUS_EVENT_RECORD,*PFOCUS_EVENT_RECORD;
typedef struct _INPUT_RECORD {
	WORD EventType;
	union {
		KEY_EVENT_RECORD KeyEvent;
		MOUSE_EVENT_RECORD MouseEvent;
		WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
		MENU_EVENT_RECORD MenuEvent;
		FOCUS_EVENT_RECORD FocusEvent;
	} Event;
} INPUT_RECORD,*PINPUT_RECORD;
#define KEY_EVENT 1 
#define MOUSE_EVENT 2 
#define WINDOW_BUFFER_SIZE_EVENT 4 
#define MENU_EVENT 8 
#define FOCUS_EVENT 16 
typedef struct _CHAR_INFO {
	union {
		WCHAR UnicodeChar;
		CHAR AsciiChar;
	} Char;
	WORD Attributes;
} CHAR_INFO,*PCHAR_INFO;
#define FOREGROUND_BLUE 1 
#define FOREGROUND_GREEN 2 
#define FOREGROUND_RED 4 
#define FOREGROUND_INTENSITY 8 
#define BACKGROUND_BLUE 16 
#define BACKGROUND_GREEN 32 
#define BACKGROUND_RED 64 
#define BACKGROUND_INTENSITY 128 
#define COMMON_LVB_LEADING_BYTE 256 
#define COMMON_LVB_TRAILING_BYTE 512 
#define COMMON_LVB_GRID_HORIZONTAL 1024 
#define COMMON_LVB_GRID_LVERTICAL 2048 
#define COMMON_LVB_GRID_RVERTICAL 0x1000 
#define COMMON_LVB_REVERSE_VIDEO 0x4000 
#define COMMON_LVB_UNDERSCORE 0x8000 
#define COMMON_LVB_SBCSDBCS 768 
typedef struct _CONSOLE_SCREEN_BUFFER_INFO {
	COORD dwSize;
	COORD dwCursorPosition;
	WORD wAttributes;
	SMALL_RECT srWindow;
	COORD dwMaximumWindowSize;
} CONSOLE_SCREEN_BUFFER_INFO,*PCONSOLE_SCREEN_BUFFER_INFO;
typedef struct _CONSOLE_CURSOR_INFO {
	DWORD dwSize;
	BOOL bVisible;
} CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;
typedef struct _CONSOLE_FONT_INFO {
	DWORD nFont;
	COORD dwFontSize;
} CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;
#if(_WIN32_WINNT >=0x0500)
typedef struct _CONSOLE_SELECTION_INFO {
	DWORD dwFlags;
	COORD dwSelectionAnchor;
	SMALL_RECT srSelection;
} CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;
#define CONSOLE_NO_SELECTION 0
#define CONSOLE_SELECTION_IN_PROGRESS 1 
#define CONSOLE_SELECTION_NOT_EMPTY 2 
#define CONSOLE_MOUSE_SELECTION 4 
#define CONSOLE_MOUSE_DOWN 8 
#endif 
typedef BOOL 
(WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);
#define CTRL_C_EVENT 0
#define CTRL_BREAK_EVENT 1
#define CTRL_CLOSE_EVENT 2
#define CTRL_LOGOFF_EVENT 5
#define CTRL_SHUTDOWN_EVENT 6
#define ENABLE_PROCESSED_INPUT 1
#define ENABLE_LINE_INPUT 2
#define ENABLE_ECHO_INPUT 4
#define ENABLE_WINDOW_INPUT 8
#define ENABLE_MOUSE_INPUT 16
#define ENABLE_PROCESSED_OUTPUT 1
#define ENABLE_WRAP_AT_EOL_OUTPUT 2
WINBASEAPI BOOL WINAPI PeekConsoleInputA(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsRead);
WINBASEAPI BOOL WINAPI PeekConsoleInputW(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsRead);
#ifdef UNICODE
#define PeekConsoleInput PeekConsoleInputW
#else
#define PeekConsoleInput PeekConsoleInputA
#endif 
WINBASEAPI BOOL WINAPI ReadConsoleInputA(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsRead);
WINBASEAPI BOOL WINAPI ReadConsoleInputW(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsRead);
#ifdef UNICODE
#define ReadConsoleInput ReadConsoleInputW
#else
#define ReadConsoleInput ReadConsoleInputA
#endif 
WINBASEAPI BOOL WINAPI WriteConsoleInputA(HANDLE hConsoleInput,CONST INPUT_RECORD *lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsWritten);
WINBASEAPI BOOL WINAPI WriteConsoleInputW(HANDLE hConsoleInput,CONST INPUT_RECORD *lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsWritten);
#ifdef UNICODE
#define WriteConsoleInput WriteConsoleInputW
#else
#define WriteConsoleInput WriteConsoleInputA
#endif 
WINBASEAPI BOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpReadRegion);
WINBASEAPI BOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpReadRegion);
#ifdef UNICODE
#define ReadConsoleOutput ReadConsoleOutputW
#else
#define ReadConsoleOutput ReadConsoleOutputA
#endif 
WINBASEAPI BOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpWriteRegion);
WINBASEAPI BOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpWriteRegion);
#ifdef UNICODE
#define WriteConsoleOutput WriteConsoleOutputW
#else
#define WriteConsoleOutput WriteConsoleOutputA
#endif 
WINBASEAPI BOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD nLength,COORD dwReadCoord,LPDWORD lpNumberOfCharsRead);
WINBASEAPI BOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD nLength,COORD dwReadCoord,LPDWORD lpNumberOfCharsRead);
#ifdef UNICODE
#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#else
#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#endif 
WINBASEAPI BOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD nLength,COORD dwReadCoord,LPDWORD lpNumberOfAttrsRead);
WINBASEAPI BOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfCharsWritten);
WINBASEAPI BOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfCharsWritten);
#ifdef UNICODE
#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#else
#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#endif 
WINBASEAPI BOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST WORD *lpAttribute,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfAttrsWritten);
WINBASEAPI BOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfCharsWritten);
WINBASEAPI BOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfCharsWritten);
#ifdef UNICODE
#define FillConsoleOutputCharacter FillConsoleOutputCharacterW
#else
#define FillConsoleOutputCharacter FillConsoleOutputCharacterA
#endif 
WINBASEAPI BOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,WORD wAttribute,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfAttrsWritten);
WINBASEAPI BOOL WINAPI GetConsoleMode(HANDLE hConsoleHandle,LPDWORD lpMode);
WINBASEAPI BOOL WINAPI GetNumberOfConsoleInputEvents(HANDLE hConsoleInput,LPDWORD lpNumberOfEvents);
WINBASEAPI BOOL WINAPI GetConsoleScreenBufferInfo(HANDLE hConsoleOutput,PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo);
WINBASEAPI COORD WINAPI GetLargestConsoleWindowSize(HANDLE hConsoleOutput);
WINBASEAPI BOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
#if(_WIN32_WINNT >=0x0500)
WINBASEAPI BOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,BOOL bMaximumWindow,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
WINBASEAPI COORD WINAPI GetConsoleFontSize(HANDLE hConsoleOutput,DWORD nFont);
WINBASEAPI BOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
#endif 
WINBASEAPI BOOL WINAPI GetNumberOfConsoleMouseButtons(LPDWORD lpNumberOfMouseButtons);
WINBASEAPI BOOL WINAPI SetConsoleMode(HANDLE hConsoleHandle,DWORD dwMode);
WINBASEAPI BOOL WINAPI SetConsoleActiveScreenBuffer(HANDLE hConsoleOutput);
WINBASEAPI BOOL WINAPI FlushConsoleInputBuffer(HANDLE hConsoleInput);
WINBASEAPI BOOL WINAPI SetConsoleScreenBufferSize(HANDLE hConsoleOutput,COORD dwSize);
WINBASEAPI BOOL WINAPI SetConsoleCursorPosition(HANDLE hConsoleOutput,COORD dwCursorPosition);
WINBASEAPI BOOL WINAPI SetConsoleCursorInfo(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
WINBASEAPI BOOL WINAPI ScrollConsoleScreenBufferA(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
WINBASEAPI BOOL WINAPI ScrollConsoleScreenBufferW(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
#ifdef UNICODE
#define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferW
#else
#define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferA
#endif 
WINBASEAPI BOOL WINAPI SetConsoleWindowInfo(HANDLE hConsoleOutput,BOOL bAbsolute,CONST SMALL_RECT *lpConsoleWindow);
WINBASEAPI BOOL WINAPI SetConsoleTextAttribute(HANDLE hConsoleOutput,WORD wAttributes);
WINBASEAPI BOOL WINAPI SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,BOOL Add);
WINBASEAPI BOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dwProcessGroupId);
WINBASEAPI BOOL WINAPI AllocConsole(VOID );
WINBASEAPI BOOL WINAPI FreeConsole(VOID );
#if(_WIN32_WINNT >=0x0500)
WINBASEAPI BOOL WINAPI AttachConsole(DWORD dwProcessId);
#define ATTACH_PARENT_PROCESS ((DWORD)-1)
#endif 
WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD nSize);
WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD nSize);
#ifdef UNICODE
#define GetConsoleTitle GetConsoleTitleW
#else
#define GetConsoleTitle GetConsoleTitleA
#endif 
WINBASEAPI BOOL WINAPI SetConsoleTitleA(LPCSTR lpConsoleTitle);
WINBASEAPI BOOL WINAPI SetConsoleTitleW(LPCWSTR lpConsoleTitle);
#ifdef UNICODE
#define SetConsoleTitle SetConsoleTitleW
#else
#define SetConsoleTitle SetConsoleTitleA
#endif 
WINBASEAPI BOOL WINAPI ReadConsoleA(HANDLE hConsoleInput,LPVOID lpBuffer,DWORD nNumberOfCharsToRead,LPDWORD lpNumberOfCharsRead,LPVOID lpReserved);
WINBASEAPI BOOL WINAPI ReadConsoleW(HANDLE hConsoleInput,LPVOID lpBuffer,DWORD nNumberOfCharsToRead,LPDWORD lpNumberOfCharsRead,LPVOID lpReserved);
#ifdef UNICODE
#define ReadConsole ReadConsoleW
#else
#define ReadConsole ReadConsoleA
#endif 
WINBASEAPI BOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lpBuffer,DWORD nNumberOfCharsToWrite,LPDWORD lpNumberOfCharsWritten,LPVOID lpReserved);
WINBASEAPI BOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lpBuffer,DWORD nNumberOfCharsToWrite,LPDWORD lpNumberOfCharsWritten,LPVOID lpReserved);
#ifdef UNICODE
#define WriteConsole WriteConsoleW
#else
#define WriteConsole WriteConsoleA
#endif 
#define CONSOLE_TEXTMODE_BUFFER 1
WINBASEAPI HANDLE WINAPI CreateConsoleScreenBuffer(DWORD dwDesiredAccess,DWORD dwShareMode,CONST SECURITY_ATTRIBUTES *lpSecurityAttributes,DWORD dwFlags,LPVOID lpScreenBufferData);
WINBASEAPI UINT WINAPI GetConsoleCP(VOID );
WINBASEAPI BOOL WINAPI SetConsoleCP(UINT wCodePageID);
WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID );
WINBASEAPI BOOL WINAPI SetConsoleOutputCP(UINT wCodePageID);
#if(_WIN32_WINNT >=0x0500)
#define CONSOLE_FULLSCREEN 1 
#define CONSOLE_FULLSCREEN_HARDWARE 2 
WINBASEAPI BOOL APIENTRY GetConsoleDisplayMode(LPDWORD lpModeFlags);
WINBASEAPI HWND APIENTRY GetConsoleWindow(VOID);
#endif 
#if(_WIN32_WINNT >=0x0501)
WINBASEAPI DWORD APIENTRY GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dwProcessCount);
WINBASEAPI BOOL APIENTRY AddConsoleAliasA(LPSTR Source,LPSTR Target,LPSTR ExeName);
WINBASEAPI BOOL APIENTRY AddConsoleAliasW(LPWSTR Source,LPWSTR Target,LPWSTR ExeName);
#ifdef UNICODE
#define AddConsoleAlias AddConsoleAliasW
#else
#define AddConsoleAlias AddConsoleAliasA
#endif 
WINBASEAPI DWORD APIENTRY GetConsoleAliasA(LPSTR Source,LPSTR TargetBuffer,DWORD TargetBufferLength,LPSTR ExeName);
WINBASEAPI DWORD APIENTRY GetConsoleAliasW(LPWSTR Source,LPWSTR TargetBuffer,DWORD TargetBufferLength,LPWSTR ExeName);
#ifdef UNICODE
#define GetConsoleAlias GetConsoleAliasW
#else
#define GetConsoleAlias GetConsoleAliasA
#endif 
WINBASEAPI DWORD APIENTRY GetConsoleAliasesLengthA(LPSTR ExeName);
WINBASEAPI DWORD APIENTRY GetConsoleAliasesLengthW(LPWSTR ExeName);
#ifdef UNICODE
#define GetConsoleAliasesLength GetConsoleAliasesLengthW
#else
#define GetConsoleAliasesLength GetConsoleAliasesLengthA
#endif 
WINBASEAPI DWORD APIENTRY GetConsoleAliasExesLengthA(VOID);
WINBASEAPI DWORD APIENTRY GetConsoleAliasExesLengthW(VOID);
#ifdef UNICODE
#define GetConsoleAliasExesLength GetConsoleAliasExesLengthW
#else
#define GetConsoleAliasExesLength GetConsoleAliasExesLengthA
#endif 
WINBASEAPI DWORD APIENTRY GetConsoleAliasesA(LPSTR AliasBuffer,DWORD AliasBufferLength,LPSTR ExeName);
WINBASEAPI DWORD APIENTRY GetConsoleAliasesW(LPWSTR AliasBuffer,DWORD AliasBufferLength,LPWSTR ExeName);
#ifdef UNICODE
#define GetConsoleAliases GetConsoleAliasesW
#else
#define GetConsoleAliases GetConsoleAliasesA
#endif 
WINBASEAPI DWORD APIENTRY GetConsoleAliasExesA(LPSTR ExeNameBuffer,DWORD ExeNameBufferLength);
WINBASEAPI DWORD APIENTRY GetConsoleAliasExesW(LPWSTR ExeNameBuffer,DWORD ExeNameBufferLength);
#ifdef UNICODE
#define GetConsoleAliasExes GetConsoleAliasExesW
#else
#define GetConsoleAliasExes GetConsoleAliasExesA
#endif 
#endif 
#endif 
