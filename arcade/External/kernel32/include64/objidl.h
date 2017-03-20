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
#ifndef __objidl_h__
#define __objidl_h__
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#endif
#ifndef __IMarshal_FWD_DEFINED__
#define __IMarshal_FWD_DEFINED__
typedef interface IMarshal IMarshal;
#endif 
#ifndef __IMarshal2_FWD_DEFINED__
#define __IMarshal2_FWD_DEFINED__
typedef interface IMarshal2 IMarshal2;
#endif 
#ifndef __IMalloc_FWD_DEFINED__
#define __IMalloc_FWD_DEFINED__
typedef interface IMalloc IMalloc;
#endif 
#ifndef __IMallocSpy_FWD_DEFINED__
#define __IMallocSpy_FWD_DEFINED__
typedef interface IMallocSpy IMallocSpy;
#endif 
#ifndef __IStdMarshalInfo_FWD_DEFINED__
#define __IStdMarshalInfo_FWD_DEFINED__
typedef interface IStdMarshalInfo IStdMarshalInfo;
#endif 
#ifndef __IExternalConnection_FWD_DEFINED__
#define __IExternalConnection_FWD_DEFINED__
typedef interface IExternalConnection IExternalConnection;
#endif 
#ifndef __IMultiQI_FWD_DEFINED__
#define __IMultiQI_FWD_DEFINED__
typedef interface IMultiQI IMultiQI;
#endif 
#ifndef __AsyncIMultiQI_FWD_DEFINED__
#define __AsyncIMultiQI_FWD_DEFINED__
typedef interface AsyncIMultiQI AsyncIMultiQI;
#endif 
#ifndef __IInternalUnknown_FWD_DEFINED__
#define __IInternalUnknown_FWD_DEFINED__
typedef interface IInternalUnknown IInternalUnknown;
#endif 
#ifndef __IEnumUnknown_FWD_DEFINED__
#define __IEnumUnknown_FWD_DEFINED__
typedef interface IEnumUnknown IEnumUnknown;
#endif 
#ifndef __IBindCtx_FWD_DEFINED__
#define __IBindCtx_FWD_DEFINED__
typedef interface IBindCtx IBindCtx;
#endif 
#ifndef __IEnumMoniker_FWD_DEFINED__
#define __IEnumMoniker_FWD_DEFINED__
typedef interface IEnumMoniker IEnumMoniker;
#endif 
#ifndef __IRunnableObject_FWD_DEFINED__
#define __IRunnableObject_FWD_DEFINED__
typedef interface IRunnableObject IRunnableObject;
#endif 
#ifndef __IRunningObjectTable_FWD_DEFINED__
#define __IRunningObjectTable_FWD_DEFINED__
typedef interface IRunningObjectTable IRunningObjectTable;
#endif 
#ifndef __IPersist_FWD_DEFINED__
#define __IPersist_FWD_DEFINED__
typedef interface IPersist IPersist;
#endif 
#ifndef __IPersistStream_FWD_DEFINED__
#define __IPersistStream_FWD_DEFINED__
typedef interface IPersistStream IPersistStream;
#endif 
#ifndef __IMoniker_FWD_DEFINED__
#define __IMoniker_FWD_DEFINED__
typedef interface IMoniker IMoniker;
#endif 
#ifndef __IROTData_FWD_DEFINED__
#define __IROTData_FWD_DEFINED__
typedef interface IROTData IROTData;
#endif 
#ifndef __IEnumString_FWD_DEFINED__
#define __IEnumString_FWD_DEFINED__
typedef interface IEnumString IEnumString;
#endif 
#ifndef __ISequentialStream_FWD_DEFINED__
#define __ISequentialStream_FWD_DEFINED__
typedef interface ISequentialStream ISequentialStream;
#endif 
#ifndef __IStream_FWD_DEFINED__
#define __IStream_FWD_DEFINED__
typedef interface IStream IStream;
#endif 
#ifndef __IEnumSTATSTG_FWD_DEFINED__
#define __IEnumSTATSTG_FWD_DEFINED__
typedef interface IEnumSTATSTG IEnumSTATSTG;
#endif 
#ifndef __IStorage_FWD_DEFINED__
#define __IStorage_FWD_DEFINED__
typedef interface IStorage IStorage;
#endif 
#ifndef __IPersistFile_FWD_DEFINED__
#define __IPersistFile_FWD_DEFINED__
typedef interface IPersistFile IPersistFile;
#endif 
#ifndef __IPersistStorage_FWD_DEFINED__
#define __IPersistStorage_FWD_DEFINED__
typedef interface IPersistStorage IPersistStorage;
#endif 
#ifndef __ILockBytes_FWD_DEFINED__
#define __ILockBytes_FWD_DEFINED__
typedef interface ILockBytes ILockBytes;
#endif 
#ifndef __IEnumFORMATETC_FWD_DEFINED__
#define __IEnumFORMATETC_FWD_DEFINED__
typedef interface IEnumFORMATETC IEnumFORMATETC;
#endif 
#ifndef __IEnumSTATDATA_FWD_DEFINED__
#define __IEnumSTATDATA_FWD_DEFINED__
typedef interface IEnumSTATDATA IEnumSTATDATA;
#endif 
#ifndef __IRootStorage_FWD_DEFINED__
#define __IRootStorage_FWD_DEFINED__
typedef interface IRootStorage IRootStorage;
#endif 
#ifndef __IAdviseSink_FWD_DEFINED__
#define __IAdviseSink_FWD_DEFINED__
typedef interface IAdviseSink IAdviseSink;
#endif 
#ifndef __AsyncIAdviseSink_FWD_DEFINED__
#define __AsyncIAdviseSink_FWD_DEFINED__
typedef interface AsyncIAdviseSink AsyncIAdviseSink;
#endif 
#ifndef __IAdviseSink2_FWD_DEFINED__
#define __IAdviseSink2_FWD_DEFINED__
typedef interface IAdviseSink2 IAdviseSink2;
#endif 
#ifndef __AsyncIAdviseSink2_FWD_DEFINED__
#define __AsyncIAdviseSink2_FWD_DEFINED__
typedef interface AsyncIAdviseSink2 AsyncIAdviseSink2;
#endif 
#ifndef __IDataObject_FWD_DEFINED__
#define __IDataObject_FWD_DEFINED__
typedef interface IDataObject IDataObject;
#endif 
#ifndef __IDataAdviseHolder_FWD_DEFINED__
#define __IDataAdviseHolder_FWD_DEFINED__
typedef interface IDataAdviseHolder IDataAdviseHolder;
#endif 
#ifndef __IMessageFilter_FWD_DEFINED__
#define __IMessageFilter_FWD_DEFINED__
typedef interface IMessageFilter IMessageFilter;
#endif 
#ifndef __IRpcChannelBuffer_FWD_DEFINED__
#define __IRpcChannelBuffer_FWD_DEFINED__
typedef interface IRpcChannelBuffer IRpcChannelBuffer;
#endif 
#ifndef __IRpcChannelBuffer2_FWD_DEFINED__
#define __IRpcChannelBuffer2_FWD_DEFINED__
typedef interface IRpcChannelBuffer2 IRpcChannelBuffer2;
#endif 
#ifndef __IAsyncRpcChannelBuffer_FWD_DEFINED__
#define __IAsyncRpcChannelBuffer_FWD_DEFINED__
typedef interface IAsyncRpcChannelBuffer IAsyncRpcChannelBuffer;
#endif 
#ifndef __IRpcChannelBuffer3_FWD_DEFINED__
#define __IRpcChannelBuffer3_FWD_DEFINED__
typedef interface IRpcChannelBuffer3 IRpcChannelBuffer3;
#endif 
#ifndef __IRpcSyntaxNegotiate_FWD_DEFINED__
#define __IRpcSyntaxNegotiate_FWD_DEFINED__
typedef interface IRpcSyntaxNegotiate IRpcSyntaxNegotiate;
#endif 
#ifndef __IRpcProxyBuffer_FWD_DEFINED__
#define __IRpcProxyBuffer_FWD_DEFINED__
typedef interface IRpcProxyBuffer IRpcProxyBuffer;
#endif 
#ifndef __IRpcStubBuffer_FWD_DEFINED__
#define __IRpcStubBuffer_FWD_DEFINED__
typedef interface IRpcStubBuffer IRpcStubBuffer;
#endif 
#ifndef __IPSFactoryBuffer_FWD_DEFINED__
#define __IPSFactoryBuffer_FWD_DEFINED__
typedef interface IPSFactoryBuffer IPSFactoryBuffer;
#endif 
#ifndef __IChannelHook_FWD_DEFINED__
#define __IChannelHook_FWD_DEFINED__
typedef interface IChannelHook IChannelHook;
#endif 
#ifndef __IClientSecurity_FWD_DEFINED__
#define __IClientSecurity_FWD_DEFINED__
typedef interface IClientSecurity IClientSecurity;
#endif 
#ifndef __IServerSecurity_FWD_DEFINED__
#define __IServerSecurity_FWD_DEFINED__
typedef interface IServerSecurity IServerSecurity;
#endif 
#ifndef __IClassActivator_FWD_DEFINED__
#define __IClassActivator_FWD_DEFINED__
typedef interface IClassActivator IClassActivator;
#endif 
#ifndef __IRpcOptions_FWD_DEFINED__
#define __IRpcOptions_FWD_DEFINED__
typedef interface IRpcOptions IRpcOptions;
#endif 
#ifndef __IFillLockBytes_FWD_DEFINED__
#define __IFillLockBytes_FWD_DEFINED__
typedef interface IFillLockBytes IFillLockBytes;
#endif 
#ifndef __IProgressNotify_FWD_DEFINED__
#define __IProgressNotify_FWD_DEFINED__
typedef interface IProgressNotify IProgressNotify;
#endif 
#ifndef __ILayoutStorage_FWD_DEFINED__
#define __ILayoutStorage_FWD_DEFINED__
typedef interface ILayoutStorage ILayoutStorage;
#endif 
#ifndef __IBlockingLock_FWD_DEFINED__
#define __IBlockingLock_FWD_DEFINED__
typedef interface IBlockingLock IBlockingLock;
#endif 
#ifndef __ITimeAndNoticeControl_FWD_DEFINED__
#define __ITimeAndNoticeControl_FWD_DEFINED__
typedef interface ITimeAndNoticeControl ITimeAndNoticeControl;
#endif 
#ifndef __IOplockStorage_FWD_DEFINED__
#define __IOplockStorage_FWD_DEFINED__
typedef interface IOplockStorage IOplockStorage;
#endif 
#ifndef __ISurrogate_FWD_DEFINED__
#define __ISurrogate_FWD_DEFINED__
typedef interface ISurrogate ISurrogate;
#endif 
#ifndef __IGlobalInterfaceTable_FWD_DEFINED__
#define __IGlobalInterfaceTable_FWD_DEFINED__
typedef interface IGlobalInterfaceTable IGlobalInterfaceTable;
#endif 
#ifndef __IDirectWriterLock_FWD_DEFINED__
#define __IDirectWriterLock_FWD_DEFINED__
typedef interface IDirectWriterLock IDirectWriterLock;
#endif 
#ifndef __ISynchronize_FWD_DEFINED__
#define __ISynchronize_FWD_DEFINED__
typedef interface ISynchronize ISynchronize;
#endif 
#ifndef __ISynchronizeHandle_FWD_DEFINED__
#define __ISynchronizeHandle_FWD_DEFINED__
typedef interface ISynchronizeHandle ISynchronizeHandle;
#endif 
#ifndef __ISynchronizeEvent_FWD_DEFINED__
#define __ISynchronizeEvent_FWD_DEFINED__
typedef interface ISynchronizeEvent ISynchronizeEvent;
#endif 
#ifndef __ISynchronizeContainer_FWD_DEFINED__
#define __ISynchronizeContainer_FWD_DEFINED__
typedef interface ISynchronizeContainer ISynchronizeContainer;
#endif 
#ifndef __ISynchronizeMutex_FWD_DEFINED__
#define __ISynchronizeMutex_FWD_DEFINED__
typedef interface ISynchronizeMutex ISynchronizeMutex;
#endif 
#ifndef __ICancelMethodCalls_FWD_DEFINED__
#define __ICancelMethodCalls_FWD_DEFINED__
typedef interface ICancelMethodCalls ICancelMethodCalls;
#endif 
#ifndef __IAsyncManager_FWD_DEFINED__
#define __IAsyncManager_FWD_DEFINED__
typedef interface IAsyncManager IAsyncManager;
#endif 
#ifndef __ICallFactory_FWD_DEFINED__
#define __ICallFactory_FWD_DEFINED__
typedef interface ICallFactory ICallFactory;
#endif 
#ifndef __IRpcHelper_FWD_DEFINED__
#define __IRpcHelper_FWD_DEFINED__
typedef interface IRpcHelper IRpcHelper;
#endif 
#ifndef __IReleaseMarshalBuffers_FWD_DEFINED__
#define __IReleaseMarshalBuffers_FWD_DEFINED__
typedef interface IReleaseMarshalBuffers IReleaseMarshalBuffers;
#endif 
#ifndef __IWaitMultiple_FWD_DEFINED__
#define __IWaitMultiple_FWD_DEFINED__
typedef interface IWaitMultiple IWaitMultiple;
#endif 
#ifndef __IUrlMon_FWD_DEFINED__
#define __IUrlMon_FWD_DEFINED__
typedef interface IUrlMon IUrlMon;
#endif 
#ifndef __IForegroundTransfer_FWD_DEFINED__
#define __IForegroundTransfer_FWD_DEFINED__
typedef interface IForegroundTransfer IForegroundTransfer;
#endif 
#ifndef __IAddrTrackingControl_FWD_DEFINED__
#define __IAddrTrackingControl_FWD_DEFINED__
typedef interface IAddrTrackingControl IAddrTrackingControl;
#endif 
#ifndef __IAddrExclusionControl_FWD_DEFINED__
#define __IAddrExclusionControl_FWD_DEFINED__
typedef interface IAddrExclusionControl IAddrExclusionControl;
#endif 
#ifndef __IPipeByte_FWD_DEFINED__
#define __IPipeByte_FWD_DEFINED__
typedef interface IPipeByte IPipeByte;
#endif 
#ifndef __AsyncIPipeByte_FWD_DEFINED__
#define __AsyncIPipeByte_FWD_DEFINED__
typedef interface AsyncIPipeByte AsyncIPipeByte;
#endif 
#ifndef __IPipeLong_FWD_DEFINED__
#define __IPipeLong_FWD_DEFINED__
typedef interface IPipeLong IPipeLong;
#endif 
#ifndef __AsyncIPipeLong_FWD_DEFINED__
#define __AsyncIPipeLong_FWD_DEFINED__
typedef interface AsyncIPipeLong AsyncIPipeLong;
#endif 
#ifndef __IPipeDouble_FWD_DEFINED__
#define __IPipeDouble_FWD_DEFINED__
typedef interface IPipeDouble IPipeDouble;
#endif 
#ifndef __AsyncIPipeDouble_FWD_DEFINED__
#define __AsyncIPipeDouble_FWD_DEFINED__
typedef interface AsyncIPipeDouble AsyncIPipeDouble;
#endif 
#ifndef __IThumbnailExtractor_FWD_DEFINED__
#define __IThumbnailExtractor_FWD_DEFINED__
typedef interface IThumbnailExtractor IThumbnailExtractor;
#endif 
#ifndef __IDummyHICONIncluder_FWD_DEFINED__
#define __IDummyHICONIncluder_FWD_DEFINED__
typedef interface IDummyHICONIncluder IDummyHICONIncluder;
#endif 
#ifndef __IEnumContextProps_FWD_DEFINED__
#define __IEnumContextProps_FWD_DEFINED__
typedef interface IEnumContextProps IEnumContextProps;
#endif 
#ifndef __IContext_FWD_DEFINED__
#define __IContext_FWD_DEFINED__
typedef interface IContext IContext;
#endif 
#ifndef __IObjContext_FWD_DEFINED__
#define __IObjContext_FWD_DEFINED__
typedef interface IObjContext IObjContext;
#endif 
#ifndef __IProcessLock_FWD_DEFINED__
#define __IProcessLock_FWD_DEFINED__
typedef interface IProcessLock IProcessLock;
#endif 
#ifndef __ISurrogateService_FWD_DEFINED__
#define __ISurrogateService_FWD_DEFINED__
typedef interface ISurrogateService ISurrogateService;
#endif 
#ifndef __IComThreadingInfo_FWD_DEFINED__
#define __IComThreadingInfo_FWD_DEFINED__
typedef interface IComThreadingInfo IComThreadingInfo;
#endif 
#ifndef __IProcessInitControl_FWD_DEFINED__
#define __IProcessInitControl_FWD_DEFINED__
typedef interface IProcessInitControl IProcessInitControl;
#endif 
#ifndef __IInitializeSpy_FWD_DEFINED__
#define __IInitializeSpy_FWD_DEFINED__
typedef interface IInitializeSpy IInitializeSpy;
#endif 
#include "unknwn.h"
void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void *); 
#if (_MSC_VER >= 800)
#if _MSC_VER >= 1200
#endif
#endif
#if (_MSC_VER >= 1020)
#endif
typedef struct _COSERVERINFO
{
DWORD dwReserved1;
LPWSTR pwszName;
COAUTHINFO *pAuthInfo;
DWORD dwReserved2;
} COSERVERINFO;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0000_v0_0_s_ifspec;
#ifndef __IMarshal_INTERFACE_DEFINED__
#define __IMarshal_INTERFACE_DEFINED__
typedef IMarshal *LPMARSHAL;
EXTERN_C const IID IID_IMarshal;
typedef struct IMarshalVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IMarshal *,REFIID,void **);
	ULONG (*AddRef)(IMarshal *);
	ULONG (*Release)(IMarshal *);
	HRESULT(*GetUnmarshalClass)(IMarshal *,REFIID,void *,DWORD,void *,DWORD,CLSID *);
	HRESULT(*GetMarshalSizeMax)(IMarshal *,REFIID,void *,DWORD,void *,DWORD,DWORD *);
	HRESULT(*MarshalInterface)(IMarshal *,IStream *,REFIID,void *,DWORD,void *,DWORD);
	HRESULT(*UnmarshalInterface)(IMarshal *,IStream *,REFIID,void **);
	HRESULT(*ReleaseMarshalData)(IMarshal *,IStream *);
	HRESULT(*DisconnectObject)(IMarshal *,DWORD);
END_INTERFACE
} IMarshalVtbl;
interface IMarshal
{
CONST_VTBL struct IMarshalVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMarshal_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IMarshal_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IMarshal_Release(A) (A)->lpVtbl->Release(A)
#define IMarshal_GetUnmarshalClass(A,B,C,D,E,F,G) (A)->lpVtbl->GetUnmarshalClass(A,B,C,D,E,F,G)
#define IMarshal_GetMarshalSizeMax(A,B,C,D,E,F,G) (A)->lpVtbl->GetMarshalSizeMax(A,B,C,D,E,F,G)
#define IMarshal_MarshalInterface(A,B,C,D,E,F,G) (A)->lpVtbl->MarshalInterface(A,B,C,D,E,F,G)
#define IMarshal_UnmarshalInterface(A,B,C,D) (A)->lpVtbl->UnmarshalInterface(A,B,C,D)
#define IMarshal_ReleaseMarshalData(A,B) (A)->lpVtbl->ReleaseMarshalData(A,B)
#define IMarshal_DisconnectObject(A,B) (A)->lpVtbl->DisconnectObject(A,B)
#endif 
HRESULT IMarshal_GetUnmarshalClass_Proxy(IMarshal *,REFIID,void *,DWORD,void *,DWORD,CLSID *);
void IMarshal_GetUnmarshalClass_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMarshal_GetMarshalSizeMax_Proxy(IMarshal *,REFIID,void *,DWORD,void *,DWORD,DWORD *);
void IMarshal_GetMarshalSizeMax_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMarshal_MarshalInterface_Proxy(IMarshal *,IStream *,REFIID,void *,DWORD,void *,DWORD);
void IMarshal_MarshalInterface_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMarshal_UnmarshalInterface_Proxy(IMarshal *,IStream *,REFIID,void **);
void IMarshal_UnmarshalInterface_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMarshal_ReleaseMarshalData_Proxy(IMarshal *,IStream *);
void IMarshal_ReleaseMarshalData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMarshal_DisconnectObject_Proxy(IMarshal *,DWORD);
void IMarshal_DisconnectObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IMarshal2_INTERFACE_DEFINED__
#define __IMarshal2_INTERFACE_DEFINED__
typedef IMarshal2 *LPMARSHAL2;
EXTERN_C const IID IID_IMarshal2;
typedef struct IMarshal2Vtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IMarshal2 *,REFIID,void **);
	ULONG (*AddRef)(IMarshal2 *);
	ULONG (*Release)(IMarshal2 *);
	HRESULT(*GetUnmarshalClass)(IMarshal2 *,REFIID,void *,DWORD,void *,DWORD,CLSID *);
	HRESULT(*GetMarshalSizeMax)(IMarshal2 *,REFIID,void *,DWORD,void *,DWORD,DWORD *);
	HRESULT(*MarshalInterface)(IMarshal2 *,IStream *,REFIID,void *,DWORD,void *,DWORD);
	HRESULT(*UnmarshalInterface)(IMarshal2 *,IStream *,REFIID,void **);
	HRESULT(*ReleaseMarshalData)(IMarshal2 *,IStream *);
	HRESULT(*DisconnectObject)(IMarshal2 *,DWORD);
END_INTERFACE
} IMarshal2Vtbl;
interface IMarshal2
{
CONST_VTBL struct IMarshal2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMarshal2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IMarshal2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IMarshal2_Release(A) (A)->lpVtbl->Release(A)
#define IMarshal2_GetUnmarshalClass(A,B,C,D,E,F,G) (A)->lpVtbl->GetUnmarshalClass(A,B,C,D,E,F,G)
#define IMarshal2_GetMarshalSizeMax(A,B,C,D,E,F,G) (A)->lpVtbl->GetMarshalSizeMax(A,B,C,D,E,F,G)
#define IMarshal2_MarshalInterface(A,B,C,D,E,F,G) (A)->lpVtbl->MarshalInterface(A,B,C,D,E,F,G)
#define IMarshal2_UnmarshalInterface(A,B,C,D) (A)->lpVtbl->UnmarshalInterface(A,B,C,D)
#define IMarshal2_ReleaseMarshalData(A,B) (A)->lpVtbl->ReleaseMarshalData(A,B)
#define IMarshal2_DisconnectObject(A,B) (A)->lpVtbl->DisconnectObject(A,B)
#endif 
#endif 
#ifndef __IMalloc_INTERFACE_DEFINED__
#define __IMalloc_INTERFACE_DEFINED__
typedef IMalloc *LPMALLOC;
EXTERN_C const IID IID_IMalloc;
typedef struct IMallocVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IMalloc *,REFIID,void **);
	ULONG (*AddRef)(IMalloc *);
	ULONG (*Release)(IMalloc *);
	void *(*Alloc)(IMalloc *,SIZE_T);
	void *(*Realloc)(IMalloc *,void *,SIZE_T);
	void (*Free)(IMalloc *,void *);
	SIZE_T (*GetSize)(IMalloc *,void *);
	int (*DidAlloc)(IMalloc *,void *);
	void (*HeapMinimize)(IMalloc *);
END_INTERFACE
} IMallocVtbl;
interface IMalloc
{
CONST_VTBL struct IMallocVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMalloc_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IMalloc_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IMalloc_Release(A) (A)->lpVtbl->Release(A)
#define IMalloc_Alloc(A,B) (A)->lpVtbl->Alloc(A,B)
#define IMalloc_Realloc(A,B,C) (A)->lpVtbl->Realloc(A,B,C)
#define IMalloc_Free(A,B) (A)->lpVtbl->Free(A,B)
#define IMalloc_GetSize(A,B) (A)->lpVtbl->GetSize(A,B)
#define IMalloc_DidAlloc(A,B) (A)->lpVtbl->DidAlloc(A,B)
#define IMalloc_HeapMinimize(A) (A)->lpVtbl->HeapMinimize(A)
#endif 
void * IMalloc_Alloc_Proxy(IMalloc *,SIZE_T);
void IMalloc_Alloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void * IMalloc_Realloc_Proxy(IMalloc *,void *,SIZE_T);
void IMalloc_Realloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IMalloc_Free_Proxy(IMalloc *,void *);
void IMalloc_Free_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
SIZE_T IMalloc_GetSize_Proxy(IMalloc *,void *);
void IMalloc_GetSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
int IMalloc_DidAlloc_Proxy(IMalloc *,void *);
void IMalloc_DidAlloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IMalloc_HeapMinimize_Proxy(IMalloc *);
void IMalloc_HeapMinimize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IMallocSpy_INTERFACE_DEFINED__
#define __IMallocSpy_INTERFACE_DEFINED__
typedef IMallocSpy *LPMALLOCSPY;
EXTERN_C const IID IID_IMallocSpy;
typedef struct IMallocSpyVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IMallocSpy *,REFIID,void **);
	ULONG (*AddRef)(IMallocSpy *);
	ULONG (*Release)(IMallocSpy *);
	SIZE_T (*PreAlloc)(IMallocSpy *,SIZE_T);
	void *(*PostAlloc)(IMallocSpy *,void *);
	void *(*PreFree)(IMallocSpy *,void *,BOOL);
	void (*PostFree)(IMallocSpy *,BOOL);
	SIZE_T (*PreRealloc)(IMallocSpy *,void *,SIZE_T,void **,BOOL);
	void *(*PostRealloc)(IMallocSpy *,void *,BOOL);
	void *(*PreGetSize)(IMallocSpy *,void *,BOOL);
	SIZE_T (*PostGetSize)(IMallocSpy *,SIZE_T,BOOL);
	void *(*PreDidAlloc)(IMallocSpy *,void *,BOOL);
	int (*PostDidAlloc)(IMallocSpy *,void *,BOOL,int);
	void (*PreHeapMinimize)(IMallocSpy *);
	void (*PostHeapMinimize)(IMallocSpy *);
END_INTERFACE
} IMallocSpyVtbl;
interface IMallocSpy
{
CONST_VTBL struct IMallocSpyVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMallocSpy_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IMallocSpy_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IMallocSpy_Release(A) (A)->lpVtbl->Release(A)
#define IMallocSpy_PreAlloc(A,B) (A)->lpVtbl->PreAlloc(A,B)
#define IMallocSpy_PostAlloc(A,B) (A)->lpVtbl->PostAlloc(A,B)
#define IMallocSpy_PreFree(A,B,C) (A)->lpVtbl->PreFree(A,B,C)
#define IMallocSpy_PostFree(A,B) (A)->lpVtbl->PostFree(A,B)
#define IMallocSpy_PreRealloc(A,B,C,D,E) (A)->lpVtbl->PreRealloc(A,B,C,D,E)
#define IMallocSpy_PostRealloc(A,B,C) (A)->lpVtbl->PostRealloc(A,B,C)
#define IMallocSpy_PreGetSize(A,B,C) (A)->lpVtbl->PreGetSize(A,B,C)
#define IMallocSpy_PostGetSize(A,B,C) (A)->lpVtbl->PostGetSize(A,B,C)
#define IMallocSpy_PreDidAlloc(A,B,C) (A)->lpVtbl->PreDidAlloc(A,B,C)
#define IMallocSpy_PostDidAlloc(A,B,C,D) (A)->lpVtbl->PostDidAlloc(A,B,C,D)
#define IMallocSpy_PreHeapMinimize(A) (A)->lpVtbl->PreHeapMinimize(A)
#define IMallocSpy_PostHeapMinimize(A) (A)->lpVtbl->PostHeapMinimize(A)
#endif 
SIZE_T IMallocSpy_PreAlloc_Proxy(IMallocSpy *,SIZE_T);
void IMallocSpy_PreAlloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void * IMallocSpy_PostAlloc_Proxy(IMallocSpy *,void *);
void IMallocSpy_PostAlloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void * IMallocSpy_PreFree_Proxy(IMallocSpy *,void *,BOOL);
void IMallocSpy_PreFree_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IMallocSpy_PostFree_Proxy(IMallocSpy *,BOOL);
void IMallocSpy_PostFree_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
SIZE_T IMallocSpy_PreRealloc_Proxy(IMallocSpy *,void *,SIZE_T,void **,BOOL);
void IMallocSpy_PreRealloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void * IMallocSpy_PostRealloc_Proxy(IMallocSpy *,void *,BOOL);
void IMallocSpy_PostRealloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void * IMallocSpy_PreGetSize_Proxy(IMallocSpy *,void *,BOOL);
void IMallocSpy_PreGetSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
SIZE_T IMallocSpy_PostGetSize_Proxy(IMallocSpy *,SIZE_T,BOOL);
void IMallocSpy_PostGetSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void * IMallocSpy_PreDidAlloc_Proxy(IMallocSpy *,void *,BOOL);
void IMallocSpy_PreDidAlloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
int IMallocSpy_PostDidAlloc_Proxy(IMallocSpy *,void *,BOOL,int);
void IMallocSpy_PostDidAlloc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IMallocSpy_PreHeapMinimize_Proxy(IMallocSpy *);
void IMallocSpy_PreHeapMinimize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IMallocSpy_PostHeapMinimize_Proxy(IMallocSpy *);
void IMallocSpy_PostHeapMinimize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IStdMarshalInfo_INTERFACE_DEFINED__
#define __IStdMarshalInfo_INTERFACE_DEFINED__
typedef IStdMarshalInfo *LPSTDMARSHALINFO;
EXTERN_C const IID IID_IStdMarshalInfo;
typedef struct IStdMarshalInfoVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IStdMarshalInfo *,REFIID,void **);
	ULONG (*AddRef)(IStdMarshalInfo *);
	ULONG (*Release)(IStdMarshalInfo *);
	HRESULT(*GetClassForHandler)(IStdMarshalInfo *,DWORD,void *,CLSID *);
