#ifndef _INC_COMMDLG
#define _INC_COMMDLG
#if(WINVER >=0x0500)
#ifdef DEFINE_GUID
DEFINE_GUID(IID_IPrintDialogCallback,0x5852a2c3,0x6530,0x11d1,0xb6,0xa3,0x0,0x0,0xf8,0x75,0x7b,0xf9);
DEFINE_GUID(IID_IPrintDialogServices,0x509aaeda,0x5639,0x11d1,0xb6,0xa1,0x0,0x0,0xf8,0x75,0x7b,0xf9);
#endif
#endif 
#ifndef GUID_DEFS_ONLY
#include <prsht.h>
#if !defined(_WIN64)
#include <pshpack1.h> 
#endif
#ifndef WINCOMMDLGAPI
#if !defined(_COMDLG32_)
#define WINCOMMDLGAPI DECLSPEC_IMPORT
#else
#define WINCOMMDLGAPI
#endif
#endif 
#if(WINVER >=0x0400)
#ifndef SNDMSG
#ifdef __cplusplus
#ifndef _MAC
#define SNDMSG ::SendMessage
#else
#define SNDMSG ::AfxSendMessage
#endif
#else 
#ifndef _MAC
#define SNDMSG SendMessage
#else
#define SNDMSG AfxSendMessage
#endif
#endif 
#endif 
#endif 
#ifdef _MAC
typedef struct tagEDITMENU {
 HMENU hmenu;
 WORD idEdit;
 WORD idCut;
 WORD idCopy;
 WORD idPaste;
 WORD idClear;
 WORD idUndo;
} EDITMENU;
typedef EDITMENU *LPEDITMENU;
#endif
typedef UINT_PTR (CALLBACK *LPOFNHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
#ifndef CDSIZEOF_STRUCT
#define CDSIZEOF_STRUCT(structname,member)(((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
#endif
#ifndef DUMMYUNIONNAME
#ifdef NONAMELESSUNION
#define DUMMYUNIONNAME u
#endif 
#endif 
typedef struct tagOFN_NT4A {
 DWORD lStructSize;
 HWND hwndOwner;
 HINSTANCE hInstance;
 LPCSTR lpstrFilter;
 LPSTR lpstrCustomFilter;
 DWORD nMaxCustFilter;
 DWORD nFilterIndex;
 LPSTR lpstrFile;
 DWORD nMaxFile;
 LPSTR lpstrFileTitle;
 DWORD nMaxFileTitle;
 LPCSTR lpstrInitialDir;
 LPCSTR lpstrTitle;
 DWORD Flags;
 WORD nFileOffset;
 WORD nFileExtension;
 LPCSTR lpstrDefExt;
 LPARAM lCustData;
 LPOFNHOOKPROC lpfnHook;
 LPCSTR lpTemplateName;
} OPENFILENAME_NT4A,*LPOPENFILENAME_NT4A;
typedef struct tagOFN_NT4W {
 DWORD lStructSize;
 HWND hwndOwner;
 HINSTANCE hInstance;
 LPCWSTR lpstrFilter;
 LPWSTR lpstrCustomFilter;
 DWORD nMaxCustFilter;
 DWORD nFilterIndex;
 LPWSTR lpstrFile;
 DWORD nMaxFile;
 LPWSTR lpstrFileTitle;
 DWORD nMaxFileTitle;
 LPCWSTR lpstrInitialDir;
 LPCWSTR lpstrTitle;
 DWORD Flags;
 WORD nFileOffset;
 WORD nFileExtension;
 LPCWSTR lpstrDefExt;
 LPARAM lCustData;
 LPOFNHOOKPROC lpfnHook;
 LPCWSTR lpTemplateName;
} OPENFILENAME_NT4W,*LPOPENFILENAME_NT4W;
#ifdef UNICODE
typedef OPENFILENAME_NT4W OPENFILENAME_NT4;
typedef LPOPENFILENAME_NT4W LPOPENFILENAME_NT4;
#else
typedef OPENFILENAME_NT4A OPENFILENAME_NT4;
typedef LPOPENFILENAME_NT4A LPOPENFILENAME_NT4;
#endif 
typedef struct tagOFNA {
 DWORD lStructSize;
 HWND hwndOwner;
 HINSTANCE hInstance;
 LPCSTR lpstrFilter;
 LPSTR lpstrCustomFilter;
 DWORD nMaxCustFilter;
 DWORD nFilterIndex;
 LPSTR lpstrFile;
 DWORD nMaxFile;
 LPSTR lpstrFileTitle;
 DWORD nMaxFileTitle;
 LPCSTR lpstrInitialDir;
 LPCSTR lpstrTitle;
 DWORD Flags;
 WORD nFileOffset;
 WORD nFileExtension;
 LPCSTR lpstrDefExt;
 LPARAM lCustData;
 LPOFNHOOKPROC lpfnHook;
 LPCSTR lpTemplateName;
#ifdef _MAC
 LPEDITMENU lpEditInfo;
 LPCSTR lpstrPrompt;
#endif
#if (_WIN32_WINNT >=0x0500)
 void *		pvReserved;
 DWORD dwReserved;
 DWORD FlagsEx;
#endif 
} OPENFILENAMEA,*LPOPENFILENAMEA;
typedef struct tagOFNW {
 DWORD lStructSize;
 HWND hwndOwner;
 HINSTANCE hInstance;
 LPCWSTR lpstrFilter;
 LPWSTR lpstrCustomFilter;
 DWORD nMaxCustFilter;
 DWORD nFilterIndex;
 LPWSTR lpstrFile;
 DWORD nMaxFile;
 LPWSTR lpstrFileTitle;
 DWORD nMaxFileTitle;
 LPCWSTR lpstrInitialDir;
 LPCWSTR lpstrTitle;
 DWORD Flags;
 WORD nFileOffset;
 WORD nFileExtension;
 LPCWSTR lpstrDefExt;
 LPARAM lCustData;
 LPOFNHOOKPROC lpfnHook;
 LPCWSTR lpTemplateName;
#ifdef _MAC
 LPEDITMENU lpEditInfo;
 LPCSTR lpstrPrompt;
#endif
#if (_WIN32_WINNT >=0x0500)
 void *		pvReserved;
 DWORD dwReserved;
 DWORD FlagsEx;
#endif 
} OPENFILENAMEW,*LPOPENFILENAMEW;
#ifdef UNICODE
typedef OPENFILENAMEW OPENFILENAME;
typedef LPOPENFILENAMEW LPOPENFILENAME;
#else
typedef OPENFILENAMEA OPENFILENAME;
typedef LPOPENFILENAMEA LPOPENFILENAME;
#endif 
#if (_WIN32_WINNT >=0x0500)
#define OPENFILENAME_SIZE_VERSION_400A CDSIZEOF_STRUCT(OPENFILENAMEA,lpTemplateName)
#define OPENFILENAME_SIZE_VERSION_400W CDSIZEOF_STRUCT(OPENFILENAMEW,lpTemplateName)
#ifdef UNICODE
#define OPENFILENAME_SIZE_VERSION_400 OPENFILENAME_SIZE_VERSION_400W
#else
#define OPENFILENAME_SIZE_VERSION_400 OPENFILENAME_SIZE_VERSION_400A
#endif 
#endif 
WINCOMMDLGAPI BOOL APIENTRY GetOpenFileNameA(LPOPENFILENAMEA);
WINCOMMDLGAPI BOOL APIENTRY GetOpenFileNameW(LPOPENFILENAMEW);
#ifdef UNICODE
#define GetOpenFileName GetOpenFileNameW
#else
#define GetOpenFileName GetOpenFileNameA
#endif 
WINCOMMDLGAPI BOOL APIENTRY GetSaveFileNameA(LPOPENFILENAMEA);
WINCOMMDLGAPI BOOL APIENTRY GetSaveFileNameW(LPOPENFILENAMEW);
#ifdef UNICODE
#define GetSaveFileName GetSaveFileNameW
#else
#define GetSaveFileName GetSaveFileNameA
#endif 
WINCOMMDLGAPI short APIENTRY GetFileTitleA(LPCSTR,LPSTR,WORD);
WINCOMMDLGAPI short APIENTRY GetFileTitleW(LPCWSTR,LPWSTR,WORD);
#ifdef UNICODE
#define GetFileTitle GetFileTitleW
#else
#define GetFileTitle GetFileTitleA
#endif 
#define OFN_READONLY 1
#define OFN_OVERWRITEPROMPT 2
#define OFN_HIDEREADONLY 4
#define OFN_NOCHANGEDIR 8
#define OFN_SHOWHELP 16
#define OFN_ENABLEHOOK 32
#define OFN_ENABLETEMPLATE 64
#define OFN_ENABLETEMPLATEHANDLE 128
#define OFN_NOVALIDATE 256
#define OFN_ALLOWMULTISELECT 512
#define OFN_EXTENSIONDIFFERENT 1024
#define OFN_PATHMUSTEXIST 2048
#define OFN_FILEMUSTEXIST 0x1000
#define OFN_CREATEPROMPT 0x2000
#define OFN_SHAREAWARE 0x4000
#define OFN_NOREADONLYRETURN 0x8000
#define OFN_NOTESTFILECREATE 0x10000
#define OFN_NONETWORKBUTTON 0x20000
#define OFN_NOLONGNAMES 0x40000 
#if(WINVER >=0x0400)
#define OFN_EXPLORER 0x80000 
#define OFN_NODEREFERENCELINKS 0x100000
#define OFN_LONGNAMES 0x200000 
#define OFN_ENABLEINCLUDENOTIFY 0x400000 
#define OFN_ENABLESIZING 0x800000
#endif 
#if (_WIN32_WINNT >=0x0500)
#define OFN_DONTADDTORECENT 0x2000000
#define OFN_FORCESHOWHIDDEN 0x10000000 
#endif 
#if (_WIN32_WINNT >=0x0500)
#define OFN_EX_NOPLACESBAR 1
#endif 
#define OFN_SHAREFALLTHROUGH 2
#define OFN_SHARENOWARN 1
#define OFN_SHAREWARN 0
typedef UINT_PTR (CALLBACK *LPCCHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
#if(WINVER >=0x0400)
typedef struct _OFNOTIFYA {
		NMHDR hdr;
		LPOPENFILENAMEA lpOFN;
		LPSTR pszFile; 
} OFNOTIFYA,*LPOFNOTIFYA;
typedef struct _OFNOTIFYW {
		NMHDR hdr;
		LPOPENFILENAMEW lpOFN;
		LPWSTR pszFile; 
} OFNOTIFYW,*LPOFNOTIFYW;
#ifdef UNICODE
typedef OFNOTIFYW OFNOTIFY;
typedef LPOFNOTIFYW LPOFNOTIFY;
#else
typedef OFNOTIFYA OFNOTIFY;
typedef LPOFNOTIFYA LPOFNOTIFY;
#endif 
typedef struct _OFNOTIFYEXA {
		NMHDR hdr;
		LPOPENFILENAMEA lpOFN;
		LPVOID psf;
		LPVOID pidl; 
} OFNOTIFYEXA,*LPOFNOTIFYEXA;
typedef struct _OFNOTIFYEXW {
		NMHDR hdr;
		LPOPENFILENAMEW lpOFN;
		LPVOID psf;
		LPVOID pidl; 
} OFNOTIFYEXW,*LPOFNOTIFYEXW;
#ifdef UNICODE
typedef OFNOTIFYEXW OFNOTIFYEX;
typedef LPOFNOTIFYEXW LPOFNOTIFYEX;
#else
typedef OFNOTIFYEXA OFNOTIFYEX;
typedef LPOFNOTIFYEXA LPOFNOTIFYEX;
#endif 
#define CDN_FIRST (0U-601U)
#define CDN_LAST (0U-699U)
#define CDN_INITDONE (CDN_FIRST - 0x0000)
#define CDN_SELCHANGE (CDN_FIRST - 0x0001)
#define CDN_FOLDERCHANGE (CDN_FIRST - 0x0002)
#define CDN_SHAREVIOLATION (CDN_FIRST - 0x0003)
#define CDN_HELP (CDN_FIRST - 0x0004)
#define CDN_FILEOK (CDN_FIRST - 0x0005)
#define CDN_TYPECHANGE (CDN_FIRST - 0x0006)
#define CDN_INCLUDEITEM (CDN_FIRST - 0x0007)
#define CDM_FIRST (WM_USER + 100)
#define CDM_LAST (WM_USER + 200)
#define CDM_GETSPEC (CDM_FIRST + 0x0000)
#define CommDlg_OpenSave_GetSpecA(_hdlg,_psz,_cbmax)(int)SNDMSG(_hdlg,CDM_GETSPEC,(WPARAM)_cbmax,(LPARAM)(LPSTR)_psz)
#define CommDlg_OpenSave_GetSpecW(_hdlg,_psz,_cbmax)(int)SNDMSG(_hdlg,CDM_GETSPEC,(WPARAM)_cbmax,(LPARAM)(LPWSTR)_psz)
#ifdef UNICODE
#define CommDlg_OpenSave_GetSpec CommDlg_OpenSave_GetSpecW
#else
#define CommDlg_OpenSave_GetSpec CommDlg_OpenSave_GetSpecA
#endif 
#define CDM_GETFILEPATH (CDM_FIRST + 0x0001)
#define CommDlg_OpenSave_GetFilePathA(_hdlg,_psz,_cbmax)(int)SNDMSG(_hdlg,CDM_GETFILEPATH,(WPARAM)_cbmax,(LPARAM)(LPSTR)_psz)
#define CommDlg_OpenSave_GetFilePathW(_hdlg,_psz,_cbmax)(int)SNDMSG(_hdlg,CDM_GETFILEPATH,(WPARAM)_cbmax,(LPARAM)(LPWSTR)_psz)
#ifdef UNICODE
#define CommDlg_OpenSave_GetFilePath CommDlg_OpenSave_GetFilePathW
#else
#define CommDlg_OpenSave_GetFilePath CommDlg_OpenSave_GetFilePathA
#endif 
#define CDM_GETFOLDERPATH (CDM_FIRST + 0x0002)
#define CommDlg_OpenSave_GetFolderPathA(_hdlg,_psz,_cbmax)(int)SNDMSG(_hdlg,CDM_GETFOLDERPATH,(WPARAM)_cbmax,(LPARAM)(LPSTR)_psz)
#define CommDlg_OpenSave_GetFolderPathW(_hdlg,_psz,_cbmax)(int)SNDMSG(_hdlg,CDM_GETFOLDERPATH,(WPARAM)_cbmax,(LPARAM)(LPWSTR)_psz)
#ifdef UNICODE
#define CommDlg_OpenSave_GetFolderPath CommDlg_OpenSave_GetFolderPathW
#else
#define CommDlg_OpenSave_GetFolderPath CommDlg_OpenSave_GetFolderPathA
#endif 
#define CDM_GETFOLDERIDLIST (CDM_FIRST + 0x0003)
#define CommDlg_OpenSave_GetFolderIDList(_hdlg,_pidl,_cbmax)(int)SNDMSG(_hdlg,CDM_GETFOLDERIDLIST,(WPARAM)_cbmax,(LPARAM)(LPVOID)_pidl)
#define CDM_SETCONTROLTEXT (CDM_FIRST + 0x0004)
#define CommDlg_OpenSave_SetControlText(_hdlg,_id,_text)(void)SNDMSG(_hdlg,CDM_SETCONTROLTEXT,(WPARAM)_id,(LPARAM)(LPSTR)_text)
#define CDM_HIDECONTROL (CDM_FIRST + 0x0005)
#define CommDlg_OpenSave_HideControl(_hdlg,_id)(void)SNDMSG(_hdlg,CDM_HIDECONTROL,(WPARAM)_id,0)
#define CDM_SETDEFEXT (CDM_FIRST + 0x0006)
#define CommDlg_OpenSave_SetDefExt(_hdlg,_pszext)(void)SNDMSG(_hdlg,CDM_SETDEFEXT,0,(LPARAM)(LPSTR)_pszext)
#endif 
#ifndef _MAC
typedef struct tagCHOOSECOLORA {
 DWORD lStructSize;
 HWND hwndOwner;
 HWND hInstance;
 COLORREF rgbResult;
 COLORREF* lpCustColors;
 DWORD Flags;
 LPARAM lCustData;
 LPCCHOOKPROC lpfnHook;
 LPCSTR lpTemplateName;
} CHOOSECOLORA,*LPCHOOSECOLORA;
typedef struct tagCHOOSECOLORW {
 DWORD lStructSize;
 HWND hwndOwner;
 HWND hInstance;
 COLORREF rgbResult;
 COLORREF* lpCustColors;
 DWORD Flags;
 LPARAM lCustData;
 LPCCHOOKPROC lpfnHook;
 LPCWSTR lpTemplateName;
} CHOOSECOLORW,*LPCHOOSECOLORW;
#ifdef UNICODE
typedef CHOOSECOLORW CHOOSECOLOR;
typedef LPCHOOSECOLORW LPCHOOSECOLOR;
#else
typedef CHOOSECOLORA CHOOSECOLOR;
typedef LPCHOOSECOLORA LPCHOOSECOLOR;
#endif 
#else
typedef struct tagCHOOSECOLORA {
 DWORD lStructSize;
 HWND hwndOwner;
 HWND hInstance;
 COLORREF rgbResult;
 COLORREF* lpCustColors;
 DWORD Flags;
 LPARAM lCustData;
 LPCCHOOKPROC lpfnHook;
 LPCSTR lpTemplateName;
 LPEDITMENU lpEditInfo;
} CHOOSECOLORA,*LPCHOOSECOLORA;
typedef struct tagCHOOSECOLORW {
 DWORD lStructSize;
 HWND hwndOwner;
 HWND hInstance;
 COLORREF rgbResult;
 COLORREF* lpCustColors;
 DWORD Flags;
 LPARAM lCustData;
 LPCCHOOKPROC lpfnHook;
 LPCWSTR lpTemplateName;
 LPEDITMENU lpEditInfo;
} CHOOSECOLORW,*LPCHOOSECOLORW;
#ifdef UNICODE
typedef CHOOSECOLORW CHOOSECOLOR;
typedef LPCHOOSECOLORW LPCHOOSECOLOR;
#else
typedef CHOOSECOLORA CHOOSECOLOR;
typedef LPCHOOSECOLORA LPCHOOSECOLOR;
#endif 
#endif 
WINCOMMDLGAPI BOOL APIENTRY ChooseColorA(LPCHOOSECOLORA);
WINCOMMDLGAPI BOOL APIENTRY ChooseColorW(LPCHOOSECOLORW);
#ifdef UNICODE
#define ChooseColor ChooseColorW
#else
#define ChooseColor ChooseColorA
#endif 
#define CC_RGBINIT 1
#define CC_FULLOPEN 2
#define CC_PREVENTFULLOPEN 4
#define CC_SHOWHELP 8
#define CC_ENABLEHOOK 16
#define CC_ENABLETEMPLATE 32
#define CC_ENABLETEMPLATEHANDLE 64
#if(WINVER >=0x0400)
#define CC_SOLIDCOLOR 128
#define CC_ANYCOLOR 256
#endif 
typedef UINT_PTR (CALLBACK *LPFRHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef struct tagFINDREPLACEA {
 DWORD lStructSize; 
 HWND hwndOwner; 
 HINSTANCE hInstance; 
 DWORD Flags; 
 LPSTR lpstrFindWhat; 
 LPSTR lpstrReplaceWith; 
 WORD wFindWhatLen; 
 WORD wReplaceWithLen; 
 LPARAM lCustData; 
 LPFRHOOKPROC lpfnHook; 
 LPCSTR lpTemplateName; 
} FINDREPLACEA,*LPFINDREPLACEA;
typedef struct tagFINDREPLACEW {
 DWORD lStructSize; 
 HWND hwndOwner; 
 HINSTANCE hInstance; 
 DWORD Flags; 
 LPWSTR lpstrFindWhat; 
 LPWSTR lpstrReplaceWith; 
 WORD wFindWhatLen; 
 WORD wReplaceWithLen; 
 LPARAM lCustData; 
 LPFRHOOKPROC lpfnHook; 
 LPCWSTR lpTemplateName; 
} FINDREPLACEW,*LPFINDREPLACEW;
#ifdef UNICODE
typedef FINDREPLACEW FINDREPLACE;
typedef LPFINDREPLACEW LPFINDREPLACE;
#else
typedef FINDREPLACEA FINDREPLACE;
typedef LPFINDREPLACEA LPFINDREPLACE;
#endif 
#define FR_DOWN 1
#define FR_WHOLEWORD 2
#define FR_MATCHCASE 4
#define FR_FINDNEXT 8
#define FR_REPLACE 16
#define FR_REPLACEALL 32
#define FR_DIALOGTERM 64
#define FR_SHOWHELP 128
#define FR_ENABLEHOOK 256
#define FR_ENABLETEMPLATE 512
#define FR_NOUPDOWN 1024
#define FR_NOMATCHCASE 2048
#define FR_NOWHOLEWORD 0x1000
#define FR_ENABLETEMPLATEHANDLE 0x2000
#define FR_HIDEUPDOWN 0x4000
#define FR_HIDEMATCHCASE 0x8000
#define FR_HIDEWHOLEWORD 0x10000
#define FR_RAW 0x20000
#define FR_MATCHDIAC 0x20000000
#define FR_MATCHKASHIDA 0x40000000
#define FR_MATCHALEFHAMZA 0x80000000
WINCOMMDLGAPI HWND APIENTRY FindTextA(LPFINDREPLACEA);
WINCOMMDLGAPI HWND APIENTRY FindTextW(LPFINDREPLACEW);
#ifdef UNICODE
#define FindText FindTextW
#else
#define FindText FindTextA
#endif 
#ifndef _MAC
WINCOMMDLGAPI HWND APIENTRY ReplaceTextA(LPFINDREPLACEA);
WINCOMMDLGAPI HWND APIENTRY ReplaceTextW(LPFINDREPLACEW);
#ifdef UNICODE
#define ReplaceText ReplaceTextW
#else
#define ReplaceText ReplaceTextA
#endif 
#else
WINCOMMDLGAPI HWND APIENTRY AfxReplaceTextA(LPFINDREPLACEA);
WINCOMMDLGAPI HWND APIENTRY AfxReplaceTextW(LPFINDREPLACEW);
#ifdef UNICODE
#define AfxReplaceText AfxReplaceTextW
#else
#define AfxReplaceText AfxReplaceTextA
#endif 
#endif
typedef UINT_PTR (CALLBACK *LPCFHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef struct tagCHOOSEFONTA {
 DWORD lStructSize;
 HWND hwndOwner; 
 HDC hDC; 
 LPLOGFONTA lpLogFont; 
 INT iPointSize; 
 DWORD Flags; 
 COLORREF rgbColors; 
 LPARAM lCustData; 
 LPCFHOOKPROC lpfnHook; 
 LPCSTR lpTemplateName; 
 HINSTANCE hInstance; 
 LPSTR lpszStyle; 
 WORD nFontType; 
 WORD ___MISSING_ALIGNMENT__;
 INT nSizeMin; 
 INT nSizeMax; 
} CHOOSEFONTA,*LPCHOOSEFONTA;
typedef struct tagCHOOSEFONTW {
 DWORD lStructSize;
 HWND hwndOwner; 
 HDC hDC; 
 LPLOGFONTW lpLogFont; 
 INT iPointSize; 
 DWORD Flags; 
 COLORREF rgbColors; 
 LPARAM lCustData; 
 LPCFHOOKPROC lpfnHook; 
 LPCWSTR lpTemplateName; 
 HINSTANCE hInstance; 
 LPWSTR lpszStyle; 
 WORD nFontType; 
 WORD ___MISSING_ALIGNMENT__;
 INT nSizeMin; 
 INT nSizeMax; 
} CHOOSEFONTW,*LPCHOOSEFONTW;
#ifdef UNICODE
typedef CHOOSEFONTW CHOOSEFONT;
typedef LPCHOOSEFONTW LPCHOOSEFONT;
#else
typedef CHOOSEFONTA CHOOSEFONT;
typedef LPCHOOSEFONTA LPCHOOSEFONT;
#endif 
WINCOMMDLGAPI BOOL APIENTRY ChooseFontA(LPCHOOSEFONTA);
WINCOMMDLGAPI BOOL APIENTRY ChooseFontW(LPCHOOSEFONTW);
#ifdef UNICODE
#define ChooseFont ChooseFontW
#else
#define ChooseFont ChooseFontA
#endif 
#define CF_SCREENFONTS 1
#define CF_PRINTERFONTS 2
#define CF_BOTH (CF_SCREENFONTS|CF_PRINTERFONTS)
#define CF_SHOWHELP 4
#define CF_ENABLEHOOK 8
#define CF_ENABLETEMPLATE 16
#define CF_ENABLETEMPLATEHANDLE 32
#define CF_INITTOLOGFONTSTRUCT 64
#define CF_USESTYLE 128
#define CF_EFFECTS 256
#define CF_APPLY 512
#define CF_ANSIONLY 1024
#if(WINVER >=0x0400)
#define CF_SCRIPTSONLY CF_ANSIONLY
#endif 
#define CF_NOVECTORFONTS 2048
#define CF_NOOEMFONTS CF_NOVECTORFONTS
#define CF_NOSIMULATIONS 0x1000
#define CF_LIMITSIZE 0x2000
#define CF_FIXEDPITCHONLY 0x4000
#define CF_WYSIWYG 0x8000 
#define CF_FORCEFONTEXIST 0x10000
#define CF_SCALABLEONLY 0x20000
#define CF_TTONLY 0x40000
#define CF_NOFACESEL 0x80000
#define CF_NOSTYLESEL 0x100000
#define CF_NOSIZESEL 0x200000
#if(WINVER >=0x0400)
#define CF_SELECTSCRIPT 0x400000
#define CF_NOSCRIPTSEL 0x800000
#define CF_NOVERTFONTS 0x1000000
#endif 
#define SIMULATED_FONTTYPE 0x8000
#define PRINTER_FONTTYPE 0x4000
#define SCREEN_FONTTYPE 0x2000
#define BOLD_FONTTYPE 256
#define ITALIC_FONTTYPE 512
#define REGULAR_FONTTYPE 1024
#ifdef WINNT
#define PS_OPENTYPE_FONTTYPE 0x10000
#define TT_OPENTYPE_FONTTYPE 0x20000
#define TYPE1_FONTTYPE 0x40000
#endif
#define WM_CHOOSEFONT_GETLOGFONT (WM_USER + 1)
#define WM_CHOOSEFONT_SETLOGFONT (WM_USER + 101)
#define WM_CHOOSEFONT_SETFLAGS (WM_USER + 102)
#define LBSELCHSTRINGA "commdlg_LBSelChangedNotify"
#define SHAREVISTRINGA "commdlg_ShareViolation"
#define FILEOKSTRINGA "commdlg_FileNameOK"
#define COLOROKSTRINGA "commdlg_ColorOK"
#define SETRGBSTRINGA "commdlg_SetRGBColor"
#define HELPMSGSTRINGA "commdlg_help"
#define FINDMSGSTRINGA "commdlg_FindReplace"
#define LBSELCHSTRINGW L"commdlg_LBSelChangedNotify"
#define SHAREVISTRINGW L"commdlg_ShareViolation"
#define FILEOKSTRINGW L"commdlg_FileNameOK"
#define COLOROKSTRINGW L"commdlg_ColorOK"
#define SETRGBSTRINGW L"commdlg_SetRGBColor"
#define HELPMSGSTRINGW L"commdlg_help"
#define FINDMSGSTRINGW L"commdlg_FindReplace"
#ifdef UNICODE
#define LBSELCHSTRING LBSELCHSTRINGW
#define SHAREVISTRING SHAREVISTRINGW
#define FILEOKSTRING FILEOKSTRINGW
#define COLOROKSTRING COLOROKSTRINGW
#define SETRGBSTRING SETRGBSTRINGW
#define HELPMSGSTRING HELPMSGSTRINGW
#define FINDMSGSTRING FINDMSGSTRINGW
#else
#define LBSELCHSTRING LBSELCHSTRINGA
#define SHAREVISTRING SHAREVISTRINGA
#define FILEOKSTRING FILEOKSTRINGA
#define COLOROKSTRING COLOROKSTRINGA
#define SETRGBSTRING SETRGBSTRINGA
#define HELPMSGSTRING HELPMSGSTRINGA
#define FINDMSGSTRING FINDMSGSTRINGA
#endif
#define CD_LBSELNOITEMS -1
#define CD_LBSELCHANGE 0
#define CD_LBSELSUB 1
#define CD_LBSELADD 2
typedef UINT_PTR (CALLBACK *LPPRINTHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef UINT_PTR (CALLBACK *LPSETUPHOOKPROC) (HWND,UINT,WPARAM,LPARAM);
typedef struct tagPDA {
 DWORD lStructSize;
 HWND hwndOwner;
 HGLOBAL hDevMode;
 HGLOBAL hDevNames;
 HDC hDC;
 DWORD Flags;
 WORD nFromPage;
 WORD nToPage;
 WORD nMinPage;
 WORD nMaxPage;
 WORD nCopies;
 HINSTANCE hInstance;
 LPARAM lCustData;
 LPPRINTHOOKPROC lpfnPrintHook;
 LPSETUPHOOKPROC lpfnSetupHook;
 LPCSTR lpPrintTemplateName;
 LPCSTR lpSetupTemplateName;
 HGLOBAL hPrintTemplate;
 HGLOBAL hSetupTemplate;
} PRINTDLGA,*LPPRINTDLGA;
typedef struct tagPDW {
 DWORD lStructSize;
 HWND hwndOwner;
 HGLOBAL hDevMode;
 HGLOBAL hDevNames;
 HDC hDC;
 DWORD Flags;
 WORD nFromPage;
 WORD nToPage;
 WORD nMinPage;
 WORD nMaxPage;
 WORD nCopies;
 HINSTANCE hInstance;
 LPARAM lCustData;
 LPPRINTHOOKPROC lpfnPrintHook;
 LPSETUPHOOKPROC lpfnSetupHook;
 LPCWSTR lpPrintTemplateName;
 LPCWSTR lpSetupTemplateName;
 HGLOBAL hPrintTemplate;
 HGLOBAL hSetupTemplate;
} PRINTDLGW,*LPPRINTDLGW;
#ifdef UNICODE
typedef PRINTDLGW PRINTDLG;
typedef LPPRINTDLGW LPPRINTDLG;
#else
typedef PRINTDLGA PRINTDLG;
typedef LPPRINTDLGA LPPRINTDLG;
#endif 
WINCOMMDLGAPI BOOL APIENTRY PrintDlgA(LPPRINTDLGA);
WINCOMMDLGAPI BOOL APIENTRY PrintDlgW(LPPRINTDLGW);
#ifdef UNICODE
#define PrintDlg PrintDlgW
#else
#define PrintDlg PrintDlgA
#endif 
#if(WINVER >=0x0500)
#ifdef STDMETHOD
#undef INTERFACE
#define INTERFACE IPrintDialogCallback
DECLARE_INTERFACE_(IPrintDialogCallback,IUnknown) {
	STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *ppvObj) PURE;
	STDMETHOD_(ULONG,AddRef) (THIS) PURE;
	STDMETHOD_(ULONG,Release) (THIS) PURE;
	STDMETHOD(InitDone) (THIS) PURE;
	STDMETHOD(SelectionChange) (THIS) PURE;
	STDMETHOD(HandleMessage) (THIS_ HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *pResult) PURE;
};
#undef INTERFACE
#define INTERFACE IPrintDialogServices
DECLARE_INTERFACE_(IPrintDialogServices,IUnknown) {
	STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *ppvObj) PURE;
	STDMETHOD_(ULONG,AddRef) (THIS) PURE;
	STDMETHOD_(ULONG,Release) (THIS) PURE;
	STDMETHOD(GetCurrentDevMode) (THIS_ LPDEVMODE pDevMode,UINT *pcbSize) PURE;
	STDMETHOD(GetCurrentPrinterName) (THIS_ LPTSTR pPrinterName,UINT *pcchSize) PURE;
	STDMETHOD(GetCurrentPortName) (THIS_ LPTSTR pPortName,UINT *pcchSize) PURE;
};
typedef struct tagPRINTPAGERANGE {
 DWORD nFromPage;
 DWORD nToPage;
} PRINTPAGERANGE,*LPPRINTPAGERANGE;
typedef struct tagPDEXA {
 DWORD lStructSize; 
 HWND hwndOwner; 
 HGLOBAL hDevMode; 
 HGLOBAL hDevNames; 
 HDC hDC; 
 DWORD Flags; 
 DWORD Flags2; 
 DWORD ExclusionFlags; 
 DWORD nPageRanges; 
 DWORD nMaxPageRanges; 
 LPPRINTPAGERANGE lpPageRanges; 
 DWORD nMinPage; 
 DWORD nMaxPage; 
 DWORD nCopies; 
 HINSTANCE hInstance; 
 LPCSTR lpPrintTemplateName; 
 LPUNKNOWN lpCallback; 
 DWORD nPropertyPages; 
 HPROPSHEETPAGE *lphPropertyPages; 
 DWORD nStartPage; 
 DWORD dwResultAction; 
} PRINTDLGEXA,*LPPRINTDLGEXA;
typedef struct tagPDEXW {
 DWORD lStructSize; 
 HWND hwndOwner; 
 HGLOBAL hDevMode; 
 HGLOBAL hDevNames; 
 HDC hDC; 
 DWORD Flags; 
 DWORD Flags2; 
 DWORD ExclusionFlags; 
 DWORD nPageRanges; 
 DWORD nMaxPageRanges; 
 LPPRINTPAGERANGE lpPageRanges; 
 DWORD nMinPage; 
 DWORD nMaxPage; 
 DWORD nCopies; 
 HINSTANCE hInstance; 
 LPCWSTR lpPrintTemplateName; 
 LPUNKNOWN lpCallback; 
 DWORD nPropertyPages; 
 HPROPSHEETPAGE *lphPropertyPages; 
 DWORD nStartPage; 
 DWORD dwResultAction; 
} PRINTDLGEXW,*LPPRINTDLGEXW;
#ifdef UNICODE
typedef PRINTDLGEXW PRINTDLGEX;
typedef LPPRINTDLGEXW LPPRINTDLGEX;
#else
typedef PRINTDLGEXA PRINTDLGEX;
typedef LPPRINTDLGEXA LPPRINTDLGEX;
#endif 
WINCOMMDLGAPI HRESULT APIENTRY PrintDlgExA(LPPRINTDLGEXA);
WINCOMMDLGAPI HRESULT APIENTRY PrintDlgExW(LPPRINTDLGEXW);
#ifdef UNICODE
#define PrintDlgEx PrintDlgExW
#else
#define PrintDlgEx PrintDlgExA
#endif 
#endif
#endif 
#define PD_ALLPAGES 0
#define PD_SELECTION 1
#define PD_PAGENUMS 2
#define PD_NOSELECTION 4
#define PD_NOPAGENUMS 8
#define PD_COLLATE 16
#define PD_PRINTTOFILE 32
#define PD_PRINTSETUP 64
#define PD_NOWARNING 128
#define PD_RETURNDC 256
#define PD_RETURNIC 512
#define PD_RETURNDEFAULT 1024
#define PD_SHOWHELP 2048
#define PD_ENABLEPRINTHOOK 0x1000
#define PD_ENABLESETUPHOOK 0x2000
#define PD_ENABLEPRINTTEMPLATE 0x4000
#define PD_ENABLESETUPTEMPLATE 0x8000
#define PD_ENABLEPRINTTEMPLATEHANDLE 0x10000
#define PD_ENABLESETUPTEMPLATEHANDLE 0x20000
#define PD_USEDEVMODECOPIES 0x40000
#define PD_USEDEVMODECOPIESANDCOLLATE 0x40000
#define PD_DISABLEPRINTTOFILE 0x80000
#define PD_HIDEPRINTTOFILE 0x100000
#define PD_NONETWORKBUTTON 0x200000
#if(WINVER >=0x0500)
#define PD_CURRENTPAGE 0x400000
#define PD_NOCURRENTPAGE 0x800000
#define PD_EXCLUSIONFLAGS 0x1000000
#define PD_USELARGETEMPLATE 0x10000000
#endif 
#if(WINVER >=0x0500)
#define PD_EXCL_COPIESANDCOLLATE (DM_COPIES|DM_COLLATE)
#define START_PAGE_GENERAL 0xffffffff
#define PD_RESULT_CANCEL 0
#define PD_RESULT_PRINT 1
#define PD_RESULT_APPLY 2
#endif 
typedef struct tagDEVNAMES {
 WORD wDriverOffset;
 WORD wDeviceOffset;
 WORD wOutputOffset;
 WORD wDefault;
} DEVNAMES,*LPDEVNAMES;
#define DN_DEFAULTPRN 1
WINCOMMDLGAPI DWORD APIENTRY CommDlgExtendedError(VOID);
#if(WINVER >=0x0400)
#define WM_PSD_PAGESETUPDLG (WM_USER)
#define WM_PSD_FULLPAGERECT (WM_USER+1)
#define WM_PSD_MINMARGINRECT (WM_USER+2)
#define WM_PSD_MARGINRECT (WM_USER+3)
#define WM_PSD_GREEKTEXTRECT (WM_USER+4)
#define WM_PSD_ENVSTAMPRECT (WM_USER+5)
#define WM_PSD_YAFULLPAGERECT (WM_USER+6)
typedef UINT_PTR (CALLBACK* LPPAGEPAINTHOOK)(HWND,UINT,WPARAM,LPARAM );
typedef UINT_PTR (CALLBACK* LPPAGESETUPHOOK)(HWND,UINT,WPARAM,LPARAM );
typedef struct tagPSDA {
	DWORD lStructSize;
	HWND hwndOwner;
	HGLOBAL hDevMode;
	HGLOBAL hDevNames;
	DWORD Flags;
	POINT ptPaperSize;
	RECT rtMinMargin;
	RECT rtMargin;
	HINSTANCE hInstance;
	LPARAM lCustData;
	LPPAGESETUPHOOK lpfnPageSetupHook;
	LPPAGEPAINTHOOK lpfnPagePaintHook;
	LPCSTR lpPageSetupTemplateName;
	HGLOBAL hPageSetupTemplate;
} PAGESETUPDLGA,* LPPAGESETUPDLGA;
typedef struct tagPSDW {
	DWORD lStructSize;
	HWND hwndOwner;
	HGLOBAL hDevMode;
	HGLOBAL hDevNames;
	DWORD Flags;
	POINT ptPaperSize;
	RECT rtMinMargin;
	RECT rtMargin;
	HINSTANCE hInstance;
	LPARAM lCustData;
	LPPAGESETUPHOOK lpfnPageSetupHook;
	LPPAGEPAINTHOOK lpfnPagePaintHook;
	LPCWSTR lpPageSetupTemplateName;
	HGLOBAL hPageSetupTemplate;
} PAGESETUPDLGW,* LPPAGESETUPDLGW;
#ifdef UNICODE
typedef PAGESETUPDLGW PAGESETUPDLG;
typedef LPPAGESETUPDLGW LPPAGESETUPDLG;
#else
typedef PAGESETUPDLGA PAGESETUPDLG;
typedef LPPAGESETUPDLGA LPPAGESETUPDLG;
#endif 
WINCOMMDLGAPI BOOL APIENTRY PageSetupDlgA(LPPAGESETUPDLGA );
WINCOMMDLGAPI BOOL APIENTRY PageSetupDlgW(LPPAGESETUPDLGW );
#ifdef UNICODE
#define PageSetupDlg PageSetupDlgW
#else
#define PageSetupDlg PageSetupDlgA
#endif 
#define PSD_DEFAULTMINMARGINS 0 
#define PSD_INWININIINTLMEASURE 0 
#define PSD_MINMARGINS 1 
#define PSD_MARGINS 2 
#define PSD_INTHOUSANDTHSOFINCHES 4 
#define PSD_INHUNDREDTHSOFMILLIMETERS 8 
#define PSD_DISABLEMARGINS 16
#define PSD_DISABLEPRINTER 32
#define PSD_NOWARNING 128 
#define PSD_DISABLEORIENTATION 256
#define PSD_RETURNDEFAULT 1024 
#define PSD_DISABLEPAPER 512
#define PSD_SHOWHELP 2048 
#define PSD_ENABLEPAGESETUPHOOK 0x2000 
#define PSD_ENABLEPAGESETUPTEMPLATE 0x8000 
#define PSD_ENABLEPAGESETUPTEMPLATEHANDLE 0x20000 
#define PSD_ENABLEPAGEPAINTHOOK 0x40000
#define PSD_DISABLEPAGEPAINTING 0x80000
#define PSD_NONETWORKBUTTON 0x200000 
#endif 
#if !defined(RC_INVOKED) 
#if defined(ISOLATION_AWARE_ENABLED) && (ISOLATION_AWARE_ENABLED !=0)
#if !defined(ISOLATION_AWARE_USE_STATIC_LIBRARY)
#define ISOLATION_AWARE_USE_STATIC_LIBRARY 0
#endif
#if !defined(ISOLATION_AWARE_BUILD_STATIC_LIBRARY)
#define ISOLATION_AWARE_BUILD_STATIC_LIBRARY 0
#endif
#if !defined(ISOLATION_AWARE_INLINE)
#if ISOLATION_AWARE_BUILD_STATIC_LIBRARY
#define ISOLATION_AWARE_INLINE 
#else
#if defined(__cplusplus)
#define ISOLATION_AWARE_INLINE inline
#else
#define ISOLATION_AWARE_INLINE __inline
#endif
#endif
#endif
#if !ISOLATION_AWARE_USE_STATIC_LIBRARY
FARPROC WINAPI CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY(LPCSTR pszProcName);
#endif 
BOOL WINAPI IsolationAwareGetOpenFileNameA(LPOPENFILENAMEA unnamed1);
BOOL WINAPI IsolationAwareGetOpenFileNameW(LPOPENFILENAMEW unnamed1);
BOOL WINAPI IsolationAwareGetSaveFileNameA(LPOPENFILENAMEA unnamed1);
BOOL WINAPI IsolationAwareGetSaveFileNameW(LPOPENFILENAMEW unnamed1);
short WINAPI IsolationAwareGetFileTitleA(LPCSTR unnamed1,LPSTR unnamed2,WORD unnamed3);
short WINAPI IsolationAwareGetFileTitleW(LPCWSTR unnamed1,LPWSTR unnamed2,WORD unnamed3);
BOOL WINAPI IsolationAwareChooseColorA(LPCHOOSECOLORA unnamed1);
BOOL WINAPI IsolationAwareChooseColorW(LPCHOOSECOLORW unnamed1);
HWND WINAPI IsolationAwareFindTextA(LPFINDREPLACEA unnamed1);
HWND WINAPI IsolationAwareFindTextW(LPFINDREPLACEW unnamed1);
HWND WINAPI IsolationAwareReplaceTextA(LPFINDREPLACEA unnamed1);
HWND WINAPI IsolationAwareReplaceTextW(LPFINDREPLACEW unnamed1);
BOOL WINAPI IsolationAwareChooseFontA(LPCHOOSEFONTA unnamed1);
BOOL WINAPI IsolationAwareChooseFontW(LPCHOOSEFONTW unnamed1);
BOOL WINAPI IsolationAwarePrintDlgA(LPPRINTDLGA unnamed1);
BOOL WINAPI IsolationAwarePrintDlgW(LPPRINTDLGW unnamed1);
#if defined(STDMETHOD) && (WINVER >=0x0500)
HRESULT WINAPI IsolationAwarePrintDlgExA(LPPRINTDLGEXA unnamed1);
HRESULT WINAPI IsolationAwarePrintDlgExW(LPPRINTDLGEXW unnamed1);
#endif 
DWORD WINAPI IsolationAwareCommDlgExtendedError(void);
BOOL WINAPI IsolationAwarePageSetupDlgA(LPPAGESETUPDLGA unnamed1);
BOOL WINAPI IsolationAwarePageSetupDlgW(LPPAGESETUPDLGW unnamed1);
ISOLATION_AWARE_INLINE HRESULT CommdlgIsolationAwarePrivateJVaQPGbueRfhYg(void) {
	DWORD dwLastError=GetLastError();
	if (dwLastError==NO_ERROR)
		dwLastError=ERROR_INTERNAL_ERROR;
	return HRESULT_FROM_WIN32(dwLastError);
}
#if defined(UNICODE)
#define IsolationAwareChooseColor IsolationAwareChooseColorW
#define IsolationAwareChooseFont IsolationAwareChooseFontW
#define IsolationAwareFindText IsolationAwareFindTextW
#define IsolationAwareGetFileTitle IsolationAwareGetFileTitleW
#define IsolationAwareGetOpenFileName IsolationAwareGetOpenFileNameW
#define IsolationAwareGetSaveFileName IsolationAwareGetSaveFileNameW
#define IsolationAwarePageSetupDlg IsolationAwarePageSetupDlgW
#define IsolationAwarePrintDlg IsolationAwarePrintDlgW
#define IsolationAwarePrintDlgEx IsolationAwarePrintDlgExW
#define IsolationAwareReplaceText IsolationAwareReplaceTextW
#else 
#define IsolationAwareChooseColor IsolationAwareChooseColorA
#define IsolationAwareChooseFont IsolationAwareChooseFontA
#define IsolationAwareFindText IsolationAwareFindTextA
#define IsolationAwareGetFileTitle IsolationAwareGetFileTitleA
#define IsolationAwareGetOpenFileName IsolationAwareGetOpenFileNameA
#define IsolationAwareGetSaveFileName IsolationAwareGetSaveFileNameA
#define IsolationAwarePageSetupDlg IsolationAwarePageSetupDlgA
#define IsolationAwarePrintDlg IsolationAwarePrintDlgA
#define IsolationAwarePrintDlgEx IsolationAwarePrintDlgExA
#define IsolationAwareReplaceText IsolationAwareReplaceTextA
#endif 
#if !ISOLATION_AWARE_USE_STATIC_LIBRARY
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareGetOpenFileNameA(LPOPENFILENAMEA unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPOPENFILENAMEA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("GetOpenFileNameA");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareGetOpenFileNameW(LPOPENFILENAMEW unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPOPENFILENAMEW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("GetOpenFileNameW");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareGetSaveFileNameA(LPOPENFILENAMEA unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPOPENFILENAMEA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("GetSaveFileNameA");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareGetSaveFileNameW(LPOPENFILENAMEW unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPOPENFILENAMEW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("GetSaveFileNameW");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE short WINAPI IsolationAwareGetFileTitleA(LPCSTR unnamed1,LPSTR unnamed2,WORD unnamed3) {
	short nResult=-1;
	typedef short (WINAPI* PFN)(LPCSTR unnamed1,LPSTR unnamed2,WORD unnamed3);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return nResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("GetFileTitleA");
			if (s_pfn==NULL)
				__leave;
		}
		nResult=s_pfn(unnamed1,unnamed2,unnamed3);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(nResult==-1);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return nResult;
}
ISOLATION_AWARE_INLINE short WINAPI IsolationAwareGetFileTitleW(LPCWSTR unnamed1,LPWSTR unnamed2,WORD unnamed3) {
	short nResult=-1;
	typedef short (WINAPI* PFN)(LPCWSTR unnamed1,LPWSTR unnamed2,WORD unnamed3);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return nResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("GetFileTitleW");
			if (s_pfn==NULL)
				__leave;
		}
		nResult=s_pfn(unnamed1,unnamed2,unnamed3);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(nResult==-1);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return nResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareChooseColorA(LPCHOOSECOLORA unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPCHOOSECOLORA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("ChooseColorA");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareChooseColorW(LPCHOOSECOLORW unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPCHOOSECOLORW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("ChooseColorW");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE HWND WINAPI IsolationAwareFindTextA(LPFINDREPLACEA unnamed1) {
	HWND windowResult=NULL;
	typedef HWND (WINAPI* PFN)(LPFINDREPLACEA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return windowResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("FindTextA");
			if (s_pfn==NULL)
				__leave;
		}
		windowResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(windowResult==NULL);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return windowResult;
}
ISOLATION_AWARE_INLINE HWND WINAPI IsolationAwareFindTextW(LPFINDREPLACEW unnamed1) {
	HWND windowResult=NULL;
	typedef HWND (WINAPI* PFN)(LPFINDREPLACEW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return windowResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("FindTextW");
			if (s_pfn==NULL)
				__leave;
		}
		windowResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(windowResult==NULL);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return windowResult;
}
ISOLATION_AWARE_INLINE HWND WINAPI IsolationAwareReplaceTextA(LPFINDREPLACEA unnamed1) {
	HWND windowResult=NULL;
	typedef HWND (WINAPI* PFN)(LPFINDREPLACEA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return windowResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("ReplaceTextA");
			if (s_pfn==NULL)
				__leave;
		}
		windowResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(windowResult==NULL);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return windowResult;
}
ISOLATION_AWARE_INLINE HWND WINAPI IsolationAwareReplaceTextW(LPFINDREPLACEW unnamed1) {
	HWND windowResult=NULL;
	typedef HWND (WINAPI* PFN)(LPFINDREPLACEW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return windowResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("ReplaceTextW");
			if (s_pfn==NULL)
				__leave;
		}
		windowResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(windowResult==NULL);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return windowResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareChooseFontA(LPCHOOSEFONTA unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPCHOOSEFONTA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("ChooseFontA");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareChooseFontW(LPCHOOSEFONTW unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPCHOOSEFONTW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("ChooseFontW");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwarePrintDlgA(LPPRINTDLGA unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPPRINTDLGA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("PrintDlgA");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwarePrintDlgW(LPPRINTDLGW unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPPRINTDLGW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("PrintDlgW");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
#if defined(STDMETHOD) && (WINVER >=0x0500)
ISOLATION_AWARE_INLINE HRESULT WINAPI IsolationAwarePrintDlgExA(LPPRINTDLGEXA unnamed1) {
	HRESULT result=S_OK;
	typedef HRESULT (WINAPI* PFN)(LPPRINTDLGEXA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return CommdlgIsolationAwarePrivateJVaQPGbueRfhYg();
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("PrintDlgExA");
			if (s_pfn==NULL)
			{
				result=CommdlgIsolationAwarePrivateJVaQPGbueRfhYg();
				__leave;
			}
		}
		result=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
		}
	}
	return result;
}
ISOLATION_AWARE_INLINE HRESULT WINAPI IsolationAwarePrintDlgExW(LPPRINTDLGEXW unnamed1) {
	HRESULT result=S_OK;
	typedef HRESULT (WINAPI* PFN)(LPPRINTDLGEXW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return CommdlgIsolationAwarePrivateJVaQPGbueRfhYg();
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("PrintDlgExW");
			if (s_pfn==NULL)
			{
				result=CommdlgIsolationAwarePrivateJVaQPGbueRfhYg();
				__leave;
			}
		}
		result=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
		}
	}
	return result;
}
#endif 
ISOLATION_AWARE_INLINE DWORD WINAPI IsolationAwareCommDlgExtendedError(void) {
	DWORD nResult=0 ;
	typedef DWORD (WINAPI* PFN)(void);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return nResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("CommDlgExtendedError");
			if (s_pfn==NULL)
				__leave;
		}
		nResult=s_pfn();
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(nResult==0 );
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return nResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwarePageSetupDlgA(LPPAGESETUPDLGA unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPPAGESETUPDLGA unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("PageSetupDlgA");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwarePageSetupDlgW(LPPAGESETUPDLGW unnamed1) {
	BOOL fResult=FALSE;
	typedef BOOL (WINAPI* PFN)(LPPAGESETUPDLGW unnamed1);
	static PFN s_pfn;
	ULONG_PTR ulpCookie=0;
	const BOOL fActivateActCtxSuccess=IsolationAwarePrivateT_SqbjaYRiRY||IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
	if (!fActivateActCtxSuccess)
		return fResult;
__try 
	{
		if (s_pfn==NULL)
		{
			s_pfn=(PFN)CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY("PageSetupDlgW");
			if (s_pfn==NULL)
				__leave;
		}
		fResult=s_pfn(unnamed1);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			const BOOL fPreserveLastError=(fResult==FALSE);
			const DWORD dwLastError=fPreserveLastError ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (fPreserveLastError)
				SetLastError(dwLastError);
		}
	}
	return fResult;
}
ISOLATION_AWARE_INLINE FARPROC WINAPI CommdlgIsolationAwarePrivatetRgCebPnQQeRff_pbZQYTQP_QYY(LPCSTR pszProcName) {
	FARPROC proc=NULL;
	static HMODULE s_module;
	BOOL fActivateActCtxSuccess=FALSE;
	ULONG_PTR ulpCookie=0;
	const static IsolationAwarePrivatepBAFGnAG_zBqHyr_vAsB
		c={ IsolationAwarePrivatezlybNQyVOeNeln,IsolationAwarePrivatezlybNQyVOeNelJ,"Comdlg32.dll",L"Comdlg32.dll" };
	static IsolationAwarePrivatezHGnoyr_zBqHyr_vAsB m;
__try 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY)
		{
			fActivateActCtxSuccess=IsolationAwarePrivatenPgViNgRzlnPgpgk(&ulpCookie);
			if (!fActivateActCtxSuccess)
				__leave;
		}
		proc=IsolationAwarePrivatezltRgCebPnQQeRff(&c,&m,pszProcName);
	}
__finally 
	{
		if (!IsolationAwarePrivateT_SqbjaYRiRY && fActivateActCtxSuccess)
		{
			const DWORD dwLastError=(proc==NULL) ? GetLastError() : NO_ERROR;
			(void)IsolationAwareDeactivateActCtx(0,ulpCookie);
			if (proc==NULL)
				SetLastError(dwLastError);
		}
	}
	return proc;
}
#endif 
#define ChooseColorA IsolationAwareChooseColorA
#define ChooseColorW IsolationAwareChooseColorW
#define ChooseFontA IsolationAwareChooseFontA
#define ChooseFontW IsolationAwareChooseFontW
#define CommDlgExtendedError IsolationAwareCommDlgExtendedError
#define FindTextA IsolationAwareFindTextA
#define FindTextW IsolationAwareFindTextW
#define GetFileTitleA IsolationAwareGetFileTitleA
#define GetFileTitleW IsolationAwareGetFileTitleW
#define GetOpenFileNameA IsolationAwareGetOpenFileNameA
#define GetOpenFileNameW IsolationAwareGetOpenFileNameW
#define GetSaveFileNameA IsolationAwareGetSaveFileNameA
#define GetSaveFileNameW IsolationAwareGetSaveFileNameW
#define PageSetupDlgA IsolationAwarePageSetupDlgA
#define PageSetupDlgW IsolationAwarePageSetupDlgW
#define PrintDlgA IsolationAwarePrintDlgA
#define PrintDlgExA IsolationAwarePrintDlgExA
#define PrintDlgExW IsolationAwarePrintDlgExW
#define PrintDlgW IsolationAwarePrintDlgW
#define ReplaceTextA IsolationAwareReplaceTextA
#define ReplaceTextW IsolationAwareReplaceTextW
#endif 
#endif 
#if !defined(_WIN64)
#include <poppack.h>
#endif
#endif 
#endif 
