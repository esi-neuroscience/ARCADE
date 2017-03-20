
#pragma warning(disable: 4049) 
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include "rpc.h"
#include "rpcndr.h"
#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif 
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif 
#ifndef __unknwn_h__
#define __unknwn_h__
#pragma once
#ifndef __IUnknown_FWD_DEFINED__
#define __IUnknown_FWD_DEFINED__
typedef interface IUnknown IUnknown;
#endif 	
#ifndef __AsyncIUnknown_FWD_DEFINED__
#define __AsyncIUnknown_FWD_DEFINED__
typedef interface AsyncIUnknown AsyncIUnknown;
#endif 	
#ifndef __IClassFactory_FWD_DEFINED__
#define __IClassFactory_FWD_DEFINED__
typedef interface IClassFactory IClassFactory;
#endif 	
#include "wtypes.h"
#ifdef __cplusplus
extern "C"{
#endif 
void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void *); 
#pragma once
extern RPC_IF_HANDLE __MIDL_itf_unknwn_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_unknwn_0000_v0_0_s_ifspec;
#ifndef __IUnknown_INTERFACE_DEFINED__
#define __IUnknown_INTERFACE_DEFINED__
typedef IUnknown *LPUNKNOWN;
#if (_MSC_VER >= 1100) && defined(__cplusplus) && !defined(CINTERFACE)
	EXTERN_C const IID IID_IUnknown;
	extern "C++"
	{
		MIDL_INTERFACE("00000000-0000-0000-C000-000000000046")
IUnknown 
		{
		public:
BEGIN_INTERFACE 
			virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,void __RPC_FAR *__RPC_FAR *ppvObject) = 0;
			virtual ULONG STDMETHODCALLTYPE AddRef(void) = 0;
			virtual ULONG STDMETHODCALLTYPE Release(void) = 0;
			template<class Q>
		HRESULT STDMETHODCALLTYPE QueryInterface(Q** pp)
		{
		 return QueryInterface(__uuidof(Q), (void **)pp);
		}
END_INTERFACE 
		};
	} 
	HRESULT STDMETHODCALLTYPE IUnknown_QueryInterface_Proxy(IUnknown __RPC_FAR * This,REFIID riid,void __RPC_FAR *__RPC_FAR *ppvObject);
	void __RPC_STUB IUnknown_QueryInterface_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
	ULONG STDMETHODCALLTYPE IUnknown_AddRef_Proxy(IUnknown __RPC_FAR * This);
	void __RPC_STUB IUnknown_AddRef_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
	ULONG STDMETHODCALLTYPE IUnknown_Release_Proxy(IUnknown __RPC_FAR * This);
	void __RPC_STUB IUnknown_Release_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#else
EXTERN_C const IID IID_IUnknown;
#if defined(__cplusplus) && !defined(CINTERFACE)
	MIDL_INTERFACE("00000000-0000-0000-C000-000000000046")
IUnknown 
	{
	public:
BEGIN_INTERFACE 
		virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,void **ppvObject) = 0;
		virtual ULONG STDMETHODCALLTYPE AddRef(void) = 0;
		virtual ULONG STDMETHODCALLTYPE Release(void) = 0;
END_INTERFACE 
	};
#else 	
	typedef struct IUnknownVtbl
	{
BEGIN_INTERFACE 
		HRESULT (STDMETHODCALLTYPE *QueryInterface)(IUnknown * This,REFIID riid,void **ppvObject);
		ULONG (STDMETHODCALLTYPE *AddRef)(IUnknown * This);
		ULONG (STDMETHODCALLTYPE *Release)(IUnknown * This);
END_INTERFACE 
	} IUnknownVtbl;
	interface IUnknown
	{
		CONST_VTBL struct IUnknownVtbl *lpVtbl;
	};
