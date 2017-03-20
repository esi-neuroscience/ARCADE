#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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
#ifndef __oleidl_h__
#define __oleidl_h__
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#endif
#ifndef __IOleAdviseHolder_FWD_DEFINED__
#define __IOleAdviseHolder_FWD_DEFINED__
typedef interface IOleAdviseHolder IOleAdviseHolder;
#endif 
#ifndef __IOleCache_FWD_DEFINED__
#define __IOleCache_FWD_DEFINED__
typedef interface IOleCache IOleCache;
#endif 
#ifndef __IOleCache2_FWD_DEFINED__
#define __IOleCache2_FWD_DEFINED__
typedef interface IOleCache2 IOleCache2;
#endif 
#ifndef __IOleCacheControl_FWD_DEFINED__
#define __IOleCacheControl_FWD_DEFINED__
typedef interface IOleCacheControl IOleCacheControl;
#endif 
#ifndef __IParseDisplayName_FWD_DEFINED__
#define __IParseDisplayName_FWD_DEFINED__
typedef interface IParseDisplayName IParseDisplayName;
#endif 
#ifndef __IOleContainer_FWD_DEFINED__
#define __IOleContainer_FWD_DEFINED__
typedef interface IOleContainer IOleContainer;
#endif 
#ifndef __IOleClientSite_FWD_DEFINED__
#define __IOleClientSite_FWD_DEFINED__
typedef interface IOleClientSite IOleClientSite;
#endif 
#ifndef __IOleObject_FWD_DEFINED__
#define __IOleObject_FWD_DEFINED__
typedef interface IOleObject IOleObject;
#endif 
#ifndef __IOleWindow_FWD_DEFINED__
#define __IOleWindow_FWD_DEFINED__
typedef interface IOleWindow IOleWindow;
#endif 
#ifndef __IOleLink_FWD_DEFINED__
#define __IOleLink_FWD_DEFINED__
typedef interface IOleLink IOleLink;
#endif 
#ifndef __IOleItemContainer_FWD_DEFINED__
#define __IOleItemContainer_FWD_DEFINED__
typedef interface IOleItemContainer IOleItemContainer;
#endif 
#ifndef __IOleInPlaceUIWindow_FWD_DEFINED__
#define __IOleInPlaceUIWindow_FWD_DEFINED__
typedef interface IOleInPlaceUIWindow IOleInPlaceUIWindow;
#endif 
#ifndef __IOleInPlaceActiveObject_FWD_DEFINED__
#define __IOleInPlaceActiveObject_FWD_DEFINED__
typedef interface IOleInPlaceActiveObject IOleInPlaceActiveObject;
#endif 
#ifndef __IOleInPlaceFrame_FWD_DEFINED__
#define __IOleInPlaceFrame_FWD_DEFINED__
typedef interface IOleInPlaceFrame IOleInPlaceFrame;
#endif 
#ifndef __IOleInPlaceObject_FWD_DEFINED__
#define __IOleInPlaceObject_FWD_DEFINED__
typedef interface IOleInPlaceObject IOleInPlaceObject;
#endif 
#ifndef __IOleInPlaceSite_FWD_DEFINED__
#define __IOleInPlaceSite_FWD_DEFINED__
typedef interface IOleInPlaceSite IOleInPlaceSite;
#endif 
#ifndef __IContinue_FWD_DEFINED__
#define __IContinue_FWD_DEFINED__
typedef interface IContinue IContinue;
#endif 
#ifndef __IViewObject_FWD_DEFINED__
#define __IViewObject_FWD_DEFINED__
typedef interface IViewObject IViewObject;
#endif 
#ifndef __IViewObject2_FWD_DEFINED__
#define __IViewObject2_FWD_DEFINED__
typedef interface IViewObject2 IViewObject2;
#endif 
#ifndef __IDropSource_FWD_DEFINED__
#define __IDropSource_FWD_DEFINED__
typedef interface IDropSource IDropSource;
#endif 
#ifndef __IDropTarget_FWD_DEFINED__
#define __IDropTarget_FWD_DEFINED__
typedef interface IDropTarget IDropTarget;
#endif 
#ifndef __IEnumOLEVERB_FWD_DEFINED__
#define __IEnumOLEVERB_FWD_DEFINED__
typedef interface IEnumOLEVERB IEnumOLEVERB;
#endif 
#include "objidl.h"
void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void *); 
#if (_MSC_VER >= 1020)
#endif
extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oleidl_0000_v0_0_s_ifspec;
#ifndef __IOleAdviseHolder_INTERFACE_DEFINED__
#define __IOleAdviseHolder_INTERFACE_DEFINED__
typedef  IOleAdviseHolder *LPOLEADVISEHOLDER;
EXTERN_C const IID IID_IOleAdviseHolder;
typedef struct IOleAdviseHolderVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleAdviseHolder *,REFIID,void **);
 ULONG (*AddRef)(IOleAdviseHolder *);
 ULONG (*Release)(IOleAdviseHolder *);
 HRESULT (*Advise)(IOleAdviseHolder *,IAdviseSink *,DWORD *);
 HRESULT (*Unadvise)(IOleAdviseHolder *,DWORD);
 HRESULT (*EnumAdvise)(IOleAdviseHolder *,IEnumSTATDATA **);
 HRESULT (*SendOnRename)(IOleAdviseHolder *,IMoniker *);
 HRESULT (*SendOnSave)(IOleAdviseHolder *);
 HRESULT (*SendOnClose)(IOleAdviseHolder *);
END_INTERFACE
} IOleAdviseHolderVtbl;
interface IOleAdviseHolder
{
CONST_VTBL struct IOleAdviseHolderVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleAdviseHolder_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleAdviseHolder_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleAdviseHolder_Release(A) (A)->lpVtbl->Release(A)
#define IOleAdviseHolder_Advise(A,B,C) (A)->lpVtbl->Advise(A,B,C)
#define IOleAdviseHolder_Unadvise(A,B) (A)->lpVtbl->Unadvise(A,B)
#define IOleAdviseHolder_EnumAdvise(A,B) (A)->lpVtbl->EnumAdvise(A,B)
#define IOleAdviseHolder_SendOnRename(A,B) (A)->lpVtbl->SendOnRename(A,B)
#define IOleAdviseHolder_SendOnSave(A) (A)->lpVtbl->SendOnSave(A)
#define IOleAdviseHolder_SendOnClose(A) (A)->lpVtbl->SendOnClose(A)
#endif 
HRESULT IOleAdviseHolder_Advise_Proxy(IOleAdviseHolder *,IAdviseSink *,DWORD *);
void __RPC_STUB IOleAdviseHolder_Advise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleAdviseHolder_Unadvise_Proxy(IOleAdviseHolder *,DWORD );
void __RPC_STUB IOleAdviseHolder_Unadvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleAdviseHolder_EnumAdvise_Proxy(IOleAdviseHolder *,IEnumSTATDATA **);
void __RPC_STUB IOleAdviseHolder_EnumAdvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleAdviseHolder_SendOnRename_Proxy(IOleAdviseHolder *,IMoniker *);
void __RPC_STUB IOleAdviseHolder_SendOnRename_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleAdviseHolder_SendOnSave_Proxy(IOleAdviseHolder *);
void __RPC_STUB IOleAdviseHolder_SendOnSave_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleAdviseHolder_SendOnClose_Proxy(IOleAdviseHolder *);
void __RPC_STUB IOleAdviseHolder_SendOnClose_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleCache_INTERFACE_DEFINED__
#define __IOleCache_INTERFACE_DEFINED__
typedef  IOleCache *LPOLECACHE;
EXTERN_C const IID IID_IOleCache;
typedef struct IOleCacheVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleCache *,REFIID,void **);
 ULONG (*AddRef)(IOleCache *);
 ULONG (*Release)(IOleCache *);
 HRESULT (*Cache)(IOleCache *,FORMATETC *,DWORD,DWORD *);
 HRESULT (*Uncache)(IOleCache *,DWORD);
 HRESULT (*EnumCache)(IOleCache *,IEnumSTATDATA **);
 HRESULT (*InitCache)(IOleCache *,IDataObject *);
 HRESULT (*SetData)(IOleCache *,FORMATETC *,STGMEDIUM *,BOOL);
END_INTERFACE
} IOleCacheVtbl;
interface IOleCache
{
CONST_VTBL struct IOleCacheVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleCache_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleCache_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleCache_Release(A) (A)->lpVtbl->Release(A)
#define IOleCache_Cache(A,B,C,D) (A)->lpVtbl->Cache(A,B,C,D)
#define IOleCache_Uncache(A,B) (A)->lpVtbl->Uncache(A,B)
#define IOleCache_EnumCache(A,B) (A)->lpVtbl->EnumCache(A,B)
#define IOleCache_InitCache(A,B) (A)->lpVtbl->InitCache(A,B)
#define IOleCache_SetData(A,B,C,D) (A)->lpVtbl->SetData(A,B,C,D)
#endif 
HRESULT IOleCache_Cache_Proxy(IOleCache *,FORMATETC *,DWORD ,DWORD *);
void __RPC_STUB IOleCache_Cache_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleCache_Uncache_Proxy(IOleCache *,DWORD );
void __RPC_STUB IOleCache_Uncache_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleCache_EnumCache_Proxy(IOleCache *,IEnumSTATDATA **);
void __RPC_STUB IOleCache_EnumCache_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleCache_InitCache_Proxy(IOleCache *,IDataObject *);
void __RPC_STUB IOleCache_InitCache_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleCache_SetData_Proxy(IOleCache *,FORMATETC *,STGMEDIUM *,BOOL );
void __RPC_STUB IOleCache_SetData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleCache2_INTERFACE_DEFINED__
#define __IOleCache2_INTERFACE_DEFINED__
typedef  IOleCache2 *LPOLECACHE2;
#define	UPDFCACHE_NODATACACHE	1
#define	UPDFCACHE_ONSAVECACHE	2
#define	UPDFCACHE_ONSTOPCACHE	4
#define	UPDFCACHE_NORMALCACHE	8
#define	UPDFCACHE_IFBLANK	16
#define	UPDFCACHE_ONLYIFBLANK	0x80000000
#define	UPDFCACHE_IFBLANKORONSAVECACHE	(UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE)
#define	UPDFCACHE_ALL	((DWORD)~UPDFCACHE_ONLYIFBLANK)
#define	UPDFCACHE_ALLBUTNODATACACHE	(UPDFCACHE_ALL & (DWORD)~UPDFCACHE_NODATACACHE)
typedef  
enum tagDISCARDCACHE
{	DISCARDCACHE_SAVEIFDIRTY=0,
DISCARDCACHE_NOSAVE=1
} DISCARDCACHE;
EXTERN_C const IID IID_IOleCache2;
typedef struct IOleCache2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleCache2 *,REFIID,void **);
 ULONG (*AddRef)(IOleCache2 *);
 ULONG (*Release)(IOleCache2 *);
 HRESULT (*Cache)(IOleCache2 *,FORMATETC *,DWORD,DWORD *);
 HRESULT (*Uncache)(IOleCache2 *,DWORD);
 HRESULT (*EnumCache)(IOleCache2 *,IEnumSTATDATA **);
 HRESULT (*InitCache)(IOleCache2 *,IDataObject *);
 HRESULT (*SetData)(IOleCache2 *,FORMATETC *,STGMEDIUM *,BOOL);
 HRESULT (*UpdateCache)(IOleCache2 *,LPDATAOBJECT,DWORD,LPVOID);
 HRESULT (*DiscardCache)(IOleCache2 *,DWORD);
