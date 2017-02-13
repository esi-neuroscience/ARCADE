#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif
#pragma once
#include "rpc.h"
#include "rpcndr.h"
#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif 
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif 
#ifndef __urlmon_h__
#define __urlmon_h__
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#endif
#ifndef __IPersistMoniker_FWD_DEFINED__
#define __IPersistMoniker_FWD_DEFINED__
typedef interface IPersistMoniker IPersistMoniker;
#endif 
#ifndef __IMonikerProp_FWD_DEFINED__
#define __IMonikerProp_FWD_DEFINED__
typedef interface IMonikerProp IMonikerProp;
#endif 
#ifndef __IBindProtocol_FWD_DEFINED__
#define __IBindProtocol_FWD_DEFINED__
typedef interface IBindProtocol IBindProtocol;
#endif 
#ifndef __IBinding_FWD_DEFINED__
#define __IBinding_FWD_DEFINED__
typedef interface IBinding IBinding;
#endif 
#ifndef __IBindStatusCallback_FWD_DEFINED__
#define __IBindStatusCallback_FWD_DEFINED__
typedef interface IBindStatusCallback IBindStatusCallback;
#endif 
#ifndef __IAuthenticate_FWD_DEFINED__
#define __IAuthenticate_FWD_DEFINED__
typedef interface IAuthenticate IAuthenticate;
#endif 
#ifndef __IHttpNegotiate_FWD_DEFINED__
#define __IHttpNegotiate_FWD_DEFINED__
typedef interface IHttpNegotiate IHttpNegotiate;
#endif 
#ifndef __IHttpNegotiate2_FWD_DEFINED__
#define __IHttpNegotiate2_FWD_DEFINED__
typedef interface IHttpNegotiate2 IHttpNegotiate2;
#endif 
#ifndef __IWinInetFileStream_FWD_DEFINED__
#define __IWinInetFileStream_FWD_DEFINED__
typedef interface IWinInetFileStream IWinInetFileStream;
#endif 
#ifndef __IWindowForBindingUI_FWD_DEFINED__
#define __IWindowForBindingUI_FWD_DEFINED__
typedef interface IWindowForBindingUI IWindowForBindingUI;
#endif 
#ifndef __ICodeInstall_FWD_DEFINED__
#define __ICodeInstall_FWD_DEFINED__
typedef interface ICodeInstall ICodeInstall;
#endif 
#ifndef __IWinInetInfo_FWD_DEFINED__
#define __IWinInetInfo_FWD_DEFINED__
typedef interface IWinInetInfo IWinInetInfo;
#endif 
#ifndef __IHttpSecurity_FWD_DEFINED__
#define __IHttpSecurity_FWD_DEFINED__
typedef interface IHttpSecurity IHttpSecurity;
#endif 
#ifndef __IWinInetHttpInfo_FWD_DEFINED__
#define __IWinInetHttpInfo_FWD_DEFINED__
typedef interface IWinInetHttpInfo IWinInetHttpInfo;
#endif 
#ifndef __IBindHost_FWD_DEFINED__
#define __IBindHost_FWD_DEFINED__
typedef interface IBindHost IBindHost;
#endif 
#ifndef __IInternet_FWD_DEFINED__
#define __IInternet_FWD_DEFINED__
typedef interface IInternet IInternet;
#endif 
#ifndef __IInternetBindInfo_FWD_DEFINED__
#define __IInternetBindInfo_FWD_DEFINED__
typedef interface IInternetBindInfo IInternetBindInfo;
#endif 
#ifndef __IInternetProtocolRoot_FWD_DEFINED__
#define __IInternetProtocolRoot_FWD_DEFINED__
typedef interface IInternetProtocolRoot IInternetProtocolRoot;
#endif 
#ifndef __IInternetProtocol_FWD_DEFINED__
#define __IInternetProtocol_FWD_DEFINED__
typedef interface IInternetProtocol IInternetProtocol;
#endif 
#ifndef __IInternetProtocolSink_FWD_DEFINED__
#define __IInternetProtocolSink_FWD_DEFINED__
typedef interface IInternetProtocolSink IInternetProtocolSink;
#endif 
#ifndef __IInternetProtocolSinkStackable_FWD_DEFINED__
#define __IInternetProtocolSinkStackable_FWD_DEFINED__
typedef interface IInternetProtocolSinkStackable IInternetProtocolSinkStackable;
#endif 
#ifndef __IInternetSession_FWD_DEFINED__
#define __IInternetSession_FWD_DEFINED__
typedef interface IInternetSession IInternetSession;
#endif 
#ifndef __IInternetThreadSwitch_FWD_DEFINED__
#define __IInternetThreadSwitch_FWD_DEFINED__
typedef interface IInternetThreadSwitch IInternetThreadSwitch;
#endif 
#ifndef __IInternetPriority_FWD_DEFINED__
#define __IInternetPriority_FWD_DEFINED__
typedef interface IInternetPriority IInternetPriority;
#endif 
#ifndef __IInternetProtocolInfo_FWD_DEFINED__
#define __IInternetProtocolInfo_FWD_DEFINED__
typedef interface IInternetProtocolInfo IInternetProtocolInfo;
#endif 
#ifndef __IInternetSecurityMgrSite_FWD_DEFINED__
#define __IInternetSecurityMgrSite_FWD_DEFINED__
typedef interface IInternetSecurityMgrSite IInternetSecurityMgrSite;
#endif 
#ifndef __IInternetSecurityManager_FWD_DEFINED__
#define __IInternetSecurityManager_FWD_DEFINED__
typedef interface IInternetSecurityManager IInternetSecurityManager;
#endif 
#ifndef __IInternetHostSecurityManager_FWD_DEFINED__
#define __IInternetHostSecurityManager_FWD_DEFINED__
typedef interface IInternetHostSecurityManager IInternetHostSecurityManager;
#endif 
#ifndef __IInternetZoneManager_FWD_DEFINED__
#define __IInternetZoneManager_FWD_DEFINED__
typedef interface IInternetZoneManager IInternetZoneManager;
#endif 
#ifndef __ISoftDistExt_FWD_DEFINED__
#define __ISoftDistExt_FWD_DEFINED__
typedef interface ISoftDistExt ISoftDistExt;
#endif 
#ifndef __ICatalogFileInfo_FWD_DEFINED__
#define __ICatalogFileInfo_FWD_DEFINED__
typedef interface ICatalogFileInfo ICatalogFileInfo;
#endif 
#ifndef __IDataFilter_FWD_DEFINED__
#define __IDataFilter_FWD_DEFINED__
typedef interface IDataFilter IDataFilter;
#endif 
#ifndef __IEncodingFilterFactory_FWD_DEFINED__
#define __IEncodingFilterFactory_FWD_DEFINED__
typedef interface IEncodingFilterFactory IEncodingFilterFactory;
#endif 
#ifndef __IWrappedProtocol_FWD_DEFINED__
#define __IWrappedProtocol_FWD_DEFINED__
typedef interface IWrappedProtocol IWrappedProtocol;
#endif 
#include "objidl.h"
#include "oleidl.h"
#include "servprov.h"
#include "msxml.h"
void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void *); 
EXTERN_C const IID CLSID_SBS_StdURLMoniker; 
EXTERN_C const IID CLSID_SBS_HttpProtocol; 
EXTERN_C const IID CLSID_SBS_FtpProtocol; 
EXTERN_C const IID CLSID_SBS_GopherProtocol; 
EXTERN_C const IID CLSID_SBS_HttpSProtocol; 
EXTERN_C const IID CLSID_SBS_FileProtocol; 
EXTERN_C const IID CLSID_SBS_MkProtocol; 
EXTERN_C const IID CLSID_SBS_UrlMkBindCtx; 
EXTERN_C const IID CLSID_SBS_SoftDistExt; 
EXTERN_C const IID CLSID_SBS_StdEncodingFilterFac; 
EXTERN_C const IID CLSID_SBS_DeCompMimeFilter; 
EXTERN_C const IID CLSID_SBS_CdlProtocol; 
EXTERN_C const IID CLSID_SBS_ClassInstallFilter; 
EXTERN_C const IID CLSID_SBS_InternetSecurityManager; 
EXTERN_C const IID CLSID_SBS_InternetZoneManager; 
#define BINDF_DONTUSECACHE BINDF_GETNEWESTVERSION
#define BINDF_DONTPUTINCACHE BINDF_NOWRITECACHE
#define BINDF_NOCOPYDATA BINDF_PULLDATA
#define INVALID_P_ROOT_SECURITY_ID ((BYTE*)-1)
#define PI_DOCFILECLSIDLOOKUP PI_CLSIDLOOKUP
EXTERN_C const IID IID_IAsyncMoniker; 
EXTERN_C const IID CLSID_StdURLMoniker; 
EXTERN_C const IID CLSID_HttpProtocol; 
EXTERN_C const IID CLSID_FtpProtocol; 
EXTERN_C const IID CLSID_GopherProtocol; 
EXTERN_C const IID CLSID_HttpSProtocol; 
EXTERN_C const IID CLSID_FileProtocol; 
EXTERN_C const IID CLSID_MkProtocol; 
EXTERN_C const IID CLSID_StdURLProtocol; 
EXTERN_C const IID CLSID_UrlMkBindCtx; 
EXTERN_C const IID CLSID_StdEncodingFilterFac; 
EXTERN_C const IID CLSID_DeCompMimeFilter; 
EXTERN_C const IID CLSID_CdlProtocol; 
EXTERN_C const IID CLSID_ClassInstallFilter; 
EXTERN_C const IID IID_IAsyncBindCtx; 
#define SZ_URLCONTEXT OLESTR("URL Context")
#define SZ_ASYNC_CALLEE OLESTR("AsyncCallee")
#define MKSYS_URLMONIKER 6 
#define URL_MK_LEGACY 0 
#define URL_MK_UNIFORM 1 
#define URL_MK_NO_CANONICALIZE 2 
STDAPI CreateURLMoniker(LPMONIKER ,LPCWSTR ,LPMONIKER *); 
STDAPI CreateURLMonikerEx(LPMONIKER ,LPCWSTR ,LPMONIKER *,DWORD ); 
STDAPI GetClassURL(LPCWSTR ,CLSID *); 
STDAPI CreateAsyncBindCtx(DWORD ,IBindStatusCallback *,IEnumFORMATETC *,IBindCtx **); 
STDAPI CreateAsyncBindCtxEx(IBindCtx *,DWORD ,IBindStatusCallback *,IEnumFORMATETC *,IBindCtx **,DWORD ); 
STDAPI MkParseDisplayNameEx(IBindCtx *,LPCWSTR ,ULONG *,LPMONIKER *); 
STDAPI RegisterBindStatusCallback(LPBC ,IBindStatusCallback *,IBindStatusCallback** ppBSCBPrev,DWORD ); 
STDAPI RevokeBindStatusCallback(LPBC ,IBindStatusCallback *); 
STDAPI GetClassFileOrMime(LPBC ,LPCWSTR ,LPVOID ,DWORD ,LPCWSTR ,DWORD ,CLSID *); 
STDAPI IsValidURL(LPBC ,LPCWSTR ,DWORD ); 
STDAPI CoGetClassObjectFromURL(REFCLSID ,LPCWSTR ,DWORD ,DWORD ,LPCWSTR ,LPBINDCTX ,DWORD ,LPVOID ,REFIID ,LPVOID *);
STDAPI FaultInIEFeature(HWND ,uCLSSPEC *,QUERYCONTEXT *,DWORD ); 
STDAPI GetComponentIDFromCLSSPEC(uCLSSPEC *,LPSTR *); 
#define FIEF_FLAG_FORCE_JITUI 1
#define FIEF_FLAG_PEEK 2
#define FIEF_FLAG_SKIP_INSTALLED_VERSION_CHECK 4
STDAPI IsAsyncMoniker(IMoniker* pmk); 
STDAPI CreateURLBinding(LPCWSTR ,IBindCtx *,IBinding **); 
STDAPI RegisterMediaTypes(UINT ,const LPCSTR* rgszTypes,CLIPFORMAT* rgcfTypes); 
STDAPI FindMediaType(LPCSTR ,CLIPFORMAT* rgcfTypes); 
STDAPI CreateFormatEnumerator(UINT ,FORMATETC* rgfmtetc,IEnumFORMATETC** ppenumfmtetc); 
STDAPI RegisterFormatEnumerator(LPBC ,IEnumFORMATETC *,DWORD ); 
STDAPI RevokeFormatEnumerator(LPBC ,IEnumFORMATETC *); 
STDAPI RegisterMediaTypeClass(LPBC ,UINT ,const LPCSTR* rgszTypes,CLSID *,DWORD ); 
STDAPI FindMediaTypeClass(LPBC ,LPCSTR ,CLSID *,DWORD ); 
STDAPI UrlMkSetSessionOption(DWORD ,LPVOID ,DWORD ,DWORD ); 
STDAPI UrlMkGetSessionOption(DWORD ,LPVOID ,DWORD ,DWORD *,DWORD ); 
STDAPI FindMimeFromData(LPBC ,LPCWSTR ,LPVOID ,DWORD ,LPCWSTR ,DWORD ,LPWSTR *,DWORD ); 
#define FMFD_DEFAULT 0
#define FMFD_URLASFILENAME 1
STDAPI ObtainUserAgentString(DWORD ,LPSTR ,DWORD* cbSize); 
STDAPI CompareSecurityIds(BYTE* pbSecurityId1,DWORD ,BYTE* pbSecurityId2,DWORD ,DWORD ); 
#define URLMON_OPTION_USERAGENT 0x10000001
#define URLMON_OPTION_USERAGENT_REFRESH 0x10000002
#define URLMON_OPTION_URL_ENCODING 0x10000004
#define CF_NULL 0 
#define CFSTR_MIME_NULL NULL 
#define CFSTR_MIME_TEXT (TEXT("text/plain")) 
#define CFSTR_MIME_RICHTEXT (TEXT("text/richtext")) 
#define CFSTR_MIME_X_BITMAP (TEXT("image/x-xbitmap")) 
#define CFSTR_MIME_POSTSCRIPT (TEXT("application/postscript")) 
#define CFSTR_MIME_AIFF (TEXT("audio/aiff")) 
#define CFSTR_MIME_BASICAUDIO (TEXT("audio/basic")) 
#define CFSTR_MIME_WAV (TEXT("audio/wav")) 
#define CFSTR_MIME_X_WAV (TEXT("audio/x-wav")) 
#define CFSTR_MIME_GIF (TEXT("image/gif")) 
#define CFSTR_MIME_PJPEG (TEXT("image/pjpeg")) 
#define CFSTR_MIME_JPEG (TEXT("image/jpeg")) 
#define CFSTR_MIME_TIFF (TEXT("image/tiff")) 
#define CFSTR_MIME_X_PNG (TEXT("image/x-png")) 
#define CFSTR_MIME_BMP (TEXT("image/bmp")) 
#define CFSTR_MIME_X_ART (TEXT("image/x-jg")) 
#define CFSTR_MIME_X_EMF (TEXT("image/x-emf")) 
#define CFSTR_MIME_X_WMF (TEXT("image/x-wmf")) 
#define CFSTR_MIME_AVI (TEXT("video/avi")) 
#define CFSTR_MIME_MPEG (TEXT("video/mpeg")) 
#define CFSTR_MIME_FRACTALS (TEXT("application/fractals")) 
#define CFSTR_MIME_RAWDATA (TEXT("application/octet-stream"))
#define CFSTR_MIME_RAWDATASTRM (TEXT("application/octet-stream"))
#define CFSTR_MIME_PDF (TEXT("application/pdf")) 
#define CFSTR_MIME_HTA (TEXT("application/hta")) 
#define CFSTR_MIME_X_AIFF (TEXT("audio/x-aiff")) 
#define CFSTR_MIME_X_REALAUDIO (TEXT("audio/x-pn-realaudio")) 
#define CFSTR_MIME_XBM (TEXT("image/xbm")) 
#define CFSTR_MIME_QUICKTIME (TEXT("video/quicktime")) 
#define CFSTR_MIME_X_MSVIDEO (TEXT("video/x-msvideo")) 
#define CFSTR_MIME_X_SGI_MOVIE (TEXT("video/x-sgi-movie")) 
#define CFSTR_MIME_HTML (TEXT("text/html")) 
#define CFSTR_MIME_XML (TEXT("text/xml")) 
#define MK_S_ASYNCHRONOUS _HRESULT_TYPEDEF_0x401e8  
#ifndef S_ASYNCHRONOUS 
#define S_ASYNCHRONOUS MK_S_ASYNCHRONOUS 
#endif 
#ifndef E_PENDING 
#define E_PENDING _HRESULT_TYPEDEF_0x8000000a  
#endif 
#define INET_E_INVALID_URL _HRESULT_TYPEDEF_0x800c0002  
#define INET_E_NO_SESSION _HRESULT_TYPEDEF_0x800c0003  
#define INET_E_CANNOT_CONNECT _HRESULT_TYPEDEF_0x800c0004  
#define INET_E_RESOURCE_NOT_FOUND _HRESULT_TYPEDEF_0x800c0005  
#define INET_E_OBJECT_NOT_FOUND _HRESULT_TYPEDEF_0x800c0006  
#define INET_E_DATA_NOT_AVAILABLE _HRESULT_TYPEDEF_0x800c0007  
#define INET_E_DOWNLOAD_FAILURE _HRESULT_TYPEDEF_0x800c0008  
#define INET_E_AUTHENTICATION_REQUIRED _HRESULT_TYPEDEF_0x800c0009  
#define INET_E_NO_VALID_MEDIA _HRESULT_TYPEDEF_0x800c000a  
#define INET_E_CONNECTION_TIMEOUT _HRESULT_TYPEDEF_0x800c000b  
#define INET_E_INVALID_REQUEST _HRESULT_TYPEDEF_0x800c000c  
#define INET_E_UNKNOWN_PROTOCOL _HRESULT_TYPEDEF_0x800c000d  
#define INET_E_SECURITY_PROBLEM _HRESULT_TYPEDEF_0x800c000e  
#define INET_E_CANNOT_LOAD_DATA _HRESULT_TYPEDEF_0x800c000f  
#define INET_E_CANNOT_INSTANTIATE_OBJECT _HRESULT_TYPEDEF_0x800c0010  
#define INET_E_REDIRECT_FAILED _HRESULT_TYPEDEF_0x800c0014  
#define INET_E_REDIRECT_TO_DIR _HRESULT_TYPEDEF_0x800c0015  
#define INET_E_CANNOT_LOCK_REQUEST _HRESULT_TYPEDEF_0x800c0016  
#define INET_E_USE_EXTEND_BINDING _HRESULT_TYPEDEF_0x800c0017  
#define INET_E_TERMINATED_BIND _HRESULT_TYPEDEF_0x800c0018  
#define INET_E_ERROR_FIRST _HRESULT_TYPEDEF_0x800c0002  
#define INET_E_CODE_DOWNLOAD_DECLINED _HRESULT_TYPEDEF_0x800c0100  
#define INET_E_RESULT_DISPATCHED _HRESULT_TYPEDEF_0x800c0200  
#define INET_E_CANNOT_REPLACE_SFP_FILE _HRESULT_TYPEDEF_0x800c0300  
#define INET_E_ERROR_LAST INET_E_CANNOT_REPLACE_SFP_FILE
#ifndef _LPPERSISTMONIKER_DEFINED
#define _LPPERSISTMONIKER_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0000_v0_0_s_ifspec;
#ifndef __IPersistMoniker_INTERFACE_DEFINED__
#define __IPersistMoniker_INTERFACE_DEFINED__
typedef  IPersistMoniker *LPPERSISTMONIKER;
EXTERN_C const IID IID_IPersistMoniker;
typedef struct IPersistMonikerVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IPersistMoniker *,REFIID,void **);
 ULONG ( *AddRef)(IPersistMoniker *);
 ULONG ( *Release)(IPersistMoniker *);
 HRESULT ( *GetClassID)(IPersistMoniker *,CLSID *);
 HRESULT ( *IsDirty)(IPersistMoniker *);
 HRESULT ( *Load)(IPersistMoniker *,BOOL,IMoniker *,LPBC,DWORD);
 HRESULT ( *Save)(IPersistMoniker *,IMoniker *,LPBC,BOOL);
 HRESULT ( *SaveCompleted)(IPersistMoniker *,IMoniker *,LPBC);
 HRESULT ( *GetCurMoniker)(IPersistMoniker *,IMoniker **);
