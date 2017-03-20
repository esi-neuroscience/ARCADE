
#pragma warning(disable: 4049 )  
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
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
#ifndef __servprov_h__
#define __servprov_h__
#pragma once
#ifndef __IServiceProvider_FWD_DEFINED__
#define __IServiceProvider_FWD_DEFINED__
typedef interface IServiceProvider IServiceProvider;
#endif 	
#include "objidl.h"
#ifdef __cplusplus
extern "C"{
#endif 
void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void * ); 
#pragma comment(lib,"uuid.lib")
extern RPC_IF_HANDLE __MIDL_itf_servprov_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_servprov_0000_v0_0_s_ifspec;
#ifndef __IServiceProvider_INTERFACE_DEFINED__
#define __IServiceProvider_INTERFACE_DEFINED__
typedef  IServiceProvider *LPSERVICEPROVIDER;
#if (_MSC_VER >= 1100) && defined(__cplusplus) && !defined(CINTERFACE)
	EXTERN_C const IID IID_IServiceProvider;
	extern "C++"
	{
		MIDL_INTERFACE("6d5140c1-7436-11ce-8034-00aa006009fa")
		IServiceProvider : public IUnknown
		{
		public:
			virtual  HRESULT STDMETHODCALLTYPE QueryService(REFGUID guidService,REFIID riid,void __RPC_FAR *__RPC_FAR *ppvObject) = 0;
			template <class Q>
			HRESULT STDMETHODCALLTYPE QueryService(REFGUID guidService, Q** pp)
			{
				return QueryService(guidService, __uuidof(Q), (void **)pp);
			}
		};
	}
	 HRESULT STDMETHODCALLTYPE IServiceProvider_RemoteQueryService_Proxy(IServiceProvider __RPC_FAR * This,REFGUID guidService,REFIID riid,IUnknown __RPC_FAR *__RPC_FAR *ppvObject);
	void __RPC_STUB IServiceProvider_RemoteQueryService_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#else 
EXTERN_C const IID IID_IServiceProvider;
#if defined(__cplusplus) && !defined(CINTERFACE)
	MIDL_INTERFACE("6d5140c1-7436-11ce-8034-00aa006009fa")
	IServiceProvider : public IUnknown
	{
	public:
		virtual  HRESULT STDMETHODCALLTYPE QueryService(REFGUID guidService,REFIID riid,void **ppvObject) = 0;
	};
#else 	
	typedef struct IServiceProviderVtbl
	{
		BEGIN_INTERFACE
		HRESULT (STDMETHODCALLTYPE *QueryInterface )(IServiceProvider * This,REFIID riid,void **ppvObject);
		ULONG (STDMETHODCALLTYPE *AddRef )(IServiceProvider * This);
		ULONG (STDMETHODCALLTYPE *Release )(IServiceProvider * This);
		 HRESULT (STDMETHODCALLTYPE *QueryService )(IServiceProvider * This,REFGUID guidService,REFIID riid,void **ppvObject);
		END_INTERFACE
	} IServiceProviderVtbl;
	interface IServiceProvider
	{
		CONST_VTBL struct IServiceProviderVtbl *lpVtbl;
	};
#ifdef COBJMACROS
#define IServiceProvider_QueryInterface(This,riid,ppvObject)	 (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define IServiceProvider_AddRef(This)	 (This)->lpVtbl -> AddRef(This)
#define IServiceProvider_Release(This)	 (This)->lpVtbl -> Release(This)
#define IServiceProvider_QueryService(This,guidService,riid,ppvObject)	 (This)->lpVtbl -> QueryService(This,guidService,riid,ppvObject)
#endif 
#endif 	
 HRESULT STDMETHODCALLTYPE IServiceProvider_RemoteQueryService_Proxy(IServiceProvider * This,REFGUID guidService,REFIID riid,IUnknown **ppvObject);
void __RPC_STUB IServiceProvider_RemoteQueryService_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif 	
#endif 
extern RPC_IF_HANDLE __MIDL_itf_servprov_0093_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_servprov_0093_v0_0_s_ifspec;
 HRESULT STDMETHODCALLTYPE IServiceProvider_QueryService_Proxy(IServiceProvider * This,REFGUID guidService,REFIID riid,void **ppvObject);
 HRESULT STDMETHODCALLTYPE IServiceProvider_QueryService_Stub(IServiceProvider * This,REFGUID guidService,REFIID riid,IUnknown **ppvObject);
#ifdef __cplusplus
}
#endif
#endif