END_INTERFACE
} IOleCache2Vtbl;
interface IOleCache2
{
CONST_VTBL struct IOleCache2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleCache2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleCache2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleCache2_Release(A) (A)->lpVtbl->Release(A)
#define IOleCache2_Cache(A,B,C,D) (A)->lpVtbl->Cache(A,B,C,D)
#define IOleCache2_Uncache(A,B) (A)->lpVtbl->Uncache(A,B)
#define IOleCache2_EnumCache(A,B) (A)->lpVtbl->EnumCache(A,B)
#define IOleCache2_InitCache(A,B) (A)->lpVtbl->InitCache(A,B)
#define IOleCache2_SetData(A,B,C,D) (A)->lpVtbl->SetData(A,B,C,D)
#define IOleCache2_UpdateCache(A,B,C,D) (A)->lpVtbl->UpdateCache(A,B,C,D)
#define IOleCache2_DiscardCache(A,B) (A)->lpVtbl->DiscardCache(A,B)
#endif 
HRESULT IOleCache2_RemoteUpdateCache_Proxy(IOleCache2 *,LPDATAOBJECT ,DWORD ,LONG_PTR );
void __RPC_STUB IOleCache2_RemoteUpdateCache_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleCache2_DiscardCache_Proxy(IOleCache2 *,DWORD );
void __RPC_STUB IOleCache2_DiscardCache_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleCacheControl_INTERFACE_DEFINED__
#define __IOleCacheControl_INTERFACE_DEFINED__
typedef  IOleCacheControl *LPOLECACHECONTROL;
EXTERN_C const IID IID_IOleCacheControl;
typedef struct IOleCacheControlVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleCacheControl *,REFIID,void **);
 ULONG (*AddRef)(IOleCacheControl *);
 ULONG (*Release)(IOleCacheControl *);
 HRESULT (*OnRun)(IOleCacheControl *,LPDATAOBJECT);
 HRESULT (*OnStop)(IOleCacheControl *);
END_INTERFACE
} IOleCacheControlVtbl;
interface IOleCacheControl
{
CONST_VTBL struct IOleCacheControlVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleCacheControl_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleCacheControl_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleCacheControl_Release(A) (A)->lpVtbl->Release(A)
#define IOleCacheControl_OnRun(A,B) (A)->lpVtbl->OnRun(A,B)
#define IOleCacheControl_OnStop(A) (A)->lpVtbl->OnStop(A)
#endif 
HRESULT IOleCacheControl_OnRun_Proxy(IOleCacheControl *,LPDATAOBJECT );
void __RPC_STUB IOleCacheControl_OnRun_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleCacheControl_OnStop_Proxy(IOleCacheControl *);
void __RPC_STUB IOleCacheControl_OnStop_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IParseDisplayName_INTERFACE_DEFINED__
#define __IParseDisplayName_INTERFACE_DEFINED__
typedef  IParseDisplayName *LPPARSEDISPLAYNAME;
EXTERN_C const IID IID_IParseDisplayName;
typedef struct IParseDisplayNameVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IParseDisplayName *,REFIID,void **);
 ULONG (*AddRef)(IParseDisplayName *);
 ULONG (*Release)(IParseDisplayName *);
 HRESULT (*ParseDisplayName)(IParseDisplayName *,IBindCtx *,LPOLESTR,ULONG *,IMoniker **);
END_INTERFACE
} IParseDisplayNameVtbl;
interface IParseDisplayName
{
CONST_VTBL struct IParseDisplayNameVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IParseDisplayName_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IParseDisplayName_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IParseDisplayName_Release(A) (A)->lpVtbl->Release(A)
#define IParseDisplayName_ParseDisplayName(A,B,C,D,E) (A)->lpVtbl->ParseDisplayName(A,B,C,D,E)
#endif 
HRESULT IParseDisplayName_ParseDisplayName_Proxy(IParseDisplayName *,IBindCtx *,LPOLESTR ,ULONG *,IMoniker **);
void __RPC_STUB IParseDisplayName_ParseDisplayName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleContainer_INTERFACE_DEFINED__
#define __IOleContainer_INTERFACE_DEFINED__
typedef  IOleContainer *LPOLECONTAINER;
EXTERN_C const IID IID_IOleContainer;
typedef struct IOleContainerVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleContainer *,REFIID,void **);
 ULONG (*AddRef)(IOleContainer *);
 ULONG (*Release)(IOleContainer *);
 HRESULT (*ParseDisplayName)(IOleContainer *,IBindCtx *,LPOLESTR,ULONG *,IMoniker **);
 HRESULT (*EnumObjects)(IOleContainer *,DWORD,IEnumUnknown **);
 HRESULT (*LockContainer)(IOleContainer *,BOOL);
END_INTERFACE
} IOleContainerVtbl;
interface IOleContainer
{
CONST_VTBL struct IOleContainerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleContainer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleContainer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleContainer_Release(A) (A)->lpVtbl->Release(A)
#define IOleContainer_ParseDisplayName(A,B,C,D,E) (A)->lpVtbl->ParseDisplayName(A,B,C,D,E)
#define IOleContainer_EnumObjects(A,B,C) (A)->lpVtbl->EnumObjects(A,B,C)
#define IOleContainer_LockContainer(A,B) (A)->lpVtbl->LockContainer(A,B)
#endif 
HRESULT IOleContainer_EnumObjects_Proxy(IOleContainer *,DWORD ,IEnumUnknown **);
void __RPC_STUB IOleContainer_EnumObjects_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleContainer_LockContainer_Proxy(IOleContainer *,BOOL );
void __RPC_STUB IOleContainer_LockContainer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleClientSite_INTERFACE_DEFINED__
#define __IOleClientSite_INTERFACE_DEFINED__
typedef  IOleClientSite *LPOLECLIENTSITE;
EXTERN_C const IID IID_IOleClientSite;
typedef struct IOleClientSiteVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleClientSite *,REFIID,void **);
 ULONG (*AddRef)(IOleClientSite *);
 ULONG (*Release)(IOleClientSite *);
 HRESULT (*SaveObject)(IOleClientSite *);
 HRESULT (*GetMoniker)(IOleClientSite *,DWORD,DWORD,IMoniker **);
 HRESULT (*GetContainer)(IOleClientSite *,IOleContainer **);
 HRESULT (*ShowObject)(IOleClientSite *);
 HRESULT (*OnShowWindow)(IOleClientSite *,BOOL);
 HRESULT (*RequestNewObjectLayout)(IOleClientSite *);