END_INTERFACE
} IStdMarshalInfoVtbl;
interface IStdMarshalInfo
{
CONST_VTBL struct IStdMarshalInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IStdMarshalInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IStdMarshalInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IStdMarshalInfo_Release(A) (A)->lpVtbl->Release(A)
#define IStdMarshalInfo_GetClassForHandler(A,B,C,D) (A)->lpVtbl->GetClassForHandler(A,B,C,D)
#endif 
HRESULT IStdMarshalInfo_GetClassForHandler_Proxy(IStdMarshalInfo *,DWORD,void *,CLSID *);
void IStdMarshalInfo_GetClassForHandler_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IExternalConnection_INTERFACE_DEFINED__
#define __IExternalConnection_INTERFACE_DEFINED__
typedef IExternalConnection *LPEXTERNALCONNECTION;
typedef 
enum tagEXTCONN
{	EXTCONN_STRONG=1,EXTCONN_WEAK=2,EXTCONN_CALLABLE=4
} EXTCONN;
EXTERN_C const IID IID_IExternalConnection;
typedef struct IExternalConnectionVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IExternalConnection *,REFIID,void **);
	ULONG (*AddRef)(IExternalConnection *);
	ULONG (*Release)(IExternalConnection *);
	DWORD (*AddConnection)(IExternalConnection *,DWORD,DWORD);
	DWORD (*ReleaseConnection)(IExternalConnection *,DWORD,DWORD,BOOL);
END_INTERFACE
} IExternalConnectionVtbl;
interface IExternalConnection
{
CONST_VTBL struct IExternalConnectionVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IExternalConnection_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IExternalConnection_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IExternalConnection_Release(A) (A)->lpVtbl->Release(A)
#define IExternalConnection_AddConnection(A,B,C) (A)->lpVtbl->AddConnection(A,B,C)
#define IExternalConnection_ReleaseConnection(A,B,C,D) (A)->lpVtbl->ReleaseConnection(A,B,C,D)
#endif 
DWORD IExternalConnection_AddConnection_Proxy(IExternalConnection *,DWORD,DWORD);
void IExternalConnection_AddConnection_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
DWORD IExternalConnection_ReleaseConnection_Proxy(IExternalConnection *,DWORD,DWORD,BOOL);
void IExternalConnection_ReleaseConnection_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
typedef IMultiQI *LPMULTIQI;
typedef struct tagMULTI_QI
{
const IID *pIID;
IUnknown *pItf;
HRESULT hr;
} MULTI_QI;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0015_v0_0_s_ifspec;
#ifndef __IMultiQI_INTERFACE_DEFINED__
#define __IMultiQI_INTERFACE_DEFINED__
EXTERN_C const IID IID_IMultiQI;
typedef struct IMultiQIVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IMultiQI *,REFIID,void **);
	ULONG (*AddRef)(IMultiQI *);
	ULONG (*Release)(IMultiQI *);
	HRESULT(*QueryMultipleInterfaces)(IMultiQI *,ULONG,MULTI_QI *);
END_INTERFACE
} IMultiQIVtbl;
interface IMultiQI
{
CONST_VTBL struct IMultiQIVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMultiQI_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IMultiQI_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IMultiQI_Release(A) (A)->lpVtbl->Release(A)
#define IMultiQI_QueryMultipleInterfaces(A,B,C) (A)->lpVtbl->QueryMultipleInterfaces(A,B,C)
#endif 
HRESULT IMultiQI_QueryMultipleInterfaces_Proxy(IMultiQI *,ULONG,MULTI_QI *);
void IMultiQI_QueryMultipleInterfaces_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __AsyncIMultiQI_INTERFACE_DEFINED__
#define __AsyncIMultiQI_INTERFACE_DEFINED__
EXTERN_C const IID IID_AsyncIMultiQI;
typedef struct AsyncIMultiQIVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(AsyncIMultiQI *,REFIID,void **);
	ULONG (*AddRef)(AsyncIMultiQI *);
	ULONG (*Release)(AsyncIMultiQI *);
	HRESULT(*Begin_QueryMultipleInterfaces)(AsyncIMultiQI *,ULONG,MULTI_QI *);
	HRESULT(*Finish_QueryMultipleInterfaces)(AsyncIMultiQI *,MULTI_QI *);
END_INTERFACE
} AsyncIMultiQIVtbl;
interface AsyncIMultiQI
{
CONST_VTBL struct AsyncIMultiQIVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define AsyncIMultiQI_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define AsyncIMultiQI_AddRef(A) (A)->lpVtbl->AddRef(A)
#define AsyncIMultiQI_Release(A) (A)->lpVtbl->Release(A)
#define AsyncIMultiQI_Begin_QueryMultipleInterfaces(A,B,C) (A)->lpVtbl->Begin_QueryMultipleInterfaces(A,B,C)
#define AsyncIMultiQI_Finish_QueryMultipleInterfaces(A,B) (A)->lpVtbl->Finish_QueryMultipleInterfaces(A,B)
#endif 
HRESULT AsyncIMultiQI_Begin_QueryMultipleInterfaces_Proxy(AsyncIMultiQI *,ULONG,MULTI_QI *);
void AsyncIMultiQI_Begin_QueryMultipleInterfaces_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIMultiQI_Finish_QueryMultipleInterfaces_Proxy(AsyncIMultiQI *,MULTI_QI *);
void AsyncIMultiQI_Finish_QueryMultipleInterfaces_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IInternalUnknown_INTERFACE_DEFINED__
#define __IInternalUnknown_INTERFACE_DEFINED__
EXTERN_C const IID IID_IInternalUnknown;
typedef struct IInternalUnknownVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IInternalUnknown *,REFIID,void **);
	ULONG (*AddRef)(IInternalUnknown *);
	ULONG (*Release)(IInternalUnknown *);
	HRESULT(*QueryInternalInterface)(IInternalUnknown *,REFIID,void **);
END_INTERFACE
} IInternalUnknownVtbl;
interface IInternalUnknown
{
CONST_VTBL struct IInternalUnknownVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInternalUnknown_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInternalUnknown_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInternalUnknown_Release(A) (A)->lpVtbl->Release(A)
#define IInternalUnknown_QueryInternalInterface(A,B,C) (A)->lpVtbl->QueryInternalInterface(A,B,C)
#endif 
HRESULT IInternalUnknown_QueryInternalInterface_Proxy(IInternalUnknown *,REFIID,void **);
void IInternalUnknown_QueryInternalInterface_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IEnumUnknown_INTERFACE_DEFINED__
#define __IEnumUnknown_INTERFACE_DEFINED__
typedef IEnumUnknown *LPENUMUNKNOWN;
EXTERN_C const IID IID_IEnumUnknown;
typedef struct IEnumUnknownVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IEnumUnknown *,REFIID,void **);
	ULONG (*AddRef)(IEnumUnknown *);
	ULONG (*Release)(IEnumUnknown *);
	HRESULT(*Next)(IEnumUnknown *,ULONG,IUnknown **,ULONG *);
	HRESULT(*Skip)(IEnumUnknown *,ULONG);
	HRESULT(*Reset)(IEnumUnknown *);
	HRESULT(*Clone)(IEnumUnknown *,IEnumUnknown **);
END_INTERFACE
} IEnumUnknownVtbl;
interface IEnumUnknown
{
CONST_VTBL struct IEnumUnknownVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumUnknown_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumUnknown_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumUnknown_Release(A) (A)->lpVtbl->Release(A)
#define IEnumUnknown_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumUnknown_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumUnknown_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumUnknown_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IEnumUnknown_RemoteNext_Proxy(IEnumUnknown *,ULONG,IUnknown **,ULONG *);
void IEnumUnknown_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumUnknown_Skip_Proxy(IEnumUnknown *,ULONG);
void IEnumUnknown_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumUnknown_Reset_Proxy(IEnumUnknown *);
void IEnumUnknown_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumUnknown_Clone_Proxy(IEnumUnknown *,IEnumUnknown **);
void IEnumUnknown_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IBindCtx_INTERFACE_DEFINED__
#define __IBindCtx_INTERFACE_DEFINED__
typedef IBindCtx *LPBC;
typedef IBindCtx *LPBINDCTX;
typedef struct tagBIND_OPTS
{
DWORD cbStruct;
DWORD grfFlags;
DWORD grfMode;
DWORD dwTickCountDeadline;
} BIND_OPTS;
typedef struct tagBIND_OPTS *LPBIND_OPTS;
#if defined(__cplusplus)
typedef struct tagBIND_OPTS2 : tagBIND_OPTS{
DWORD dwTrackFlags;
DWORD dwClassContext;
LCID locale;
COSERVERINFO * pServerInfo;
} BIND_OPTS2,* LPBIND_OPTS2;
#else
typedef struct tagBIND_OPTS2
{
DWORD cbStruct;
DWORD grfFlags;
DWORD grfMode;
DWORD dwTickCountDeadline;
DWORD dwTrackFlags;
DWORD dwClassContext;
LCID locale;
COSERVERINFO *pServerInfo;
} BIND_OPTS2;
typedef struct tagBIND_OPTS2 *LPBIND_OPTS2;
#endif
typedef 
enum tagBIND_FLAGS
{	BIND_MAYBOTHERUSER=1,BIND_JUSTTESTEXISTENCE=2
} BIND_FLAGS;
EXTERN_C const IID IID_IBindCtx;
typedef struct IBindCtxVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IBindCtx *,REFIID,void **);
	ULONG (*AddRef)(IBindCtx *);
	ULONG (*Release)(IBindCtx *);
	HRESULT(*RegisterObjectBound)(IBindCtx *,IUnknown *);
	HRESULT(*RevokeObjectBound)(IBindCtx *,IUnknown *);
	HRESULT(*ReleaseBoundObjects)(IBindCtx *);
	HRESULT(*SetBindOptions)(IBindCtx *,BIND_OPTS *);
	HRESULT(*GetBindOptions)(IBindCtx *,BIND_OPTS *);
	HRESULT(*GetRunningObjectTable)(IBindCtx *,IRunningObjectTable **);
	HRESULT(*RegisterObjectParam)(IBindCtx *,LPOLESTR,IUnknown *);
	HRESULT(*GetObjectParam)(IBindCtx *,LPOLESTR,IUnknown **);
	HRESULT(*EnumObjectParam)(IBindCtx *,IEnumString **);
	HRESULT(*RevokeObjectParam)(IBindCtx *,LPOLESTR);
END_INTERFACE
} IBindCtxVtbl;
interface IBindCtx
{
CONST_VTBL struct IBindCtxVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IBindCtx_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IBindCtx_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IBindCtx_Release(A) (A)->lpVtbl->Release(A)
#define IBindCtx_RegisterObjectBound(A,B) (A)->lpVtbl->RegisterObjectBound(A,B)
#define IBindCtx_RevokeObjectBound(A,B) (A)->lpVtbl->RevokeObjectBound(A,B)
#define IBindCtx_ReleaseBoundObjects(A) (A)->lpVtbl->ReleaseBoundObjects(A)
#define IBindCtx_SetBindOptions(A,B) (A)->lpVtbl->SetBindOptions(A,B)
#define IBindCtx_GetBindOptions(A,B) (A)->lpVtbl->GetBindOptions(A,B)
#define IBindCtx_GetRunningObjectTable(A,B) (A)->lpVtbl->GetRunningObjectTable(A,B)
#define IBindCtx_RegisterObjectParam(A,B,C) (A)->lpVtbl->RegisterObjectParam(A,B,C)
#define IBindCtx_GetObjectParam(A,B,C) (A)->lpVtbl->GetObjectParam(A,B,C)
#define IBindCtx_EnumObjectParam(A,B) (A)->lpVtbl->EnumObjectParam(A,B)
#define IBindCtx_RevokeObjectParam(A,B) (A)->lpVtbl->RevokeObjectParam(A,B)
#endif 
HRESULT IBindCtx_RegisterObjectBound_Proxy(IBindCtx *,IUnknown *);
void IBindCtx_RegisterObjectBound_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_RevokeObjectBound_Proxy(IBindCtx *,IUnknown *);
void IBindCtx_RevokeObjectBound_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_ReleaseBoundObjects_Proxy(IBindCtx *);
void IBindCtx_ReleaseBoundObjects_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_RemoteSetBindOptions_Proxy(IBindCtx *,BIND_OPTS2 *);
void IBindCtx_RemoteSetBindOptions_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_RemoteGetBindOptions_Proxy(IBindCtx *,BIND_OPTS2 *);
void IBindCtx_RemoteGetBindOptions_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_GetRunningObjectTable_Proxy(IBindCtx *,IRunningObjectTable **);
void IBindCtx_GetRunningObjectTable_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_RegisterObjectParam_Proxy(IBindCtx *,LPOLESTR,IUnknown *);
void IBindCtx_RegisterObjectParam_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_GetObjectParam_Proxy(IBindCtx *,LPOLESTR,IUnknown **);
void IBindCtx_GetObjectParam_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_EnumObjectParam_Proxy(IBindCtx *,IEnumString **);
void IBindCtx_EnumObjectParam_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBindCtx_RevokeObjectParam_Proxy(IBindCtx *,LPOLESTR);
void IBindCtx_RevokeObjectParam_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IEnumMoniker_INTERFACE_DEFINED__
#define __IEnumMoniker_INTERFACE_DEFINED__
typedef IEnumMoniker *LPENUMMONIKER;
EXTERN_C const IID IID_IEnumMoniker;
typedef struct IEnumMonikerVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IEnumMoniker *,REFIID,void **);
	ULONG (*AddRef)(IEnumMoniker *);
	ULONG (*Release)(IEnumMoniker *);
	HRESULT(*Next)(IEnumMoniker *,ULONG,IMoniker **,ULONG *);
	HRESULT(*Skip)(IEnumMoniker *,ULONG);
	HRESULT(*Reset)(IEnumMoniker *);
	HRESULT(*Clone)(IEnumMoniker *,IEnumMoniker **);
END_INTERFACE
} IEnumMonikerVtbl;
interface IEnumMoniker
{
CONST_VTBL struct IEnumMonikerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumMoniker_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumMoniker_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumMoniker_Release(A) (A)->lpVtbl->Release(A)
#define IEnumMoniker_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumMoniker_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumMoniker_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumMoniker_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IEnumMoniker_RemoteNext_Proxy(IEnumMoniker *,ULONG,IMoniker **,ULONG *);
void IEnumMoniker_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumMoniker_Skip_Proxy(IEnumMoniker *,ULONG);
void IEnumMoniker_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumMoniker_Reset_Proxy(IEnumMoniker *);
void IEnumMoniker_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumMoniker_Clone_Proxy(IEnumMoniker *,IEnumMoniker **);
void IEnumMoniker_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRunnableObject_INTERFACE_DEFINED__
#define __IRunnableObject_INTERFACE_DEFINED__
typedef IRunnableObject *LPRUNNABLEOBJECT;
EXTERN_C const IID IID_IRunnableObject;
typedef struct IRunnableObjectVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRunnableObject *,REFIID,void **);
	ULONG (*AddRef)(IRunnableObject *);
	ULONG (*Release)(IRunnableObject *);
	HRESULT(*GetRunningClass)(IRunnableObject *,LPCLSID);
	HRESULT(*Run)(IRunnableObject *,LPBINDCTX);
	BOOL (*IsRunning)(IRunnableObject *);
	HRESULT(*LockRunning)(IRunnableObject *,BOOL,BOOL);
	HRESULT(*SetContainedObject)(IRunnableObject *,BOOL);
END_INTERFACE
} IRunnableObjectVtbl;
interface IRunnableObject
{
CONST_VTBL struct IRunnableObjectVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRunnableObject_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRunnableObject_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRunnableObject_Release(A) (A)->lpVtbl->Release(A)
#define IRunnableObject_GetRunningClass(A,B) (A)->lpVtbl->GetRunningClass(A,B)
#define IRunnableObject_Run(A,B) (A)->lpVtbl->Run(A,B)
#define IRunnableObject_IsRunning(A) (A)->lpVtbl->IsRunning(A)
#define IRunnableObject_LockRunning(A,B,C) (A)->lpVtbl->LockRunning(A,B,C)
#define IRunnableObject_SetContainedObject(A,B) (A)->lpVtbl->SetContainedObject(A,B)
#endif 
HRESULT IRunnableObject_GetRunningClass_Proxy(IRunnableObject *,LPCLSID);
void IRunnableObject_GetRunningClass_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunnableObject_Run_Proxy(IRunnableObject *,LPBINDCTX);
void IRunnableObject_Run_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunnableObject_RemoteIsRunning_Proxy(IRunnableObject *);
void IRunnableObject_RemoteIsRunning_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunnableObject_LockRunning_Proxy(IRunnableObject *,BOOL,BOOL);
void IRunnableObject_LockRunning_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunnableObject_SetContainedObject_Proxy(IRunnableObject *,BOOL);
void IRunnableObject_SetContainedObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRunningObjectTable_INTERFACE_DEFINED__
#define __IRunningObjectTable_INTERFACE_DEFINED__
typedef IRunningObjectTable *LPRUNNINGOBJECTTABLE;
EXTERN_C const IID IID_IRunningObjectTable;
typedef struct IRunningObjectTableVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRunningObjectTable *,REFIID,void **);
	ULONG (*AddRef)(IRunningObjectTable *);
	ULONG (*Release)(IRunningObjectTable *);
	HRESULT(*Register)(IRunningObjectTable *,DWORD,IUnknown *,IMoniker *,DWORD *);
	HRESULT(*Revoke)(IRunningObjectTable *,DWORD);
	HRESULT(*IsRunning)(IRunningObjectTable *,IMoniker *);
	HRESULT(*GetObject)(IRunningObjectTable *,IMoniker *,IUnknown **);
	HRESULT(*NoteChangeTime)(IRunningObjectTable *,DWORD,FILETIME *);
	HRESULT(*GetTimeOfLastChange)(IRunningObjectTable *,IMoniker *,FILETIME *);
	HRESULT(*EnumRunning)(IRunningObjectTable *,IEnumMoniker **);
END_INTERFACE
} IRunningObjectTableVtbl;
interface IRunningObjectTable
{
CONST_VTBL struct IRunningObjectTableVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRunningObjectTable_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRunningObjectTable_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRunningObjectTable_Release(A) (A)->lpVtbl->Release(A)
#define IRunningObjectTable_Register(A,B,C,D,E) (A)->lpVtbl->Register(A,B,C,D,E)
#define IRunningObjectTable_Revoke(A,B) (A)->lpVtbl->Revoke(A,B)
#define IRunningObjectTable_IsRunning(A,B) (A)->lpVtbl->IsRunning(A,B)
#define IRunningObjectTable_GetObject(A,B,C) (A)->lpVtbl->GetObject(A,B,C)
#define IRunningObjectTable_NoteChangeTime(A,B,C) (A)->lpVtbl->NoteChangeTime(A,B,C)
#define IRunningObjectTable_GetTimeOfLastChange(A,B,C) (A)->lpVtbl->GetTimeOfLastChange(A,B,C)
#define IRunningObjectTable_EnumRunning(A,B) (A)->lpVtbl->EnumRunning(A,B)
#endif 
HRESULT IRunningObjectTable_Register_Proxy(IRunningObjectTable *,DWORD,IUnknown *,IMoniker *,DWORD *);
void IRunningObjectTable_Register_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunningObjectTable_Revoke_Proxy(IRunningObjectTable *,DWORD);
void IRunningObjectTable_Revoke_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunningObjectTable_IsRunning_Proxy(IRunningObjectTable *,IMoniker *);
void IRunningObjectTable_IsRunning_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunningObjectTable_GetObject_Proxy(IRunningObjectTable *,IMoniker *,IUnknown **);
void IRunningObjectTable_GetObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunningObjectTable_NoteChangeTime_Proxy(IRunningObjectTable *,DWORD,FILETIME *);
void IRunningObjectTable_NoteChangeTime_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunningObjectTable_GetTimeOfLastChange_Proxy(IRunningObjectTable *,IMoniker *,FILETIME *);
void IRunningObjectTable_GetTimeOfLastChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRunningObjectTable_EnumRunning_Proxy(IRunningObjectTable *,IEnumMoniker **);
void IRunningObjectTable_EnumRunning_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IPersist_INTERFACE_DEFINED__
#define __IPersist_INTERFACE_DEFINED__
typedef IPersist *LPPERSIST;
EXTERN_C const IID IID_IPersist;
typedef struct IPersistVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IPersist *,REFIID,void **);
	ULONG (*AddRef)(IPersist *);
	ULONG (*Release)(IPersist *);
	HRESULT(*GetClassID)(IPersist *,CLSID *);
END_INTERFACE
} IPersistVtbl;
interface IPersist
{
CONST_VTBL struct IPersistVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPersist_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPersist_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPersist_Release(A) (A)->lpVtbl->Release(A)
#define IPersist_GetClassID(A,B) (A)->lpVtbl->GetClassID(A,B)
#endif 
HRESULT IPersist_GetClassID_Proxy(IPersist *,CLSID *);
void IPersist_GetClassID_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IPersistStream_INTERFACE_DEFINED__
#define __IPersistStream_INTERFACE_DEFINED__
typedef IPersistStream *LPPERSISTSTREAM;
EXTERN_C const IID IID_IPersistStream;
typedef struct IPersistStreamVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IPersistStream *,REFIID,void **);
	ULONG (*AddRef)(IPersistStream *);
	ULONG (*Release)(IPersistStream *);
	HRESULT(*GetClassID)(IPersistStream *,CLSID *);
	HRESULT(*IsDirty)(IPersistStream *);
	HRESULT(*Load)(IPersistStream *,IStream *);
	HRESULT(*Save)(IPersistStream *,IStream *,BOOL);
	HRESULT(*GetSizeMax)(IPersistStream *,ULARGE_INTEGER *);
END_INTERFACE
} IPersistStreamVtbl;
interface IPersistStream
{
CONST_VTBL struct IPersistStreamVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPersistStream_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPersistStream_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPersistStream_Release(A) (A)->lpVtbl->Release(A)
#define IPersistStream_GetClassID(A,B) (A)->lpVtbl->GetClassID(A,B)
#define IPersistStream_IsDirty(A) (A)->lpVtbl->IsDirty(A)
#define IPersistStream_Load(A,B) (A)->lpVtbl->Load(A,B)
#define IPersistStream_Save(A,B,C) (A)->lpVtbl->Save(A,B,C)
#define IPersistStream_GetSizeMax(A,B) (A)->lpVtbl->GetSizeMax(A,B)
#endif 
HRESULT IPersistStream_IsDirty_Proxy(IPersistStream *);
void IPersistStream_IsDirty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistStream_Load_Proxy(IPersistStream *,IStream *);
void IPersistStream_Load_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistStream_Save_Proxy(IPersistStream *,IStream *,BOOL);
void IPersistStream_Save_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistStream_GetSizeMax_Proxy(IPersistStream *,ULARGE_INTEGER *);
void IPersistStream_GetSizeMax_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IMoniker_INTERFACE_DEFINED__
#define __IMoniker_INTERFACE_DEFINED__
typedef IMoniker *LPMONIKER;
typedef 
enum tagMKSYS
{	MKSYS_NONE=0,MKSYS_GENERICCOMPOSITE=1,MKSYS_FILEMONIKER=2,MKSYS_ANTIMONIKER=3,MKSYS_ITEMMONIKER=4,MKSYS_POINTERMONIKER=5,MKSYS_CLASSMONIKER=7,MKSYS_OBJREFMONIKER=8,MKSYS_SESSIONMONIKER=9
} MKSYS;
typedef 
enum tagMKREDUCE
{	MKRREDUCE_ONE=3 << 16,MKRREDUCE_TOUSER=2 << 16,MKRREDUCE_THROUGHUSER=1 << 16,MKRREDUCE_ALL=0
} MKRREDUCE;
EXTERN_C const IID IID_IMoniker;
typedef struct IMonikerVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IMoniker *,REFIID,void **);
	ULONG (*AddRef)(IMoniker *);
	ULONG (*Release)(IMoniker *);
	HRESULT(*GetClassID)(IMoniker *,CLSID *);
	HRESULT(*IsDirty)(IMoniker *);
	HRESULT(*Load)(IMoniker *,IStream *);
	HRESULT(*Save)(IMoniker *,IStream *,BOOL);
	HRESULT(*GetSizeMax)(IMoniker *,ULARGE_INTEGER *);
	HRESULT(*BindToObject)(IMoniker *,IBindCtx *,IMoniker *,REFIID,void **);
	HRESULT(*BindToStorage)(IMoniker *,IBindCtx *,IMoniker *,REFIID,void **);
	HRESULT(*Reduce)(IMoniker *,IBindCtx *,DWORD,IMoniker **,IMoniker **);
	HRESULT(*ComposeWith)(IMoniker *,IMoniker *,BOOL,IMoniker **);
	HRESULT(*Enum)(IMoniker *,BOOL,IEnumMoniker **);
	HRESULT(*IsEqual)(IMoniker *,IMoniker *);
	HRESULT(*Hash)(IMoniker *,DWORD *);
	HRESULT(*IsRunning)(IMoniker *,IBindCtx *,IMoniker *,IMoniker *);
	HRESULT(*GetTimeOfLastChange)(IMoniker *,IBindCtx *,IMoniker *,FILETIME *);
	HRESULT(*Inverse)(IMoniker *,IMoniker **);
	HRESULT(*CommonPrefixWith)(IMoniker *,IMoniker *,IMoniker **);
	HRESULT(*RelativePathTo)(IMoniker *,IMoniker *,IMoniker **);
	HRESULT(*GetDisplayName)(IMoniker *,IBindCtx *,IMoniker *,LPOLESTR *);
	HRESULT(*ParseDisplayName)(IMoniker *,IBindCtx *,IMoniker *,LPOLESTR,ULONG *,IMoniker **);
	HRESULT(*IsSystemMoniker)(IMoniker *,DWORD *);