END_INTERFACE
} IPersistMonikerVtbl;
interface IPersistMoniker
{
CONST_VTBL struct IPersistMonikerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPersistMoniker_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPersistMoniker_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPersistMoniker_Release(A) (A)->lpVtbl->Release(A)
#define IPersistMoniker_GetClassID(A,B) (A)->lpVtbl->GetClassID(A,B)
#define IPersistMoniker_IsDirty(A) (A)->lpVtbl->IsDirty(A)
#define IPersistMoniker_Load(A,B,C,D,E) (A)->lpVtbl->Load(A,B,C,D,E)
#define IPersistMoniker_Save(A,B,C,D) (A)->lpVtbl->Save(A,B,C,D)
#define IPersistMoniker_SaveCompleted(A,B,C) (A)->lpVtbl->SaveCompleted(A,B,C)
#define IPersistMoniker_GetCurMoniker(A,B) (A)->lpVtbl->GetCurMoniker(A,B)
#endif 
HRESULT IPersistMoniker_GetClassID_Proxy(IPersistMoniker *,CLSID *);
void __RPC_STUB IPersistMoniker_GetClassID_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IPersistMoniker_IsDirty_Proxy(IPersistMoniker *);
void __RPC_STUB IPersistMoniker_IsDirty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IPersistMoniker_Load_Proxy(IPersistMoniker *,BOOL ,IMoniker *,LPBC ,DWORD );
void __RPC_STUB IPersistMoniker_Load_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IPersistMoniker_Save_Proxy(IPersistMoniker *,IMoniker *,LPBC ,BOOL );
void __RPC_STUB IPersistMoniker_Save_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IPersistMoniker_SaveCompleted_Proxy(IPersistMoniker *,IMoniker *,LPBC );
void __RPC_STUB IPersistMoniker_SaveCompleted_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IPersistMoniker_GetCurMoniker_Proxy(IPersistMoniker *,IMoniker **);
void __RPC_STUB IPersistMoniker_GetCurMoniker_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPMONIKERPROP_DEFINED
#define _LPMONIKERPROP_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0178_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0178_v0_0_s_ifspec;
#ifndef __IMonikerProp_INTERFACE_DEFINED__
#define __IMonikerProp_INTERFACE_DEFINED__
typedef  IMonikerProp *LPMONIKERPROP;
typedef  
enum __MIDL_IMonikerProp_0001
{	MIMETYPEPROP=0,
USE_SRC_URL=1
} MONIKERPROPERTY;
EXTERN_C const IID IID_IMonikerProp;
typedef struct IMonikerPropVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IMonikerProp *,REFIID,void **);
 ULONG ( *AddRef)(IMonikerProp *);
 ULONG ( *Release)(IMonikerProp *);
 HRESULT ( *PutProperty)(IMonikerProp *,MONIKERPROPERTY,LPCWSTR);
END_INTERFACE
} IMonikerPropVtbl;
interface IMonikerProp
{
CONST_VTBL struct IMonikerPropVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMonikerProp_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IMonikerProp_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IMonikerProp_Release(A) (A)->lpVtbl->Release(A)
#define IMonikerProp_PutProperty(A,B,C) (A)->lpVtbl->PutProperty(A,B,C)
#endif 
HRESULT IMonikerProp_PutProperty_Proxy(IMonikerProp *,MONIKERPROPERTY ,LPCWSTR );
void __RPC_STUB IMonikerProp_PutProperty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPBINDPROTOCOL_DEFINED
#define _LPBINDPROTOCOL_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0179_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0179_v0_0_s_ifspec;
#ifndef __IBindProtocol_INTERFACE_DEFINED__
#define __IBindProtocol_INTERFACE_DEFINED__
typedef  IBindProtocol *LPBINDPROTOCOL;
EXTERN_C const IID IID_IBindProtocol;
typedef struct IBindProtocolVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IBindProtocol *,REFIID,void **);
 ULONG ( *AddRef)(IBindProtocol *);
 ULONG ( *Release)(IBindProtocol *);
 HRESULT ( *CreateBinding)(IBindProtocol *,LPCWSTR,IBindCtx *,IBinding **);
END_INTERFACE
} IBindProtocolVtbl;
interface IBindProtocol
{
CONST_VTBL struct IBindProtocolVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IBindProtocol_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IBindProtocol_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IBindProtocol_Release(A) (A)->lpVtbl->Release(A)
#define IBindProtocol_CreateBinding(A,B,C,D) (A)->lpVtbl->CreateBinding(A,B,C,D)
#endif 
HRESULT IBindProtocol_CreateBinding_Proxy(IBindProtocol *,LPCWSTR ,IBindCtx *,IBinding **);
void __RPC_STUB IBindProtocol_CreateBinding_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPBINDING_DEFINED
#define _LPBINDING_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0180_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0180_v0_0_s_ifspec;
#ifndef __IBinding_INTERFACE_DEFINED__
#define __IBinding_INTERFACE_DEFINED__
typedef  IBinding *LPBINDING;
EXTERN_C const IID IID_IBinding;
typedef struct IBindingVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IBinding *,REFIID,void **);
 ULONG ( *AddRef)(IBinding *);
 ULONG ( *Release)(IBinding *);
 HRESULT ( *Abort)(IBinding *);
 HRESULT ( *Suspend)(IBinding *);
 HRESULT ( *Resume)(IBinding *);
 HRESULT ( *SetPriority)(IBinding *,LONG);
 HRESULT ( *GetPriority)(IBinding *,LONG *);
 HRESULT ( *GetBindResult)(IBinding *,CLSID *,DWORD *,LPOLESTR *,DWORD *);
END_INTERFACE
} IBindingVtbl;
interface IBinding
{
CONST_VTBL struct IBindingVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IBinding_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IBinding_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IBinding_Release(A) (A)->lpVtbl->Release(A)
#define IBinding_Abort(A) (A)->lpVtbl->Abort(A)
#define IBinding_Suspend(A) (A)->lpVtbl->Suspend(A)
#define IBinding_Resume(A) (A)->lpVtbl->Resume(A)
#define IBinding_SetPriority(A,B) (A)->lpVtbl->SetPriority(A,B)
#define IBinding_GetPriority(A,B) (A)->lpVtbl->GetPriority(A,B)
#define IBinding_GetBindResult(A,B,C,D,E) (A)->lpVtbl->GetBindResult(A,B,C,D,E)
#endif 
HRESULT IBinding_Abort_Proxy(IBinding *);
void __RPC_STUB IBinding_Abort_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBinding_Suspend_Proxy(IBinding *);
void __RPC_STUB IBinding_Suspend_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBinding_Resume_Proxy(IBinding *);
void __RPC_STUB IBinding_Resume_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBinding_SetPriority_Proxy(IBinding *,LONG );
void __RPC_STUB IBinding_SetPriority_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBinding_GetPriority_Proxy(IBinding *,LONG *);
void __RPC_STUB IBinding_GetPriority_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBinding_RemoteGetBindResult_Proxy(IBinding *,CLSID *,DWORD *,LPOLESTR *,DWORD );
void __RPC_STUB IBinding_RemoteGetBindResult_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPBINDSTATUSCALLBACK_DEFINED
#define _LPBINDSTATUSCALLBACK_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0181_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0181_v0_0_s_ifspec;
#ifndef __IBindStatusCallback_INTERFACE_DEFINED__
#define __IBindStatusCallback_INTERFACE_DEFINED__
typedef  IBindStatusCallback *LPBINDSTATUSCALLBACK;
typedef  
enum __MIDL_IBindStatusCallback_0001
{	BINDVERB_GET=0,
BINDVERB_POST=1,
BINDVERB_PUT=2,
BINDVERB_CUSTOM=3
} BINDVERB;
typedef  
enum __MIDL_IBindStatusCallback_0002
{	BINDINFOF_URLENCODESTGMEDDATA=1,
BINDINFOF_URLENCODEDEXTRAINFO=2
} BINDINFOF;
typedef  
enum __MIDL_IBindStatusCallback_0003
{	BINDF_ASYNCHRONOUS=1,
BINDF_ASYNCSTORAGE=2,
BINDF_NOPROGRESSIVERENDERING=4,
BINDF_OFFLINEOPERATION=8,
BINDF_GETNEWESTVERSION=16,
BINDF_NOWRITECACHE=32,
BINDF_NEEDFILE=64,
BINDF_PULLDATA=128,
BINDF_IGNORESECURITYPROBLEM=256,
BINDF_RESYNCHRONIZE=512,
BINDF_HYPERLINK=1024,
BINDF_NO_UI=2048,
BINDF_SILENTOPERATION=4096,
BINDF_PRAGMA_NO_CACHE=0x2000,
BINDF_GETCLASSOBJECT=0x4000,
BINDF_RESERVED_1=0x8000,
BINDF_FREE_THREADED=0x10000,
BINDF_DIRECT_READ=0x20000,
BINDF_FORMS_SUBMIT=0x40000,
BINDF_GETFROMCACHE_IF_NET_FAIL=0x80000,
BINDF_FROMURLMON=0x100000,
BINDF_FWD_BACK=0x200000,
BINDF_PREFERDEFAULTHANDLER=0x400000,
BINDF_ENFORCERESTRICTED=0x800000
} BINDF;
typedef  
enum __MIDL_IBindStatusCallback_0004
{	URL_ENCODING_NONE=0,
URL_ENCODING_ENABLE_UTF8=0x10000000,
URL_ENCODING_DISABLE_UTF8=0x20000000
} URL_ENCODING;
typedef struct _tagBINDINFO
{
ULONG cbSize;
LPWSTR szExtraInfo;
STGMEDIUM stgmedData;
DWORD grfBindInfoF;
DWORD dwBindVerb;
LPWSTR szCustomVerb;
DWORD cbstgmedData;
DWORD dwOptions;
DWORD dwOptionsFlags;
DWORD dwCodePage;
SECURITY_ATTRIBUTES securityAttributes;
IID iid;
IUnknown *pUnk;
DWORD dwReserved;
} BINDINFO;
typedef struct _REMSECURITY_ATTRIBUTES
{
DWORD nLength;
DWORD lpSecurityDescriptor;
BOOL bInheritHandle;
} REMSECURITY_ATTRIBUTES;
typedef struct _REMSECURITY_ATTRIBUTES *PREMSECURITY_ATTRIBUTES;
typedef struct _REMSECURITY_ATTRIBUTES *LPREMSECURITY_ATTRIBUTES;
typedef struct _tagRemBINDINFO
{
ULONG cbSize;
LPWSTR szExtraInfo;
DWORD grfBindInfoF;
DWORD dwBindVerb;
LPWSTR szCustomVerb;
DWORD cbstgmedData;
DWORD dwOptions;
DWORD dwOptionsFlags;
DWORD dwCodePage;
REMSECURITY_ATTRIBUTES securityAttributes;
IID iid;
IUnknown *pUnk;
DWORD dwReserved;
} RemBINDINFO;
typedef struct tagRemFORMATETC
{
DWORD cfFormat;
DWORD ptd;
DWORD dwAspect;
LONG lindex;
DWORD tymed;
} RemFORMATETC;
typedef struct tagRemFORMATETC *LPREMFORMATETC;
typedef  
enum __MIDL_IBindStatusCallback_0005
{	BINDINFO_OPTIONS_WININETFLAG=0x10000,
BINDINFO_OPTIONS_ENABLE_UTF8=0x20000,
BINDINFO_OPTIONS_DISABLE_UTF8=0x40000,
BINDINFO_OPTIONS_USE_IE_ENCODING=0x80000,
BINDINFO_OPTIONS_BINDTOOBJECT=0x100000
} BINDINFO_OPTIONS;
typedef  
enum __MIDL_IBindStatusCallback_0006
{	BSCF_FIRSTDATANOTIFICATION=1,
BSCF_INTERMEDIATEDATANOTIFICATION=2,
BSCF_LASTDATANOTIFICATION=4,
BSCF_DATAFULLYAVAILABLE=8,
BSCF_AVAILABLEDATASIZEUNKNOWN=16
} BSCF;
typedef 
enum tagBINDSTATUS
{	BINDSTATUS_FINDINGRESOURCE=1,
BINDSTATUS_CONNECTING=BINDSTATUS_FINDINGRESOURCE + 1,
BINDSTATUS_REDIRECTING=BINDSTATUS_CONNECTING + 1,
BINDSTATUS_BEGINDOWNLOADDATA=BINDSTATUS_REDIRECTING + 1,
BINDSTATUS_DOWNLOADINGDATA=BINDSTATUS_BEGINDOWNLOADDATA + 1,
BINDSTATUS_ENDDOWNLOADDATA=BINDSTATUS_DOWNLOADINGDATA + 1,
BINDSTATUS_BEGINDOWNLOADCOMPONENTS=BINDSTATUS_ENDDOWNLOADDATA + 1,
BINDSTATUS_INSTALLINGCOMPONENTS=BINDSTATUS_BEGINDOWNLOADCOMPONENTS + 1,
BINDSTATUS_ENDDOWNLOADCOMPONENTS=BINDSTATUS_INSTALLINGCOMPONENTS + 1,
BINDSTATUS_USINGCACHEDCOPY=BINDSTATUS_ENDDOWNLOADCOMPONENTS + 1,
BINDSTATUS_SENDINGREQUEST=BINDSTATUS_USINGCACHEDCOPY + 1,
BINDSTATUS_CLASSIDAVAILABLE=BINDSTATUS_SENDINGREQUEST + 1,
BINDSTATUS_MIMETYPEAVAILABLE=BINDSTATUS_CLASSIDAVAILABLE + 1,
BINDSTATUS_CACHEFILENAMEAVAILABLE=BINDSTATUS_MIMETYPEAVAILABLE + 1,
BINDSTATUS_BEGINSYNCOPERATION=BINDSTATUS_CACHEFILENAMEAVAILABLE + 1,
BINDSTATUS_ENDSYNCOPERATION=BINDSTATUS_BEGINSYNCOPERATION + 1,
BINDSTATUS_BEGINUPLOADDATA=BINDSTATUS_ENDSYNCOPERATION + 1,
BINDSTATUS_UPLOADINGDATA=BINDSTATUS_BEGINUPLOADDATA + 1,
BINDSTATUS_ENDUPLOADDATA=BINDSTATUS_UPLOADINGDATA + 1,
BINDSTATUS_PROTOCOLCLASSID=BINDSTATUS_ENDUPLOADDATA + 1,
BINDSTATUS_ENCODING=BINDSTATUS_PROTOCOLCLASSID + 1,
BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE=BINDSTATUS_ENCODING + 1,
BINDSTATUS_CLASSINSTALLLOCATION=BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE + 1,
BINDSTATUS_DECODING=BINDSTATUS_CLASSINSTALLLOCATION + 1,
BINDSTATUS_LOADINGMIMEHANDLER=BINDSTATUS_DECODING + 1,
BINDSTATUS_CONTENTDISPOSITIONATTACH=BINDSTATUS_LOADINGMIMEHANDLER + 1,
BINDSTATUS_FILTERREPORTMIMETYPE=BINDSTATUS_CONTENTDISPOSITIONATTACH + 1,
BINDSTATUS_CLSIDCANINSTANTIATE=BINDSTATUS_FILTERREPORTMIMETYPE + 1,
BINDSTATUS_IUNKNOWNAVAILABLE=BINDSTATUS_CLSIDCANINSTANTIATE + 1,
BINDSTATUS_DIRECTBIND=BINDSTATUS_IUNKNOWNAVAILABLE + 1,
BINDSTATUS_RAWMIMETYPE=BINDSTATUS_DIRECTBIND + 1,
BINDSTATUS_PROXYDETECTING=BINDSTATUS_RAWMIMETYPE + 1,
BINDSTATUS_ACCEPTRANGES=BINDSTATUS_PROXYDETECTING + 1,
BINDSTATUS_COOKIE_SENT=BINDSTATUS_ACCEPTRANGES + 1,
BINDSTATUS_COMPACT_POLICY_RECEIVED=BINDSTATUS_COOKIE_SENT + 1,
BINDSTATUS_COOKIE_SUPPRESSED=BINDSTATUS_COMPACT_POLICY_RECEIVED + 1,
BINDSTATUS_COOKIE_STATE_UNKNOWN=BINDSTATUS_COOKIE_SUPPRESSED + 1,
BINDSTATUS_COOKIE_STATE_ACCEPT=BINDSTATUS_COOKIE_STATE_UNKNOWN + 1,
BINDSTATUS_COOKIE_STATE_REJECT=BINDSTATUS_COOKIE_STATE_ACCEPT + 1,
BINDSTATUS_COOKIE_STATE_PROMPT=BINDSTATUS_COOKIE_STATE_REJECT + 1,
BINDSTATUS_COOKIE_STATE_LEASH=BINDSTATUS_COOKIE_STATE_PROMPT + 1,
BINDSTATUS_COOKIE_STATE_DOWNGRADE=BINDSTATUS_COOKIE_STATE_LEASH + 1,
BINDSTATUS_POLICY_HREF=BINDSTATUS_COOKIE_STATE_DOWNGRADE + 1,
BINDSTATUS_P3P_HEADER=BINDSTATUS_POLICY_HREF + 1,
BINDSTATUS_SESSION_COOKIE_RECEIVED=BINDSTATUS_P3P_HEADER + 1,
BINDSTATUS_PERSISTENT_COOKIE_RECEIVED=BINDSTATUS_SESSION_COOKIE_RECEIVED + 1,
BINDSTATUS_SESSION_COOKIES_ALLOWED=BINDSTATUS_PERSISTENT_COOKIE_RECEIVED + 1,
BINDSTATUS_CACHECONTROL=BINDSTATUS_SESSION_COOKIES_ALLOWED + 1
} BINDSTATUS;
EXTERN_C const IID IID_IBindStatusCallback;
typedef struct IBindStatusCallbackVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IBindStatusCallback *,REFIID,void **);
 ULONG ( *AddRef)(IBindStatusCallback *);
 ULONG ( *Release)(IBindStatusCallback *);
 HRESULT ( *OnStartBinding)(IBindStatusCallback *,DWORD,IBinding *);
 HRESULT ( *GetPriority)(IBindStatusCallback *,LONG *);
 HRESULT ( *OnLowResource)(IBindStatusCallback *,DWORD);
 HRESULT ( *OnProgress)(IBindStatusCallback *,ULONG,ULONG,ULONG,LPCWSTR);
 HRESULT ( *OnStopBinding)(IBindStatusCallback *,HRESULT,LPCWSTR);
 HRESULT ( *GetBindInfo)(IBindStatusCallback *,DWORD *,BINDINFO *);
 HRESULT ( *OnDataAvailable)(IBindStatusCallback *,DWORD,DWORD,FORMATETC *,STGMEDIUM *);
 HRESULT ( *OnObjectAvailable)(IBindStatusCallback *,REFIID,IUnknown *);
