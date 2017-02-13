#ifndef __RPCDCE_H__
#define __RPCDCE_H__
#pragma once
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef OPTIONAL
#define OPTIONAL
#endif
#ifndef DECLSPEC_NORETURN
#if (_MSC_VER >=1200) && !defined(MIDL_PASS)
#define DECLSPEC_NORETURN __declspec(noreturn)
#else
#define DECLSPEC_NORETURN
#endif
#endif
typedef I_RPC_HANDLE RPC_BINDING_HANDLE;
typedef RPC_BINDING_HANDLE handle_t;
#define rpc_binding_handle_t RPC_BINDING_HANDLE
#ifndef GUID_DEFINED
#include <guiddef.h>
#endif 
#ifndef UUID_DEFINED
#define UUID_DEFINED
typedef GUID UUID;
#ifndef uuid_t
#define uuid_t UUID
#endif
#endif
typedef struct _RPC_BINDING_VECTOR {
	unsigned long Count;
	RPC_BINDING_HANDLE BindingH[1];
} RPC_BINDING_VECTOR;
#ifndef rpc_binding_vector_t
#define rpc_binding_vector_t RPC_BINDING_VECTOR
#endif
typedef struct _UUID_VECTOR {
 unsigned long Count;
 UUID *Uuid[1];
} UUID_VECTOR;
#ifndef uuid_vector_t
#define uuid_vector_t UUID_VECTOR
#endif
typedef void __RPC_FAR * RPC_IF_HANDLE;
#ifndef IFID_DEFINED
#define IFID_DEFINED
typedef struct _RPC_IF_ID {
	UUID Uuid;
	unsigned short VersMajor;
	unsigned short VersMinor;
} RPC_IF_ID;
#endif
#define RPC_C_BINDING_INFINITE_TIMEOUT 10
#define RPC_C_BINDING_MIN_TIMEOUT 0
#define RPC_C_BINDING_DEFAULT_TIMEOUT 5
#define RPC_C_BINDING_MAX_TIMEOUT 9
#define RPC_C_CANCEL_INFINITE_TIMEOUT -1
#define RPC_C_LISTEN_MAX_CALLS_DEFAULT 1234
#define RPC_C_PROTSEQ_MAX_REQS_DEFAULT 10
#define RPC_C_BIND_TO_ALL_NICS 1
#define RPC_C_USE_INTERNET_PORT 1
#define RPC_C_USE_INTRANET_PORT 2
#define RPC_C_DONT_FAIL 4
#define RPC_C_MQ_TEMPORARY 0
#define RPC_C_MQ_PERMANENT 1
#define RPC_C_MQ_CLEAR_ON_OPEN 2
#define RPC_C_MQ_USE_EXISTING_SECURITY 4
#define RPC_C_MQ_AUTHN_LEVEL_NONE 0
#define RPC_C_MQ_AUTHN_LEVEL_PKT_INTEGRITY 8
#define RPC_C_MQ_AUTHN_LEVEL_PKT_PRIVACY 16
#define RPC_C_OPT_MQ_DELIVERY 1
#define RPC_C_OPT_MQ_PRIORITY 2
#define RPC_C_OPT_MQ_JOURNAL 3
#define RPC_C_OPT_MQ_ACKNOWLEDGE 4
#define RPC_C_OPT_MQ_AUTHN_SERVICE 5
#define RPC_C_OPT_MQ_AUTHN_LEVEL 6
#define RPC_C_OPT_MQ_TIME_TO_REACH_QUEUE 7
#define RPC_C_OPT_MQ_TIME_TO_BE_RECEIVED 8
#define RPC_C_OPT_BINDING_NONCAUSAL 9
#define RPC_C_OPT_SECURITY_CALLBACK 10
#define RPC_C_OPT_UNIQUE_BINDING 11
#define RPC_C_OPT_CALL_TIMEOUT 12
#define RPC_C_OPT_DONT_LINGER 13
#define RPC_C_OPT_MAX_OPTIONS 14
#define RPC_C_MQ_EXPRESS 0 
#define RPC_C_MQ_RECOVERABLE 1
#define RPC_C_MQ_JOURNAL_NONE 0 
#define RPC_C_MQ_JOURNAL_DEADLETTER 1
#define RPC_C_MQ_JOURNAL_ALWAYS 2
#define RPC_C_FULL_CERT_CHAIN 1
#ifdef RPC_UNICODE_SUPPORTED
typedef struct _RPC_PROTSEQ_VECTORA {
	unsigned int Count;
	unsigned char __RPC_FAR * Protseq[1];
} RPC_PROTSEQ_VECTORA;
typedef struct _RPC_PROTSEQ_VECTORW {
	unsigned int Count;
	unsigned short __RPC_FAR * Protseq[1];
} RPC_PROTSEQ_VECTORW;
#ifdef UNICODE
#define RPC_PROTSEQ_VECTOR RPC_PROTSEQ_VECTORW
#else 
#define RPC_PROTSEQ_VECTOR RPC_PROTSEQ_VECTORA
#endif 
#else 
typedef struct _RPC_PROTSEQ_VECTOR {
	unsigned int Count;
	unsigned char __RPC_FAR * Protseq[1];
} RPC_PROTSEQ_VECTOR;
#endif 
typedef struct _RPC_POLICY {
	unsigned int Length ;
	unsigned long EndpointFlags ;
	unsigned long NICFlags ;
	} RPC_POLICY,__RPC_FAR *PRPC_POLICY ;