END_INTERFACE
} IMonikerVtbl;
interface IMoniker
{
CONST_VTBL struct IMonikerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMoniker_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IMoniker_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IMoniker_Release(A) (A)->lpVtbl->Release(A)
#define IMoniker_GetClassID(A,B) (A)->lpVtbl->GetClassID(A,B)
#define IMoniker_IsDirty(A) (A)->lpVtbl->IsDirty(A)
#define IMoniker_Load(A,B) (A)->lpVtbl->Load(A,B)
#define IMoniker_Save(A,B,C) (A)->lpVtbl->Save(A,B,C)
#define IMoniker_GetSizeMax(A,B) (A)->lpVtbl->GetSizeMax(A,B)
#define IMoniker_BindToObject(A,B,C,D,E) (A)->lpVtbl->BindToObject(A,B,C,D,E)
#define IMoniker_BindToStorage(A,B,C,D,E) (A)->lpVtbl->BindToStorage(A,B,C,D,E)
#define IMoniker_Reduce(A,B,C,D,E) (A)->lpVtbl->Reduce(A,B,C,D,E)
#define IMoniker_ComposeWith(A,B,C,D) (A)->lpVtbl->ComposeWith(A,B,C,D)
#define IMoniker_Enum(A,B,C) (A)->lpVtbl->Enum(A,B,C)
#define IMoniker_IsEqual(A,B) (A)->lpVtbl->IsEqual(A,B)
#define IMoniker_Hash(A,B) (A)->lpVtbl->Hash(A,B)
#define IMoniker_IsRunning(A,B,C,D) (A)->lpVtbl->IsRunning(A,B,C,D)
#define IMoniker_GetTimeOfLastChange(A,B,C,D) (A)->lpVtbl->GetTimeOfLastChange(A,B,C,D)
#define IMoniker_Inverse(A,B) (A)->lpVtbl->Inverse(A,B)
#define IMoniker_CommonPrefixWith(A,B,C) (A)->lpVtbl->CommonPrefixWith(A,B,C)
#define IMoniker_RelativePathTo(A,B,C) (A)->lpVtbl->RelativePathTo(A,B,C)
#define IMoniker_GetDisplayName(A,B,C,D) (A)->lpVtbl->GetDisplayName(A,B,C,D)
#define IMoniker_ParseDisplayName(A,B,C,D,E,F) (A)->lpVtbl->ParseDisplayName(A,B,C,D,E,F)
#define IMoniker_IsSystemMoniker(A,B) (A)->lpVtbl->IsSystemMoniker(A,B)
#endif 
HRESULT IMoniker_RemoteBindToObject_Proxy(IMoniker *,IBindCtx *,IMoniker *,REFIID,IUnknown **);
void IMoniker_RemoteBindToObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_RemoteBindToStorage_Proxy(IMoniker *,IBindCtx *,IMoniker *,REFIID,IUnknown **);
void IMoniker_RemoteBindToStorage_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_Reduce_Proxy(IMoniker *,IBindCtx *,DWORD,IMoniker **,IMoniker **);
void IMoniker_Reduce_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_ComposeWith_Proxy(IMoniker *,IMoniker *,BOOL,IMoniker **);
void IMoniker_ComposeWith_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_Enum_Proxy(IMoniker *,BOOL,IEnumMoniker **);
void IMoniker_Enum_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_IsEqual_Proxy(IMoniker *,IMoniker *);
void IMoniker_IsEqual_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_Hash_Proxy(IMoniker *,DWORD *);
void IMoniker_Hash_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_IsRunning_Proxy(IMoniker *,IBindCtx *,IMoniker *,IMoniker *);
void IMoniker_IsRunning_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_GetTimeOfLastChange_Proxy(IMoniker *,IBindCtx *,IMoniker *,FILETIME *);
void IMoniker_GetTimeOfLastChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_Inverse_Proxy(IMoniker *,IMoniker **);
void IMoniker_Inverse_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_CommonPrefixWith_Proxy(IMoniker *,IMoniker *,IMoniker **);
void IMoniker_CommonPrefixWith_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_RelativePathTo_Proxy(IMoniker *,IMoniker *,IMoniker **);
void IMoniker_RelativePathTo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_GetDisplayName_Proxy(IMoniker *,IBindCtx *,IMoniker *,LPOLESTR *);
void IMoniker_GetDisplayName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_ParseDisplayName_Proxy(IMoniker *,IBindCtx *,IMoniker *,LPOLESTR,ULONG *,IMoniker **);
void IMoniker_ParseDisplayName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IMoniker_IsSystemMoniker_Proxy(IMoniker *,DWORD *);
void IMoniker_IsSystemMoniker_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IROTData_INTERFACE_DEFINED__
#define __IROTData_INTERFACE_DEFINED__
EXTERN_C const IID IID_IROTData;
typedef struct IROTDataVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IROTData *,REFIID,void **);
	ULONG (*AddRef)(IROTData *);
	ULONG (*Release)(IROTData *);
	HRESULT(*GetComparisonData)(IROTData *,byte *,ULONG,ULONG *);
END_INTERFACE
} IROTDataVtbl;
interface IROTData
{
CONST_VTBL struct IROTDataVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IROTData_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IROTData_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IROTData_Release(A) (A)->lpVtbl->Release(A)
#define IROTData_GetComparisonData(A,B,C,D) (A)->lpVtbl->GetComparisonData(A,B,C,D)
#endif 
HRESULT IROTData_GetComparisonData_Proxy(IROTData *,byte *,ULONG,ULONG *);
void IROTData_GetComparisonData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IEnumString_INTERFACE_DEFINED__
#define __IEnumString_INTERFACE_DEFINED__
typedef IEnumString *LPENUMSTRING;
EXTERN_C const IID IID_IEnumString;
typedef struct IEnumStringVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IEnumString *,REFIID,void **);
	ULONG (*AddRef)(IEnumString *);
	ULONG (*Release)(IEnumString *);
	HRESULT(*Next)(IEnumString *,ULONG,LPOLESTR *,ULONG *);
	HRESULT(*Skip)(IEnumString *,ULONG);
	HRESULT(*Reset)(IEnumString *);
	HRESULT(*Clone)(IEnumString *,IEnumString **);
END_INTERFACE
} IEnumStringVtbl;
interface IEnumString
{
CONST_VTBL struct IEnumStringVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumString_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumString_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumString_Release(A) (A)->lpVtbl->Release(A)
#define IEnumString_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumString_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumString_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumString_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IEnumString_RemoteNext_Proxy(IEnumString *,ULONG,LPOLESTR *,ULONG *);
void IEnumString_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumString_Skip_Proxy(IEnumString *,ULONG);
void IEnumString_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumString_Reset_Proxy(IEnumString *);
void IEnumString_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumString_Clone_Proxy(IEnumString *,IEnumString **);
void IEnumString_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ISequentialStream_INTERFACE_DEFINED__
#define __ISequentialStream_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISequentialStream;
typedef struct ISequentialStreamVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ISequentialStream *,REFIID,void **);
	ULONG (*AddRef)(ISequentialStream *);
	ULONG (*Release)(ISequentialStream *);
	HRESULT(*Read)(ISequentialStream *,void *,ULONG,ULONG *);
	HRESULT(*Write)(ISequentialStream *,const void *pv,ULONG,ULONG *);
END_INTERFACE
} ISequentialStreamVtbl;
interface ISequentialStream
{
CONST_VTBL struct ISequentialStreamVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISequentialStream_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISequentialStream_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISequentialStream_Release(A) (A)->lpVtbl->Release(A)
#define ISequentialStream_Read(A,B,C,D) (A)->lpVtbl->Read(A,B,C,D)
#define ISequentialStream_Write(A,B,C,D) (A)->lpVtbl->Write(A,B,C,D)
#endif 
HRESULT ISequentialStream_RemoteRead_Proxy(ISequentialStream *,byte *,ULONG,ULONG *);
void ISequentialStream_RemoteRead_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISequentialStream_RemoteWrite_Proxy(ISequentialStream *,const byte *pv,ULONG,ULONG *);
void ISequentialStream_RemoteWrite_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IStream_INTERFACE_DEFINED__
#define __IStream_INTERFACE_DEFINED__
typedef IStream *LPSTREAM;
#ifdef _MAC
typedef struct tagSTATSTG
{ 
LPOLESTR pwcsName;
FSSpec *pspec;
DWORD type;
ULARGE_INTEGER cbSize;
FILETIME mtime;
FILETIME ctime;
FILETIME atime;
DWORD grfMode;
DWORD grfLocksSupported;
CLSID clsid;
DWORD grfStateBits;
DWORD reserved;
} STATSTG;
#else 
typedef struct tagSTATSTG
{
LPOLESTR pwcsName;
DWORD type;
ULARGE_INTEGER cbSize;
FILETIME mtime;
FILETIME ctime;
FILETIME atime;
DWORD grfMode;
DWORD grfLocksSupported;
CLSID clsid;
DWORD grfStateBits;
DWORD reserved;
} STATSTG;
#endif 
typedef 
enum tagSTGTY
{	STGTY_STORAGE=1,STGTY_STREAM=2,STGTY_LOCKBYTES=3,STGTY_PROPERTY=4
} STGTY;
typedef 
enum tagSTREAM_SEEK
{	STREAM_SEEK_SET=0,STREAM_SEEK_CUR=1,STREAM_SEEK_END=2
} STREAM_SEEK;
typedef 
enum tagLOCKTYPE
{	LOCK_WRITE=1,LOCK_EXCLUSIVE=2,LOCK_ONLYONCE=4
} LOCKTYPE;
EXTERN_C const IID IID_IStream;
typedef struct IStreamVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IStream *,REFIID,void **);
	ULONG (*AddRef)(IStream *);
	ULONG (*Release)(IStream *);
	HRESULT(*Read)(IStream *,void *,ULONG,ULONG *);
	HRESULT(*Write)(IStream *,const void *pv,ULONG,ULONG *);
	HRESULT(*Seek)(IStream *,LARGE_INTEGER,DWORD,ULARGE_INTEGER *);
	HRESULT(*SetSize)(IStream *,ULARGE_INTEGER);
	HRESULT(*CopyTo)(IStream *,IStream *,ULARGE_INTEGER,ULARGE_INTEGER *,ULARGE_INTEGER *);
	HRESULT(*Commit)(IStream *,DWORD);
	HRESULT(*Revert)(IStream *);
	HRESULT(*LockRegion)(IStream *,ULARGE_INTEGER,ULARGE_INTEGER,DWORD);
	HRESULT(*UnlockRegion)(IStream *,ULARGE_INTEGER,ULARGE_INTEGER,DWORD);
	HRESULT(*Stat)(IStream *,STATSTG *,DWORD);
	HRESULT(*Clone)(IStream *,IStream **);
END_INTERFACE
} IStreamVtbl;
interface IStream
{
CONST_VTBL struct IStreamVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IStream_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IStream_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IStream_Release(A) (A)->lpVtbl->Release(A)
#define IStream_Read(A,B,C,D) (A)->lpVtbl->Read(A,B,C,D)
#define IStream_Write(A,B,C,D) (A)->lpVtbl->Write(A,B,C,D)
#define IStream_Seek(A,B,C,D) (A)->lpVtbl->Seek(A,B,C,D)
#define IStream_SetSize(A,B) (A)->lpVtbl->SetSize(A,B)
#define IStream_CopyTo(A,B,C,D,E) (A)->lpVtbl->CopyTo(A,B,C,D,E)
#define IStream_Commit(A,B) (A)->lpVtbl->Commit(A,B)
#define IStream_Revert(A) (A)->lpVtbl->Revert(A)
#define IStream_LockRegion(A,B,C,D) (A)->lpVtbl->LockRegion(A,B,C,D)
#define IStream_UnlockRegion(A,B,C,D) (A)->lpVtbl->UnlockRegion(A,B,C,D)
#define IStream_Stat(A,B,C) (A)->lpVtbl->Stat(A,B,C)
#define IStream_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IStream_RemoteSeek_Proxy(IStream *,LARGE_INTEGER,DWORD,ULARGE_INTEGER *);
void IStream_RemoteSeek_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStream_SetSize_Proxy(IStream *,ULARGE_INTEGER);
void IStream_SetSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStream_RemoteCopyTo_Proxy(IStream *,IStream *,ULARGE_INTEGER,ULARGE_INTEGER *,ULARGE_INTEGER *);
void IStream_RemoteCopyTo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStream_Commit_Proxy(IStream *,DWORD);
void IStream_Commit_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStream_Revert_Proxy(IStream *);
void IStream_Revert_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStream_LockRegion_Proxy(IStream *,ULARGE_INTEGER,ULARGE_INTEGER,DWORD);
void IStream_LockRegion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStream_UnlockRegion_Proxy(IStream *,ULARGE_INTEGER,ULARGE_INTEGER,DWORD);
void IStream_UnlockRegion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStream_Stat_Proxy(IStream *,STATSTG *,DWORD);
void IStream_Stat_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStream_Clone_Proxy(IStream *,IStream **);
void IStream_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IEnumSTATSTG_INTERFACE_DEFINED__
#define __IEnumSTATSTG_INTERFACE_DEFINED__
typedef IEnumSTATSTG *LPENUMSTATSTG;
EXTERN_C const IID IID_IEnumSTATSTG;
typedef struct IEnumSTATSTGVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IEnumSTATSTG *,REFIID,void **);
	ULONG (*AddRef)(IEnumSTATSTG *);
	ULONG (*Release)(IEnumSTATSTG *);
	HRESULT(*Next)(IEnumSTATSTG *,ULONG,STATSTG *,ULONG *);
	HRESULT(*Skip)(IEnumSTATSTG *,ULONG);
	HRESULT(*Reset)(IEnumSTATSTG *);
	HRESULT(*Clone)(IEnumSTATSTG *,IEnumSTATSTG **);
END_INTERFACE
} IEnumSTATSTGVtbl;
interface IEnumSTATSTG
{
CONST_VTBL struct IEnumSTATSTGVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumSTATSTG_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumSTATSTG_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumSTATSTG_Release(A) (A)->lpVtbl->Release(A)
#define IEnumSTATSTG_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumSTATSTG_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumSTATSTG_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumSTATSTG_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IEnumSTATSTG_RemoteNext_Proxy(IEnumSTATSTG *,ULONG,STATSTG *,ULONG *);
void IEnumSTATSTG_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumSTATSTG_Skip_Proxy(IEnumSTATSTG *,ULONG);
void IEnumSTATSTG_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumSTATSTG_Reset_Proxy(IEnumSTATSTG *);
void IEnumSTATSTG_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumSTATSTG_Clone_Proxy(IEnumSTATSTG *,IEnumSTATSTG **);
void IEnumSTATSTG_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IStorage_INTERFACE_DEFINED__
#define __IStorage_INTERFACE_DEFINED__
typedef IStorage *LPSTORAGE;
typedef struct tagRemSNB
{
unsigned long ulCntStr;
unsigned long ulCntChar;
OLECHAR rgString[ 1 ];
} RemSNB;
typedef RemSNB *wireSNB;
typedef OLECHAR **SNB;
EXTERN_C const IID IID_IStorage;
typedef struct IStorageVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IStorage *,REFIID,void **);
	ULONG (*AddRef)(IStorage *);
	ULONG (*Release)(IStorage *);
	HRESULT(*CreateStream)(IStorage *,const OLECHAR *pwcsName,DWORD,DWORD,DWORD,IStream **);
	HRESULT(*OpenStream)(IStorage *,const OLECHAR *pwcsName,void *,DWORD,DWORD,IStream **);
	HRESULT(*CreateStorage)(IStorage *,const OLECHAR *pwcsName,DWORD,DWORD,DWORD,IStorage **);
	HRESULT(*OpenStorage)(IStorage *,const OLECHAR *pwcsName,IStorage *,DWORD,SNB,DWORD,IStorage **);
	HRESULT(*CopyTo)(IStorage *,DWORD,const IID *rgiidExclude,SNB,IStorage *);
	HRESULT(*MoveElementTo)(IStorage *,const OLECHAR *pwcsName,IStorage *,const OLECHAR *pwcsNewName,DWORD);
	HRESULT(*Commit)(IStorage *,DWORD);
	HRESULT(*Revert)(IStorage *);
	HRESULT(*EnumElements)(IStorage *,DWORD,void *,DWORD,IEnumSTATSTG **);
	HRESULT(*DestroyElement)(IStorage *,const OLECHAR *pwcsName);
	HRESULT(*RenameElement)(IStorage *,const OLECHAR *pwcsOldName,const OLECHAR *pwcsNewName);
	HRESULT(*SetElementTimes)(IStorage *,const OLECHAR *pwcsName,const FILETIME *pctime,const FILETIME *patime,const FILETIME *pmtime);
	HRESULT(*SetClass)(IStorage *,REFCLSID);
	HRESULT(*SetStateBits)(IStorage *,DWORD,DWORD);
	HRESULT(*Stat)(IStorage *,STATSTG *,DWORD);
END_INTERFACE
} IStorageVtbl;
interface IStorage
{
CONST_VTBL struct IStorageVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IStorage_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IStorage_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IStorage_Release(A) (A)->lpVtbl->Release(A)
#define IStorage_CreateStream(A,B,C,D,E,F) (A)->lpVtbl->CreateStream(A,B,C,D,E,F)
#define IStorage_OpenStream(A,B,C,D,E,F) (A)->lpVtbl->OpenStream(A,B,C,D,E,F)
#define IStorage_CreateStorage(A,B,C,D,E,F) (A)->lpVtbl->CreateStorage(A,B,C,D,E,F)
#define IStorage_OpenStorage(A,B,C,D,E,F,G) (A)->lpVtbl->OpenStorage(A,B,C,D,E,F,G)
#define IStorage_CopyTo(A,B,C,D,E) (A)->lpVtbl->CopyTo(A,B,C,D,E)
#define IStorage_MoveElementTo(A,B,C,D,E) (A)->lpVtbl->MoveElementTo(A,B,C,D,E)
#define IStorage_Commit(A,B) (A)->lpVtbl->Commit(A,B)
#define IStorage_Revert(A) (A)->lpVtbl->Revert(A)
#define IStorage_EnumElements(A,B,C,D,E) (A)->lpVtbl->EnumElements(A,B,C,D,E)
#define IStorage_DestroyElement(A,B) (A)->lpVtbl->DestroyElement(A,B)
#define IStorage_RenameElement(A,B,C) (A)->lpVtbl->RenameElement(A,B,C)
#define IStorage_SetElementTimes(A,B,C,D,E) (A)->lpVtbl->SetElementTimes(A,B,C,D,E)
#define IStorage_SetClass(A,B) (A)->lpVtbl->SetClass(A,B)
#define IStorage_SetStateBits(A,B,C) (A)->lpVtbl->SetStateBits(A,B,C)
#define IStorage_Stat(A,B,C) (A)->lpVtbl->Stat(A,B,C)
#endif 
HRESULT IStorage_CreateStream_Proxy(IStorage *,const OLECHAR *pwcsName,DWORD,DWORD,DWORD,IStream **);
void IStorage_CreateStream_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_RemoteOpenStream_Proxy(IStorage *,const OLECHAR *pwcsName,unsigned long cbReserved1,byte *,DWORD,DWORD,IStream **);
void IStorage_RemoteOpenStream_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_CreateStorage_Proxy(IStorage *,const OLECHAR *pwcsName,DWORD,DWORD,DWORD,IStorage **);
void IStorage_CreateStorage_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_OpenStorage_Proxy(IStorage *,const OLECHAR *pwcsName,IStorage *,DWORD,SNB,DWORD,IStorage **);
void IStorage_OpenStorage_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_CopyTo_Proxy(IStorage *,DWORD,const IID *rgiidExclude,SNB,IStorage *);
void IStorage_CopyTo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_MoveElementTo_Proxy(IStorage *,const OLECHAR *pwcsName,IStorage *,const OLECHAR *pwcsNewName,DWORD);
void IStorage_MoveElementTo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_Commit_Proxy(IStorage *,DWORD);
void IStorage_Commit_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_Revert_Proxy(IStorage *);
void IStorage_Revert_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_RemoteEnumElements_Proxy(IStorage *,DWORD,unsigned long cbReserved2,byte *,DWORD,IEnumSTATSTG **);
void IStorage_RemoteEnumElements_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_DestroyElement_Proxy(IStorage *,const OLECHAR *pwcsName);
void IStorage_DestroyElement_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_RenameElement_Proxy(IStorage *,const OLECHAR *pwcsOldName,const OLECHAR *pwcsNewName);
void IStorage_RenameElement_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_SetElementTimes_Proxy(IStorage *,const OLECHAR *pwcsName,const FILETIME *pctime,const FILETIME *patime,const FILETIME *pmtime);
void IStorage_SetElementTimes_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_SetClass_Proxy(IStorage *,REFCLSID);
void IStorage_SetClass_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_SetStateBits_Proxy(IStorage *,DWORD,DWORD);
void IStorage_SetStateBits_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IStorage_Stat_Proxy(IStorage *,STATSTG *,DWORD);
void IStorage_Stat_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IPersistFile_INTERFACE_DEFINED__
#define __IPersistFile_INTERFACE_DEFINED__
typedef IPersistFile *LPPERSISTFILE;
EXTERN_C const IID IID_IPersistFile;
typedef struct IPersistFileVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IPersistFile *,REFIID,void **);
	ULONG (*AddRef)(IPersistFile *);
	ULONG (*Release)(IPersistFile *);
	HRESULT(*GetClassID)(IPersistFile *,CLSID *);
	HRESULT(*IsDirty)(IPersistFile *);
	HRESULT(*Load)(IPersistFile *,LPCOLESTR,DWORD);
	HRESULT(*Save)(IPersistFile *,LPCOLESTR,BOOL);
	HRESULT(*SaveCompleted)(IPersistFile *,LPCOLESTR);
	HRESULT(*GetCurFile)(IPersistFile *,LPOLESTR *);
END_INTERFACE
} IPersistFileVtbl;
interface IPersistFile
{
CONST_VTBL struct IPersistFileVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPersistFile_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPersistFile_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPersistFile_Release(A) (A)->lpVtbl->Release(A)
#define IPersistFile_GetClassID(A,B) (A)->lpVtbl->GetClassID(A,B)
#define IPersistFile_IsDirty(A) (A)->lpVtbl->IsDirty(A)
#define IPersistFile_Load(A,B,C) (A)->lpVtbl->Load(A,B,C)
#define IPersistFile_Save(A,B,C) (A)->lpVtbl->Save(A,B,C)
#define IPersistFile_SaveCompleted(A,B) (A)->lpVtbl->SaveCompleted(A,B)
#define IPersistFile_GetCurFile(A,B) (A)->lpVtbl->GetCurFile(A,B)
#endif 
HRESULT IPersistFile_IsDirty_Proxy(IPersistFile *);
void IPersistFile_IsDirty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistFile_Load_Proxy(IPersistFile *,LPCOLESTR,DWORD);
void IPersistFile_Load_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistFile_Save_Proxy(IPersistFile *,LPCOLESTR,BOOL);
void IPersistFile_Save_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistFile_SaveCompleted_Proxy(IPersistFile *,LPCOLESTR);
void IPersistFile_SaveCompleted_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistFile_GetCurFile_Proxy(IPersistFile *,LPOLESTR *);
void IPersistFile_GetCurFile_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IPersistStorage_INTERFACE_DEFINED__
#define __IPersistStorage_INTERFACE_DEFINED__
typedef IPersistStorage *LPPERSISTSTORAGE;
EXTERN_C const IID IID_IPersistStorage;
typedef struct IPersistStorageVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IPersistStorage *,REFIID,void **);
	ULONG (*AddRef)(IPersistStorage *);
	ULONG (*Release)(IPersistStorage *);
	HRESULT(*GetClassID)(IPersistStorage *,CLSID *);
	HRESULT(*IsDirty)(IPersistStorage *);
	HRESULT(*InitNew)(IPersistStorage *,IStorage *);
	HRESULT(*Load)(IPersistStorage *,IStorage *);
	HRESULT(*Save)(IPersistStorage *,IStorage *,BOOL);
	HRESULT(*SaveCompleted)(IPersistStorage *,IStorage *);
	HRESULT(*HandsOffStorage)(IPersistStorage *);
END_INTERFACE
} IPersistStorageVtbl;
interface IPersistStorage
{
CONST_VTBL struct IPersistStorageVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPersistStorage_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPersistStorage_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPersistStorage_Release(A) (A)->lpVtbl->Release(A)
#define IPersistStorage_GetClassID(A,B) (A)->lpVtbl->GetClassID(A,B)
#define IPersistStorage_IsDirty(A) (A)->lpVtbl->IsDirty(A)
#define IPersistStorage_InitNew(A,B) (A)->lpVtbl->InitNew(A,B)
#define IPersistStorage_Load(A,B) (A)->lpVtbl->Load(A,B)
#define IPersistStorage_Save(A,B,C) (A)->lpVtbl->Save(A,B,C)
#define IPersistStorage_SaveCompleted(A,B) (A)->lpVtbl->SaveCompleted(A,B)
#define IPersistStorage_HandsOffStorage(A) (A)->lpVtbl->HandsOffStorage(A)
#endif 
HRESULT IPersistStorage_IsDirty_Proxy(IPersistStorage *);
void IPersistStorage_IsDirty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistStorage_InitNew_Proxy(IPersistStorage *,IStorage *);
void IPersistStorage_InitNew_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistStorage_Load_Proxy(IPersistStorage *,IStorage *);
void IPersistStorage_Load_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistStorage_Save_Proxy(IPersistStorage *,IStorage *,BOOL);
void IPersistStorage_Save_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistStorage_SaveCompleted_Proxy(IPersistStorage *,IStorage *);
void IPersistStorage_SaveCompleted_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPersistStorage_HandsOffStorage_Proxy(IPersistStorage *);
void IPersistStorage_HandsOffStorage_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ILockBytes_INTERFACE_DEFINED__
#define __ILockBytes_INTERFACE_DEFINED__
typedef ILockBytes *LPLOCKBYTES;
EXTERN_C const IID IID_ILockBytes;
typedef struct ILockBytesVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ILockBytes *,REFIID,void **);
	ULONG (*AddRef)(ILockBytes *);
	ULONG (*Release)(ILockBytes *);
	HRESULT(*ReadAt)(ILockBytes *,ULARGE_INTEGER,void *,ULONG,ULONG *);
	HRESULT(*WriteAt)(ILockBytes *,ULARGE_INTEGER,const void *pv,ULONG,ULONG *);
	HRESULT(*Flush)(ILockBytes *);
	HRESULT(*SetSize)(ILockBytes *,ULARGE_INTEGER);
	HRESULT(*LockRegion)(ILockBytes *,ULARGE_INTEGER,ULARGE_INTEGER,DWORD);
	HRESULT(*UnlockRegion)(ILockBytes *,ULARGE_INTEGER,ULARGE_INTEGER,DWORD);
	HRESULT(*Stat)(ILockBytes *,STATSTG *,DWORD);
END_INTERFACE
} ILockBytesVtbl;
interface ILockBytes
{
CONST_VTBL struct ILockBytesVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ILockBytes_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ILockBytes_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ILockBytes_Release(A) (A)->lpVtbl->Release(A)
#define ILockBytes_ReadAt(A,B,C,D,E) (A)->lpVtbl->ReadAt(A,B,C,D,E)
#define ILockBytes_WriteAt(A,B,C,D,E) (A)->lpVtbl->WriteAt(A,B,C,D,E)
#define ILockBytes_Flush(A) (A)->lpVtbl->Flush(A)
#define ILockBytes_SetSize(A,B) (A)->lpVtbl->SetSize(A,B)
#define ILockBytes_LockRegion(A,B,C,D) (A)->lpVtbl->LockRegion(A,B,C,D)
#define ILockBytes_UnlockRegion(A,B,C,D) (A)->lpVtbl->UnlockRegion(A,B,C,D)
#define ILockBytes_Stat(A,B,C) (A)->lpVtbl->Stat(A,B,C)
#endif 
HRESULT ILockBytes_RemoteReadAt_Proxy(ILockBytes *,ULARGE_INTEGER,byte *,ULONG,ULONG *);
void ILockBytes_RemoteReadAt_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILockBytes_RemoteWriteAt_Proxy(ILockBytes *,ULARGE_INTEGER,const byte *pv,ULONG,ULONG *);
void ILockBytes_RemoteWriteAt_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILockBytes_Flush_Proxy(ILockBytes *);
void ILockBytes_Flush_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILockBytes_SetSize_Proxy(ILockBytes *,ULARGE_INTEGER);
void ILockBytes_SetSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILockBytes_LockRegion_Proxy(ILockBytes *,ULARGE_INTEGER,ULARGE_INTEGER,DWORD);
void ILockBytes_LockRegion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILockBytes_UnlockRegion_Proxy(ILockBytes *,ULARGE_INTEGER,ULARGE_INTEGER,DWORD);
void ILockBytes_UnlockRegion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILockBytes_Stat_Proxy(ILockBytes *,STATSTG *,DWORD);
void ILockBytes_Stat_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IEnumFORMATETC_INTERFACE_DEFINED__
#define __IEnumFORMATETC_INTERFACE_DEFINED__
typedef IEnumFORMATETC *LPENUMFORMATETC;
typedef struct tagDVTARGETDEVICE
{
DWORD tdSize;
WORD tdDriverNameOffset;
WORD tdDeviceNameOffset;
WORD tdPortNameOffset;
WORD tdExtDevmodeOffset;
BYTE tdData[ 1 ];
} DVTARGETDEVICE;
typedef CLIPFORMAT *LPCLIPFORMAT;
typedef struct tagFORMATETC
{
CLIPFORMAT cfFormat;
DVTARGETDEVICE *ptd;
DWORD dwAspect;
LONG lindex;
DWORD tymed;
} FORMATETC;
typedef struct tagFORMATETC *LPFORMATETC;
EXTERN_C const IID IID_IEnumFORMATETC;
typedef struct IEnumFORMATETCVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IEnumFORMATETC *,REFIID,void **);
	ULONG (*AddRef)(IEnumFORMATETC *);
	ULONG (*Release)(IEnumFORMATETC *);
	HRESULT(*Next)(IEnumFORMATETC *,ULONG,FORMATETC *,ULONG *);
	HRESULT(*Skip)(IEnumFORMATETC *,ULONG);
	HRESULT(*Reset)(IEnumFORMATETC *);
	HRESULT(*Clone)(IEnumFORMATETC *,IEnumFORMATETC **);
