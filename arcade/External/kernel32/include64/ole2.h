#if !defined(_OLE2_H_ )
#define _OLE2_H_
#pragma once
#ifndef _MAC
#include <pshpack8.h>
#ifndef WIN32
#define WIN32 100 
#endif
#else 
#ifdef _WIN32
#include "macname1.h"
#endif 
#endif 
#include <winerror.h>
#ifdef _MAC
#if !defined(__MACPUB__)
#include <macpub.h>
#endif
#endif 
#include <objbase.h>
#include <oleauto.h>
#define E_DRAW VIEW_E_DRAW
#define DATA_E_FORMATETC DV_E_FORMATETC
#ifdef _MAC
typedef enum {
	OLE_E_NOEXTENSION	=OLE_E_NOSTORAGE +1,	
	OLE_E_VERSEXTENSION,						
	OLE_E_IPBUSY,								
	OLE_E_NOT_FRONT_PROCESS,					
	OLE_E_WRONG_MENU,							
	OLE_E_MENU_NOT_PATCHED,						
	OLE_E_MENUID_NOT_HASHED,					
OLE_E_foo 
} inplace_errors;
typedef struct tagDRAG_FLAVORINFO {
	unsigned long	cfFormat;
	unsigned long	FlavorFlags;		
	OLEBOOL			fAddData;			
	long			reserved;			
} DRAG_FLAVORINFO;
#endif 
#define OLEIVERB_PRIMARY (0L)
#define OLEIVERB_SHOW (-1L)
#define OLEIVERB_OPEN (-2L)
#define OLEIVERB_HIDE (-3L)
#define OLEIVERB_UIACTIVATE (-4L)
#define OLEIVERB_INPLACEACTIVATE (-5L)
#define OLEIVERB_DISCARDUNDOSTATE (-6L)
#define EMBDHLP_INPROC_HANDLER 0
#define EMBDHLP_INPROC_SERVER 1
#define EMBDHLP_CREATENOW 0
#define EMBDHLP_DELAYCREATE 0x10000
#define OLECREATE_LEAVERUNNING	1
#include <oleidl.h>
#ifdef _MAC
typedef struct tagOleMBarRec {
		long reserved;
} OleMBarRec,*OleMBarPtr,**OleMBarHandle;
#define noAxis 3 
#endif 
#if !defined(ISOLATION_AWARE_ENABLED)||!ISOLATION_AWARE_ENABLED||!defined(_OBJBASE_H_)||!defined(CreateDataAdviseHolder)
WINOLEAPI CreateDataAdviseHolder(OUT LPDATAADVISEHOLDER FAR* ppDAHolder);
#endif
WINOLEAPI_(DWORD) OleBuildVersion(VOID );
WINOLEAPI ReadClassStg(LPSTORAGE pStg,CLSID FAR* pclsid);
WINOLEAPI WriteClassStg(LPSTORAGE pStg,REFCLSID rclsid);
WINOLEAPI ReadClassStm(LPSTREAM pStm,CLSID FAR* pclsid);
WINOLEAPI WriteClassStm(LPSTREAM pStm,REFCLSID rclsid);
WINOLEAPI WriteFmtUserTypeStg (LPSTORAGE pstg,CLIPFORMAT cf,LPOLESTR lpszUserType);
WINOLEAPI ReadFmtUserTypeStg (LPSTORAGE pstg,CLIPFORMAT FAR* pcf,LPOLESTR FAR* lplpszUserType);
WINOLEAPI OleInitialize(LPVOID pvReserved);
WINOLEAPI_(void) OleUninitialize(void);
WINOLEAPI OleQueryLinkFromData(LPDATAOBJECT pSrcDataObject);
WINOLEAPI OleQueryCreateFromData(LPDATAOBJECT pSrcDataObject);
WINOLEAPI OleCreate(REFCLSID rclsid,REFIID riid,DWORD renderopt,LPFORMATETC pFormatEtc,LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateEx(REFCLSID rclsid,REFIID riid,DWORD dwFlags,DWORD renderopt,ULONG cFormats,DWORD* rgAdvf,LPFORMATETC rgFormatEtc,IAdviseSink FAR* lpAdviseSink,DWORD FAR* rgdwConnection,LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateFromData(LPDATAOBJECT pSrcDataObj,REFIID riid,DWORD renderopt,LPFORMATETC pFormatEtc,LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateFromDataEx(LPDATAOBJECT pSrcDataObj,REFIID riid,DWORD dwFlags,DWORD renderopt,ULONG cFormats,DWORD* rgAdvf,LPFORMATETC rgFormatEtc,IAdviseSink FAR* lpAdviseSink,DWORD FAR* rgdwConnection,LPOLECLIENTSITE pClientSite,
				 LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkFromData(LPDATAOBJECT pSrcDataObj,REFIID riid,DWORD renderopt,LPFORMATETC pFormatEtc,LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkFromDataEx(LPDATAOBJECT pSrcDataObj,REFIID riid,DWORD dwFlags,DWORD renderopt,ULONG cFormats,DWORD* rgAdvf,LPFORMATETC rgFormatEtc,IAdviseSink FAR* lpAdviseSink,DWORD FAR* rgdwConnection,LPOLECLIENTSITE pClientSite,
				 LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateStaticFromData(LPDATAOBJECT pSrcDataObj,REFIID iid,DWORD renderopt,LPFORMATETC pFormatEtc,LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLink(LPMONIKER pmkLinkSrc,REFIID riid,DWORD renderopt,LPFORMATETC lpFormatEtc,LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkEx(LPMONIKER pmkLinkSrc,REFIID riid,DWORD dwFlags,DWORD renderopt,ULONG cFormats,DWORD* rgAdvf,LPFORMATETC rgFormatEtc,IAdviseSink FAR* lpAdviseSink,DWORD FAR* rgdwConnection,LPOLECLIENTSITE pClientSite,
			 LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkToFile(LPCOLESTR lpszFileName,REFIID riid,DWORD renderopt,LPFORMATETC lpFormatEtc,LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkToFileEx(LPCOLESTR lpszFileName,REFIID riid,DWORD dwFlags,DWORD renderopt,ULONG cFormats,DWORD* rgAdvf,LPFORMATETC rgFormatEtc,IAdviseSink FAR* lpAdviseSink,DWORD FAR* rgdwConnection,LPOLECLIENTSITE pClientSite,
			 LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateFromFile(REFCLSID rclsid,LPCOLESTR lpszFileName,REFIID riid,DWORD renderopt,LPFORMATETC lpFormatEtc,LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleCreateFromFileEx(REFCLSID rclsid,LPCOLESTR lpszFileName,REFIID riid,DWORD dwFlags,DWORD renderopt,ULONG cFormats,DWORD* rgAdvf,LPFORMATETC rgFormatEtc,IAdviseSink FAR* lpAdviseSink,DWORD FAR* rgdwConnection,LPOLECLIENTSITE pClientSite,
			 LPSTORAGE pStg,LPVOID FAR* ppvObj);
WINOLEAPI OleLoad(LPSTORAGE pStg,REFIID riid,LPOLECLIENTSITE pClientSite,LPVOID FAR* ppvObj);
WINOLEAPI OleSave(LPPERSISTSTORAGE pPS,LPSTORAGE pStg,BOOL fSameAsLoad);
WINOLEAPI OleLoadFromStream(LPSTREAM pStm,REFIID iidInterface,LPVOID FAR* ppvObj);
WINOLEAPI OleSaveToStream(LPPERSISTSTREAM pPStm,LPSTREAM pStm );
WINOLEAPI OleSetContainedObject(LPUNKNOWN pUnknown,BOOL fContained);
WINOLEAPI OleNoteObjectVisible(LPUNKNOWN pUnknown,BOOL fVisible);
WINOLEAPI RegisterDragDrop(HWND hwnd,LPDROPTARGET pDropTarget);
WINOLEAPI RevokeDragDrop(HWND hwnd);
WINOLEAPI DoDragDrop(LPDATAOBJECT pDataObj,LPDROPSOURCE pDropSource,DWORD dwOKEffects,LPDWORD pdwEffect);
WINOLEAPI OleSetClipboard(LPDATAOBJECT pDataObj);
WINOLEAPI OleGetClipboard(OUT LPDATAOBJECT FAR* ppDataObj);
WINOLEAPI OleFlushClipboard(void);
WINOLEAPI OleIsCurrentClipboard(LPDATAOBJECT pDataObj);
WINOLEAPI_(HOLEMENU) OleCreateMenuDescriptor (HMENU hmenuCombined,LPOLEMENUGROUPWIDTHS lpMenuWidths);
WINOLEAPI OleSetMenuDescriptor (HOLEMENU holemenu,HWND hwndFrame,HWND hwndActiveObject,LPOLEINPLACEFRAME lpFrame,LPOLEINPLACEACTIVEOBJECT lpActiveObj);
WINOLEAPI OleDestroyMenuDescriptor (HOLEMENU holemenu);
WINOLEAPI OleTranslateAccelerator (LPOLEINPLACEFRAME lpFrame,LPOLEINPLACEFRAMEINFO lpFrameInfo,LPMSG lpmsg);
WINOLEAPI_(HANDLE) OleDuplicateData (HANDLE hSrc,CLIPFORMAT cfFormat,UINT uiFlags);
WINOLEAPI OleDraw (LPUNKNOWN pUnknown,DWORD dwAspect,HDC hdcDraw,LPCRECT lprcBounds);
WINOLEAPI OleRun(LPUNKNOWN pUnknown);
WINOLEAPI_(BOOL) OleIsRunning(LPOLEOBJECT pObject);
WINOLEAPI OleLockRunning(LPUNKNOWN pUnknown,BOOL fLock,BOOL fLastUnlockCloses);
WINOLEAPI_(void) ReleaseStgMedium(LPSTGMEDIUM);
WINOLEAPI CreateOleAdviseHolder(OUT LPOLEADVISEHOLDER FAR* ppOAHolder);
WINOLEAPI OleCreateDefaultHandler(REFCLSID clsid,LPUNKNOWN pUnkOuter,REFIID riid,LPVOID FAR* lplpObj);
WINOLEAPI OleCreateEmbeddingHelper(REFCLSID clsid,LPUNKNOWN pUnkOuter,DWORD flags,LPCLASSFACTORY pCF,REFIID riid,LPVOID FAR* lplpObj);
WINOLEAPI_(BOOL) IsAccelerator(HACCEL hAccel,int cAccelEntries,LPMSG lpMsg,WORD FAR* lpwCmd);
WINOLEAPI_(HGLOBAL) OleGetIconOfFile(LPOLESTR lpszPath,BOOL fUseFileAsLabel);
WINOLEAPI_(HGLOBAL) OleGetIconOfClass(REFCLSID rclsid,LPOLESTR lpszLabel,BOOL fUseTypeAsLabel);
WINOLEAPI_(HGLOBAL) OleMetafilePictFromIconAndLabel(HICON hIcon,LPOLESTR lpszLabel,LPOLESTR lpszSourceFile,UINT iIconIndex);
WINOLEAPI OleRegGetUserType (REFCLSID clsid,DWORD dwFormOfType,LPOLESTR FAR* pszUserType);
WINOLEAPI OleRegGetMiscStatus(REFCLSID clsid,DWORD dwAspect,DWORD FAR* pdwStatus);
WINOLEAPI OleRegEnumFormatEtc(REFCLSID clsid,DWORD dwDirection,LPENUMFORMATETC FAR* ppenum);
WINOLEAPI OleRegEnumVerbs (REFCLSID clsid,LPENUMOLEVERB FAR* ppenum);
#ifdef _MAC
WINOLEAPI WlmOleCheckoutMacInterface(LPUNKNOWN pUnk,LPVOID* ppv);
WINOLEAPI WlmOleCheckinMacInterface(LPUNKNOWN pUnk);
WINOLEAPI WlmOleWrapMacInterface(LPUNKNOWN pUnk,REFIID riid,LPVOID* ppv);
WINOLEAPI WlmOleUnwrapMacInterface(LPVOID pv);
WINOLEAPI WlmOleCheckoutWinInterface(LPVOID pUnk,LPUNKNOWN* ppv);
WINOLEAPI WlmOleCheckinWinInterface(LPVOID pUnk);
WINOLEAPI WlmOleWrapWinInterface(LPVOID pUnk,REFIID riid,LPUNKNOWN* ppv);
WINOLEAPI WlmOleUnwrapWinInterface(LPVOID pv);
WINOLEAPI_(void) WlmOleVersion(void);
WINOLEAPI_(void) WlmOleSetInPlaceWindow(HWND hwnd);
typedef HRESULT (STDAPICALLTYPE* OLEWRAPPROC) (REFIID riid,LPVOID* ppvWin,LPVOID* ppvMac);
WINOLEAPI WlmOleRegisterUserWrap(OLEWRAPPROC procNew,OLEWRAPPROC* pprocOld);
#endif
typedef struct _OLESTREAM FAR* LPOLESTREAM;
typedef struct _OLESTREAMVTBL {
	DWORD (* Get)(LPOLESTREAM,void *,DWORD);
	DWORD (* Put)(LPOLESTREAM,const void *,DWORD);
} OLESTREAMVTBL;
typedef OLESTREAMVTBL FAR* LPOLESTREAMVTBL;
typedef struct _OLESTREAM {
	LPOLESTREAMVTBL lpstbl;
} OLESTREAM;
WINOLEAPI OleConvertOLESTREAMToIStorage
	(LPOLESTREAM lpolestream,LPSTORAGE pstg,const DVTARGETDEVICE FAR* ptd);
WINOLEAPI OleConvertIStorageToOLESTREAM
	(LPSTORAGE pstg,LPOLESTREAM lpolestream);
WINOLEAPI GetHGlobalFromILockBytes (LPLOCKBYTES plkbyt,HGLOBAL FAR* phglobal);
WINOLEAPI CreateILockBytesOnHGlobal (HGLOBAL hGlobal,BOOL fDeleteOnRelease,LPLOCKBYTES FAR* pplkbyt);
WINOLEAPI GetHGlobalFromStream (LPSTREAM pstm,HGLOBAL FAR* phglobal);
WINOLEAPI CreateStreamOnHGlobal (HGLOBAL hGlobal,BOOL fDeleteOnRelease,LPSTREAM FAR* ppstm);
WINOLEAPI OleDoAutoConvert(LPSTORAGE pStg,LPCLSID pClsidNew);
WINOLEAPI OleGetAutoConvert(REFCLSID clsidOld,LPCLSID pClsidNew);
WINOLEAPI OleSetAutoConvert(REFCLSID clsidOld,REFCLSID clsidNew);
WINOLEAPI GetConvertStg(LPSTORAGE pStg);
WINOLEAPI SetConvertStg(LPSTORAGE pStg,BOOL fConvert);
WINOLEAPI OleConvertIStorageToOLESTREAMEx
	(LPSTORAGE pstg,CLIPFORMAT cfFormat,LONG lWidth,LONG lHeight,DWORD dwSize,LPSTGMEDIUM pmedium,LPOLESTREAM polestm);
WINOLEAPI OleConvertOLESTREAMToIStorageEx
	(LPOLESTREAM polestm,LPSTORAGE pstg,CLIPFORMAT FAR* pcfFormat,LONG FAR* plwWidth,LONG FAR* plHeight,DWORD FAR* pdwSize,LPSTGMEDIUM pmedium); 
#ifndef _MAC
#ifndef RC_INVOKED
#include <poppack.h>
#endif 
#else 
#ifndef __MACAPI__
#include <macapi.h>
#endif
#ifdef _WIN32
#include "macname2.h"
#endif 
#endif 
#endif 