#ifdef COBJMACROS
#define IUnknown_QueryInterface(This,riid,ppvObject)	 (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IUnknown_AddRef(This)	 (This)->lpVtbl -> AddRef(This)
#define IUnknown_Release(This)	 (This)->lpVtbl -> Release(This)
#endif 
#endif 	
HRESULT STDMETHODCALLTYPE IUnknown_QueryInterface_Proxy(IUnknown * This,REFIID riid,void **ppvObject);
void __RPC_STUB IUnknown_QueryInterface_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
ULONG STDMETHODCALLTYPE IUnknown_AddRef_Proxy(IUnknown * This);
void __RPC_STUB IUnknown_AddRef_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
ULONG STDMETHODCALLTYPE IUnknown_Release_Proxy(IUnknown * This);
void __RPC_STUB IUnknown_Release_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif 	
#endif
extern RPC_IF_HANDLE __MIDL_itf_unknwn_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_unknwn_0005_v0_0_s_ifspec;
#ifndef __AsyncIUnknown_INTERFACE_DEFINED__
#define __AsyncIUnknown_INTERFACE_DEFINED__
EXTERN_C const IID IID_AsyncIUnknown;
#if defined(__cplusplus) && !defined(CINTERFACE)
	MIDL_INTERFACE("000e0000-0000-0000-C000-000000000046")
	AsyncIUnknown : public IUnknown
	{
	public:
		virtual HRESULT STDMETHODCALLTYPE Begin_QueryInterface(REFIID riid) = 0;
		virtual HRESULT STDMETHODCALLTYPE Finish_QueryInterface(void **ppvObject) = 0;
		virtual HRESULT STDMETHODCALLTYPE Begin_AddRef(void) = 0;
		virtual ULONG STDMETHODCALLTYPE Finish_AddRef(void) = 0;
		virtual HRESULT STDMETHODCALLTYPE Begin_Release(void) = 0;
		virtual ULONG STDMETHODCALLTYPE Finish_Release(void) = 0;
	};
#else 	
	typedef struct AsyncIUnknownVtbl
	{
BEGIN_INTERFACE 
		HRESULT (STDMETHODCALLTYPE *QueryInterface)(AsyncIUnknown * This,REFIID riid,void **ppvObject);
		ULONG (STDMETHODCALLTYPE *AddRef)(AsyncIUnknown * This);
		ULONG (STDMETHODCALLTYPE *Release)(AsyncIUnknown * This);
		HRESULT (STDMETHODCALLTYPE *Begin_QueryInterface)(AsyncIUnknown * This,REFIID riid);
		HRESULT (STDMETHODCALLTYPE *Finish_QueryInterface)(AsyncIUnknown * This,void **ppvObject);
		HRESULT (STDMETHODCALLTYPE *Begin_AddRef)(AsyncIUnknown * This);
		ULONG (STDMETHODCALLTYPE *Finish_AddRef)(AsyncIUnknown * This);
		HRESULT (STDMETHODCALLTYPE *Begin_Release)(AsyncIUnknown * This);
		ULONG (STDMETHODCALLTYPE *Finish_Release)(AsyncIUnknown * This);
END_INTERFACE 
	} AsyncIUnknownVtbl;
	interface AsyncIUnknown
	{
		CONST_VTBL struct AsyncIUnknownVtbl *lpVtbl;
	};