END_INTERFACE
} IEnumFORMATETCVtbl;
interface IEnumFORMATETC
{
CONST_VTBL struct IEnumFORMATETCVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumFORMATETC_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumFORMATETC_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumFORMATETC_Release(A) (A)->lpVtbl->Release(A)
#define IEnumFORMATETC_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumFORMATETC_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumFORMATETC_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumFORMATETC_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IEnumFORMATETC_RemoteNext_Proxy(IEnumFORMATETC *,ULONG,FORMATETC *,ULONG *);
void IEnumFORMATETC_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumFORMATETC_Skip_Proxy(IEnumFORMATETC *,ULONG);
void IEnumFORMATETC_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumFORMATETC_Reset_Proxy(IEnumFORMATETC *);
void IEnumFORMATETC_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumFORMATETC_Clone_Proxy(IEnumFORMATETC *,IEnumFORMATETC **);
void IEnumFORMATETC_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IEnumSTATDATA_INTERFACE_DEFINED__
#define __IEnumSTATDATA_INTERFACE_DEFINED__
typedef IEnumSTATDATA *LPENUMSTATDATA;
typedef 
enum tagADVF
{	ADVF_NODATA=1,ADVF_PRIMEFIRST=2,ADVF_ONLYONCE=4,ADVF_DATAONSTOP=64,ADVFCACHE_NOHANDLER=8,ADVFCACHE_FORCEBUILTIN=16,ADVFCACHE_ONSAVE=32
} ADVF;
typedef struct tagSTATDATA
{
FORMATETC formatetc;
DWORD advf;
IAdviseSink *pAdvSink;
DWORD dwConnection;
} STATDATA;
typedef STATDATA *LPSTATDATA;
EXTERN_C const IID IID_IEnumSTATDATA;
typedef struct IEnumSTATDATAVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IEnumSTATDATA *,REFIID,void **);
	ULONG (*AddRef)(IEnumSTATDATA *);
	ULONG (*Release)(IEnumSTATDATA *);
	HRESULT(*Next)(IEnumSTATDATA *,ULONG,STATDATA *,ULONG *);
	HRESULT(*Skip)(IEnumSTATDATA *,ULONG);
	HRESULT(*Reset)(IEnumSTATDATA *);
	HRESULT(*Clone)(IEnumSTATDATA *,IEnumSTATDATA **);
END_INTERFACE
} IEnumSTATDATAVtbl;
interface IEnumSTATDATA
{
CONST_VTBL struct IEnumSTATDATAVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumSTATDATA_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumSTATDATA_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumSTATDATA_Release(A) (A)->lpVtbl->Release(A)
#define IEnumSTATDATA_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumSTATDATA_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumSTATDATA_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumSTATDATA_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IEnumSTATDATA_RemoteNext_Proxy(IEnumSTATDATA *,ULONG,STATDATA *,ULONG *);
void IEnumSTATDATA_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumSTATDATA_Skip_Proxy(IEnumSTATDATA *,ULONG);
void IEnumSTATDATA_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumSTATDATA_Reset_Proxy(IEnumSTATDATA *);
void IEnumSTATDATA_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumSTATDATA_Clone_Proxy(IEnumSTATDATA *,IEnumSTATDATA **);
void IEnumSTATDATA_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRootStorage_INTERFACE_DEFINED__
#define __IRootStorage_INTERFACE_DEFINED__
typedef IRootStorage *LPROOTSTORAGE;
EXTERN_C const IID IID_IRootStorage;
typedef struct IRootStorageVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRootStorage *,REFIID,void **);
	ULONG (*AddRef)(IRootStorage *);
	ULONG (*Release)(IRootStorage *);
	HRESULT(*SwitchToFile)(IRootStorage *,LPOLESTR);
END_INTERFACE
} IRootStorageVtbl;
interface IRootStorage
{
CONST_VTBL struct IRootStorageVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRootStorage_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRootStorage_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRootStorage_Release(A) (A)->lpVtbl->Release(A)
#define IRootStorage_SwitchToFile(A,B) (A)->lpVtbl->SwitchToFile(A,B)
#endif 
HRESULT IRootStorage_SwitchToFile_Proxy(IRootStorage *,LPOLESTR);
void IRootStorage_SwitchToFile_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IAdviseSink_INTERFACE_DEFINED__
#define __IAdviseSink_INTERFACE_DEFINED__
typedef IAdviseSink *LPADVISESINK;
typedef 
enum tagTYMED
{	TYMED_HGLOBAL=1,TYMED_FILE=2,TYMED_ISTREAM=4,TYMED_ISTORAGE=8,TYMED_GDI=16,TYMED_MFPICT=32,TYMED_ENHMF=64,TYMED_NULL=0
} TYMED;
#ifndef RC_INVOKED
#if _MSC_VER >= 1200
#endif
#endif
typedef struct tagRemSTGMEDIUM
{
DWORD tymed;
DWORD dwHandleType;
unsigned long pData;
unsigned long pUnkForRelease;
unsigned long cbData;
byte data[ 1 ];
} RemSTGMEDIUM;
#ifndef RC_INVOKED
#if _MSC_VER >= 1200
#else
#endif
#endif
#ifdef NONAMELESSUNION
typedef struct tagSTGMEDIUM {
DWORD tymed;
union {
HBITMAP hBitmap;
HMETAFILEPICT hMetaFilePict;
HENHMETAFILE hEnhMetaFile;
HGLOBAL hGlobal;
LPOLESTR lpszFileName;
IStream *pstm;
IStorage *pstg;
} u;
IUnknown *pUnkForRelease;
}uSTGMEDIUM;
#else
typedef struct tagSTGMEDIUM
{
DWORD tymed;
union 
{
HBITMAP hBitmap;
HMETAFILEPICT hMetaFilePict;
HENHMETAFILE hEnhMetaFile;
HGLOBAL hGlobal;
LPOLESTR lpszFileName;
IStream *pstm;
IStorage *pstg;
} ;
IUnknown *pUnkForRelease;
} uSTGMEDIUM;
#endif 
typedef struct _GDI_OBJECT
{
DWORD ObjectType;
union __MIDL_IAdviseSink_0002
{
wireHBITMAP hBitmap;
wireHPALETTE hPalette;
wireHGLOBAL hGeneric;
} u;
} GDI_OBJECT;
typedef struct _userSTGMEDIUM
{
struct _STGMEDIUM_UNION
{
DWORD tymed;
union __MIDL_IAdviseSink_0003
{
wireHMETAFILEPICT hMetaFilePict;
wireHENHMETAFILE hHEnhMetaFile;
GDI_OBJECT *hGdiHandle;
wireHGLOBAL hGlobal;
LPOLESTR lpszFileName;
BYTE_BLOB *pstm;
BYTE_BLOB *pstg;
} u;
} ;
IUnknown *pUnkForRelease;
} userSTGMEDIUM;
typedef userSTGMEDIUM *wireSTGMEDIUM;
typedef uSTGMEDIUM STGMEDIUM;
typedef userSTGMEDIUM *wireASYNC_STGMEDIUM;
typedef STGMEDIUM ASYNC_STGMEDIUM;
typedef STGMEDIUM *LPSTGMEDIUM;
typedef struct _userFLAG_STGMEDIUM
{
long ContextFlags;
long fPassOwnership;
userSTGMEDIUM Stgmed;
} userFLAG_STGMEDIUM;
typedef userFLAG_STGMEDIUM *wireFLAG_STGMEDIUM;
typedef struct _FLAG_STGMEDIUM
{
long ContextFlags;
long fPassOwnership;
STGMEDIUM Stgmed;
} FLAG_STGMEDIUM;
EXTERN_C const IID IID_IAdviseSink;
typedef struct IAdviseSinkVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IAdviseSink *,REFIID,void **);
	ULONG (*AddRef)(IAdviseSink *);
	ULONG (*Release)(IAdviseSink *);
	void (*OnDataChange)(IAdviseSink *,FORMATETC *,STGMEDIUM *);
	void (*OnViewChange)(IAdviseSink *,DWORD,LONG);
	void (*OnRename)(IAdviseSink *,IMoniker *);
	void (*OnSave)(IAdviseSink *);
	void (*OnClose)(IAdviseSink *);
END_INTERFACE
} IAdviseSinkVtbl;
interface IAdviseSink
{
CONST_VTBL struct IAdviseSinkVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IAdviseSink_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IAdviseSink_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IAdviseSink_Release(A) (A)->lpVtbl->Release(A)
#define IAdviseSink_OnDataChange(A,B,C) (A)->lpVtbl->OnDataChange(A,B,C)
#define IAdviseSink_OnViewChange(A,B,C) (A)->lpVtbl->OnViewChange(A,B,C)
#define IAdviseSink_OnRename(A,B) (A)->lpVtbl->OnRename(A,B)
#define IAdviseSink_OnSave(A) (A)->lpVtbl->OnSave(A)
#define IAdviseSink_OnClose(A) (A)->lpVtbl->OnClose(A)
#endif 
HRESULT IAdviseSink_RemoteOnDataChange_Proxy(IAdviseSink *,FORMATETC *,ASYNC_STGMEDIUM *);
void IAdviseSink_RemoteOnDataChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAdviseSink_RemoteOnViewChange_Proxy(IAdviseSink *,DWORD,LONG);
void IAdviseSink_RemoteOnViewChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAdviseSink_RemoteOnRename_Proxy(IAdviseSink *,IMoniker *);
void IAdviseSink_RemoteOnRename_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAdviseSink_RemoteOnSave_Proxy(IAdviseSink *);
void IAdviseSink_RemoteOnSave_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAdviseSink_RemoteOnClose_Proxy(IAdviseSink *);
void IAdviseSink_RemoteOnClose_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __AsyncIAdviseSink_INTERFACE_DEFINED__
#define __AsyncIAdviseSink_INTERFACE_DEFINED__
EXTERN_C const IID IID_AsyncIAdviseSink;
typedef struct AsyncIAdviseSinkVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(AsyncIAdviseSink *,REFIID,void **);
	ULONG (*AddRef)(AsyncIAdviseSink *);
	ULONG (*Release)(AsyncIAdviseSink *);
	void (*Begin_OnDataChange)(AsyncIAdviseSink *,FORMATETC *,STGMEDIUM *);
	void (*Finish_OnDataChange)(AsyncIAdviseSink *);
	void (*Begin_OnViewChange)(AsyncIAdviseSink *,DWORD,LONG);
	void (*Finish_OnViewChange)(AsyncIAdviseSink *);
	void (*Begin_OnRename)(AsyncIAdviseSink *,IMoniker *);
	void (*Finish_OnRename)(AsyncIAdviseSink *);
	void (*Begin_OnSave)(AsyncIAdviseSink *);
	void (*Finish_OnSave)(AsyncIAdviseSink *);
	void (*Begin_OnClose)(AsyncIAdviseSink *);
	void (*Finish_OnClose)(AsyncIAdviseSink *);
END_INTERFACE
} AsyncIAdviseSinkVtbl;
interface AsyncIAdviseSink
{
CONST_VTBL struct AsyncIAdviseSinkVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define AsyncIAdviseSink_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define AsyncIAdviseSink_AddRef(A) (A)->lpVtbl->AddRef(A)
#define AsyncIAdviseSink_Release(A) (A)->lpVtbl->Release(A)
#define AsyncIAdviseSink_Begin_OnDataChange(A,B,C) (A)->lpVtbl->Begin_OnDataChange(A,B,C)
#define AsyncIAdviseSink_Finish_OnDataChange(A) (A)->lpVtbl->Finish_OnDataChange(A)
#define AsyncIAdviseSink_Begin_OnViewChange(A,B,C) (A)->lpVtbl->Begin_OnViewChange(A,B,C)
#define AsyncIAdviseSink_Finish_OnViewChange(A) (A)->lpVtbl->Finish_OnViewChange(A)
#define AsyncIAdviseSink_Begin_OnRename(A,B) (A)->lpVtbl->Begin_OnRename(A,B)
#define AsyncIAdviseSink_Finish_OnRename(A) (A)->lpVtbl->Finish_OnRename(A)
#define AsyncIAdviseSink_Begin_OnSave(A) (A)->lpVtbl->Begin_OnSave(A)
#define AsyncIAdviseSink_Finish_OnSave(A) (A)->lpVtbl->Finish_OnSave(A)
#define AsyncIAdviseSink_Begin_OnClose(A) (A)->lpVtbl->Begin_OnClose(A)
#define AsyncIAdviseSink_Finish_OnClose(A) (A)->lpVtbl->Finish_OnClose(A)
#endif 
HRESULT AsyncIAdviseSink_Begin_RemoteOnDataChange_Proxy(AsyncIAdviseSink *,FORMATETC *,ASYNC_STGMEDIUM *);
void AsyncIAdviseSink_Begin_RemoteOnDataChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Finish_RemoteOnDataChange_Proxy(AsyncIAdviseSink *);
void AsyncIAdviseSink_Finish_RemoteOnDataChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Begin_RemoteOnViewChange_Proxy(AsyncIAdviseSink *,DWORD,LONG);
void AsyncIAdviseSink_Begin_RemoteOnViewChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Finish_RemoteOnViewChange_Proxy(AsyncIAdviseSink *);
void AsyncIAdviseSink_Finish_RemoteOnViewChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Begin_RemoteOnRename_Proxy(AsyncIAdviseSink *,IMoniker *);
void AsyncIAdviseSink_Begin_RemoteOnRename_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Finish_RemoteOnRename_Proxy(AsyncIAdviseSink *);
void AsyncIAdviseSink_Finish_RemoteOnRename_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Begin_RemoteOnSave_Proxy(AsyncIAdviseSink *);
void AsyncIAdviseSink_Begin_RemoteOnSave_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Finish_RemoteOnSave_Proxy(AsyncIAdviseSink *);
void AsyncIAdviseSink_Finish_RemoteOnSave_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Begin_RemoteOnClose_Proxy(AsyncIAdviseSink *);
void AsyncIAdviseSink_Begin_RemoteOnClose_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink_Finish_RemoteOnClose_Proxy(AsyncIAdviseSink *);
void AsyncIAdviseSink_Finish_RemoteOnClose_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IAdviseSink2_INTERFACE_DEFINED__
#define __IAdviseSink2_INTERFACE_DEFINED__
typedef IAdviseSink2 *LPADVISESINK2;
EXTERN_C const IID IID_IAdviseSink2;
typedef struct IAdviseSink2Vtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IAdviseSink2 *,REFIID,void **);
	ULONG (*AddRef)(IAdviseSink2 *);
	ULONG (*Release)(IAdviseSink2 *);
	void (*OnDataChange)(IAdviseSink2 *,FORMATETC *,STGMEDIUM *);
	void (*OnViewChange)(IAdviseSink2 *,DWORD,LONG);
	void (*OnRename)(IAdviseSink2 *,IMoniker *);
	void (*OnSave)(IAdviseSink2 *);
	void (*OnClose)(IAdviseSink2 *);
	void (*OnLinkSrcChange)(IAdviseSink2 *,IMoniker *);
END_INTERFACE
} IAdviseSink2Vtbl;
interface IAdviseSink2
{
CONST_VTBL struct IAdviseSink2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IAdviseSink2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IAdviseSink2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IAdviseSink2_Release(A) (A)->lpVtbl->Release(A)
#define IAdviseSink2_OnDataChange(A,B,C) (A)->lpVtbl->OnDataChange(A,B,C)
#define IAdviseSink2_OnViewChange(A,B,C) (A)->lpVtbl->OnViewChange(A,B,C)
#define IAdviseSink2_OnRename(A,B) (A)->lpVtbl->OnRename(A,B)
#define IAdviseSink2_OnSave(A) (A)->lpVtbl->OnSave(A)
#define IAdviseSink2_OnClose(A) (A)->lpVtbl->OnClose(A)
#define IAdviseSink2_OnLinkSrcChange(A,B) (A)->lpVtbl->OnLinkSrcChange(A,B)
#endif 
HRESULT IAdviseSink2_RemoteOnLinkSrcChange_Proxy(IAdviseSink2 *,IMoniker *);
void IAdviseSink2_RemoteOnLinkSrcChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __AsyncIAdviseSink2_INTERFACE_DEFINED__
#define __AsyncIAdviseSink2_INTERFACE_DEFINED__
EXTERN_C const IID IID_AsyncIAdviseSink2;
typedef struct AsyncIAdviseSink2Vtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(AsyncIAdviseSink2 *,REFIID,void **);
	ULONG (*AddRef)(AsyncIAdviseSink2 *);
	ULONG (*Release)(AsyncIAdviseSink2 *);
	void (*Begin_OnDataChange)(AsyncIAdviseSink2 *,FORMATETC *,STGMEDIUM *);
	void (*Finish_OnDataChange)(AsyncIAdviseSink2 *);
	void (*Begin_OnViewChange)(AsyncIAdviseSink2 *,DWORD,LONG);
	void (*Finish_OnViewChange)(AsyncIAdviseSink2 *);
	void (*Begin_OnRename)(AsyncIAdviseSink2 *,IMoniker *);
	void (*Finish_OnRename)(AsyncIAdviseSink2 *);
	void (*Begin_OnSave)(AsyncIAdviseSink2 *);
	void (*Finish_OnSave)(AsyncIAdviseSink2 *);
	void (*Begin_OnClose)(AsyncIAdviseSink2 *);
	void (*Finish_OnClose)(AsyncIAdviseSink2 *);
	void (*Begin_OnLinkSrcChange)(AsyncIAdviseSink2 *,IMoniker *);
	void (*Finish_OnLinkSrcChange)(AsyncIAdviseSink2 *);
END_INTERFACE
} AsyncIAdviseSink2Vtbl;
interface AsyncIAdviseSink2
{
CONST_VTBL struct AsyncIAdviseSink2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define AsyncIAdviseSink2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define AsyncIAdviseSink2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define AsyncIAdviseSink2_Release(A) (A)->lpVtbl->Release(A)
#define AsyncIAdviseSink2_Begin_OnDataChange(A,B,C) (A)->lpVtbl->Begin_OnDataChange(A,B,C)
#define AsyncIAdviseSink2_Finish_OnDataChange(A) (A)->lpVtbl->Finish_OnDataChange(A)
#define AsyncIAdviseSink2_Begin_OnViewChange(A,B,C) (A)->lpVtbl->Begin_OnViewChange(A,B,C)
#define AsyncIAdviseSink2_Finish_OnViewChange(A) (A)->lpVtbl->Finish_OnViewChange(A)
#define AsyncIAdviseSink2_Begin_OnRename(A,B) (A)->lpVtbl->Begin_OnRename(A,B)
#define AsyncIAdviseSink2_Finish_OnRename(A) (A)->lpVtbl->Finish_OnRename(A)
#define AsyncIAdviseSink2_Begin_OnSave(A) (A)->lpVtbl->Begin_OnSave(A)
#define AsyncIAdviseSink2_Finish_OnSave(A) (A)->lpVtbl->Finish_OnSave(A)
#define AsyncIAdviseSink2_Begin_OnClose(A) (A)->lpVtbl->Begin_OnClose(A)
#define AsyncIAdviseSink2_Finish_OnClose(A) (A)->lpVtbl->Finish_OnClose(A)
#define AsyncIAdviseSink2_Begin_OnLinkSrcChange(A,B) (A)->lpVtbl->Begin_OnLinkSrcChange(A,B)
#define AsyncIAdviseSink2_Finish_OnLinkSrcChange(A) (A)->lpVtbl->Finish_OnLinkSrcChange(A)
#endif 
HRESULT AsyncIAdviseSink2_Begin_RemoteOnLinkSrcChange_Proxy(AsyncIAdviseSink2 *,IMoniker *);
void AsyncIAdviseSink2_Begin_RemoteOnLinkSrcChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIAdviseSink2_Finish_RemoteOnLinkSrcChange_Proxy(AsyncIAdviseSink2 *);
void AsyncIAdviseSink2_Finish_RemoteOnLinkSrcChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IDataObject_INTERFACE_DEFINED__
#define __IDataObject_INTERFACE_DEFINED__
typedef IDataObject *LPDATAOBJECT;
typedef 
enum tagDATADIR
{	DATADIR_GET=1,DATADIR_SET=2
} DATADIR;
EXTERN_C const IID IID_IDataObject;
typedef struct IDataObjectVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IDataObject *,REFIID,void **);
	ULONG (*AddRef)(IDataObject *);
	ULONG (*Release)(IDataObject *);
	HRESULT(*GetData)(IDataObject *,FORMATETC *,STGMEDIUM *);
	HRESULT(*GetDataHere)(IDataObject *,FORMATETC *,STGMEDIUM *);
	HRESULT(*QueryGetData)(IDataObject *,FORMATETC *);
	HRESULT(*GetCanonicalFormatEtc)(IDataObject *,FORMATETC *,FORMATETC *);
	HRESULT(*SetData)(IDataObject *,FORMATETC *,STGMEDIUM *,BOOL);
	HRESULT(*EnumFormatEtc)(IDataObject *,DWORD,IEnumFORMATETC **);
	HRESULT(*DAdvise)(IDataObject *,FORMATETC *,DWORD,IAdviseSink *,DWORD *);
	HRESULT(*DUnadvise)(IDataObject *,DWORD);
	HRESULT(*EnumDAdvise)(IDataObject *,IEnumSTATDATA **);
END_INTERFACE
} IDataObjectVtbl;
interface IDataObject
{
CONST_VTBL struct IDataObjectVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IDataObject_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IDataObject_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IDataObject_Release(A) (A)->lpVtbl->Release(A)
#define IDataObject_GetData(A,B,C) (A)->lpVtbl->GetData(A,B,C)
#define IDataObject_GetDataHere(A,B,C) (A)->lpVtbl->GetDataHere(A,B,C)
#define IDataObject_QueryGetData(A,B) (A)->lpVtbl->QueryGetData(A,B)
#define IDataObject_GetCanonicalFormatEtc(A,B,C) (A)->lpVtbl->GetCanonicalFormatEtc(A,B,C)
#define IDataObject_SetData(A,B,C,D) (A)->lpVtbl->SetData(A,B,C,D)
#define IDataObject_EnumFormatEtc(A,B,C) (A)->lpVtbl->EnumFormatEtc(A,B,C)
#define IDataObject_DAdvise(A,B,C,D,E) (A)->lpVtbl->DAdvise(A,B,C,D,E)
#define IDataObject_DUnadvise(A,B) (A)->lpVtbl->DUnadvise(A,B)
#define IDataObject_EnumDAdvise(A,B) (A)->lpVtbl->EnumDAdvise(A,B)
#endif 
HRESULT IDataObject_RemoteGetData_Proxy(IDataObject *,FORMATETC *,STGMEDIUM *);
void IDataObject_RemoteGetData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataObject_RemoteGetDataHere_Proxy(IDataObject *,FORMATETC *,STGMEDIUM *);
void IDataObject_RemoteGetDataHere_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataObject_QueryGetData_Proxy(IDataObject *,FORMATETC *);
void IDataObject_QueryGetData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataObject_GetCanonicalFormatEtc_Proxy(IDataObject *,FORMATETC *,FORMATETC *);
void IDataObject_GetCanonicalFormatEtc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataObject_RemoteSetData_Proxy(IDataObject *,FORMATETC *,FLAG_STGMEDIUM *,BOOL);
void IDataObject_RemoteSetData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataObject_EnumFormatEtc_Proxy(IDataObject *,DWORD,IEnumFORMATETC **);
void IDataObject_EnumFormatEtc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataObject_DAdvise_Proxy(IDataObject *,FORMATETC *,DWORD,IAdviseSink *,DWORD *);
void IDataObject_DAdvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataObject_DUnadvise_Proxy(IDataObject *,DWORD);
void IDataObject_DUnadvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataObject_EnumDAdvise_Proxy(IDataObject *,IEnumSTATDATA **);
void IDataObject_EnumDAdvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IDataAdviseHolder_INTERFACE_DEFINED__
#define __IDataAdviseHolder_INTERFACE_DEFINED__
typedef IDataAdviseHolder *LPDATAADVISEHOLDER;
EXTERN_C const IID IID_IDataAdviseHolder;
typedef struct IDataAdviseHolderVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IDataAdviseHolder *,REFIID,void **);
	ULONG (*AddRef)(IDataAdviseHolder *);
	ULONG (*Release)(IDataAdviseHolder *);
	HRESULT(*Advise)(IDataAdviseHolder *,IDataObject *,FORMATETC *,DWORD,IAdviseSink *,DWORD *);
	HRESULT(*Unadvise)(IDataAdviseHolder *,DWORD);
	HRESULT(*EnumAdvise)(IDataAdviseHolder *,IEnumSTATDATA **);
	HRESULT(*SendOnDataChange)(IDataAdviseHolder *,IDataObject *,DWORD,DWORD);
END_INTERFACE
} IDataAdviseHolderVtbl;
interface IDataAdviseHolder
{
CONST_VTBL struct IDataAdviseHolderVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IDataAdviseHolder_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IDataAdviseHolder_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IDataAdviseHolder_Release(A) (A)->lpVtbl->Release(A)
#define IDataAdviseHolder_Advise(A,B,C,D,E,F) (A)->lpVtbl->Advise(A,B,C,D,E,F)
#define IDataAdviseHolder_Unadvise(A,B) (A)->lpVtbl->Unadvise(A,B)
#define IDataAdviseHolder_EnumAdvise(A,B) (A)->lpVtbl->EnumAdvise(A,B)
#define IDataAdviseHolder_SendOnDataChange(A,B,C,D) (A)->lpVtbl->SendOnDataChange(A,B,C,D)
#endif 
HRESULT IDataAdviseHolder_Advise_Proxy(IDataAdviseHolder *,IDataObject *,FORMATETC *,DWORD,IAdviseSink *,DWORD *);
void IDataAdviseHolder_Advise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataAdviseHolder_Unadvise_Proxy(IDataAdviseHolder *,DWORD);
void IDataAdviseHolder_Unadvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataAdviseHolder_EnumAdvise_Proxy(IDataAdviseHolder *,IEnumSTATDATA **);
void IDataAdviseHolder_EnumAdvise_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDataAdviseHolder_SendOnDataChange_Proxy(IDataAdviseHolder *,IDataObject *,DWORD,DWORD);
void IDataAdviseHolder_SendOnDataChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IMessageFilter_INTERFACE_DEFINED__
#define __IMessageFilter_INTERFACE_DEFINED__
typedef IMessageFilter *LPMESSAGEFILTER;
typedef 
enum tagCALLTYPE
{	CALLTYPE_TOPLEVEL=1,CALLTYPE_NESTED=2,CALLTYPE_ASYNC=3,CALLTYPE_TOPLEVEL_CALLPENDING=4,CALLTYPE_ASYNC_CALLPENDING=5
} CALLTYPE;
typedef 
enum tagSERVERCALL
{	SERVERCALL_ISHANDLED=0,SERVERCALL_REJECTED=1,SERVERCALL_RETRYLATER=2
} SERVERCALL;
typedef 
enum tagPENDINGTYPE
{	PENDINGTYPE_TOPLEVEL=1,PENDINGTYPE_NESTED=2
} PENDINGTYPE;
typedef 
enum tagPENDINGMSG
{	PENDINGMSG_CANCELCALL=0,PENDINGMSG_WAITNOPROCESS=1,PENDINGMSG_WAITDEFPROCESS=2
} PENDINGMSG;
typedef struct tagINTERFACEINFO
{
IUnknown *pUnk;
IID iid;
WORD wMethod;
} INTERFACEINFO;
typedef struct tagINTERFACEINFO *LPINTERFACEINFO;
EXTERN_C const IID IID_IMessageFilter;
typedef struct IMessageFilterVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IMessageFilter *,REFIID,void **);
	ULONG (*AddRef)(IMessageFilter *);
	ULONG (*Release)(IMessageFilter *);
	DWORD (*HandleInComingCall)(IMessageFilter *,DWORD,HTASK,DWORD,LPINTERFACEINFO);
	DWORD (*RetryRejectedCall)(IMessageFilter *,HTASK,DWORD,DWORD);
	DWORD (*MessagePending)(IMessageFilter *,HTASK,DWORD,DWORD);