END_INTERFACE
} IOleClientSiteVtbl;
interface IOleClientSite
{
CONST_VTBL struct IOleClientSiteVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleClientSite_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleClientSite_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleClientSite_Release(A) (A)->lpVtbl->Release(A)
#define IOleClientSite_SaveObject(A) (A)->lpVtbl->SaveObject(A)
#define IOleClientSite_GetMoniker(A,B,C,D) (A)->lpVtbl->GetMoniker(A,B,C,D)
#define IOleClientSite_GetContainer(A,B) (A)->lpVtbl->GetContainer(A,B)
#define IOleClientSite_ShowObject(A) (A)->lpVtbl->ShowObject(A)
#define IOleClientSite_OnShowWindow(A,B) (A)->lpVtbl->OnShowWindow(A,B)
#define IOleClientSite_RequestNewObjectLayout(A) (A)->lpVtbl->RequestNewObjectLayout(A)
#endif 
HRESULT IOleClientSite_SaveObject_Proxy(IOleClientSite *);
void __RPC_STUB IOleClientSite_SaveObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleClientSite_GetMoniker_Proxy(IOleClientSite *,DWORD ,DWORD ,IMoniker **);
void __RPC_STUB IOleClientSite_GetMoniker_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleClientSite_GetContainer_Proxy(IOleClientSite *,IOleContainer **);
void __RPC_STUB IOleClientSite_GetContainer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleClientSite_ShowObject_Proxy(IOleClientSite *);
void __RPC_STUB IOleClientSite_ShowObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleClientSite_OnShowWindow_Proxy(IOleClientSite *,BOOL );
void __RPC_STUB IOleClientSite_OnShowWindow_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleClientSite_RequestNewObjectLayout_Proxy(IOleClientSite *);
void __RPC_STUB IOleClientSite_RequestNewObjectLayout_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleObject_INTERFACE_DEFINED__
#define __IOleObject_INTERFACE_DEFINED__
typedef  IOleObject *LPOLEOBJECT;
typedef 
enum tagOLEGETMONIKER
{	OLEGETMONIKER_ONLYIFTHERE=1,
OLEGETMONIKER_FORCEASSIGN=2,
OLEGETMONIKER_UNASSIGN=3,
OLEGETMONIKER_TEMPFORUSER=4
} OLEGETMONIKER;
typedef 
enum tagOLEWHICHMK
{	OLEWHICHMK_CONTAINER=1,
OLEWHICHMK_OBJREL=2,
OLEWHICHMK_OBJFULL=3
} OLEWHICHMK;
typedef 
enum tagUSERCLASSTYPE
{	USERCLASSTYPE_FULL=1,
USERCLASSTYPE_SHORT=2,
USERCLASSTYPE_APPNAME=3
} USERCLASSTYPE;
typedef 
enum tagOLEMISC
{	OLEMISC_RECOMPOSEONRESIZE=1,
OLEMISC_ONLYICONIC=2,
OLEMISC_INSERTNOTREPLACE=4,
OLEMISC_STATIC=8,
OLEMISC_CANTLINKINSIDE=16,
OLEMISC_CANLINKBYOLE1=32,
OLEMISC_ISLINKOBJECT=64,
OLEMISC_INSIDEOUT=128,
OLEMISC_ACTIVATEWHENVISIBLE=256,
OLEMISC_RENDERINGISDEVICEINDEPENDENT=512,
OLEMISC_INVISIBLEATRUNTIME=1024,
OLEMISC_ALWAYSRUN=2048,
OLEMISC_ACTSLIKEBUTTON=4096,
OLEMISC_ACTSLIKELABEL=0x2000,
OLEMISC_NOUIACTIVATE=0x4000,
OLEMISC_ALIGNABLE=0x8000,
OLEMISC_SIMPLEFRAME=0x10000,
OLEMISC_SETCLIENTSITEFIRST=0x20000,
OLEMISC_IMEMODE=0x40000,
OLEMISC_IGNOREACTIVATEWHENVISIBLE=0x80000,
OLEMISC_WANTSTOMENUMERGE=0x100000,
OLEMISC_SUPPORTSMULTILEVELUNDO=0x200000
} OLEMISC;
typedef 
enum tagOLECLOSE
{	OLECLOSE_SAVEIFDIRTY=0,
OLECLOSE_NOSAVE=1,
OLECLOSE_PROMPTSAVE=2
} OLECLOSE;
EXTERN_C const IID IID_IOleObject;
typedef struct IOleObjectVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleObject *,REFIID,void **);
 ULONG (*AddRef)(IOleObject *);
 ULONG (*Release)(IOleObject *);
 HRESULT (*SetClientSite)(IOleObject *,IOleClientSite *);
 HRESULT (*GetClientSite)(IOleObject *,IOleClientSite **);
 HRESULT (*SetHostNames)(IOleObject *,LPCOLESTR,LPCOLESTR);
 HRESULT (*Close)(IOleObject *,DWORD);
 HRESULT (*SetMoniker)(IOleObject *,DWORD,IMoniker *);
 HRESULT (*GetMoniker)(IOleObject *,DWORD,DWORD,IMoniker **);
 HRESULT (*InitFromData)(IOleObject *,IDataObject *,BOOL,DWORD);
 HRESULT (*GetClipboardData)(IOleObject *,DWORD,IDataObject **);
 HRESULT (*DoVerb)(IOleObject *,LONG,LPMSG,IOleClientSite *,LONG,HWND,LPCRECT);
 HRESULT (*EnumVerbs)(IOleObject *,IEnumOLEVERB **);
 HRESULT (*Update)(IOleObject *);
 HRESULT (*IsUpToDate)(IOleObject *);
 HRESULT (*GetUserClassID)(IOleObject *,CLSID *);
 HRESULT (*GetUserType)(IOleObject *,DWORD,LPOLESTR *);
 HRESULT (*SetExtent)(IOleObject *,DWORD,SIZEL *);
 HRESULT (*GetExtent)(IOleObject *,DWORD,SIZEL *);
 HRESULT (*Advise)(IOleObject *,IAdviseSink *,DWORD *);
 HRESULT (*Unadvise)(IOleObject *,DWORD);
 HRESULT (*EnumAdvise)(IOleObject *,IEnumSTATDATA **);
 HRESULT (*GetMiscStatus)(IOleObject *,DWORD,DWORD *);
 HRESULT (*SetColorScheme)(IOleObject *,LOGPALETTE *);
END_INTERFACE
} IOleObjectVtbl;
interface IOleObject
{
CONST_VTBL struct IOleObjectVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleObject_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleObject_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleObject_Release(A) (A)->lpVtbl->Release(A)
#define IOleObject_SetClientSite(A,B) (A)->lpVtbl->SetClientSite(A,B)
#define IOleObject_GetClientSite(A,B) (A)->lpVtbl->GetClientSite(A,B)
#define IOleObject_SetHostNames(A,B,C) (A)->lpVtbl->SetHostNames(A,B,C)
#define IOleObject_Close(A,B) (A)->lpVtbl->Close(A,B)
#define IOleObject_SetMoniker(A,B,C) (A)->lpVtbl->SetMoniker(A,B,C)
#define IOleObject_GetMoniker(A,B,C,D) (A)->lpVtbl->GetMoniker(A,B,C,D)
#define IOleObject_InitFromData(A,B,C,D) (A)->lpVtbl->InitFromData(A,B,C,D)
#define IOleObject_GetClipboardData(A,B,C) (A)->lpVtbl->GetClipboardData(A,B,C)
#define IOleObject_DoVerb(A,B,C,D,E,F,G) (A)->lpVtbl->DoVerb(A,B,C,D,E,F,G)
#define IOleObject_EnumVerbs(A,B) (A)->lpVtbl->EnumVerbs(A,B)
#define IOleObject_Update(A) (A)->lpVtbl->Update(A)
#define IOleObject_IsUpToDate(A) (A)->lpVtbl->IsUpToDate(A)
#define IOleObject_GetUserClassID(A,B) (A)->lpVtbl->GetUserClassID(A,B)
#define IOleObject_GetUserType(A,B,C) (A)->lpVtbl->GetUserType(A,B,C)
#define IOleObject_SetExtent(A,B,C) (A)->lpVtbl->SetExtent(A,B,C)
#define IOleObject_GetExtent(A,B,C) (A)->lpVtbl->GetExtent(A,B,C)
#define IOleObject_Advise(A,B,C) (A)->lpVtbl->Advise(A,B,C)
#define IOleObject_Unadvise(A,B) (A)->lpVtbl->Unadvise(A,B)
#define IOleObject_EnumAdvise(A,B) (A)->lpVtbl->EnumAdvise(A,B)
#define IOleObject_GetMiscStatus(A,B,C) (A)->lpVtbl->GetMiscStatus(A,B,C)
#define IOleObject_SetColorScheme(A,B) (A)->lpVtbl->SetColorScheme(A,B)
#endif 
HRESULT IOleObject_SetClientSite_Proxy(IOleObject *,IOleClientSite *);
void __RPC_STUB IOleObject_SetClientSite_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_GetClientSite_Proxy(IOleObject *,IOleClientSite **);
void __RPC_STUB IOleObject_GetClientSite_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_SetHostNames_Proxy(IOleObject *,LPCOLESTR ,LPCOLESTR );
void __RPC_STUB IOleObject_SetHostNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_Close_Proxy(IOleObject *,DWORD );
void __RPC_STUB IOleObject_Close_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_SetMoniker_Proxy(IOleObject *,DWORD ,IMoniker *);
void __RPC_STUB IOleObject_SetMoniker_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_GetMoniker_Proxy(IOleObject *,DWORD ,DWORD ,IMoniker **);
void __RPC_STUB IOleObject_GetMoniker_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_InitFromData_Proxy(IOleObject *,IDataObject *,BOOL ,DWORD );
void __RPC_STUB IOleObject_InitFromData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_GetClipboardData_Proxy(IOleObject *,DWORD ,IDataObject **);
void __RPC_STUB IOleObject_GetClipboardData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_DoVerb_Proxy(IOleObject *,LONG ,LPMSG ,IOleClientSite *,LONG ,HWND ,LPCRECT );
void __RPC_STUB IOleObject_DoVerb_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_EnumVerbs_Proxy(IOleObject *,IEnumOLEVERB **);
void __RPC_STUB IOleObject_EnumVerbs_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_Update_Proxy(IOleObject *);
void __RPC_STUB IOleObject_Update_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_IsUpToDate_Proxy(IOleObject *);
void __RPC_STUB IOleObject_IsUpToDate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_GetUserClassID_Proxy(IOleObject *,CLSID *);
void __RPC_STUB IOleObject_GetUserClassID_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_GetUserType_Proxy(IOleObject *,DWORD ,LPOLESTR *);
void __RPC_STUB IOleObject_GetUserType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_SetExtent_Proxy(IOleObject *,DWORD ,SIZEL *);
void __RPC_STUB IOleObject_SetExtent_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_GetExtent_Proxy(IOleObject *,DWORD ,SIZEL *);
void __RPC_STUB IOleObject_GetExtent_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_Advise_Proxy(IOleObject *,IAdviseSink *,DWORD *);
void __RPC_STUB IOleObject_Advise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_Unadvise_Proxy(IOleObject *,DWORD );
void __RPC_STUB IOleObject_Unadvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_EnumAdvise_Proxy(IOleObject *,IEnumSTATDATA **);
void __RPC_STUB IOleObject_EnumAdvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_GetMiscStatus_Proxy(IOleObject *,DWORD ,DWORD *);
void __RPC_STUB IOleObject_GetMiscStatus_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleObject_SetColorScheme_Proxy(IOleObject *,LOGPALETTE *);
void __RPC_STUB IOleObject_SetColorScheme_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOLETypes_INTERFACE_DEFINED__
#define __IOLETypes_INTERFACE_DEFINED__
typedef 
enum tagOLERENDER
{	OLERENDER_NONE=0,
OLERENDER_DRAW=1,
OLERENDER_FORMAT=2,
OLERENDER_ASIS=3
} OLERENDER;
typedef OLERENDER *LPOLERENDER;
typedef struct tagOBJECTDESCRIPTOR
{
ULONG cbSize;
CLSID clsid;
DWORD dwDrawAspect;
SIZEL sizel;
POINTL pointl;
DWORD dwStatus;
DWORD dwFullUserTypeName;
DWORD dwSrcOfCopy;
} OBJECTDESCRIPTOR;
typedef struct tagOBJECTDESCRIPTOR *POBJECTDESCRIPTOR;
typedef struct tagOBJECTDESCRIPTOR *LPOBJECTDESCRIPTOR;
typedef struct tagOBJECTDESCRIPTOR LINKSRCDESCRIPTOR;
typedef struct tagOBJECTDESCRIPTOR *PLINKSRCDESCRIPTOR;
typedef struct tagOBJECTDESCRIPTOR *LPLINKSRCDESCRIPTOR;
extern RPC_IF_HANDLE IOLETypes_v0_0_c_ifspec;
extern RPC_IF_HANDLE IOLETypes_v0_0_s_ifspec;
#endif 
#ifndef __IOleWindow_INTERFACE_DEFINED__
#define __IOleWindow_INTERFACE_DEFINED__
typedef  IOleWindow *LPOLEWINDOW;
EXTERN_C const IID IID_IOleWindow;
typedef struct IOleWindowVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleWindow *,REFIID,void **);
 ULONG (*AddRef)(IOleWindow *);
 ULONG (*Release)(IOleWindow *);
 HRESULT (*GetWindow)(IOleWindow *,HWND *);
 HRESULT (*ContextSensitiveHelp)(IOleWindow *,BOOL);
