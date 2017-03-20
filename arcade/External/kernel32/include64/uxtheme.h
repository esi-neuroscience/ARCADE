#ifndef _UXTHEME_H_
#define _UXTHEME_H_
#include <commctrl.h>
#ifndef THEMEAPI
#if !defined(_UXTHEME_)
#define THEMEAPI EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define THEMEAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE
#else
#define THEMEAPI STDAPI
#define THEMEAPI_(type) STDAPI_(type)
#endif
#endif 
typedef HANDLE HTHEME; 
THEMEAPI_(HTHEME) OpenThemeData(HWND hwnd,LPCWSTR pszClassList);
THEMEAPI CloseThemeData(HTHEME hTheme);
THEMEAPI DrawThemeBackground(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pRect,const RECT *pClipRect);
#define DTT_GRAYED 1 
THEMEAPI DrawThemeText(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,LPCWSTR pszText,int iCharCount,DWORD dwTextFlags,DWORD dwTextFlags2,const RECT *pRect);
THEMEAPI GetThemeBackgroundContentRect(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pBoundingRect,RECT *pContentRect);
THEMEAPI GetThemeBackgroundExtent(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pContentRect,RECT *pExtentRect);
typedef enum THEMESIZE {
	TS_MIN,TS_TRUE,TS_DRAW,};