END_INTERFACE
} IMessageFilterVtbl;
interface IMessageFilter
{
CONST_VTBL struct IMessageFilterVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMessageFilter_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IMessageFilter_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IMessageFilter_Release(A) (A)->lpVtbl->Release(A)
#define IMessageFilter_HandleInComingCall(A,B,C,D,E) (A)->lpVtbl->HandleInComingCall(A,B,C,D,E)
#define IMessageFilter_RetryRejectedCall(A,B,C,D) (A)->lpVtbl->RetryRejectedCall(A,B,C,D)
#define IMessageFilter_MessagePending(A,B,C,D) (A)->lpVtbl->MessagePending(A,B,C,D)
#endif 
DWORD IMessageFilter_HandleInComingCall_Proxy(IMessageFilter *,DWORD,HTASK,DWORD,LPINTERFACEINFO);
void IMessageFilter_HandleInComingCall_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
DWORD IMessageFilter_RetryRejectedCall_Proxy(IMessageFilter *,HTASK,DWORD,DWORD);
void IMessageFilter_RetryRejectedCall_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
DWORD IMessageFilter_MessagePending_Proxy(IMessageFilter *,HTASK,DWORD,DWORD);
void IMessageFilter_MessagePending_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRpcChannelBuffer_INTERFACE_DEFINED__
#define __IRpcChannelBuffer_INTERFACE_DEFINED__
typedef unsigned long RPCOLEDATAREP;
typedef struct tagRPCOLEMESSAGE
{
void *reserved1;
RPCOLEDATAREP dataRepresentation;
void *Buffer;
ULONG cbBuffer;
ULONG iMethod;
void *reserved2[ 5 ];
ULONG rpcFlags;
} RPCOLEMESSAGE;
typedef RPCOLEMESSAGE *PRPCOLEMESSAGE;
EXTERN_C const IID IID_IRpcChannelBuffer;
typedef struct IRpcChannelBufferVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRpcChannelBuffer *,REFIID,void **);
	ULONG (*AddRef)(IRpcChannelBuffer *);
	ULONG (*Release)(IRpcChannelBuffer *);
	HRESULT(*GetBuffer)(IRpcChannelBuffer *,RPCOLEMESSAGE *,REFIID);
	HRESULT(*SendReceive)(IRpcChannelBuffer *,RPCOLEMESSAGE *,ULONG *);
	HRESULT(*FreeBuffer)(IRpcChannelBuffer *,RPCOLEMESSAGE *);
	HRESULT(*GetDestCtx)(IRpcChannelBuffer *,DWORD *,void **);
	HRESULT(*IsConnected)(IRpcChannelBuffer *);
END_INTERFACE
} IRpcChannelBufferVtbl;
interface IRpcChannelBuffer
{
CONST_VTBL struct IRpcChannelBufferVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRpcChannelBuffer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRpcChannelBuffer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRpcChannelBuffer_Release(A) (A)->lpVtbl->Release(A)
#define IRpcChannelBuffer_GetBuffer(A,B,C) (A)->lpVtbl->GetBuffer(A,B,C)
#define IRpcChannelBuffer_SendReceive(A,B,C) (A)->lpVtbl->SendReceive(A,B,C)
#define IRpcChannelBuffer_FreeBuffer(A,B) (A)->lpVtbl->FreeBuffer(A,B)
#define IRpcChannelBuffer_GetDestCtx(A,B,C) (A)->lpVtbl->GetDestCtx(A,B,C)
#define IRpcChannelBuffer_IsConnected(A) (A)->lpVtbl->IsConnected(A)
#endif 
HRESULT IRpcChannelBuffer_GetBuffer_Proxy(IRpcChannelBuffer *,RPCOLEMESSAGE *,REFIID);
void IRpcChannelBuffer_GetBuffer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer_SendReceive_Proxy(IRpcChannelBuffer *,RPCOLEMESSAGE *,ULONG *);
void IRpcChannelBuffer_SendReceive_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer_FreeBuffer_Proxy(IRpcChannelBuffer *,RPCOLEMESSAGE *);
void IRpcChannelBuffer_FreeBuffer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer_GetDestCtx_Proxy(IRpcChannelBuffer *,DWORD *,void **);
void IRpcChannelBuffer_GetDestCtx_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer_IsConnected_Proxy(IRpcChannelBuffer *);
void IRpcChannelBuffer_IsConnected_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRpcChannelBuffer2_INTERFACE_DEFINED__
#define __IRpcChannelBuffer2_INTERFACE_DEFINED__
EXTERN_C const IID IID_IRpcChannelBuffer2;
typedef struct IRpcChannelBuffer2Vtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRpcChannelBuffer2 *,REFIID,void **);
	ULONG (*AddRef)(IRpcChannelBuffer2 *);
	ULONG (*Release)(IRpcChannelBuffer2 *);
	HRESULT(*GetBuffer)(IRpcChannelBuffer2 *,RPCOLEMESSAGE *,REFIID);
	HRESULT(*SendReceive)(IRpcChannelBuffer2 *,RPCOLEMESSAGE *,ULONG *);
	HRESULT(*FreeBuffer)(IRpcChannelBuffer2 *,RPCOLEMESSAGE *);
	HRESULT(*GetDestCtx)(IRpcChannelBuffer2 *,DWORD *,void **);
	HRESULT(*IsConnected)(IRpcChannelBuffer2 *);
	HRESULT(*GetProtocolVersion)(IRpcChannelBuffer2 *,DWORD *);
END_INTERFACE
} IRpcChannelBuffer2Vtbl;
interface IRpcChannelBuffer2
{
CONST_VTBL struct IRpcChannelBuffer2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRpcChannelBuffer2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRpcChannelBuffer2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRpcChannelBuffer2_Release(A) (A)->lpVtbl->Release(A)
#define IRpcChannelBuffer2_GetBuffer(A,B,C) (A)->lpVtbl->GetBuffer(A,B,C)
#define IRpcChannelBuffer2_SendReceive(A,B,C) (A)->lpVtbl->SendReceive(A,B,C)
#define IRpcChannelBuffer2_FreeBuffer(A,B) (A)->lpVtbl->FreeBuffer(A,B)
#define IRpcChannelBuffer2_GetDestCtx(A,B,C) (A)->lpVtbl->GetDestCtx(A,B,C)
#define IRpcChannelBuffer2_IsConnected(A) (A)->lpVtbl->IsConnected(A)
#define IRpcChannelBuffer2_GetProtocolVersion(A,B) (A)->lpVtbl->GetProtocolVersion(A,B)
#endif 
HRESULT IRpcChannelBuffer2_GetProtocolVersion_Proxy(IRpcChannelBuffer2 *,DWORD *);
void IRpcChannelBuffer2_GetProtocolVersion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__
#define __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__
EXTERN_C const IID IID_IAsyncRpcChannelBuffer;
typedef struct IAsyncRpcChannelBufferVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IAsyncRpcChannelBuffer *,REFIID,void **);
	ULONG (*AddRef)(IAsyncRpcChannelBuffer *);
	ULONG (*Release)(IAsyncRpcChannelBuffer *);
	HRESULT(*GetBuffer)(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *,REFIID);
	HRESULT(*SendReceive)(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *,ULONG *);
	HRESULT(*FreeBuffer)(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *);
	HRESULT(*GetDestCtx)(IAsyncRpcChannelBuffer *,DWORD *,void **);
	HRESULT(*IsConnected)(IAsyncRpcChannelBuffer *);
	HRESULT(*GetProtocolVersion)(IAsyncRpcChannelBuffer *,DWORD *);
	HRESULT(*Send)(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *,ISynchronize *,ULONG *);
	HRESULT(*Receive)(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *,ULONG *);
	HRESULT(*GetDestCtxEx)(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *,DWORD *,void **);
END_INTERFACE
} IAsyncRpcChannelBufferVtbl;
interface IAsyncRpcChannelBuffer
{
CONST_VTBL struct IAsyncRpcChannelBufferVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IAsyncRpcChannelBuffer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IAsyncRpcChannelBuffer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IAsyncRpcChannelBuffer_Release(A) (A)->lpVtbl->Release(A)
#define IAsyncRpcChannelBuffer_GetBuffer(A,B,C) (A)->lpVtbl->GetBuffer(A,B,C)
#define IAsyncRpcChannelBuffer_SendReceive(A,B,C) (A)->lpVtbl->SendReceive(A,B,C)
#define IAsyncRpcChannelBuffer_FreeBuffer(A,B) (A)->lpVtbl->FreeBuffer(A,B)
#define IAsyncRpcChannelBuffer_GetDestCtx(A,B,C) (A)->lpVtbl->GetDestCtx(A,B,C)
#define IAsyncRpcChannelBuffer_IsConnected(A) (A)->lpVtbl->IsConnected(A)
#define IAsyncRpcChannelBuffer_GetProtocolVersion(A,B) (A)->lpVtbl->GetProtocolVersion(A,B)
#define IAsyncRpcChannelBuffer_Send(A,B,C,D) (A)->lpVtbl->Send(A,B,C,D)
#define IAsyncRpcChannelBuffer_Receive(A,B,C) (A)->lpVtbl->Receive(A,B,C)
#define IAsyncRpcChannelBuffer_GetDestCtxEx(A,B,C,D) (A)->lpVtbl->GetDestCtxEx(A,B,C,D)
#endif 
HRESULT IAsyncRpcChannelBuffer_Send_Proxy(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *,ISynchronize *,ULONG *);
void IAsyncRpcChannelBuffer_Send_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAsyncRpcChannelBuffer_Receive_Proxy(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *,ULONG *);
void IAsyncRpcChannelBuffer_Receive_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAsyncRpcChannelBuffer_GetDestCtxEx_Proxy(IAsyncRpcChannelBuffer *,RPCOLEMESSAGE *,DWORD *,void **);
void IAsyncRpcChannelBuffer_GetDestCtxEx_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRpcChannelBuffer3_INTERFACE_DEFINED__
#define __IRpcChannelBuffer3_INTERFACE_DEFINED__
EXTERN_C const IID IID_IRpcChannelBuffer3;
typedef struct IRpcChannelBuffer3Vtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRpcChannelBuffer3 *,REFIID,void **);
	ULONG (*AddRef)(IRpcChannelBuffer3 *);
	ULONG (*Release)(IRpcChannelBuffer3 *);
	HRESULT(*GetBuffer)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,REFIID);
	HRESULT(*SendReceive)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,ULONG *);
	HRESULT(*FreeBuffer)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *);
	HRESULT(*GetDestCtx)(IRpcChannelBuffer3 *,DWORD *,void **);
	HRESULT(*IsConnected)(IRpcChannelBuffer3 *);
	HRESULT(*GetProtocolVersion)(IRpcChannelBuffer3 *,DWORD *);
	HRESULT(*Send)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,ULONG *);
	HRESULT(*Receive)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,ULONG,ULONG *);
	HRESULT(*Cancel)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *);
	HRESULT(*GetCallContext)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,REFIID,void **);
	HRESULT(*GetDestCtxEx)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,DWORD *,void **);
	HRESULT(*GetState)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,DWORD *);
	HRESULT(*RegisterAsync)(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,IAsyncManager *);
END_INTERFACE
} IRpcChannelBuffer3Vtbl;
interface IRpcChannelBuffer3
{
CONST_VTBL struct IRpcChannelBuffer3Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRpcChannelBuffer3_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRpcChannelBuffer3_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRpcChannelBuffer3_Release(A) (A)->lpVtbl->Release(A)
#define IRpcChannelBuffer3_GetBuffer(A,B,C) (A)->lpVtbl->GetBuffer(A,B,C)
#define IRpcChannelBuffer3_SendReceive(A,B,C) (A)->lpVtbl->SendReceive(A,B,C)
#define IRpcChannelBuffer3_FreeBuffer(A,B) (A)->lpVtbl->FreeBuffer(A,B)
#define IRpcChannelBuffer3_GetDestCtx(A,B,C) (A)->lpVtbl->GetDestCtx(A,B,C)
#define IRpcChannelBuffer3_IsConnected(A) (A)->lpVtbl->IsConnected(A)
#define IRpcChannelBuffer3_GetProtocolVersion(A,B) (A)->lpVtbl->GetProtocolVersion(A,B)
#define IRpcChannelBuffer3_Send(A,B,C) (A)->lpVtbl->Send(A,B,C)
#define IRpcChannelBuffer3_Receive(A,B,C,D) (A)->lpVtbl->Receive(A,B,C,D)
#define IRpcChannelBuffer3_Cancel(A,B) (A)->lpVtbl->Cancel(A,B)
#define IRpcChannelBuffer3_GetCallContext(A,B,C,D) (A)->lpVtbl->GetCallContext(A,B,C,D)
#define IRpcChannelBuffer3_GetDestCtxEx(A,B,C,D) (A)->lpVtbl->GetDestCtxEx(A,B,C,D)
#define IRpcChannelBuffer3_GetState(A,B,C) (A)->lpVtbl->GetState(A,B,C)
#define IRpcChannelBuffer3_RegisterAsync(A,B,C) (A)->lpVtbl->RegisterAsync(A,B,C)
#endif 
HRESULT IRpcChannelBuffer3_Send_Proxy(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,ULONG *);
void IRpcChannelBuffer3_Send_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer3_Receive_Proxy(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,ULONG,ULONG *);
void IRpcChannelBuffer3_Receive_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer3_Cancel_Proxy(IRpcChannelBuffer3 *,RPCOLEMESSAGE *);
void IRpcChannelBuffer3_Cancel_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer3_GetCallContext_Proxy(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,REFIID,void **);
void IRpcChannelBuffer3_GetCallContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer3_GetDestCtxEx_Proxy(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,DWORD *,void **);
void IRpcChannelBuffer3_GetDestCtxEx_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer3_GetState_Proxy(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,DWORD *);
void IRpcChannelBuffer3_GetState_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcChannelBuffer3_RegisterAsync_Proxy(IRpcChannelBuffer3 *,RPCOLEMESSAGE *,IAsyncManager *);
void IRpcChannelBuffer3_RegisterAsync_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRpcSyntaxNegotiate_INTERFACE_DEFINED__
#define __IRpcSyntaxNegotiate_INTERFACE_DEFINED__
EXTERN_C const IID IID_IRpcSyntaxNegotiate;
typedef struct IRpcSyntaxNegotiateVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRpcSyntaxNegotiate *,REFIID,void **);
	ULONG (*AddRef)(IRpcSyntaxNegotiate *);
	ULONG (*Release)(IRpcSyntaxNegotiate *);
	HRESULT(*NegotiateSyntax)(IRpcSyntaxNegotiate *,RPCOLEMESSAGE *);
END_INTERFACE
} IRpcSyntaxNegotiateVtbl;
interface IRpcSyntaxNegotiate
{
CONST_VTBL struct IRpcSyntaxNegotiateVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRpcSyntaxNegotiate_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRpcSyntaxNegotiate_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRpcSyntaxNegotiate_Release(A) (A)->lpVtbl->Release(A)
#define IRpcSyntaxNegotiate_NegotiateSyntax(A,B) (A)->lpVtbl->NegotiateSyntax(A,B)
#endif 
HRESULT IRpcSyntaxNegotiate_NegotiateSyntax_Proxy(IRpcSyntaxNegotiate *,RPCOLEMESSAGE *);
void IRpcSyntaxNegotiate_NegotiateSyntax_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRpcProxyBuffer_INTERFACE_DEFINED__
#define __IRpcProxyBuffer_INTERFACE_DEFINED__
EXTERN_C const IID IID_IRpcProxyBuffer;
typedef struct IRpcProxyBufferVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRpcProxyBuffer *,REFIID,void **);
	ULONG (*AddRef)(IRpcProxyBuffer *);
	ULONG (*Release)(IRpcProxyBuffer *);
	HRESULT(*Connect)(IRpcProxyBuffer *,IRpcChannelBuffer *);
	void (*Disconnect)(IRpcProxyBuffer *);
END_INTERFACE
} IRpcProxyBufferVtbl;
interface IRpcProxyBuffer
{
CONST_VTBL struct IRpcProxyBufferVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRpcProxyBuffer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRpcProxyBuffer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRpcProxyBuffer_Release(A) (A)->lpVtbl->Release(A)
#define IRpcProxyBuffer_Connect(A,B) (A)->lpVtbl->Connect(A,B)
#define IRpcProxyBuffer_Disconnect(A) (A)->lpVtbl->Disconnect(A)
#endif 
HRESULT IRpcProxyBuffer_Connect_Proxy(IRpcProxyBuffer *,IRpcChannelBuffer *);
void IRpcProxyBuffer_Connect_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IRpcProxyBuffer_Disconnect_Proxy(IRpcProxyBuffer *);
void IRpcProxyBuffer_Disconnect_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRpcStubBuffer_INTERFACE_DEFINED__
#define __IRpcStubBuffer_INTERFACE_DEFINED__
EXTERN_C const IID IID_IRpcStubBuffer;
typedef struct IRpcStubBufferVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRpcStubBuffer *,REFIID,void **);
	ULONG (*AddRef)(IRpcStubBuffer *);
	ULONG (*Release)(IRpcStubBuffer *);
	HRESULT(*Connect)(IRpcStubBuffer *,IUnknown *);
	void (*Disconnect)(IRpcStubBuffer *);
	HRESULT(*Invoke)(IRpcStubBuffer *,RPCOLEMESSAGE *,IRpcChannelBuffer *);
	IRpcStubBuffer *(*IsIIDSupported)(IRpcStubBuffer *,REFIID);
	ULONG (*CountRefs)(IRpcStubBuffer *);
	HRESULT(*DebugServerQueryInterface)(IRpcStubBuffer *,void **);
	void (*DebugServerRelease)(IRpcStubBuffer *,void *);
END_INTERFACE
} IRpcStubBufferVtbl;
interface IRpcStubBuffer
{
CONST_VTBL struct IRpcStubBufferVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRpcStubBuffer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRpcStubBuffer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRpcStubBuffer_Release(A) (A)->lpVtbl->Release(A)
#define IRpcStubBuffer_Connect(A,B) (A)->lpVtbl->Connect(A,B)
#define IRpcStubBuffer_Disconnect(A) (A)->lpVtbl->Disconnect(A)
#define IRpcStubBuffer_Invoke(A,B,C) (A)->lpVtbl->Invoke(A,B,C)
#define IRpcStubBuffer_IsIIDSupported(A,B) (A)->lpVtbl->IsIIDSupported(A,B)
#define IRpcStubBuffer_CountRefs(A) (A)->lpVtbl->CountRefs(A)
#define IRpcStubBuffer_DebugServerQueryInterface(A,B) (A)->lpVtbl->DebugServerQueryInterface(A,B)
#define IRpcStubBuffer_DebugServerRelease(A,B) (A)->lpVtbl->DebugServerRelease(A,B)
#endif 
HRESULT IRpcStubBuffer_Connect_Proxy(IRpcStubBuffer *,IUnknown *);
void IRpcStubBuffer_Connect_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IRpcStubBuffer_Disconnect_Proxy(IRpcStubBuffer *);
void IRpcStubBuffer_Disconnect_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcStubBuffer_Invoke_Proxy(IRpcStubBuffer *,RPCOLEMESSAGE *,IRpcChannelBuffer *);
void IRpcStubBuffer_Invoke_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
IRpcStubBuffer * IRpcStubBuffer_IsIIDSupported_Proxy(IRpcStubBuffer *,REFIID);
void IRpcStubBuffer_IsIIDSupported_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
ULONG IRpcStubBuffer_CountRefs_Proxy(IRpcStubBuffer *);
void IRpcStubBuffer_CountRefs_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcStubBuffer_DebugServerQueryInterface_Proxy(IRpcStubBuffer *,void **);
void IRpcStubBuffer_DebugServerQueryInterface_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IRpcStubBuffer_DebugServerRelease_Proxy(IRpcStubBuffer *,void *);
void IRpcStubBuffer_DebugServerRelease_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IPSFactoryBuffer_INTERFACE_DEFINED__
#define __IPSFactoryBuffer_INTERFACE_DEFINED__
EXTERN_C const IID IID_IPSFactoryBuffer;
typedef struct IPSFactoryBufferVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IPSFactoryBuffer *,REFIID,void **);
	ULONG (*AddRef)(IPSFactoryBuffer *);
	ULONG (*Release)(IPSFactoryBuffer *);
	HRESULT(*CreateProxy)(IPSFactoryBuffer *,IUnknown *,REFIID,IRpcProxyBuffer **,void **);
	HRESULT(*CreateStub)(IPSFactoryBuffer *,REFIID,IUnknown *,IRpcStubBuffer **);
END_INTERFACE
} IPSFactoryBufferVtbl;
interface IPSFactoryBuffer
{
CONST_VTBL struct IPSFactoryBufferVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPSFactoryBuffer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPSFactoryBuffer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPSFactoryBuffer_Release(A) (A)->lpVtbl->Release(A)
#define IPSFactoryBuffer_CreateProxy(A,B,C,D,E) (A)->lpVtbl->CreateProxy(A,B,C,D,E)
#define IPSFactoryBuffer_CreateStub(A,B,C,D) (A)->lpVtbl->CreateStub(A,B,C,D)
#endif 
HRESULT IPSFactoryBuffer_CreateProxy_Proxy(IPSFactoryBuffer *,IUnknown *,REFIID,IRpcProxyBuffer **,void **);
void IPSFactoryBuffer_CreateProxy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPSFactoryBuffer_CreateStub_Proxy(IPSFactoryBuffer *,REFIID,IUnknown *,IRpcStubBuffer **);
void IPSFactoryBuffer_CreateStub_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#if (_WIN32_WINNT >= 1024) || defined(_WIN32_DCOM) 
typedef struct SChannelHookCallInfo
{
IID iid;
DWORD cbSize;
GUID uCausality;
DWORD dwServerPid;
DWORD iMethod;
void *pObject;
} SChannelHookCallInfo;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0050_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0050_v0_0_s_ifspec;
#ifndef __IChannelHook_INTERFACE_DEFINED__
#define __IChannelHook_INTERFACE_DEFINED__
EXTERN_C const IID IID_IChannelHook;
typedef struct IChannelHookVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IChannelHook *,REFIID,void **);
	ULONG (*AddRef)(IChannelHook *);
	ULONG (*Release)(IChannelHook *);
	void (*ClientGetSize)(IChannelHook *,REFGUID,REFIID,ULONG *);
	void (*ClientFillBuffer)(IChannelHook *,REFGUID,REFIID,ULONG *,void *);
	void (*ClientNotify)(IChannelHook *,REFGUID,REFIID,ULONG,void *,DWORD,HRESULT);
	void (*ServerNotify)(IChannelHook *,REFGUID,REFIID,ULONG,void *,DWORD);
	void (*ServerGetSize)(IChannelHook *,REFGUID,REFIID,HRESULT,ULONG *);
	void (*ServerFillBuffer)(IChannelHook *,REFGUID,REFIID,ULONG *,void *,HRESULT);
END_INTERFACE
} IChannelHookVtbl;
interface IChannelHook
{
CONST_VTBL struct IChannelHookVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IChannelHook_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IChannelHook_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IChannelHook_Release(A) (A)->lpVtbl->Release(A)
#define IChannelHook_ClientGetSize(A,B,C,D) (A)->lpVtbl->ClientGetSize(A,B,C,D)
#define IChannelHook_ClientFillBuffer(A,B,C,D,E) (A)->lpVtbl->ClientFillBuffer(A,B,C,D,E)
#define IChannelHook_ClientNotify(A,B,C,D,E,F,G) (A)->lpVtbl->ClientNotify(A,B,C,D,E,F,G)
#define IChannelHook_ServerNotify(A,B,C,D,E,F) (A)->lpVtbl->ServerNotify(A,B,C,D,E,F)
#define IChannelHook_ServerGetSize(A,B,C,D,E) (A)->lpVtbl->ServerGetSize(A,B,C,D,E)
#define IChannelHook_ServerFillBuffer(A,B,C,D,E,F) (A)->lpVtbl->ServerFillBuffer(A,B,C,D,E,F)
#endif 
void IChannelHook_ClientGetSize_Proxy(IChannelHook *,REFGUID,REFIID,ULONG *);
void IChannelHook_ClientGetSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IChannelHook_ClientFillBuffer_Proxy(IChannelHook *,REFGUID,REFIID,ULONG *,void *);
void IChannelHook_ClientFillBuffer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IChannelHook_ClientNotify_Proxy(IChannelHook *,REFGUID,REFIID,ULONG,void *,DWORD,HRESULT);
void IChannelHook_ClientNotify_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IChannelHook_ServerNotify_Proxy(IChannelHook *,REFGUID,REFIID,ULONG,void *,DWORD);
void IChannelHook_ServerNotify_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IChannelHook_ServerGetSize_Proxy(IChannelHook *,REFGUID,REFIID,HRESULT,ULONG *);
void IChannelHook_ServerGetSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IChannelHook_ServerFillBuffer_Proxy(IChannelHook *,REFGUID,REFIID,ULONG *,void *,HRESULT);
void IChannelHook_ServerFillBuffer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#endif 
extern const FMTID FMTID_SummaryInformation;
extern const FMTID FMTID_DocSummaryInformation;
extern const FMTID FMTID_UserDefinedProperties;
extern const FMTID FMTID_DiscardableInformation;
extern const FMTID FMTID_ImageSummaryInformation;
extern const FMTID FMTID_AudioSummaryInformation;
extern const FMTID FMTID_VideoSummaryInformation;
extern const FMTID FMTID_MediaFileSummaryInformation;
#if (_WIN32_WINNT >= 1024) || defined(_WIN32_DCOM) 
extern RPC_IF_HANDLE __MIDL_itf_objidl_0051_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0051_v0_0_s_ifspec;
#ifndef __IClientSecurity_INTERFACE_DEFINED__
#define __IClientSecurity_INTERFACE_DEFINED__
typedef struct tagSOLE_AUTHENTICATION_SERVICE
{
DWORD dwAuthnSvc;
DWORD dwAuthzSvc;
OLECHAR *pPrincipalName;
HRESULT hr;
} SOLE_AUTHENTICATION_SERVICE;
typedef SOLE_AUTHENTICATION_SERVICE *PSOLE_AUTHENTICATION_SERVICE;
typedef 
enum tagEOLE_AUTHENTICATION_CAPABILITIES
{	EOAC_NONE=0,EOAC_MUTUAL_AUTH=1,EOAC_STATIC_CLOAKING=32,EOAC_DYNAMIC_CLOAKING=64,EOAC_ANY_AUTHORITY=128,EOAC_MAKE_FULLSIC=256,EOAC_DEFAULT=2048,EOAC_SECURE_REFS=2,EOAC_ACCESS_CONTROL=4,EOAC_APPID=8,EOAC_DYNAMIC=16,EOAC_REQUIRE_FULLSIC=512,EOAC_AUTO_IMPERSONATE=1024,EOAC_NO_CUSTOM_MARSHAL=0x2000,EOAC_DISABLE_AAA=4096
} EOLE_AUTHENTICATION_CAPABILITIES;
#define	COLE_DEFAULT_PRINCIPAL	((OLECHAR *)-1)
#define	COLE_DEFAULT_AUTHINFO	((void *)-1)
typedef struct tagSOLE_AUTHENTICATION_INFO
{
DWORD dwAuthnSvc;
DWORD dwAuthzSvc;
void *pAuthInfo;
} SOLE_AUTHENTICATION_INFO;
typedef struct tagSOLE_AUTHENTICATION_INFO *PSOLE_AUTHENTICATION_INFO;
typedef struct tagSOLE_AUTHENTICATION_LIST
{
DWORD cAuthInfo;
SOLE_AUTHENTICATION_INFO *aAuthInfo;
} SOLE_AUTHENTICATION_LIST;
typedef struct tagSOLE_AUTHENTICATION_LIST *PSOLE_AUTHENTICATION_LIST;
EXTERN_C const IID IID_IClientSecurity;
typedef struct IClientSecurityVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IClientSecurity *,REFIID,void **);
	ULONG (*AddRef)(IClientSecurity *);
	ULONG (*Release)(IClientSecurity *);
	HRESULT(*QueryBlanket)(IClientSecurity *,IUnknown *,DWORD *,DWORD *,OLECHAR **,DWORD *,DWORD *,void **,DWORD *);
	HRESULT(*SetBlanket)(IClientSecurity *,IUnknown *,DWORD,DWORD,OLECHAR *,DWORD,DWORD,void *,DWORD);
	HRESULT(*CopyProxy)(IClientSecurity *,IUnknown *,IUnknown **);