END_INTERFACE
} IBindStatusCallbackVtbl;
interface IBindStatusCallback
{
CONST_VTBL struct IBindStatusCallbackVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IBindStatusCallback_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IBindStatusCallback_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IBindStatusCallback_Release(A) (A)->lpVtbl->Release(A)
#define IBindStatusCallback_OnStartBinding(A,B,C) (A)->lpVtbl->OnStartBinding(A,B,C)
#define IBindStatusCallback_GetPriority(A,B) (A)->lpVtbl->GetPriority(A,B)
#define IBindStatusCallback_OnLowResource(A,B) (A)->lpVtbl->OnLowResource(A,B)
#define IBindStatusCallback_OnProgress(A,B,C,D,E) (A)->lpVtbl->OnProgress(A,B,C,D,E)
#define IBindStatusCallback_OnStopBinding(A,B,C) (A)->lpVtbl->OnStopBinding(A,B,C)
#define IBindStatusCallback_GetBindInfo(A,B,C) (A)->lpVtbl->GetBindInfo(A,B,C)
#define IBindStatusCallback_OnDataAvailable(A,B,C,D,E) (A)->lpVtbl->OnDataAvailable(A,B,C,D,E)
#define IBindStatusCallback_OnObjectAvailable(A,B,C) (A)->lpVtbl->OnObjectAvailable(A,B,C)
#endif 
HRESULT IBindStatusCallback_OnStartBinding_Proxy(IBindStatusCallback *,DWORD ,IBinding *);
void __RPC_STUB IBindStatusCallback_OnStartBinding_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindStatusCallback_GetPriority_Proxy(IBindStatusCallback *,LONG *);
void __RPC_STUB IBindStatusCallback_GetPriority_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindStatusCallback_OnLowResource_Proxy(IBindStatusCallback *,DWORD );
void __RPC_STUB IBindStatusCallback_OnLowResource_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindStatusCallback_OnProgress_Proxy(IBindStatusCallback *,ULONG ,ULONG ,ULONG ,LPCWSTR );
void __RPC_STUB IBindStatusCallback_OnProgress_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindStatusCallback_OnStopBinding_Proxy(IBindStatusCallback *,HRESULT ,LPCWSTR );
void __RPC_STUB IBindStatusCallback_OnStopBinding_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindStatusCallback_RemoteGetBindInfo_Proxy(IBindStatusCallback *,DWORD *,RemBINDINFO *,RemSTGMEDIUM *);
void __RPC_STUB IBindStatusCallback_RemoteGetBindInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindStatusCallback_RemoteOnDataAvailable_Proxy(IBindStatusCallback *,DWORD ,DWORD ,RemFORMATETC *,RemSTGMEDIUM *);
void __RPC_STUB IBindStatusCallback_RemoteOnDataAvailable_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindStatusCallback_OnObjectAvailable_Proxy(IBindStatusCallback *,REFIID ,IUnknown *);
void __RPC_STUB IBindStatusCallback_OnObjectAvailable_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPAUTHENTICATION_DEFINED
#define _LPAUTHENTICATION_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0182_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0182_v0_0_s_ifspec;
#ifndef __IAuthenticate_INTERFACE_DEFINED__
#define __IAuthenticate_INTERFACE_DEFINED__
typedef  IAuthenticate *LPAUTHENTICATION;
EXTERN_C const IID IID_IAuthenticate;
typedef struct IAuthenticateVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IAuthenticate *,REFIID,void **);
 ULONG ( *AddRef)(IAuthenticate *);
 ULONG ( *Release)(IAuthenticate *);
 HRESULT ( *Authenticate)(IAuthenticate *,HWND *,LPWSTR *,LPWSTR *);
END_INTERFACE
} IAuthenticateVtbl;
interface IAuthenticate
{
CONST_VTBL struct IAuthenticateVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IAuthenticate_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IAuthenticate_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IAuthenticate_Release(A) (A)->lpVtbl->Release(A)
#define IAuthenticate_Authenticate(A,B,C,D) (A)->lpVtbl->Authenticate(A,B,C,D)
#endif 
HRESULT IAuthenticate_Authenticate_Proxy(IAuthenticate *,HWND *,LPWSTR *,LPWSTR *);
void __RPC_STUB IAuthenticate_Authenticate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPHTTPNEGOTIATE_DEFINED
#define _LPHTTPNEGOTIATE_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0183_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0183_v0_0_s_ifspec;
#ifndef __IHttpNegotiate_INTERFACE_DEFINED__
#define __IHttpNegotiate_INTERFACE_DEFINED__
typedef  IHttpNegotiate *LPHTTPNEGOTIATE;
EXTERN_C const IID IID_IHttpNegotiate;
typedef struct IHttpNegotiateVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IHttpNegotiate *,REFIID,void **);
 ULONG ( *AddRef)(IHttpNegotiate *);
 ULONG ( *Release)(IHttpNegotiate *);
 HRESULT ( *BeginningTransaction)(IHttpNegotiate *,LPCWSTR,LPCWSTR,DWORD,LPWSTR *);
 HRESULT ( *OnResponse)(IHttpNegotiate *,DWORD,LPCWSTR,LPCWSTR,LPWSTR *);
END_INTERFACE
} IHttpNegotiateVtbl;
interface IHttpNegotiate
{
CONST_VTBL struct IHttpNegotiateVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IHttpNegotiate_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IHttpNegotiate_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IHttpNegotiate_Release(A) (A)->lpVtbl->Release(A)
#define IHttpNegotiate_BeginningTransaction(A,B,C,D,E) (A)->lpVtbl->BeginningTransaction(A,B,C,D,E)
#define IHttpNegotiate_OnResponse(A,B,C,D,E) (A)->lpVtbl->OnResponse(A,B,C,D,E)
#endif 
HRESULT IHttpNegotiate_BeginningTransaction_Proxy(IHttpNegotiate *,LPCWSTR ,LPCWSTR ,DWORD ,LPWSTR *);
void __RPC_STUB IHttpNegotiate_BeginningTransaction_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IHttpNegotiate_OnResponse_Proxy(IHttpNegotiate *,DWORD ,LPCWSTR ,LPCWSTR ,LPWSTR *);
void __RPC_STUB IHttpNegotiate_OnResponse_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPHTTPNEGOTIATE2_DEFINED
#define _LPHTTPNEGOTIATE2_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0184_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0184_v0_0_s_ifspec;
#ifndef __IHttpNegotiate2_INTERFACE_DEFINED__
#define __IHttpNegotiate2_INTERFACE_DEFINED__
typedef  IHttpNegotiate2 *LPHTTPNEGOTIATE2;
EXTERN_C const IID IID_IHttpNegotiate2;
typedef struct IHttpNegotiate2Vtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IHttpNegotiate2 *,REFIID,void **);
 ULONG ( *AddRef)(IHttpNegotiate2 *);
 ULONG ( *Release)(IHttpNegotiate2 *);
 HRESULT ( *BeginningTransaction)(IHttpNegotiate2 *,LPCWSTR,LPCWSTR,DWORD,LPWSTR *);
 HRESULT ( *OnResponse)(IHttpNegotiate2 *,DWORD,LPCWSTR,LPCWSTR,LPWSTR *);
 HRESULT ( *GetRootSecurityId)(IHttpNegotiate2 *,BYTE *,DWORD *,DWORD_PTR);
END_INTERFACE
} IHttpNegotiate2Vtbl;
interface IHttpNegotiate2
{
CONST_VTBL struct IHttpNegotiate2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IHttpNegotiate2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IHttpNegotiate2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IHttpNegotiate2_Release(A) (A)->lpVtbl->Release(A)
#define IHttpNegotiate2_BeginningTransaction(A,B,C,D,E) (A)->lpVtbl->BeginningTransaction(A,B,C,D,E)
#define IHttpNegotiate2_OnResponse(A,B,C,D,E) (A)->lpVtbl->OnResponse(A,B,C,D,E)
#define IHttpNegotiate2_GetRootSecurityId(A,B,C,D) (A)->lpVtbl->GetRootSecurityId(A,B,C,D)
#endif 
HRESULT IHttpNegotiate2_GetRootSecurityId_Proxy(IHttpNegotiate2 *,BYTE *,DWORD *,DWORD_PTR );
void __RPC_STUB IHttpNegotiate2_GetRootSecurityId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPWININETFILESTREAM_DEFINED
#define _LPWININETFILESTREAM_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0185_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0185_v0_0_s_ifspec;
#ifndef __IWinInetFileStream_INTERFACE_DEFINED__
#define __IWinInetFileStream_INTERFACE_DEFINED__
typedef  IWinInetFileStream *LPWININETFILESTREAM;
EXTERN_C const IID IID_IWinInetFileStream;
typedef struct IWinInetFileStreamVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IWinInetFileStream *,REFIID,void **);
 ULONG ( *AddRef)(IWinInetFileStream *);
 ULONG ( *Release)(IWinInetFileStream *);
 HRESULT ( *SetHandleForUnlock)(IWinInetFileStream *,DWORD_PTR,DWORD_PTR);
 HRESULT ( *SetDeleteFile)(IWinInetFileStream *,DWORD_PTR);
END_INTERFACE
} IWinInetFileStreamVtbl;
interface IWinInetFileStream
{
CONST_VTBL struct IWinInetFileStreamVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWinInetFileStream_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWinInetFileStream_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWinInetFileStream_Release(A) (A)->lpVtbl->Release(A)
#define IWinInetFileStream_SetHandleForUnlock(A,B,C) (A)->lpVtbl->SetHandleForUnlock(A,B,C)
#define IWinInetFileStream_SetDeleteFile(A,B) (A)->lpVtbl->SetDeleteFile(A,B)
#endif 
HRESULT IWinInetFileStream_SetHandleForUnlock_Proxy(IWinInetFileStream *,DWORD_PTR ,DWORD_PTR );
void __RPC_STUB IWinInetFileStream_SetHandleForUnlock_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWinInetFileStream_SetDeleteFile_Proxy(IWinInetFileStream *,DWORD_PTR );
void __RPC_STUB IWinInetFileStream_SetDeleteFile_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPWINDOWFORBINDINGUI_DEFINED
#define _LPWINDOWFORBINDINGUI_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0186_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0186_v0_0_s_ifspec;
#ifndef __IWindowForBindingUI_INTERFACE_DEFINED__
#define __IWindowForBindingUI_INTERFACE_DEFINED__
typedef  IWindowForBindingUI *LPWINDOWFORBINDINGUI;
EXTERN_C const IID IID_IWindowForBindingUI;
typedef struct IWindowForBindingUIVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IWindowForBindingUI *,REFIID,void **);
 ULONG ( *AddRef)(IWindowForBindingUI *);
 ULONG ( *Release)(IWindowForBindingUI *);
 HRESULT ( *GetWindow)(IWindowForBindingUI *,REFGUID,HWND *);
END_INTERFACE
} IWindowForBindingUIVtbl;
interface IWindowForBindingUI
{
CONST_VTBL struct IWindowForBindingUIVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWindowForBindingUI_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWindowForBindingUI_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWindowForBindingUI_Release(A) (A)->lpVtbl->Release(A)
#define IWindowForBindingUI_GetWindow(A,B,C) (A)->lpVtbl->GetWindow(A,B,C)
#endif 
HRESULT IWindowForBindingUI_GetWindow_Proxy(IWindowForBindingUI *,REFGUID ,HWND *);
void __RPC_STUB IWindowForBindingUI_GetWindow_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPCODEINSTALL_DEFINED
#define _LPCODEINSTALL_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0187_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0187_v0_0_s_ifspec;
#ifndef __ICodeInstall_INTERFACE_DEFINED__
#define __ICodeInstall_INTERFACE_DEFINED__
typedef  ICodeInstall *LPCODEINSTALL;
typedef  
enum __MIDL_ICodeInstall_0001
{	CIP_DISK_FULL=0,
CIP_ACCESS_DENIED=CIP_DISK_FULL + 1,
CIP_NEWER_VERSION_EXISTS=CIP_ACCESS_DENIED + 1,
CIP_OLDER_VERSION_EXISTS=CIP_NEWER_VERSION_EXISTS + 1,
CIP_NAME_CONFLICT=CIP_OLDER_VERSION_EXISTS + 1,
CIP_TRUST_VERIFICATION_COMPONENT_MISSING=CIP_NAME_CONFLICT + 1,
CIP_EXE_SELF_REGISTERATION_TIMEOUT=CIP_TRUST_VERIFICATION_COMPONENT_MISSING + 1,
CIP_UNSAFE_TO_ABORT=CIP_EXE_SELF_REGISTERATION_TIMEOUT + 1,
CIP_NEED_REBOOT=CIP_UNSAFE_TO_ABORT + 1
} CIP_STATUS;
EXTERN_C const IID IID_ICodeInstall;
typedef struct ICodeInstallVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(ICodeInstall *,REFIID,void **);
 ULONG ( *AddRef)(ICodeInstall *);
 ULONG ( *Release)(ICodeInstall *);
 HRESULT ( *GetWindow)(ICodeInstall *,REFGUID,HWND *);
 HRESULT ( *OnCodeInstallProblem)(ICodeInstall *,ULONG,LPCWSTR,LPCWSTR,DWORD);
END_INTERFACE
} ICodeInstallVtbl;
interface ICodeInstall
{
CONST_VTBL struct ICodeInstallVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICodeInstall_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICodeInstall_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICodeInstall_Release(A) (A)->lpVtbl->Release(A)
#define ICodeInstall_GetWindow(A,B,C) (A)->lpVtbl->GetWindow(A,B,C)
#define ICodeInstall_OnCodeInstallProblem(A,B,C,D,E) (A)->lpVtbl->OnCodeInstallProblem(A,B,C,D,E)
#endif 
HRESULT ICodeInstall_OnCodeInstallProblem_Proxy(ICodeInstall *,ULONG ,LPCWSTR ,LPCWSTR ,DWORD );
void __RPC_STUB ICodeInstall_OnCodeInstallProblem_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPWININETINFO_DEFINED
#define _LPWININETINFO_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0188_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0188_v0_0_s_ifspec;
#ifndef __IWinInetInfo_INTERFACE_DEFINED__
#define __IWinInetInfo_INTERFACE_DEFINED__
typedef  IWinInetInfo *LPWININETINFO;
EXTERN_C const IID IID_IWinInetInfo;
typedef struct IWinInetInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IWinInetInfo *,REFIID,void **);
 ULONG ( *AddRef)(IWinInetInfo *);
 ULONG ( *Release)(IWinInetInfo *);
 HRESULT ( *QueryOption)(IWinInetInfo *,DWORD,LPVOID,DWORD *);