END_INTERFACE
} IOleWindowVtbl;
interface IOleWindow
{
CONST_VTBL struct IOleWindowVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleWindow_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleWindow_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleWindow_Release(A) (A)->lpVtbl->Release(A)
#define IOleWindow_GetWindow(A,B) (A)->lpVtbl->GetWindow(A,B)
#define IOleWindow_ContextSensitiveHelp(A,B) (A)->lpVtbl->ContextSensitiveHelp(A,B)
#endif 
HRESULT IOleWindow_GetWindow_Proxy(IOleWindow *,HWND *);
void __RPC_STUB IOleWindow_GetWindow_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleWindow_ContextSensitiveHelp_Proxy(IOleWindow *,BOOL );
void __RPC_STUB IOleWindow_ContextSensitiveHelp_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleLink_INTERFACE_DEFINED__
#define __IOleLink_INTERFACE_DEFINED__
typedef  IOleLink *LPOLELINK;
typedef 
enum tagOLEUPDATE
{	OLEUPDATE_ALWAYS=1,
OLEUPDATE_ONCALL=3
} OLEUPDATE;
typedef OLEUPDATE *LPOLEUPDATE;
typedef OLEUPDATE *POLEUPDATE;
typedef 
enum tagOLELINKBIND
{	OLELINKBIND_EVENIFCLASSDIFF=1
} OLELINKBIND;
EXTERN_C const IID IID_IOleLink;
typedef struct IOleLinkVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleLink *,REFIID,void **);
 ULONG (*AddRef)(IOleLink *);
 ULONG (*Release)(IOleLink *);
 HRESULT (*SetUpdateOptions)(IOleLink *,DWORD);
 HRESULT (*GetUpdateOptions)(IOleLink *,DWORD *);
 HRESULT (*SetSourceMoniker)(IOleLink *,IMoniker *,REFCLSID);
 HRESULT (*GetSourceMoniker)(IOleLink *,IMoniker **);
 HRESULT (*SetSourceDisplayName)(IOleLink *,LPCOLESTR);
 HRESULT (*GetSourceDisplayName)(IOleLink *,LPOLESTR *);
 HRESULT (*BindToSource)(IOleLink *,DWORD,IBindCtx *);
 HRESULT (*BindIfRunning)(IOleLink *);
 HRESULT (*GetBoundSource)(IOleLink *,IUnknown **);
 HRESULT (*UnbindSource)(IOleLink *);
 HRESULT (*Update)(IOleLink *,IBindCtx *);
END_INTERFACE
} IOleLinkVtbl;
interface IOleLink
{
CONST_VTBL struct IOleLinkVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleLink_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleLink_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleLink_Release(A) (A)->lpVtbl->Release(A)
#define IOleLink_SetUpdateOptions(A,B) (A)->lpVtbl->SetUpdateOptions(A,B)
#define IOleLink_GetUpdateOptions(A,B) (A)->lpVtbl->GetUpdateOptions(A,B)
#define IOleLink_SetSourceMoniker(A,B,C) (A)->lpVtbl->SetSourceMoniker(A,B,C)
#define IOleLink_GetSourceMoniker(A,B) (A)->lpVtbl->GetSourceMoniker(A,B)
#define IOleLink_SetSourceDisplayName(A,B) (A)->lpVtbl->SetSourceDisplayName(A,B)
#define IOleLink_GetSourceDisplayName(A,B) (A)->lpVtbl->GetSourceDisplayName(A,B)
#define IOleLink_BindToSource(A,B,C) (A)->lpVtbl->BindToSource(A,B,C)
#define IOleLink_BindIfRunning(A) (A)->lpVtbl->BindIfRunning(A)
#define IOleLink_GetBoundSource(A,B) (A)->lpVtbl->GetBoundSource(A,B)
#define IOleLink_UnbindSource(A) (A)->lpVtbl->UnbindSource(A)
#define IOleLink_Update(A,B) (A)->lpVtbl->Update(A,B)
#endif 
HRESULT IOleLink_SetUpdateOptions_Proxy(IOleLink *,DWORD );
void __RPC_STUB IOleLink_SetUpdateOptions_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_GetUpdateOptions_Proxy(IOleLink *,DWORD *);
void __RPC_STUB IOleLink_GetUpdateOptions_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_SetSourceMoniker_Proxy(IOleLink *,IMoniker *,REFCLSID );
void __RPC_STUB IOleLink_SetSourceMoniker_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_GetSourceMoniker_Proxy(IOleLink *,IMoniker **);
void __RPC_STUB IOleLink_GetSourceMoniker_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_SetSourceDisplayName_Proxy(IOleLink *,LPCOLESTR );
void __RPC_STUB IOleLink_SetSourceDisplayName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_GetSourceDisplayName_Proxy(IOleLink *,LPOLESTR *);
void __RPC_STUB IOleLink_GetSourceDisplayName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_BindToSource_Proxy(IOleLink *,DWORD ,IBindCtx *);
void __RPC_STUB IOleLink_BindToSource_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_BindIfRunning_Proxy(IOleLink *);
void __RPC_STUB IOleLink_BindIfRunning_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_GetBoundSource_Proxy(IOleLink *,IUnknown **);
void __RPC_STUB IOleLink_GetBoundSource_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_UnbindSource_Proxy(IOleLink *);
void __RPC_STUB IOleLink_UnbindSource_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleLink_Update_Proxy(IOleLink *,IBindCtx *);
void __RPC_STUB IOleLink_Update_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleItemContainer_INTERFACE_DEFINED__
#define __IOleItemContainer_INTERFACE_DEFINED__
typedef  IOleItemContainer *LPOLEITEMCONTAINER;
typedef 
enum tagBINDSPEED
{	BINDSPEED_INDEFINITE=1,
BINDSPEED_MODERATE=2,
BINDSPEED_IMMEDIATE=3
} BINDSPEED;
typedef  
enum tagOLECONTF
{	OLECONTF_EMBEDDINGS=1,
OLECONTF_LINKS=2,
OLECONTF_OTHERS=4,
OLECONTF_ONLYUSER=8,
OLECONTF_ONLYIFRUNNING=16
} OLECONTF;
EXTERN_C const IID IID_IOleItemContainer;
typedef struct IOleItemContainerVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleItemContainer *,REFIID,void **);
 ULONG (*AddRef)(IOleItemContainer *);
 ULONG (*Release)(IOleItemContainer *);
 HRESULT (*ParseDisplayName)(IOleItemContainer *,IBindCtx *,LPOLESTR,ULONG *,IMoniker **);
 HRESULT (*EnumObjects)(IOleItemContainer *,DWORD,IEnumUnknown **);
 HRESULT (*LockContainer)(IOleItemContainer *,BOOL);
 HRESULT (*GetObject)(IOleItemContainer *,LPOLESTR,DWORD,IBindCtx *,REFIID,void **);
 HRESULT (*GetObjectStorage)(IOleItemContainer *,LPOLESTR,IBindCtx *,REFIID,void **);
 HRESULT (*IsRunning)(IOleItemContainer *,LPOLESTR);