THEMEAPI GetThemePartSize(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,RECT *prc,enum THEMESIZE eSize,SIZE *psz);
THEMEAPI GetThemeTextExtent(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,LPCWSTR pszText,int iCharCount,DWORD dwTextFlags,const RECT *pBoundingRect,RECT *pExtentRect);
THEMEAPI GetThemeTextMetrics(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,TEXTMETRIC* ptm);
THEMEAPI GetThemeBackgroundRegion(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pRect,HRGN *pRegion);
#define HTTB_BACKGROUNDSEG 0 
#define HTTB_FIXEDBORDER 2 
#define HTTB_CAPTION 4 
#define HTTB_RESIZINGBORDER_LEFT 16 
#define HTTB_RESIZINGBORDER_TOP 32 
#define HTTB_RESIZINGBORDER_RIGHT 64 
#define HTTB_RESIZINGBORDER_BOTTOM 128 
#define HTTB_RESIZINGBORDER (HTTB_RESIZINGBORDER_LEFT|HTTB_RESIZINGBORDER_TOP|HTTB_RESIZINGBORDER_RIGHT|HTTB_RESIZINGBORDER_BOTTOM)
#define HTTB_SIZINGTEMPLATE 256
#define HTTB_SYSTEMSIZINGMARGINS 512
THEMEAPI HitTestThemeBackground(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,DWORD dwOptions,const RECT *pRect,HRGN hrgn,POINT ptTest,WORD *pwHitTestCode);
THEMEAPI DrawThemeEdge(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pDestRect,UINT uEdge,UINT uFlags,RECT *pContentRect);
THEMEAPI DrawThemeIcon(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pRect,HIMAGELIST himl,int iImageIndex);
THEMEAPI_(BOOL) IsThemePartDefined(HTHEME hTheme,int iPartId,int iStateId);
THEMEAPI_(BOOL) IsThemeBackgroundPartiallyTransparent(HTHEME hTheme,int iPartId,int iStateId);
THEMEAPI GetThemeColor(HTHEME hTheme,int iPartId,int iStateId,int iPropId,COLORREF *pColor);
THEMEAPI GetThemeMetric(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,int iPropId,int *piVal);
THEMEAPI GetThemeString(HTHEME hTheme,int iPartId,int iStateId,int iPropId,LPWSTR pszBuff,int cchMaxBuffChars);
THEMEAPI GetThemeBool(HTHEME hTheme,int iPartId,int iStateId,int iPropId,BOOL *pfVal);
THEMEAPI GetThemeInt(HTHEME hTheme,int iPartId,int iStateId,int iPropId,int *piVal);
THEMEAPI GetThemeEnumValue(HTHEME hTheme,int iPartId,int iStateId,int iPropId,int *piVal);
THEMEAPI GetThemePosition(HTHEME hTheme,int iPartId,int iStateId,int iPropId,POINT *pPoint);
THEMEAPI GetThemeFont(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,int iPropId,LOGFONT *pFont);
THEMEAPI GetThemeRect(HTHEME hTheme,int iPartId,int iStateId,int iPropId,RECT *pRect);
typedef struct _MARGINS {
	int cxLeftWidth; 
	int cxRightWidth; 
	int cyTopHeight; 
	int cyBottomHeight; 
} MARGINS,*PMARGINS;
THEMEAPI GetThemeMargins(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,int iPropId,RECT *prc,MARGINS *pMargins);
#define MAX_INTLIST_COUNT 10
typedef struct _INTLIST {
	int iValueCount; 
	int iValues[MAX_INTLIST_COUNT];
} INTLIST,*PINTLIST;
THEMEAPI GetThemeIntList(HTHEME hTheme,int iPartId,int iStateId,int iPropId,INTLIST *pIntList);
typedef enum PROPERTYORIGIN {
	PO_STATE,PO_PART,PO_CLASS,PO_GLOBAL,PO_NOTFOUND 
};
THEMEAPI GetThemePropertyOrigin(HTHEME hTheme,int iPartId,int iStateId,int iPropId,enum PROPERTYORIGIN *pOrigin);
THEMEAPI SetWindowTheme(HWND hwnd,LPCWSTR pszSubAppName,LPCWSTR pszSubIdList);
THEMEAPI GetThemeFilename(HTHEME hTheme,int iPartId,int iStateId,int iPropId,LPWSTR pszThemeFileName,int cchMaxBuffChars);
THEMEAPI_(COLORREF) GetThemeSysColor(HTHEME hTheme,int iColorId);
THEMEAPI_(HBRUSH) GetThemeSysColorBrush(HTHEME hTheme,int iColorId);
THEMEAPI_(BOOL) GetThemeSysBool(HTHEME hTheme,int iBoolId);
THEMEAPI_(int) GetThemeSysSize(HTHEME hTheme,int iSizeId);
THEMEAPI GetThemeSysFont(HTHEME hTheme,int iFontId,LOGFONT *plf);
THEMEAPI GetThemeSysString(HTHEME hTheme,int iStringId,LPWSTR pszStringBuff,int cchMaxStringChars);
THEMEAPI GetThemeSysInt(HTHEME hTheme,int iIntId,int *piValue);
THEMEAPI_(BOOL) IsThemeActive();
THEMEAPI_(BOOL) IsAppThemed();
THEMEAPI_(HTHEME) GetWindowTheme(HWND hwnd);
#define ETDT_DISABLE 1
#define ETDT_ENABLE 2
#define ETDT_USETABTEXTURE 4
#define ETDT_ENABLETAB (ETDT_ENABLE|ETDT_USETABTEXTURE)
THEMEAPI EnableThemeDialogTexture(HWND hwnd,DWORD dwFlags);
THEMEAPI_(BOOL) IsThemeDialogTextureEnabled(HWND hwnd);
#define STAP_ALLOW_NONCLIENT (1 << 0)
#define STAP_ALLOW_CONTROLS (1 << 1)
#define STAP_ALLOW_WEBCONTENT (1 << 2)
THEMEAPI_(DWORD) GetThemeAppProperties();
THEMEAPI_(void) SetThemeAppProperties(DWORD dwFlags);
THEMEAPI GetCurrentThemeName(LPWSTR pszThemeFileName,int cchMaxNameChars,LPWSTR pszColorBuff,int cchMaxColorChars,LPWSTR pszSizeBuff,int cchMaxSizeChars);
#define SZ_THDOCPROP_DISPLAYNAME L"DisplayName"
#define SZ_THDOCPROP_CANONICALNAME L"ThemeName"
#define SZ_THDOCPROP_TOOLTIP L"ToolTip"
#define SZ_THDOCPROP_AUTHOR L"author"
THEMEAPI GetThemeDocumentationProperty(LPCWSTR pszThemeName,LPCWSTR pszPropertyName,LPWSTR pszValueBuff,int cchMaxValChars);
THEMEAPI DrawThemeParentBackground(HWND hwnd,HDC hdc,RECT* prc);
THEMEAPI EnableTheming(BOOL fEnable);
#define DTBG_CLIPRECT 1 
#define DTBG_DRAWSOLID 2 
#define DTBG_OMITBORDER 4 
#define DTBG_OMITCONTENT 8 
#define DTBG_COMPUTINGREGION 16 
#define DTBG_MIRRORDC 32 
typedef struct _DTBGOPTS {
	DWORD dwSize; 
	DWORD dwFlags; 
	RECT rcClip; 
}
DTBGOPTS,*PDTBGOPTS;
THEMEAPI DrawThemeBackgroundEx(HTHEME hTheme,HDC hdc,int iPartId,int iStateId,const RECT *pRect,const DTBGOPTS *pOptions);
#endif 