END_INTERFACE
} IWinInetInfoVtbl;
interface IWinInetInfo
{
CONST_VTBL struct IWinInetInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWinInetInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWinInetInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWinInetInfo_Release(A) (A)->lpVtbl->Release(A)
#define IWinInetInfo_QueryOption(A,B,C,D) (A)->lpVtbl->QueryOption(A,B,C,D)
#endif 
HRESULT IWinInetInfo_RemoteQueryOption_Proxy(IWinInetInfo *,DWORD ,BYTE *,DWORD *);
void __RPC_STUB IWinInetInfo_RemoteQueryOption_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#define WININETINFO_OPTION_LOCK_HANDLE 65534
#ifndef _LPHTTPSECURITY_DEFINED
#define _LPHTTPSECURITY_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0189_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0189_v0_0_s_ifspec;
#ifndef __IHttpSecurity_INTERFACE_DEFINED__
#define __IHttpSecurity_INTERFACE_DEFINED__
typedef  IHttpSecurity *LPHTTPSECURITY;
EXTERN_C const IID IID_IHttpSecurity;
typedef struct IHttpSecurityVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IHttpSecurity *,REFIID,void **);
 ULONG ( *AddRef)(IHttpSecurity *);
 ULONG ( *Release)(IHttpSecurity *);
 HRESULT ( *GetWindow)(IHttpSecurity *,REFGUID,HWND *);
 HRESULT ( *OnSecurityProblem)(IHttpSecurity *,DWORD);
END_INTERFACE
} IHttpSecurityVtbl;
interface IHttpSecurity
{
CONST_VTBL struct IHttpSecurityVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IHttpSecurity_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IHttpSecurity_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IHttpSecurity_Release(A) (A)->lpVtbl->Release(A)
#define IHttpSecurity_GetWindow(A,B,C) (A)->lpVtbl->GetWindow(A,B,C)
#define IHttpSecurity_OnSecurityProblem(A,B) (A)->lpVtbl->OnSecurityProblem(A,B)
#endif 
HRESULT IHttpSecurity_OnSecurityProblem_Proxy(IHttpSecurity *,DWORD );
void __RPC_STUB IHttpSecurity_OnSecurityProblem_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPWININETHTTPINFO_DEFINED
#define _LPWININETHTTPINFO_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0190_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0190_v0_0_s_ifspec;
#ifndef __IWinInetHttpInfo_INTERFACE_DEFINED__
#define __IWinInetHttpInfo_INTERFACE_DEFINED__
typedef  IWinInetHttpInfo *LPWININETHTTPINFO;
EXTERN_C const IID IID_IWinInetHttpInfo;
typedef struct IWinInetHttpInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IWinInetHttpInfo *,REFIID,void **);
 ULONG ( *AddRef)(IWinInetHttpInfo *);
 ULONG ( *Release)(IWinInetHttpInfo *);
 HRESULT ( *QueryOption)(IWinInetHttpInfo *,DWORD,LPVOID,DWORD *);
 HRESULT ( *QueryInfo)(IWinInetHttpInfo *,DWORD,LPVOID,DWORD *,DWORD *,DWORD *);
END_INTERFACE
} IWinInetHttpInfoVtbl;
interface IWinInetHttpInfo
{
CONST_VTBL struct IWinInetHttpInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWinInetHttpInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWinInetHttpInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWinInetHttpInfo_Release(A) (A)->lpVtbl->Release(A)
#define IWinInetHttpInfo_QueryOption(A,B,C,D) (A)->lpVtbl->QueryOption(A,B,C,D)
#define IWinInetHttpInfo_QueryInfo(A,B,C,D,E,F) (A)->lpVtbl->QueryInfo(A,B,C,D,E,F)
#endif 
HRESULT IWinInetHttpInfo_RemoteQueryInfo_Proxy(IWinInetHttpInfo *,DWORD ,BYTE *,DWORD *,DWORD *,DWORD *);
void __RPC_STUB IWinInetHttpInfo_RemoteQueryInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#define SID_IBindHost IID_IBindHost
#define SID_SBindHost IID_IBindHost
#ifndef _LPBINDHOST_DEFINED
#define _LPBINDHOST_DEFINED
EXTERN_C const GUID SID_BindHost;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0191_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0191_v0_0_s_ifspec;
#ifndef __IBindHost_INTERFACE_DEFINED__
#define __IBindHost_INTERFACE_DEFINED__
typedef  IBindHost *LPBINDHOST;
EXTERN_C const IID IID_IBindHost;
typedef struct IBindHostVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IBindHost *,REFIID,void **);
 ULONG ( *AddRef)(IBindHost *);
 ULONG ( *Release)(IBindHost *);
 HRESULT ( *CreateMoniker)(IBindHost *,LPOLESTR,IBindCtx *,IMoniker **,DWORD);
 HRESULT ( *MonikerBindToStorage)(IBindHost *,IMoniker *,IBindCtx *,IBindStatusCallback *,REFIID,void **);
 HRESULT ( *MonikerBindToObject)(IBindHost *,IMoniker *,IBindCtx *,IBindStatusCallback *,REFIID,void **);