#ifdef COBJMACROS
#define AsyncIUnknown_QueryInterface(This,riid,ppvObject)	 (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define AsyncIUnknown_AddRef(This)	 (This)->lpVtbl -> AddRef(This)
#define AsyncIUnknown_Release(This)	 (This)->lpVtbl -> Release(This)
#define AsyncIUnknown_Begin_QueryInterface(This,riid)	 (This)->lpVtbl -> Begin_QueryInterface(This,riid)
#define AsyncIUnknown_Finish_QueryInterface(This,ppvObject)	 (This)->lpVtbl -> Finish_QueryInterface(This,ppvObject)
#define AsyncIUnknown_Begin_AddRef(This)	 (This)->lpVtbl -> Begin_AddRef(This)
#define AsyncIUnknown_Finish_AddRef(This)	 (This)->lpVtbl -> Finish_AddRef(This)
#define AsyncIUnknown_Begin_Release(This)	 (This)->lpVtbl -> Begin_Release(This)
#define AsyncIUnknown_Finish_Release(This)	 (This)->lpVtbl -> Finish_Release(This)
#endif 
#endif 	
HRESULT STDMETHODCALLTYPE AsyncIUnknown_Begin_QueryInterface_Proxy(AsyncIUnknown * This,REFIID riid);
void __RPC_STUB AsyncIUnknown_Begin_QueryInterface_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
HRESULT STDMETHODCALLTYPE AsyncIUnknown_Finish_QueryInterface_Proxy(AsyncIUnknown * This,void **ppvObject);
void __RPC_STUB AsyncIUnknown_Finish_QueryInterface_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
HRESULT STDMETHODCALLTYPE AsyncIUnknown_Begin_AddRef_Proxy(AsyncIUnknown * This);
void __RPC_STUB AsyncIUnknown_Begin_AddRef_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
ULONG STDMETHODCALLTYPE AsyncIUnknown_Finish_AddRef_Proxy(AsyncIUnknown * This);
void __RPC_STUB AsyncIUnknown_Finish_AddRef_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
HRESULT STDMETHODCALLTYPE AsyncIUnknown_Begin_Release_Proxy(AsyncIUnknown * This);
void __RPC_STUB AsyncIUnknown_Begin_Release_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
ULONG STDMETHODCALLTYPE AsyncIUnknown_Finish_Release_Proxy(AsyncIUnknown * This);
void __RPC_STUB AsyncIUnknown_Finish_Release_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif 	
#ifndef __IClassFactory_INTERFACE_DEFINED__
#define __IClassFactory_INTERFACE_DEFINED__
typedef IClassFactory *LPCLASSFACTORY;
EXTERN_C const IID IID_IClassFactory;
#if defined(__cplusplus) && !defined(CINTERFACE)
	MIDL_INTERFACE("00000001-0000-0000-C000-000000000046")
	IClassFactory : public IUnknown
	{
	public:
		virtual HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown *pUnkOuter,REFIID riid,void **ppvObject) = 0;
		virtual HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock) = 0;
	};
#else 	
	typedef struct IClassFactoryVtbl
	{
BEGIN_INTERFACE 
		HRESULT (STDMETHODCALLTYPE *QueryInterface)(IClassFactory * This,REFIID riid,void **ppvObject);
		ULONG (STDMETHODCALLTYPE *AddRef)(IClassFactory * This);
		ULONG (STDMETHODCALLTYPE *Release)(IClassFactory * This);
		 HRESULT (STDMETHODCALLTYPE *CreateInstance)(IClassFactory * This,IUnknown *pUnkOuter,REFIID riid,void **ppvObject);
		 HRESULT (STDMETHODCALLTYPE *LockServer)(IClassFactory * This,BOOL fLock);
END_INTERFACE 
	} IClassFactoryVtbl;
	interface IClassFactory
	{
		CONST_VTBL struct IClassFactoryVtbl *lpVtbl;
	};
#ifdef COBJMACROS
#define IClassFactory_QueryInterface(This,riid,ppvObject)	 (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IClassFactory_AddRef(This)	 (This)->lpVtbl -> AddRef(This)
#define IClassFactory_Release(This)	 (This)->lpVtbl -> Release(This)
#define IClassFactory_CreateInstance(This,pUnkOuter,riid,ppvObject)	 (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObject)
#define IClassFactory_LockServer(This,fLock)	 (This)->lpVtbl -> LockServer(This,fLock)
#endif 
#endif 	
 HRESULT STDMETHODCALLTYPE IClassFactory_RemoteCreateInstance_Proxy(IClassFactory * This,REFIID riid,IUnknown **ppvObject);
void __RPC_STUB IClassFactory_RemoteCreateInstance_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
 HRESULT __stdcall IClassFactory_RemoteLockServer_Proxy(IClassFactory * This,BOOL fLock);
void __RPC_STUB IClassFactory_RemoteLockServer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif 	
 HRESULT STDMETHODCALLTYPE IClassFactory_CreateInstance_Proxy(IClassFactory * This,IUnknown *pUnkOuter,REFIID riid,void **ppvObject);
 HRESULT STDMETHODCALLTYPE IClassFactory_CreateInstance_Stub(IClassFactory * This,REFIID riid,IUnknown **ppvObject);
 HRESULT STDMETHODCALLTYPE IClassFactory_LockServer_Proxy(IClassFactory * This,BOOL fLock);
 HRESULT __stdcall IClassFactory_LockServer_Stub(IClassFactory * This,BOOL fLock);
#ifdef __cplusplus
}
#endif
#endif
