#ifndef __RPCNSI_H__
#define __RPCNSI_H__
#pragma once
typedef void  * RPC_NS_HANDLE;
#define RPC_C_NS_SYNTAX_DEFAULT 0
#define RPC_C_NS_SYNTAX_DCE 3
#define RPC_C_PROFILE_DEFAULT_ELT 0
#define RPC_C_PROFILE_ALL_ELT 1
#define RPC_C_PROFILE_ALL_ELTS RPC_C_PROFILE_ALL_ELT
#define RPC_C_PROFILE_MATCH_BY_IF 2
#define RPC_C_PROFILE_MATCH_BY_MBR 3
#define RPC_C_PROFILE_MATCH_BY_BOTH 4
#define RPC_C_NS_DEFAULT_EXP_AGE -1
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingExportA(unsigned long EntryNameSyntax,unsigned char  * EntryName,RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR  * BindingVec,UUID_VECTOR __RPC_FAR * ObjectUuidVec OPTIONAL);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingUnexportA(unsigned long EntryNameSyntax,unsigned char  * EntryName,RPC_IF_HANDLE IfSpec,UUID_VECTOR  * ObjectUuidVec OPTIONAL);
#ifdef RPC_UNICODE_SUPPORTED
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingExportW(unsigned long EntryNameSyntax,unsigned short  * EntryName,RPC_IF_HANDLE IfSpec,RPC_BINDING_VECTOR  * BindingVec,UUID_VECTOR __RPC_FAR * ObjectUuidVec OPTIONAL);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingUnexportW(unsigned long EntryNameSyntax,unsigned short  * EntryName,RPC_IF_HANDLE IfSpec,UUID_VECTOR  * ObjectUuidVec OPTIONAL);
#endif
RPC_STATUS RPC_ENTRY
RpcNsBindingExportPnPA(unsigned long EntryNameSyntax,unsigned char * EntryName,RPC_IF_HANDLE IfSpec,UUID_VECTOR * ObjectVector OPTIONAL);
RPC_STATUS RPC_ENTRY
RpcNsBindingUnexportPnPA(unsigned long EntryNameSyntax,unsigned char * EntryName,RPC_IF_HANDLE IfSpec,UUID_VECTOR * ObjectVector OPTIONAL);
#ifdef RPC_UNICODE_SUPPORTED
RPC_STATUS RPC_ENTRY
RpcNsBindingExportPnPW(unsigned long EntryNameSyntax,unsigned short * EntryName,RPC_IF_HANDLE IfSpec,UUID_VECTOR * ObjectVector OPTIONAL);
RPC_STATUS RPC_ENTRY
RpcNsBindingUnexportPnPW(unsigned long EntryNameSyntax,unsigned short * EntryName,RPC_IF_HANDLE IfSpec,UUID_VECTOR * ObjectVector OPTIONAL);
#endif
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingLookupBeginA(unsigned long EntryNameSyntax,unsigned char  * EntryName,RPC_IF_HANDLE IfSpec,UUID  * ObjUuid,unsigned long BindingMaxCount,RPC_NS_HANDLE __RPC_FAR * LookupContext);
#ifdef RPC_UNICODE_SUPPORTED
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingLookupBeginW(unsigned long EntryNameSyntax,unsigned short  * EntryName,RPC_IF_HANDLE IfSpec,UUID  * ObjUuid,unsigned long BindingMaxCount,RPC_NS_HANDLE __RPC_FAR * LookupContext);
#endif
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingLookupNext(RPC_NS_HANDLE LookupContext,RPC_BINDING_VECTOR  *  * BindingVec);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingLookupDone(RPC_NS_HANDLE  * LookupContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupDeleteA(unsigned long GroupNameSyntax,unsigned char  * GroupName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrAddA(unsigned long GroupNameSyntax,unsigned char  * GroupName,unsigned long MemberNameSyntax,unsigned char  * MemberName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrRemoveA(unsigned long GroupNameSyntax,unsigned char  * GroupName,unsigned long MemberNameSyntax,unsigned char  * MemberName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrInqBeginA(unsigned long GroupNameSyntax,unsigned char  * GroupName,unsigned long MemberNameSyntax,RPC_NS_HANDLE  * InquiryContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrInqNextA(RPC_NS_HANDLE InquiryContext,unsigned char  *  * MemberName);
#ifdef RPC_UNICODE_SUPPORTED
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupDeleteW(unsigned long GroupNameSyntax,unsigned short  * GroupName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrAddW(unsigned long GroupNameSyntax,unsigned short  * GroupName,unsigned long MemberNameSyntax,unsigned short  * MemberName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrRemoveW(unsigned long GroupNameSyntax,unsigned short  * GroupName,unsigned long MemberNameSyntax,unsigned short  * MemberName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrInqBeginW(unsigned long GroupNameSyntax,unsigned short  * GroupName,unsigned long MemberNameSyntax,RPC_NS_HANDLE  * InquiryContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrInqNextW(RPC_NS_HANDLE InquiryContext,unsigned short  *  * MemberName);
#endif
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsGroupMbrInqDone(RPC_NS_HANDLE  * InquiryContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileDeleteA(unsigned long ProfileNameSyntax,unsigned char  * ProfileName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltAddA(unsigned long ProfileNameSyntax,unsigned char  * ProfileName,RPC_IF_ID  * IfId,unsigned long MemberNameSyntax,unsigned char __RPC_FAR * MemberName,unsigned long Priority,unsigned char __RPC_FAR * Annotation OPTIONAL);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltRemoveA(unsigned long ProfileNameSyntax,unsigned char  * ProfileName,RPC_IF_ID  * IfId,unsigned long MemberNameSyntax,unsigned char __RPC_FAR * MemberName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltInqBeginA(unsigned long ProfileNameSyntax,unsigned char  * ProfileName,unsigned long InquiryType,RPC_IF_ID  * IfId,unsigned long VersOption,unsigned long MemberNameSyntax,unsigned char __RPC_FAR * MemberName,
	 RPC_NS_HANDLE  * InquiryContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltInqNextA(RPC_NS_HANDLE InquiryContext,RPC_IF_ID  * IfId,unsigned char  * __RPC_FAR * MemberName,unsigned long __RPC_FAR * Priority,unsigned char __RPC_FAR * __RPC_FAR * Annotation);
#ifdef RPC_UNICODE_SUPPORTED
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileDeleteW(unsigned long ProfileNameSyntax,unsigned short  * ProfileName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltAddW(unsigned long ProfileNameSyntax,unsigned short  * ProfileName,RPC_IF_ID  * IfId,unsigned long MemberNameSyntax,unsigned short __RPC_FAR * MemberName,unsigned long Priority,unsigned short __RPC_FAR * Annotation OPTIONAL);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltRemoveW(unsigned long ProfileNameSyntax,unsigned short  * ProfileName,RPC_IF_ID  * IfId,unsigned long MemberNameSyntax,unsigned short __RPC_FAR * MemberName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltInqBeginW(unsigned long ProfileNameSyntax,unsigned short  * ProfileName,unsigned long InquiryType,RPC_IF_ID  * IfId,unsigned long VersOption,unsigned long MemberNameSyntax,unsigned short __RPC_FAR * MemberName,
	 RPC_NS_HANDLE  * InquiryContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltInqNextW(RPC_NS_HANDLE InquiryContext,RPC_IF_ID  * IfId,unsigned short  * __RPC_FAR * MemberName,unsigned long __RPC_FAR * Priority,unsigned short __RPC_FAR * __RPC_FAR * Annotation);
#endif
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsProfileEltInqDone(RPC_NS_HANDLE  * InquiryContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsEntryObjectInqBeginA(unsigned long EntryNameSyntax,unsigned char  * EntryName,RPC_NS_HANDLE  * InquiryContext);
#ifdef RPC_UNICODE_SUPPORTED
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsEntryObjectInqBeginW(unsigned long EntryNameSyntax,unsigned short  * EntryName,RPC_NS_HANDLE  * InquiryContext);
#endif
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsEntryObjectInqNext(RPC_NS_HANDLE InquiryContext,UUID  * ObjUuid);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsEntryObjectInqDone(RPC_NS_HANDLE  * InquiryContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsEntryExpandNameA(unsigned long EntryNameSyntax,unsigned char  * EntryName,unsigned char  * __RPC_FAR * ExpandedName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtBindingUnexportA(unsigned long EntryNameSyntax,unsigned char  * EntryName,RPC_IF_ID  * IfId,unsigned long VersOption,UUID_VECTOR __RPC_FAR * ObjectUuidVec OPTIONAL);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtEntryCreateA(unsigned long EntryNameSyntax,unsigned char  * EntryName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtEntryDeleteA(unsigned long EntryNameSyntax,unsigned char  * EntryName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtEntryInqIfIdsA(unsigned long EntryNameSyntax,unsigned char  * EntryName,RPC_IF_ID_VECTOR  * __RPC_FAR * IfIdVec);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtHandleSetExpAge(RPC_NS_HANDLE NsHandle,unsigned long ExpirationAge);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtInqExpAge(unsigned long  * ExpirationAge);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtSetExpAge(unsigned long ExpirationAge);
#ifdef RPC_UNICODE_SUPPORTED
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsEntryExpandNameW(unsigned long EntryNameSyntax,unsigned short  * EntryName,unsigned short  * __RPC_FAR * ExpandedName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtBindingUnexportW(unsigned long EntryNameSyntax,unsigned short  * EntryName,RPC_IF_ID  * IfId,unsigned long VersOption,UUID_VECTOR __RPC_FAR * ObjectUuidVec OPTIONAL);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtEntryCreateW(unsigned long EntryNameSyntax,unsigned short  * EntryName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtEntryDeleteW(unsigned long EntryNameSyntax,unsigned short  * EntryName);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsMgmtEntryInqIfIdsW(unsigned long EntryNameSyntax,unsigned short  * EntryName,RPC_IF_ID_VECTOR  * __RPC_FAR * IfIdVec);
#endif
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingImportBeginA(unsigned long EntryNameSyntax,unsigned char  * EntryName,RPC_IF_HANDLE IfSpec,UUID  * ObjUuid,RPC_NS_HANDLE __RPC_FAR * ImportContext);
#ifdef RPC_UNICODE_SUPPORTED
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingImportBeginW(unsigned long EntryNameSyntax,unsigned short  * EntryName,RPC_IF_HANDLE IfSpec,UUID  * ObjUuid,RPC_NS_HANDLE __RPC_FAR * ImportContext);
#endif
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingImportNext(RPC_NS_HANDLE ImportContext,RPC_BINDING_HANDLE  * Binding);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingImportDone(RPC_NS_HANDLE  * ImportContext);
RPCNSAPI RPC_STATUS RPC_ENTRY
RpcNsBindingSelect(RPC_BINDING_VECTOR  * BindingVec,RPC_BINDING_HANDLE  * Binding);
#ifdef UNICODE
#define RpcNsBindingLookupBegin RpcNsBindingLookupBeginW
#define RpcNsBindingImportBegin RpcNsBindingImportBeginW
#define RpcNsBindingExport RpcNsBindingExportW
#define RpcNsBindingUnexport RpcNsBindingUnexportW
#define RpcNsGroupDelete RpcNsGroupDeleteW
#define RpcNsGroupMbrAdd RpcNsGroupMbrAddW
#define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveW
#define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginW
#define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextW
#define RpcNsEntryExpandName RpcNsEntryExpandNameW
#define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginW
#define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportW
#define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateW
#define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteW
#define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsW
#define RpcNsProfileDelete RpcNsProfileDeleteW
#define RpcNsProfileEltAdd RpcNsProfileEltAddW
#define RpcNsProfileEltRemove RpcNsProfileEltRemoveW
#define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginW
#define RpcNsProfileEltInqNext RpcNsProfileEltInqNextW
#define RpcNsBindingExportPnP RpcNsBindingExportPnPW
#define RpcNsBindingUnexportPnP RpcNsBindingUnexportPnPW
#else
#define RpcNsBindingLookupBegin RpcNsBindingLookupBeginA
#define RpcNsBindingImportBegin RpcNsBindingImportBeginA
#define RpcNsBindingExport RpcNsBindingExportA
#define RpcNsBindingUnexport RpcNsBindingUnexportA
#define RpcNsGroupDelete RpcNsGroupDeleteA
#define RpcNsGroupMbrAdd RpcNsGroupMbrAddA
#define RpcNsGroupMbrRemove RpcNsGroupMbrRemoveA
#define RpcNsGroupMbrInqBegin RpcNsGroupMbrInqBeginA
#define RpcNsGroupMbrInqNext RpcNsGroupMbrInqNextA
#define RpcNsEntryExpandName RpcNsEntryExpandNameA
#define RpcNsEntryObjectInqBegin RpcNsEntryObjectInqBeginA
#define RpcNsMgmtBindingUnexport RpcNsMgmtBindingUnexportA
#define RpcNsMgmtEntryCreate RpcNsMgmtEntryCreateA
#define RpcNsMgmtEntryDelete RpcNsMgmtEntryDeleteA
#define RpcNsMgmtEntryInqIfIds RpcNsMgmtEntryInqIfIdsA
#define RpcNsProfileDelete RpcNsProfileDeleteA
#define RpcNsProfileEltAdd RpcNsProfileEltAddA
#define RpcNsProfileEltRemove RpcNsProfileEltRemoveA
#define RpcNsProfileEltInqBegin RpcNsProfileEltInqBeginA
#define RpcNsProfileEltInqNext RpcNsProfileEltInqNextA
#define RpcNsBindingExportPnP RpcNsBindingExportPnPA
#define RpcNsBindingUnexportPnP RpcNsBindingUnexportPnPA
#endif 
#endif 