END_INTERFACE
} IBindHostVtbl;
interface IBindHost
{
CONST_VTBL struct IBindHostVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IBindHost_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IBindHost_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IBindHost_Release(A) (A)->lpVtbl->Release(A)
#define IBindHost_CreateMoniker(A,B,C,D,E) (A)->lpVtbl->CreateMoniker(A,B,C,D,E)
#define IBindHost_MonikerBindToStorage(A,B,C,D,E,F) (A)->lpVtbl->MonikerBindToStorage(A,B,C,D,E,F)
#define IBindHost_MonikerBindToObject(A,B,C,D,E,F) (A)->lpVtbl->MonikerBindToObject(A,B,C,D,E,F)
#endif 
HRESULT IBindHost_CreateMoniker_Proxy(IBindHost *,LPOLESTR ,IBindCtx *,IMoniker **,DWORD );
void __RPC_STUB IBindHost_CreateMoniker_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindHost_RemoteMonikerBindToStorage_Proxy(IBindHost *,IMoniker *,IBindCtx *,IBindStatusCallback *,REFIID ,IUnknown **);
void __RPC_STUB IBindHost_RemoteMonikerBindToStorage_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IBindHost_RemoteMonikerBindToObject_Proxy(IBindHost *,IMoniker *,IBindCtx *,IBindStatusCallback *,REFIID ,IUnknown **);
void __RPC_STUB IBindHost_RemoteMonikerBindToObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#define URLOSTRM_USECACHEDCOPY_ONLY 1
#define URLOSTRM_USECACHEDCOPY 2
#define URLOSTRM_GETNEWESTVERSION 3
struct IBindStatusCallback; 
STDAPI HlinkSimpleNavigateToString(LPCWSTR ,LPCWSTR ,LPCWSTR ,IUnknown *,IBindCtx *,IBindStatusCallback *,DWORD ,DWORD dwReserved  ); 
STDAPI HlinkSimpleNavigateToMoniker(IMoniker *,LPCWSTR ,LPCWSTR ,IUnknown *,IBindCtx *,IBindStatusCallback *,DWORD ,DWORD dwReserved  ); 
STDAPI URLOpenStreamA(LPUNKNOWN,LPCSTR,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLOpenStreamW(LPUNKNOWN,LPCWSTR,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLOpenPullStreamA(LPUNKNOWN,LPCSTR,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLOpenPullStreamW(LPUNKNOWN,LPCWSTR,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLDownloadToFileA(LPUNKNOWN,LPCSTR,LPCSTR,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLDownloadToFileW(LPUNKNOWN,LPCWSTR,LPCWSTR,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLDownloadToCacheFileA(LPUNKNOWN,LPCSTR,LPTSTR,DWORD,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLDownloadToCacheFileW(LPUNKNOWN,LPCWSTR,LPWSTR,DWORD,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLOpenBlockingStreamA(LPUNKNOWN,LPCSTR,LPSTREAM*,DWORD,LPBINDSTATUSCALLBACK); 
STDAPI URLOpenBlockingStreamW(LPUNKNOWN,LPCWSTR,LPSTREAM*,DWORD,LPBINDSTATUSCALLBACK); 
#ifdef UNICODE 
#define URLOpenStream URLOpenStreamW 
#define URLOpenPullStream URLOpenPullStreamW 
#define URLDownloadToFile URLDownloadToFileW 
#define URLDownloadToCacheFile URLDownloadToCacheFileW 
#define URLOpenBlockingStream URLOpenBlockingStreamW 
#else 
#define URLOpenStream URLOpenStreamA 
#define URLOpenPullStream URLOpenPullStreamA 
#define URLDownloadToFile URLDownloadToFileA 
#define URLDownloadToCacheFile URLDownloadToCacheFileA 
#define URLOpenBlockingStream URLOpenBlockingStreamA 
#endif 
STDAPI HlinkGoBack(IUnknown *); 
STDAPI HlinkGoForward(IUnknown *); 
STDAPI HlinkNavigateString(IUnknown *,LPCWSTR ); 
STDAPI HlinkNavigateMoniker(IUnknown *,IMoniker *); 
#ifndef _URLMON_NO_ASYNC_PLUGABLE_PROTOCOLS_ 
#ifndef _LPIINTERNET
#define _LPIINTERNET
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0192_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0192_v0_0_s_ifspec;
#ifndef __IInternet_INTERFACE_DEFINED__
#define __IInternet_INTERFACE_DEFINED__
typedef  IInternet *LPIINTERNET;
EXTERN_C const IID IID_IInternet;
typedef struct IInternetVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternet *,REFIID,void **);
 ULONG ( *AddRef)(IInternet *);
 ULONG ( *Release)(IInternet *);
END_INTERFACE
} IInternetVtbl;
interface IInternet
{
CONST_VTBL struct IInternetVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternet_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternet_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternet_Release(A) (A)->lpVtbl->Release(A)
#endif 
#endif 
#endif
#ifndef _LPIINTERNETBINDINFO
#define _LPIINTERNETBINDINFO
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0193_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0193_v0_0_s_ifspec;
#ifndef __IInternetBindInfo_INTERFACE_DEFINED__
#define __IInternetBindInfo_INTERFACE_DEFINED__
typedef  IInternetBindInfo *LPIINTERNETBINDINFO;
typedef 
enum tagBINDSTRING
{	BINDSTRING_HEADERS=1,
BINDSTRING_ACCEPT_MIMES=BINDSTRING_HEADERS + 1,
BINDSTRING_EXTRA_URL=BINDSTRING_ACCEPT_MIMES + 1,
BINDSTRING_LANGUAGE=BINDSTRING_EXTRA_URL + 1,
BINDSTRING_USERNAME=BINDSTRING_LANGUAGE + 1,
BINDSTRING_PASSWORD=BINDSTRING_USERNAME + 1,
BINDSTRING_UA_PIXELS=BINDSTRING_PASSWORD + 1,
BINDSTRING_UA_COLOR=BINDSTRING_UA_PIXELS + 1,
BINDSTRING_OS=BINDSTRING_UA_COLOR + 1,
BINDSTRING_USER_AGENT=BINDSTRING_OS + 1,
BINDSTRING_ACCEPT_ENCODINGS=BINDSTRING_USER_AGENT + 1,
BINDSTRING_POST_COOKIE=BINDSTRING_ACCEPT_ENCODINGS + 1,
BINDSTRING_POST_DATA_MIME=BINDSTRING_POST_COOKIE + 1,
BINDSTRING_URL=BINDSTRING_POST_DATA_MIME + 1,
BINDSTRING_IID=BINDSTRING_URL + 1,
BINDSTRING_FLAG_BIND_TO_OBJECT=BINDSTRING_IID + 1,
BINDSTRING_PTR_BIND_CONTEXT=BINDSTRING_FLAG_BIND_TO_OBJECT + 1
} BINDSTRING;
EXTERN_C const IID IID_IInternetBindInfo;
typedef struct IInternetBindInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetBindInfo *,REFIID,void **);
 ULONG ( *AddRef)(IInternetBindInfo *);
 ULONG ( *Release)(IInternetBindInfo *);
 HRESULT ( *GetBindInfo)(IInternetBindInfo *,DWORD *,BINDINFO *);
 HRESULT ( *GetBindString)(IInternetBindInfo *,ULONG,LPOLESTR *,ULONG,ULONG *);
END_INTERFACE
} IInternetBindInfoVtbl;
interface IInternetBindInfo
{
CONST_VTBL struct IInternetBindInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetBindInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetBindInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetBindInfo_Release(A) (A)->lpVtbl->Release(A)
#define IInternetBindInfo_GetBindInfo(A,B,C) (A)->lpVtbl->GetBindInfo(A,B,C)
#define IInternetBindInfo_GetBindString(A,B,C,D,E) (A)->lpVtbl->GetBindString(A,B,C,D,E)
#endif 
HRESULT IInternetBindInfo_GetBindInfo_Proxy(IInternetBindInfo *,DWORD *,BINDINFO *);
void __RPC_STUB IInternetBindInfo_GetBindInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetBindInfo_GetBindString_Proxy(IInternetBindInfo *,ULONG ,LPOLESTR *,ULONG ,ULONG *);
void __RPC_STUB IInternetBindInfo_GetBindString_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPIINTERNETPROTOCOLROOT_DEFINED
#define _LPIINTERNETPROTOCOLROOT_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0194_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0194_v0_0_s_ifspec;
#ifndef __IInternetProtocolRoot_INTERFACE_DEFINED__
#define __IInternetProtocolRoot_INTERFACE_DEFINED__
typedef  IInternetProtocolRoot *LPIINTERNETPROTOCOLROOT;
typedef 
enum _tagPI_FLAGS
{	PI_PARSE_URL=1,
PI_FILTER_MODE=2,
PI_FORCE_ASYNC=4,
PI_USE_WORKERTHREAD=8,
PI_MIMEVERIFICATION=16,
PI_CLSIDLOOKUP=32,
PI_DATAPROGRESS=64,
PI_SYNCHRONOUS=128,
PI_APARTMENTTHREADED=256,
PI_CLASSINSTALL=512,
PI_PASSONBINDCTX=0x2000,
PI_NOMIMEHANDLER=0x8000,
PI_LOADAPPDIRECT=0x4000,
PD_FORCE_SWITCH=0x10000,
PI_PREFERDEFAULTHANDLER=0x20000
} PI_FLAGS;
typedef struct _tagPROTOCOLDATA
{
DWORD grfFlags;
DWORD dwState;
LPVOID pData;
ULONG cbData;
} PROTOCOLDATA;
typedef struct _tagStartParam
{
IID iid;
IBindCtx *pIBindCtx;
IUnknown *pItf;
} StartParam;
EXTERN_C const IID IID_IInternetProtocolRoot;
typedef struct IInternetProtocolRootVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetProtocolRoot *,REFIID,void **);
 ULONG ( *AddRef)(IInternetProtocolRoot *);
 ULONG ( *Release)(IInternetProtocolRoot *);
 HRESULT ( *Start)(IInternetProtocolRoot *,LPCWSTR,IInternetProtocolSink *,IInternetBindInfo *,DWORD,HANDLE_PTR);
 HRESULT ( *Continue)(IInternetProtocolRoot *,PROTOCOLDATA *);
 HRESULT ( *Abort)(IInternetProtocolRoot *,HRESULT,DWORD);
 HRESULT ( *Terminate)(IInternetProtocolRoot *,DWORD);
 HRESULT ( *Suspend)(IInternetProtocolRoot *);
 HRESULT ( *Resume)(IInternetProtocolRoot *);
END_INTERFACE
} IInternetProtocolRootVtbl;
interface IInternetProtocolRoot
{
CONST_VTBL struct IInternetProtocolRootVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetProtocolRoot_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetProtocolRoot_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetProtocolRoot_Release(A) (A)->lpVtbl->Release(A)
#define IInternetProtocolRoot_Start(A,B,C,D,E,F) (A)->lpVtbl->Start(A,B,C,D,E,F)
#define IInternetProtocolRoot_Continue(A,B) (A)->lpVtbl->Continue(A,B)
#define IInternetProtocolRoot_Abort(A,B,C) (A)->lpVtbl->Abort(A,B,C)
#define IInternetProtocolRoot_Terminate(A,B) (A)->lpVtbl->Terminate(A,B)
#define IInternetProtocolRoot_Suspend(A) (A)->lpVtbl->Suspend(A)
#define IInternetProtocolRoot_Resume(A) (A)->lpVtbl->Resume(A)
#endif 
HRESULT IInternetProtocolRoot_Start_Proxy(IInternetProtocolRoot *,LPCWSTR ,IInternetProtocolSink *,IInternetBindInfo *,DWORD ,HANDLE_PTR );
void __RPC_STUB IInternetProtocolRoot_Start_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolRoot_Continue_Proxy(IInternetProtocolRoot *,PROTOCOLDATA *);
void __RPC_STUB IInternetProtocolRoot_Continue_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolRoot_Abort_Proxy(IInternetProtocolRoot *,HRESULT ,DWORD );
void __RPC_STUB IInternetProtocolRoot_Abort_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolRoot_Terminate_Proxy(IInternetProtocolRoot *,DWORD );
void __RPC_STUB IInternetProtocolRoot_Terminate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolRoot_Suspend_Proxy(IInternetProtocolRoot *);
void __RPC_STUB IInternetProtocolRoot_Suspend_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolRoot_Resume_Proxy(IInternetProtocolRoot *);
void __RPC_STUB IInternetProtocolRoot_Resume_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPIINTERNETPROTOCOL_DEFINED
#define _LPIINTERNETPROTOCOL_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0195_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0195_v0_0_s_ifspec;
#ifndef __IInternetProtocol_INTERFACE_DEFINED__
#define __IInternetProtocol_INTERFACE_DEFINED__
typedef  IInternetProtocol *LPIINTERNETPROTOCOL;
EXTERN_C const IID IID_IInternetProtocol;
typedef struct IInternetProtocolVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetProtocol *,REFIID,void **);
 ULONG ( *AddRef)(IInternetProtocol *);
 ULONG ( *Release)(IInternetProtocol *);
 HRESULT ( *Start)(IInternetProtocol *,LPCWSTR,IInternetProtocolSink *,IInternetBindInfo *,DWORD,HANDLE_PTR);
 HRESULT ( *Continue)(IInternetProtocol *,PROTOCOLDATA *);
 HRESULT ( *Abort)(IInternetProtocol *,HRESULT,DWORD);
 HRESULT ( *Terminate)(IInternetProtocol *,DWORD);
 HRESULT ( *Suspend)(IInternetProtocol *);
 HRESULT ( *Resume)(IInternetProtocol *);
 HRESULT ( *Read)(IInternetProtocol *,void *,ULONG,ULONG *);
 HRESULT ( *Seek)(IInternetProtocol *,LARGE_INTEGER,DWORD,ULARGE_INTEGER *);
 HRESULT ( *LockRequest)(IInternetProtocol *,DWORD);
 HRESULT ( *UnlockRequest)(IInternetProtocol *);
END_INTERFACE
} IInternetProtocolVtbl;
interface IInternetProtocol
{
CONST_VTBL struct IInternetProtocolVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetProtocol_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetProtocol_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetProtocol_Release(A) (A)->lpVtbl->Release(A)
#define IInternetProtocol_Start(A,B,C,D,E,F) (A)->lpVtbl->Start(A,B,C,D,E,F)
#define IInternetProtocol_Continue(A,B) (A)->lpVtbl->Continue(A,B)
#define IInternetProtocol_Abort(A,B,C) (A)->lpVtbl->Abort(A,B,C)
#define IInternetProtocol_Terminate(A,B) (A)->lpVtbl->Terminate(A,B)
#define IInternetProtocol_Suspend(A) (A)->lpVtbl->Suspend(A)
#define IInternetProtocol_Resume(A) (A)->lpVtbl->Resume(A)
#define IInternetProtocol_Read(A,B,C,D) (A)->lpVtbl->Read(A,B,C,D)
#define IInternetProtocol_Seek(A,B,C,D) (A)->lpVtbl->Seek(A,B,C,D)
#define IInternetProtocol_LockRequest(A,B) (A)->lpVtbl->LockRequest(A,B)
#define IInternetProtocol_UnlockRequest(A) (A)->lpVtbl->UnlockRequest(A)
#endif 
HRESULT IInternetProtocol_Read_Proxy(IInternetProtocol *,void *,ULONG ,ULONG *);
void __RPC_STUB IInternetProtocol_Read_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocol_Seek_Proxy(IInternetProtocol *,LARGE_INTEGER ,DWORD ,ULARGE_INTEGER *);
void __RPC_STUB IInternetProtocol_Seek_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocol_LockRequest_Proxy(IInternetProtocol *,DWORD );
void __RPC_STUB IInternetProtocol_LockRequest_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocol_UnlockRequest_Proxy(IInternetProtocol *);
void __RPC_STUB IInternetProtocol_UnlockRequest_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPIINTERNETPROTOCOLSINK_DEFINED
#define _LPIINTERNETPROTOCOLSINK_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0196_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0196_v0_0_s_ifspec;
#ifndef __IInternetProtocolSink_INTERFACE_DEFINED__
#define __IInternetProtocolSink_INTERFACE_DEFINED__
typedef  IInternetProtocolSink *LPIINTERNETPROTOCOLSINK;
EXTERN_C const IID IID_IInternetProtocolSink;
typedef struct IInternetProtocolSinkVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetProtocolSink *,REFIID,void **);
 ULONG ( *AddRef)(IInternetProtocolSink *);
 ULONG ( *Release)(IInternetProtocolSink *);
 HRESULT ( *Switch)(IInternetProtocolSink *,PROTOCOLDATA *);
 HRESULT ( *ReportProgress)(IInternetProtocolSink *,ULONG,LPCWSTR);
 HRESULT ( *ReportData)(IInternetProtocolSink *,DWORD,ULONG,ULONG);
 HRESULT ( *ReportResult)(IInternetProtocolSink *,HRESULT,DWORD,LPCWSTR);
END_INTERFACE
} IInternetProtocolSinkVtbl;
interface IInternetProtocolSink
{
CONST_VTBL struct IInternetProtocolSinkVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetProtocolSink_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetProtocolSink_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetProtocolSink_Release(A) (A)->lpVtbl->Release(A)
#define IInternetProtocolSink_Switch(A,B) (A)->lpVtbl->Switch(A,B)
#define IInternetProtocolSink_ReportProgress(A,B,C) (A)->lpVtbl->ReportProgress(A,B,C)
#define IInternetProtocolSink_ReportData(A,B,C,D) (A)->lpVtbl->ReportData(A,B,C,D)
#define IInternetProtocolSink_ReportResult(A,B,C,D) (A)->lpVtbl->ReportResult(A,B,C,D)
#endif 
HRESULT IInternetProtocolSink_Switch_Proxy(IInternetProtocolSink *,PROTOCOLDATA *);
void __RPC_STUB IInternetProtocolSink_Switch_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolSink_ReportProgress_Proxy(IInternetProtocolSink *,ULONG ,LPCWSTR );
void __RPC_STUB IInternetProtocolSink_ReportProgress_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolSink_ReportData_Proxy(IInternetProtocolSink *,DWORD ,ULONG ,ULONG );
void __RPC_STUB IInternetProtocolSink_ReportData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolSink_ReportResult_Proxy(IInternetProtocolSink *,HRESULT ,DWORD ,LPCWSTR );
void __RPC_STUB IInternetProtocolSink_ReportResult_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPIINTERNETPROTOCOLSINKSTACKABLE_DEFINED
#define _LPIINTERNETPROTOCOLSINKSTACKABLE_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0197_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0197_v0_0_s_ifspec;
#ifndef __IInternetProtocolSinkStackable_INTERFACE_DEFINED__
#define __IInternetProtocolSinkStackable_INTERFACE_DEFINED__
typedef  IInternetProtocolSinkStackable *LPIINTERNETPROTOCOLSINKStackable;
EXTERN_C const IID IID_IInternetProtocolSinkStackable;
typedef struct IInternetProtocolSinkStackableVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetProtocolSinkStackable *,REFIID,void **);
 ULONG ( *AddRef)(IInternetProtocolSinkStackable *);
 ULONG ( *Release)(IInternetProtocolSinkStackable *);
 HRESULT ( *SwitchSink)(IInternetProtocolSinkStackable *,IInternetProtocolSink *);
 HRESULT ( *CommitSwitch)(IInternetProtocolSinkStackable *);
 HRESULT ( *RollbackSwitch)(IInternetProtocolSinkStackable *);
END_INTERFACE
} IInternetProtocolSinkStackableVtbl;
interface IInternetProtocolSinkStackable
{
CONST_VTBL struct IInternetProtocolSinkStackableVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetProtocolSinkStackable_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetProtocolSinkStackable_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetProtocolSinkStackable_Release(A) (A)->lpVtbl->Release(A)
#define IInternetProtocolSinkStackable_SwitchSink(A,B) (A)->lpVtbl->SwitchSink(A,B)
#define IInternetProtocolSinkStackable_CommitSwitch(A) (A)->lpVtbl->CommitSwitch(A)
#define IInternetProtocolSinkStackable_RollbackSwitch(A) (A)->lpVtbl->RollbackSwitch(A)
#endif 
HRESULT IInternetProtocolSinkStackable_SwitchSink_Proxy(IInternetProtocolSinkStackable *,IInternetProtocolSink *);
void __RPC_STUB IInternetProtocolSinkStackable_SwitchSink_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolSinkStackable_CommitSwitch_Proxy(IInternetProtocolSinkStackable *);
void __RPC_STUB IInternetProtocolSinkStackable_CommitSwitch_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolSinkStackable_RollbackSwitch_Proxy(IInternetProtocolSinkStackable *);
void __RPC_STUB IInternetProtocolSinkStackable_RollbackSwitch_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPIINTERNETSESSION_DEFINED
#define _LPIINTERNETSESSION_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0198_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0198_v0_0_s_ifspec;
#ifndef __IInternetSession_INTERFACE_DEFINED__
#define __IInternetSession_INTERFACE_DEFINED__
typedef  IInternetSession *LPIINTERNETSESSION;
typedef 
enum _tagOIBDG_FLAGS
{	OIBDG_APARTMENTTHREADED=256,
OIBDG_DATAONLY=4096
} OIBDG_FLAGS;
EXTERN_C const IID IID_IInternetSession;
typedef struct IInternetSessionVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetSession *,REFIID,void **);
 ULONG ( *AddRef)(IInternetSession *);
 ULONG ( *Release)(IInternetSession *);
 HRESULT ( *RegisterNameSpace)(IInternetSession *,IClassFactory *,REFCLSID,LPCWSTR,ULONG,const LPCWSTR *,DWORD);
 HRESULT ( *UnregisterNameSpace)(IInternetSession *,IClassFactory *,LPCWSTR);
 HRESULT ( *RegisterMimeFilter)(IInternetSession *,IClassFactory *,REFCLSID,LPCWSTR);
 HRESULT ( *UnregisterMimeFilter)(IInternetSession *,IClassFactory *,LPCWSTR);
 HRESULT ( *CreateBinding)(IInternetSession *,LPBC,LPCWSTR,IUnknown *,IUnknown **,IInternetProtocol **,DWORD);
 HRESULT ( *SetSessionOption)(IInternetSession *,DWORD,LPVOID,DWORD,DWORD);
 HRESULT ( *GetSessionOption)(IInternetSession *,DWORD,LPVOID,DWORD *,DWORD);
END_INTERFACE
} IInternetSessionVtbl;
interface IInternetSession
{
CONST_VTBL struct IInternetSessionVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetSession_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetSession_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetSession_Release(A) (A)->lpVtbl->Release(A)
#define IInternetSession_RegisterNameSpace(A,B,C,D,E,F,G) (A)->lpVtbl->RegisterNameSpace(A,B,C,D,E,F,G)
#define IInternetSession_UnregisterNameSpace(A,B,C) (A)->lpVtbl->UnregisterNameSpace(A,B,C)
#define IInternetSession_RegisterMimeFilter(A,B,C,D) (A)->lpVtbl->RegisterMimeFilter(A,B,C,D)
#define IInternetSession_UnregisterMimeFilter(A,B,C) (A)->lpVtbl->UnregisterMimeFilter(A,B,C)
#define IInternetSession_CreateBinding(A,B,C,D,E,F,G) (A)->lpVtbl->CreateBinding(A,B,C,D,E,F,G)
#define IInternetSession_SetSessionOption(A,B,C,D,E) (A)->lpVtbl->SetSessionOption(A,B,C,D,E)
#define IInternetSession_GetSessionOption(A,B,C,D,E) (A)->lpVtbl->GetSessionOption(A,B,C,D,E)
#endif 
HRESULT IInternetSession_RegisterNameSpace_Proxy(IInternetSession *,IClassFactory *,REFCLSID ,LPCWSTR ,ULONG ,const LPCWSTR *ppwzPatterns,DWORD );
void __RPC_STUB IInternetSession_RegisterNameSpace_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSession_UnregisterNameSpace_Proxy(IInternetSession *,IClassFactory *,LPCWSTR );
void __RPC_STUB IInternetSession_UnregisterNameSpace_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSession_RegisterMimeFilter_Proxy(IInternetSession *,IClassFactory *,REFCLSID ,LPCWSTR );
void __RPC_STUB IInternetSession_RegisterMimeFilter_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSession_UnregisterMimeFilter_Proxy(IInternetSession *,IClassFactory *,LPCWSTR );
void __RPC_STUB IInternetSession_UnregisterMimeFilter_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSession_CreateBinding_Proxy(IInternetSession *,LPBC ,LPCWSTR ,IUnknown *,IUnknown **,IInternetProtocol **,DWORD );
void __RPC_STUB IInternetSession_CreateBinding_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSession_SetSessionOption_Proxy(IInternetSession *,DWORD ,LPVOID ,DWORD ,DWORD );
void __RPC_STUB IInternetSession_SetSessionOption_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSession_GetSessionOption_Proxy(IInternetSession *,DWORD ,LPVOID ,DWORD *,DWORD );
void __RPC_STUB IInternetSession_GetSessionOption_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPIINTERNETTHREADSWITCH_DEFINED
#define _LPIINTERNETTHREADSWITCH_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0199_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0199_v0_0_s_ifspec;
#ifndef __IInternetThreadSwitch_INTERFACE_DEFINED__
#define __IInternetThreadSwitch_INTERFACE_DEFINED__
typedef  IInternetThreadSwitch *LPIINTERNETTHREADSWITCH;
EXTERN_C const IID IID_IInternetThreadSwitch;
typedef struct IInternetThreadSwitchVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetThreadSwitch *,REFIID,void **);
 ULONG ( *AddRef)(IInternetThreadSwitch *);
 ULONG ( *Release)(IInternetThreadSwitch *);
 HRESULT ( *Prepare)(IInternetThreadSwitch *);
 HRESULT ( *Continue)(IInternetThreadSwitch *);
END_INTERFACE
} IInternetThreadSwitchVtbl;
interface IInternetThreadSwitch
{
CONST_VTBL struct IInternetThreadSwitchVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetThreadSwitch_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetThreadSwitch_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetThreadSwitch_Release(A) (A)->lpVtbl->Release(A)
#define IInternetThreadSwitch_Prepare(A) (A)->lpVtbl->Prepare(A)
#define IInternetThreadSwitch_Continue(A) (A)->lpVtbl->Continue(A)
#endif 
HRESULT IInternetThreadSwitch_Prepare_Proxy(IInternetThreadSwitch *);
void __RPC_STUB IInternetThreadSwitch_Prepare_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetThreadSwitch_Continue_Proxy(IInternetThreadSwitch *);
void __RPC_STUB IInternetThreadSwitch_Continue_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPIINTERNETPRIORITY_DEFINED
#define _LPIINTERNETPRIORITY_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0200_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0200_v0_0_s_ifspec;
#ifndef __IInternetPriority_INTERFACE_DEFINED__
#define __IInternetPriority_INTERFACE_DEFINED__
typedef  IInternetPriority *LPIINTERNETPRIORITY;
EXTERN_C const IID IID_IInternetPriority;
typedef struct IInternetPriorityVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetPriority *,REFIID,void **);
 ULONG ( *AddRef)(IInternetPriority *);
 ULONG ( *Release)(IInternetPriority *);
 HRESULT ( *SetPriority)(IInternetPriority *,LONG);
 HRESULT ( *GetPriority)(IInternetPriority *,LONG *);
