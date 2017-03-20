#ifndef __winver_h__
#define __winver_h__
#ifndef __windows_h__
#include <windows.h>
#endif
#define VS_FILE_INFO RT_VERSION
#define VS_VERSION_INFO 1
#define VS_USER_DEFINED 100
#ifndef _MAC
#define VS_FFI_SIGNATURE 0xfeef04bd
#else
#define VS_FFI_SIGNATURE 0xbd04effe
#endif
#define VS_FFI_STRUCVERSION 0x10000
#define VS_FFI_FILEFLAGSMASK 63
#define VS_FF_DEBUG 1
#define VS_FF_PRERELEASE 2
#define VS_FF_PATCHED 4
#define VS_FF_PRIVATEBUILD 8
#define VS_FF_INFOINFERRED 16
#define VS_FF_SPECIALBUILD 32
#define VOS_UNKNOWN 0
#define VOS_DOS 0x10000
#define VOS_OS216 0x20000
#define VOS_OS232 0x30000
#define VOS_NT 0x40000
#define VOS_WINCE 0x50000
#define VOS__BASE 0
#define VOS__WINDOWS16 1
#define VOS__PM16 2
#define VOS__PM32 3
#define VOS__WINDOWS32 4
#define VOS_DOS_WINDOWS16 0x10001
#define VOS_DOS_WINDOWS32 0x10004
#define VOS_OS216_PM16 0x20002
#define VOS_OS232_PM32 0x30003
#define VOS_NT_WINDOWS32 0x40004
#define VFT_UNKNOWN 0
#define VFT_APP 1
#define VFT_DLL 2
#define VFT_DRV 3
#define VFT_FONT 4
#define VFT_VXD 5
#define VFT_STATIC_LIB 7
#define VFT2_UNKNOWN 0
#define VFT2_DRV_PRINTER 1
#define VFT2_DRV_KEYBOARD 2
#define VFT2_DRV_LANGUAGE 3
#define VFT2_DRV_DISPLAY 4
#define VFT2_DRV_MOUSE 5
#define VFT2_DRV_NETWORK 6
#define VFT2_DRV_SYSTEM 7
#define VFT2_DRV_INSTALLABLE 8
#define VFT2_DRV_SOUND 9
#define VFT2_DRV_COMM 10
#define VFT2_DRV_INPUTMETHOD 11
#define VFT2_DRV_VERSIONED_PRINTER 12
#define VFT2_FONT_RASTER 1
#define VFT2_FONT_VECTOR 2
#define VFT2_FONT_TRUETYPE 3
#define VFFF_ISSHAREDFILE 1
#define VFF_CURNEDEST 1
#define VFF_FILEINUSE 2
#define VFF_BUFFTOOSMALL 4
#define VIFF_FORCEINSTALL 1
#define VIFF_DONTDELETEOLD 2
#define VIF_TEMPFILE 1
#define VIF_MISMATCH 2
#define VIF_SRCOLD 4
#define VIF_DIFFLANG 8
#define VIF_DIFFCODEPG 16
#define VIF_DIFFTYPE 32
#define VIF_WRITEPROT 64
#define VIF_FILEINUSE 128
#define VIF_OUTOFSPACE 256
#define VIF_ACCESSVIOLATION 512
#define VIF_SHARINGVIOLATION 1024
#define VIF_CANNOTCREATE 2048
#define VIF_CANNOTDELETE 0x1000
#define VIF_CANNOTRENAME 0x2000
#define VIF_CANNOTDELETECUR 0x4000
#define VIF_OUTOFMEMORY 0x8000
#define VIF_CANNOTREADSRC 0x10000
#define VIF_CANNOTREADDST 0x20000
#define VIF_BUFFTOOSMALL 0x40000
#define VIF_CANNOTLOADLZ32 0x80000
#define VIF_CANNOTLOADCABINET 0x100000
#ifndef RC_INVOKED 
typedef struct tagVS_FIXEDFILEINFO {
	DWORD dwSignature; 
	DWORD dwStrucVersion; 
	DWORD dwFileVersionMS; 
	DWORD dwFileVersionLS; 
	DWORD dwProductVersionMS; 
	DWORD dwProductVersionLS; 
	DWORD dwFileFlagsMask; 
	DWORD dwFileFlags; 
	DWORD dwFileOS; 
	DWORD dwFileType; 
	DWORD dwFileSubtype; 
	DWORD dwFileDateMS; 
	DWORD dwFileDateLS; 
} VS_FIXEDFILEINFO;
DWORD APIENTRY VerFindFileA(DWORD uFlags,LPSTR szFileName,LPSTR szWinDir,LPSTR szAppDir,LPSTR szCurDir,PUINT lpuCurDirLen,LPSTR szDestDir,PUINT lpuDestDirLen);
DWORD APIENTRY VerFindFileW(DWORD uFlags,LPWSTR szFileName,LPWSTR szWinDir,LPWSTR szAppDir,LPWSTR szCurDir,PUINT lpuCurDirLen,LPWSTR szDestDir,PUINT lpuDestDirLen);
#ifdef UNICODE
#define VerFindFile VerFindFileW
#else
#define VerFindFile VerFindFileA
#endif 
DWORD APIENTRY VerInstallFileA(DWORD uFlags,LPSTR szSrcFileName,LPSTR szDestFileName,LPSTR szSrcDir,LPSTR szDestDir,LPSTR szCurDir,LPSTR szTmpFile,PUINT lpuTmpFileLen);
DWORD APIENTRY VerInstallFileW(DWORD uFlags,LPWSTR szSrcFileName,LPWSTR szDestFileName,LPWSTR szSrcDir,LPWSTR szDestDir,LPWSTR szCurDir,LPWSTR szTmpFile,PUINT lpuTmpFileLen);
#ifdef UNICODE
#define VerInstallFile VerInstallFileW
#else
#define VerInstallFile VerInstallFileA
#endif 
DWORD APIENTRY GetFileVersionInfoSizeA(LPCSTR lptstrFilename,LPDWORD lpdwHandle); 
DWORD APIENTRY GetFileVersionInfoSizeW(LPCWSTR lptstrFilename,LPDWORD lpdwHandle); 
#ifdef UNICODE
#define GetFileVersionInfoSize GetFileVersionInfoSizeW
#else
#define GetFileVersionInfoSize GetFileVersionInfoSizeA
#endif 
BOOL APIENTRY GetFileVersionInfoA(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData); 
BOOL APIENTRY GetFileVersionInfoW(LPCWSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData); 
#ifdef UNICODE
#define GetFileVersionInfo GetFileVersionInfoW
#else
#define GetFileVersionInfo GetFileVersionInfoA
#endif 
DWORD APIENTRY VerLanguageNameA(DWORD wLang,LPSTR szLang,DWORD nSize);
DWORD APIENTRY VerLanguageNameW(DWORD wLang,LPWSTR szLang,DWORD nSize);
#ifdef UNICODE
#define VerLanguageName VerLanguageNameW
#else
#define VerLanguageName VerLanguageNameA
#endif 
BOOL APIENTRY VerQueryValueA(const LPVOID pBlock,LPSTR lpSubBlock,LPVOID * lplpBuffer,PUINT puLen);
BOOL APIENTRY VerQueryValueW(const LPVOID pBlock,LPWSTR lpSubBlock,LPVOID * lplpBuffer,PUINT puLen);
#ifdef UNICODE
#define VerQueryValue VerQueryValueW
#else
#define VerQueryValue VerQueryValueA
#endif 
#endif 
#endif 
