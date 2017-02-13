#ifndef __RPCDCEP_H__
#define __RPCDCEP_H__
#pragma once
typedef struct _RPC_VERSION {
	unsigned short MajorVersion;
	unsigned short MinorVersion;
} RPC_VERSION;
typedef struct _RPC_SYNTAX_IDENTIFIER {
	GUID SyntaxGUID;
	RPC_VERSION SyntaxVersion;
} RPC_SYNTAX_IDENTIFIER,__RPC_FAR * PRPC_SYNTAX_IDENTIFIER;
typedef struct _RPC_MESSAGE {
	RPC_BINDING_HANDLE Handle;
	unsigned long DataRepresentation;
	void __RPC_FAR * Buffer;
	unsigned int BufferLength;
	unsigned int ProcNum;
	PRPC_SYNTAX_IDENTIFIER TransferSyntax;
	void __RPC_FAR * RpcInterfaceInformation;
	void __RPC_FAR * ReservedForRuntime;
	RPC_MGR_EPV __RPC_FAR * ManagerEpv;
	void __RPC_FAR * ImportContext;
	unsigned long RpcFlags;
} RPC_MESSAGE,__RPC_FAR * PRPC_MESSAGE;
typedef RPC_STATUS
RPC_ENTRY RPC_FORWARD_FUNCTION(UUID __RPC_FAR * InterfaceId,RPC_VERSION __RPC_FAR * InterfaceVersion,UUID __RPC_FAR * ObjectId,unsigned char __RPC_FAR * Rpcpro,void __RPC_FAR * __RPC_FAR * ppDestEndpoint);
enum RPC_ADDRESS_CHANGE_TYPE {
	PROTOCOL_NOT_LOADED=1,PROTOCOL_LOADED,PROTOCOL_ADDRESS_CHANGE
};
typedef void
RPC_ENTRY RPC_ADDRESS_CHANGE_FN(void * arg);
#define RPC_CONTEXT_HANDLE_DEFAULT_GUARD ((void *) -4083) 
#define RPC_CONTEXT_HANDLE_DEFAULT_FLAGS 0UL
#define RPC_CONTEXT_HANDLE_FLAGS 0x30000000UL
#define RPC_CONTEXT_HANDLE_SERIALIZE 0x10000000UL
#define RPC_CONTEXT_HANDLE_DONT_SERIALIZE 0x20000000UL
#define RPC_NCA_FLAGS_DEFAULT 0 
#define RPC_NCA_FLAGS_IDEMPOTENT 1 
#define RPC_NCA_FLAGS_BROADCAST 2 
#define RPC_NCA_FLAGS_MAYBE 4 
#define RPC_BUFFER_COMPLETE 0x1000 
#define RPC_BUFFER_PARTIAL 0x2000 
#define RPC_BUFFER_EXTRA 0x4000 
#define RPC_BUFFER_ASYNC 0x8000 
#define RPC_BUFFER_NONOTIFY 0x10000 
#define RPCFLG_MESSAGE 0x1000000UL
#define RPCFLG_AUTO_COMPLETE 0x8000000UL
#define RPCFLG_LOCAL_CALL 0x10000000UL
#define RPCFLG_INPUT_SYNCHRONOUS 0x20000000UL
#define RPCFLG_ASYNCHRONOUS 0x40000000UL
#define RPCFLG_NON_NDR 0x80000000UL
#define RPCFLG_HAS_MULTI_SYNTAXES 0x2000000UL
#define RPCFLG_HAS_CALLBACK 0x4000000UL
#define RPC_FLAGS_VALID_BIT 0x8000
typedef void 
(__RPC_STUB __RPC_FAR * RPC_DISPATCH_FUNCTION) (PRPC_MESSAGE Message);
typedef struct {
	unsigned int DispatchTableCount;
	RPC_DISPATCH_FUNCTION __RPC_FAR * DispatchTable;
	LONG_PTR Reserved;
} RPC_DISPATCH_TABLE,__RPC_FAR * PRPC_DISPATCH_TABLE;
typedef struct _RPC_PROTSEQ_ENDPOINT {
	unsigned char __RPC_FAR * RpcProtocolSequence;
	unsigned char __RPC_FAR * Endpoint;
} RPC_PROTSEQ_ENDPOINT,__RPC_FAR * PRPC_PROTSEQ_ENDPOINT;
#define NT351_INTERFACE_SIZE 64
#define RPC_INTERFACE_HAS_PIPES 1
typedef struct _RPC_SERVER_INTERFACE {
	unsigned int Length;
	RPC_SYNTAX_IDENTIFIER InterfaceId;
	RPC_SYNTAX_IDENTIFIER TransferSyntax;
	PRPC_DISPATCH_TABLE DispatchTable;
	unsigned int RpcProtseqEndpointCount;
	PRPC_PROTSEQ_ENDPOINT RpcProtseqEndpoint;
	RPC_MGR_EPV __RPC_FAR *DefaultManagerEpv;
	void const __RPC_FAR *InterpreterInfo;
	unsigned int Flags ;
} RPC_SERVER_INTERFACE,__RPC_FAR * PRPC_SERVER_INTERFACE;
typedef struct _RPC_CLIENT_INTERFACE {
	unsigned int Length;
	RPC_SYNTAX_IDENTIFIER InterfaceId;
	RPC_SYNTAX_IDENTIFIER TransferSyntax;
	PRPC_DISPATCH_TABLE DispatchTable;
	unsigned int RpcProtseqEndpointCount;
	PRPC_PROTSEQ_ENDPOINT RpcProtseqEndpoint;
	ULONG_PTR Reserved;
	void const __RPC_FAR * InterpreterInfo;
	unsigned int Flags ;
} RPC_CLIENT_INTERFACE,__RPC_FAR * PRPC_CLIENT_INTERFACE;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcNegotiateTransferSyntax (RPC_MESSAGE __RPC_FAR * Message);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcGetBuffer (RPC_MESSAGE __RPC_FAR * Message);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcGetBufferWithObject (RPC_MESSAGE __RPC_FAR * Message,UUID * ObjectUuid);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcSendReceive (RPC_MESSAGE __RPC_FAR * Message);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcFreeBuffer (RPC_MESSAGE __RPC_FAR * Message);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcSend (PRPC_MESSAGE Message) ;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcReceive (PRPC_MESSAGE Message,unsigned int Size) ;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcFreePipeBuffer (RPC_MESSAGE __RPC_FAR * Message) ;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcReallocPipeBuffer (PRPC_MESSAGE Message,unsigned int NewSize) ;
typedef void * I_RPC_MUTEX;
RPCRTAPI void RPC_ENTRY I_RpcRequestMutex (I_RPC_MUTEX * Mutex);
RPCRTAPI void RPC_ENTRY I_RpcClearMutex (I_RPC_MUTEX Mutex);
RPCRTAPI void RPC_ENTRY I_RpcDeleteMutex (I_RPC_MUTEX Mutex);
RPCRTAPI void __RPC_FAR *
RPC_ENTRY I_RpcAllocate (unsigned int Size);
RPCRTAPI void RPC_ENTRY I_RpcFree (void __RPC_FAR * Object);
RPCRTAPI void RPC_ENTRY I_RpcPauseExecution (unsigned long Milliseconds);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcGetExtendedError ();
typedef void 
(__RPC_USER __RPC_FAR * PRPC_RUNDOWN) (void __RPC_FAR * AssociationContext);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcMonitorAssociation (RPC_BINDING_HANDLE Handle,PRPC_RUNDOWN RundownRoutine,void * Context);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcStopMonitorAssociation (RPC_BINDING_HANDLE Handle);
RPCRTAPI RPC_BINDING_HANDLE RPC_ENTRY I_RpcGetCurrentCallHandle(void);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcGetAssociationContext (RPC_BINDING_HANDLE BindingHandle,void __RPC_FAR * __RPC_FAR * AssociationContext);
RPCRTAPI void *
RPC_ENTRY I_RpcGetServerContextList (RPC_BINDING_HANDLE BindingHandle);
RPCRTAPI void RPC_ENTRY I_RpcSetServerContextList (RPC_BINDING_HANDLE BindingHandle,void * ServerContextList);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcNsInterfaceExported (unsigned long EntryNameSyntax,unsigned short *EntryName,RPC_SERVER_INTERFACE * RpcInterfaceInformation);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcNsInterfaceUnexported (unsigned long EntryNameSyntax,unsigned short *EntryName,RPC_SERVER_INTERFACE * RpcInterfaceInformation);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingToStaticStringBindingW (RPC_BINDING_HANDLE Binding,unsigned short **StringBinding);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqSecurityContext (RPC_BINDING_HANDLE Binding,void **SecurityContextHandle);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqWireIdForSnego (RPC_BINDING_HANDLE Binding,unsigned char *WireId);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqMarshalledTargetInfo (RPC_BINDING_HANDLE Binding,unsigned long *MarshalledTargetInfoLength,unsigned char **MarshalledTargetInfo);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqLocalClientPID (RPC_BINDING_HANDLE Binding,unsigned long *Pid);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingHandleToAsyncHandle (RPC_BINDING_HANDLE Binding,void **AsyncHandle);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcNsBindingSetEntryNameW (RPC_BINDING_HANDLE Binding,unsigned long EntryNameSyntax,unsigned short __RPC_FAR * EntryName);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcNsBindingSetEntryNameA (RPC_BINDING_HANDLE Binding,unsigned long EntryNameSyntax,unsigned char __RPC_FAR * EntryName);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerUseProtseqEp2A (unsigned char __RPC_FAR * NetworkAddress,unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned char __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor,void *Policy);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerUseProtseqEp2W (unsigned short __RPC_FAR * NetworkAddress,unsigned short __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned short __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor,void * Policy);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerUseProtseq2W (unsigned short __RPC_FAR * NetworkAddress,unsigned short __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor,void * Policy);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerUseProtseq2A (unsigned char __RPC_FAR * NetworkAddress,unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor,void * Policy);
#ifdef UNICODE
#define I_RpcNsBindingSetEntryName I_RpcNsBindingSetEntryNameW
#define I_RpcServerUseProtseqEp2 I_RpcServerUseProtseqEp2W
#define I_RpcServerUseProtseq2 I_RpcServerUseProtseq2W
#else
#define I_RpcNsBindingSetEntryName I_RpcNsBindingSetEntryNameA
#define I_RpcServerUseProtseqEp2 I_RpcServerUseProtseqEp2A
#define I_RpcServerUseProtseq2 I_RpcServerUseProtseq2A
#endif
#else
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcNsBindingSetEntryName (RPC_BINDING_HANDLE Binding,unsigned long EntryNameSyntax,unsigned char __RPC_FAR * EntryName);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerUseProtseq2 (unsigned char __RPC_FAR * NetworkAddress,unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor,void * Policy);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerUseProtseqEp2 (unsigned char __RPC_FAR * NetworkAddress,unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned char __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor,void * Policy);
#endif
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqDynamicEndpointW (RPC_BINDING_HANDLE Binding,unsigned short __RPC_FAR * __RPC_FAR * DynamicEndpoint);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqDynamicEndpointA (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * __RPC_FAR * DynamicEndpoint);
#ifdef UNICODE
#define I_RpcBindingInqDynamicEndpoint I_RpcBindingInqDynamicEndpointW
#else
#define I_RpcBindingInqDynamicEndpoint I_RpcBindingInqDynamicEndpointA
#endif
#else
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqDynamicEndpoint (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * __RPC_FAR * DynamicEndpoint);
#endif
#define TRANSPORT_TYPE_CN 1
#define TRANSPORT_TYPE_DG 2
#define TRANSPORT_TYPE_LPC 4
#define TRANSPORT_TYPE_WMSG 8
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqTransportType (RPC_BINDING_HANDLE Binding,unsigned int __RPC_FAR * Type);
typedef struct _RPC_TRANSFER_SYNTAX {
	UUID Uuid;
	unsigned short VersMajor;
	unsigned short VersMinor;
} RPC_TRANSFER_SYNTAX;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcIfInqTransferSyntaxes (RPC_IF_HANDLE RpcIfHandle,RPC_TRANSFER_SYNTAX __RPC_FAR * TransferSyntaxes,unsigned int TransferSyntaxSize,unsigned int __RPC_FAR * TransferSyntaxCount);
RPCRTAPI RPC_STATUS RPC_ENTRY I_UuidCreate (UUID __RPC_FAR * Uuid);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingCopy (RPC_BINDING_HANDLE SourceBinding,RPC_BINDING_HANDLE __RPC_FAR * DestinationBinding);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingIsClientLocal (RPC_BINDING_HANDLE BindingHandle,unsigned int __RPC_FAR * ClientLocalFlag);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqConnId (RPC_BINDING_HANDLE Binding,void **ConnId,int *pfFirstCall);
RPCRTAPI void RPC_ENTRY I_RpcSsDontSerializeContext (void);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcLaunchDatagramReceiveThread(void __RPC_FAR * pAddress);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerRegisterForwardFunction (RPC_FORWARD_FUNCTION * pForwardFunction);
RPC_ADDRESS_CHANGE_FN * RPC_ENTRY
I_RpcServerInqAddressChangeFn();
RPC_STATUS RPC_ENTRY
I_RpcServerSetAddressChangeFn(RPC_ADDRESS_CHANGE_FN * pAddressChangeFn);
#define RPC_P_ADDR_FORMAT_TCP_IPV4 1
#define RPC_P_ADDR_FORMAT_TCP_IPV6 2
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerInqLocalConnAddress (RPC_BINDING_HANDLE Binding,void *Buffer,unsigned long *BufferSize,unsigned long *AddressFormat);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcTurnOnEEInfoPropagation (void);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcConnectionInqSockBuffSize(unsigned long __RPC_FAR * RecvBuffSize,unsigned long __RPC_FAR * SendBuffSize);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcConnectionSetSockBuffSize(unsigned long RecvBuffSize,unsigned long SendBuffSize);
typedef void 
(*RPCLT_PDU_FILTER_FUNC) (void *Buffer,unsigned int BufferLength,int fDatagram);
typedef void 
(*RPC_SETFILTER_FUNC) (RPCLT_PDU_FILTER_FUNC pfnFilter);
#ifndef WINNT
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerStartListening(void * hWnd) ;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerStopListening() ;
typedef RPC_STATUS (*RPC_BLOCKING_FN) (void * hWnd,void * Context,void * hSyncEvent) ;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingSetAsync(RPC_BINDING_HANDLE Binding,RPC_BLOCKING_FN BlockingFn,unsigned long ServerTid) ;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcSetThreadParams(int fClientFree,void *Context,void * hWndClient);
RPCRTAPI unsigned int
RPC_ENTRY I_RpcWindowProc(void * hWnd,unsigned int Message,unsigned int wParam,unsigned long lParam) ;
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerUnregisterEndpointA (unsigned char * Protseq,unsigned char * Endpoint);
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerUnregisterEndpointW (unsigned short * Protseq,unsigned short * Endpoint);
#ifdef UNICODE
#define I_RpcServerUnregisterEndpoint I_RpcServerUnregisterEndpointW
#else
#define I_RpcServerUnregisterEndpoint I_RpcServerUnregisterEndpointA
#endif
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcServerInqTransportType(unsigned int __RPC_FAR * Type) ;
RPCRTAPI long RPC_ENTRY I_RpcMapWin32Status (RPC_STATUS Status);
typedef RPC_STATUS
(RPC_ENTRY *I_RpcProxyIsValidMachineFn)
		(char *pszMachine,char *pszDotMachine,unsigned long dwPortNumber );
typedef RPC_STATUS
(RPC_ENTRY *I_RpcProxyGetClientAddressFn)
		(void *Context,char *Buffer,unsigned long *BufferLength);
typedef RPC_STATUS
(RPC_ENTRY *I_RpcProxyGetConnectionTimeoutFn)
		(unsigned long *ConnectionTimeout);
typedef struct tagI_RpcProxyCallbackInterface {
	I_RpcProxyIsValidMachineFn IsValidMachineFn;
	I_RpcProxyGetClientAddressFn GetClientAddressFn;
	I_RpcProxyGetConnectionTimeoutFn GetConnectionTimeoutFn;
} I_RpcProxyCallbackInterface;
#define RPC_PROXY_CONNECTION_TYPE_IN_PROXY 0
#define RPC_PROXY_CONNECTION_TYPE_OUT_PROXY 1
RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcProxyNewConnection (unsigned long ConnectionType,unsigned short *ServerAddress,unsigned short *ServerPort,unsigned short *MinConnTimeout,void *ConnectionParameter,I_RpcProxyCallbackInterface *ProxyCallbackInterface);
#endif 