END_INTERFACE
} IOleItemContainerVtbl;
interface IOleItemContainer
{
CONST_VTBL struct IOleItemContainerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleItemContainer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleItemContainer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleItemContainer_Release(A) (A)->lpVtbl->Release(A)
#define IOleItemContainer_ParseDisplayName(A,B,C,D,E) (A)->lpVtbl->ParseDisplayName(A,B,C,D,E)
#define IOleItemContainer_EnumObjects(A,B,C) (A)->lpVtbl->EnumObjects(A,B,C)
#define IOleItemContainer_LockContainer(A,B) (A)->lpVtbl->LockContainer(A,B)
#define IOleItemContainer_GetObject(A,B,C,D,E,F) (A)->lpVtbl->GetObject(A,B,C,D,E,F)
#define IOleItemContainer_GetObjectStorage(A,B,C,D,E) (A)->lpVtbl->GetObjectStorage(A,B,C,D,E)
#define IOleItemContainer_IsRunning(A,B) (A)->lpVtbl->IsRunning(A,B)
#endif 
HRESULT IOleItemContainer_GetObject_Proxy(IOleItemContainer *,LPOLESTR ,DWORD ,IBindCtx *,REFIID ,void **);
void __RPC_STUB IOleItemContainer_GetObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleItemContainer_GetObjectStorage_Proxy(IOleItemContainer *,LPOLESTR ,IBindCtx *,REFIID ,void **);
void __RPC_STUB IOleItemContainer_GetObjectStorage_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleItemContainer_IsRunning_Proxy(IOleItemContainer *,LPOLESTR );
void __RPC_STUB IOleItemContainer_IsRunning_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleInPlaceUIWindow_INTERFACE_DEFINED__
#define __IOleInPlaceUIWindow_INTERFACE_DEFINED__
typedef  IOleInPlaceUIWindow *LPOLEINPLACEUIWINDOW;
typedef RECT BORDERWIDTHS;
typedef LPRECT LPBORDERWIDTHS;
typedef LPCRECT LPCBORDERWIDTHS;
EXTERN_C const IID IID_IOleInPlaceUIWindow;
typedef struct IOleInPlaceUIWindowVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleInPlaceUIWindow *,REFIID,void **);
 ULONG (*AddRef)(IOleInPlaceUIWindow *);
 ULONG (*Release)(IOleInPlaceUIWindow *);
 HRESULT (*GetWindow)(IOleInPlaceUIWindow *,HWND *);
 HRESULT (*ContextSensitiveHelp)(IOleInPlaceUIWindow *,BOOL);
 HRESULT (*GetBorder)(IOleInPlaceUIWindow *,LPRECT);
 HRESULT (*RequestBorderSpace)(IOleInPlaceUIWindow *,LPCBORDERWIDTHS);
 HRESULT (*SetBorderSpace)(IOleInPlaceUIWindow *,LPCBORDERWIDTHS);
 HRESULT (*SetActiveObject)(IOleInPlaceUIWindow *,IOleInPlaceActiveObject *,LPCOLESTR);
END_INTERFACE
} IOleInPlaceUIWindowVtbl;
interface IOleInPlaceUIWindow
{
CONST_VTBL struct IOleInPlaceUIWindowVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleInPlaceUIWindow_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleInPlaceUIWindow_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleInPlaceUIWindow_Release(A) (A)->lpVtbl->Release(A)
#define IOleInPlaceUIWindow_GetWindow(A,B) (A)->lpVtbl->GetWindow(A,B)
#define IOleInPlaceUIWindow_ContextSensitiveHelp(A,B) (A)->lpVtbl->ContextSensitiveHelp(A,B)
#define IOleInPlaceUIWindow_GetBorder(A,B) (A)->lpVtbl->GetBorder(A,B)
#define IOleInPlaceUIWindow_RequestBorderSpace(A,B) (A)->lpVtbl->RequestBorderSpace(A,B)
#define IOleInPlaceUIWindow_SetBorderSpace(A,B) (A)->lpVtbl->SetBorderSpace(A,B)
#define IOleInPlaceUIWindow_SetActiveObject(A,B,C) (A)->lpVtbl->SetActiveObject(A,B,C)
#endif 
HRESULT IOleInPlaceUIWindow_GetBorder_Proxy(IOleInPlaceUIWindow *,LPRECT );
void __RPC_STUB IOleInPlaceUIWindow_GetBorder_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceUIWindow_RequestBorderSpace_Proxy(IOleInPlaceUIWindow *,LPCBORDERWIDTHS );
void __RPC_STUB IOleInPlaceUIWindow_RequestBorderSpace_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceUIWindow_SetBorderSpace_Proxy(IOleInPlaceUIWindow *,LPCBORDERWIDTHS );
void __RPC_STUB IOleInPlaceUIWindow_SetBorderSpace_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceUIWindow_SetActiveObject_Proxy(IOleInPlaceUIWindow *,IOleInPlaceActiveObject *,LPCOLESTR );
void __RPC_STUB IOleInPlaceUIWindow_SetActiveObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleInPlaceActiveObject_INTERFACE_DEFINED__
#define __IOleInPlaceActiveObject_INTERFACE_DEFINED__
typedef  IOleInPlaceActiveObject *LPOLEINPLACEACTIVEOBJECT;
EXTERN_C const IID IID_IOleInPlaceActiveObject;
typedef struct IOleInPlaceActiveObjectVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleInPlaceActiveObject *,REFIID,void **);
 ULONG (*AddRef)(IOleInPlaceActiveObject *);
 ULONG (*Release)(IOleInPlaceActiveObject *);
 HRESULT (*GetWindow)(IOleInPlaceActiveObject *,HWND *);
 HRESULT (*ContextSensitiveHelp)(IOleInPlaceActiveObject *,BOOL);
 HRESULT (*TranslateAccelerator)(IOleInPlaceActiveObject *,LPMSG);
 HRESULT (*OnFrameWindowActivate)(IOleInPlaceActiveObject *,BOOL);
 HRESULT (*OnDocWindowActivate)(IOleInPlaceActiveObject *,BOOL);
 HRESULT (*ResizeBorder)(IOleInPlaceActiveObject *,LPCRECT,IOleInPlaceUIWindow *,BOOL);
 HRESULT (*EnableModeless)(IOleInPlaceActiveObject *,BOOL);
END_INTERFACE
} IOleInPlaceActiveObjectVtbl;
interface IOleInPlaceActiveObject
{
CONST_VTBL struct IOleInPlaceActiveObjectVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleInPlaceActiveObject_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleInPlaceActiveObject_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleInPlaceActiveObject_Release(A) (A)->lpVtbl->Release(A)
#define IOleInPlaceActiveObject_GetWindow(A,B) (A)->lpVtbl->GetWindow(A,B)
#define IOleInPlaceActiveObject_ContextSensitiveHelp(A,B) (A)->lpVtbl->ContextSensitiveHelp(A,B)
#define IOleInPlaceActiveObject_TranslateAccelerator(A,B) (A)->lpVtbl->TranslateAccelerator(A,B)
#define IOleInPlaceActiveObject_OnFrameWindowActivate(A,B) (A)->lpVtbl->OnFrameWindowActivate(A,B)
#define IOleInPlaceActiveObject_OnDocWindowActivate(A,B) (A)->lpVtbl->OnDocWindowActivate(A,B)
#define IOleInPlaceActiveObject_ResizeBorder(A,B,C,D) (A)->lpVtbl->ResizeBorder(A,B,C,D)
#define IOleInPlaceActiveObject_EnableModeless(A,B) (A)->lpVtbl->EnableModeless(A,B)
#endif 
HRESULT IOleInPlaceActiveObject_RemoteTranslateAccelerator_Proxy(IOleInPlaceActiveObject *);
void __RPC_STUB IOleInPlaceActiveObject_RemoteTranslateAccelerator_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceActiveObject_OnFrameWindowActivate_Proxy(IOleInPlaceActiveObject *,BOOL );
void __RPC_STUB IOleInPlaceActiveObject_OnFrameWindowActivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceActiveObject_OnDocWindowActivate_Proxy(IOleInPlaceActiveObject *,BOOL );
void __RPC_STUB IOleInPlaceActiveObject_OnDocWindowActivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceActiveObject_RemoteResizeBorder_Proxy(IOleInPlaceActiveObject *,LPCRECT ,REFIID ,IOleInPlaceUIWindow *,BOOL );
void __RPC_STUB IOleInPlaceActiveObject_RemoteResizeBorder_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceActiveObject_EnableModeless_Proxy(IOleInPlaceActiveObject *,BOOL );
void __RPC_STUB IOleInPlaceActiveObject_EnableModeless_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleInPlaceFrame_INTERFACE_DEFINED__
#define __IOleInPlaceFrame_INTERFACE_DEFINED__
typedef  IOleInPlaceFrame *LPOLEINPLACEFRAME;
typedef struct tagOIFI
{
UINT cb;
BOOL fMDIApp;
HWND hwndFrame;
HACCEL haccel;
UINT cAccelEntries;
} OLEINPLACEFRAMEINFO;
typedef struct tagOIFI *LPOLEINPLACEFRAMEINFO;
typedef struct tagOleMenuGroupWidths
{
LONG width[ 6 ];
} OLEMENUGROUPWIDTHS;
typedef struct tagOleMenuGroupWidths *LPOLEMENUGROUPWIDTHS;
typedef HGLOBAL HOLEMENU;
EXTERN_C const IID IID_IOleInPlaceFrame;
typedef struct IOleInPlaceFrameVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleInPlaceFrame *,REFIID,void **);
 ULONG (*AddRef)(IOleInPlaceFrame *);
 ULONG (*Release)(IOleInPlaceFrame *);
 HRESULT (*GetWindow)(IOleInPlaceFrame *,HWND *);
 HRESULT (*ContextSensitiveHelp)(IOleInPlaceFrame *,BOOL);
 HRESULT (*GetBorder)(IOleInPlaceFrame *,LPRECT);
 HRESULT (*RequestBorderSpace)(IOleInPlaceFrame *,LPCBORDERWIDTHS);
 HRESULT (*SetBorderSpace)(IOleInPlaceFrame *,LPCBORDERWIDTHS);
 HRESULT (*SetActiveObject)(IOleInPlaceFrame *,IOleInPlaceActiveObject *,LPCOLESTR);
 HRESULT (*InsertMenus)(IOleInPlaceFrame *,HMENU,LPOLEMENUGROUPWIDTHS);
 HRESULT (*SetMenu)(IOleInPlaceFrame *,HMENU,HOLEMENU,HWND);
 HRESULT (*RemoveMenus)(IOleInPlaceFrame *,HMENU);
 HRESULT (*SetStatusText)(IOleInPlaceFrame *,LPCOLESTR);
 HRESULT (*EnableModeless)(IOleInPlaceFrame *,BOOL);
 HRESULT (*TranslateAccelerator)(IOleInPlaceFrame *,LPMSG,WORD);