END_INTERFACE
} IClientSecurityVtbl;
interface IClientSecurity
{
CONST_VTBL struct IClientSecurityVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IClientSecurity_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IClientSecurity_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IClientSecurity_Release(A) (A)->lpVtbl->Release(A)
#define IClientSecurity_QueryBlanket(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->QueryBlanket(A,B,C,D,E,F,G,H,I)
#define IClientSecurity_SetBlanket(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->SetBlanket(A,B,C,D,E,F,G,H,I)
#define IClientSecurity_CopyProxy(A,B,C) (A)->lpVtbl->CopyProxy(A,B,C)
#endif 
HRESULT IClientSecurity_QueryBlanket_Proxy(IClientSecurity *,IUnknown *,DWORD *,DWORD *,OLECHAR **,DWORD *,DWORD *,void **,DWORD *);
void IClientSecurity_QueryBlanket_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IClientSecurity_SetBlanket_Proxy(IClientSecurity *,IUnknown *,DWORD,DWORD,OLECHAR *,DWORD,DWORD,void *,DWORD);
void IClientSecurity_SetBlanket_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IClientSecurity_CopyProxy_Proxy(IClientSecurity *,IUnknown *,IUnknown **);
void IClientSecurity_CopyProxy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IServerSecurity_INTERFACE_DEFINED__
#define __IServerSecurity_INTERFACE_DEFINED__
EXTERN_C const IID IID_IServerSecurity;
typedef struct IServerSecurityVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IServerSecurity *,REFIID,void **);
	ULONG (*AddRef)(IServerSecurity *);
	ULONG (*Release)(IServerSecurity *);
	HRESULT(*QueryBlanket)(IServerSecurity *,DWORD *,DWORD *,OLECHAR **,DWORD *,DWORD *,void **,DWORD *);
	HRESULT(*ImpersonateClient)(IServerSecurity *);
	HRESULT(*RevertToSelf)(IServerSecurity *);
	BOOL (*IsImpersonating)(IServerSecurity *);
END_INTERFACE
} IServerSecurityVtbl;
interface IServerSecurity
{
CONST_VTBL struct IServerSecurityVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IServerSecurity_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IServerSecurity_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IServerSecurity_Release(A) (A)->lpVtbl->Release(A)
#define IServerSecurity_QueryBlanket(A,B,C,D,E,F,G,H) (A)->lpVtbl->QueryBlanket(A,B,C,D,E,F,G,H)
#define IServerSecurity_ImpersonateClient(A) (A)->lpVtbl->ImpersonateClient(A)
#define IServerSecurity_RevertToSelf(A) (A)->lpVtbl->RevertToSelf(A)
#define IServerSecurity_IsImpersonating(A) (A)->lpVtbl->IsImpersonating(A)
#endif 
HRESULT IServerSecurity_QueryBlanket_Proxy(IServerSecurity *,DWORD *,DWORD *,OLECHAR **,DWORD *,DWORD *,void **,DWORD *);
void IServerSecurity_QueryBlanket_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IServerSecurity_ImpersonateClient_Proxy(IServerSecurity *);
void IServerSecurity_ImpersonateClient_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IServerSecurity_RevertToSelf_Proxy(IServerSecurity *);
void IServerSecurity_RevertToSelf_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
BOOL IServerSecurity_IsImpersonating_Proxy(IServerSecurity *);
void IServerSecurity_IsImpersonating_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IClassActivator_INTERFACE_DEFINED__
#define __IClassActivator_INTERFACE_DEFINED__
EXTERN_C const IID IID_IClassActivator;
typedef struct IClassActivatorVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IClassActivator *,REFIID,void **);
	ULONG (*AddRef)(IClassActivator *);
	ULONG (*Release)(IClassActivator *);
	HRESULT(*GetClassObject)(IClassActivator *,REFCLSID,DWORD,LCID,REFIID,void **);
END_INTERFACE
} IClassActivatorVtbl;
interface IClassActivator
{
CONST_VTBL struct IClassActivatorVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IClassActivator_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IClassActivator_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IClassActivator_Release(A) (A)->lpVtbl->Release(A)
#define IClassActivator_GetClassObject(A,B,C,D,E,F) (A)->lpVtbl->GetClassObject(A,B,C,D,E,F)
#endif 
HRESULT IClassActivator_GetClassObject_Proxy(IClassActivator *,REFCLSID,DWORD,LCID,REFIID,void **);
void IClassActivator_GetClassObject_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRpcOptions_INTERFACE_DEFINED__
#define __IRpcOptions_INTERFACE_DEFINED__
EXTERN_C const IID IID_IRpcOptions;
typedef struct IRpcOptionsVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRpcOptions *,REFIID,void **);
	ULONG (*AddRef)(IRpcOptions *);
	ULONG (*Release)(IRpcOptions *);
	HRESULT(*Set)(IRpcOptions *,IUnknown *,DWORD,ULONG_PTR);
	HRESULT(*Query)(IRpcOptions *,IUnknown *,DWORD,ULONG_PTR *);
END_INTERFACE
} IRpcOptionsVtbl;
interface IRpcOptions
{
CONST_VTBL struct IRpcOptionsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRpcOptions_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRpcOptions_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRpcOptions_Release(A) (A)->lpVtbl->Release(A)
#define IRpcOptions_Set(A,B,C,D) (A)->lpVtbl->Set(A,B,C,D)
#define IRpcOptions_Query(A,B,C,D) (A)->lpVtbl->Query(A,B,C,D)
#endif 
HRESULT IRpcOptions_Set_Proxy(IRpcOptions *,IUnknown *,DWORD,ULONG_PTR);
void IRpcOptions_Set_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcOptions_Query_Proxy(IRpcOptions *,IUnknown *,DWORD,ULONG_PTR *);
void IRpcOptions_Query_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
enum __MIDL___MIDL_itf_objidl_0055_0001
{	COMBND_RPCTIMEOUT=1,COMBND_SERVER_LOCALITY=2
} ;
enum __MIDL___MIDL_itf_objidl_0055_0002
{	SERVER_LOCALITY_PROCESS_LOCAL=0,SERVER_LOCALITY_MACHINE_LOCAL=1,SERVER_LOCALITY_REMOTE=2
} ;
#endif 
extern RPC_IF_HANDLE __MIDL_itf_objidl_0055_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0055_v0_0_s_ifspec;
#ifndef __IFillLockBytes_INTERFACE_DEFINED__
#define __IFillLockBytes_INTERFACE_DEFINED__
EXTERN_C const IID IID_IFillLockBytes;
typedef struct IFillLockBytesVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IFillLockBytes *,REFIID,void **);
	ULONG (*AddRef)(IFillLockBytes *);
	ULONG (*Release)(IFillLockBytes *);
	HRESULT(*FillAppend)(IFillLockBytes *,const void *pv,ULONG,ULONG *);
	HRESULT(*FillAt)(IFillLockBytes *,ULARGE_INTEGER,const void *pv,ULONG,ULONG *);
	HRESULT(*SetFillSize)(IFillLockBytes *,ULARGE_INTEGER);
	HRESULT(*Terminate)(IFillLockBytes *,BOOL);
END_INTERFACE
} IFillLockBytesVtbl;
interface IFillLockBytes
{
CONST_VTBL struct IFillLockBytesVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IFillLockBytes_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IFillLockBytes_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IFillLockBytes_Release(A) (A)->lpVtbl->Release(A)
#define IFillLockBytes_FillAppend(A,B,C,D) (A)->lpVtbl->FillAppend(A,B,C,D)
#define IFillLockBytes_FillAt(A,B,C,D,E) (A)->lpVtbl->FillAt(A,B,C,D,E)
#define IFillLockBytes_SetFillSize(A,B) (A)->lpVtbl->SetFillSize(A,B)
#define IFillLockBytes_Terminate(A,B) (A)->lpVtbl->Terminate(A,B)
#endif 
HRESULT IFillLockBytes_RemoteFillAppend_Proxy(IFillLockBytes *,const byte *pv,ULONG,ULONG *);
void IFillLockBytes_RemoteFillAppend_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IFillLockBytes_RemoteFillAt_Proxy(IFillLockBytes *,ULARGE_INTEGER,const byte *pv,ULONG,ULONG *);
void IFillLockBytes_RemoteFillAt_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IFillLockBytes_SetFillSize_Proxy(IFillLockBytes *,ULARGE_INTEGER);
void IFillLockBytes_SetFillSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IFillLockBytes_Terminate_Proxy(IFillLockBytes *,BOOL);
void IFillLockBytes_Terminate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IProgressNotify_INTERFACE_DEFINED__
#define __IProgressNotify_INTERFACE_DEFINED__
EXTERN_C const IID IID_IProgressNotify;
typedef struct IProgressNotifyVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IProgressNotify *,REFIID,void **);
	ULONG (*AddRef)(IProgressNotify *);
	ULONG (*Release)(IProgressNotify *);
	HRESULT(*OnProgress)(IProgressNotify *,DWORD,DWORD,BOOL,BOOL);
END_INTERFACE
} IProgressNotifyVtbl;
interface IProgressNotify
{
CONST_VTBL struct IProgressNotifyVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IProgressNotify_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IProgressNotify_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IProgressNotify_Release(A) (A)->lpVtbl->Release(A)
#define IProgressNotify_OnProgress(A,B,C,D,E) (A)->lpVtbl->OnProgress(A,B,C,D,E)
#endif 
HRESULT IProgressNotify_OnProgress_Proxy(IProgressNotify *,DWORD,DWORD,BOOL,BOOL);
void IProgressNotify_OnProgress_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ILayoutStorage_INTERFACE_DEFINED__
#define __ILayoutStorage_INTERFACE_DEFINED__
typedef struct tagStorageLayout
{
DWORD LayoutType;
OLECHAR *pwcsElementName;
LARGE_INTEGER cOffset;
LARGE_INTEGER cBytes;
} StorageLayout;
EXTERN_C const IID IID_ILayoutStorage;
typedef struct ILayoutStorageVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ILayoutStorage *,REFIID,void **);
	ULONG (*AddRef)(ILayoutStorage *);
	ULONG (*Release)(ILayoutStorage *);
	HRESULT(*LayoutScript)(ILayoutStorage *,StorageLayout *,DWORD,DWORD);
	HRESULT(*BeginMonitor)(ILayoutStorage *);
	HRESULT(*EndMonitor)(ILayoutStorage *);
	HRESULT(*ReLayoutDocfile)(ILayoutStorage *,OLECHAR *);
	HRESULT(*ReLayoutDocfileOnILockBytes)(ILayoutStorage *,ILockBytes *);
END_INTERFACE
} ILayoutStorageVtbl;
interface ILayoutStorage
{
CONST_VTBL struct ILayoutStorageVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ILayoutStorage_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ILayoutStorage_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ILayoutStorage_Release(A) (A)->lpVtbl->Release(A)
#define ILayoutStorage_LayoutScript(A,B,C,D) (A)->lpVtbl->LayoutScript(A,B,C,D)
#define ILayoutStorage_BeginMonitor(A) (A)->lpVtbl->BeginMonitor(A)
#define ILayoutStorage_EndMonitor(A) (A)->lpVtbl->EndMonitor(A)
#define ILayoutStorage_ReLayoutDocfile(A,B) (A)->lpVtbl->ReLayoutDocfile(A,B)
#define ILayoutStorage_ReLayoutDocfileOnILockBytes(A,B) (A)->lpVtbl->ReLayoutDocfileOnILockBytes(A,B)
#endif 
HRESULT ILayoutStorage_LayoutScript_Proxy(ILayoutStorage *,StorageLayout *,DWORD,DWORD);
void ILayoutStorage_LayoutScript_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILayoutStorage_BeginMonitor_Proxy(ILayoutStorage *);
void ILayoutStorage_BeginMonitor_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILayoutStorage_EndMonitor_Proxy(ILayoutStorage *);
void ILayoutStorage_EndMonitor_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILayoutStorage_ReLayoutDocfile_Proxy(ILayoutStorage *,OLECHAR *);
void ILayoutStorage_ReLayoutDocfile_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ILayoutStorage_ReLayoutDocfileOnILockBytes_Proxy(ILayoutStorage *,ILockBytes *);
void ILayoutStorage_ReLayoutDocfileOnILockBytes_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IBlockingLock_INTERFACE_DEFINED__
#define __IBlockingLock_INTERFACE_DEFINED__
EXTERN_C const IID IID_IBlockingLock;
typedef struct IBlockingLockVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IBlockingLock *,REFIID,void **);
	ULONG (*AddRef)(IBlockingLock *);
	ULONG (*Release)(IBlockingLock *);
	HRESULT(*Lock)(IBlockingLock *,DWORD);
	HRESULT(*Unlock)(IBlockingLock *);
END_INTERFACE
} IBlockingLockVtbl;
interface IBlockingLock
{
CONST_VTBL struct IBlockingLockVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IBlockingLock_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IBlockingLock_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IBlockingLock_Release(A) (A)->lpVtbl->Release(A)
#define IBlockingLock_Lock(A,B) (A)->lpVtbl->Lock(A,B)
#define IBlockingLock_Unlock(A) (A)->lpVtbl->Unlock(A)
#endif 
HRESULT IBlockingLock_Lock_Proxy(IBlockingLock *,DWORD);
void IBlockingLock_Lock_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IBlockingLock_Unlock_Proxy(IBlockingLock *);
void IBlockingLock_Unlock_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ITimeAndNoticeControl_INTERFACE_DEFINED__
#define __ITimeAndNoticeControl_INTERFACE_DEFINED__
EXTERN_C const IID IID_ITimeAndNoticeControl;
typedef struct ITimeAndNoticeControlVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ITimeAndNoticeControl *,REFIID,void **);
	ULONG (*AddRef)(ITimeAndNoticeControl *);
	ULONG (*Release)(ITimeAndNoticeControl *);
	HRESULT(*SuppressChanges)(ITimeAndNoticeControl *,DWORD,DWORD);
END_INTERFACE
} ITimeAndNoticeControlVtbl;
interface ITimeAndNoticeControl
{
CONST_VTBL struct ITimeAndNoticeControlVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITimeAndNoticeControl_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITimeAndNoticeControl_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITimeAndNoticeControl_Release(A) (A)->lpVtbl->Release(A)
#define ITimeAndNoticeControl_SuppressChanges(A,B,C) (A)->lpVtbl->SuppressChanges(A,B,C)
#endif 
HRESULT ITimeAndNoticeControl_SuppressChanges_Proxy(ITimeAndNoticeControl *,DWORD,DWORD);
void ITimeAndNoticeControl_SuppressChanges_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IOplockStorage_INTERFACE_DEFINED__
#define __IOplockStorage_INTERFACE_DEFINED__
EXTERN_C const IID IID_IOplockStorage;
typedef struct IOplockStorageVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IOplockStorage *,REFIID,void **);
	ULONG (*AddRef)(IOplockStorage *);
	ULONG (*Release)(IOplockStorage *);
	HRESULT(*CreateStorageEx)(IOplockStorage *,LPCWSTR,DWORD,DWORD,DWORD,REFIID,void **);
	HRESULT(*OpenStorageEx)(IOplockStorage *,LPCWSTR,DWORD,DWORD,DWORD,REFIID,void **);
END_INTERFACE
} IOplockStorageVtbl;
interface IOplockStorage
{
CONST_VTBL struct IOplockStorageVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IOplockStorage_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IOplockStorage_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IOplockStorage_Release(A) (A)->lpVtbl->Release(A)
#define IOplockStorage_CreateStorageEx(A,B,C,D,E,F,G) (A)->lpVtbl->CreateStorageEx(A,B,C,D,E,F,G)
#define IOplockStorage_OpenStorageEx(A,B,C,D,E,F,G) (A)->lpVtbl->OpenStorageEx(A,B,C,D,E,F,G)
#endif 
HRESULT IOplockStorage_CreateStorageEx_Proxy(IOplockStorage *,LPCWSTR,DWORD,DWORD,DWORD,REFIID,void **);
void IOplockStorage_CreateStorageEx_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IOplockStorage_OpenStorageEx_Proxy(IOplockStorage *,LPCWSTR,DWORD,DWORD,DWORD,REFIID,void **);
void IOplockStorage_OpenStorageEx_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ISurrogate_INTERFACE_DEFINED__
#define __ISurrogate_INTERFACE_DEFINED__
typedef ISurrogate *LPSURROGATE;
EXTERN_C const IID IID_ISurrogate;
typedef struct ISurrogateVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ISurrogate *,REFIID,void **);
	ULONG (*AddRef)(ISurrogate *);
	ULONG (*Release)(ISurrogate *);
	HRESULT(*LoadDllServer)(ISurrogate *,REFCLSID);
	HRESULT(*FreeSurrogate)(ISurrogate *);
END_INTERFACE
} ISurrogateVtbl;
interface ISurrogate
{
CONST_VTBL struct ISurrogateVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISurrogate_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISurrogate_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISurrogate_Release(A) (A)->lpVtbl->Release(A)
#define ISurrogate_LoadDllServer(A,B) (A)->lpVtbl->LoadDllServer(A,B)
#define ISurrogate_FreeSurrogate(A) (A)->lpVtbl->FreeSurrogate(A)
#endif 
HRESULT ISurrogate_LoadDllServer_Proxy(ISurrogate *,REFCLSID);
void ISurrogate_LoadDllServer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISurrogate_FreeSurrogate_Proxy(ISurrogate *);
void ISurrogate_FreeSurrogate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IGlobalInterfaceTable_INTERFACE_DEFINED__
#define __IGlobalInterfaceTable_INTERFACE_DEFINED__
typedef IGlobalInterfaceTable *LPGLOBALINTERFACETABLE;
EXTERN_C const IID IID_IGlobalInterfaceTable;
typedef struct IGlobalInterfaceTableVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IGlobalInterfaceTable *,REFIID,void **);
	ULONG (*AddRef)(IGlobalInterfaceTable *);
	ULONG (*Release)(IGlobalInterfaceTable *);
	HRESULT(*RegisterInterfaceInGlobal)(IGlobalInterfaceTable *,IUnknown *,REFIID,DWORD *);
	HRESULT(*RevokeInterfaceFromGlobal)(IGlobalInterfaceTable *,DWORD);
	HRESULT(*GetInterfaceFromGlobal)(IGlobalInterfaceTable *,DWORD,REFIID,void **);
END_INTERFACE
} IGlobalInterfaceTableVtbl;
interface IGlobalInterfaceTable
{
CONST_VTBL struct IGlobalInterfaceTableVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IGlobalInterfaceTable_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IGlobalInterfaceTable_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IGlobalInterfaceTable_Release(A) (A)->lpVtbl->Release(A)
#define IGlobalInterfaceTable_RegisterInterfaceInGlobal(A,B,C,D) (A)->lpVtbl->RegisterInterfaceInGlobal(A,B,C,D)
#define IGlobalInterfaceTable_RevokeInterfaceFromGlobal(A,B) (A)->lpVtbl->RevokeInterfaceFromGlobal(A,B)
#define IGlobalInterfaceTable_GetInterfaceFromGlobal(A,B,C,D) (A)->lpVtbl->GetInterfaceFromGlobal(A,B,C,D)
#endif 
HRESULT IGlobalInterfaceTable_RegisterInterfaceInGlobal_Proxy(IGlobalInterfaceTable *,IUnknown *,REFIID,DWORD *);
void IGlobalInterfaceTable_RegisterInterfaceInGlobal_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IGlobalInterfaceTable_RevokeInterfaceFromGlobal_Proxy(IGlobalInterfaceTable *,DWORD);
void IGlobalInterfaceTable_RevokeInterfaceFromGlobal_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IGlobalInterfaceTable_GetInterfaceFromGlobal_Proxy(IGlobalInterfaceTable *,DWORD,REFIID,void **);
void IGlobalInterfaceTable_GetInterfaceFromGlobal_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IDirectWriterLock_INTERFACE_DEFINED__
#define __IDirectWriterLock_INTERFACE_DEFINED__
EXTERN_C const IID IID_IDirectWriterLock;
typedef struct IDirectWriterLockVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IDirectWriterLock *,REFIID,void **);
	ULONG (*AddRef)(IDirectWriterLock *);
	ULONG (*Release)(IDirectWriterLock *);
	HRESULT(*WaitForWriteAccess)(IDirectWriterLock *,DWORD);
	HRESULT(*ReleaseWriteAccess)(IDirectWriterLock *);
	HRESULT(*HaveWriteAccess)(IDirectWriterLock *);
END_INTERFACE
} IDirectWriterLockVtbl;
interface IDirectWriterLock
{
CONST_VTBL struct IDirectWriterLockVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IDirectWriterLock_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IDirectWriterLock_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IDirectWriterLock_Release(A) (A)->lpVtbl->Release(A)
#define IDirectWriterLock_WaitForWriteAccess(A,B) (A)->lpVtbl->WaitForWriteAccess(A,B)
#define IDirectWriterLock_ReleaseWriteAccess(A) (A)->lpVtbl->ReleaseWriteAccess(A)
#define IDirectWriterLock_HaveWriteAccess(A) (A)->lpVtbl->HaveWriteAccess(A)
#endif 
HRESULT IDirectWriterLock_WaitForWriteAccess_Proxy(IDirectWriterLock *,DWORD);
void IDirectWriterLock_WaitForWriteAccess_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDirectWriterLock_ReleaseWriteAccess_Proxy(IDirectWriterLock *);
void IDirectWriterLock_ReleaseWriteAccess_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IDirectWriterLock_HaveWriteAccess_Proxy(IDirectWriterLock *);
void IDirectWriterLock_HaveWriteAccess_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ISynchronize_INTERFACE_DEFINED__
#define __ISynchronize_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISynchronize;
typedef struct ISynchronizeVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ISynchronize *,REFIID,void **);
	ULONG (*AddRef)(ISynchronize *);
	ULONG (*Release)(ISynchronize *);
	HRESULT(*Wait)(ISynchronize *,DWORD,DWORD);
	HRESULT(*Signal)(ISynchronize *);
	HRESULT(*Reset)(ISynchronize *);
END_INTERFACE
} ISynchronizeVtbl;
interface ISynchronize
{
CONST_VTBL struct ISynchronizeVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISynchronize_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISynchronize_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISynchronize_Release(A) (A)->lpVtbl->Release(A)
#define ISynchronize_Wait(A,B,C) (A)->lpVtbl->Wait(A,B,C)
#define ISynchronize_Signal(A) (A)->lpVtbl->Signal(A)
#define ISynchronize_Reset(A) (A)->lpVtbl->Reset(A)
#endif 
HRESULT ISynchronize_Wait_Proxy(ISynchronize *,DWORD,DWORD);
void ISynchronize_Wait_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISynchronize_Signal_Proxy(ISynchronize *);
void ISynchronize_Signal_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISynchronize_Reset_Proxy(ISynchronize *);
void ISynchronize_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ISynchronizeHandle_INTERFACE_DEFINED__
#define __ISynchronizeHandle_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISynchronizeHandle;
typedef struct ISynchronizeHandleVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ISynchronizeHandle *,REFIID,void **);
	ULONG (*AddRef)(ISynchronizeHandle *);
	ULONG (*Release)(ISynchronizeHandle *);
	HRESULT(*GetHandle)(ISynchronizeHandle *,HANDLE *);
END_INTERFACE
} ISynchronizeHandleVtbl;
interface ISynchronizeHandle
{
CONST_VTBL struct ISynchronizeHandleVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISynchronizeHandle_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISynchronizeHandle_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISynchronizeHandle_Release(A) (A)->lpVtbl->Release(A)
#define ISynchronizeHandle_GetHandle(A,B) (A)->lpVtbl->GetHandle(A,B)
#endif 
HRESULT ISynchronizeHandle_GetHandle_Proxy(ISynchronizeHandle *,HANDLE *);
void ISynchronizeHandle_GetHandle_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ISynchronizeEvent_INTERFACE_DEFINED__
#define __ISynchronizeEvent_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISynchronizeEvent;
typedef struct ISynchronizeEventVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ISynchronizeEvent *,REFIID,void **);
	ULONG (*AddRef)(ISynchronizeEvent *);
	ULONG (*Release)(ISynchronizeEvent *);
	HRESULT(*GetHandle)(ISynchronizeEvent *,HANDLE *);
	HRESULT(*SetEventHandle)(ISynchronizeEvent *,HANDLE *);
END_INTERFACE
} ISynchronizeEventVtbl;
interface ISynchronizeEvent
{
CONST_VTBL struct ISynchronizeEventVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISynchronizeEvent_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISynchronizeEvent_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISynchronizeEvent_Release(A) (A)->lpVtbl->Release(A)
#define ISynchronizeEvent_GetHandle(A,B) (A)->lpVtbl->GetHandle(A,B)
#define ISynchronizeEvent_SetEventHandle(A,B) (A)->lpVtbl->SetEventHandle(A,B)
#endif 
HRESULT ISynchronizeEvent_SetEventHandle_Proxy(ISynchronizeEvent *,HANDLE *);
void ISynchronizeEvent_SetEventHandle_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ISynchronizeContainer_INTERFACE_DEFINED__
#define __ISynchronizeContainer_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISynchronizeContainer;
typedef struct ISynchronizeContainerVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ISynchronizeContainer *,REFIID,void **);
	ULONG (*AddRef)(ISynchronizeContainer *);
	ULONG (*Release)(ISynchronizeContainer *);
	HRESULT(*AddSynchronize)(ISynchronizeContainer *,ISynchronize *);
	HRESULT(*WaitMultiple)(ISynchronizeContainer *,DWORD,DWORD,ISynchronize **);
END_INTERFACE
} ISynchronizeContainerVtbl;
interface ISynchronizeContainer
{
CONST_VTBL struct ISynchronizeContainerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISynchronizeContainer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISynchronizeContainer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISynchronizeContainer_Release(A) (A)->lpVtbl->Release(A)
#define ISynchronizeContainer_AddSynchronize(A,B) (A)->lpVtbl->AddSynchronize(A,B)
#define ISynchronizeContainer_WaitMultiple(A,B,C,D) (A)->lpVtbl->WaitMultiple(A,B,C,D)
#endif 
HRESULT ISynchronizeContainer_AddSynchronize_Proxy(ISynchronizeContainer *,ISynchronize *);
void ISynchronizeContainer_AddSynchronize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISynchronizeContainer_WaitMultiple_Proxy(ISynchronizeContainer *,DWORD,DWORD,ISynchronize **);
void ISynchronizeContainer_WaitMultiple_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ISynchronizeMutex_INTERFACE_DEFINED__
#define __ISynchronizeMutex_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISynchronizeMutex;
typedef struct ISynchronizeMutexVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ISynchronizeMutex *,REFIID,void **);
	ULONG (*AddRef)(ISynchronizeMutex *);
	ULONG (*Release)(ISynchronizeMutex *);
	HRESULT(*Wait)(ISynchronizeMutex *,DWORD,DWORD);
	HRESULT(*Signal)(ISynchronizeMutex *);
	HRESULT(*Reset)(ISynchronizeMutex *);
	HRESULT(*ReleaseMutex)(ISynchronizeMutex *);
END_INTERFACE
} ISynchronizeMutexVtbl;
interface ISynchronizeMutex
{
CONST_VTBL struct ISynchronizeMutexVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISynchronizeMutex_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISynchronizeMutex_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISynchronizeMutex_Release(A) (A)->lpVtbl->Release(A)
#define ISynchronizeMutex_Wait(A,B,C) (A)->lpVtbl->Wait(A,B,C)
#define ISynchronizeMutex_Signal(A) (A)->lpVtbl->Signal(A)
#define ISynchronizeMutex_Reset(A) (A)->lpVtbl->Reset(A)
#define ISynchronizeMutex_ReleaseMutex(A) (A)->lpVtbl->ReleaseMutex(A)
#endif 
HRESULT ISynchronizeMutex_ReleaseMutex_Proxy(ISynchronizeMutex *);
void ISynchronizeMutex_ReleaseMutex_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ICancelMethodCalls_INTERFACE_DEFINED__
#define __ICancelMethodCalls_INTERFACE_DEFINED__
typedef ICancelMethodCalls *LPCANCELMETHODCALLS;
EXTERN_C const IID IID_ICancelMethodCalls;
typedef struct ICancelMethodCallsVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ICancelMethodCalls *,REFIID,void **);
	ULONG (*AddRef)(ICancelMethodCalls *);
	ULONG (*Release)(ICancelMethodCalls *);
	HRESULT(*Cancel)(ICancelMethodCalls *,ULONG);
	HRESULT(*TestCancel)(ICancelMethodCalls *);