END_INTERFACE
} IInternetPriorityVtbl;
interface IInternetPriority
{
CONST_VTBL struct IInternetPriorityVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetPriority_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetPriority_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetPriority_Release(A) (A)->lpVtbl->Release(A)
#define IInternetPriority_SetPriority(A,B) (A)->lpVtbl->SetPriority(A,B)
#define IInternetPriority_GetPriority(A,B) (A)->lpVtbl->GetPriority(A,B)
#endif 
HRESULT IInternetPriority_SetPriority_Proxy(IInternetPriority *,LONG );
void __RPC_STUB IInternetPriority_SetPriority_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetPriority_GetPriority_Proxy(IInternetPriority *,LONG *);
void __RPC_STUB IInternetPriority_GetPriority_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPIINTERNETPROTOCOLINFO_DEFINED
#define _LPIINTERNETPROTOCOLINFO_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0201_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0201_v0_0_s_ifspec;
#ifndef __IInternetProtocolInfo_INTERFACE_DEFINED__
#define __IInternetProtocolInfo_INTERFACE_DEFINED__
typedef  IInternetProtocolInfo *LPIINTERNETPROTOCOLINFO;
typedef 
enum _tagPARSEACTION
{	PARSE_CANONICALIZE=1,
PARSE_FRIENDLY=PARSE_CANONICALIZE + 1,
PARSE_SECURITY_URL=PARSE_FRIENDLY + 1,
PARSE_ROOTDOCUMENT=PARSE_SECURITY_URL + 1,
PARSE_DOCUMENT=PARSE_ROOTDOCUMENT + 1,
PARSE_ANCHOR=PARSE_DOCUMENT + 1,
PARSE_ENCODE=PARSE_ANCHOR + 1,
PARSE_DECODE=PARSE_ENCODE + 1,
PARSE_PATH_FROM_URL=PARSE_DECODE + 1,
PARSE_URL_FROM_PATH=PARSE_PATH_FROM_URL + 1,
PARSE_MIME=PARSE_URL_FROM_PATH + 1,
PARSE_SERVER=PARSE_MIME + 1,
PARSE_SCHEMA=PARSE_SERVER + 1,
PARSE_SITE=PARSE_SCHEMA + 1,
PARSE_DOMAIN=PARSE_SITE + 1,
PARSE_LOCATION=PARSE_DOMAIN + 1,
PARSE_SECURITY_DOMAIN=PARSE_LOCATION + 1,
PARSE_ESCAPE=PARSE_SECURITY_DOMAIN + 1,
PARSE_UNESCAPE=PARSE_ESCAPE + 1
} PARSEACTION;
typedef 
enum _tagPSUACTION
{	PSU_DEFAULT=1,
PSU_SECURITY_URL_ONLY=PSU_DEFAULT + 1
} PSUACTION;
typedef 
enum _tagQUERYOPTION
{	QUERY_EXPIRATION_DATE=1,
QUERY_TIME_OF_LAST_CHANGE=QUERY_EXPIRATION_DATE + 1,
QUERY_CONTENT_ENCODING=QUERY_TIME_OF_LAST_CHANGE + 1,
QUERY_CONTENT_TYPE=QUERY_CONTENT_ENCODING + 1,
QUERY_REFRESH=QUERY_CONTENT_TYPE + 1,
QUERY_RECOMBINE=QUERY_REFRESH + 1,
QUERY_CAN_NAVIGATE=QUERY_RECOMBINE + 1,
QUERY_USES_NETWORK=QUERY_CAN_NAVIGATE + 1,
QUERY_IS_CACHED=QUERY_USES_NETWORK + 1,
QUERY_IS_INSTALLEDENTRY=QUERY_IS_CACHED + 1,
QUERY_IS_CACHED_OR_MAPPED=QUERY_IS_INSTALLEDENTRY + 1,
QUERY_USES_CACHE=QUERY_IS_CACHED_OR_MAPPED + 1,
QUERY_IS_SECURE=QUERY_USES_CACHE + 1,
QUERY_IS_SAFE=QUERY_IS_SECURE + 1
} QUERYOPTION;
EXTERN_C const IID IID_IInternetProtocolInfo;
typedef struct IInternetProtocolInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetProtocolInfo *,REFIID,void **);
 ULONG ( *AddRef)(IInternetProtocolInfo *);
 ULONG ( *Release)(IInternetProtocolInfo *);
 HRESULT ( *ParseUrl)(IInternetProtocolInfo *,LPCWSTR,PARSEACTION,DWORD,LPWSTR,DWORD,DWORD *,DWORD);
 HRESULT ( *CombineUrl)(IInternetProtocolInfo *,LPCWSTR,LPCWSTR,DWORD,LPWSTR,DWORD,DWORD *,DWORD);
 HRESULT ( *CompareUrl)(IInternetProtocolInfo *,LPCWSTR,LPCWSTR,DWORD);
 HRESULT ( *QueryInfo)(IInternetProtocolInfo *,LPCWSTR,QUERYOPTION,DWORD,LPVOID,DWORD,DWORD *,DWORD);
END_INTERFACE
} IInternetProtocolInfoVtbl;
interface IInternetProtocolInfo
{
CONST_VTBL struct IInternetProtocolInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetProtocolInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetProtocolInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetProtocolInfo_Release(A) (A)->lpVtbl->Release(A)
#define IInternetProtocolInfo_ParseUrl(A,B,C,D,E,F,G,H) (A)->lpVtbl->ParseUrl(A,B,C,D,E,F,G,H)
#define IInternetProtocolInfo_CombineUrl(A,B,C,D,E,F,G,H) (A)->lpVtbl->CombineUrl(A,B,C,D,E,F,G,H)
#define IInternetProtocolInfo_CompareUrl(A,B,C,D) (A)->lpVtbl->CompareUrl(A,B,C,D)
#define IInternetProtocolInfo_QueryInfo(A,B,C,D,E,F,G,H) (A)->lpVtbl->QueryInfo(A,B,C,D,E,F,G,H)
#endif 
HRESULT IInternetProtocolInfo_ParseUrl_Proxy(IInternetProtocolInfo *,LPCWSTR ,PARSEACTION ,DWORD ,LPWSTR ,DWORD ,DWORD *,DWORD );
void __RPC_STUB IInternetProtocolInfo_ParseUrl_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolInfo_CombineUrl_Proxy(IInternetProtocolInfo *,LPCWSTR ,LPCWSTR ,DWORD ,LPWSTR ,DWORD ,DWORD *,DWORD );
void __RPC_STUB IInternetProtocolInfo_CombineUrl_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolInfo_CompareUrl_Proxy(IInternetProtocolInfo *,LPCWSTR ,LPCWSTR ,DWORD );
void __RPC_STUB IInternetProtocolInfo_CompareUrl_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetProtocolInfo_QueryInfo_Proxy(IInternetProtocolInfo *,LPCWSTR ,QUERYOPTION ,DWORD ,LPVOID ,DWORD ,DWORD *,DWORD );
void __RPC_STUB IInternetProtocolInfo_QueryInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#define IOInet IInternet 
#define IOInetBindInfo IInternetBindInfo 
#define IOInetProtocolRoot IInternetProtocolRoot
#define IOInetProtocol IInternetProtocol 
#define IOInetProtocolSink IInternetProtocolSink
#define IOInetProtocolInfo IInternetProtocolInfo
#define IOInetSession IInternetSession 
#define IOInetPriority IInternetPriority 
#define IOInetThreadSwitch IInternetThreadSwitch
#define IOInetProtocolSinkStackable IInternetProtocolSinkStackable
#define LPOINET LPIINTERNET 
#define LPOINETPROTOCOLINFO LPIINTERNETPROTOCOLINFO 
#define LPOINETBINDINFO LPIINTERNETBINDINFO 
#define LPOINETPROTOCOLROOT LPIINTERNETPROTOCOLROOT 
#define LPOINETPROTOCOL LPIINTERNETPROTOCOL 
#define LPOINETPROTOCOLSINK LPIINTERNETPROTOCOLSINK 
#define LPOINETSESSION LPIINTERNETSESSION 
#define LPOINETTHREADSWITCH LPIINTERNETTHREADSWITCH 
#define LPOINETPRIORITY LPIINTERNETPRIORITY 
#define LPOINETPROTOCOLINFO LPIINTERNETPROTOCOLINFO 
#define LPOINETPROTOCOLSINKSTACKABLE LPIINTERNETPROTOCOLSINKSTACKABLE 
#define IID_IOInet IID_IInternet 
#define IID_IOInetBindInfo IID_IInternetBindInfo 
#define IID_IOInetProtocolRoot IID_IInternetProtocolRoot
#define IID_IOInetProtocol IID_IInternetProtocol 
#define IID_IOInetProtocolSink IID_IInternetProtocolSink
#define IID_IOInetProtocolInfo IID_IInternetProtocolInfo
#define IID_IOInetSession IID_IInternetSession 
#define IID_IOInetPriority IID_IInternetPriority 
#define IID_IOInetThreadSwitch IID_IInternetThreadSwitch
#define IID_IOInetProtocolSinkStackable IID_IInternetProtocolSinkStackable
STDAPI CoInternetParseUrl(LPCWSTR ,PARSEACTION ,DWORD ,LPWSTR ,DWORD ,DWORD *,DWORD dwReserved  ); 
STDAPI CoInternetCombineUrl(LPCWSTR ,LPCWSTR ,DWORD ,LPWSTR ,DWORD ,DWORD *,DWORD dwReserved  ); 
STDAPI CoInternetCompareUrl(LPCWSTR ,LPCWSTR ,DWORD dwFlags  ); 
STDAPI CoInternetGetProtocolFlags(LPCWSTR ,DWORD *,DWORD dwReserved  ); 
STDAPI CoInternetQueryInfo(LPCWSTR ,QUERYOPTION ,DWORD ,LPVOID ,DWORD ,DWORD *,DWORD dwReserved  ); 
STDAPI CoInternetGetSession(DWORD ,IInternetSession **,DWORD dwReserved  ); 
STDAPI CoInternetGetSecurityUrl(LPCWSTR ,LPWSTR *,PSUACTION ,DWORD dwReserved  ); 
STDAPI AsyncInstallDistributionUnit(LPCWSTR ,LPCWSTR ,LPCWSTR ,DWORD ,DWORD ,LPCWSTR ,IBindCtx *,LPVOID ,DWORD flags  ); 
STDAPI CopyStgMedium(const STGMEDIUM * pcstgmedSrc,STGMEDIUM *); 
STDAPI CopyBindInfo(const BINDINFO * pcbiSrc,BINDINFO *); 
STDAPI_(void) ReleaseBindInfo(BINDINFO *); 
#define INET_E_USE_DEFAULT_PROTOCOLHANDLER _HRESULT_TYPEDEF_0x800c0011  
#define INET_E_USE_DEFAULT_SETTING _HRESULT_TYPEDEF_0x800c0012  
#define INET_E_DEFAULT_ACTION INET_E_USE_DEFAULT_PROTOCOLHANDLER 
#define INET_E_QUERYOPTION_UNKNOWN _HRESULT_TYPEDEF_0x800c0013  
#define INET_E_REDIRECTING _HRESULT_TYPEDEF_0x800c0014  
#define OInetParseUrl CoInternetParseUrl 
#define OInetCombineUrl CoInternetCombineUrl 
#define OInetCompareUrl CoInternetCompareUrl 
#define OInetQueryInfo CoInternetQueryInfo 
#define OInetGetSession CoInternetGetSession 
#endif 
#define PROTOCOLFLAG_NO_PICS_CHECK 1
STDAPI CoInternetCreateSecurityManager(IServiceProvider *,IInternetSecurityManager **,DWORD );
STDAPI CoInternetCreateZoneManager(IServiceProvider *,IInternetZoneManager **,DWORD );
EXTERN_C const IID CLSID_InternetSecurityManager; 
EXTERN_C const IID CLSID_InternetZoneManager; 
#define SID_SInternetSecurityManager IID_IInternetSecurityManager
#define SID_SInternetHostSecurityManager IID_IInternetHostSecurityManager
#ifndef _LPINTERNETSECURITYMGRSITE_DEFINED
#define _LPINTERNETSECURITYMGRSITE_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0202_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0202_v0_0_s_ifspec;
#ifndef __IInternetSecurityMgrSite_INTERFACE_DEFINED__
#define __IInternetSecurityMgrSite_INTERFACE_DEFINED__
EXTERN_C const IID IID_IInternetSecurityMgrSite;
typedef struct IInternetSecurityMgrSiteVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetSecurityMgrSite *,REFIID,void **);
 ULONG ( *AddRef)(IInternetSecurityMgrSite *);
 ULONG ( *Release)(IInternetSecurityMgrSite *);
 HRESULT ( *GetWindow)(IInternetSecurityMgrSite *,HWND *);
 HRESULT ( *EnableModeless)(IInternetSecurityMgrSite *,BOOL);
END_INTERFACE
} IInternetSecurityMgrSiteVtbl;
interface IInternetSecurityMgrSite
{
CONST_VTBL struct IInternetSecurityMgrSiteVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetSecurityMgrSite_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetSecurityMgrSite_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetSecurityMgrSite_Release(A) (A)->lpVtbl->Release(A)
#define IInternetSecurityMgrSite_GetWindow(A,B) (A)->lpVtbl->GetWindow(A,B)
#define IInternetSecurityMgrSite_EnableModeless(A,B) (A)->lpVtbl->EnableModeless(A,B)
#endif 
HRESULT IInternetSecurityMgrSite_GetWindow_Proxy(IInternetSecurityMgrSite *,HWND *);
void __RPC_STUB IInternetSecurityMgrSite_GetWindow_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSecurityMgrSite_EnableModeless_Proxy(IInternetSecurityMgrSite *,BOOL );
void __RPC_STUB IInternetSecurityMgrSite_EnableModeless_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPINTERNETSECURITYMANANGER_DEFINED
#define _LPINTERNETSECURITYMANANGER_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0203_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0203_v0_0_s_ifspec;
#ifndef __IInternetSecurityManager_INTERFACE_DEFINED__
#define __IInternetSecurityManager_INTERFACE_DEFINED__
#define MUTZ_NOSAVEDFILECHECK 1
#define MUTZ_ENFORCERESTRICTED 256
#define MAX_SIZE_SECURITY_ID 512 
typedef  
enum __MIDL_IInternetSecurityManager_0001
{	PUAF_DEFAULT=0,
PUAF_NOUI=1,
PUAF_ISFILE=2,
PUAF_WARN_IF_DENIED=4,
PUAF_FORCEUI_FOREGROUND=8,
PUAF_CHECK_TIFS=16,
PUAF_DONTCHECKBOXINDIALOG=32,
PUAF_TRUSTED=64,
PUAF_ACCEPT_WILDCARD_SCHEME=128,
PUAF_ENFORCERESTRICTED=256
} PUAF;
typedef  
enum __MIDL_IInternetSecurityManager_0002
{	SZM_CREATE=0,
SZM_DELETE=1
} SZM_FLAGS;
EXTERN_C const IID IID_IInternetSecurityManager;
typedef struct IInternetSecurityManagerVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetSecurityManager *,REFIID,void **);
 ULONG ( *AddRef)(IInternetSecurityManager *);
 ULONG ( *Release)(IInternetSecurityManager *);
 HRESULT ( *SetSecuritySite)(IInternetSecurityManager *,IInternetSecurityMgrSite *);
 HRESULT ( *GetSecuritySite)(IInternetSecurityManager *,IInternetSecurityMgrSite **);
 HRESULT ( *MapUrlToZone)(IInternetSecurityManager *,LPCWSTR,DWORD *,DWORD);
 HRESULT ( *GetSecurityId)(IInternetSecurityManager *,LPCWSTR,BYTE *,DWORD *,DWORD_PTR);
 HRESULT ( *ProcessUrlAction)(IInternetSecurityManager *,LPCWSTR,DWORD,BYTE *,DWORD,BYTE *,DWORD,DWORD,DWORD);
 HRESULT ( *QueryCustomPolicy)(IInternetSecurityManager *,LPCWSTR,REFGUID,BYTE **,DWORD *,BYTE *,DWORD,DWORD);
 HRESULT ( *SetZoneMapping)(IInternetSecurityManager *,DWORD,LPCWSTR,DWORD);
 HRESULT ( *GetZoneMappings)(IInternetSecurityManager *,DWORD,IEnumString **,DWORD);
END_INTERFACE
} IInternetSecurityManagerVtbl;
interface IInternetSecurityManager
{
CONST_VTBL struct IInternetSecurityManagerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetSecurityManager_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetSecurityManager_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetSecurityManager_Release(A) (A)->lpVtbl->Release(A)
#define IInternetSecurityManager_SetSecuritySite(A,B) (A)->lpVtbl->SetSecuritySite(A,B)
#define IInternetSecurityManager_GetSecuritySite(A,B) (A)->lpVtbl->GetSecuritySite(A,B)
#define IInternetSecurityManager_MapUrlToZone(A,B,C,D) (A)->lpVtbl->MapUrlToZone(A,B,C,D)
#define IInternetSecurityManager_GetSecurityId(A,B,C,D,E) (A)->lpVtbl->GetSecurityId(A,B,C,D,E)
#define IInternetSecurityManager_ProcessUrlAction(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->ProcessUrlAction(A,B,C,D,E,F,G,H,I)
#define IInternetSecurityManager_QueryCustomPolicy(A,B,C,D,E,F,G,H) (A)->lpVtbl->QueryCustomPolicy(A,B,C,D,E,F,G,H)
#define IInternetSecurityManager_SetZoneMapping(A,B,C,D) (A)->lpVtbl->SetZoneMapping(A,B,C,D)
#define IInternetSecurityManager_GetZoneMappings(A,B,C,D) (A)->lpVtbl->GetZoneMappings(A,B,C,D)
#endif 
HRESULT IInternetSecurityManager_SetSecuritySite_Proxy(IInternetSecurityManager *,IInternetSecurityMgrSite *);
void __RPC_STUB IInternetSecurityManager_SetSecuritySite_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSecurityManager_GetSecuritySite_Proxy(IInternetSecurityManager *,IInternetSecurityMgrSite **);
void __RPC_STUB IInternetSecurityManager_GetSecuritySite_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSecurityManager_MapUrlToZone_Proxy(IInternetSecurityManager *,LPCWSTR ,DWORD *,DWORD );
void __RPC_STUB IInternetSecurityManager_MapUrlToZone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSecurityManager_GetSecurityId_Proxy(IInternetSecurityManager *,LPCWSTR ,BYTE *,DWORD *,DWORD_PTR );
void __RPC_STUB IInternetSecurityManager_GetSecurityId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSecurityManager_ProcessUrlAction_Proxy(IInternetSecurityManager *,LPCWSTR ,DWORD ,BYTE *,DWORD ,BYTE *,DWORD ,DWORD ,DWORD );
void __RPC_STUB IInternetSecurityManager_ProcessUrlAction_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSecurityManager_QueryCustomPolicy_Proxy(IInternetSecurityManager *,LPCWSTR ,REFGUID ,BYTE **,DWORD *,BYTE *,DWORD ,DWORD );
void __RPC_STUB IInternetSecurityManager_QueryCustomPolicy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSecurityManager_SetZoneMapping_Proxy(IInternetSecurityManager *,DWORD ,LPCWSTR ,DWORD );
void __RPC_STUB IInternetSecurityManager_SetZoneMapping_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetSecurityManager_GetZoneMappings_Proxy(IInternetSecurityManager *,DWORD ,IEnumString **,DWORD );
void __RPC_STUB IInternetSecurityManager_GetZoneMappings_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPINTERNETHOSTSECURITYMANANGER_DEFINED
#define _LPINTERNETHOSTSECURITYMANANGER_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0204_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0204_v0_0_s_ifspec;
#ifndef __IInternetHostSecurityManager_INTERFACE_DEFINED__
#define __IInternetHostSecurityManager_INTERFACE_DEFINED__
EXTERN_C const IID IID_IInternetHostSecurityManager;
typedef struct IInternetHostSecurityManagerVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetHostSecurityManager *,REFIID,void **);
 ULONG ( *AddRef)(IInternetHostSecurityManager *);
 ULONG ( *Release)(IInternetHostSecurityManager *);
 HRESULT ( *GetSecurityId)(IInternetHostSecurityManager *,BYTE *,DWORD *,DWORD_PTR);
 HRESULT ( *ProcessUrlAction)(IInternetHostSecurityManager *,DWORD,BYTE *,DWORD,BYTE *,DWORD,DWORD,DWORD);
 HRESULT ( *QueryCustomPolicy)(IInternetHostSecurityManager *,REFGUID,BYTE **,DWORD *,BYTE *,DWORD,DWORD);
