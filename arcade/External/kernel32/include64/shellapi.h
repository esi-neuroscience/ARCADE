#ifndef _INC_SHELLAPI
#define _INC_SHELLAPI
#ifndef WINSHELLAPI
#if !defined(_SHELL32_)
#define WINSHELLAPI DECLSPEC_IMPORT
#else
#define WINSHELLAPI
#endif
#endif 
#ifndef SHSTDAPI
#define SHSTDAPI EXTERN_C __declspec(dllimport) HRESULT 
#define SHSTDAPI_(type) EXTERN_C __declspec(dllimport) type
#endif 
#ifndef SHDOCAPI
#if !defined(_SHDOCVW_)
#define SHDOCAPI EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define SHDOCAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE
#else
#define SHDOCAPI STDAPI
#define SHDOCAPI_(type) STDAPI_(type)
#endif
#endif 
#if !defined(_WIN64)
#include <pshpack1.h>
#endif
DECLARE_HANDLE(HDROP);
SHSTDAPI_(UINT) DragQueryFileA(HDROP,UINT,LPSTR,UINT);
SHSTDAPI_(UINT) DragQueryFileW(HDROP,UINT,LPWSTR,UINT);
#ifdef UNICODE
#define DragQueryFile DragQueryFileW
#else
#define DragQueryFile DragQueryFileA
#endif 
SHSTDAPI_(BOOL) DragQueryPoint(HDROP,LPPOINT);
SHSTDAPI_(void) DragFinish(HDROP);
SHSTDAPI_(void) DragAcceptFiles(HWND,BOOL);
SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
#ifdef UNICODE
#define ShellExecute ShellExecuteW
#else
#define ShellExecute ShellExecuteA
#endif 
SHSTDAPI_(HINSTANCE) FindExecutableA(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lpResult);
SHSTDAPI_(HINSTANCE) FindExecutableW(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lpResult);
#ifdef UNICODE
#define FindExecutable FindExecutableW
#else
#define FindExecutable FindExecutableA
#endif 
SHSTDAPI_(LPWSTR *) CommandLineToArgvW(LPCWSTR lpCmdLine,int*pNumArgs);
SHSTDAPI_(INT) ShellAboutA(HWND hWnd,LPCSTR szApp,LPCSTR szOtherStuff,HICON hIcon);
SHSTDAPI_(INT) ShellAboutW(HWND hWnd,LPCWSTR szApp,LPCWSTR szOtherStuff,HICON hIcon);
#ifdef UNICODE
#define ShellAbout ShellAboutW
#else
#define ShellAbout ShellAboutA
#endif 
SHSTDAPI_(HICON) DuplicateIcon(HINSTANCE hInst,HICON hIcon);
SHSTDAPI_(HICON) ExtractAssociatedIconA(HINSTANCE hInst,LPSTR lpIconPath,LPWORD lpiIcon);
SHSTDAPI_(HICON) ExtractAssociatedIconW(HINSTANCE hInst,LPWSTR lpIconPath,LPWORD lpiIcon);
#ifdef UNICODE
#define ExtractAssociatedIcon ExtractAssociatedIconW
#else
#define ExtractAssociatedIcon ExtractAssociatedIconA
#endif 
SHSTDAPI_(HICON) ExtractAssociatedIconExA(HINSTANCE hInst,LPSTR lpIconPath,LPWORD lpiIconIndex,LPWORD lpiIconId); 
SHSTDAPI_(HICON) ExtractAssociatedIconExW(HINSTANCE hInst,LPWSTR lpIconPath,LPWORD lpiIconIndex,LPWORD lpiIconId); 
#ifdef UNICODE
#define ExtractAssociatedIconEx ExtractAssociatedIconExW
#else
#define ExtractAssociatedIconEx ExtractAssociatedIconExA
#endif 
SHSTDAPI_(HICON) ExtractIconA(HINSTANCE hInst,LPCSTR lpszExeFileName,UINT nIconIndex);
SHSTDAPI_(HICON) ExtractIconW(HINSTANCE hInst,LPCWSTR lpszExeFileName,UINT nIconIndex);
#ifdef UNICODE
#define ExtractIcon ExtractIconW
#else
#define ExtractIcon ExtractIconA
#endif 
#if(WINVER >=0x0400)
typedef struct _DRAGINFOA {
	UINT uSize; 
	POINT pt;
	BOOL fNC;
	LPSTR lpFileList;
	DWORD grfKeyState;
} DRAGINFOA,*LPDRAGINFOA;
typedef struct _DRAGINFOW {
	UINT uSize; 
	POINT pt;
	BOOL fNC;
	LPWSTR lpFileList;
	DWORD grfKeyState;
} DRAGINFOW,*LPDRAGINFOW;
#ifdef UNICODE
typedef DRAGINFOW DRAGINFO;
typedef LPDRAGINFOW LPDRAGINFO;
#else
typedef DRAGINFOA DRAGINFO;
typedef LPDRAGINFOA LPDRAGINFO;
#endif 
#define ABM_NEW 0
#define ABM_REMOVE 1
#define ABM_QUERYPOS 2
#define ABM_SETPOS 3
#define ABM_GETSTATE 4
#define ABM_GETTASKBARPOS 5
#define ABM_ACTIVATE 6 
#define ABM_GETAUTOHIDEBAR 7
#define ABM_SETAUTOHIDEBAR 8 
#define ABM_WINDOWPOSCHANGED 9
#define ABM_SETSTATE 10
#define ABN_STATECHANGE 0
#define ABN_POSCHANGED 1
#define ABN_FULLSCREENAPP 2
#define ABN_WINDOWARRANGE 3 
#define ABS_AUTOHIDE 1
#define ABS_ALWAYSONTOP 2
#define ABE_LEFT 0
#define ABE_TOP 1
#define ABE_RIGHT 2
#define ABE_BOTTOM 3
typedef struct _AppBarData {
	DWORD cbSize;
	HWND hWnd;
	UINT uCallbackMessage;
	UINT uEdge;
	RECT rc;
	LPARAM lParam; 
} APPBARDATA,*PAPPBARDATA;
SHSTDAPI_(UINT_PTR) SHAppBarMessage(DWORD dwMessage,PAPPBARDATA pData);
SHSTDAPI_(DWORD) DoEnvironmentSubstA(LPSTR szString,UINT cchString);
SHSTDAPI_(DWORD) DoEnvironmentSubstW(LPWSTR szString,UINT cchString);
#ifdef UNICODE
#define DoEnvironmentSubst DoEnvironmentSubstW
#else
#define DoEnvironmentSubst DoEnvironmentSubstA
#endif 
#define EIRESID(x) (-1 * (int)(x))
SHSTDAPI_(UINT) ExtractIconExA(LPCSTR lpszFile,int nIconIndex,HICON *phiconLarge,HICON *phiconSmall,UINT nIcons);
SHSTDAPI_(UINT) ExtractIconExW(LPCWSTR lpszFile,int nIconIndex,HICON *phiconLarge,HICON *phiconSmall,UINT nIcons);
#ifdef UNICODE
#define ExtractIconEx ExtractIconExW
#else
#define ExtractIconEx ExtractIconExA
#endif 
#ifndef FO_MOVE 
#define FO_MOVE 1
#define FO_COPY 2
#define FO_DELETE 3
#define FO_RENAME 4
#define FOF_MULTIDESTFILES 1
#define FOF_CONFIRMMOUSE 2
#define FOF_SILENT 4 
#define FOF_RENAMEONCOLLISION 8
#define FOF_NOCONFIRMATION 16 
#define FOF_WANTMAPPINGHANDLE 32 
#define FOF_ALLOWUNDO 64
#define FOF_FILESONLY 128 
#define FOF_SIMPLEPROGRESS 256 
#define FOF_NOCONFIRMMKDIR 512 
#define FOF_NOERRORUI 1024 
#define FOF_NOCOPYSECURITYATTRIBS 2048 
#define FOF_NORECURSION 0x1000 
#if (_WIN32_IE >=0x0500)
#define FOF_NO_CONNECTED_ELEMENTS 0x2000 
#define FOF_WANTNUKEWARNING 0x4000 
#endif 
#if (_WIN32_WINNT >=0x0501)
#define FOF_NORECURSEREPARSE 0x8000 
#endif 
typedef WORD FILEOP_FLAGS;
#define PO_DELETE 19 
#define PO_RENAME 20 
#define PO_PORTCHANGE 32 
#define PO_REN_PORT 52 
typedef WORD PRINTEROP_FLAGS;
#endif 
typedef struct _SHFILEOPSTRUCTA {
		HWND hwnd;
		UINT wFunc;
		LPCSTR pFrom;
		LPCSTR pTo;
		FILEOP_FLAGS fFlags;
		BOOL fAnyOperationsAborted;
		LPVOID hNameMappings;
		LPCSTR lpszProgressTitle; 
} SHFILEOPSTRUCTA,*LPSHFILEOPSTRUCTA;
typedef struct _SHFILEOPSTRUCTW {
		HWND hwnd;
		UINT wFunc;
		LPCWSTR pFrom;
		LPCWSTR pTo;
		FILEOP_FLAGS fFlags;
		BOOL fAnyOperationsAborted;
		LPVOID hNameMappings;
		LPCWSTR lpszProgressTitle; 
} SHFILEOPSTRUCTW,*LPSHFILEOPSTRUCTW;
#ifdef UNICODE
typedef SHFILEOPSTRUCTW SHFILEOPSTRUCT;
typedef LPSHFILEOPSTRUCTW LPSHFILEOPSTRUCT;
#else
typedef SHFILEOPSTRUCTA SHFILEOPSTRUCT;
typedef LPSHFILEOPSTRUCTA LPSHFILEOPSTRUCT;
#endif 
SHSTDAPI_(int) SHFileOperationA(LPSHFILEOPSTRUCTA lpFileOp);
SHSTDAPI_(int) SHFileOperationW(LPSHFILEOPSTRUCTW lpFileOp);
#ifdef UNICODE
#define SHFileOperation SHFileOperationW
#else
#define SHFileOperation SHFileOperationA
#endif 
SHSTDAPI_(void) SHFreeNameMappings(HANDLE hNameMappings);
typedef struct _SHNAMEMAPPINGA {
	LPSTR pszOldPath;
	LPSTR pszNewPath;
	int cchOldPath;
	int cchNewPath;
} SHNAMEMAPPINGA,*LPSHNAMEMAPPINGA;
typedef struct _SHNAMEMAPPINGW {
	LPWSTR pszOldPath;
	LPWSTR pszNewPath;
	int cchOldPath;
	int cchNewPath;
} SHNAMEMAPPINGW,*LPSHNAMEMAPPINGW;
#ifdef UNICODE
typedef SHNAMEMAPPINGW SHNAMEMAPPING;
typedef LPSHNAMEMAPPINGW LPSHNAMEMAPPING;
#else
typedef SHNAMEMAPPINGA SHNAMEMAPPING;
typedef LPSHNAMEMAPPINGA LPSHNAMEMAPPING;
#endif 
#define SE_ERR_FNF 2 
#define SE_ERR_PNF 3 
#define SE_ERR_ACCESSDENIED 5 
#define SE_ERR_OOM 8 
#define SE_ERR_DLLNOTFOUND 32
#endif 
#define SE_ERR_SHARE 26
#define SE_ERR_ASSOCINCOMPLETE 27
#define SE_ERR_DDETIMEOUT 28
#define SE_ERR_DDEFAIL 29
#define SE_ERR_DDEBUSY 30
#define SE_ERR_NOASSOC 31
#if(WINVER >=0x0400)
#define SEE_MASK_CLASSNAME 1
#define SEE_MASK_CLASSKEY 3
#define SEE_MASK_IDLIST 4
#define SEE_MASK_INVOKEIDLIST 12
#define SEE_MASK_ICON 16
#define SEE_MASK_HOTKEY 32
#define SEE_MASK_NOCLOSEPROCESS 64
#define SEE_MASK_CONNECTNETDRV 128
#define SEE_MASK_FLAG_DDEWAIT 256
#define SEE_MASK_DOENVSUBST 512
#define SEE_MASK_FLAG_NO_UI 1024
#define SEE_MASK_UNICODE 0x4000
#define SEE_MASK_NO_CONSOLE 0x8000
#define SEE_MASK_ASYNCOK 0x100000
#define SEE_MASK_HMONITOR 0x200000
#if (_WIN32_IE >=0x0560)
#define SEE_MASK_NOZONECHECKS 0x800000
#endif 
#if (_WIN32_IE >=0x0500)
#define SEE_MASK_NOQUERYCLASSSTORE 0x1000000
#define SEE_MASK_WAITFORINPUTIDLE 0x2000000
#endif 
#if (_WIN32_IE >=0x0560)
#define SEE_MASK_FLAG_LOG_USAGE 0x4000000
#endif 
#ifndef DUMMYUNIONNAME
#ifdef NONAMELESSUNION
#define DUMMYUNIONNAME u
#define DUMMYUNIONNAME2 u2
#define DUMMYUNIONNAME3 u3
#define DUMMYUNIONNAME4 u4
#define DUMMYUNIONNAME5 u5
#else
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#endif
#endif 
typedef struct _SHELLEXECUTEINFOA {
		DWORD cbSize;
		ULONG fMask;
		HWND hwnd;
		LPCSTR lpVerb;
		LPCSTR lpFile;
		LPCSTR lpParameters;
		LPCSTR lpDirectory;
		int nShow;
		HINSTANCE hInstApp;
		LPVOID lpIDList;
		LPCSTR lpClass;
		HKEY hkeyClass;
		DWORD dwHotKey;
		union {
		HANDLE hIcon;
		HANDLE hMonitor;
		} DUMMYUNIONNAME;
		HANDLE hProcess;
} SHELLEXECUTEINFOA,*LPSHELLEXECUTEINFOA;
typedef struct _SHELLEXECUTEINFOW {
		DWORD cbSize;
		ULONG fMask;
		HWND hwnd;
		LPCWSTR lpVerb;
		LPCWSTR lpFile;
		LPCWSTR lpParameters;
		LPCWSTR lpDirectory;
		int nShow;
		HINSTANCE hInstApp;
		LPVOID lpIDList;
		LPCWSTR lpClass;
		HKEY hkeyClass;
		DWORD dwHotKey;
		union {
		HANDLE hIcon;
		HANDLE hMonitor;
		} DUMMYUNIONNAME;
		HANDLE hProcess;
} SHELLEXECUTEINFOW,*LPSHELLEXECUTEINFOW;
#ifdef UNICODE
typedef SHELLEXECUTEINFOW SHELLEXECUTEINFO;
typedef LPSHELLEXECUTEINFOW LPSHELLEXECUTEINFO;
#else
typedef SHELLEXECUTEINFOA SHELLEXECUTEINFO;
typedef LPSHELLEXECUTEINFOA LPSHELLEXECUTEINFO;
#endif 
SHSTDAPI_(BOOL) ShellExecuteExA(LPSHELLEXECUTEINFOA lpExecInfo);
SHSTDAPI_(BOOL) ShellExecuteExW(LPSHELLEXECUTEINFOW lpExecInfo);
#ifdef UNICODE
#define ShellExecuteEx ShellExecuteExW
#else
#define ShellExecuteEx ShellExecuteExA
#endif 
SHSTDAPI_(void) WinExecErrorA(HWND hwnd,int error,LPCSTR lpstrFileName,LPCSTR lpstrTitle);
SHSTDAPI_(void) WinExecErrorW(HWND hwnd,int error,LPCWSTR lpstrFileName,LPCWSTR lpstrTitle);
#ifdef UNICODE
#define WinExecError WinExecErrorW
#else
#define WinExecError WinExecErrorA
#endif 
typedef struct _SHCREATEPROCESSINFOW {
		DWORD cbSize;
		ULONG fMask;
		HWND hwnd;
		LPCWSTR pszFile;
		LPCWSTR pszParameters;
		LPCWSTR pszCurrentDirectory;
		 HANDLE hUserToken;
		 LPSECURITY_ATTRIBUTES lpProcessAttributes;
		 LPSECURITY_ATTRIBUTES lpThreadAttributes;
		 BOOL bInheritHandles;
		 DWORD dwCreationFlags;
		 LPSTARTUPINFOW lpStartupInfo;
		 LPPROCESS_INFORMATION lpProcessInformation;
} SHCREATEPROCESSINFOW,*PSHCREATEPROCESSINFOW;
SHSTDAPI_(BOOL) SHCreateProcessAsUserW(PSHCREATEPROCESSINFOW pscpi);
typedef struct _SHQUERYRBINFO {
	DWORD cbSize;
#if !defined(_MAC)||defined(_MAC_INT_64)
	__int64 i64Size;
	__int64 i64NumItems;
#else
	DWORDLONG i64Size;
	DWORDLONG i64NumItems;
#endif
} SHQUERYRBINFO,*LPSHQUERYRBINFO;
#define SHERB_NOCONFIRMATION 1
#define SHERB_NOPROGRESSUI 2
#define SHERB_NOSOUND 4
SHSTDAPI SHQueryRecycleBinA(LPCSTR pszRootPath,LPSHQUERYRBINFO pSHQueryRBInfo);
SHSTDAPI SHQueryRecycleBinW(LPCWSTR pszRootPath,LPSHQUERYRBINFO pSHQueryRBInfo);
#ifdef UNICODE
#define SHQueryRecycleBin SHQueryRecycleBinW
#else
#define SHQueryRecycleBin SHQueryRecycleBinA
#endif 
SHSTDAPI SHEmptyRecycleBinA(HWND hwnd,LPCSTR pszRootPath,DWORD dwFlags);
SHSTDAPI SHEmptyRecycleBinW(HWND hwnd,LPCWSTR pszRootPath,DWORD dwFlags);
#ifdef UNICODE
#define SHEmptyRecycleBin SHEmptyRecycleBinW
#else
#define SHEmptyRecycleBin SHEmptyRecycleBinA
#endif 
typedef struct _NOTIFYICONDATAA {
		DWORD cbSize;
		HWND hWnd;
		UINT uID;
		UINT uFlags;
		UINT uCallbackMessage;
		HICON hIcon;
#if (_WIN32_IE < 0x0500)
		CHAR szTip[64];
#else
		CHAR szTip[128];
#endif
#if (_WIN32_IE >=0x0500)
		DWORD dwState;
		DWORD dwStateMask;
		CHAR szInfo[256];
		union {
			UINT uTimeout;
			UINT uVersion;
		} DUMMYUNIONNAME;
		CHAR szInfoTitle[64];
		DWORD dwInfoFlags;
#endif
#if (_WIN32_IE >=0x600)
		GUID guidItem;
#endif
} NOTIFYICONDATAA,*PNOTIFYICONDATAA;
typedef struct _NOTIFYICONDATAW {
		DWORD cbSize;
		HWND hWnd;
		UINT uID;
		UINT uFlags;
		UINT uCallbackMessage;
		HICON hIcon;
#if (_WIN32_IE < 0x0500)
		WCHAR szTip[64];
#else
		WCHAR szTip[128];
#endif
#if (_WIN32_IE >=0x0500)
		DWORD dwState;
		DWORD dwStateMask;
		WCHAR szInfo[256];
		union {
			UINT uTimeout;
			UINT uVersion;
		} DUMMYUNIONNAME;
		WCHAR szInfoTitle[64];
		DWORD dwInfoFlags;
#endif
#if (_WIN32_IE >=0x600)
		GUID guidItem;
#endif
} NOTIFYICONDATAW,*PNOTIFYICONDATAW;
#ifdef UNICODE
typedef NOTIFYICONDATAW NOTIFYICONDATA;
typedef PNOTIFYICONDATAW PNOTIFYICONDATA;
#else
typedef NOTIFYICONDATAA NOTIFYICONDATA;
typedef PNOTIFYICONDATAA PNOTIFYICONDATA;
#endif 
#define NOTIFYICONDATAA_V1_SIZE FIELD_OFFSET(NOTIFYICONDATAA,szTip[64])
#define NOTIFYICONDATAW_V1_SIZE FIELD_OFFSET(NOTIFYICONDATAW,szTip[64])
#ifdef UNICODE
#define NOTIFYICONDATA_V1_SIZE NOTIFYICONDATAW_V1_SIZE
#else
#define NOTIFYICONDATA_V1_SIZE NOTIFYICONDATAA_V1_SIZE
#endif
#define NOTIFYICONDATAA_V2_SIZE FIELD_OFFSET(NOTIFYICONDATAA,guidItem)
#define NOTIFYICONDATAW_V2_SIZE FIELD_OFFSET(NOTIFYICONDATAW,guidItem)
#ifdef UNICODE
#define NOTIFYICONDATA_V2_SIZE NOTIFYICONDATAW_V2_SIZE
#else
#define NOTIFYICONDATA_V2_SIZE NOTIFYICONDATAA_V2_SIZE
#endif
#if (_WIN32_IE >=0x0500)
#define NIN_SELECT (WM_USER + 0)
#define NINF_KEY 1
#define NIN_KEYSELECT (NIN_SELECT|NINF_KEY)
#endif
#if (_WIN32_IE >=0x0501)
#define NIN_BALLOONSHOW (WM_USER + 2)
#define NIN_BALLOONHIDE (WM_USER + 3)
#define NIN_BALLOONTIMEOUT (WM_USER + 4)
#define NIN_BALLOONUSERCLICK (WM_USER + 5)
#endif
#define NIM_ADD 0
#define NIM_MODIFY 1
#define NIM_DELETE 2
#if (_WIN32_IE >=0x0500)
#define NIM_SETFOCUS 3
#define NIM_SETVERSION 4
#define NOTIFYICON_VERSION 3
#endif
#define NIF_MESSAGE 1
#define NIF_ICON 2
#define NIF_TIP 4
#if (_WIN32_IE >=0x0500)
#define NIF_STATE 8
#define NIF_INFO 16
#endif
#if (_WIN32_IE >=0x600)
#define NIF_GUID 32
#endif
#if (_WIN32_IE >=0x0500)
#define NIS_HIDDEN 1
#define NIS_SHAREDICON 2
#define NIIF_NONE 0
#define NIIF_INFO 1
#define NIIF_WARNING 2
#define NIIF_ERROR 3
#define NIIF_ICON_MASK 15
#if (_WIN32_IE >=0x0501)
#define NIIF_NOSOUND 16
#endif
#endif
SHSTDAPI_(BOOL) Shell_NotifyIconA(DWORD dwMessage,PNOTIFYICONDATAA lpData);
SHSTDAPI_(BOOL) Shell_NotifyIconW(DWORD dwMessage,PNOTIFYICONDATAW lpData);
#ifdef UNICODE
#define Shell_NotifyIcon Shell_NotifyIconW
#else
#define Shell_NotifyIcon Shell_NotifyIconA
#endif 
#ifndef SHFILEINFO_DEFINED
#define SHFILEINFO_DEFINED
typedef struct _SHFILEINFOA {
		HICON hIcon; 
		int iIcon; 
		DWORD dwAttributes; 
		CHAR szDisplayName[MAX_PATH]; 
		CHAR szTypeName[80]; 
} SHFILEINFOA;
typedef struct _SHFILEINFOW {
		HICON hIcon; 
		int iIcon; 
		DWORD dwAttributes; 
		WCHAR szDisplayName[MAX_PATH]; 
		WCHAR szTypeName[80]; 
} SHFILEINFOW;
#ifdef UNICODE
typedef SHFILEINFOW SHFILEINFO;
#else
typedef SHFILEINFOA SHFILEINFO;
#endif 
#endif 
#define SHGFI_ICON 256 
#define SHGFI_DISPLAYNAME 512 
#define SHGFI_TYPENAME 1024 
#define SHGFI_ATTRIBUTES 2048 
#define SHGFI_ICONLOCATION 0x1000 
#define SHGFI_EXETYPE 0x2000 
#define SHGFI_SYSICONINDEX 0x4000 
#define SHGFI_LINKOVERLAY 0x8000 
#define SHGFI_SELECTED 0x10000 
#define SHGFI_ATTR_SPECIFIED 0x20000 
#define SHGFI_LARGEICON 0 
#define SHGFI_SMALLICON 1 
#define SHGFI_OPENICON 2 
#define SHGFI_SHELLICONSIZE 4 
#define SHGFI_PIDL 8 
#define SHGFI_USEFILEATTRIBUTES 16 
#if (_WIN32_IE >=0x0500)
#define SHGFI_ADDOVERLAYS 32 
#define SHGFI_OVERLAYINDEX 64 
#endif
SHSTDAPI_(DWORD_PTR) SHGetFileInfoA(LPCSTR pszPath,DWORD dwFileAttributes,SHFILEINFOA *psfi,UINT cbFileInfo,UINT uFlags);
SHSTDAPI_(DWORD_PTR) SHGetFileInfoW(LPCWSTR pszPath,DWORD dwFileAttributes,SHFILEINFOW *psfi,UINT cbFileInfo,UINT uFlags);
#ifdef UNICODE
#define SHGetFileInfo SHGetFileInfoW
#else
#define SHGetFileInfo SHGetFileInfoA
#endif 
#define SHGetDiskFreeSpace SHGetDiskFreeSpaceEx
SHSTDAPI_(BOOL) SHGetDiskFreeSpaceExA(LPCSTR pszDirectoryName,ULARGE_INTEGER* pulFreeBytesAvailableToCaller,ULARGE_INTEGER* pulTotalNumberOfBytes,ULARGE_INTEGER* pulTotalNumberOfFreeBytes);
SHSTDAPI_(BOOL) SHGetDiskFreeSpaceExW(LPCWSTR pszDirectoryName,ULARGE_INTEGER* pulFreeBytesAvailableToCaller,ULARGE_INTEGER* pulTotalNumberOfBytes,ULARGE_INTEGER* pulTotalNumberOfFreeBytes);
#ifdef UNICODE
#define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExW
#else
#define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExA
#endif 
SHSTDAPI_(BOOL) SHGetNewLinkInfoA(LPCSTR pszLinkTo,LPCSTR pszDir,LPSTR pszName,BOOL *pfMustCopy,UINT uFlags);
SHSTDAPI_(BOOL) SHGetNewLinkInfoW(LPCWSTR pszLinkTo,LPCWSTR pszDir,LPWSTR pszName,BOOL *pfMustCopy,UINT uFlags);
#ifdef UNICODE
#define SHGetNewLinkInfo SHGetNewLinkInfoW
#else
#define SHGetNewLinkInfo SHGetNewLinkInfoA
#endif 
#define SHGNLI_PIDL 1 
#define SHGNLI_PREFIXNAME 2 
#define SHGNLI_NOUNIQUE 4 
#if (_WIN32_IE >=0x0501)
#define SHGNLI_NOLNK 8 
#endif 
#define PRINTACTION_OPEN 0
#define PRINTACTION_PROPERTIES 1
#define PRINTACTION_NETINSTALL 2
#define PRINTACTION_NETINSTALLLINK 3
#define PRINTACTION_TESTPAGE 4
#define PRINTACTION_OPENNETPRN 5
#ifdef WINNT
#define PRINTACTION_DOCUMENTDEFAULTS 6
#define PRINTACTION_SERVERPROPERTIES 7
#endif
SHSTDAPI_(BOOL) SHInvokePrinterCommandA(HWND hwnd,UINT uAction,LPCSTR lpBuf1,LPCSTR lpBuf2,BOOL fModal);
SHSTDAPI_(BOOL) SHInvokePrinterCommandW(HWND hwnd,UINT uAction,LPCWSTR lpBuf1,LPCWSTR lpBuf2,BOOL fModal);
#ifdef UNICODE
#define SHInvokePrinterCommand SHInvokePrinterCommandW
#else
#define SHInvokePrinterCommand SHInvokePrinterCommandA
#endif 
#endif 
#if (_WIN32_WINNT >=0x0500)||(_WIN32_WINDOWS >=0x0500) 
SHSTDAPI SHLoadNonloadedIconOverlayIdentifiers(void);
SHSTDAPI SHIsFileAvailableOffline(LPCWSTR pwszPath,LPDWORD pdwStatus);
#define OFFLINE_STATUS_LOCAL 1 
#define OFFLINE_STATUS_REMOTE 2 
#define OFFLINE_STATUS_INCOMPLETE 4 
#endif
SHSTDAPI SHSetLocalizedName(LPWSTR pszPath,LPCWSTR pszResModule,int idsRes);
int _cdecl ShellMessageBoxA(HINSTANCE hAppInst,HWND hWnd,LPCSTR lpcText,LPCSTR lpcTitle,UINT fuStyle,...);
int _cdecl ShellMessageBoxW(HINSTANCE hAppInst,HWND hWnd,LPCWSTR lpcText,LPCWSTR lpcTitle,UINT fuStyle,...);
#ifdef UNICODE
#define ShellMessageBox ShellMessageBoxW
#else
#define ShellMessageBox ShellMessageBoxA
#endif 
SHSTDAPI_(BOOL) IsLFNDriveA(LPCSTR pszPath);
SHSTDAPI_(BOOL) IsLFNDriveW(LPCWSTR pszPath);
#ifdef UNICODE
#define IsLFNDrive IsLFNDriveW
#else
#define IsLFNDrive IsLFNDriveA
#endif 
#if _WIN32_IE >=0x0600
STDAPI SHEnumerateUnreadMailAccountsA(HKEY hKeyUser,DWORD dwIndex,LPSTR pszMailAddress,int cchMailAddress);
STDAPI SHEnumerateUnreadMailAccountsW(HKEY hKeyUser,DWORD dwIndex,LPWSTR pszMailAddress,int cchMailAddress);
#ifdef UNICODE
#define SHEnumerateUnreadMailAccounts SHEnumerateUnreadMailAccountsW
#else
#define SHEnumerateUnreadMailAccounts SHEnumerateUnreadMailAccountsA
#endif 
STDAPI SHGetUnreadMailCountA(HKEY hKeyUser,LPCSTR pszMailAddress,DWORD *pdwCount,FILETIME *pFileTime,LPSTR pszShellExecuteCommand,int cchShellExecuteCommand);
STDAPI SHGetUnreadMailCountW(HKEY hKeyUser,LPCWSTR pszMailAddress,DWORD *pdwCount,FILETIME *pFileTime,LPWSTR pszShellExecuteCommand,int cchShellExecuteCommand);
#ifdef UNICODE
#define SHGetUnreadMailCount SHGetUnreadMailCountW
#else
#define SHGetUnreadMailCount SHGetUnreadMailCountA
#endif 
STDAPI SHSetUnreadMailCountA(LPCSTR pszMailAddress,DWORD dwCount,LPCSTR pszShellExecuteCommand);
STDAPI SHSetUnreadMailCountW(LPCWSTR pszMailAddress,DWORD dwCount,LPCWSTR pszShellExecuteCommand);
#ifdef UNICODE
#define SHSetUnreadMailCount SHSetUnreadMailCountW
#else
#define SHSetUnreadMailCount SHSetUnreadMailCountA
#endif 
#endif 
STDAPI_(BOOL) SHTestTokenMembership(HANDLE hToken,ULONG ulRID);
#if _WIN32_IE >=0x0600
HRESULT SHGetImageList(int iImageList,REFIID riid,void **ppvObj);
#define SHIL_LARGE 0 
#define SHIL_SMALL 1 
#define SHIL_EXTRALARGE 2
#define SHIL_SYSSMALL 3 
#define SHIL_LAST SHIL_SYSSMALL
typedef HRESULT (STDMETHODCALLTYPE *PFNCANSHAREFOLDERW)(LPCWSTR pszPath);
typedef HRESULT (STDMETHODCALLTYPE *PFNSHOWSHAREFOLDERUIW)(HWND hwndParent,LPCWSTR pszPath);
#endif 
#if !defined(_WIN64)
#include <poppack.h>
#endif
#endif 