typedef void __RPC_USER
RPC_OBJECT_INQ_FN (UUID __RPC_FAR * ObjectUuid,UUID __RPC_FAR * TypeUuid,RPC_STATUS __RPC_FAR * Status);
typedef RPC_STATUS RPC_ENTRY
RPC_IF_CALLBACK_FN (RPC_IF_HANDLE InterfaceUuid,void *Context) ;
typedef void RPC_ENTRY
RPC_SECURITY_CALLBACK_FN (void *Context) ;
#define RPC_MGR_EPV void
typedef struct {
	unsigned int Count;
	unsigned long Stats[1];
} RPC_STATS_VECTOR;
#define RPC_C_STATS_CALLS_IN 0
#define RPC_C_STATS_CALLS_OUT 1
#define RPC_C_STATS_PKTS_IN 2
#define RPC_C_STATS_PKTS_OUT 3
typedef struct {
 unsigned long Count;
 RPC_IF_ID __RPC_FAR * IfId[1];
} RPC_IF_ID_VECTOR;
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingCopy (RPC_BINDING_HANDLE SourceBinding,RPC_BINDING_HANDLE __RPC_FAR * DestinationBinding);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingFree (RPC_BINDING_HANDLE __RPC_FAR * Binding);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingSetOption(RPC_BINDING_HANDLE hBinding,unsigned long option,ULONG_PTR optionValue );
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqOption(RPC_BINDING_HANDLE hBinding,unsigned long option,ULONG_PTR *pOptionValue );
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingFromStringBindingA (unsigned char __RPC_FAR * StringBinding,RPC_BINDING_HANDLE __RPC_FAR * Binding);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingFromStringBindingW (unsigned short __RPC_FAR * StringBinding,RPC_BINDING_HANDLE __RPC_FAR * Binding);
#ifdef UNICODE
#define RpcBindingFromStringBinding RpcBindingFromStringBindingW
#else 
#define RpcBindingFromStringBinding RpcBindingFromStringBindingA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingFromStringBinding (unsigned char __RPC_FAR * StringBinding,RPC_BINDING_HANDLE __RPC_FAR * Binding);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcSsGetContextBinding (void *ContextHandle,RPC_BINDING_HANDLE __RPC_FAR * Binding);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqObject (RPC_BINDING_HANDLE Binding,UUID __RPC_FAR * ObjectUuid);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingReset (RPC_BINDING_HANDLE Binding);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingSetObject (RPC_BINDING_HANDLE Binding,UUID __RPC_FAR * ObjectUuid);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtInqDefaultProtectLevel(unsigned long AuthnSvc,unsigned long __RPC_FAR *AuthnLevel);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingToStringBindingA (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * __RPC_FAR * StringBinding);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingToStringBindingW (RPC_BINDING_HANDLE Binding,unsigned short __RPC_FAR * __RPC_FAR * StringBinding);
#ifdef UNICODE
#define RpcBindingToStringBinding RpcBindingToStringBindingW
#else 
#define RpcBindingToStringBinding RpcBindingToStringBindingA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingToStringBinding (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * __RPC_FAR * StringBinding);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingVectorFree (RPC_BINDING_VECTOR __RPC_FAR * __RPC_FAR * BindingVector);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringBindingComposeA (unsigned char __RPC_FAR * ObjUuid,unsigned char __RPC_FAR * Protseq,unsigned char __RPC_FAR * NetworkAddr,unsigned char __RPC_FAR * Endpoint,unsigned char __RPC_FAR * Options,unsigned char __RPC_FAR * __RPC_FAR * StringBinding OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringBindingComposeW (unsigned short __RPC_FAR * ObjUuid,unsigned short __RPC_FAR * Protseq,unsigned short __RPC_FAR * NetworkAddr,unsigned short __RPC_FAR * Endpoint,unsigned short __RPC_FAR * Options,unsigned short __RPC_FAR * __RPC_FAR * StringBinding OPTIONAL);
#ifdef UNICODE
#define RpcStringBindingCompose RpcStringBindingComposeW
#else 
#define RpcStringBindingCompose RpcStringBindingComposeA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringBindingCompose (unsigned char __RPC_FAR * ObjUuid,unsigned char __RPC_FAR * Protseq,unsigned char __RPC_FAR * NetworkAddr,unsigned char __RPC_FAR * Endpoint,unsigned char __RPC_FAR * Options,unsigned char __RPC_FAR * __RPC_FAR * StringBinding OPTIONAL);
#endif 
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringBindingParseA (unsigned char __RPC_FAR * StringBinding,unsigned char __RPC_FAR * __RPC_FAR * ObjUuid,unsigned char __RPC_FAR * __RPC_FAR * Protseq,unsigned char __RPC_FAR * __RPC_FAR * NetworkAddr,unsigned char __RPC_FAR * __RPC_FAR * Endpoint,
	 unsigned char __RPC_FAR * __RPC_FAR * NetworkOptions OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringBindingParseW (unsigned short __RPC_FAR * StringBinding,unsigned short __RPC_FAR * __RPC_FAR * ObjUuid,unsigned short __RPC_FAR * __RPC_FAR * Protseq,unsigned short __RPC_FAR * __RPC_FAR * NetworkAddr,unsigned short __RPC_FAR * __RPC_FAR * Endpoint,
	 unsigned short __RPC_FAR * __RPC_FAR * NetworkOptions OPTIONAL);
#ifdef UNICODE
#define RpcStringBindingParse RpcStringBindingParseW
#else 
#define RpcStringBindingParse RpcStringBindingParseA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringBindingParse (unsigned char __RPC_FAR * StringBinding,unsigned char __RPC_FAR * __RPC_FAR * ObjUuid,unsigned char __RPC_FAR * __RPC_FAR * Protseq,unsigned char __RPC_FAR * __RPC_FAR * NetworkAddr,unsigned char __RPC_FAR * __RPC_FAR * Endpoint,
	 unsigned char __RPC_FAR * __RPC_FAR * NetworkOptions OPTIONAL);