END_INTERFACE
} IInternetHostSecurityManagerVtbl;
interface IInternetHostSecurityManager
{
CONST_VTBL struct IInternetHostSecurityManagerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetHostSecurityManager_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetHostSecurityManager_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetHostSecurityManager_Release(A) (A)->lpVtbl->Release(A)
#define IInternetHostSecurityManager_GetSecurityId(A,B,C,D) (A)->lpVtbl->GetSecurityId(A,B,C,D)
#define IInternetHostSecurityManager_ProcessUrlAction(A,B,C,D,E,F,G,H) (A)->lpVtbl->ProcessUrlAction(A,B,C,D,E,F,G,H)
#define IInternetHostSecurityManager_QueryCustomPolicy(A,B,C,D,E,F,G) (A)->lpVtbl->QueryCustomPolicy(A,B,C,D,E,F,G)
#endif 
HRESULT IInternetHostSecurityManager_GetSecurityId_Proxy(IInternetHostSecurityManager *,BYTE *,DWORD *,DWORD_PTR );
void __RPC_STUB IInternetHostSecurityManager_GetSecurityId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetHostSecurityManager_ProcessUrlAction_Proxy(IInternetHostSecurityManager *,DWORD ,BYTE *,DWORD ,BYTE *,DWORD ,DWORD ,DWORD );
void __RPC_STUB IInternetHostSecurityManager_ProcessUrlAction_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetHostSecurityManager_QueryCustomPolicy_Proxy(IInternetHostSecurityManager *,REFGUID ,BYTE **,DWORD *,BYTE *,DWORD ,DWORD );
void __RPC_STUB IInternetHostSecurityManager_QueryCustomPolicy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#define URLACTION_MIN 4096
#define URLACTION_DOWNLOAD_MIN 4096
#define URLACTION_DOWNLOAD_SIGNED_ACTIVEX 4097
#define URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX 4100
#define URLACTION_DOWNLOAD_CURR_MAX 4100
#define URLACTION_DOWNLOAD_MAX 4607
#define URLACTION_ACTIVEX_MIN 4608
#define URLACTION_ACTIVEX_RUN 4608
#define URLPOLICY_ACTIVEX_CHECK_LIST 0x10000
#define URLACTION_ACTIVEX_OVERRIDE_OBJECT_SAFETY 4609
#define URLACTION_ACTIVEX_OVERRIDE_DATA_SAFETY 4610
#define URLACTION_ACTIVEX_OVERRIDE_SCRIPT_SAFETY 4611
#define URLACTION_SCRIPT_OVERRIDE_SAFETY 5121
#define URLACTION_ACTIVEX_CONFIRM_NOOBJECTSAFETY 4612
#define URLACTION_ACTIVEX_TREATASUNTRUSTED 4613
#define URLACTION_ACTIVEX_NO_WEBOC_SCRIPT 4614
#define URLACTION_ACTIVEX_CURR_MAX 4614
#define URLACTION_ACTIVEX_MAX 5119
#define URLACTION_SCRIPT_MIN 5120
#define URLACTION_SCRIPT_RUN 5120
#define URLACTION_SCRIPT_JAVA_USE 5122
#define URLACTION_SCRIPT_SAFE_ACTIVEX 5125
#define URLACTION_CROSS_DOMAIN_DATA 5126
#define URLACTION_SCRIPT_PASTE 5127
#define URLACTION_SCRIPT_CURR_MAX 5127
#define URLACTION_SCRIPT_MAX 5631
#define URLACTION_HTML_MIN 5632
#define URLACTION_HTML_SUBMIT_FORMS 5633
#define URLACTION_HTML_SUBMIT_FORMS_FROM 5634
#define URLACTION_HTML_SUBMIT_FORMS_TO 5635
#define URLACTION_HTML_FONT_DOWNLOAD 5636
#define URLACTION_HTML_JAVA_RUN 5637
#define URLACTION_HTML_USERDATA_SAVE 5638
#define URLACTION_HTML_SUBFRAME_NAVIGATE 5639
#define URLACTION_HTML_META_REFRESH 5640
#define URLACTION_HTML_MIXED_CONTENT 5641
#define URLACTION_HTML_MAX 6143
#define URLACTION_SHELL_MIN 6144
#define URLACTION_SHELL_INSTALL_DTITEMS 6144
#define URLACTION_SHELL_MOVE_OR_COPY 6146
#define URLACTION_SHELL_FILE_DOWNLOAD 6147
#define URLACTION_SHELL_VERB 6148
#define URLACTION_SHELL_WEBVIEW_VERB 6149
#define URLACTION_SHELL_SHELLEXECUTE 6150
#define URLACTION_SHELL_CURR_MAX 6150
#define URLACTION_SHELL_MAX 6655
#define URLACTION_NETWORK_MIN 6656
#define URLACTION_CREDENTIALS_USE 6656
#define URLPOLICY_CREDENTIALS_SILENT_LOGON_OK 0
#define URLPOLICY_CREDENTIALS_MUST_PROMPT_USER 0x10000
#define URLPOLICY_CREDENTIALS_CONDITIONAL_PROMPT 0x20000
#define URLPOLICY_CREDENTIALS_ANONYMOUS_ONLY 0x30000
#define URLACTION_AUTHENTICATE_CLIENT 6657
#define URLPOLICY_AUTHENTICATE_CLEARTEXT_OK 0
#define URLPOLICY_AUTHENTICATE_CHALLENGE_RESPONSE 0x10000
#define URLPOLICY_AUTHENTICATE_MUTUAL_ONLY 0x30000
#define URLACTION_COOKIES 6658
#define URLACTION_COOKIES_SESSION 6659
#define URLACTION_CLIENT_CERT_PROMPT 6660
#define URLACTION_COOKIES_THIRD_PARTY 6661
#define URLACTION_COOKIES_SESSION_THIRD_PARTY 6662
#define URLACTION_COOKIES_ENABLED 6672
#define URLACTION_NETWORK_CURR_MAX 6672
#define URLACTION_NETWORK_MAX 7167
#define URLACTION_JAVA_MIN 7168
#define URLACTION_JAVA_PERMISSIONS 7168
#define URLPOLICY_JAVA_PROHIBIT 0
#define URLPOLICY_JAVA_HIGH 0x10000
#define URLPOLICY_JAVA_MEDIUM 0x20000
#define URLPOLICY_JAVA_LOW 0x30000
#define URLPOLICY_JAVA_CUSTOM 0x800000
#define URLACTION_JAVA_CURR_MAX 7168
#define URLACTION_JAVA_MAX 7423
#define URLACTION_INFODELIVERY_MIN 7424
#define URLACTION_INFODELIVERY_NO_ADDING_CHANNELS 7424
#define URLACTION_INFODELIVERY_NO_EDITING_CHANNELS 7425
#define URLACTION_INFODELIVERY_NO_REMOVING_CHANNELS 7426
#define URLACTION_INFODELIVERY_NO_ADDING_SUBSCRIPTIONS 7427
#define URLACTION_INFODELIVERY_NO_EDITING_SUBSCRIPTIONS 7428
#define URLACTION_INFODELIVERY_NO_REMOVING_SUBSCRIPTIONS 7429
#define URLACTION_INFODELIVERY_NO_CHANNEL_LOGGING 7430
#define URLACTION_INFODELIVERY_CURR_MAX 7430
#define URLACTION_INFODELIVERY_MAX 7679
#define URLACTION_CHANNEL_SOFTDIST_MIN 7680
#define URLACTION_CHANNEL_SOFTDIST_PERMISSIONS 7685
#define URLPOLICY_CHANNEL_SOFTDIST_PROHIBIT 0x10000
#define URLPOLICY_CHANNEL_SOFTDIST_PRECACHE 0x20000
#define URLPOLICY_CHANNEL_SOFTDIST_AUTOINSTALL 0x30000
#define URLACTION_CHANNEL_SOFTDIST_MAX 7935
#define URLPOLICY_ALLOW 0
#define URLPOLICY_QUERY 1
#define URLPOLICY_DISALLOW 3
#define URLPOLICY_NOTIFY_ON_ALLOW 16
#define URLPOLICY_NOTIFY_ON_DISALLOW 32
#define URLPOLICY_LOG_ON_ALLOW 64
#define URLPOLICY_LOG_ON_DISALLOW 128
#define URLPOLICY_MASK_PERMISSIONS 15
#define GetUrlPolicyPermissions(dw) (dw & URLPOLICY_MASK_PERMISSIONS)
#define SetUrlPolicyPermissions(dw,dw2) ((dw)=((dw) & ~(URLPOLICY_MASK_PERMISSIONS)) | (dw2))
#define URLPOLICY_DONTCHECKDLGBOX 256
#ifndef _LPINTERNETZONEMANAGER_DEFINED
#define _LPINTERNETZONEMANAGER_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0205_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0205_v0_0_s_ifspec;
#ifndef __IInternetZoneManager_INTERFACE_DEFINED__
#define __IInternetZoneManager_INTERFACE_DEFINED__
typedef  IInternetZoneManager *LPURLZONEMANAGER;
typedef 
enum tagURLZONE
{	URLZONE_PREDEFINED_MIN=0,
URLZONE_LOCAL_MACHINE=0,
URLZONE_INTRANET=URLZONE_LOCAL_MACHINE + 1,
URLZONE_TRUSTED=URLZONE_INTRANET + 1,
URLZONE_INTERNET=URLZONE_TRUSTED + 1,
URLZONE_UNTRUSTED=URLZONE_INTERNET + 1,
URLZONE_PREDEFINED_MAX=999,
URLZONE_USER_MIN=1000,
URLZONE_USER_MAX=10000
} URLZONE;
#define URLZONE_ESC_FLAG 256
typedef 
enum tagURLTEMPLATE
{	URLTEMPLATE_CUSTOM=0,
URLTEMPLATE_PREDEFINED_MIN=0x10000,
URLTEMPLATE_LOW=0x10000,
URLTEMPLATE_MEDLOW=0x10500,
URLTEMPLATE_MEDIUM=0x11000,
URLTEMPLATE_HIGH=0x12000,
URLTEMPLATE_PREDEFINED_MAX=0x20000
} URLTEMPLATE;
enum __MIDL_IInternetZoneManager_0001
{	MAX_ZONE_PATH=260,
MAX_ZONE_DESCRIPTION=200
} ;
typedef  
enum __MIDL_IInternetZoneManager_0002
{	ZAFLAGS_CUSTOM_EDIT=1,
ZAFLAGS_ADD_SITES=2,
ZAFLAGS_REQUIRE_VERIFICATION=4,
ZAFLAGS_INCLUDE_PROXY_OVERRIDE=8,
ZAFLAGS_INCLUDE_INTRANET_SITES=16,
ZAFLAGS_NO_UI=32,
ZAFLAGS_SUPPORTS_VERIFICATION=64,
ZAFLAGS_UNC_AS_INTRANET=128
} ZAFLAGS;
typedef struct _ZONEATTRIBUTES
{
ULONG cbSize;
WCHAR szDisplayName[ 260 ];
WCHAR szDescription[ 200 ];
WCHAR szIconPath[ 260 ];
DWORD dwTemplateMinLevel;
DWORD dwTemplateRecommended;
DWORD dwTemplateCurrentLevel;
DWORD dwFlags;
} ZONEATTRIBUTES;
typedef struct _ZONEATTRIBUTES *LPZONEATTRIBUTES;
typedef 
enum _URLZONEREG
{	URLZONEREG_DEFAULT=0,
URLZONEREG_HKLM=URLZONEREG_DEFAULT + 1,
URLZONEREG_HKCU=URLZONEREG_HKLM + 1
} URLZONEREG;
EXTERN_C const IID IID_IInternetZoneManager;
typedef struct IInternetZoneManagerVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IInternetZoneManager *,REFIID,void **);
 ULONG ( *AddRef)(IInternetZoneManager *);
 ULONG ( *Release)(IInternetZoneManager *);
 HRESULT ( *GetZoneAttributes)(IInternetZoneManager *,DWORD,ZONEATTRIBUTES *);
 HRESULT ( *SetZoneAttributes)(IInternetZoneManager *,DWORD,ZONEATTRIBUTES *);
 HRESULT ( *GetZoneCustomPolicy)(IInternetZoneManager *,DWORD,REFGUID,BYTE **,DWORD *,URLZONEREG);
 HRESULT ( *SetZoneCustomPolicy)(IInternetZoneManager *,DWORD,REFGUID,BYTE *,DWORD,URLZONEREG);
 HRESULT ( *GetZoneActionPolicy)(IInternetZoneManager *,DWORD,DWORD,BYTE *,DWORD,URLZONEREG);
 HRESULT ( *SetZoneActionPolicy)(IInternetZoneManager *,DWORD,DWORD,BYTE *,DWORD,URLZONEREG);
 HRESULT ( *PromptAction)(IInternetZoneManager *,DWORD,HWND,LPCWSTR,LPCWSTR,DWORD);
 HRESULT ( *LogAction)(IInternetZoneManager *,DWORD,LPCWSTR,LPCWSTR,DWORD);
 HRESULT ( *CreateZoneEnumerator)(IInternetZoneManager *,DWORD *,DWORD *,DWORD);
 HRESULT ( *GetZoneAt)(IInternetZoneManager *,DWORD,DWORD,DWORD *);
 HRESULT ( *DestroyZoneEnumerator)(IInternetZoneManager *,DWORD);
 HRESULT ( *CopyTemplatePoliciesToZone)(IInternetZoneManager *,DWORD,DWORD,DWORD);