END_INTERFACE
} ICancelMethodCallsVtbl;
interface ICancelMethodCalls
{
CONST_VTBL struct ICancelMethodCallsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICancelMethodCalls_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICancelMethodCalls_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICancelMethodCalls_Release(A) (A)->lpVtbl->Release(A)
#define ICancelMethodCalls_Cancel(A,B) (A)->lpVtbl->Cancel(A,B)
#define ICancelMethodCalls_TestCancel(A) (A)->lpVtbl->TestCancel(A)
#endif 
HRESULT ICancelMethodCalls_Cancel_Proxy(ICancelMethodCalls *,ULONG);
void ICancelMethodCalls_Cancel_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ICancelMethodCalls_TestCancel_Proxy(ICancelMethodCalls *);
void ICancelMethodCalls_TestCancel_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IAsyncManager_INTERFACE_DEFINED__
#define __IAsyncManager_INTERFACE_DEFINED__
typedef 
enum tagDCOM_CALL_STATE
{	DCOM_NONE=0,DCOM_CALL_COMPLETE=1,DCOM_CALL_CANCELED=2
} DCOM_CALL_STATE;
EXTERN_C const IID IID_IAsyncManager;
typedef struct IAsyncManagerVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IAsyncManager *,REFIID,void **);
	ULONG (*AddRef)(IAsyncManager *);
	ULONG (*Release)(IAsyncManager *);
	HRESULT(*CompleteCall)(IAsyncManager *,HRESULT);
	HRESULT(*GetCallContext)(IAsyncManager *,REFIID,void **);
	HRESULT(*GetState)(IAsyncManager *,ULONG *);
END_INTERFACE
} IAsyncManagerVtbl;
interface IAsyncManager
{
CONST_VTBL struct IAsyncManagerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IAsyncManager_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IAsyncManager_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IAsyncManager_Release(A) (A)->lpVtbl->Release(A)
#define IAsyncManager_CompleteCall(A,B) (A)->lpVtbl->CompleteCall(A,B)
#define IAsyncManager_GetCallContext(A,B,C) (A)->lpVtbl->GetCallContext(A,B,C)
#define IAsyncManager_GetState(A,B) (A)->lpVtbl->GetState(A,B)
#endif 
HRESULT IAsyncManager_CompleteCall_Proxy(IAsyncManager *,HRESULT);
void IAsyncManager_CompleteCall_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAsyncManager_GetCallContext_Proxy(IAsyncManager *,REFIID,void **);
void IAsyncManager_GetCallContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAsyncManager_GetState_Proxy(IAsyncManager *,ULONG *);
void IAsyncManager_GetState_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ICallFactory_INTERFACE_DEFINED__
#define __ICallFactory_INTERFACE_DEFINED__
EXTERN_C const IID IID_ICallFactory;
typedef struct ICallFactoryVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ICallFactory *,REFIID,void **);
	ULONG (*AddRef)(ICallFactory *);
	ULONG (*Release)(ICallFactory *);
	HRESULT(*CreateCall)(ICallFactory *,REFIID,IUnknown *,REFIID,IUnknown **);
END_INTERFACE
} ICallFactoryVtbl;
interface ICallFactory
{
CONST_VTBL struct ICallFactoryVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICallFactory_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICallFactory_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICallFactory_Release(A) (A)->lpVtbl->Release(A)
#define ICallFactory_CreateCall(A,B,C,D,E) (A)->lpVtbl->CreateCall(A,B,C,D,E)
#endif 
HRESULT ICallFactory_CreateCall_Proxy(ICallFactory *,REFIID,IUnknown *,REFIID,IUnknown **);
void ICallFactory_CreateCall_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IRpcHelper_INTERFACE_DEFINED__
#define __IRpcHelper_INTERFACE_DEFINED__
EXTERN_C const IID IID_IRpcHelper;
typedef struct IRpcHelperVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IRpcHelper *,REFIID,void **);
	ULONG (*AddRef)(IRpcHelper *);
	ULONG (*Release)(IRpcHelper *);
	HRESULT(*GetDCOMProtocolVersion)(IRpcHelper *,DWORD *);
	HRESULT(*GetIIDFromOBJREF)(IRpcHelper *,void *,IID **);
END_INTERFACE
} IRpcHelperVtbl;
interface IRpcHelper
{
CONST_VTBL struct IRpcHelperVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRpcHelper_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRpcHelper_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRpcHelper_Release(A) (A)->lpVtbl->Release(A)
#define IRpcHelper_GetDCOMProtocolVersion(A,B) (A)->lpVtbl->GetDCOMProtocolVersion(A,B)
#define IRpcHelper_GetIIDFromOBJREF(A,B,C) (A)->lpVtbl->GetIIDFromOBJREF(A,B,C)
#endif 
HRESULT IRpcHelper_GetDCOMProtocolVersion_Proxy(IRpcHelper *,DWORD *);
void IRpcHelper_GetDCOMProtocolVersion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IRpcHelper_GetIIDFromOBJREF_Proxy(IRpcHelper *,void *,IID **);
void IRpcHelper_GetIIDFromOBJREF_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IReleaseMarshalBuffers_INTERFACE_DEFINED__
#define __IReleaseMarshalBuffers_INTERFACE_DEFINED__
EXTERN_C const IID IID_IReleaseMarshalBuffers;
typedef struct IReleaseMarshalBuffersVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IReleaseMarshalBuffers *,REFIID,void **);
	ULONG (*AddRef)(IReleaseMarshalBuffers *);
	ULONG (*Release)(IReleaseMarshalBuffers *);
	HRESULT(*ReleaseMarshalBuffer)(IReleaseMarshalBuffers *,RPCOLEMESSAGE *,DWORD,IUnknown *);
END_INTERFACE
} IReleaseMarshalBuffersVtbl;
interface IReleaseMarshalBuffers
{
CONST_VTBL struct IReleaseMarshalBuffersVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IReleaseMarshalBuffers_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IReleaseMarshalBuffers_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IReleaseMarshalBuffers_Release(A) (A)->lpVtbl->Release(A)
#define IReleaseMarshalBuffers_ReleaseMarshalBuffer(A,B,C,D) (A)->lpVtbl->ReleaseMarshalBuffer(A,B,C,D)
#endif 
HRESULT IReleaseMarshalBuffers_ReleaseMarshalBuffer_Proxy(IReleaseMarshalBuffers *,RPCOLEMESSAGE *,DWORD,IUnknown *);
void IReleaseMarshalBuffers_ReleaseMarshalBuffer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IWaitMultiple_INTERFACE_DEFINED__
#define __IWaitMultiple_INTERFACE_DEFINED__
EXTERN_C const IID IID_IWaitMultiple;
typedef struct IWaitMultipleVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IWaitMultiple *,REFIID,void **);
	ULONG (*AddRef)(IWaitMultiple *);
	ULONG (*Release)(IWaitMultiple *);
	HRESULT(*WaitMultiple)(IWaitMultiple *,DWORD,ISynchronize **);
	HRESULT(*AddSynchronize)(IWaitMultiple *,ISynchronize *);
END_INTERFACE
} IWaitMultipleVtbl;
interface IWaitMultiple
{
CONST_VTBL struct IWaitMultipleVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWaitMultiple_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWaitMultiple_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWaitMultiple_Release(A) (A)->lpVtbl->Release(A)
#define IWaitMultiple_WaitMultiple(A,B,C) (A)->lpVtbl->WaitMultiple(A,B,C)
#define IWaitMultiple_AddSynchronize(A,B) (A)->lpVtbl->AddSynchronize(A,B)
#endif 
HRESULT IWaitMultiple_WaitMultiple_Proxy(IWaitMultiple *,DWORD,ISynchronize **);
void IWaitMultiple_WaitMultiple_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IWaitMultiple_AddSynchronize_Proxy(IWaitMultiple *,ISynchronize *);
void IWaitMultiple_AddSynchronize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IUrlMon_INTERFACE_DEFINED__
#define __IUrlMon_INTERFACE_DEFINED__
EXTERN_C const IID IID_IUrlMon;
typedef struct IUrlMonVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IUrlMon *,REFIID,void **);
	ULONG (*AddRef)(IUrlMon *);
	ULONG (*Release)(IUrlMon *);
	HRESULT(*AsyncGetClassBits)(IUrlMon *,REFCLSID,LPCWSTR,LPCWSTR,DWORD,DWORD,LPCWSTR,IBindCtx *,DWORD,REFIID,DWORD);
END_INTERFACE
} IUrlMonVtbl;
interface IUrlMon
{
CONST_VTBL struct IUrlMonVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IUrlMon_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IUrlMon_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IUrlMon_Release(A) (A)->lpVtbl->Release(A)
#define IUrlMon_AsyncGetClassBits(A,B,C,D,E,F,G,H,I,J,K) (A)->lpVtbl->AsyncGetClassBits(A,B,C,D,E,F,G,H,I,J,K)
#endif 
HRESULT IUrlMon_AsyncGetClassBits_Proxy(IUrlMon *,REFCLSID,LPCWSTR,LPCWSTR,DWORD,DWORD,LPCWSTR,IBindCtx *,DWORD,REFIID,DWORD);
void IUrlMon_AsyncGetClassBits_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IForegroundTransfer_INTERFACE_DEFINED__
#define __IForegroundTransfer_INTERFACE_DEFINED__
EXTERN_C const IID IID_IForegroundTransfer;
typedef struct IForegroundTransferVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IForegroundTransfer *,REFIID,void **);
	ULONG (*AddRef)(IForegroundTransfer *);
	ULONG (*Release)(IForegroundTransfer *);
	HRESULT(*AllowForegroundTransfer)(IForegroundTransfer *,void *);
END_INTERFACE
} IForegroundTransferVtbl;
interface IForegroundTransfer
{
CONST_VTBL struct IForegroundTransferVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IForegroundTransfer_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IForegroundTransfer_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IForegroundTransfer_Release(A) (A)->lpVtbl->Release(A)
#define IForegroundTransfer_AllowForegroundTransfer(A,B) (A)->lpVtbl->AllowForegroundTransfer(A,B)
#endif 
HRESULT IForegroundTransfer_AllowForegroundTransfer_Proxy(IForegroundTransfer *,void *);
void IForegroundTransfer_AllowForegroundTransfer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IAddrTrackingControl_INTERFACE_DEFINED__
#define __IAddrTrackingControl_INTERFACE_DEFINED__
typedef IAddrTrackingControl *LPADDRTRACKINGCONTROL;
EXTERN_C const IID IID_IAddrTrackingControl;
typedef struct IAddrTrackingControlVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IAddrTrackingControl *,REFIID,void **);
	ULONG (*AddRef)(IAddrTrackingControl *);
	ULONG (*Release)(IAddrTrackingControl *);
	HRESULT(*EnableCOMDynamicAddrTracking)(IAddrTrackingControl *);
	HRESULT(*DisableCOMDynamicAddrTracking)(IAddrTrackingControl *);
END_INTERFACE
} IAddrTrackingControlVtbl;
interface IAddrTrackingControl
{
CONST_VTBL struct IAddrTrackingControlVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IAddrTrackingControl_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IAddrTrackingControl_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IAddrTrackingControl_Release(A) (A)->lpVtbl->Release(A)
#define IAddrTrackingControl_EnableCOMDynamicAddrTracking(A) (A)->lpVtbl->EnableCOMDynamicAddrTracking(A)
#define IAddrTrackingControl_DisableCOMDynamicAddrTracking(A) (A)->lpVtbl->DisableCOMDynamicAddrTracking(A)
#endif 
HRESULT IAddrTrackingControl_EnableCOMDynamicAddrTracking_Proxy(IAddrTrackingControl *);
void IAddrTrackingControl_EnableCOMDynamicAddrTracking_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAddrTrackingControl_DisableCOMDynamicAddrTracking_Proxy(IAddrTrackingControl *);
void IAddrTrackingControl_DisableCOMDynamicAddrTracking_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IAddrExclusionControl_INTERFACE_DEFINED__
#define __IAddrExclusionControl_INTERFACE_DEFINED__
typedef IAddrExclusionControl *LPADDREXCLUSIONCONTROL;
EXTERN_C const IID IID_IAddrExclusionControl;
typedef struct IAddrExclusionControlVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IAddrExclusionControl *,REFIID,void **);
	ULONG (*AddRef)(IAddrExclusionControl *);
	ULONG (*Release)(IAddrExclusionControl *);
	HRESULT(*GetCurrentAddrExclusionList)(IAddrExclusionControl *,REFIID,void **);
	HRESULT(*UpdateAddrExclusionList)(IAddrExclusionControl *,IUnknown *);
END_INTERFACE
} IAddrExclusionControlVtbl;
interface IAddrExclusionControl
{
CONST_VTBL struct IAddrExclusionControlVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IAddrExclusionControl_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IAddrExclusionControl_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IAddrExclusionControl_Release(A) (A)->lpVtbl->Release(A)
#define IAddrExclusionControl_GetCurrentAddrExclusionList(A,B,C) (A)->lpVtbl->GetCurrentAddrExclusionList(A,B,C)
#define IAddrExclusionControl_UpdateAddrExclusionList(A,B) (A)->lpVtbl->UpdateAddrExclusionList(A,B)
#endif 
HRESULT IAddrExclusionControl_GetCurrentAddrExclusionList_Proxy(IAddrExclusionControl *,REFIID,void **);
void IAddrExclusionControl_GetCurrentAddrExclusionList_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IAddrExclusionControl_UpdateAddrExclusionList_Proxy(IAddrExclusionControl *,IUnknown *);
void IAddrExclusionControl_UpdateAddrExclusionList_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IPipeByte_INTERFACE_DEFINED__
#define __IPipeByte_INTERFACE_DEFINED__
EXTERN_C const IID IID_IPipeByte;
typedef struct IPipeByteVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IPipeByte *,REFIID,void **);
	ULONG (*AddRef)(IPipeByte *);
	ULONG (*Release)(IPipeByte *);
	HRESULT(*Pull)(IPipeByte *,BYTE *,ULONG,ULONG *);
	HRESULT(*Push)(IPipeByte *,BYTE *,ULONG);
END_INTERFACE
} IPipeByteVtbl;
interface IPipeByte
{
CONST_VTBL struct IPipeByteVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPipeByte_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPipeByte_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPipeByte_Release(A) (A)->lpVtbl->Release(A)
#define IPipeByte_Pull(A,B,C,D) (A)->lpVtbl->Pull(A,B,C,D)
#define IPipeByte_Push(A,B,C) (A)->lpVtbl->Push(A,B,C)
#endif 
HRESULT IPipeByte_Pull_Proxy(IPipeByte *,BYTE *,ULONG,ULONG *);
void IPipeByte_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPipeByte_Push_Proxy(IPipeByte *,BYTE *,ULONG);
void IPipeByte_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __AsyncIPipeByte_INTERFACE_DEFINED__
#define __AsyncIPipeByte_INTERFACE_DEFINED__
EXTERN_C const IID IID_AsyncIPipeByte;
typedef struct AsyncIPipeByteVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(AsyncIPipeByte *,REFIID,void **);
	ULONG (*AddRef)(AsyncIPipeByte *);
	ULONG (*Release)(AsyncIPipeByte *);
	HRESULT(*Begin_Pull)(AsyncIPipeByte *,ULONG);
	HRESULT(*Finish_Pull)(AsyncIPipeByte *,BYTE *,ULONG *);
	HRESULT(*Begin_Push)(AsyncIPipeByte *,BYTE *,ULONG);
	HRESULT(*Finish_Push)(AsyncIPipeByte *);
END_INTERFACE
} AsyncIPipeByteVtbl;
interface AsyncIPipeByte
{
CONST_VTBL struct AsyncIPipeByteVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define AsyncIPipeByte_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define AsyncIPipeByte_AddRef(A) (A)->lpVtbl->AddRef(A)
#define AsyncIPipeByte_Release(A) (A)->lpVtbl->Release(A)
#define AsyncIPipeByte_Begin_Pull(A,B) (A)->lpVtbl->Begin_Pull(A,B)
#define AsyncIPipeByte_Finish_Pull(A,B,C) (A)->lpVtbl->Finish_Pull(A,B,C)
#define AsyncIPipeByte_Begin_Push(A,B,C) (A)->lpVtbl->Begin_Push(A,B,C)
#define AsyncIPipeByte_Finish_Push(A) (A)->lpVtbl->Finish_Push(A)
#endif 
HRESULT AsyncIPipeByte_Begin_Pull_Proxy(AsyncIPipeByte *,ULONG);
void AsyncIPipeByte_Begin_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeByte_Finish_Pull_Proxy(AsyncIPipeByte *,BYTE *,ULONG *);
void AsyncIPipeByte_Finish_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeByte_Begin_Push_Proxy(AsyncIPipeByte *,BYTE *,ULONG);
void AsyncIPipeByte_Begin_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeByte_Finish_Push_Proxy(AsyncIPipeByte *);
void AsyncIPipeByte_Finish_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IPipeLong_INTERFACE_DEFINED__
#define __IPipeLong_INTERFACE_DEFINED__
EXTERN_C const IID IID_IPipeLong;
typedef struct IPipeLongVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IPipeLong *,REFIID,void **);
	ULONG (*AddRef)(IPipeLong *);
	ULONG (*Release)(IPipeLong *);
	HRESULT(*Pull)(IPipeLong *,LONG *,ULONG,ULONG *);
	HRESULT(*Push)(IPipeLong *,LONG *,ULONG);
END_INTERFACE
} IPipeLongVtbl;
interface IPipeLong
{
CONST_VTBL struct IPipeLongVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPipeLong_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPipeLong_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPipeLong_Release(A) (A)->lpVtbl->Release(A)
#define IPipeLong_Pull(A,B,C,D) (A)->lpVtbl->Pull(A,B,C,D)
#define IPipeLong_Push(A,B,C) (A)->lpVtbl->Push(A,B,C)
#endif 
HRESULT IPipeLong_Pull_Proxy(IPipeLong *,LONG *,ULONG,ULONG *);
void IPipeLong_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPipeLong_Push_Proxy(IPipeLong *,LONG *,ULONG);
void IPipeLong_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __AsyncIPipeLong_INTERFACE_DEFINED__
#define __AsyncIPipeLong_INTERFACE_DEFINED__
EXTERN_C const IID IID_AsyncIPipeLong;
typedef struct AsyncIPipeLongVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(AsyncIPipeLong *,REFIID,void **);
	ULONG (*AddRef)(AsyncIPipeLong *);
	ULONG (*Release)(AsyncIPipeLong *);
	HRESULT(*Begin_Pull)(AsyncIPipeLong *,ULONG);
	HRESULT(*Finish_Pull)(AsyncIPipeLong *,LONG *,ULONG *);
	HRESULT(*Begin_Push)(AsyncIPipeLong *,LONG *,ULONG);
	HRESULT(*Finish_Push)(AsyncIPipeLong *);
END_INTERFACE
} AsyncIPipeLongVtbl;
interface AsyncIPipeLong
{
CONST_VTBL struct AsyncIPipeLongVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define AsyncIPipeLong_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define AsyncIPipeLong_AddRef(A) (A)->lpVtbl->AddRef(A)
#define AsyncIPipeLong_Release(A) (A)->lpVtbl->Release(A)
#define AsyncIPipeLong_Begin_Pull(A,B) (A)->lpVtbl->Begin_Pull(A,B)
#define AsyncIPipeLong_Finish_Pull(A,B,C) (A)->lpVtbl->Finish_Pull(A,B,C)
#define AsyncIPipeLong_Begin_Push(A,B,C) (A)->lpVtbl->Begin_Push(A,B,C)
#define AsyncIPipeLong_Finish_Push(A) (A)->lpVtbl->Finish_Push(A)
#endif 
HRESULT AsyncIPipeLong_Begin_Pull_Proxy(AsyncIPipeLong *,ULONG);
void AsyncIPipeLong_Begin_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeLong_Finish_Pull_Proxy(AsyncIPipeLong *,LONG *,ULONG *);
void AsyncIPipeLong_Finish_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeLong_Begin_Push_Proxy(AsyncIPipeLong *,LONG *,ULONG);
void AsyncIPipeLong_Begin_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeLong_Finish_Push_Proxy(AsyncIPipeLong *);
void AsyncIPipeLong_Finish_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IPipeDouble_INTERFACE_DEFINED__
#define __IPipeDouble_INTERFACE_DEFINED__
EXTERN_C const IID IID_IPipeDouble;
typedef struct IPipeDoubleVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IPipeDouble *,REFIID,void **);
	ULONG (*AddRef)(IPipeDouble *);
	ULONG (*Release)(IPipeDouble *);
	HRESULT(*Pull)(IPipeDouble *,DOUBLE *,ULONG,ULONG *);
	HRESULT(*Push)(IPipeDouble *,DOUBLE *,ULONG);
END_INTERFACE
} IPipeDoubleVtbl;
interface IPipeDouble
{
CONST_VTBL struct IPipeDoubleVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPipeDouble_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPipeDouble_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPipeDouble_Release(A) (A)->lpVtbl->Release(A)
#define IPipeDouble_Pull(A,B,C,D) (A)->lpVtbl->Pull(A,B,C,D)
#define IPipeDouble_Push(A,B,C) (A)->lpVtbl->Push(A,B,C)
#endif 
HRESULT IPipeDouble_Pull_Proxy(IPipeDouble *,DOUBLE *,ULONG,ULONG *);
void IPipeDouble_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IPipeDouble_Push_Proxy(IPipeDouble *,DOUBLE *,ULONG);
void IPipeDouble_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __AsyncIPipeDouble_INTERFACE_DEFINED__
#define __AsyncIPipeDouble_INTERFACE_DEFINED__
EXTERN_C const IID IID_AsyncIPipeDouble;
typedef struct AsyncIPipeDoubleVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(AsyncIPipeDouble *,REFIID,void **);
	ULONG (*AddRef)(AsyncIPipeDouble *);
	ULONG (*Release)(AsyncIPipeDouble *);
	HRESULT(*Begin_Pull)(AsyncIPipeDouble *,ULONG);
	HRESULT(*Finish_Pull)(AsyncIPipeDouble *,DOUBLE *,ULONG *);
	HRESULT(*Begin_Push)(AsyncIPipeDouble *,DOUBLE *,ULONG);
	HRESULT(*Finish_Push)(AsyncIPipeDouble *);
END_INTERFACE
} AsyncIPipeDoubleVtbl;
interface AsyncIPipeDouble
{
CONST_VTBL struct AsyncIPipeDoubleVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define AsyncIPipeDouble_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define AsyncIPipeDouble_AddRef(A) (A)->lpVtbl->AddRef(A)
#define AsyncIPipeDouble_Release(A) (A)->lpVtbl->Release(A)
#define AsyncIPipeDouble_Begin_Pull(A,B) (A)->lpVtbl->Begin_Pull(A,B)
#define AsyncIPipeDouble_Finish_Pull(A,B,C) (A)->lpVtbl->Finish_Pull(A,B,C)
#define AsyncIPipeDouble_Begin_Push(A,B,C) (A)->lpVtbl->Begin_Push(A,B,C)
#define AsyncIPipeDouble_Finish_Push(A) (A)->lpVtbl->Finish_Push(A)
#endif 
HRESULT AsyncIPipeDouble_Begin_Pull_Proxy(AsyncIPipeDouble *,ULONG);
void AsyncIPipeDouble_Begin_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeDouble_Finish_Pull_Proxy(AsyncIPipeDouble *,DOUBLE *,ULONG *);
void AsyncIPipeDouble_Finish_Pull_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeDouble_Begin_Push_Proxy(AsyncIPipeDouble *,DOUBLE *,ULONG);
void AsyncIPipeDouble_Begin_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT AsyncIPipeDouble_Finish_Push_Proxy(AsyncIPipeDouble *);
void AsyncIPipeDouble_Finish_Push_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IThumbnailExtractor_INTERFACE_DEFINED__
#define __IThumbnailExtractor_INTERFACE_DEFINED__
EXTERN_C const IID IID_IThumbnailExtractor;
typedef struct IThumbnailExtractorVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IThumbnailExtractor *,REFIID,void **);
	ULONG (*AddRef)(IThumbnailExtractor *);
	ULONG (*Release)(IThumbnailExtractor *);
	HRESULT(*ExtractThumbnail)(IThumbnailExtractor *,IStorage *,ULONG,ULONG,ULONG *,ULONG *,HBITMAP *);
	HRESULT(*OnFileUpdated)(IThumbnailExtractor *,IStorage *);
END_INTERFACE
} IThumbnailExtractorVtbl;
interface IThumbnailExtractor
{
CONST_VTBL struct IThumbnailExtractorVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IThumbnailExtractor_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IThumbnailExtractor_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IThumbnailExtractor_Release(A) (A)->lpVtbl->Release(A)
#define IThumbnailExtractor_ExtractThumbnail(A,B,C,D,E,F,G) (A)->lpVtbl->ExtractThumbnail(A,B,C,D,E,F,G)
#define IThumbnailExtractor_OnFileUpdated(A,B) (A)->lpVtbl->OnFileUpdated(A,B)
#endif 
HRESULT IThumbnailExtractor_ExtractThumbnail_Proxy(IThumbnailExtractor *,IStorage *,ULONG,ULONG,ULONG *,ULONG *,HBITMAP *);
void IThumbnailExtractor_ExtractThumbnail_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IThumbnailExtractor_OnFileUpdated_Proxy(IThumbnailExtractor *,IStorage *);
void IThumbnailExtractor_OnFileUpdated_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IDummyHICONIncluder_INTERFACE_DEFINED__
#define __IDummyHICONIncluder_INTERFACE_DEFINED__
EXTERN_C const IID IID_IDummyHICONIncluder;
typedef struct IDummyHICONIncluderVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IDummyHICONIncluder *,REFIID,void **);
	ULONG (*AddRef)(IDummyHICONIncluder *);
	ULONG (*Release)(IDummyHICONIncluder *);
	HRESULT(*Dummy)(IDummyHICONIncluder *,HICON,HDC);
END_INTERFACE
} IDummyHICONIncluderVtbl;
interface IDummyHICONIncluder
{
CONST_VTBL struct IDummyHICONIncluderVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IDummyHICONIncluder_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IDummyHICONIncluder_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IDummyHICONIncluder_Release(A) (A)->lpVtbl->Release(A)
#define IDummyHICONIncluder_Dummy(A,B,C) (A)->lpVtbl->Dummy(A,B,C)
#endif 
HRESULT IDummyHICONIncluder_Dummy_Proxy(IDummyHICONIncluder *,HICON,HDC);
void IDummyHICONIncluder_Dummy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#if defined USE_COM_CONTEXT_DEF || defined BUILDTYPE_COMSVCS || defined _OLE32_
typedef DWORD CPFLAGS;
typedef struct tagContextProperty
{
GUID policyId;
CPFLAGS flags;
IUnknown *pUnk;
} ContextProperty;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0084_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0084_v0_0_s_ifspec;
#ifndef __IEnumContextProps_INTERFACE_DEFINED__
#define __IEnumContextProps_INTERFACE_DEFINED__
typedef IEnumContextProps *LPENUMCONTEXTPROPS;
EXTERN_C const IID IID_IEnumContextProps;
typedef struct IEnumContextPropsVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IEnumContextProps *,REFIID,void **);
	ULONG (*AddRef)(IEnumContextProps *);
	ULONG (*Release)(IEnumContextProps *);
	HRESULT(*Next)(IEnumContextProps *,ULONG,ContextProperty *,ULONG *);
	HRESULT(*Skip)(IEnumContextProps *,ULONG);
	HRESULT(*Reset)(IEnumContextProps *);
	HRESULT(*Clone)(IEnumContextProps *,IEnumContextProps **);
	HRESULT(*Count)(IEnumContextProps *,ULONG *);
END_INTERFACE
} IEnumContextPropsVtbl;
interface IEnumContextProps
{
CONST_VTBL struct IEnumContextPropsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumContextProps_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumContextProps_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumContextProps_Release(A) (A)->lpVtbl->Release(A)
#define IEnumContextProps_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumContextProps_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumContextProps_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumContextProps_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#define IEnumContextProps_Count(A,B) (A)->lpVtbl->Count(A,B)
#endif 
HRESULT IEnumContextProps_Next_Proxy(IEnumContextProps *,ULONG,ContextProperty *,ULONG *);
void IEnumContextProps_Next_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumContextProps_Skip_Proxy(IEnumContextProps *,ULONG);
void IEnumContextProps_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumContextProps_Reset_Proxy(IEnumContextProps *);
void IEnumContextProps_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumContextProps_Clone_Proxy(IEnumContextProps *,IEnumContextProps **);
void IEnumContextProps_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IEnumContextProps_Count_Proxy(IEnumContextProps *,ULONG *);
void IEnumContextProps_Count_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IContext_INTERFACE_DEFINED__
#define __IContext_INTERFACE_DEFINED__
EXTERN_C const IID IID_IContext;
typedef struct IContextVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IContext *,REFIID,void **);
	ULONG (*AddRef)(IContext *);
	ULONG (*Release)(IContext *);
	HRESULT(*SetProperty)(IContext *,REFGUID,CPFLAGS,IUnknown *);
	HRESULT(*RemoveProperty)(IContext *,REFGUID);
	HRESULT(*GetProperty)(IContext *,REFGUID,CPFLAGS *,IUnknown **);
	HRESULT(*EnumContextProps)(IContext *,IEnumContextProps **);