END_INTERFACE
} IOleInPlaceFrameVtbl;
interface IOleInPlaceFrame
{
CONST_VTBL struct IOleInPlaceFrameVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleInPlaceFrame_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleInPlaceFrame_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleInPlaceFrame_Release(A) (A)->lpVtbl->Release(A)
#define IOleInPlaceFrame_GetWindow(A,B) (A)->lpVtbl->GetWindow(A,B)
#define IOleInPlaceFrame_ContextSensitiveHelp(A,B) (A)->lpVtbl->ContextSensitiveHelp(A,B)
#define IOleInPlaceFrame_GetBorder(A,B) (A)->lpVtbl->GetBorder(A,B)
#define IOleInPlaceFrame_RequestBorderSpace(A,B) (A)->lpVtbl->RequestBorderSpace(A,B)
#define IOleInPlaceFrame_SetBorderSpace(A,B) (A)->lpVtbl->SetBorderSpace(A,B)
#define IOleInPlaceFrame_SetActiveObject(A,B,C) (A)->lpVtbl->SetActiveObject(A,B,C)
#define IOleInPlaceFrame_InsertMenus(A,B,C) (A)->lpVtbl->InsertMenus(A,B,C)
#define IOleInPlaceFrame_SetMenu(A,B,C,D) (A)->lpVtbl->SetMenu(A,B,C,D)
#define IOleInPlaceFrame_RemoveMenus(A,B) (A)->lpVtbl->RemoveMenus(A,B)
#define IOleInPlaceFrame_SetStatusText(A,B) (A)->lpVtbl->SetStatusText(A,B)
#define IOleInPlaceFrame_EnableModeless(A,B) (A)->lpVtbl->EnableModeless(A,B)
#define IOleInPlaceFrame_TranslateAccelerator(A,B,C) (A)->lpVtbl->TranslateAccelerator(A,B,C)
#endif 
HRESULT IOleInPlaceFrame_InsertMenus_Proxy(IOleInPlaceFrame *,HMENU ,LPOLEMENUGROUPWIDTHS );
void __RPC_STUB IOleInPlaceFrame_InsertMenus_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceFrame_SetMenu_Proxy(IOleInPlaceFrame *,HMENU ,HOLEMENU ,HWND );
void __RPC_STUB IOleInPlaceFrame_SetMenu_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceFrame_RemoveMenus_Proxy(IOleInPlaceFrame *,HMENU );
void __RPC_STUB IOleInPlaceFrame_RemoveMenus_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceFrame_SetStatusText_Proxy(IOleInPlaceFrame *,LPCOLESTR );
void __RPC_STUB IOleInPlaceFrame_SetStatusText_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceFrame_EnableModeless_Proxy(IOleInPlaceFrame *,BOOL );
void __RPC_STUB IOleInPlaceFrame_EnableModeless_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceFrame_TranslateAccelerator_Proxy(IOleInPlaceFrame *,LPMSG ,WORD );
void __RPC_STUB IOleInPlaceFrame_TranslateAccelerator_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleInPlaceObject_INTERFACE_DEFINED__
#define __IOleInPlaceObject_INTERFACE_DEFINED__
typedef  IOleInPlaceObject *LPOLEINPLACEOBJECT;
EXTERN_C const IID IID_IOleInPlaceObject;
typedef struct IOleInPlaceObjectVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleInPlaceObject *,REFIID,void **);
 ULONG (*AddRef)(IOleInPlaceObject *);
 ULONG (*Release)(IOleInPlaceObject *);
 HRESULT (*GetWindow)(IOleInPlaceObject *,HWND *);
 HRESULT (*ContextSensitiveHelp)(IOleInPlaceObject *,BOOL);
 HRESULT (*InPlaceDeactivate)(IOleInPlaceObject *);
 HRESULT (*UIDeactivate)(IOleInPlaceObject *);
 HRESULT (*SetObjectRects)(IOleInPlaceObject *,LPCRECT,LPCRECT);
 HRESULT (*ReactivateAndUndo)(IOleInPlaceObject *);
END_INTERFACE
} IOleInPlaceObjectVtbl;
interface IOleInPlaceObject
{
CONST_VTBL struct IOleInPlaceObjectVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleInPlaceObject_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleInPlaceObject_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleInPlaceObject_Release(A) (A)->lpVtbl->Release(A)
#define IOleInPlaceObject_GetWindow(A,B) (A)->lpVtbl->GetWindow(A,B)
#define IOleInPlaceObject_ContextSensitiveHelp(A,B) (A)->lpVtbl->ContextSensitiveHelp(A,B)
#define IOleInPlaceObject_InPlaceDeactivate(A) (A)->lpVtbl->InPlaceDeactivate(A)
#define IOleInPlaceObject_UIDeactivate(A) (A)->lpVtbl->UIDeactivate(A)
#define IOleInPlaceObject_SetObjectRects(A,B,C) (A)->lpVtbl->SetObjectRects(A,B,C)
#define IOleInPlaceObject_ReactivateAndUndo(A) (A)->lpVtbl->ReactivateAndUndo(A)
#endif 
HRESULT IOleInPlaceObject_InPlaceDeactivate_Proxy(IOleInPlaceObject *);
void __RPC_STUB IOleInPlaceObject_InPlaceDeactivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceObject_UIDeactivate_Proxy(IOleInPlaceObject *);
void __RPC_STUB IOleInPlaceObject_UIDeactivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceObject_SetObjectRects_Proxy(IOleInPlaceObject *,LPCRECT ,LPCRECT );
void __RPC_STUB IOleInPlaceObject_SetObjectRects_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceObject_ReactivateAndUndo_Proxy(IOleInPlaceObject *);
void __RPC_STUB IOleInPlaceObject_ReactivateAndUndo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IOleInPlaceSite_INTERFACE_DEFINED__
#define __IOleInPlaceSite_INTERFACE_DEFINED__
typedef  IOleInPlaceSite *LPOLEINPLACESITE;
EXTERN_C const IID IID_IOleInPlaceSite;
typedef struct IOleInPlaceSiteVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IOleInPlaceSite *,REFIID,void **);
 ULONG (*AddRef)(IOleInPlaceSite *);
 ULONG (*Release)(IOleInPlaceSite *);
 HRESULT (*GetWindow)(IOleInPlaceSite *,HWND *);
 HRESULT (*ContextSensitiveHelp)(IOleInPlaceSite *,BOOL);
 HRESULT (*CanInPlaceActivate)(IOleInPlaceSite *);
 HRESULT (*OnInPlaceActivate)(IOleInPlaceSite *);
 HRESULT (*OnUIActivate)(IOleInPlaceSite *);
 HRESULT (*GetWindowContext)(IOleInPlaceSite *,IOleInPlaceFrame **,IOleInPlaceUIWindow **,LPRECT,LPRECT,LPOLEINPLACEFRAMEINFO);
 HRESULT (*Scroll)(IOleInPlaceSite *,SIZE);
 HRESULT (*OnUIDeactivate)(IOleInPlaceSite *,BOOL);
 HRESULT (*OnInPlaceDeactivate)(IOleInPlaceSite *);
 HRESULT (*DiscardUndoState)(IOleInPlaceSite *);
 HRESULT (*DeactivateAndUndo)(IOleInPlaceSite *);
 HRESULT (*OnPosRectChange)(IOleInPlaceSite *,LPCRECT);
END_INTERFACE
} IOleInPlaceSiteVtbl;
interface IOleInPlaceSite
{
CONST_VTBL struct IOleInPlaceSiteVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOleInPlaceSite_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOleInPlaceSite_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOleInPlaceSite_Release(A) (A)->lpVtbl->Release(A)
#define IOleInPlaceSite_GetWindow(A,B) (A)->lpVtbl->GetWindow(A,B)
#define IOleInPlaceSite_ContextSensitiveHelp(A,B) (A)->lpVtbl->ContextSensitiveHelp(A,B)
#define IOleInPlaceSite_CanInPlaceActivate(A) (A)->lpVtbl->CanInPlaceActivate(A)
#define IOleInPlaceSite_OnInPlaceActivate(A) (A)->lpVtbl->OnInPlaceActivate(A)
#define IOleInPlaceSite_OnUIActivate(A) (A)->lpVtbl->OnUIActivate(A)
#define IOleInPlaceSite_GetWindowContext(A,B,C,D,E,F) (A)->lpVtbl->GetWindowContext(A,B,C,D,E,F)
#define IOleInPlaceSite_Scroll(A,B) (A)->lpVtbl->Scroll(A,B)
#define IOleInPlaceSite_OnUIDeactivate(A,B) (A)->lpVtbl->OnUIDeactivate(A,B)
#define IOleInPlaceSite_OnInPlaceDeactivate(A) (A)->lpVtbl->OnInPlaceDeactivate(A)
#define IOleInPlaceSite_DiscardUndoState(A) (A)->lpVtbl->DiscardUndoState(A)
#define IOleInPlaceSite_DeactivateAndUndo(A) (A)->lpVtbl->DeactivateAndUndo(A)
#define IOleInPlaceSite_OnPosRectChange(A,B) (A)->lpVtbl->OnPosRectChange(A,B)
#endif 
HRESULT IOleInPlaceSite_CanInPlaceActivate_Proxy(IOleInPlaceSite *);
void __RPC_STUB IOleInPlaceSite_CanInPlaceActivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_OnInPlaceActivate_Proxy(IOleInPlaceSite *);
void __RPC_STUB IOleInPlaceSite_OnInPlaceActivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_OnUIActivate_Proxy(IOleInPlaceSite *);
void __RPC_STUB IOleInPlaceSite_OnUIActivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_GetWindowContext_Proxy(IOleInPlaceSite *,IOleInPlaceFrame **,IOleInPlaceUIWindow **,LPRECT ,LPRECT ,LPOLEINPLACEFRAMEINFO );
void __RPC_STUB IOleInPlaceSite_GetWindowContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_Scroll_Proxy(IOleInPlaceSite *,SIZE );
void __RPC_STUB IOleInPlaceSite_Scroll_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_OnUIDeactivate_Proxy(IOleInPlaceSite *,BOOL );
void __RPC_STUB IOleInPlaceSite_OnUIDeactivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_OnInPlaceDeactivate_Proxy(IOleInPlaceSite *);
void __RPC_STUB IOleInPlaceSite_OnInPlaceDeactivate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_DiscardUndoState_Proxy(IOleInPlaceSite *);
void __RPC_STUB IOleInPlaceSite_DiscardUndoState_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_DeactivateAndUndo_Proxy(IOleInPlaceSite *);
void __RPC_STUB IOleInPlaceSite_DeactivateAndUndo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IOleInPlaceSite_OnPosRectChange_Proxy(IOleInPlaceSite *,LPCRECT );
void __RPC_STUB IOleInPlaceSite_OnPosRectChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IContinue_INTERFACE_DEFINED__
#define __IContinue_INTERFACE_DEFINED__
EXTERN_C const IID IID_IContinue;
typedef struct IContinueVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IContinue *,REFIID,void **);
 ULONG (*AddRef)(IContinue *);
 ULONG (*Release)(IContinue *);
 HRESULT (*FContinue)(IContinue *);
