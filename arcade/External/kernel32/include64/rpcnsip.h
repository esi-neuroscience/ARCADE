#ifndef __rpcnsip_h__
#define __rpcnsip_h__
#pragma once
typedef struct {
   RPC_NS_HANDLE        LookupContext;
   RPC_BINDING_HANDLE   ProposedHandle;
   RPC_BINDING_VECTOR * Bindings;

} RPC_IMPORT_CONTEXT_P, * PRPC_IMPORT_CONTEXT_P;


RPCNSAPI RPC_STATUS RPC_ENTRY I_RpcNsGetBuffer( PRPC_MESSAGE Message );

RPCNSAPI
RPC_STATUS
RPC_ENTRY
I_RpcNsSendReceive(
    IN PRPC_MESSAGE Message,
    OUT RPC_BINDING_HANDLE __RPC_FAR * Handle
    );

RPCNSAPI
void
RPC_ENTRY
I_RpcNsRaiseException(
    IN PRPC_MESSAGE Message,
    IN RPC_STATUS Status
    );

RPCNSAPI
RPC_STATUS
RPC_ENTRY
I_RpcReBindBuffer(
    IN PRPC_MESSAGE Message
    );

RPCNSAPI
RPC_STATUS
RPC_ENTRY
I_NsServerBindSearch(
    );

RPCNSAPI
RPC_STATUS
RPC_ENTRY
I_NsClientBindSearch(
    );

RPCNSAPI
void
RPC_ENTRY
I_NsClientBindDone(
    );

#ifdef __cplusplus
}
#endif

#endif /* __RPCNSIP_H__ */