END_INTERFACE
} IContextVtbl;
interface IContext
{
CONST_VTBL struct IContextVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IContext_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IContext_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IContext_Release(A) (A)->lpVtbl->Release(A)
#define IContext_SetProperty(A,B,C,D) (A)->lpVtbl->SetProperty(A,B,C,D)
#define IContext_RemoveProperty(A,B) (A)->lpVtbl->RemoveProperty(A,B)
#define IContext_GetProperty(A,B,C,D) (A)->lpVtbl->GetProperty(A,B,C,D)
#define IContext_EnumContextProps(A,B) (A)->lpVtbl->EnumContextProps(A,B)
#endif 
HRESULT IContext_SetProperty_Proxy(IContext *,REFGUID,CPFLAGS,IUnknown *);
void IContext_SetProperty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IContext_RemoveProperty_Proxy(IContext *,REFGUID);
void IContext_RemoveProperty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IContext_GetProperty_Proxy(IContext *,REFGUID,CPFLAGS *,IUnknown **);
void IContext_GetProperty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IContext_EnumContextProps_Proxy(IContext *,IEnumContextProps **);
void IContext_EnumContextProps_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#if !defined BUILDTYPE_COMSVCS && !defined _OLE32_
extern RPC_IF_HANDLE __MIDL_itf_objidl_0086_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0086_v0_0_s_ifspec;
#ifndef __IObjContext_INTERFACE_DEFINED__
#define __IObjContext_INTERFACE_DEFINED__
EXTERN_C const IID IID_IObjContext;
typedef struct IObjContextVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IObjContext *,REFIID,void **);
	ULONG (*AddRef)(IObjContext *);
	ULONG (*Release)(IObjContext *);
	HRESULT(*SetProperty)(IObjContext *,REFGUID,CPFLAGS,IUnknown *);
	HRESULT(*RemoveProperty)(IObjContext *,REFGUID);
	HRESULT(*GetProperty)(IObjContext *,REFGUID,CPFLAGS *,IUnknown **);
	HRESULT(*EnumContextProps)(IObjContext *,IEnumContextProps **);
	void (*Reserved1)(IObjContext *);
	void (*Reserved2)(IObjContext *);
	void (*Reserved3)(IObjContext *);
	void (*Reserved4)(IObjContext *);
	void (*Reserved5)(IObjContext *);
	void (*Reserved6)(IObjContext *);
	void (*Reserved7)(IObjContext *);
END_INTERFACE
} IObjContextVtbl;
interface IObjContext
{
CONST_VTBL struct IObjContextVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IObjContext_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IObjContext_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IObjContext_Release(A) (A)->lpVtbl->Release(A)
#define IObjContext_SetProperty(A,B,C,D) (A)->lpVtbl->SetProperty(A,B,C,D)
#define IObjContext_RemoveProperty(A,B) (A)->lpVtbl->RemoveProperty(A,B)
#define IObjContext_GetProperty(A,B,C,D) (A)->lpVtbl->GetProperty(A,B,C,D)
#define IObjContext_EnumContextProps(A,B) (A)->lpVtbl->EnumContextProps(A,B)
#define IObjContext_Reserved1(A) (A)->lpVtbl->Reserved1(A)
#define IObjContext_Reserved2(A) (A)->lpVtbl->Reserved2(A)
#define IObjContext_Reserved3(A) (A)->lpVtbl->Reserved3(A)
#define IObjContext_Reserved4(A) (A)->lpVtbl->Reserved4(A)
#define IObjContext_Reserved5(A) (A)->lpVtbl->Reserved5(A)
#define IObjContext_Reserved6(A) (A)->lpVtbl->Reserved6(A)
#define IObjContext_Reserved7(A) (A)->lpVtbl->Reserved7(A)
#endif 
void IObjContext_Reserved1_Proxy(IObjContext *);
void IObjContext_Reserved1_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IObjContext_Reserved2_Proxy(IObjContext *);
void IObjContext_Reserved2_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IObjContext_Reserved3_Proxy(IObjContext *);
void IObjContext_Reserved3_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IObjContext_Reserved4_Proxy(IObjContext *);
void IObjContext_Reserved4_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IObjContext_Reserved5_Proxy(IObjContext *);
void IObjContext_Reserved5_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IObjContext_Reserved6_Proxy(IObjContext *);
void IObjContext_Reserved6_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
void IObjContext_Reserved7_Proxy(IObjContext *);
void IObjContext_Reserved7_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#endif
#endif
typedef 
enum tagApplicationType
{	ServerApplication=0,LibraryApplication=ServerApplication + 1
} ApplicationType;
typedef 
enum tagShutdownType
{	IdleShutdown=0,ForcedShutdown=IdleShutdown + 1
} ShutdownType;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0087_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0087_v0_0_s_ifspec;
#ifndef __IProcessLock_INTERFACE_DEFINED__
#define __IProcessLock_INTERFACE_DEFINED__
EXTERN_C const IID IID_IProcessLock;
typedef struct IProcessLockVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IProcessLock *,REFIID,void **);
	ULONG (*AddRef)(IProcessLock *);
	ULONG (*Release)(IProcessLock *);
	ULONG (*AddRefOnProcess)(IProcessLock *);
	ULONG (*ReleaseRefOnProcess)(IProcessLock *);
END_INTERFACE
} IProcessLockVtbl;
interface IProcessLock
{
CONST_VTBL struct IProcessLockVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IProcessLock_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IProcessLock_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IProcessLock_Release(A) (A)->lpVtbl->Release(A)
#define IProcessLock_AddRefOnProcess(A) (A)->lpVtbl->AddRefOnProcess(A)
#define IProcessLock_ReleaseRefOnProcess(A) (A)->lpVtbl->ReleaseRefOnProcess(A)
#endif 
ULONG IProcessLock_AddRefOnProcess_Proxy(IProcessLock *);
void IProcessLock_AddRefOnProcess_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
ULONG IProcessLock_ReleaseRefOnProcess_Proxy(IProcessLock *);
void IProcessLock_ReleaseRefOnProcess_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __ISurrogateService_INTERFACE_DEFINED__
#define __ISurrogateService_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISurrogateService;
typedef struct ISurrogateServiceVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(ISurrogateService *,REFIID,void **);
	ULONG (*AddRef)(ISurrogateService *);
	ULONG (*Release)(ISurrogateService *);
	HRESULT(*Init)(ISurrogateService *,REFGUID,IProcessLock *,BOOL *);
	HRESULT(*ApplicationLaunch)(ISurrogateService *,REFGUID,ApplicationType);
	HRESULT(*ApplicationFree)(ISurrogateService *,REFGUID);
	HRESULT(*CatalogRefresh)(ISurrogateService *,ULONG);
	HRESULT(*ProcessShutdown)(ISurrogateService *,ShutdownType);
END_INTERFACE
} ISurrogateServiceVtbl;
interface ISurrogateService
{
CONST_VTBL struct ISurrogateServiceVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISurrogateService_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISurrogateService_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISurrogateService_Release(A) (A)->lpVtbl->Release(A)
#define ISurrogateService_Init(A,B,C,D) (A)->lpVtbl->Init(A,B,C,D)
#define ISurrogateService_ApplicationLaunch(A,B,C) (A)->lpVtbl->ApplicationLaunch(A,B,C)
#define ISurrogateService_ApplicationFree(A,B) (A)->lpVtbl->ApplicationFree(A,B)
#define ISurrogateService_CatalogRefresh(A,B) (A)->lpVtbl->CatalogRefresh(A,B)
#define ISurrogateService_ProcessShutdown(A,B) (A)->lpVtbl->ProcessShutdown(A,B)
#endif 
HRESULT ISurrogateService_Init_Proxy(ISurrogateService *,REFGUID,IProcessLock *,BOOL *);
void ISurrogateService_Init_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISurrogateService_ApplicationLaunch_Proxy(ISurrogateService *,REFGUID,ApplicationType);
void ISurrogateService_ApplicationLaunch_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISurrogateService_ApplicationFree_Proxy(ISurrogateService *,REFGUID);
void ISurrogateService_ApplicationFree_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISurrogateService_CatalogRefresh_Proxy(ISurrogateService *,ULONG);
void ISurrogateService_CatalogRefresh_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT ISurrogateService_ProcessShutdown_Proxy(ISurrogateService *,ShutdownType);
void ISurrogateService_ProcessShutdown_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
typedef 
enum _APTTYPE
{	APTTYPE_CURRENT=-1,APTTYPE_STA=0,APTTYPE_MTA=1,APTTYPE_NA=2,APTTYPE_MAINSTA=3
} APTTYPE;
typedef 
enum _THDTYPE
{	THDTYPE_BLOCKMESSAGES=0,THDTYPE_PROCESSMESSAGES=1
} THDTYPE;
typedef DWORD APARTMENTID;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0089_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0089_v0_0_s_ifspec;
#ifndef __IComThreadingInfo_INTERFACE_DEFINED__
#define __IComThreadingInfo_INTERFACE_DEFINED__
EXTERN_C const IID IID_IComThreadingInfo;
typedef struct IComThreadingInfoVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IComThreadingInfo *,REFIID,void **);
	ULONG (*AddRef)(IComThreadingInfo *);
	ULONG (*Release)(IComThreadingInfo *);
	HRESULT(*GetCurrentApartmentType)(IComThreadingInfo *,APTTYPE *);
	HRESULT(*GetCurrentThreadType)(IComThreadingInfo *,THDTYPE *);
	HRESULT(*GetCurrentLogicalThreadId)(IComThreadingInfo *,GUID *);
	HRESULT(*SetCurrentLogicalThreadId)(IComThreadingInfo *,REFGUID);
END_INTERFACE
} IComThreadingInfoVtbl;
interface IComThreadingInfo
{
CONST_VTBL struct IComThreadingInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IComThreadingInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IComThreadingInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IComThreadingInfo_Release(A) (A)->lpVtbl->Release(A)
#define IComThreadingInfo_GetCurrentApartmentType(A,B) (A)->lpVtbl->GetCurrentApartmentType(A,B)
#define IComThreadingInfo_GetCurrentThreadType(A,B) (A)->lpVtbl->GetCurrentThreadType(A,B)
#define IComThreadingInfo_GetCurrentLogicalThreadId(A,B) (A)->lpVtbl->GetCurrentLogicalThreadId(A,B)
#define IComThreadingInfo_SetCurrentLogicalThreadId(A,B) (A)->lpVtbl->SetCurrentLogicalThreadId(A,B)
#endif 
HRESULT IComThreadingInfo_GetCurrentApartmentType_Proxy(IComThreadingInfo *,APTTYPE *);
void IComThreadingInfo_GetCurrentApartmentType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IComThreadingInfo_GetCurrentThreadType_Proxy(IComThreadingInfo *,THDTYPE *);
void IComThreadingInfo_GetCurrentThreadType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IComThreadingInfo_GetCurrentLogicalThreadId_Proxy(IComThreadingInfo *,GUID *);
void IComThreadingInfo_GetCurrentLogicalThreadId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IComThreadingInfo_SetCurrentLogicalThreadId_Proxy(IComThreadingInfo *,REFGUID);
void IComThreadingInfo_SetCurrentLogicalThreadId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#ifndef __IProcessInitControl_INTERFACE_DEFINED__
#define __IProcessInitControl_INTERFACE_DEFINED__
EXTERN_C const IID IID_IProcessInitControl;
typedef struct IProcessInitControlVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IProcessInitControl *,REFIID,void **);
	ULONG (*AddRef)(IProcessInitControl *);
	ULONG (*Release)(IProcessInitControl *);
	HRESULT(*ResetInitializerTimeout)(IProcessInitControl *,DWORD);
END_INTERFACE
} IProcessInitControlVtbl;
interface IProcessInitControl
{
CONST_VTBL struct IProcessInitControlVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IProcessInitControl_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IProcessInitControl_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IProcessInitControl_Release(A) (A)->lpVtbl->Release(A)
#define IProcessInitControl_ResetInitializerTimeout(A,B) (A)->lpVtbl->ResetInitializerTimeout(A,B)
#endif 
HRESULT IProcessInitControl_ResetInitializerTimeout_Proxy(IProcessInitControl *,DWORD);
void IProcessInitControl_ResetInitializerTimeout_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#if (_WIN32_WINNT >= 1281)
extern RPC_IF_HANDLE __MIDL_itf_objidl_0091_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0091_v0_0_s_ifspec;
#ifndef __IInitializeSpy_INTERFACE_DEFINED__
#define __IInitializeSpy_INTERFACE_DEFINED__
typedef IInitializeSpy *LPINITIALIZESPY;
EXTERN_C const IID IID_IInitializeSpy;
typedef struct IInitializeSpyVtbl
{
	BEGIN_INTERFACE
	HRESULT(*QueryInterface)(IInitializeSpy *,REFIID,void **);
	ULONG (*AddRef)(IInitializeSpy *);
	ULONG (*Release)(IInitializeSpy *);
	HRESULT(*PreInitialize)(IInitializeSpy *,DWORD,DWORD);
	HRESULT(*PostInitialize)(IInitializeSpy *,HRESULT,DWORD,DWORD);
	HRESULT(*PreUninitialize)(IInitializeSpy *,DWORD);
	HRESULT(*PostUninitialize)(IInitializeSpy *,DWORD);
END_INTERFACE
} IInitializeSpyVtbl;
interface IInitializeSpy
{
CONST_VTBL struct IInitializeSpyVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IInitializeSpy_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IInitializeSpy_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IInitializeSpy_Release(A) (A)->lpVtbl->Release(A)
#define IInitializeSpy_PreInitialize(A,B,C) (A)->lpVtbl->PreInitialize(A,B,C)
#define IInitializeSpy_PostInitialize(A,B,C,D) (A)->lpVtbl->PostInitialize(A,B,C,D)
#define IInitializeSpy_PreUninitialize(A,B) (A)->lpVtbl->PreUninitialize(A,B)
#define IInitializeSpy_PostUninitialize(A,B) (A)->lpVtbl->PostUninitialize(A,B)
#endif 
HRESULT IInitializeSpy_PreInitialize_Proxy(IInitializeSpy *,DWORD,DWORD);
void IInitializeSpy_PreInitialize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IInitializeSpy_PostInitialize_Proxy(IInitializeSpy *,HRESULT,DWORD,DWORD);
void IInitializeSpy_PostInitialize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IInitializeSpy_PreUninitialize_Proxy(IInitializeSpy *,DWORD);
void IInitializeSpy_PreUninitialize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
HRESULT IInitializeSpy_PostUninitialize_Proxy(IInitializeSpy *,DWORD);
void IInitializeSpy_PostUninitialize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE,DWORD *);
#endif 
#endif
extern RPC_IF_HANDLE __MIDL_itf_objidl_0092_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_objidl_0092_v0_0_s_ifspec;
unsigned long __RPC_USER ASYNC_STGMEDIUM_UserSize(unsigned long *,unsigned,ASYNC_STGMEDIUM *); 
unsigned char * __RPC_USER ASYNC_STGMEDIUM_UserMarshal(unsigned long *,unsigned char *,ASYNC_STGMEDIUM *); 
unsigned char * __RPC_USER ASYNC_STGMEDIUM_UserUnmarshal(unsigned long *,unsigned char *,ASYNC_STGMEDIUM *); 
void __RPC_USER ASYNC_STGMEDIUM_UserFree(unsigned long *,ASYNC_STGMEDIUM *); 
unsigned long __RPC_USER CLIPFORMAT_UserSize(unsigned long *,unsigned,CLIPFORMAT *); 
unsigned char * __RPC_USER CLIPFORMAT_UserMarshal(unsigned long *,unsigned char *,CLIPFORMAT *); 
unsigned char * __RPC_USER CLIPFORMAT_UserUnmarshal(unsigned long *,unsigned char *,CLIPFORMAT *); 
void __RPC_USER CLIPFORMAT_UserFree(unsigned long *,CLIPFORMAT *); 
unsigned long __RPC_USER FLAG_STGMEDIUM_UserSize(unsigned long *,unsigned,FLAG_STGMEDIUM *); 
unsigned char * __RPC_USER FLAG_STGMEDIUM_UserMarshal(unsigned long *,unsigned char *,FLAG_STGMEDIUM *); 
unsigned char * __RPC_USER FLAG_STGMEDIUM_UserUnmarshal(unsigned long *,unsigned char *,FLAG_STGMEDIUM *); 
void __RPC_USER FLAG_STGMEDIUM_UserFree(unsigned long *,FLAG_STGMEDIUM *); 
unsigned long __RPC_USER HBITMAP_UserSize(unsigned long *,unsigned,HBITMAP *); 
unsigned char * __RPC_USER HBITMAP_UserMarshal(unsigned long *,unsigned char *,HBITMAP *); 
unsigned char * __RPC_USER HBITMAP_UserUnmarshal(unsigned long *,unsigned char *,HBITMAP *); 
void __RPC_USER HBITMAP_UserFree(unsigned long *,HBITMAP *); 
unsigned long __RPC_USER HDC_UserSize(unsigned long *,unsigned,HDC *); 
unsigned char * __RPC_USER HDC_UserMarshal(unsigned long *,unsigned char *,HDC *); 
unsigned char * __RPC_USER HDC_UserUnmarshal(unsigned long *,unsigned char *,HDC *); 
void __RPC_USER HDC_UserFree(unsigned long *,HDC *); 
unsigned long __RPC_USER HICON_UserSize(unsigned long *,unsigned,HICON *); 
unsigned char * __RPC_USER HICON_UserMarshal(unsigned long *,unsigned char *,HICON *); 
unsigned char * __RPC_USER HICON_UserUnmarshal(unsigned long *,unsigned char *,HICON *); 
void __RPC_USER HICON_UserFree(unsigned long *,HICON *); 
unsigned long __RPC_USER SNB_UserSize(unsigned long *,unsigned,SNB *); 
unsigned char * __RPC_USER SNB_UserMarshal(unsigned long *,unsigned char *,SNB *); 
unsigned char * __RPC_USER SNB_UserUnmarshal(unsigned long *,unsigned char *,SNB *); 
void __RPC_USER SNB_UserFree(unsigned long *,SNB *); 
unsigned long __RPC_USER STGMEDIUM_UserSize(unsigned long *,unsigned,STGMEDIUM *); 
unsigned char * __RPC_USER STGMEDIUM_UserMarshal(unsigned long *,unsigned char *,STGMEDIUM *); 
unsigned char * __RPC_USER STGMEDIUM_UserUnmarshal(unsigned long *,unsigned char *,STGMEDIUM *); 
void __RPC_USER STGMEDIUM_UserFree(unsigned long *,STGMEDIUM *); 
HRESULT IEnumUnknown_Next_Proxy(IEnumUnknown *,ULONG,IUnknown **,ULONG *);
HRESULT IEnumUnknown_Next_Stub(IEnumUnknown *,ULONG,IUnknown **,ULONG *);
HRESULT IBindCtx_SetBindOptions_Proxy(IBindCtx *,BIND_OPTS *);
HRESULT IBindCtx_SetBindOptions_Stub(IBindCtx *,BIND_OPTS2 *);
HRESULT IBindCtx_GetBindOptions_Proxy(IBindCtx *,BIND_OPTS *);
HRESULT IBindCtx_GetBindOptions_Stub(IBindCtx *,BIND_OPTS2 *);
HRESULT IEnumMoniker_Next_Proxy(IEnumMoniker *,ULONG,IMoniker **,ULONG *);
HRESULT IEnumMoniker_Next_Stub(IEnumMoniker *,ULONG,IMoniker **,ULONG *);
BOOL IRunnableObject_IsRunning_Proxy(IRunnableObject *);
HRESULT IRunnableObject_IsRunning_Stub(IRunnableObject *);
HRESULT IMoniker_BindToObject_Proxy(IMoniker *,IBindCtx *,IMoniker *,REFIID,void **);
HRESULT IMoniker_BindToObject_Stub(IMoniker *,IBindCtx *,IMoniker *,REFIID,IUnknown **);
HRESULT IMoniker_BindToStorage_Proxy(IMoniker *,IBindCtx *,IMoniker *,REFIID,void **);
HRESULT IMoniker_BindToStorage_Stub(IMoniker *,IBindCtx *,IMoniker *,REFIID,IUnknown **);
HRESULT IEnumString_Next_Proxy(IEnumString *,ULONG,LPOLESTR *,ULONG *);
HRESULT IEnumString_Next_Stub(IEnumString *,ULONG,LPOLESTR *,ULONG *);
HRESULT ISequentialStream_Read_Proxy(ISequentialStream *,void *,ULONG,ULONG *);
HRESULT ISequentialStream_Read_Stub(ISequentialStream *,byte *,ULONG,ULONG *);
HRESULT ISequentialStream_Write_Proxy(ISequentialStream *,const void *pv,ULONG,ULONG *);
HRESULT ISequentialStream_Write_Stub(ISequentialStream *,const byte *pv,ULONG,ULONG *);
HRESULT IStream_Seek_Proxy(IStream *,LARGE_INTEGER,DWORD,ULARGE_INTEGER *);
HRESULT IStream_Seek_Stub(IStream *,LARGE_INTEGER,DWORD,ULARGE_INTEGER *);
HRESULT IStream_CopyTo_Proxy(IStream *,IStream *,ULARGE_INTEGER,ULARGE_INTEGER *,ULARGE_INTEGER *);
HRESULT IStream_CopyTo_Stub(IStream *,IStream *,ULARGE_INTEGER,ULARGE_INTEGER *,ULARGE_INTEGER *);
HRESULT IEnumSTATSTG_Next_Proxy(IEnumSTATSTG *,ULONG,STATSTG *,ULONG *);
HRESULT IEnumSTATSTG_Next_Stub(IEnumSTATSTG *,ULONG,STATSTG *,ULONG *);
HRESULT IStorage_OpenStream_Proxy(IStorage *,const OLECHAR *pwcsName,void *,DWORD,DWORD,IStream **);
HRESULT IStorage_OpenStream_Stub(IStorage *,const OLECHAR *pwcsName,unsigned long cbReserved1,byte *,DWORD,DWORD,IStream **);
HRESULT IStorage_EnumElements_Proxy(IStorage *,DWORD,void *,DWORD,IEnumSTATSTG **);
HRESULT IStorage_EnumElements_Stub(IStorage *,DWORD,unsigned long cbReserved2,byte *,DWORD,IEnumSTATSTG **);
HRESULT ILockBytes_ReadAt_Proxy(ILockBytes *,ULARGE_INTEGER,void *,ULONG,ULONG *);
HRESULT ILockBytes_ReadAt_Stub(ILockBytes *,ULARGE_INTEGER,byte *,ULONG,ULONG *);
HRESULT ILockBytes_WriteAt_Proxy(ILockBytes *,ULARGE_INTEGER,const void *pv,ULONG,ULONG *);
HRESULT ILockBytes_WriteAt_Stub(ILockBytes *,ULARGE_INTEGER,const byte *pv,ULONG,ULONG *);
HRESULT IEnumFORMATETC_Next_Proxy(IEnumFORMATETC *,ULONG,FORMATETC *,ULONG *);
HRESULT IEnumFORMATETC_Next_Stub(IEnumFORMATETC *,ULONG,FORMATETC *,ULONG *);
HRESULT IEnumSTATDATA_Next_Proxy(IEnumSTATDATA *,ULONG,STATDATA *,ULONG *);
HRESULT IEnumSTATDATA_Next_Stub(IEnumSTATDATA *,ULONG,STATDATA *,ULONG *);
void IAdviseSink_OnDataChange_Proxy(IAdviseSink *,FORMATETC *,STGMEDIUM *);
HRESULT IAdviseSink_OnDataChange_Stub(IAdviseSink *,FORMATETC *,ASYNC_STGMEDIUM *);
void IAdviseSink_OnViewChange_Proxy(IAdviseSink *,DWORD,LONG);
HRESULT IAdviseSink_OnViewChange_Stub(IAdviseSink *,DWORD,LONG);
void IAdviseSink_OnRename_Proxy(IAdviseSink *,IMoniker *);
HRESULT IAdviseSink_OnRename_Stub(IAdviseSink *,IMoniker *);
void IAdviseSink_OnSave_Proxy(IAdviseSink *);
HRESULT IAdviseSink_OnSave_Stub(IAdviseSink *);
void IAdviseSink_OnClose_Proxy(IAdviseSink *);
HRESULT IAdviseSink_OnClose_Stub(IAdviseSink *);
void IAdviseSink2_OnLinkSrcChange_Proxy(IAdviseSink2 *,IMoniker *);
HRESULT IAdviseSink2_OnLinkSrcChange_Stub(IAdviseSink2 *,IMoniker *);
HRESULT IDataObject_GetData_Proxy(IDataObject *,FORMATETC *,STGMEDIUM *);
HRESULT IDataObject_GetData_Stub(IDataObject *,FORMATETC *,STGMEDIUM *);
HRESULT IDataObject_GetDataHere_Proxy(IDataObject *,FORMATETC *,STGMEDIUM *);
HRESULT IDataObject_GetDataHere_Stub(IDataObject *,FORMATETC *,STGMEDIUM *);
HRESULT IDataObject_SetData_Proxy(IDataObject *,FORMATETC *,STGMEDIUM *,BOOL);
HRESULT IDataObject_SetData_Stub(IDataObject *,FORMATETC *,FLAG_STGMEDIUM *,BOOL);
HRESULT IFillLockBytes_FillAppend_Proxy(IFillLockBytes *,const void *pv,ULONG,ULONG *);
HRESULT IFillLockBytes_FillAppend_Stub(IFillLockBytes *,const byte *pv,ULONG,ULONG *);
HRESULT IFillLockBytes_FillAt_Proxy(IFillLockBytes *,ULARGE_INTEGER,const void *pv,ULONG,ULONG *);
HRESULT IFillLockBytes_FillAt_Stub(IFillLockBytes *,ULARGE_INTEGER,const byte *pv,ULONG,ULONG *);
void AsyncIAdviseSink_Begin_OnDataChange_Proxy(AsyncIAdviseSink *,FORMATETC *,STGMEDIUM *);
HRESULT AsyncIAdviseSink_Begin_OnDataChange_Stub(AsyncIAdviseSink *,FORMATETC *,ASYNC_STGMEDIUM *);
void AsyncIAdviseSink_Finish_OnDataChange_Proxy(AsyncIAdviseSink *);
HRESULT AsyncIAdviseSink_Finish_OnDataChange_Stub(AsyncIAdviseSink *);
void AsyncIAdviseSink_Begin_OnViewChange_Proxy(AsyncIAdviseSink *,DWORD,LONG);
HRESULT AsyncIAdviseSink_Begin_OnViewChange_Stub(AsyncIAdviseSink *,DWORD,LONG);
void AsyncIAdviseSink_Finish_OnViewChange_Proxy(AsyncIAdviseSink *);
HRESULT AsyncIAdviseSink_Finish_OnViewChange_Stub(AsyncIAdviseSink *);
void AsyncIAdviseSink_Begin_OnRename_Proxy(AsyncIAdviseSink *,IMoniker *);
HRESULT AsyncIAdviseSink_Begin_OnRename_Stub(AsyncIAdviseSink *,IMoniker *);
void AsyncIAdviseSink_Finish_OnRename_Proxy(AsyncIAdviseSink *);
HRESULT AsyncIAdviseSink_Finish_OnRename_Stub(AsyncIAdviseSink *);
void AsyncIAdviseSink_Begin_OnSave_Proxy(AsyncIAdviseSink *);
HRESULT AsyncIAdviseSink_Begin_OnSave_Stub(AsyncIAdviseSink *);
void AsyncIAdviseSink_Finish_OnSave_Proxy(AsyncIAdviseSink *);
HRESULT AsyncIAdviseSink_Finish_OnSave_Stub(AsyncIAdviseSink *);
void AsyncIAdviseSink_Begin_OnClose_Proxy(AsyncIAdviseSink *);
HRESULT AsyncIAdviseSink_Begin_OnClose_Stub(AsyncIAdviseSink *);
void AsyncIAdviseSink_Finish_OnClose_Proxy(AsyncIAdviseSink *);
HRESULT AsyncIAdviseSink_Finish_OnClose_Stub(AsyncIAdviseSink *);
void AsyncIAdviseSink2_Begin_OnLinkSrcChange_Proxy(AsyncIAdviseSink2 *,IMoniker *);
HRESULT AsyncIAdviseSink2_Begin_OnLinkSrcChange_Stub(AsyncIAdviseSink2 *,IMoniker *);
void AsyncIAdviseSink2_Finish_OnLinkSrcChange_Proxy(AsyncIAdviseSink2 *);
HRESULT AsyncIAdviseSink2_Finish_OnLinkSrcChange_Stub(AsyncIAdviseSink2 *);
#endif