END_INTERFACE
} IContinueVtbl;
interface IContinue
{
CONST_VTBL struct IContinueVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IContinue_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IContinue_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IContinue_Release(A) (A)->lpVtbl->Release(A)
#define IContinue_FContinue(A) (A)->lpVtbl->FContinue(A)
#endif 
HRESULT IContinue_FContinue_Proxy(IContinue *);
void __RPC_STUB IContinue_FContinue_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IViewObject_INTERFACE_DEFINED__
#define __IViewObject_INTERFACE_DEFINED__
typedef  IViewObject *LPVIEWOBJECT;
EXTERN_C const IID IID_IViewObject;
typedef struct IViewObjectVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IViewObject *,REFIID,void **);
 ULONG (*AddRef)(IViewObject *);
 ULONG (*Release)(IViewObject *);
 HRESULT (*Draw)(IViewObject *,DWORD,LONG,void *,DVTARGETDEVICE *,HDC,HDC,LPCRECTL,LPCRECTL,BOOL (_stdcall *pfnContinue)(ULONG_PTR),ULONG_PTR);
 HRESULT (*GetColorSet)(IViewObject *,DWORD,LONG,void *,DVTARGETDEVICE *,HDC,LOGPALETTE **);
 HRESULT (*Freeze)(IViewObject *,DWORD,LONG,void *,DWORD *);
 HRESULT (*Unfreeze)(IViewObject *,DWORD);
 HRESULT (*SetAdvise)(IViewObject *,DWORD,DWORD,IAdviseSink *);
 HRESULT (*GetAdvise)(IViewObject *,DWORD *,DWORD *,IAdviseSink **);
END_INTERFACE
} IViewObjectVtbl;
interface IViewObject
{
CONST_VTBL struct IViewObjectVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IViewObject_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IViewObject_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IViewObject_Release(A) (A)->lpVtbl->Release(A)
#define IViewObject_Draw(A,B,C,D,E,F,G,H,I,J,K) (A)->lpVtbl->Draw(A,B,C,D,E,F,G,H,I,J,K)
#define IViewObject_GetColorSet(A,B,C,D,E,F,G) (A)->lpVtbl->GetColorSet(A,B,C,D,E,F,G)
#define IViewObject_Freeze(A,B,C,D,E) (A)->lpVtbl->Freeze(A,B,C,D,E)
#define IViewObject_Unfreeze(A,B) (A)->lpVtbl->Unfreeze(A,B)
#define IViewObject_SetAdvise(A,B,C,D) (A)->lpVtbl->SetAdvise(A,B,C,D)
#define IViewObject_GetAdvise(A,B,C,D) (A)->lpVtbl->GetAdvise(A,B,C,D)
#endif 
HRESULT IViewObject_RemoteDraw_Proxy(IViewObject *,DWORD ,LONG ,ULONG_PTR ,DVTARGETDEVICE *,ULONG_PTR ,ULONG_PTR ,LPCRECTL ,LPCRECTL ,IContinue *);
void __RPC_STUB IViewObject_RemoteDraw_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IViewObject_RemoteGetColorSet_Proxy(IViewObject *,DWORD ,LONG ,ULONG_PTR ,DVTARGETDEVICE *,ULONG_PTR ,LOGPALETTE **);
void __RPC_STUB IViewObject_RemoteGetColorSet_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IViewObject_RemoteFreeze_Proxy(IViewObject *,DWORD ,LONG ,ULONG_PTR ,DWORD *);
void __RPC_STUB IViewObject_RemoteFreeze_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IViewObject_Unfreeze_Proxy(IViewObject *,DWORD );
void __RPC_STUB IViewObject_Unfreeze_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IViewObject_SetAdvise_Proxy(IViewObject *,DWORD ,DWORD ,IAdviseSink *);
void __RPC_STUB IViewObject_SetAdvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IViewObject_RemoteGetAdvise_Proxy(IViewObject *,DWORD *,DWORD *,IAdviseSink **);
void __RPC_STUB IViewObject_RemoteGetAdvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IViewObject2_INTERFACE_DEFINED__
#define __IViewObject2_INTERFACE_DEFINED__
typedef  IViewObject2 *LPVIEWOBJECT2;
EXTERN_C const IID IID_IViewObject2;
typedef struct IViewObject2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IViewObject2 *,REFIID,void **);
 ULONG (*AddRef)(IViewObject2 *);
 ULONG (*Release)(IViewObject2 *);
 HRESULT (*Draw)(IViewObject2 *,DWORD,LONG,void *,DVTARGETDEVICE *,HDC,HDC,LPCRECTL,LPCRECTL,BOOL (_stdcall *pfnContinue)(ULONG_PTR),ULONG_PTR);
 HRESULT (*GetColorSet)(IViewObject2 *,DWORD,LONG,void *,DVTARGETDEVICE *,HDC,LOGPALETTE **);
 HRESULT (*Freeze)(IViewObject2 *,DWORD,LONG,void *,DWORD *);
 HRESULT (*Unfreeze)(IViewObject2 *,DWORD);
 HRESULT (*SetAdvise)(IViewObject2 *,DWORD,DWORD,IAdviseSink *);
 HRESULT (*GetAdvise)(IViewObject2 *,DWORD *,DWORD *,IAdviseSink **);
 HRESULT (*GetExtent)(IViewObject2 *,DWORD,LONG,DVTARGETDEVICE *,LPSIZEL);
END_INTERFACE
} IViewObject2Vtbl;
interface IViewObject2
{
CONST_VTBL struct IViewObject2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IViewObject2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IViewObject2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IViewObject2_Release(A) (A)->lpVtbl->Release(A)
#define IViewObject2_Draw(A,B,C,D,E,F,G,H,I,J,K) (A)->lpVtbl->Draw(A,B,C,D,E,F,G,H,I,J,K)
#define IViewObject2_GetColorSet(A,B,C,D,E,F,G) (A)->lpVtbl->GetColorSet(A,B,C,D,E,F,G)
#define IViewObject2_Freeze(A,B,C,D,E) (A)->lpVtbl->Freeze(A,B,C,D,E)
#define IViewObject2_Unfreeze(A,B) (A)->lpVtbl->Unfreeze(A,B)
#define IViewObject2_SetAdvise(A,B,C,D) (A)->lpVtbl->SetAdvise(A,B,C,D)
#define IViewObject2_GetAdvise(A,B,C,D) (A)->lpVtbl->GetAdvise(A,B,C,D)
#define IViewObject2_GetExtent(A,B,C,D,E) (A)->lpVtbl->GetExtent(A,B,C,D,E)
#endif 
HRESULT IViewObject2_GetExtent_Proxy(IViewObject2 *,DWORD ,LONG ,DVTARGETDEVICE *,LPSIZEL );
void __RPC_STUB IViewObject2_GetExtent_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IDropSource_INTERFACE_DEFINED__
#define __IDropSource_INTERFACE_DEFINED__
typedef  IDropSource *LPDROPSOURCE;
EXTERN_C const IID IID_IDropSource;
typedef struct IDropSourceVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IDropSource *,REFIID,void **);
 ULONG (*AddRef)(IDropSource *);
 ULONG (*Release)(IDropSource *);
 HRESULT (*QueryContinueDrag)(IDropSource *,BOOL,DWORD);
 HRESULT (*GiveFeedback)(IDropSource *,DWORD);
END_INTERFACE
} IDropSourceVtbl;
interface IDropSource
{
CONST_VTBL struct IDropSourceVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IDropSource_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IDropSource_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IDropSource_Release(A) (A)->lpVtbl->Release(A)
#define IDropSource_QueryContinueDrag(A,B,C) (A)->lpVtbl->QueryContinueDrag(A,B,C)
#define IDropSource_GiveFeedback(A,B) (A)->lpVtbl->GiveFeedback(A,B)
#endif 
HRESULT IDropSource_QueryContinueDrag_Proxy(IDropSource *,BOOL ,DWORD );
void __RPC_STUB IDropSource_QueryContinueDrag_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDropSource_GiveFeedback_Proxy(IDropSource *,DWORD );
void __RPC_STUB IDropSource_GiveFeedback_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IDropTarget_INTERFACE_DEFINED__
#define __IDropTarget_INTERFACE_DEFINED__
typedef  IDropTarget *LPDROPTARGET;
#define	MK_ALT	32
#define	DROPEFFECT_NONE	(0)
#define	DROPEFFECT_COPY	(1)
#define	DROPEFFECT_MOVE	(2)
#define	DROPEFFECT_LINK	(4)
#define	DROPEFFECT_SCROLL	0x80000000
#define	DD_DEFSCROLLINSET	(11)
#define	DD_DEFSCROLLDELAY	(50)
#define	DD_DEFSCROLLINTERVAL	(50)
#define	DD_DEFDRAGDELAY	(200)
#define	DD_DEFDRAGMINDIST	(2)
EXTERN_C const IID IID_IDropTarget;
typedef struct IDropTargetVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IDropTarget *,REFIID,void **);
 ULONG (*AddRef)(IDropTarget *);
 ULONG (*Release)(IDropTarget *);
 HRESULT (*DragEnter)(IDropTarget *,IDataObject *,DWORD,POINTL,DWORD *);
 HRESULT (*DragOver)(IDropTarget *,DWORD,POINTL,DWORD *);
 HRESULT (*DragLeave)(IDropTarget *);
 HRESULT (*Drop)(IDropTarget *,IDataObject *,DWORD,POINTL,DWORD *);