END_INTERFACE
} IInternetZoneManagerVtbl;
interface IInternetZoneManager
{
CONST_VTBL struct IInternetZoneManagerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternetZoneManager_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternetZoneManager_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternetZoneManager_Release(A) (A)->lpVtbl->Release(A)
#define IInternetZoneManager_GetZoneAttributes(A,B,C) (A)->lpVtbl->GetZoneAttributes(A,B,C)
#define IInternetZoneManager_SetZoneAttributes(A,B,C) (A)->lpVtbl->SetZoneAttributes(A,B,C)
#define IInternetZoneManager_GetZoneCustomPolicy(A,B,C,D,E,F) (A)->lpVtbl->GetZoneCustomPolicy(A,B,C,D,E,F)
#define IInternetZoneManager_SetZoneCustomPolicy(A,B,C,D,E,F) (A)->lpVtbl->SetZoneCustomPolicy(A,B,C,D,E,F)
#define IInternetZoneManager_GetZoneActionPolicy(A,B,C,D,E,F) (A)->lpVtbl->GetZoneActionPolicy(A,B,C,D,E,F)
#define IInternetZoneManager_SetZoneActionPolicy(A,B,C,D,E,F) (A)->lpVtbl->SetZoneActionPolicy(A,B,C,D,E,F)
#define IInternetZoneManager_PromptAction(A,B,C,D,E,F) (A)->lpVtbl->PromptAction(A,B,C,D,E,F)
#define IInternetZoneManager_LogAction(A,B,C,D,E) (A)->lpVtbl->LogAction(A,B,C,D,E)
#define IInternetZoneManager_CreateZoneEnumerator(A,B,C,D) (A)->lpVtbl->CreateZoneEnumerator(A,B,C,D)
#define IInternetZoneManager_GetZoneAt(A,B,C,D) (A)->lpVtbl->GetZoneAt(A,B,C,D)
#define IInternetZoneManager_DestroyZoneEnumerator(A,B) (A)->lpVtbl->DestroyZoneEnumerator(A,B)
#define IInternetZoneManager_CopyTemplatePoliciesToZone(A,B,C,D) (A)->lpVtbl->CopyTemplatePoliciesToZone(A,B,C,D)
#endif 
HRESULT IInternetZoneManager_GetZoneAttributes_Proxy(IInternetZoneManager *,DWORD ,ZONEATTRIBUTES *);
void __RPC_STUB IInternetZoneManager_GetZoneAttributes_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_SetZoneAttributes_Proxy(IInternetZoneManager *,DWORD ,ZONEATTRIBUTES *);
void __RPC_STUB IInternetZoneManager_SetZoneAttributes_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_GetZoneCustomPolicy_Proxy(IInternetZoneManager *,DWORD ,REFGUID ,BYTE **,DWORD *,URLZONEREG );
void __RPC_STUB IInternetZoneManager_GetZoneCustomPolicy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_SetZoneCustomPolicy_Proxy(IInternetZoneManager *,DWORD ,REFGUID ,BYTE *,DWORD ,URLZONEREG );
void __RPC_STUB IInternetZoneManager_SetZoneCustomPolicy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_GetZoneActionPolicy_Proxy(IInternetZoneManager *,DWORD ,DWORD ,BYTE *,DWORD ,URLZONEREG );
void __RPC_STUB IInternetZoneManager_GetZoneActionPolicy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_SetZoneActionPolicy_Proxy(IInternetZoneManager *,DWORD ,DWORD ,BYTE *,DWORD ,URLZONEREG );
void __RPC_STUB IInternetZoneManager_SetZoneActionPolicy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_PromptAction_Proxy(IInternetZoneManager *,DWORD ,HWND ,LPCWSTR ,LPCWSTR ,DWORD );
void __RPC_STUB IInternetZoneManager_PromptAction_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_LogAction_Proxy(IInternetZoneManager *,DWORD ,LPCWSTR ,LPCWSTR ,DWORD );
void __RPC_STUB IInternetZoneManager_LogAction_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_CreateZoneEnumerator_Proxy(IInternetZoneManager *,DWORD *,DWORD *,DWORD );
void __RPC_STUB IInternetZoneManager_CreateZoneEnumerator_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_GetZoneAt_Proxy(IInternetZoneManager *,DWORD ,DWORD ,DWORD *);
void __RPC_STUB IInternetZoneManager_GetZoneAt_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_DestroyZoneEnumerator_Proxy(IInternetZoneManager *,DWORD );
void __RPC_STUB IInternetZoneManager_DestroyZoneEnumerator_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IInternetZoneManager_CopyTemplatePoliciesToZone_Proxy(IInternetZoneManager *,DWORD ,DWORD ,DWORD );
void __RPC_STUB IInternetZoneManager_CopyTemplatePoliciesToZone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
EXTERN_C const IID CLSID_SoftDistExt; 
#ifndef _LPSOFTDISTEXT_DEFINED
#define _LPSOFTDISTEXT_DEFINED
#define SOFTDIST_FLAG_USAGE_EMAIL 1
#define SOFTDIST_FLAG_USAGE_PRECACHE 2
#define SOFTDIST_FLAG_USAGE_AUTOINSTALL 4
#define SOFTDIST_FLAG_DELETE_SUBSCRIPTION 8
#define SOFTDIST_ADSTATE_NONE 0
#define SOFTDIST_ADSTATE_AVAILABLE 1
#define SOFTDIST_ADSTATE_DOWNLOADED 2
#define SOFTDIST_ADSTATE_INSTALLED 3
typedef struct _tagCODEBASEHOLD
{
ULONG cbSize;
LPWSTR szDistUnit;
LPWSTR szCodeBase;
DWORD dwVersionMS;
DWORD dwVersionLS;
DWORD dwStyle;
} CODEBASEHOLD;
typedef struct _tagCODEBASEHOLD *LPCODEBASEHOLD;
typedef struct _tagSOFTDISTINFO
{
ULONG cbSize;
DWORD dwFlags;
DWORD dwAdState;
LPWSTR szTitle;
LPWSTR szAbstract;
LPWSTR szHREF;
DWORD dwInstalledVersionMS;
DWORD dwInstalledVersionLS;
DWORD dwUpdateVersionMS;
DWORD dwUpdateVersionLS;
DWORD dwAdvertisedVersionMS;
DWORD dwAdvertisedVersionLS;
DWORD dwReserved;
} SOFTDISTINFO;
typedef struct _tagSOFTDISTINFO *LPSOFTDISTINFO;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0206_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0206_v0_0_s_ifspec;
#ifndef __ISoftDistExt_INTERFACE_DEFINED__
#define __ISoftDistExt_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISoftDistExt;
typedef struct ISoftDistExtVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(ISoftDistExt *,REFIID,void **);
 ULONG ( *AddRef)(ISoftDistExt *);
 ULONG ( *Release)(ISoftDistExt *);
 HRESULT ( *ProcessSoftDist)(ISoftDistExt *,LPCWSTR,IXMLElement *,LPSOFTDISTINFO);
 HRESULT ( *GetFirstCodeBase)(ISoftDistExt *,LPWSTR *,LPDWORD);
 HRESULT ( *GetNextCodeBase)(ISoftDistExt *,LPWSTR *,LPDWORD);
 HRESULT ( *AsyncInstallDistributionUnit)(ISoftDistExt *,IBindCtx *,LPVOID,DWORD,LPCODEBASEHOLD);
END_INTERFACE
} ISoftDistExtVtbl;
interface ISoftDistExt
{
CONST_VTBL struct ISoftDistExtVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISoftDistExt_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISoftDistExt_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISoftDistExt_Release(A) (A)->lpVtbl->Release(A)
#define ISoftDistExt_ProcessSoftDist(A,B,C,D) (A)->lpVtbl->ProcessSoftDist(A,B,C,D)
#define ISoftDistExt_GetFirstCodeBase(A,B,C) (A)->lpVtbl->GetFirstCodeBase(A,B,C)
#define ISoftDistExt_GetNextCodeBase(A,B,C) (A)->lpVtbl->GetNextCodeBase(A,B,C)
#define ISoftDistExt_AsyncInstallDistributionUnit(A,B,C,D,E) (A)->lpVtbl->AsyncInstallDistributionUnit(A,B,C,D,E)
#endif 
HRESULT ISoftDistExt_ProcessSoftDist_Proxy(ISoftDistExt *,LPCWSTR ,IXMLElement *,LPSOFTDISTINFO );
void __RPC_STUB ISoftDistExt_ProcessSoftDist_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISoftDistExt_GetFirstCodeBase_Proxy(ISoftDistExt *,LPWSTR *,LPDWORD );
void __RPC_STUB ISoftDistExt_GetFirstCodeBase_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISoftDistExt_GetNextCodeBase_Proxy(ISoftDistExt *,LPWSTR *,LPDWORD );
void __RPC_STUB ISoftDistExt_GetNextCodeBase_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISoftDistExt_AsyncInstallDistributionUnit_Proxy(ISoftDistExt *,IBindCtx *,LPVOID ,DWORD ,LPCODEBASEHOLD );
void __RPC_STUB ISoftDistExt_AsyncInstallDistributionUnit_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
STDAPI GetSoftwareUpdateInfo(LPCWSTR ,LPSOFTDISTINFO );
STDAPI SetSoftwareUpdateAdvertisementState(LPCWSTR ,DWORD ,DWORD ,DWORD );
#endif
#ifndef _LPCATALOGFILEINFO_DEFINED
#define _LPCATALOGFILEINFO_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0207_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0207_v0_0_s_ifspec;
#ifndef __ICatalogFileInfo_INTERFACE_DEFINED__
#define __ICatalogFileInfo_INTERFACE_DEFINED__
typedef  ICatalogFileInfo *LPCATALOGFILEINFO;
EXTERN_C const IID IID_ICatalogFileInfo;
typedef struct ICatalogFileInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(ICatalogFileInfo *,REFIID,void **);
 ULONG ( *AddRef)(ICatalogFileInfo *);
 ULONG ( *Release)(ICatalogFileInfo *);
 HRESULT ( *GetCatalogFile)(ICatalogFileInfo *,LPSTR *);
 HRESULT ( *GetJavaTrust)(ICatalogFileInfo *,void **);
END_INTERFACE
} ICatalogFileInfoVtbl;
interface ICatalogFileInfo
{
CONST_VTBL struct ICatalogFileInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICatalogFileInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICatalogFileInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICatalogFileInfo_Release(A) (A)->lpVtbl->Release(A)
#define ICatalogFileInfo_GetCatalogFile(A,B) (A)->lpVtbl->GetCatalogFile(A,B)
#define ICatalogFileInfo_GetJavaTrust(A,B) (A)->lpVtbl->GetJavaTrust(A,B)
#endif 
HRESULT ICatalogFileInfo_GetCatalogFile_Proxy(ICatalogFileInfo *,LPSTR *);
void __RPC_STUB ICatalogFileInfo_GetCatalogFile_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICatalogFileInfo_GetJavaTrust_Proxy(ICatalogFileInfo *,void **);
void __RPC_STUB ICatalogFileInfo_GetJavaTrust_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPDATAFILTER_DEFINED
#define _LPDATAFILTER_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0208_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0208_v0_0_s_ifspec;
#ifndef __IDataFilter_INTERFACE_DEFINED__
#define __IDataFilter_INTERFACE_DEFINED__
typedef  IDataFilter *LPDATAFILTER;
EXTERN_C const IID IID_IDataFilter;
typedef struct IDataFilterVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IDataFilter *,REFIID,void **);
 ULONG ( *AddRef)(IDataFilter *);
 ULONG ( *Release)(IDataFilter *);
 HRESULT ( *DoEncode)(IDataFilter *,DWORD,LONG,BYTE *,LONG,BYTE *,LONG,LONG *,LONG *,DWORD);
 HRESULT ( *DoDecode)(IDataFilter *,DWORD,LONG,BYTE *,LONG,BYTE *,LONG,LONG *,LONG *,DWORD);
 HRESULT ( *SetEncodingLevel)(IDataFilter *,DWORD);
END_INTERFACE
} IDataFilterVtbl;
interface IDataFilter
{
CONST_VTBL struct IDataFilterVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IDataFilter_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IDataFilter_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IDataFilter_Release(A) (A)->lpVtbl->Release(A)
#define IDataFilter_DoEncode(A,B,C,D,E,F,G,H,I,J) (A)->lpVtbl->DoEncode(A,B,C,D,E,F,G,H,I,J)
#define IDataFilter_DoDecode(A,B,C,D,E,F,G,H,I,J) (A)->lpVtbl->DoDecode(A,B,C,D,E,F,G,H,I,J)
#define IDataFilter_SetEncodingLevel(A,B) (A)->lpVtbl->SetEncodingLevel(A,B)
#endif 
HRESULT IDataFilter_DoEncode_Proxy(IDataFilter *,DWORD ,LONG ,BYTE *,LONG ,BYTE *,LONG ,LONG *,LONG *,DWORD );
void __RPC_STUB IDataFilter_DoEncode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDataFilter_DoDecode_Proxy(IDataFilter *,DWORD ,LONG ,BYTE *,LONG ,BYTE *,LONG ,LONG *,LONG *,DWORD );
void __RPC_STUB IDataFilter_DoDecode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDataFilter_SetEncodingLevel_Proxy(IDataFilter *,DWORD );
void __RPC_STUB IDataFilter_SetEncodingLevel_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _LPENCODINGFILTERFACTORY_DEFINED
#define _LPENCODINGFILTERFACTORY_DEFINED
typedef struct _tagPROTOCOLFILTERDATA
{
DWORD cbSize;
IInternetProtocolSink *pProtocolSink;
IInternetProtocol *pProtocol;
IUnknown *pUnk;
DWORD dwFilterFlags;
} PROTOCOLFILTERDATA;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0209_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0209_v0_0_s_ifspec;
#ifndef __IEncodingFilterFactory_INTERFACE_DEFINED__
#define __IEncodingFilterFactory_INTERFACE_DEFINED__
typedef  IEncodingFilterFactory *LPENCODINGFILTERFACTORY;
typedef struct _tagDATAINFO
{
ULONG ulTotalSize;
ULONG ulavrPacketSize;
ULONG ulConnectSpeed;
ULONG ulProcessorSpeed;
} DATAINFO;
EXTERN_C const IID IID_IEncodingFilterFactory;
typedef struct IEncodingFilterFactoryVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IEncodingFilterFactory *,REFIID,void **);
 ULONG ( *AddRef)(IEncodingFilterFactory *);
 ULONG ( *Release)(IEncodingFilterFactory *);
 HRESULT ( *FindBestFilter)(IEncodingFilterFactory *,LPCWSTR,LPCWSTR,DATAINFO,IDataFilter **);
 HRESULT ( *GetDefaultFilter)(IEncodingFilterFactory *,LPCWSTR,LPCWSTR,IDataFilter **);
END_INTERFACE
} IEncodingFilterFactoryVtbl;
interface IEncodingFilterFactory
{
CONST_VTBL struct IEncodingFilterFactoryVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEncodingFilterFactory_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEncodingFilterFactory_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEncodingFilterFactory_Release(A) (A)->lpVtbl->Release(A)
#define IEncodingFilterFactory_FindBestFilter(A,B,C,D,E) (A)->lpVtbl->FindBestFilter(A,B,C,D,E)
#define IEncodingFilterFactory_GetDefaultFilter(A,B,C,D) (A)->lpVtbl->GetDefaultFilter(A,B,C,D)
#endif 
HRESULT IEncodingFilterFactory_FindBestFilter_Proxy(IEncodingFilterFactory *,LPCWSTR ,LPCWSTR ,DATAINFO ,IDataFilter **);
void __RPC_STUB IEncodingFilterFactory_FindBestFilter_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IEncodingFilterFactory_GetDefaultFilter_Proxy(IEncodingFilterFactory *,LPCWSTR ,LPCWSTR ,IDataFilter **);
void __RPC_STUB IEncodingFilterFactory_GetDefaultFilter_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
#ifndef _HITLOGGING_DEFINED
#define _HITLOGGING_DEFINED
BOOL WINAPI IsLoggingEnabledA(IN LPCSTR pszUrl); 
BOOL WINAPI IsLoggingEnabledW(IN LPCWSTR pwszUrl); 
#ifdef UNICODE 
#define IsLoggingEnabled IsLoggingEnabledW 
#else 
#define IsLoggingEnabled IsLoggingEnabledA 
#endif 
typedef struct _tagHIT_LOGGING_INFO
{
DWORD dwStructSize;
LPSTR lpszLoggedUrlName;
SYSTEMTIME StartTime;
SYSTEMTIME EndTime;
LPSTR lpszExtendedInfo;
} HIT_LOGGING_INFO;
typedef struct _tagHIT_LOGGING_INFO *LPHIT_LOGGING_INFO;
BOOL WINAPI WriteHitLogging(IN LPHIT_LOGGING_INFO lpLogginginfo); 
#define CONFIRMSAFETYACTION_LOADOBJECT 1
struct CONFIRMSAFETY
{
CLSID clsid;
IUnknown *pUnk;
DWORD dwFlags;
} ;
EXTERN_C const GUID GUID_CUSTOM_CONFIRMOBJECTSAFETY; 
#endif
#ifndef _LPIWRAPPEDPROTOCOL_DEFINED
#define _LPIWRAPPEDPROTOCOL_DEFINED
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0210_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0210_v0_0_s_ifspec;
#ifndef __IWrappedProtocol_INTERFACE_DEFINED__
#define __IWrappedProtocol_INTERFACE_DEFINED__
typedef  IWrappedProtocol *LPIWRAPPEDPROTOCOL;
EXTERN_C const IID IID_IWrappedProtocol;
typedef struct IWrappedProtocolVtbl
{
 BEGIN_INTERFACE
 HRESULT ( *QueryInterface)(IWrappedProtocol *,REFIID,void **);
 ULONG ( *AddRef)(IWrappedProtocol *);
 ULONG ( *Release)(IWrappedProtocol *);
 HRESULT ( *GetWrapperCode)(IWrappedProtocol *,LONG *,DWORD_PTR);
END_INTERFACE
} IWrappedProtocolVtbl;
interface IWrappedProtocol
{
CONST_VTBL struct IWrappedProtocolVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWrappedProtocol_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWrappedProtocol_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWrappedProtocol_Release(A) (A)->lpVtbl->Release(A)
#define IWrappedProtocol_GetWrapperCode(A,B,C) (A)->lpVtbl->GetWrapperCode(A,B,C)
#endif 
HRESULT IWrappedProtocol_GetWrapperCode_Proxy(IWrappedProtocol *,LONG *,DWORD_PTR );
void __RPC_STUB IWrappedProtocol_GetWrapperCode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#endif
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0211_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_urlmon_0211_v0_0_s_ifspec;
unsigned long __RPC_USER HWND_UserSize(unsigned long *,unsigned ,HWND *); 
unsigned char * __RPC_USER HWND_UserMarshal(unsigned long *,unsigned char *,HWND *); 
unsigned char * __RPC_USER HWND_UserUnmarshal(unsigned long *,unsigned char *,HWND *); 
void __RPC_USER HWND_UserFree(unsigned long *,HWND *); 
HRESULT IBinding_GetBindResult_Proxy(IBinding *,CLSID *,DWORD *,LPOLESTR *,DWORD *);
HRESULT IBinding_GetBindResult_Stub(IBinding *,CLSID *,DWORD *,LPOLESTR *,DWORD );
HRESULT IBindStatusCallback_GetBindInfo_Proxy(IBindStatusCallback *,DWORD *,BINDINFO *);
HRESULT IBindStatusCallback_GetBindInfo_Stub(IBindStatusCallback *,DWORD *,RemBINDINFO *,RemSTGMEDIUM *);
HRESULT IBindStatusCallback_OnDataAvailable_Proxy(IBindStatusCallback *,DWORD ,DWORD ,FORMATETC *,STGMEDIUM *);
HRESULT IBindStatusCallback_OnDataAvailable_Stub(IBindStatusCallback *,DWORD ,DWORD ,RemFORMATETC *,RemSTGMEDIUM *);
HRESULT IWinInetInfo_QueryOption_Proxy(IWinInetInfo *,DWORD ,LPVOID ,DWORD *);
HRESULT IWinInetInfo_QueryOption_Stub(IWinInetInfo *,DWORD ,BYTE *,DWORD *);
HRESULT IWinInetHttpInfo_QueryInfo_Proxy(IWinInetHttpInfo *,DWORD ,LPVOID ,DWORD *,DWORD *,DWORD *);
HRESULT IWinInetHttpInfo_QueryInfo_Stub(IWinInetHttpInfo *,DWORD ,BYTE *,DWORD *,DWORD *,DWORD *);
HRESULT IBindHost_MonikerBindToStorage_Proxy(IBindHost *,IMoniker *,IBindCtx *,IBindStatusCallback *,REFIID ,void **);
HRESULT IBindHost_MonikerBindToStorage_Stub(IBindHost *,IMoniker *,IBindCtx *,IBindStatusCallback *,REFIID ,IUnknown **);
HRESULT IBindHost_MonikerBindToObject_Proxy(IBindHost *,IMoniker *,IBindCtx *,IBindStatusCallback *,REFIID ,void **);
HRESULT IBindHost_MonikerBindToObject_Stub(IBindHost *,IMoniker *,IBindCtx *,IBindStatusCallback *,REFIID ,IUnknown **);
#endif