#endif 
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringFreeA (unsigned char __RPC_FAR * __RPC_FAR * String);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringFreeW (unsigned short __RPC_FAR * __RPC_FAR * String);
#ifdef UNICODE
#define RpcStringFree RpcStringFreeW
#else 
#define RpcStringFree RpcStringFreeA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcStringFree (unsigned char __RPC_FAR * __RPC_FAR * String);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcIfInqId (RPC_IF_HANDLE RpcIfHandle,RPC_IF_ID __RPC_FAR * RpcIfId);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNetworkIsProtseqValidA (unsigned char __RPC_FAR * Protseq);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNetworkIsProtseqValidW (unsigned short __RPC_FAR * Protseq);
#ifdef UNICODE
#define RpcNetworkIsProtseqValid RpcNetworkIsProtseqValidW
#else 
#define RpcNetworkIsProtseqValid RpcNetworkIsProtseqValidA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNetworkIsProtseqValid (unsigned char __RPC_FAR * Protseq);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtInqComTimeout (RPC_BINDING_HANDLE Binding,unsigned int __RPC_FAR * Timeout);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtSetComTimeout (RPC_BINDING_HANDLE Binding,unsigned int Timeout);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtSetCancelTimeout(long Timeout);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNetworkInqProtseqsA (RPC_PROTSEQ_VECTORA __RPC_FAR * __RPC_FAR * ProtseqVector);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNetworkInqProtseqsW (RPC_PROTSEQ_VECTORW __RPC_FAR * __RPC_FAR * ProtseqVector);
#ifdef UNICODE
#define RpcNetworkInqProtseqs RpcNetworkInqProtseqsW
#else 
#define RpcNetworkInqProtseqs RpcNetworkInqProtseqsA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNetworkInqProtseqs (RPC_PROTSEQ_VECTOR __RPC_FAR * __RPC_FAR * ProtseqVector);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcObjectInqType (UUID __RPC_FAR * ObjUuid,UUID __RPC_FAR * TypeUuid OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcObjectSetInqFn (RPC_OBJECT_INQ_FN __RPC_FAR * InquiryFn);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcObjectSetType (UUID __RPC_FAR * ObjUuid,UUID __RPC_FAR * TypeUuid OPTIONAL);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcProtseqVectorFreeA (RPC_PROTSEQ_VECTORA __RPC_FAR * __RPC_FAR * ProtseqVector);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcProtseqVectorFreeW (RPC_PROTSEQ_VECTORW __RPC_FAR * __RPC_FAR * ProtseqVector);
#ifdef UNICODE
#define RpcProtseqVectorFree RpcProtseqVectorFreeW
#else 
#define RpcProtseqVectorFree RpcProtseqVectorFreeA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcProtseqVectorFree (RPC_PROTSEQ_VECTOR __RPC_FAR * __RPC_FAR * ProtseqVector);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerInqBindings (RPC_BINDING_VECTOR __RPC_FAR * __RPC_FAR * BindingVector);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerInqIf (RPC_IF_HANDLE IfSpec,UUID __RPC_FAR * MgrTypeUuid,OPTIONAL
	 RPC_MGR_EPV __RPC_FAR * __RPC_FAR * MgrEpv);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerListen (unsigned int MinimumCallThreads,unsigned int MaxCalls,unsigned int DontWait);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerRegisterIf (RPC_IF_HANDLE IfSpec,UUID __RPC_FAR * MgrTypeUuid,RPC_MGR_EPV __RPC_FAR * MgrEpv OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerRegisterIfEx (RPC_IF_HANDLE IfSpec,UUID __RPC_FAR * MgrTypeUuid,RPC_MGR_EPV __RPC_FAR * MgrEpv,unsigned int Flags,unsigned int MaxCalls,RPC_IF_CALLBACK_FN __RPC_FAR *IfCallback);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerRegisterIf2 (RPC_IF_HANDLE IfSpec,UUID * MgrTypeUuid,RPC_MGR_EPV * MgrEpv,unsigned int Flags,unsigned int MaxCalls,unsigned int MaxRpcSize,RPC_IF_CALLBACK_FN *IfCallbackFn);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUnregisterIf (RPC_IF_HANDLE IfSpec,UUID __RPC_FAR * MgrTypeUuid,OPTIONAL
	 unsigned int WaitForCallsToComplete);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUnregisterIfEx (RPC_IF_HANDLE IfSpec,UUID __RPC_FAR * MgrTypeUuid,OPTIONAL
	 int RundownContextHandles);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseAllProtseqs (unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseAllProtseqsEx (unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseAllProtseqsIf (unsigned int MaxCalls,RPC_IF_HANDLE IfSpec,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseAllProtseqsIfEx (unsigned int MaxCalls,RPC_IF_HANDLE IfSpec,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqA (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqExA (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqW (unsigned short __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqExW (unsigned short __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
#ifdef UNICODE
#define RpcServerUseProtseq RpcServerUseProtseqW
#define RpcServerUseProtseqEx RpcServerUseProtseqExW
#else 
#define RpcServerUseProtseq RpcServerUseProtseqA
#define RpcServerUseProtseqEx RpcServerUseProtseqExA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseq (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqEx (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
#endif 
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqEpA (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned char __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqEpExA (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned char __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqEpW (unsigned short __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned short __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqEpExW (unsigned short __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned short __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
#ifdef UNICODE
#define RpcServerUseProtseqEp RpcServerUseProtseqEpW
#define RpcServerUseProtseqEpEx RpcServerUseProtseqEpExW
#else 
#define RpcServerUseProtseqEp RpcServerUseProtseqEpA
#define RpcServerUseProtseqEpEx RpcServerUseProtseqEpExA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqEp (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned char __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqEpEx (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,unsigned char __RPC_FAR * Endpoint,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
#endif 
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqIfA (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,RPC_IF_HANDLE IfSpec,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqIfExA (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,RPC_IF_HANDLE IfSpec,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqIfW (unsigned short __RPC_FAR * Protseq,unsigned int MaxCalls,RPC_IF_HANDLE IfSpec,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqIfExW (unsigned short __RPC_FAR * Protseq,unsigned int MaxCalls,RPC_IF_HANDLE IfSpec,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
#ifdef UNICODE
#define RpcServerUseProtseqIf RpcServerUseProtseqIfW
#define RpcServerUseProtseqIfEx RpcServerUseProtseqIfExW
#else 
#define RpcServerUseProtseqIf RpcServerUseProtseqIfA
#define RpcServerUseProtseqIfEx RpcServerUseProtseqIfExA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqIf (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,RPC_IF_HANDLE IfSpec,void __RPC_FAR * SecurityDescriptor OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUseProtseqIfEx (unsigned char __RPC_FAR * Protseq,unsigned int MaxCalls,RPC_IF_HANDLE IfSpec,void __RPC_FAR * SecurityDescriptor,PRPC_POLICY Policy);
#endif 
RPCRTAPI void RPC_ENTRY RpcServerYield ();
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtStatsVectorFree (RPC_STATS_VECTOR ** StatsVector);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtInqStats (RPC_BINDING_HANDLE Binding,RPC_STATS_VECTOR ** Statistics);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtIsServerListening (RPC_BINDING_HANDLE Binding);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtStopServerListening (RPC_BINDING_HANDLE Binding);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtWaitServerListen (void);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtSetServerStackSize (unsigned long ThreadStackSize);
RPCRTAPI void RPC_ENTRY RpcSsDontSerializeContext (void);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtEnableIdleCleanup (void);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtInqIfIds (RPC_BINDING_HANDLE Binding,RPC_IF_ID_VECTOR __RPC_FAR * __RPC_FAR * IfIdVector);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcIfIdVectorFree (RPC_IF_ID_VECTOR __RPC_FAR * __RPC_FAR * IfIdVector);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtInqServerPrincNameA (RPC_BINDING_HANDLE Binding,unsigned long AuthnSvc,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtInqServerPrincNameW (RPC_BINDING_HANDLE Binding,unsigned long AuthnSvc,unsigned short __RPC_FAR * __RPC_FAR * ServerPrincName);
#ifdef UNICODE
#define RpcMgmtInqServerPrincName RpcMgmtInqServerPrincNameW
#else 
#define RpcMgmtInqServerPrincName RpcMgmtInqServerPrincNameA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtInqServerPrincName (RPC_BINDING_HANDLE Binding,unsigned long AuthnSvc,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName);
#endif 
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerInqDefaultPrincNameA (unsigned long AuthnSvc,unsigned char __RPC_FAR * __RPC_FAR * PrincName);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerInqDefaultPrincNameW (unsigned long AuthnSvc,unsigned short __RPC_FAR * __RPC_FAR * PrincName);
#ifdef UNICODE
#define RpcServerInqDefaultPrincName RpcServerInqDefaultPrincNameW
#else 
#define RpcServerInqDefaultPrincName RpcServerInqDefaultPrincNameA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerInqDefaultPrincName (unsigned long AuthnSvc,unsigned char __RPC_FAR * __RPC_FAR * PrincName);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcEpResolveBinding (RPC_BINDING_HANDLE Binding,RPC_IF_HANDLE IfSpec);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNsBindingInqEntryNameA (RPC_BINDING_HANDLE Binding,unsigned long EntryNameSyntax,unsigned char __RPC_FAR * __RPC_FAR * EntryName);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNsBindingInqEntryNameW (RPC_BINDING_HANDLE Binding,unsigned long EntryNameSyntax,unsigned short __RPC_FAR * __RPC_FAR * EntryName);
#ifdef UNICODE
#define RpcNsBindingInqEntryName RpcNsBindingInqEntryNameW
#else 
#define RpcNsBindingInqEntryName RpcNsBindingInqEntryNameA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcNsBindingInqEntryName (RPC_BINDING_HANDLE Binding,unsigned long EntryNameSyntax,unsigned char __RPC_FAR * __RPC_FAR * EntryName);
#endif 
typedef void __RPC_FAR * RPC_AUTH_IDENTITY_HANDLE;
typedef void __RPC_FAR * RPC_AUTHZ_HANDLE;
#define RPC_C_AUTHN_LEVEL_DEFAULT 0
#define RPC_C_AUTHN_LEVEL_NONE 1
#define RPC_C_AUTHN_LEVEL_CONNECT 2
#define RPC_C_AUTHN_LEVEL_CALL 3
#define RPC_C_AUTHN_LEVEL_PKT 4
#define RPC_C_AUTHN_LEVEL_PKT_INTEGRITY 5
#define RPC_C_AUTHN_LEVEL_PKT_PRIVACY 6
#define RPC_C_IMP_LEVEL_DEFAULT 0
#define RPC_C_IMP_LEVEL_ANONYMOUS 1
#define RPC_C_IMP_LEVEL_IDENTIFY 2
#define RPC_C_IMP_LEVEL_IMPERSONATE 3
#define RPC_C_IMP_LEVEL_DELEGATE 4
#define RPC_C_QOS_IDENTITY_STATIC 0
#define RPC_C_QOS_IDENTITY_DYNAMIC 1
#define RPC_C_QOS_CAPABILITIES_DEFAULT 0
#define RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH 1
#define RPC_C_QOS_CAPABILITIES_MAKE_FULLSIC 2
#define RPC_C_QOS_CAPABILITIES_ANY_AUTHORITY 4
#define RPC_C_QOS_CAPABILITIES_IGNORE_DELEGATE_FAILURE 8
#define RPC_C_QOS_CAPABILITIES_LOCAL_MA_HINT 16
#define RPC_C_PROTECT_LEVEL_DEFAULT (RPC_C_AUTHN_LEVEL_DEFAULT)
#define RPC_C_PROTECT_LEVEL_NONE (RPC_C_AUTHN_LEVEL_NONE)
#define RPC_C_PROTECT_LEVEL_CONNECT (RPC_C_AUTHN_LEVEL_CONNECT)
#define RPC_C_PROTECT_LEVEL_CALL (RPC_C_AUTHN_LEVEL_CALL)
#define RPC_C_PROTECT_LEVEL_PKT (RPC_C_AUTHN_LEVEL_PKT)
#define RPC_C_PROTECT_LEVEL_PKT_INTEGRITY (RPC_C_AUTHN_LEVEL_PKT_INTEGRITY)
#define RPC_C_PROTECT_LEVEL_PKT_PRIVACY (RPC_C_AUTHN_LEVEL_PKT_PRIVACY)
#define RPC_C_AUTHN_NONE 0
#define RPC_C_AUTHN_DCE_PRIVATE 1
#define RPC_C_AUTHN_DCE_PUBLIC 2
#define RPC_C_AUTHN_DEC_PUBLIC 4
#define RPC_C_AUTHN_GSS_NEGOTIATE 9
#define RPC_C_AUTHN_WINNT 10
#define RPC_C_AUTHN_GSS_SCHANNEL 14
#define RPC_C_AUTHN_GSS_KERBEROS 16
#define RPC_C_AUTHN_DPA 17
#define RPC_C_AUTHN_MSN 18
#define RPC_C_AUTHN_DIGEST 21
#define RPC_C_AUTHN_MQ 100
#define RPC_C_AUTHN_DEFAULT 0xffffffff
#define RPC_C_NO_CREDENTIALS ((RPC_AUTH_IDENTITY_HANDLE) MAXUINT_PTR)
#define RPC_C_SECURITY_QOS_VERSION 1L
#define RPC_C_SECURITY_QOS_VERSION_1 1L
typedef struct _RPC_SECURITY_QOS {
 unsigned long Version;
 unsigned long Capabilities;
 unsigned long IdentityTracking;
 unsigned long ImpersonationType;
} RPC_SECURITY_QOS,*PRPC_SECURITY_QOS;
#ifndef _AUTH_IDENTITY_DEFINED
#define _AUTH_IDENTITY_DEFINED
#define SEC_WINNT_AUTH_IDENTITY_ANSI 1
#define SEC_WINNT_AUTH_IDENTITY_UNICODE 2
typedef struct _SEC_WINNT_AUTH_IDENTITY_W {
 unsigned short __RPC_FAR *User;
 unsigned long UserLength;
 unsigned short __RPC_FAR *Domain;
 unsigned long DomainLength;
 unsigned short __RPC_FAR *Password;
 unsigned long PasswordLength;
 unsigned long Flags;
} SEC_WINNT_AUTH_IDENTITY_W,*PSEC_WINNT_AUTH_IDENTITY_W;
typedef struct _SEC_WINNT_AUTH_IDENTITY_A {
 unsigned char __RPC_FAR *User;
 unsigned long UserLength;
 unsigned char __RPC_FAR *Domain;
 unsigned long DomainLength;
 unsigned char __RPC_FAR *Password;
 unsigned long PasswordLength;
 unsigned long Flags;
} SEC_WINNT_AUTH_IDENTITY_A,*PSEC_WINNT_AUTH_IDENTITY_A;
#ifdef UNICODE
#define SEC_WINNT_AUTH_IDENTITY SEC_WINNT_AUTH_IDENTITY_W
#define PSEC_WINNT_AUTH_IDENTITY PSEC_WINNT_AUTH_IDENTITY_W
#define _SEC_WINNT_AUTH_IDENTITY _SEC_WINNT_AUTH_IDENTITY_W
#else 
#define SEC_WINNT_AUTH_IDENTITY SEC_WINNT_AUTH_IDENTITY_A
#define PSEC_WINNT_AUTH_IDENTITY PSEC_WINNT_AUTH_IDENTITY_A
#define _SEC_WINNT_AUTH_IDENTITY _SEC_WINNT_AUTH_IDENTITY_A
#endif 
#define RPC_C_SECURITY_QOS_VERSION_2 2L
#define RPC_C_AUTHN_INFO_TYPE_HTTP 1
#define RPC_C_HTTP_AUTHN_TARGET_SERVER 1
#define RPC_C_HTTP_AUTHN_TARGET_PROXY 2
#define RPC_C_HTTP_AUTHN_SCHEME_BASIC 1
#define RPC_C_HTTP_AUTHN_SCHEME_NTLM 2
#define RPC_C_HTTP_AUTHN_SCHEME_PASSPORT 4
#define RPC_C_HTTP_AUTHN_SCHEME_DIGEST 8
#define RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE 16
#define RPC_C_HTTP_FLAG_USE_SSL 1
#define RPC_C_HTTP_FLAG_USE_FIRST_AUTH_SCHEME 2
typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_W {
	SEC_WINNT_AUTH_IDENTITY_W *TransportCredentials;
	unsigned long Flags;
	unsigned long AuthenticationTarget;
	unsigned long NumberOfAuthnSchemes;
	unsigned long *AuthnSchemes;
	unsigned short __RPC_FAR *ServerCertificateSubject;
} RPC_HTTP_TRANSPORT_CREDENTIALS_W,*PRPC_HTTP_TRANSPORT_CREDENTIALS_W;
typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_A {
	SEC_WINNT_AUTH_IDENTITY_A *TransportCredentials;
	unsigned long Flags;
	unsigned long AuthenticationTarget;
	unsigned long NumberOfAuthnSchemes;
	unsigned long *AuthnSchemes;
	unsigned char __RPC_FAR *ServerCertificateSubject;
} RPC_HTTP_TRANSPORT_CREDENTIALS_A,*PRPC_HTTP_TRANSPORT_CREDENTIALS_A;
typedef struct _RPC_SECURITY_QOS_V2_W {
 unsigned long Version;
 unsigned long Capabilities;
 unsigned long IdentityTracking;
 unsigned long ImpersonationType;
 unsigned long AdditionalSecurityInfoType;
 union 
	 {
	 RPC_HTTP_TRANSPORT_CREDENTIALS_W *HttpCredentials;
	 } u;
} RPC_SECURITY_QOS_V2_W,*PRPC_SECURITY_QOS_V2_W;
typedef struct _RPC_SECURITY_QOS_V2_A {
 unsigned long Version;
 unsigned long Capabilities;
 unsigned long IdentityTracking;
 unsigned long ImpersonationType;
 unsigned long AdditionalSecurityInfoType;
 union 
	 {
	 RPC_HTTP_TRANSPORT_CREDENTIALS_A *HttpCredentials;
	 } u;
} RPC_SECURITY_QOS_V2_A,*PRPC_SECURITY_QOS_V2_A;
#define RPC_C_SECURITY_QOS_VERSION_3 3L
typedef struct _RPC_SECURITY_QOS_V3_W {
 unsigned long Version;
 unsigned long Capabilities;
 unsigned long IdentityTracking;
 unsigned long ImpersonationType;
 unsigned long AdditionalSecurityInfoType;
 union 
	 {
	 RPC_HTTP_TRANSPORT_CREDENTIALS_W *HttpCredentials;
	 } u;
 void *Sid;
} RPC_SECURITY_QOS_V3_W,*PRPC_SECURITY_QOS_V3_W;
typedef struct _RPC_SECURITY_QOS_V3_A {
 unsigned long Version;
 unsigned long Capabilities;
 unsigned long IdentityTracking;
 unsigned long ImpersonationType;
 unsigned long AdditionalSecurityInfoType;
 union 
	 {
	 RPC_HTTP_TRANSPORT_CREDENTIALS_A *HttpCredentials;
	 } u;
 void *Sid;
} RPC_SECURITY_QOS_V3_A,*PRPC_SECURITY_QOS_V3_A;
#endif 
#ifdef UNICODE
#define RPC_SECURITY_QOS_V2 RPC_SECURITY_QOS_V2_W
#define PRPC_SECURITY_QOS_V2 PRPC_SECURITY_QOS_V2_W
#define _RPC_SECURITY_QOS_V2 _RPC_SECURITY_QOS_V2_W
#define RPC_HTTP_TRANSPORT_CREDENTIALS RPC_HTTP_TRANSPORT_CREDENTIALS_W
#define PRPC_HTTP_TRANSPORT_CREDENTIALS PRPC_HTTP_TRANSPORT_CREDENTIALS_W
#define _RPC_HTTP_TRANSPORT_CREDENTIALS _RPC_HTTP_TRANSPORT_CREDENTIALS_W
#define RPC_SECURITY_QOS_V3 RPC_SECURITY_QOS_V3_W
#define PRPC_SECURITY_QOS_V3 PRPC_SECURITY_QOS_V3_W
#define _RPC_SECURITY_QOS_V3 _RPC_SECURITY_QOS_V3_W
#else 
#define RPC_SECURITY_QOS_V2 RPC_SECURITY_QOS_V2_A
#define PRPC_SECURITY_QOS_V2 PRPC_SECURITY_QOS_V2_A
#define _RPC_SECURITY_QOS_V2 _RPC_SECURITY_QOS_V2_A
#define RPC_HTTP_TRANSPORT_CREDENTIALS RPC_HTTP_TRANSPORT_CREDENTIALS_A
#define PRPC_HTTP_TRANSPORT_CREDENTIALS PRPC_HTTP_TRANSPORT_CREDENTIALS_A
#define _RPC_HTTP_TRANSPORT_CREDENTIALS _RPC_HTTP_TRANSPORT_CREDENTIALS_A
#define RPC_SECURITY_QOS_V3 RPC_SECURITY_QOS_V3_A
#define PRPC_SECURITY_QOS_V3 PRPC_SECURITY_QOS_V3_A
#define _RPC_SECURITY_QOS_V3 _RPC_SECURITY_QOS_V3_A
#endif 
typedef RPC_STATUS
(__RPC_USER * RPC_NEW_HTTP_PROXY_CHANNEL) (unsigned short __RPC_FAR *ServerName,unsigned short __RPC_FAR *ServerPort,unsigned char __RPC_FAR *RemoteUser,unsigned short __RPC_FAR **NewServerName);
typedef void
(__RPC_USER * RPC_HTTP_PROXY_FREE_STRING) (unsigned short __RPC_FAR *ServerName);
#define RPC_C_AUTHZ_NONE 0
#define RPC_C_AUTHZ_NAME 1
#define RPC_C_AUTHZ_DCE 2
#define RPC_C_AUTHZ_DEFAULT 0xffffffff
RPCRTAPI RPC_STATUS RPC_ENTRY RpcImpersonateClient (RPC_BINDING_HANDLE BindingHandle OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcRevertToSelfEx (RPC_BINDING_HANDLE BindingHandle OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcRevertToSelf ();
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthClientA (RPC_BINDING_HANDLE ClientBinding,OPTIONAL
	 RPC_AUTHZ_HANDLE __RPC_FAR * Privs,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthClientW (RPC_BINDING_HANDLE ClientBinding,OPTIONAL
	 RPC_AUTHZ_HANDLE __RPC_FAR * Privs,unsigned short __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthClientExA (RPC_BINDING_HANDLE ClientBinding,OPTIONAL
	 RPC_AUTHZ_HANDLE __RPC_FAR * Privs,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc,OPTIONAL
	 unsigned long Flags);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthClientExW (RPC_BINDING_HANDLE ClientBinding,OPTIONAL
	 RPC_AUTHZ_HANDLE __RPC_FAR * Privs,unsigned short __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc,OPTIONAL
	 unsigned long Flags);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthInfoA (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 RPC_AUTH_IDENTITY_HANDLE __RPC_FAR * AuthIdentity,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthInfoW (RPC_BINDING_HANDLE Binding,unsigned short __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 RPC_AUTH_IDENTITY_HANDLE __RPC_FAR * AuthIdentity,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingSetAuthInfoA (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * ServerPrincName,unsigned long AuthnLevel,unsigned long AuthnSvc,RPC_AUTH_IDENTITY_HANDLE AuthIdentity,OPTIONAL
	 unsigned long AuthzSvc);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingSetAuthInfoExA (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * ServerPrincName,unsigned long AuthnLevel,unsigned long AuthnSvc,RPC_AUTH_IDENTITY_HANDLE AuthIdentity,OPTIONAL
	 unsigned long AuthzSvc,RPC_SECURITY_QOS *SecurityQos OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingSetAuthInfoW (RPC_BINDING_HANDLE Binding,unsigned short __RPC_FAR * ServerPrincName,unsigned long AuthnLevel,unsigned long AuthnSvc,RPC_AUTH_IDENTITY_HANDLE AuthIdentity,OPTIONAL
	 unsigned long AuthzSvc);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingSetAuthInfoExW (RPC_BINDING_HANDLE Binding,unsigned short __RPC_FAR * ServerPrincName,unsigned long AuthnLevel,unsigned long AuthnSvc,RPC_AUTH_IDENTITY_HANDLE AuthIdentity,OPTIONAL
	 unsigned long AuthzSvc,OPTIONAL
	 RPC_SECURITY_QOS *SecurityQOS);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthInfoExA (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 RPC_AUTH_IDENTITY_HANDLE __RPC_FAR * AuthIdentity,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc,OPTIONAL
	 unsigned long RpcQosVersion,RPC_SECURITY_QOS *SecurityQOS);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthInfoExW (RPC_BINDING_HANDLE Binding,unsigned short __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 RPC_AUTH_IDENTITY_HANDLE __RPC_FAR * AuthIdentity,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc,unsigned long RpcQosVersion,RPC_SECURITY_QOS *SecurityQOS);
typedef void
(__RPC_USER * RPC_AUTH_KEY_RETRIEVAL_FN) (void __RPC_FAR * Arg,unsigned short __RPC_FAR * ServerPrincName,unsigned long KeyVer,void __RPC_FAR * __RPC_FAR * Key,RPC_STATUS __RPC_FAR * Status);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerRegisterAuthInfoA (unsigned char __RPC_FAR * ServerPrincName,unsigned long AuthnSvc,RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn,void __RPC_FAR * Arg OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerRegisterAuthInfoW (unsigned short __RPC_FAR * ServerPrincName,unsigned long AuthnSvc,RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn,void __RPC_FAR * Arg OPTIONAL);
#ifdef UNICODE
#define RpcBindingInqAuthClient RpcBindingInqAuthClientW
#define RpcBindingInqAuthClientEx RpcBindingInqAuthClientExW
#define RpcBindingInqAuthInfo RpcBindingInqAuthInfoW
#define RpcBindingSetAuthInfo RpcBindingSetAuthInfoW
#define RpcServerRegisterAuthInfo RpcServerRegisterAuthInfoW
#define RpcBindingInqAuthInfoEx RpcBindingInqAuthInfoExW
#define RpcBindingSetAuthInfoEx RpcBindingSetAuthInfoExW
#else 
#define RpcBindingInqAuthClient RpcBindingInqAuthClientA
#define RpcBindingInqAuthClientEx RpcBindingInqAuthClientExA
#define RpcBindingInqAuthInfo RpcBindingInqAuthInfoA
#define RpcBindingSetAuthInfo RpcBindingSetAuthInfoA
#define RpcServerRegisterAuthInfo RpcServerRegisterAuthInfoA
#define RpcBindingInqAuthInfoEx RpcBindingInqAuthInfoExA
#define RpcBindingSetAuthInfoEx RpcBindingSetAuthInfoExA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthClient (RPC_BINDING_HANDLE ClientBinding,OPTIONAL
	 RPC_AUTHZ_HANDLE __RPC_FAR * Privs,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthClientEx (RPC_BINDING_HANDLE ClientBinding,OPTIONAL
	 RPC_AUTHZ_HANDLE __RPC_FAR * Privs,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc,OPTIONAL
	 unsigned long Flags);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingInqAuthInfo (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * __RPC_FAR * ServerPrincName,OPTIONAL
	 unsigned long __RPC_FAR * AuthnLevel,OPTIONAL
	 unsigned long __RPC_FAR * AuthnSvc,OPTIONAL
	 RPC_AUTH_IDENTITY_HANDLE __RPC_FAR * AuthIdentity,OPTIONAL
	 unsigned long __RPC_FAR * AuthzSvc OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingSetAuthInfo (RPC_BINDING_HANDLE Binding,unsigned char __RPC_FAR * ServerPrincName,unsigned long AuthnLevel,unsigned long AuthnSvc,RPC_AUTH_IDENTITY_HANDLE AuthIdentity,OPTIONAL
	 unsigned long AuthzSvc);
typedef void
(__RPC_USER * RPC_AUTH_KEY_RETRIEVAL_FN) (void __RPC_FAR * Arg,unsigned char __RPC_FAR * ServerPrincName,unsigned long KeyVer,void __RPC_FAR * __RPC_FAR * Key,RPC_STATUS __RPC_FAR * Status);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerRegisterAuthInfo (unsigned char __RPC_FAR * ServerPrincName,unsigned long AuthnSvc,RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn,void __RPC_FAR * Arg OPTIONAL);
#endif 
#if !defined(_M_IA64)
typedef struct {
	unsigned char __RPC_FAR * UserName;
	unsigned char __RPC_FAR * ComputerName;
	unsigned short Privilege;
	unsigned long AuthFlags;
} RPC_CLIENT_INFORMATION1,__RPC_FAR * PRPC_CLIENT_INFORMATION1;
#endif
RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingServerFromClient (RPC_BINDING_HANDLE ClientBinding,RPC_BINDING_HANDLE __RPC_FAR * ServerBinding);
RPCRTAPI DECLSPEC_NORETURN void RPC_ENTRY RpcRaiseException (RPC_STATUS exception);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcTestCancel();
RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerTestCancel (RPC_BINDING_HANDLE BindingHandle OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcCancelThread(void * Thread);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcCancelThreadEx(void * Thread,long Timeout);
RPCRTAPI RPC_STATUS RPC_ENTRY UuidCreate (UUID __RPC_FAR * Uuid);
RPCRTAPI RPC_STATUS RPC_ENTRY UuidCreateSequential (UUID __RPC_FAR * Uuid);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY UuidToStringA (UUID __RPC_FAR * Uuid,unsigned char __RPC_FAR * __RPC_FAR * StringUuid);
RPCRTAPI RPC_STATUS RPC_ENTRY UuidFromStringA (unsigned char __RPC_FAR * StringUuid,UUID __RPC_FAR * Uuid);
RPCRTAPI RPC_STATUS RPC_ENTRY UuidToStringW (UUID __RPC_FAR * Uuid,unsigned short __RPC_FAR * __RPC_FAR * StringUuid);
RPCRTAPI RPC_STATUS RPC_ENTRY UuidFromStringW (unsigned short __RPC_FAR * StringUuid,UUID __RPC_FAR * Uuid);
#ifdef UNICODE
#define UuidFromString UuidFromStringW
#define UuidToString UuidToStringW
#else 
#define UuidFromString UuidFromStringA
#define UuidToString UuidToStringA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY UuidToString (UUID __RPC_FAR * Uuid,unsigned char __RPC_FAR * __RPC_FAR * StringUuid);
RPCRTAPI RPC_STATUS RPC_ENTRY UuidFromString (unsigned char __RPC_FAR * StringUuid,UUID __RPC_FAR * Uuid);
#endif 
RPCRTAPI signed int
RPC_ENTRY UuidCompare (UUID __RPC_FAR * Uuid1,UUID __RPC_FAR * Uuid2,RPC_STATUS __RPC_FAR * Status);
RPCRTAPI RPC_STATUS RPC_ENTRY UuidCreateNil (UUID __RPC_FAR * NilUuid);
RPCRTAPI int RPC_ENTRY UuidEqual (UUID __RPC_FAR * Uuid1,UUID __RPC_FAR * Uuid2,RPC_STATUS __RPC_FAR * Status);
RPCRTAPI unsigned short
RPC_ENTRY UuidHash (UUID __RPC_FAR * Uuid,RPC_STATUS __RPC_FAR * Status);
RPCRTAPI int RPC_ENTRY UuidIsNil (UUID __RPC_FAR * Uuid,RPC_STATUS __RPC_FAR * Status);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcEpRegisterNoReplaceA (RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR * BindingVector,UUID_VECTOR * UuidVector,unsigned char * Annotation);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcEpRegisterNoReplaceW (RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR * BindingVector,UUID_VECTOR * UuidVector,unsigned short * Annotation);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcEpRegisterA (RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR * BindingVector,UUID_VECTOR * UuidVector,unsigned char * Annotation);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcEpRegisterW (RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR * BindingVector,UUID_VECTOR * UuidVector,unsigned short * Annotation);
#ifdef UNICODE
#define RpcEpRegisterNoReplace RpcEpRegisterNoReplaceW
#define RpcEpRegister RpcEpRegisterW
#else 
#define RpcEpRegisterNoReplace RpcEpRegisterNoReplaceA
#define RpcEpRegister RpcEpRegisterA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcEpRegisterNoReplace (RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR * BindingVector,UUID_VECTOR * UuidVector,unsigned char * Annotation);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcEpRegister (RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR * BindingVector,UUID_VECTOR * UuidVector,unsigned char * Annotation);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcEpUnregister(RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR * BindingVector,UUID_VECTOR * UuidVector);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY DceErrorInqTextA (RPC_STATUS RpcStatus,unsigned char __RPC_FAR * ErrorText);
RPCRTAPI RPC_STATUS RPC_ENTRY DceErrorInqTextW (RPC_STATUS RpcStatus,unsigned short __RPC_FAR * ErrorText);
#ifdef UNICODE
#define DceErrorInqText DceErrorInqTextW
#else 
#define DceErrorInqText DceErrorInqTextA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY DceErrorInqText (RPC_STATUS RpcStatus,unsigned char __RPC_FAR * ErrorText);
#endif 
#define DCE_C_ERROR_STRING_LEN 256
typedef I_RPC_HANDLE * RPC_EP_INQ_HANDLE;
#define RPC_C_EP_ALL_ELTS 0
#define RPC_C_EP_MATCH_BY_IF 1
#define RPC_C_EP_MATCH_BY_OBJ 2
#define RPC_C_EP_MATCH_BY_BOTH 3
#define RPC_C_VERS_ALL 1
#define RPC_C_VERS_COMPATIBLE 2
#define RPC_C_VERS_EXACT 3
#define RPC_C_VERS_MAJOR_ONLY 4
#define RPC_C_VERS_UPTO 5
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtEpEltInqBegin (RPC_BINDING_HANDLE EpBinding,unsigned long InquiryType,RPC_IF_ID __RPC_FAR * IfId,unsigned long VersOption,UUID __RPC_FAR * ObjectUuid,RPC_EP_INQ_HANDLE __RPC_FAR * InquiryContext);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtEpEltInqDone (RPC_EP_INQ_HANDLE __RPC_FAR * InquiryContext);
#ifdef RPC_UNICODE_SUPPORTED
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtEpEltInqNextA (RPC_EP_INQ_HANDLE InquiryContext,RPC_IF_ID __RPC_FAR * IfId,RPC_BINDING_HANDLE __RPC_FAR * Binding,UUID __RPC_FAR * ObjectUuid,unsigned char __RPC_FAR * __RPC_FAR * Annotation OPTIONAL);
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtEpEltInqNextW (RPC_EP_INQ_HANDLE InquiryContext,RPC_IF_ID __RPC_FAR * IfId,RPC_BINDING_HANDLE __RPC_FAR * Binding,UUID __RPC_FAR * ObjectUuid,unsigned short __RPC_FAR * __RPC_FAR * Annotation OPTIONAL);
#ifdef UNICODE
#define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextW
#else 
#define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextA
#endif 
#else 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtEpEltInqNext (RPC_EP_INQ_HANDLE InquiryContext,RPC_IF_ID __RPC_FAR * IfId,RPC_BINDING_HANDLE __RPC_FAR * Binding,unsigned char __RPC_FAR * __RPC_FAR * Annotation OPTIONAL);
#endif 
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtEpUnregister (RPC_BINDING_HANDLE EpBinding,RPC_IF_ID __RPC_FAR * IfId,RPC_BINDING_HANDLE Binding,UUID __RPC_FAR * ObjectUuid OPTIONAL);
typedef int
(* RPC_MGMT_AUTHORIZATION_FN) (RPC_BINDING_HANDLE ClientBinding,unsigned long RequestedMgmtOperation,RPC_STATUS __RPC_FAR * Status);
#define RPC_C_MGMT_INQ_IF_IDS 0
#define RPC_C_MGMT_INQ_PRINC_NAME 1
#define RPC_C_MGMT_INQ_STATS 2
#define RPC_C_MGMT_IS_SERVER_LISTEN 3
#define RPC_C_MGMT_STOP_SERVER_LISTEN 4
RPCRTAPI RPC_STATUS RPC_ENTRY RpcMgmtSetAuthorizationFn (RPC_MGMT_AUTHORIZATION_FN AuthorizationFn);
#define RPC_C_PARM_MAX_PACKET_LENGTH 1
#define RPC_C_PARM_BUFFER_LENGTH 2
#define RPC_IF_AUTOLISTEN 1
#define RPC_IF_OLE 2
#define RPC_IF_ALLOW_UNKNOWN_AUTHORITY 4
#define RPC_IF_ALLOW_SECURE_ONLY 8
#define RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH 16
#include <rpcdcep.h>
#endif 