END_INTERFACE
} IDropTargetVtbl;
interface IDropTarget
{
CONST_VTBL struct IDropTargetVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IDropTarget_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IDropTarget_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IDropTarget_Release(A) (A)->lpVtbl->Release(A)
#define IDropTarget_DragEnter(A,B,C,D,E) (A)->lpVtbl->DragEnter(A,B,C,D,E)
#define IDropTarget_DragOver(A,B,C,D) (A)->lpVtbl->DragOver(A,B,C,D)
#define IDropTarget_DragLeave(A) (A)->lpVtbl->DragLeave(A)
#define IDropTarget_Drop(A,B,C,D,E) (A)->lpVtbl->Drop(A,B,C,D,E)
#endif 
HRESULT IDropTarget_DragEnter_Proxy(IDropTarget *,IDataObject *,DWORD ,POINTL ,DWORD *);
void __RPC_STUB IDropTarget_DragEnter_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDropTarget_DragOver_Proxy(IDropTarget *,DWORD ,POINTL ,DWORD *);
void __RPC_STUB IDropTarget_DragOver_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDropTarget_DragLeave_Proxy(IDropTarget *);
void __RPC_STUB IDropTarget_DragLeave_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDropTarget_Drop_Proxy(IDropTarget *,IDataObject *,DWORD ,POINTL ,DWORD *);
void __RPC_STUB IDropTarget_Drop_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IEnumOLEVERB_INTERFACE_DEFINED__
#define __IEnumOLEVERB_INTERFACE_DEFINED__
typedef  IEnumOLEVERB *LPENUMOLEVERB;
typedef struct tagOLEVERB
{
LONG lVerb;
LPOLESTR lpszVerbName;
DWORD fuFlags;
DWORD grfAttribs;
} OLEVERB;
typedef struct tagOLEVERB *LPOLEVERB;
typedef  
enum tagOLEVERBATTRIB
{	OLEVERBATTRIB_NEVERDIRTIES=1,
OLEVERBATTRIB_ONCONTAINERMENU=2
} OLEVERBATTRIB;
EXTERN_C const IID IID_IEnumOLEVERB;
typedef struct IEnumOLEVERBVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IEnumOLEVERB *,REFIID,void **);
 ULONG (*AddRef)(IEnumOLEVERB *);
 ULONG (*Release)(IEnumOLEVERB *);
 HRESULT (*Next)(IEnumOLEVERB *,ULONG,LPOLEVERB,ULONG *);
 HRESULT (*Skip)(IEnumOLEVERB *,ULONG);
 HRESULT (*Reset)(IEnumOLEVERB *);
 HRESULT (*Clone)(IEnumOLEVERB *,IEnumOLEVERB **);
END_INTERFACE
} IEnumOLEVERBVtbl;
interface IEnumOLEVERB
{
CONST_VTBL struct IEnumOLEVERBVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumOLEVERB_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumOLEVERB_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumOLEVERB_Release(A) (A)->lpVtbl->Release(A)
#define IEnumOLEVERB_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumOLEVERB_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumOLEVERB_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumOLEVERB_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IEnumOLEVERB_RemoteNext_Proxy(IEnumOLEVERB *,ULONG ,LPOLEVERB ,ULONG *);
void __RPC_STUB IEnumOLEVERB_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IEnumOLEVERB_Skip_Proxy(IEnumOLEVERB *,ULONG );
void __RPC_STUB IEnumOLEVERB_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IEnumOLEVERB_Reset_Proxy(IEnumOLEVERB *);
void __RPC_STUB IEnumOLEVERB_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IEnumOLEVERB_Clone_Proxy(IEnumOLEVERB *,IEnumOLEVERB **);
void __RPC_STUB IEnumOLEVERB_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
unsigned long __RPC_USER CLIPFORMAT_UserSize(unsigned long *,unsigned ,CLIPFORMAT *); 
unsigned char * __RPC_USER CLIPFORMAT_UserMarshal(unsigned long *,unsigned char *,CLIPFORMAT *); 
unsigned char * __RPC_USER CLIPFORMAT_UserUnmarshal(unsigned long *,unsigned char *,CLIPFORMAT *); 
void __RPC_USER CLIPFORMAT_UserFree(unsigned long *,CLIPFORMAT *); 
unsigned long __RPC_USER HACCEL_UserSize(unsigned long *,unsigned ,HACCEL *); 
unsigned char * __RPC_USER HACCEL_UserMarshal(unsigned long *,unsigned char *,HACCEL *); 
unsigned char * __RPC_USER HACCEL_UserUnmarshal(unsigned long *,unsigned char *,HACCEL *); 
void __RPC_USER HACCEL_UserFree(unsigned long *,HACCEL *); 
unsigned long __RPC_USER HGLOBAL_UserSize(unsigned long *,unsigned ,HGLOBAL *); 
unsigned char * __RPC_USER HGLOBAL_UserMarshal(unsigned long *,unsigned char *,HGLOBAL *); 
unsigned char * __RPC_USER HGLOBAL_UserUnmarshal(unsigned long *,unsigned char *,HGLOBAL *); 
void __RPC_USER HGLOBAL_UserFree(unsigned long *,HGLOBAL *); 
unsigned long __RPC_USER HMENU_UserSize(unsigned long *,unsigned ,HMENU *); 
unsigned char * __RPC_USER HMENU_UserMarshal(unsigned long *,unsigned char *,HMENU *); 
unsigned char * __RPC_USER HMENU_UserUnmarshal(unsigned long *,unsigned char *,HMENU *); 
void __RPC_USER HMENU_UserFree(unsigned long *,HMENU *); 
unsigned long __RPC_USER HWND_UserSize(unsigned long *,unsigned ,HWND *); 
unsigned char * __RPC_USER HWND_UserMarshal(unsigned long *,unsigned char *,HWND *); 
unsigned char * __RPC_USER HWND_UserUnmarshal(unsigned long *,unsigned char *,HWND *); 
void __RPC_USER HWND_UserFree(unsigned long *,HWND *); 
unsigned long __RPC_USER STGMEDIUM_UserSize(unsigned long *,unsigned ,STGMEDIUM *); 
unsigned char * __RPC_USER STGMEDIUM_UserMarshal(unsigned long *,unsigned char *,STGMEDIUM *); 
unsigned char * __RPC_USER STGMEDIUM_UserUnmarshal(unsigned long *,unsigned char *,STGMEDIUM *); 
void __RPC_USER STGMEDIUM_UserFree(unsigned long *,STGMEDIUM *); 
HRESULT IOleCache2_UpdateCache_Proxy(IOleCache2 *,LPDATAOBJECT ,DWORD ,LPVOID );
HRESULT IOleCache2_UpdateCache_Stub(IOleCache2 *,LPDATAOBJECT ,DWORD ,LONG_PTR );
HRESULT IOleInPlaceActiveObject_TranslateAccelerator_Proxy(IOleInPlaceActiveObject *,LPMSG );
HRESULT IOleInPlaceActiveObject_TranslateAccelerator_Stub(IOleInPlaceActiveObject *);
HRESULT IOleInPlaceActiveObject_ResizeBorder_Proxy(IOleInPlaceActiveObject *,LPCRECT ,IOleInPlaceUIWindow *,BOOL );
HRESULT IOleInPlaceActiveObject_ResizeBorder_Stub(IOleInPlaceActiveObject *,LPCRECT ,REFIID ,IOleInPlaceUIWindow *,BOOL );
HRESULT IViewObject_Draw_Proxy(IViewObject *,DWORD ,LONG ,void *,DVTARGETDEVICE *,HDC ,HDC ,LPCRECTL ,LPCRECTL ,BOOL (*pfnContinue)(ULONG_PTR ),ULONG_PTR );
HRESULT IViewObject_Draw_Stub(IViewObject *,DWORD ,LONG ,ULONG_PTR ,DVTARGETDEVICE *,ULONG_PTR ,ULONG_PTR ,LPCRECTL ,LPCRECTL ,IContinue *);
HRESULT IViewObject_GetColorSet_Proxy(IViewObject *,DWORD ,LONG ,void *,DVTARGETDEVICE *,HDC ,LOGPALETTE **);
HRESULT IViewObject_GetColorSet_Stub(IViewObject *,DWORD ,LONG ,ULONG_PTR ,DVTARGETDEVICE *,ULONG_PTR ,LOGPALETTE **);
HRESULT IViewObject_Freeze_Proxy(IViewObject *,DWORD ,LONG ,void *,DWORD *);
HRESULT IViewObject_Freeze_Stub(IViewObject *,DWORD ,LONG ,ULONG_PTR ,DWORD *);
HRESULT IViewObject_GetAdvise_Proxy(IViewObject *,DWORD *,DWORD *,IAdviseSink **);
HRESULT IViewObject_GetAdvise_Stub(IViewObject *,DWORD *,DWORD *,IAdviseSink **);
HRESULT IEnumOLEVERB_Next_Proxy(IEnumOLEVERB *,ULONG ,LPOLEVERB ,ULONG *);
HRESULT IEnumOLEVERB_Next_Stub(IEnumOLEVERB *,ULONG ,LPOLEVERB ,ULONG *);
#endif
