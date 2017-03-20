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
#ifndef __propidl_h__
#define __propidl_h__
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#endif
#ifndef __IPropertyStorage_FWD_DEFINED__
#define __IPropertyStorage_FWD_DEFINED__
typedef interface IPropertyStorage IPropertyStorage;
#endif 
#ifndef __IPropertySetStorage_FWD_DEFINED__
#define __IPropertySetStorage_FWD_DEFINED__
typedef interface IPropertySetStorage IPropertySetStorage;
#endif 
#ifndef __IEnumSTATPROPSTG_FWD_DEFINED__
#define __IEnumSTATPROPSTG_FWD_DEFINED__
typedef interface IEnumSTATPROPSTG IEnumSTATPROPSTG;
#endif 
#ifndef __IEnumSTATPROPSETSTG_FWD_DEFINED__
#define __IEnumSTATPROPSETSTG_FWD_DEFINED__
typedef interface IEnumSTATPROPSETSTG IEnumSTATPROPSETSTG;
#endif 
#include "objidl.h"
#include "oaidl.h"
void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void *); 
#if (_MSC_VER >= 800)
#if _MSC_VER >= 1200
#endif
#endif
#if (_MSC_VER >= 1020)
#endif
typedef struct tagVersionedStream
{
GUID guidVersion;
IStream *pStream;
} VERSIONEDSTREAM;
typedef struct tagVersionedStream *LPVERSIONEDSTREAM;
#define	PROPSETFLAG_DEFAULT	(0)
#define	PROPSETFLAG_NONSIMPLE	(1)
#define	PROPSETFLAG_ANSI	(2)
#define	PROPSETFLAG_UNBUFFERED	(4)
#define	PROPSETFLAG_CASE_SENSITIVE	(8)
#define	PROPSET_BEHAVIOR_CASE_SENSITIVE	(1)
#ifdef MIDL_PASS
typedef struct tag_inner_PROPVARIANT PROPVARIANT;
#else
typedef struct tagPROPVARIANT PROPVARIANT;
#endif
typedef struct tagCAC
{
ULONG cElems;
CHAR *pElems;
} CAC;
typedef struct tagCAUB
{
ULONG cElems;
UCHAR *pElems;
} CAUB;
typedef struct tagCAI
{
ULONG cElems;
SHORT *pElems;
} CAI;
typedef struct tagCAUI
{
ULONG cElems;
USHORT *pElems;
} CAUI;
typedef struct tagCAL
{
ULONG cElems;
LONG *pElems;
} CAL;
typedef struct tagCAUL
{
ULONG cElems;
ULONG *pElems;
} CAUL;
typedef struct tagCAFLT
{
ULONG cElems;
FLOAT *pElems;
} CAFLT;
typedef struct tagCADBL
{
ULONG cElems;
DOUBLE *pElems;
} CADBL;
typedef struct tagCACY
{
ULONG cElems;
CY *pElems;
} CACY;
typedef struct tagCADATE
{
ULONG cElems;
DATE *pElems;
} CADATE;
typedef struct tagCABSTR
{
ULONG cElems;
BSTR *pElems;
} CABSTR;
typedef struct tagCABSTRBLOB
{
ULONG cElems;
BSTRBLOB *pElems;
} CABSTRBLOB;
typedef struct tagCABOOL
{
ULONG cElems;
VARIANT_BOOL *pElems;
} CABOOL;
typedef struct tagCASCODE
{
ULONG cElems;
SCODE *pElems;
} CASCODE;
typedef struct tagCAPROPVARIANT
{
ULONG cElems;
PROPVARIANT *pElems;
} CAPROPVARIANT;
typedef struct tagCAH
{
ULONG cElems;
LARGE_INTEGER *pElems;
} CAH;
typedef struct tagCAUH
{
ULONG cElems;
ULARGE_INTEGER *pElems;
} CAUH;
typedef struct tagCALPSTR
{
ULONG cElems;
LPSTR *pElems;
} CALPSTR;
typedef struct tagCALPWSTR
{
ULONG cElems;
LPWSTR *pElems;
} CALPWSTR;
typedef struct tagCAFILETIME
{
ULONG cElems;
FILETIME *pElems;
} CAFILETIME;
typedef struct tagCACLIPDATA
{
ULONG cElems;
CLIPDATA *pElems;
} CACLIPDATA;
typedef struct tagCACLSID
{
ULONG cElems;
CLSID *pElems;
} CACLSID;
#ifdef MIDL_PASS
typedef BYTE PROPVAR_PAD1;
typedef BYTE PROPVAR_PAD2;
typedef ULONG PROPVAR_PAD3;
#else
typedef WORD PROPVAR_PAD1;
typedef WORD PROPVAR_PAD2;
typedef WORD PROPVAR_PAD3;
#define tag_inner_PROPVARIANT
#endif
#ifndef MIDL_PASS
struct tagPROPVARIANT {
union {
#endif
struct tag_inner_PROPVARIANT
{
VARTYPE vt;
PROPVAR_PAD1 wReserved1;
PROPVAR_PAD2 wReserved2;
PROPVAR_PAD3 wReserved3;
union 
{
CHAR cVal;
UCHAR bVal;
SHORT iVal;
USHORT uiVal;
LONG lVal;
ULONG ulVal;
INT intVal;
UINT uintVal;
LARGE_INTEGER hVal;
ULARGE_INTEGER uhVal;
FLOAT fltVal;
DOUBLE dblVal;
VARIANT_BOOL boolVal;
SCODE scode;
CY cyVal;
DATE date;
FILETIME filetime;
CLSID *puuid;
CLIPDATA *pclipdata;
BSTR bstrVal;
BSTRBLOB bstrblobVal;
BLOB blob;
LPSTR pszVal;
LPWSTR pwszVal;
IUnknown *punkVal;
IDispatch *pdispVal;
IStream *pStream;
IStorage *pStorage;
LPVERSIONEDSTREAM pVersionedStream;
LPSAFEARRAY parray;
CAC cac;
CAUB caub;
CAI cai;
CAUI caui;
CAL cal;
CAUL caul;
CAH cah;
CAUH cauh;
CAFLT caflt;
CADBL cadbl;
CABOOL cabool;
CASCODE cascode;
CACY cacy;
CADATE cadate;
CAFILETIME cafiletime;
CACLSID cauuid;
CACLIPDATA caclipdata;
CABSTR cabstr;
CABSTRBLOB cabstrblob;
CALPSTR calpstr;
CALPWSTR calpwstr;
CAPROPVARIANT capropvar;
CHAR *pcVal;
UCHAR *pbVal;
SHORT *piVal;
USHORT *puiVal;
LONG *plVal;
ULONG *pulVal;
INT *pintVal;
UINT *puintVal;
FLOAT *pfltVal;
DOUBLE *pdblVal;
VARIANT_BOOL *pboolVal;
DECIMAL *pdecVal;
SCODE *pscode;
CY *pcyVal;
DATE *pdate;
BSTR *pbstrVal;
IUnknown **ppunkVal;
IDispatch **ppdispVal;
LPSAFEARRAY *pparray;
PROPVARIANT *pvarVal;
} ;
} ;
#ifndef MIDL_PASS
DECIMAL decVal;
};
};
#endif
#ifdef MIDL_PASS
typedef struct tag_inner_PROPVARIANT *LPPROPVARIANT;
#else
typedef struct tagPROPVARIANT * LPPROPVARIANT;
#endif
#define	PID_DICTIONARY	(0)
#define	PID_CODEPAGE	1
#define	PID_FIRST_USABLE	2
#define	PID_FIRST_NAME_DEFAULT	4095
#define	PID_LOCALE	0x80000000
#define	PID_MODIFY_TIME	0x80000001
#define	PID_SECURITY	0x80000002
#define	PID_BEHAVIOR	0x80000003
#define	PID_ILLEGAL	0xffffffff
#define	PID_MIN_READONLY	0x80000000
#define	PID_MAX_READONLY	0xbfffffff
#define PIDDI_THUMBNAIL 2
#define PIDSI_TITLE 2
#define PIDSI_SUBJECT 3
#define PIDSI_AUTHOR 4
#define PIDSI_KEYWORDS 5
#define PIDSI_COMMENTS 6
#define PIDSI_TEMPLATE 7
#define PIDSI_LASTAUTHOR 8
#define PIDSI_REVNUMBER 9
#define PIDSI_EDITTIME 10
#define PIDSI_LASTPRINTED 11
#define PIDSI_CREATE_DTM 12
#define PIDSI_LASTSAVE_DTM 13
#define PIDSI_PAGECOUNT 14
#define PIDSI_WORDCOUNT 15
#define PIDSI_CHARCOUNT 16
#define PIDSI_THUMBNAIL 17
#define PIDSI_APPNAME 18
#define PIDSI_DOC_SECURITY 19
#define PIDDSI_CATEGORY 2
#define PIDDSI_PRESFORMAT 3
#define PIDDSI_BYTECOUNT 4
#define PIDDSI_LINECOUNT 5
#define PIDDSI_PARCOUNT 6
#define PIDDSI_SLIDECOUNT 7
#define PIDDSI_NOTECOUNT 8
#define PIDDSI_HIDDENCOUNT 9
#define PIDDSI_MMCLIPCOUNT 10
#define PIDDSI_SCALE 11
#define PIDDSI_HEADINGPAIR 12
#define PIDDSI_DOCPARTS 13
#define PIDDSI_MANAGER 14
#define PIDDSI_COMPANY 15
#define PIDDSI_LINKSDIRTY 16
#define PIDMSI_EDITOR 2
#define PIDMSI_SUPPLIER 3
#define PIDMSI_SOURCE 4
#define PIDMSI_SEQUENCE_NO 5
#define PIDMSI_PROJECT 6
#define PIDMSI_STATUS 7
#define PIDMSI_OWNER 8
#define PIDMSI_RATING 9
#define PIDMSI_PRODUCTION 10
#define PIDMSI_COPYRIGHT 11
enum PIDMSI_STATUS_VALUE
{	PIDMSI_STATUS_NORMAL=0,
PIDMSI_STATUS_NEW=PIDMSI_STATUS_NORMAL + 1,
PIDMSI_STATUS_PRELIM=PIDMSI_STATUS_NEW + 1,
PIDMSI_STATUS_DRAFT=PIDMSI_STATUS_PRELIM + 1,
PIDMSI_STATUS_INPROGRESS=PIDMSI_STATUS_DRAFT + 1,
PIDMSI_STATUS_EDIT=PIDMSI_STATUS_INPROGRESS + 1,
PIDMSI_STATUS_REVIEW=PIDMSI_STATUS_EDIT + 1,
PIDMSI_STATUS_PROOF=PIDMSI_STATUS_REVIEW + 1,
PIDMSI_STATUS_FINAL=PIDMSI_STATUS_PROOF + 1,
PIDMSI_STATUS_OTHER=0x7fff
} ;
#define	PRSPEC_INVALID	0xffffffff
#define	PRSPEC_LPWSTR	(0)
#define	PRSPEC_PROPID	(1)
typedef struct tagPROPSPEC
{
ULONG ulKind;
union 
{
PROPID propid;
LPOLESTR lpwstr;
} ;
} PROPSPEC;
typedef struct tagSTATPROPSTG
{
LPOLESTR lpwstrName;
PROPID propid;
VARTYPE vt;
} STATPROPSTG;
#define PROPSETHDR_OSVER_KIND(dwOSVer) HIWORD((dwOSVer))
#define PROPSETHDR_OSVER_MAJOR(dwOSVer) LOBYTE(LOWORD((dwOSVer)))
#define PROPSETHDR_OSVER_MINOR(dwOSVer) HIBYTE(LOWORD((dwOSVer)))
#define PROPSETHDR_OSVERSION_UNKNOWN 0xffffffff
typedef struct tagSTATPROPSETSTG
{
FMTID fmtid;
CLSID clsid;
DWORD grfFlags;
FILETIME mtime;
FILETIME ctime;
FILETIME atime;
DWORD dwOSVersion;
} STATPROPSETSTG;
extern RPC_IF_HANDLE __MIDL_itf_propidl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_propidl_0000_v0_0_s_ifspec;
#ifndef __IPropertyStorage_INTERFACE_DEFINED__
#define __IPropertyStorage_INTERFACE_DEFINED__
EXTERN_C const IID IID_IPropertyStorage;
typedef struct IPropertyStorageVtbl
{
 BEGIN_INTERFACE
 HRESULT (_stdcall *QueryInterface)(IPropertyStorage *,REFIID,void **);
 ULONG (_stdcall *AddRef)(IPropertyStorage *);
 ULONG (_stdcall *Release)(IPropertyStorage *);
 HRESULT (_stdcall *ReadMultiple)(IPropertyStorage *,ULONG,const PROPSPEC *,PROPVARIANT *);
 HRESULT (_stdcall *WriteMultiple)(IPropertyStorage *,ULONG,const PROPSPEC *,const PROPVARIANT *,PROPID);
 HRESULT (_stdcall *DeleteMultiple)(IPropertyStorage *,ULONG,const PROPSPEC *);
 HRESULT (_stdcall *ReadPropertyNames)(IPropertyStorage *,ULONG,const PROPID *,LPOLESTR *);
 HRESULT (_stdcall *WritePropertyNames)(IPropertyStorage *,ULONG,const PROPID *,const LPOLESTR *);
 HRESULT (_stdcall *DeletePropertyNames)(IPropertyStorage *,ULONG,const PROPID *);
 HRESULT (_stdcall *Commit)(IPropertyStorage *,DWORD);
 HRESULT (_stdcall *Revert)(IPropertyStorage *);
 HRESULT (_stdcall *Enum)(IPropertyStorage *,IEnumSTATPROPSTG **);
 HRESULT (_stdcall *SetTimes)(IPropertyStorage *,const FILETIME *,const FILETIME *,const FILETIME *);
 HRESULT (_stdcall *SetClass)(IPropertyStorage *,REFCLSID);
 HRESULT (_stdcall *Stat)(IPropertyStorage *,STATPROPSETSTG *);
END_INTERFACE
} IPropertyStorageVtbl;
interface IPropertyStorage
{
CONST_VTBL struct IPropertyStorageVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPropertyStorage_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPropertyStorage_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPropertyStorage_Release(A) (A)->lpVtbl->Release(A)
#define IPropertyStorage_ReadMultiple(A,B,C,D) (A)->lpVtbl->ReadMultiple(A,B,C,D)
#define IPropertyStorage_WriteMultiple(A,B,C,D,E) (A)->lpVtbl->WriteMultiple(A,B,C,D,E)
#define IPropertyStorage_DeleteMultiple(A,B,C) (A)->lpVtbl->DeleteMultiple(A,B,C)
#define IPropertyStorage_ReadPropertyNames(A,B,C,D) (A)->lpVtbl->ReadPropertyNames(A,B,C,D)
#define IPropertyStorage_WritePropertyNames(A,B,C,D) (A)->lpVtbl->WritePropertyNames(A,B,C,D)
#define IPropertyStorage_DeletePropertyNames(A,B,C) (A)->lpVtbl->DeletePropertyNames(A,B,C)
#define IPropertyStorage_Commit(A,B) (A)->lpVtbl->Commit(A,B)
#define IPropertyStorage_Revert(A) (A)->lpVtbl->Revert(A)
#define IPropertyStorage_Enum(A,B) (A)->lpVtbl->Enum(A,B)
#define IPropertyStorage_SetTimes(A,B,C,D) (A)->lpVtbl->SetTimes(A,B,C,D)
#define IPropertyStorage_SetClass(A,B) (A)->lpVtbl->SetClass(A,B)
#define IPropertyStorage_Stat(A,B) (A)->lpVtbl->Stat(A,B)
#endif 
HRESULT _stdcall IPropertyStorage_ReadMultiple_Proxy(IPropertyStorage *,ULONG ,const PROPSPEC rgpspec[ ],PROPVARIANT rgpropvar[ ]);
void __RPC_STUB IPropertyStorage_ReadMultiple_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_WriteMultiple_Proxy(IPropertyStorage *,ULONG ,const PROPSPEC rgpspec[ ],const PROPVARIANT rgpropvar[ ],PROPID );
void __RPC_STUB IPropertyStorage_WriteMultiple_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_DeleteMultiple_Proxy(IPropertyStorage *,ULONG ,const PROPSPEC rgpspec[ ]);
void __RPC_STUB IPropertyStorage_DeleteMultiple_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_ReadPropertyNames_Proxy(IPropertyStorage *,ULONG ,const PROPID rgpropid[ ],LPOLESTR rglpwstrName[ ]);
void __RPC_STUB IPropertyStorage_ReadPropertyNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_WritePropertyNames_Proxy(IPropertyStorage *,ULONG ,const PROPID rgpropid[ ],const LPOLESTR rglpwstrName[ ]);
void __RPC_STUB IPropertyStorage_WritePropertyNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_DeletePropertyNames_Proxy(IPropertyStorage *,ULONG ,const PROPID rgpropid[ ]);
void __RPC_STUB IPropertyStorage_DeletePropertyNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_Commit_Proxy(IPropertyStorage *,DWORD );
void __RPC_STUB IPropertyStorage_Commit_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_Revert_Proxy(IPropertyStorage *);
void __RPC_STUB IPropertyStorage_Revert_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_Enum_Proxy(IPropertyStorage *,IEnumSTATPROPSTG **);
void __RPC_STUB IPropertyStorage_Enum_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_SetTimes_Proxy(IPropertyStorage *,const FILETIME *pctime,const FILETIME *patime,const FILETIME *pmtime);
void __RPC_STUB IPropertyStorage_SetTimes_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_SetClass_Proxy(IPropertyStorage *,REFCLSID );
void __RPC_STUB IPropertyStorage_SetClass_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertyStorage_Stat_Proxy(IPropertyStorage *,STATPROPSETSTG *);
void __RPC_STUB IPropertyStorage_Stat_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IPropertySetStorage_INTERFACE_DEFINED__
#define __IPropertySetStorage_INTERFACE_DEFINED__
typedef  IPropertySetStorage *LPPROPERTYSETSTORAGE;
EXTERN_C const IID IID_IPropertySetStorage;
typedef struct IPropertySetStorageVtbl
{
 BEGIN_INTERFACE
 HRESULT (_stdcall *QueryInterface)(IPropertySetStorage *,REFIID,void **);
 ULONG (_stdcall *AddRef)(IPropertySetStorage *);
 ULONG (_stdcall *Release)(IPropertySetStorage *);
 HRESULT (_stdcall *Create)(IPropertySetStorage *,REFFMTID,const CLSID *,DWORD,DWORD,IPropertyStorage **);
 HRESULT (_stdcall *Open)(IPropertySetStorage *,REFFMTID,DWORD,IPropertyStorage **);
 HRESULT (_stdcall *Delete)(IPropertySetStorage *,REFFMTID);
 HRESULT (_stdcall *Enum)(IPropertySetStorage *,IEnumSTATPROPSETSTG **);
END_INTERFACE
} IPropertySetStorageVtbl;
interface IPropertySetStorage
{
CONST_VTBL struct IPropertySetStorageVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPropertySetStorage_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPropertySetStorage_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPropertySetStorage_Release(A) (A)->lpVtbl->Release(A)
#define IPropertySetStorage_Create(A,B,C,D,E,F) (A)->lpVtbl->Create(A,B,C,D,E,F)
#define IPropertySetStorage_Open(A,B,C,D) (A)->lpVtbl->Open(A,B,C,D)
#define IPropertySetStorage_Delete(A,B) (A)->lpVtbl->Delete(A,B)
#define IPropertySetStorage_Enum(A,B) (A)->lpVtbl->Enum(A,B)
#endif 
HRESULT _stdcall IPropertySetStorage_Create_Proxy(IPropertySetStorage *,REFFMTID ,const CLSID *pclsid,DWORD ,DWORD ,IPropertyStorage **);
void __RPC_STUB IPropertySetStorage_Create_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertySetStorage_Open_Proxy(IPropertySetStorage *,REFFMTID ,DWORD ,IPropertyStorage **);
void __RPC_STUB IPropertySetStorage_Open_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertySetStorage_Delete_Proxy(IPropertySetStorage *,REFFMTID );
void __RPC_STUB IPropertySetStorage_Delete_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IPropertySetStorage_Enum_Proxy(IPropertySetStorage *,IEnumSTATPROPSETSTG **);
void __RPC_STUB IPropertySetStorage_Enum_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IEnumSTATPROPSTG_INTERFACE_DEFINED__
#define __IEnumSTATPROPSTG_INTERFACE_DEFINED__
typedef  IEnumSTATPROPSTG *LPENUMSTATPROPSTG;
EXTERN_C const IID IID_IEnumSTATPROPSTG;
typedef struct IEnumSTATPROPSTGVtbl
{
 BEGIN_INTERFACE
 HRESULT (_stdcall *QueryInterface)(IEnumSTATPROPSTG *,REFIID,void **);
 ULONG (_stdcall *AddRef)(IEnumSTATPROPSTG *);
 ULONG (_stdcall *Release)(IEnumSTATPROPSTG *);
 HRESULT (_stdcall *Next)(IEnumSTATPROPSTG *,ULONG,STATPROPSTG *,ULONG *);
 HRESULT (_stdcall *Skip)(IEnumSTATPROPSTG *,ULONG);
 HRESULT (_stdcall *Reset)(IEnumSTATPROPSTG *);
 HRESULT (_stdcall *Clone)(IEnumSTATPROPSTG *,IEnumSTATPROPSTG **);
END_INTERFACE
} IEnumSTATPROPSTGVtbl;
interface IEnumSTATPROPSTG
{
CONST_VTBL struct IEnumSTATPROPSTGVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumSTATPROPSTG_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumSTATPROPSTG_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumSTATPROPSTG_Release(A) (A)->lpVtbl->Release(A)
#define IEnumSTATPROPSTG_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumSTATPROPSTG_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumSTATPROPSTG_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumSTATPROPSTG_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT _stdcall IEnumSTATPROPSTG_RemoteNext_Proxy(IEnumSTATPROPSTG *,ULONG ,STATPROPSTG *,ULONG *);
void __RPC_STUB IEnumSTATPROPSTG_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IEnumSTATPROPSTG_Skip_Proxy(IEnumSTATPROPSTG *,ULONG );
void __RPC_STUB IEnumSTATPROPSTG_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IEnumSTATPROPSTG_Reset_Proxy(IEnumSTATPROPSTG *);
void __RPC_STUB IEnumSTATPROPSTG_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IEnumSTATPROPSTG_Clone_Proxy(IEnumSTATPROPSTG *,IEnumSTATPROPSTG **);
void __RPC_STUB IEnumSTATPROPSTG_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__
#define __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__
typedef  IEnumSTATPROPSETSTG *LPENUMSTATPROPSETSTG;
EXTERN_C const IID IID_IEnumSTATPROPSETSTG;
typedef struct IEnumSTATPROPSETSTGVtbl
{
 BEGIN_INTERFACE
 HRESULT (_stdcall *QueryInterface)(IEnumSTATPROPSETSTG *,REFIID,void **);
 ULONG (_stdcall *AddRef)(IEnumSTATPROPSETSTG *);
 ULONG (_stdcall *Release)(IEnumSTATPROPSETSTG *);
 HRESULT (_stdcall *Next)(IEnumSTATPROPSETSTG *,ULONG,STATPROPSETSTG *,ULONG *);
 HRESULT (_stdcall *Skip)(IEnumSTATPROPSETSTG *,ULONG);
 HRESULT (_stdcall *Reset)(IEnumSTATPROPSETSTG *);
 HRESULT (_stdcall *Clone)(IEnumSTATPROPSETSTG *,IEnumSTATPROPSETSTG **);
END_INTERFACE
} IEnumSTATPROPSETSTGVtbl;
interface IEnumSTATPROPSETSTG
{
CONST_VTBL struct IEnumSTATPROPSETSTGVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumSTATPROPSETSTG_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumSTATPROPSETSTG_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumSTATPROPSETSTG_Release(A) (A)->lpVtbl->Release(A)
#define IEnumSTATPROPSETSTG_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumSTATPROPSETSTG_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumSTATPROPSETSTG_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumSTATPROPSETSTG_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT _stdcall IEnumSTATPROPSETSTG_RemoteNext_Proxy(IEnumSTATPROPSETSTG *,ULONG ,STATPROPSETSTG *,ULONG *);
void __RPC_STUB IEnumSTATPROPSETSTG_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IEnumSTATPROPSETSTG_Skip_Proxy(IEnumSTATPROPSETSTG *,ULONG );
void __RPC_STUB IEnumSTATPROPSETSTG_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IEnumSTATPROPSETSTG_Reset_Proxy(IEnumSTATPROPSETSTG *);
void __RPC_STUB IEnumSTATPROPSETSTG_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT _stdcall IEnumSTATPROPSETSTG_Clone_Proxy(IEnumSTATPROPSETSTG *,IEnumSTATPROPSETSTG **);
void __RPC_STUB IEnumSTATPROPSETSTG_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
typedef  IPropertyStorage *LPPROPERTYSTORAGE;
WINOLEAPI PropVariantCopy (PROPVARIANT *,const PROPVARIANT * pvarSrc);
WINOLEAPI PropVariantClear (PROPVARIANT *);
WINOLEAPI FreePropVariantArray (ULONG ,PROPVARIANT *);
#define _PROPVARIANTINIT_DEFINED_
# ifdef __cplusplus
inline void PropVariantInit (PROPVARIANT *)
{
memset (pvar,0,sizeof(PROPVARIANT));
}
# else
# define PropVariantInit(pvar) memset ((pvar),0,sizeof(PROPVARIANT))
# endif
#ifndef _STGCREATEPROPSTG_DEFINED_
WINOLEAPI StgCreatePropStg(IUnknown* pUnk,REFFMTID ,const CLSID *pclsid,DWORD ,DWORD ,IPropertyStorage **);
WINOLEAPI StgOpenPropStg(IUnknown* pUnk,REFFMTID ,DWORD ,DWORD ,IPropertyStorage **);
WINOLEAPI StgCreatePropSetStg(IStorage *,DWORD ,IPropertySetStorage **);
#define CCH_MAX_PROPSTG_NAME 31
WINOLEAPI FmtIdToPropStgName(const FMTID *pfmtid,LPOLESTR );
WINOLEAPI PropStgNameToFmtId(const LPOLESTR oszName,FMTID *);
#endif
#if _MSC_VER >= 1200
#else
#endif
extern RPC_IF_HANDLE __MIDL_itf_propidl_0120_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_propidl_0120_v0_0_s_ifspec;
unsigned long __RPC_USER BSTR_UserSize(unsigned long *,unsigned ,BSTR *); 
unsigned char * __RPC_USER BSTR_UserMarshal(unsigned long *,unsigned char *,BSTR *); 
unsigned char * __RPC_USER BSTR_UserUnmarshal(unsigned long *,unsigned char *,BSTR *); 
void __RPC_USER BSTR_UserFree(unsigned long *,BSTR *); 
unsigned long __RPC_USER LPSAFEARRAY_UserSize(unsigned long *,unsigned ,LPSAFEARRAY *); 
unsigned char * __RPC_USER LPSAFEARRAY_UserMarshal(unsigned long *,unsigned char *,LPSAFEARRAY *); 
unsigned char * __RPC_USER LPSAFEARRAY_UserUnmarshal(unsigned long *,unsigned char *,LPSAFEARRAY *); 
void __RPC_USER LPSAFEARRAY_UserFree(unsigned long *,LPSAFEARRAY *); 
HRESULT _stdcall IEnumSTATPROPSTG_Next_Proxy(IEnumSTATPROPSTG *,ULONG ,STATPROPSTG *,ULONG *);
HRESULT _stdcall IEnumSTATPROPSTG_Next_Stub(IEnumSTATPROPSTG *,ULONG ,STATPROPSTG *,ULONG *);
HRESULT _stdcall IEnumSTATPROPSETSTG_Next_Proxy(IEnumSTATPROPSETSTG *,ULONG ,STATPROPSETSTG *,ULONG *);
HRESULT _stdcall IEnumSTATPROPSETSTG_Next_Stub(IEnumSTATPROPSETSTG *,ULONG ,STATPROPSETSTG *,ULONG *);
#endif
