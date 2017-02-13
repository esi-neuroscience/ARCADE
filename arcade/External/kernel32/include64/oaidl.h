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
#ifndef __oaidl_h__
#define __oaidl_h__
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#endif
#ifndef __ICreateTypeInfo_FWD_DEFINED__
#define __ICreateTypeInfo_FWD_DEFINED__
typedef interface ICreateTypeInfo ICreateTypeInfo;
#endif 
#ifndef __ICreateTypeInfo2_FWD_DEFINED__
#define __ICreateTypeInfo2_FWD_DEFINED__
typedef interface ICreateTypeInfo2 ICreateTypeInfo2;
#endif 
#ifndef __ICreateTypeLib_FWD_DEFINED__
#define __ICreateTypeLib_FWD_DEFINED__
typedef interface ICreateTypeLib ICreateTypeLib;
#endif 
#ifndef __ICreateTypeLib2_FWD_DEFINED__
#define __ICreateTypeLib2_FWD_DEFINED__
typedef interface ICreateTypeLib2 ICreateTypeLib2;
#endif 
#ifndef __IDispatch_FWD_DEFINED__
#define __IDispatch_FWD_DEFINED__
typedef interface IDispatch IDispatch;
#endif 
#ifndef __IEnumVARIANT_FWD_DEFINED__
#define __IEnumVARIANT_FWD_DEFINED__
typedef interface IEnumVARIANT IEnumVARIANT;
#endif 
#ifndef __ITypeComp_FWD_DEFINED__
#define __ITypeComp_FWD_DEFINED__
typedef interface ITypeComp ITypeComp;
#endif 
#ifndef __ITypeInfo_FWD_DEFINED__
#define __ITypeInfo_FWD_DEFINED__
typedef interface ITypeInfo ITypeInfo;
#endif 
#ifndef __ITypeInfo2_FWD_DEFINED__
#define __ITypeInfo2_FWD_DEFINED__
typedef interface ITypeInfo2 ITypeInfo2;
#endif 
#ifndef __ITypeLib_FWD_DEFINED__
#define __ITypeLib_FWD_DEFINED__
typedef interface ITypeLib ITypeLib;
#endif 
#ifndef __ITypeLib2_FWD_DEFINED__
#define __ITypeLib2_FWD_DEFINED__
typedef interface ITypeLib2 ITypeLib2;
#endif 
#ifndef __ITypeChangeEvents_FWD_DEFINED__
#define __ITypeChangeEvents_FWD_DEFINED__
typedef interface ITypeChangeEvents ITypeChangeEvents;
#endif 
#ifndef __IErrorInfo_FWD_DEFINED__
#define __IErrorInfo_FWD_DEFINED__
typedef interface IErrorInfo IErrorInfo;
#endif 
#ifndef __ICreateErrorInfo_FWD_DEFINED__
#define __ICreateErrorInfo_FWD_DEFINED__
typedef interface ICreateErrorInfo ICreateErrorInfo;
#endif 
#ifndef __ISupportErrorInfo_FWD_DEFINED__
#define __ISupportErrorInfo_FWD_DEFINED__
typedef interface ISupportErrorInfo ISupportErrorInfo;
#endif 
#ifndef __ITypeFactory_FWD_DEFINED__
#define __ITypeFactory_FWD_DEFINED__
typedef interface ITypeFactory ITypeFactory;
#endif 
#ifndef __ITypeMarshal_FWD_DEFINED__
#define __ITypeMarshal_FWD_DEFINED__
typedef interface ITypeMarshal ITypeMarshal;
#endif 
#ifndef __IRecordInfo_FWD_DEFINED__
#define __IRecordInfo_FWD_DEFINED__
typedef interface IRecordInfo IRecordInfo;
#endif 
#ifndef __IErrorLog_FWD_DEFINED__
#define __IErrorLog_FWD_DEFINED__
typedef interface IErrorLog IErrorLog;
#endif 
#ifndef __IPropertyBag_FWD_DEFINED__
#define __IPropertyBag_FWD_DEFINED__
typedef interface IPropertyBag IPropertyBag;
#endif 
#include "objidl.h"
void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void *); 
#if (_MSC_VER >= 800)
#if _MSC_VER >= 1200
#endif
#endif
#if (_MSC_VER >= 1020)
#endif
extern RPC_IF_HANDLE __MIDL_itf_oaidl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oaidl_0000_v0_0_s_ifspec;
#ifndef __IOleAutomationTypes_INTERFACE_DEFINED__
#define __IOleAutomationTypes_INTERFACE_DEFINED__
typedef CY CURRENCY;
typedef struct tagSAFEARRAYBOUND
{
ULONG cElements;
LONG lLbound;
} SAFEARRAYBOUND;
typedef struct tagSAFEARRAYBOUND *LPSAFEARRAYBOUND;
typedef  struct _wireVARIANT *wireVARIANT;
typedef  struct _wireBRECORD *wireBRECORD;
typedef struct _wireSAFEARR_BSTR
{
ULONG Size;
wireBSTR *aBstr;
} SAFEARR_BSTR;
typedef struct _wireSAFEARR_UNKNOWN
{
ULONG Size;
IUnknown **apUnknown;
} SAFEARR_UNKNOWN;
typedef struct _wireSAFEARR_DISPATCH
{
ULONG Size;
IDispatch **apDispatch;
} SAFEARR_DISPATCH;
typedef struct _wireSAFEARR_VARIANT
{
ULONG Size;
wireVARIANT *aVariant;
} SAFEARR_VARIANT;
typedef struct _wireSAFEARR_BRECORD
{
ULONG Size;
wireBRECORD *aRecord;
} SAFEARR_BRECORD;
typedef struct _wireSAFEARR_HAVEIID
{
ULONG Size;
IUnknown **apUnknown;
IID iid;
} SAFEARR_HAVEIID;
typedef  
enum tagSF_TYPE
{	SF_ERROR=VT_ERROR,
SF_I1=VT_I1,
SF_I2=VT_I2,
SF_I4=VT_I4,
SF_I8=VT_I8,
SF_BSTR=VT_BSTR,
SF_UNKNOWN=VT_UNKNOWN,
SF_DISPATCH=VT_DISPATCH,
SF_VARIANT=VT_VARIANT,
SF_RECORD=VT_RECORD,
SF_HAVEIID=VT_UNKNOWN | VT_RESERVED
} SF_TYPE;
typedef struct _wireSAFEARRAY_UNION
{
ULONG sfType;
union __MIDL_IOleAutomationTypes_0001
{
SAFEARR_BSTR BstrStr;
SAFEARR_UNKNOWN UnknownStr;
SAFEARR_DISPATCH DispatchStr;
SAFEARR_VARIANT VariantStr;
SAFEARR_BRECORD RecordStr;
SAFEARR_HAVEIID HaveIidStr;
BYTE_SIZEDARR ByteStr;
WORD_SIZEDARR WordStr;
DWORD_SIZEDARR LongStr;
HYPER_SIZEDARR HyperStr;
} u;
} SAFEARRAYUNION;
typedef  struct _wireSAFEARRAY
{
USHORT cDims;
USHORT fFeatures;
ULONG cbElements;
ULONG cLocks;
SAFEARRAYUNION uArrayStructs;
SAFEARRAYBOUND rgsabound[ 1 ];
} *wireSAFEARRAY;
typedef  wireSAFEARRAY *wirePSAFEARRAY;
typedef struct tagSAFEARRAY
{
USHORT cDims;
USHORT fFeatures;
ULONG cbElements;
ULONG cLocks;
PVOID pvData;
SAFEARRAYBOUND rgsabound[ 1 ];
} SAFEARRAY;
typedef  SAFEARRAY *LPSAFEARRAY;
#define	FADF_AUTO	1
#define	FADF_STATIC	2
#define	FADF_EMBEDDED	4
#define	FADF_FIXEDSIZE	16
#define	FADF_RECORD	32
#define	FADF_HAVEIID	64
#define	FADF_HAVEVARTYPE	128
#define	FADF_BSTR	256
#define	FADF_UNKNOWN	512
#define	FADF_DISPATCH	1024
#define	FADF_VARIANT	2048
#define	FADF_RESERVED	0xf008
#define __tagVARIANT
#define __VARIANT_NAME_1
#define __VARIANT_NAME_2
#define __VARIANT_NAME_3
#define __tagBRECORD
#define __VARIANT_NAME_4
typedef  struct tagVARIANT VARIANT;
struct tagVARIANT {
	union {
	struct __tagVARIANT {
		VARTYPE vt;
		WORD wReserved1;
		WORD wReserved2;
		WORD wReserved3;
		union {
			LONGLONG llVal;
			LONG lVal;
			BYTE bVal;
			SHORT iVal;
			FLOAT fltVal;
			DOUBLE dblVal;
			VARIANT_BOOL boolVal;
			SCODE scode;
			CY cyVal;
			DATE date;
			BSTR bstrVal;
			IUnknown *punkVal;
			IDispatch *pdispVal;
			SAFEARRAY *parray;
			BYTE *pbVal;
			SHORT *piVal;
			LONG *plVal;
			LONGLONG *pllVal;
			FLOAT *pfltVal;
			DOUBLE *pdblVal;
			VARIANT_BOOL *pboolVal;
			SCODE *pscode;
			CY *pcyVal;
			DATE *pdate;
			BSTR *pbstrVal;
			IUnknown **ppunkVal;
			IDispatch **ppdispVal;
			SAFEARRAY **pparray;
			VARIANT *pvarVal;
			PVOID byref;
			CHAR cVal;
			USHORT uiVal;
			ULONG ulVal;
			ULONGLONG ullVal;
			INT intVal;
			UINT uintVal;
			DECIMAL *pdecVal;
			CHAR *pcVal;
			USHORT *puiVal;
			ULONG *pulVal;
			ULONGLONG *pullVal;
			INT *pintVal;
			UINT *puintVal;
			struct __tagBRECORD {
				PVOID pvRecord;
				IRecordInfo *pRecInfo;
			} __VARIANT_NAME_4;
		} __VARIANT_NAME_3;
	} __VARIANT_NAME_2;
	DECIMAL decVal;
} __VARIANT_NAME_1;
} ;
typedef VARIANT *LPVARIANT;
typedef VARIANT VARIANTARG;
typedef VARIANT *LPVARIANTARG;
struct _wireBRECORD
{
ULONG fFlags;
ULONG clSize;
IRecordInfo *pRecInfo;
byte *pRecord;
} ;
struct _wireVARIANT
{
DWORD clSize;
DWORD rpcReserved;
USHORT vt;
USHORT wReserved1;
USHORT wReserved2;
USHORT wReserved3;
union 
{
LONGLONG llVal;
LONG lVal;
BYTE bVal;
SHORT iVal;
FLOAT fltVal;
DOUBLE dblVal;
VARIANT_BOOL boolVal;
SCODE scode;
CY cyVal;
DATE date;
wireBSTR bstrVal;
IUnknown *punkVal;
IDispatch *pdispVal;
wirePSAFEARRAY parray;
wireBRECORD brecVal;
BYTE *pbVal;
SHORT *piVal;
LONG *plVal;
LONGLONG *pllVal;
FLOAT *pfltVal;
DOUBLE *pdblVal;
VARIANT_BOOL *pboolVal;
SCODE *pscode;
CY *pcyVal;
DATE *pdate;
wireBSTR *pbstrVal;
IUnknown **ppunkVal;
IDispatch **ppdispVal;
wirePSAFEARRAY *pparray;
wireVARIANT *pvarVal;
CHAR cVal;
USHORT uiVal;
ULONG ulVal;
ULONGLONG ullVal;
INT intVal;
UINT uintVal;
DECIMAL decVal;
DECIMAL *pdecVal;
CHAR *pcVal;
USHORT *puiVal;
ULONG *pulVal;
ULONGLONG *pullVal;
INT *pintVal;
UINT *puintVal;
} ;
} ;
typedef LONG DISPID;
typedef DISPID MEMBERID;
typedef DWORD HREFTYPE;
typedef  
enum tagTYPEKIND
{	TKIND_ENUM=0,
TKIND_RECORD=TKIND_ENUM + 1,
TKIND_MODULE=TKIND_RECORD + 1,
TKIND_INTERFACE=TKIND_MODULE + 1,
TKIND_DISPATCH=TKIND_INTERFACE + 1,
TKIND_COCLASS=TKIND_DISPATCH + 1,
TKIND_ALIAS=TKIND_COCLASS + 1,
TKIND_UNION=TKIND_ALIAS + 1,
TKIND_MAX=TKIND_UNION + 1
} TYPEKIND;
typedef struct tagTYPEDESC
{
union 
{
struct tagTYPEDESC *lptdesc;
struct tagARRAYDESC *lpadesc;
HREFTYPE hreftype;
} ;
VARTYPE vt;
} TYPEDESC;
typedef struct tagARRAYDESC
{
TYPEDESC tdescElem;
USHORT cDims;
SAFEARRAYBOUND rgbounds[ 1 ];
} ARRAYDESC;
typedef struct tagPARAMDESCEX
{
ULONG cBytes;
VARIANTARG varDefaultValue;
} PARAMDESCEX;
typedef struct tagPARAMDESCEX *LPPARAMDESCEX;
typedef struct tagPARAMDESC
{
LPPARAMDESCEX pparamdescex;
USHORT wParamFlags;
} PARAMDESC;
typedef struct tagPARAMDESC *LPPARAMDESC;
#define	PARAMFLAG_NONE	(0)
#define	PARAMFLAG_FIN	1
#define	PARAMFLAG_FOUT	2
#define	PARAMFLAG_FLCID	4
#define	PARAMFLAG_FRETVAL	8
#define	PARAMFLAG_FOPT	16
#define	PARAMFLAG_FHASDEFAULT	32
#define	PARAMFLAG_FHASCUSTDATA	64
typedef struct tagIDLDESC
{
ULONG_PTR dwReserved;
USHORT wIDLFlags;
} IDLDESC;
typedef struct tagIDLDESC *LPIDLDESC;
#define	IDLFLAG_NONE	(PARAMFLAG_NONE)
#define	IDLFLAG_FIN	(PARAMFLAG_FIN)
#define	IDLFLAG_FOUT	(PARAMFLAG_FOUT)
#define	IDLFLAG_FLCID	(PARAMFLAG_FLCID)
#define	IDLFLAG_FRETVAL	(PARAMFLAG_FRETVAL)
#if 0
typedef struct tagELEMDESC
{
TYPEDESC tdesc;
PARAMDESC paramdesc;
} ELEMDESC;
#else 
typedef struct tagELEMDESC {
TYPEDESC tdesc; 
union {
IDLDESC idldesc; 
PARAMDESC paramdesc; 
};
} ELEMDESC,* LPELEMDESC;
#endif 
typedef struct tagTYPEATTR
{
GUID guid;
LCID lcid;
DWORD dwReserved;
MEMBERID memidConstructor;
MEMBERID memidDestructor;
LPOLESTR lpstrSchema;
ULONG cbSizeInstance;
TYPEKIND typekind;
WORD cFuncs;
WORD cVars;
WORD cImplTypes;
WORD cbSizeVft;
WORD cbAlignment;
WORD wTypeFlags;
WORD wMajorVerNum;
WORD wMinorVerNum;
TYPEDESC tdescAlias;
IDLDESC idldescType;
} TYPEATTR;
typedef struct tagTYPEATTR *LPTYPEATTR;
typedef struct tagDISPPARAMS
{
VARIANTARG *rgvarg;
DISPID *rgdispidNamedArgs;
UINT cArgs;
UINT cNamedArgs;
} DISPPARAMS;
#if 0
typedef struct tagEXCEPINFO
{
WORD wCode;
WORD wReserved;
BSTR bstrSource;
BSTR bstrDescription;
BSTR bstrHelpFile;
DWORD dwHelpContext;
ULONG_PTR pvReserved;
ULONG_PTR pfnDeferredFillIn;
SCODE scode;
} EXCEPINFO;
#else 
typedef struct tagEXCEPINFO {
WORD wCode;
WORD wReserved;
BSTR bstrSource;
BSTR bstrDescription;
BSTR bstrHelpFile;
DWORD dwHelpContext;
PVOID pvReserved;
HRESULT (*pfnDeferredFillIn)(struct tagEXCEPINFO *);
SCODE scode;
} EXCEPINFO,* LPEXCEPINFO;
#endif 
typedef  
enum tagCALLCONV
{	CC_FASTCALL=0,
CC_CDECL=1,
CC_MSCPASCAL=CC_CDECL + 1,
CC_PASCAL=CC_MSCPASCAL,
CC_MACPASCAL=CC_PASCAL + 1,
CC_STDCALL=CC_MACPASCAL + 1,
CC_FPFASTCALL=CC_STDCALL + 1,
CC_SYSCALL=CC_FPFASTCALL + 1,
CC_MPWCDECL=CC_SYSCALL + 1,
CC_MPWPASCAL=CC_MPWCDECL + 1,
CC_MAX=CC_MPWPASCAL + 1
} CALLCONV;
typedef  
enum tagFUNCKIND
{	FUNC_VIRTUAL=0,
FUNC_PUREVIRTUAL=FUNC_VIRTUAL + 1,
FUNC_NONVIRTUAL=FUNC_PUREVIRTUAL + 1,
FUNC_STATIC=FUNC_NONVIRTUAL + 1,
FUNC_DISPATCH=FUNC_STATIC + 1
} FUNCKIND;
typedef  
enum tagINVOKEKIND
{	INVOKE_FUNC=1,
INVOKE_PROPERTYGET=2,
INVOKE_PROPERTYPUT=4,
INVOKE_PROPERTYPUTREF=8
} INVOKEKIND;
typedef struct tagFUNCDESC
{
MEMBERID memid;
SCODE *lprgscode;
ELEMDESC *lprgelemdescParam;
FUNCKIND funckind;
INVOKEKIND invkind;
CALLCONV callconv;
SHORT cParams;
SHORT cParamsOpt;
SHORT oVft;
SHORT cScodes;
ELEMDESC elemdescFunc;
WORD wFuncFlags;
} FUNCDESC;
typedef struct tagFUNCDESC *LPFUNCDESC;
typedef  
enum tagVARKIND
{	VAR_PERINSTANCE=0,
VAR_STATIC=VAR_PERINSTANCE + 1,
VAR_CONST=VAR_STATIC + 1,
VAR_DISPATCH=VAR_CONST + 1
} VARKIND;
#define	IMPLTYPEFLAG_FDEFAULT	1
#define	IMPLTYPEFLAG_FSOURCE	2
#define	IMPLTYPEFLAG_FRESTRICTED	4
#define	IMPLTYPEFLAG_FDEFAULTVTABLE	8
typedef struct tagVARDESC
{
MEMBERID memid;
LPOLESTR lpstrSchema;
union 
{
ULONG oInst;
VARIANT *lpvarValue;
} ;
ELEMDESC elemdescVar;
WORD wVarFlags;
VARKIND varkind;
} VARDESC;
typedef struct tagVARDESC *LPVARDESC;
typedef 
enum tagTYPEFLAGS
{	TYPEFLAG_FAPPOBJECT=1,
TYPEFLAG_FCANCREATE=2,
TYPEFLAG_FLICENSED=4,
TYPEFLAG_FPREDECLID=8,
TYPEFLAG_FHIDDEN=16,
TYPEFLAG_FCONTROL=32,
TYPEFLAG_FDUAL=64,
TYPEFLAG_FNONEXTENSIBLE=128,
TYPEFLAG_FOLEAUTOMATION=256,
TYPEFLAG_FRESTRICTED=512,
TYPEFLAG_FAGGREGATABLE=1024,
TYPEFLAG_FREPLACEABLE=2048,
TYPEFLAG_FDISPATCHABLE=4096,
TYPEFLAG_FREVERSEBIND=0x2000,
TYPEFLAG_FPROXY=0x4000
} TYPEFLAGS;
typedef 
enum tagFUNCFLAGS
{	FUNCFLAG_FRESTRICTED=1,
FUNCFLAG_FSOURCE=2,
FUNCFLAG_FBINDABLE=4,
FUNCFLAG_FREQUESTEDIT=8,
FUNCFLAG_FDISPLAYBIND=16,
FUNCFLAG_FDEFAULTBIND=32,
FUNCFLAG_FHIDDEN=64,
FUNCFLAG_FUSESGETLASTERROR=128,
FUNCFLAG_FDEFAULTCOLLELEM=256,
FUNCFLAG_FUIDEFAULT=512,
FUNCFLAG_FNONBROWSABLE=1024,
FUNCFLAG_FREPLACEABLE=2048,
FUNCFLAG_FIMMEDIATEBIND=4096
} FUNCFLAGS;
typedef 
enum tagVARFLAGS
{	VARFLAG_FREADONLY=1,
VARFLAG_FSOURCE=2,
VARFLAG_FBINDABLE=4,
VARFLAG_FREQUESTEDIT=8,
VARFLAG_FDISPLAYBIND=16,
VARFLAG_FDEFAULTBIND=32,
VARFLAG_FHIDDEN=64,
VARFLAG_FRESTRICTED=128,
VARFLAG_FDEFAULTCOLLELEM=256,
VARFLAG_FUIDEFAULT=512,
VARFLAG_FNONBROWSABLE=1024,
VARFLAG_FREPLACEABLE=2048,
VARFLAG_FIMMEDIATEBIND=4096
} VARFLAGS;
typedef  struct tagCLEANLOCALSTORAGE
{
IUnknown *pInterface;
PVOID pStorage;
DWORD flags;
} CLEANLOCALSTORAGE;
typedef struct tagCUSTDATAITEM
{
GUID guid;
VARIANTARG varValue;
} CUSTDATAITEM;
typedef struct tagCUSTDATAITEM *LPCUSTDATAITEM;
typedef struct tagCUSTDATA
{
DWORD cCustData;
LPCUSTDATAITEM prgCustData;
} CUSTDATA;
typedef struct tagCUSTDATA *LPCUSTDATA;
extern RPC_IF_HANDLE IOleAutomationTypes_v1_0_c_ifspec;
extern RPC_IF_HANDLE IOleAutomationTypes_v1_0_s_ifspec;
#endif 
#ifndef __ICreateTypeInfo_INTERFACE_DEFINED__
#define __ICreateTypeInfo_INTERFACE_DEFINED__
typedef  ICreateTypeInfo *LPCREATETYPEINFO;
EXTERN_C const IID IID_ICreateTypeInfo;
typedef struct ICreateTypeInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ICreateTypeInfo *,REFIID,void **);
 ULONG (*AddRef)(ICreateTypeInfo *);
 ULONG (*Release)(ICreateTypeInfo *);
 HRESULT (*SetGuid)(ICreateTypeInfo *,REFGUID);
 HRESULT (*SetTypeFlags)(ICreateTypeInfo *,UINT);
 HRESULT (*SetDocString)(ICreateTypeInfo *,LPOLESTR);
 HRESULT (*SetHelpContext)(ICreateTypeInfo *,DWORD);
 HRESULT (*SetVersion)(ICreateTypeInfo *,WORD,WORD);
 HRESULT (*AddRefTypeInfo)(ICreateTypeInfo *,ITypeInfo *,HREFTYPE *);
 HRESULT (*AddFuncDesc)(ICreateTypeInfo *,UINT,FUNCDESC *);
 HRESULT (*AddImplType)(ICreateTypeInfo *,UINT,HREFTYPE);
 HRESULT (*SetImplTypeFlags)(ICreateTypeInfo *,UINT,INT);
 HRESULT (*SetAlignment)(ICreateTypeInfo *,WORD);
 HRESULT (*SetSchema)(ICreateTypeInfo *,LPOLESTR);
 HRESULT (*AddVarDesc)(ICreateTypeInfo *,UINT,VARDESC *);
 HRESULT (*SetFuncAndParamNames)(ICreateTypeInfo *,UINT,LPOLESTR *,UINT);
 HRESULT (*SetVarName)(ICreateTypeInfo *,UINT,LPOLESTR);
 HRESULT (*SetTypeDescAlias)(ICreateTypeInfo *,TYPEDESC *);
 HRESULT (*DefineFuncAsDllEntry)(ICreateTypeInfo *,UINT,LPOLESTR,LPOLESTR);
 HRESULT (*SetFuncDocString)(ICreateTypeInfo *,UINT,LPOLESTR);
 HRESULT (*SetVarDocString)(ICreateTypeInfo *,UINT,LPOLESTR);
 HRESULT (*SetFuncHelpContext)(ICreateTypeInfo *,UINT,DWORD);
 HRESULT (*SetVarHelpContext)(ICreateTypeInfo *,UINT,DWORD);
 HRESULT (*SetMops)(ICreateTypeInfo *,UINT,BSTR);
 HRESULT (*SetTypeIdldesc)(ICreateTypeInfo *,IDLDESC *);
 HRESULT (*LayOut)(ICreateTypeInfo *);
END_INTERFACE
} ICreateTypeInfoVtbl;
interface ICreateTypeInfo
{
CONST_VTBL struct ICreateTypeInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICreateTypeInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICreateTypeInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICreateTypeInfo_Release(A) (A)->lpVtbl->Release(A)
#define ICreateTypeInfo_SetGuid(A,B) (A)->lpVtbl->SetGuid(A,B)
#define ICreateTypeInfo_SetTypeFlags(A,B) (A)->lpVtbl->SetTypeFlags(A,B)
#define ICreateTypeInfo_SetDocString(A,B) (A)->lpVtbl->SetDocString(A,B)
#define ICreateTypeInfo_SetHelpContext(A,B) (A)->lpVtbl->SetHelpContext(A,B)
#define ICreateTypeInfo_SetVersion(A,B,C) (A)->lpVtbl->SetVersion(A,B,C)
#define ICreateTypeInfo_AddRefTypeInfo(A,B,C) (A)->lpVtbl->AddRefTypeInfo(A,B,C)
#define ICreateTypeInfo_AddFuncDesc(A,B,C) (A)->lpVtbl->AddFuncDesc(A,B,C)
#define ICreateTypeInfo_AddImplType(A,B,C) (A)->lpVtbl->AddImplType(A,B,C)
#define ICreateTypeInfo_SetImplTypeFlags(A,B,C) (A)->lpVtbl->SetImplTypeFlags(A,B,C)
#define ICreateTypeInfo_SetAlignment(A,B) (A)->lpVtbl->SetAlignment(A,B)
#define ICreateTypeInfo_SetSchema(A,B) (A)->lpVtbl->SetSchema(A,B)
#define ICreateTypeInfo_AddVarDesc(A,B,C) (A)->lpVtbl->AddVarDesc(A,B,C)
#define ICreateTypeInfo_SetFuncAndParamNames(A,B,C,D) (A)->lpVtbl->SetFuncAndParamNames(A,B,C,D)
#define ICreateTypeInfo_SetVarName(A,B,C) (A)->lpVtbl->SetVarName(A,B,C)
#define ICreateTypeInfo_SetTypeDescAlias(A,B) (A)->lpVtbl->SetTypeDescAlias(A,B)
#define ICreateTypeInfo_DefineFuncAsDllEntry(A,B,C,D) (A)->lpVtbl->DefineFuncAsDllEntry(A,B,C,D)
#define ICreateTypeInfo_SetFuncDocString(A,B,C) (A)->lpVtbl->SetFuncDocString(A,B,C)
#define ICreateTypeInfo_SetVarDocString(A,B,C) (A)->lpVtbl->SetVarDocString(A,B,C)
#define ICreateTypeInfo_SetFuncHelpContext(A,B,C) (A)->lpVtbl->SetFuncHelpContext(A,B,C)
#define ICreateTypeInfo_SetVarHelpContext(A,B,C) (A)->lpVtbl->SetVarHelpContext(A,B,C)
#define ICreateTypeInfo_SetMops(A,B,C) (A)->lpVtbl->SetMops(A,B,C)
#define ICreateTypeInfo_SetTypeIdldesc(A,B) (A)->lpVtbl->SetTypeIdldesc(A,B)
#define ICreateTypeInfo_LayOut(A) (A)->lpVtbl->LayOut(A)
#endif 
HRESULT ICreateTypeInfo_SetGuid_Proxy(ICreateTypeInfo *,REFGUID );
void ICreateTypeInfo_SetGuid_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetTypeFlags_Proxy(ICreateTypeInfo *,UINT );
void ICreateTypeInfo_SetTypeFlags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetDocString_Proxy(ICreateTypeInfo *,LPOLESTR );
void ICreateTypeInfo_SetDocString_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetHelpContext_Proxy(ICreateTypeInfo *,DWORD );
void ICreateTypeInfo_SetHelpContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetVersion_Proxy(ICreateTypeInfo *,WORD ,WORD );
void ICreateTypeInfo_SetVersion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_AddRefTypeInfo_Proxy(ICreateTypeInfo *,ITypeInfo *,HREFTYPE *);
void ICreateTypeInfo_AddRefTypeInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_AddFuncDesc_Proxy(ICreateTypeInfo *,UINT ,FUNCDESC *);
void ICreateTypeInfo_AddFuncDesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_AddImplType_Proxy(ICreateTypeInfo *,UINT ,HREFTYPE );
void ICreateTypeInfo_AddImplType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetImplTypeFlags_Proxy(ICreateTypeInfo *,UINT ,INT );
void ICreateTypeInfo_SetImplTypeFlags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetAlignment_Proxy(ICreateTypeInfo *,WORD );
void ICreateTypeInfo_SetAlignment_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetSchema_Proxy(ICreateTypeInfo *,LPOLESTR );
void ICreateTypeInfo_SetSchema_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_AddVarDesc_Proxy(ICreateTypeInfo *,UINT ,VARDESC *);
void ICreateTypeInfo_AddVarDesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetFuncAndParamNames_Proxy(ICreateTypeInfo *,UINT ,LPOLESTR *,UINT );
void ICreateTypeInfo_SetFuncAndParamNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetVarName_Proxy(ICreateTypeInfo *,UINT ,LPOLESTR );
void ICreateTypeInfo_SetVarName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetTypeDescAlias_Proxy(ICreateTypeInfo *,TYPEDESC *);
void ICreateTypeInfo_SetTypeDescAlias_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_DefineFuncAsDllEntry_Proxy(ICreateTypeInfo *,UINT ,LPOLESTR ,LPOLESTR );
void ICreateTypeInfo_DefineFuncAsDllEntry_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetFuncDocString_Proxy(ICreateTypeInfo *,UINT ,LPOLESTR );
void ICreateTypeInfo_SetFuncDocString_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetVarDocString_Proxy(ICreateTypeInfo *,UINT ,LPOLESTR );
void ICreateTypeInfo_SetVarDocString_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetFuncHelpContext_Proxy(ICreateTypeInfo *,UINT ,DWORD );
void ICreateTypeInfo_SetFuncHelpContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetVarHelpContext_Proxy(ICreateTypeInfo *,UINT ,DWORD );
void ICreateTypeInfo_SetVarHelpContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetMops_Proxy(ICreateTypeInfo *,UINT ,BSTR );
void ICreateTypeInfo_SetMops_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_SetTypeIdldesc_Proxy(ICreateTypeInfo *,IDLDESC *);
void ICreateTypeInfo_SetTypeIdldesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo_LayOut_Proxy(ICreateTypeInfo *);
void ICreateTypeInfo_LayOut_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ICreateTypeInfo2_INTERFACE_DEFINED__
#define __ICreateTypeInfo2_INTERFACE_DEFINED__
typedef  ICreateTypeInfo2 *LPCREATETYPEINFO2;
EXTERN_C const IID IID_ICreateTypeInfo2;
typedef struct ICreateTypeInfo2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ICreateTypeInfo2 *,REFIID,void **);
 ULONG (*AddRef)(ICreateTypeInfo2 *);
 ULONG (*Release)(ICreateTypeInfo2 *);
 HRESULT (*SetGuid)(ICreateTypeInfo2 *,REFGUID);
 HRESULT (*SetTypeFlags)(ICreateTypeInfo2 *,UINT);
 HRESULT (*SetDocString)(ICreateTypeInfo2 *,LPOLESTR);
 HRESULT (*SetHelpContext)(ICreateTypeInfo2 *,DWORD);
 HRESULT (*SetVersion)(ICreateTypeInfo2 *,WORD,WORD);
 HRESULT (*AddRefTypeInfo)(ICreateTypeInfo2 *,ITypeInfo *,HREFTYPE *);
 HRESULT (*AddFuncDesc)(ICreateTypeInfo2 *,UINT,FUNCDESC *);
 HRESULT (*AddImplType)(ICreateTypeInfo2 *,UINT,HREFTYPE);
 HRESULT (*SetImplTypeFlags)(ICreateTypeInfo2 *,UINT,INT);
 HRESULT (*SetAlignment)(ICreateTypeInfo2 *,WORD);
 HRESULT (*SetSchema)(ICreateTypeInfo2 *,LPOLESTR);
 HRESULT (*AddVarDesc)(ICreateTypeInfo2 *,UINT,VARDESC *);
 HRESULT (*SetFuncAndParamNames)(ICreateTypeInfo2 *,UINT,LPOLESTR *,UINT);
 HRESULT (*SetVarName)(ICreateTypeInfo2 *,UINT,LPOLESTR);
 HRESULT (*SetTypeDescAlias)(ICreateTypeInfo2 *,TYPEDESC *);
 HRESULT (*DefineFuncAsDllEntry)(ICreateTypeInfo2 *,UINT,LPOLESTR,LPOLESTR);
 HRESULT (*SetFuncDocString)(ICreateTypeInfo2 *,UINT,LPOLESTR);
 HRESULT (*SetVarDocString)(ICreateTypeInfo2 *,UINT,LPOLESTR);
 HRESULT (*SetFuncHelpContext)(ICreateTypeInfo2 *,UINT,DWORD);
 HRESULT (*SetVarHelpContext)(ICreateTypeInfo2 *,UINT,DWORD);
 HRESULT (*SetMops)(ICreateTypeInfo2 *,UINT,BSTR);
 HRESULT (*SetTypeIdldesc)(ICreateTypeInfo2 *,IDLDESC *);
 HRESULT (*LayOut)(ICreateTypeInfo2 *);
 HRESULT (*DeleteFuncDesc)(ICreateTypeInfo2 *,UINT);
 HRESULT (*DeleteFuncDescByMemId)(ICreateTypeInfo2 *,MEMBERID,INVOKEKIND);
 HRESULT (*DeleteVarDesc)(ICreateTypeInfo2 *,UINT);
 HRESULT (*DeleteVarDescByMemId)(ICreateTypeInfo2 *,MEMBERID);
 HRESULT (*DeleteImplType)(ICreateTypeInfo2 *,UINT);
 HRESULT (*SetCustData)(ICreateTypeInfo2 *,REFGUID,VARIANT *);
 HRESULT (*SetFuncCustData)(ICreateTypeInfo2 *,UINT,REFGUID,VARIANT *);
 HRESULT (*SetParamCustData)(ICreateTypeInfo2 *,UINT,UINT,REFGUID,VARIANT *);
 HRESULT (*SetVarCustData)(ICreateTypeInfo2 *,UINT,REFGUID,VARIANT *);
 HRESULT (*SetImplTypeCustData)(ICreateTypeInfo2 *,UINT,REFGUID,VARIANT *);
 HRESULT (*SetHelpStringContext)(ICreateTypeInfo2 *,ULONG);
 HRESULT (*SetFuncHelpStringContext)(ICreateTypeInfo2 *,UINT,ULONG);
 HRESULT (*SetVarHelpStringContext)(ICreateTypeInfo2 *,UINT,ULONG);
 HRESULT (*Invalidate)(ICreateTypeInfo2 *);
 HRESULT (*SetName)(ICreateTypeInfo2 *,LPOLESTR);
END_INTERFACE
} ICreateTypeInfo2Vtbl;
interface ICreateTypeInfo2
{
CONST_VTBL struct ICreateTypeInfo2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICreateTypeInfo2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICreateTypeInfo2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICreateTypeInfo2_Release(A) (A)->lpVtbl->Release(A)
#define ICreateTypeInfo2_SetGuid(A,B) (A)->lpVtbl->SetGuid(A,B)
#define ICreateTypeInfo2_SetTypeFlags(A,B) (A)->lpVtbl->SetTypeFlags(A,B)
#define ICreateTypeInfo2_SetDocString(A,B) (A)->lpVtbl->SetDocString(A,B)
#define ICreateTypeInfo2_SetHelpContext(A,B) (A)->lpVtbl->SetHelpContext(A,B)
#define ICreateTypeInfo2_SetVersion(A,B,C) (A)->lpVtbl->SetVersion(A,B,C)
#define ICreateTypeInfo2_AddRefTypeInfo(A,B,C) (A)->lpVtbl->AddRefTypeInfo(A,B,C)
#define ICreateTypeInfo2_AddFuncDesc(A,B,C) (A)->lpVtbl->AddFuncDesc(A,B,C)
#define ICreateTypeInfo2_AddImplType(A,B,C) (A)->lpVtbl->AddImplType(A,B,C)
#define ICreateTypeInfo2_SetImplTypeFlags(A,B,C) (A)->lpVtbl->SetImplTypeFlags(A,B,C)
#define ICreateTypeInfo2_SetAlignment(A,B) (A)->lpVtbl->SetAlignment(A,B)
#define ICreateTypeInfo2_SetSchema(A,B) (A)->lpVtbl->SetSchema(A,B)
#define ICreateTypeInfo2_AddVarDesc(A,B,C) (A)->lpVtbl->AddVarDesc(A,B,C)
#define ICreateTypeInfo2_SetFuncAndParamNames(A,B,C,D) (A)->lpVtbl->SetFuncAndParamNames(A,B,C,D)
#define ICreateTypeInfo2_SetVarName(A,B,C) (A)->lpVtbl->SetVarName(A,B,C)
#define ICreateTypeInfo2_SetTypeDescAlias(A,B) (A)->lpVtbl->SetTypeDescAlias(A,B)
#define ICreateTypeInfo2_DefineFuncAsDllEntry(A,B,C,D) (A)->lpVtbl->DefineFuncAsDllEntry(A,B,C,D)
#define ICreateTypeInfo2_SetFuncDocString(A,B,C) (A)->lpVtbl->SetFuncDocString(A,B,C)
#define ICreateTypeInfo2_SetVarDocString(A,B,C) (A)->lpVtbl->SetVarDocString(A,B,C)
#define ICreateTypeInfo2_SetFuncHelpContext(A,B,C) (A)->lpVtbl->SetFuncHelpContext(A,B,C)
#define ICreateTypeInfo2_SetVarHelpContext(A,B,C) (A)->lpVtbl->SetVarHelpContext(A,B,C)
#define ICreateTypeInfo2_SetMops(A,B,C) (A)->lpVtbl->SetMops(A,B,C)
#define ICreateTypeInfo2_SetTypeIdldesc(A,B) (A)->lpVtbl->SetTypeIdldesc(A,B)
#define ICreateTypeInfo2_LayOut(A) (A)->lpVtbl->LayOut(A)
#define ICreateTypeInfo2_DeleteFuncDesc(A,B) (A)->lpVtbl->DeleteFuncDesc(A,B)
#define ICreateTypeInfo2_DeleteFuncDescByMemId(A,B,C) (A)->lpVtbl->DeleteFuncDescByMemId(A,B,C)
#define ICreateTypeInfo2_DeleteVarDesc(A,B) (A)->lpVtbl->DeleteVarDesc(A,B)
#define ICreateTypeInfo2_DeleteVarDescByMemId(A,B) (A)->lpVtbl->DeleteVarDescByMemId(A,B)
#define ICreateTypeInfo2_DeleteImplType(A,B) (A)->lpVtbl->DeleteImplType(A,B)
#define ICreateTypeInfo2_SetCustData(A,B,C) (A)->lpVtbl->SetCustData(A,B,C)
#define ICreateTypeInfo2_SetFuncCustData(A,B,C,D) (A)->lpVtbl->SetFuncCustData(A,B,C,D)
#define ICreateTypeInfo2_SetParamCustData(A,B,C,D,E) (A)->lpVtbl->SetParamCustData(A,B,C,D,E)
#define ICreateTypeInfo2_SetVarCustData(A,B,C,D) (A)->lpVtbl->SetVarCustData(A,B,C,D)
#define ICreateTypeInfo2_SetImplTypeCustData(A,B,C,D) (A)->lpVtbl->SetImplTypeCustData(A,B,C,D)
#define ICreateTypeInfo2_SetHelpStringContext(A,B) (A)->lpVtbl->SetHelpStringContext(A,B)
#define ICreateTypeInfo2_SetFuncHelpStringContext(A,B,C) (A)->lpVtbl->SetFuncHelpStringContext(A,B,C)
#define ICreateTypeInfo2_SetVarHelpStringContext(A,B,C) (A)->lpVtbl->SetVarHelpStringContext(A,B,C)
#define ICreateTypeInfo2_Invalidate(A) (A)->lpVtbl->Invalidate(A)
#define ICreateTypeInfo2_SetName(A,B) (A)->lpVtbl->SetName(A,B)
#endif 
HRESULT ICreateTypeInfo2_DeleteFuncDesc_Proxy(ICreateTypeInfo2 *,UINT );
void ICreateTypeInfo2_DeleteFuncDesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_DeleteFuncDescByMemId_Proxy(ICreateTypeInfo2 *,MEMBERID ,INVOKEKIND );
void ICreateTypeInfo2_DeleteFuncDescByMemId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_DeleteVarDesc_Proxy(ICreateTypeInfo2 *,UINT );
void ICreateTypeInfo2_DeleteVarDesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_DeleteVarDescByMemId_Proxy(ICreateTypeInfo2 *,MEMBERID );
void ICreateTypeInfo2_DeleteVarDescByMemId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_DeleteImplType_Proxy(ICreateTypeInfo2 *,UINT );
void ICreateTypeInfo2_DeleteImplType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetCustData_Proxy(ICreateTypeInfo2 *,REFGUID ,VARIANT *);
void ICreateTypeInfo2_SetCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetFuncCustData_Proxy(ICreateTypeInfo2 *,UINT ,REFGUID ,VARIANT *);
void ICreateTypeInfo2_SetFuncCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetParamCustData_Proxy(ICreateTypeInfo2 *,UINT ,UINT ,REFGUID ,VARIANT *);
void ICreateTypeInfo2_SetParamCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetVarCustData_Proxy(ICreateTypeInfo2 *,UINT ,REFGUID ,VARIANT *);
void ICreateTypeInfo2_SetVarCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetImplTypeCustData_Proxy(ICreateTypeInfo2 *,UINT ,REFGUID ,VARIANT *);
void ICreateTypeInfo2_SetImplTypeCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetHelpStringContext_Proxy(ICreateTypeInfo2 *,ULONG );
void ICreateTypeInfo2_SetHelpStringContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetFuncHelpStringContext_Proxy(ICreateTypeInfo2 *,UINT ,ULONG );
void ICreateTypeInfo2_SetFuncHelpStringContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetVarHelpStringContext_Proxy(ICreateTypeInfo2 *,UINT ,ULONG );
void ICreateTypeInfo2_SetVarHelpStringContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_Invalidate_Proxy(ICreateTypeInfo2 *);
void ICreateTypeInfo2_Invalidate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeInfo2_SetName_Proxy(ICreateTypeInfo2 *,LPOLESTR );
void ICreateTypeInfo2_SetName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ICreateTypeLib_INTERFACE_DEFINED__
#define __ICreateTypeLib_INTERFACE_DEFINED__
typedef  ICreateTypeLib *LPCREATETYPELIB;
EXTERN_C const IID IID_ICreateTypeLib;
typedef struct ICreateTypeLibVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ICreateTypeLib *,REFIID,void **);
 ULONG (*AddRef)(ICreateTypeLib *);
 ULONG (*Release)(ICreateTypeLib *);
 HRESULT (*CreateTypeInfo)(ICreateTypeLib *,LPOLESTR,TYPEKIND,ICreateTypeInfo **);
 HRESULT (*SetName)(ICreateTypeLib *,LPOLESTR);
 HRESULT (*SetVersion)(ICreateTypeLib *,WORD,WORD);
 HRESULT (*SetGuid)(ICreateTypeLib *,REFGUID);
 HRESULT (*SetDocString)(ICreateTypeLib *,LPOLESTR);
 HRESULT (*SetHelpFileName)(ICreateTypeLib *,LPOLESTR);
 HRESULT (*SetHelpContext)(ICreateTypeLib *,DWORD);
 HRESULT (*SetLcid)(ICreateTypeLib *,LCID);
 HRESULT (*SetLibFlags)(ICreateTypeLib *,UINT);
 HRESULT (*SaveAllChanges)(ICreateTypeLib *);
END_INTERFACE
} ICreateTypeLibVtbl;
interface ICreateTypeLib
{
CONST_VTBL struct ICreateTypeLibVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICreateTypeLib_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICreateTypeLib_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICreateTypeLib_Release(A) (A)->lpVtbl->Release(A)
#define ICreateTypeLib_CreateTypeInfo(A,B,C,D) (A)->lpVtbl->CreateTypeInfo(A,B,C,D)
#define ICreateTypeLib_SetName(A,B) (A)->lpVtbl->SetName(A,B)
#define ICreateTypeLib_SetVersion(A,B,C) (A)->lpVtbl->SetVersion(A,B,C)
#define ICreateTypeLib_SetGuid(A,B) (A)->lpVtbl->SetGuid(A,B)
#define ICreateTypeLib_SetDocString(A,B) (A)->lpVtbl->SetDocString(A,B)
#define ICreateTypeLib_SetHelpFileName(A,B) (A)->lpVtbl->SetHelpFileName(A,B)
#define ICreateTypeLib_SetHelpContext(A,B) (A)->lpVtbl->SetHelpContext(A,B)
#define ICreateTypeLib_SetLcid(A,B) (A)->lpVtbl->SetLcid(A,B)
#define ICreateTypeLib_SetLibFlags(A,B) (A)->lpVtbl->SetLibFlags(A,B)
#define ICreateTypeLib_SaveAllChanges(A) (A)->lpVtbl->SaveAllChanges(A)
#endif 
HRESULT ICreateTypeLib_CreateTypeInfo_Proxy(ICreateTypeLib *,LPOLESTR ,TYPEKIND ,ICreateTypeInfo **);
void ICreateTypeLib_CreateTypeInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SetName_Proxy(ICreateTypeLib *,LPOLESTR );
void ICreateTypeLib_SetName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SetVersion_Proxy(ICreateTypeLib *,WORD ,WORD );
void ICreateTypeLib_SetVersion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SetGuid_Proxy(ICreateTypeLib *,REFGUID );
void ICreateTypeLib_SetGuid_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SetDocString_Proxy(ICreateTypeLib *,LPOLESTR );
void ICreateTypeLib_SetDocString_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SetHelpFileName_Proxy(ICreateTypeLib *,LPOLESTR );
void ICreateTypeLib_SetHelpFileName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SetHelpContext_Proxy(ICreateTypeLib *,DWORD );
void ICreateTypeLib_SetHelpContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SetLcid_Proxy(ICreateTypeLib *,LCID );
void ICreateTypeLib_SetLcid_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SetLibFlags_Proxy(ICreateTypeLib *,UINT );
void ICreateTypeLib_SetLibFlags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib_SaveAllChanges_Proxy(ICreateTypeLib *);
void ICreateTypeLib_SaveAllChanges_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ICreateTypeLib2_INTERFACE_DEFINED__
#define __ICreateTypeLib2_INTERFACE_DEFINED__
typedef  ICreateTypeLib2 *LPCREATETYPELIB2;
EXTERN_C const IID IID_ICreateTypeLib2;
typedef struct ICreateTypeLib2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ICreateTypeLib2 *,REFIID,void **);
 ULONG (*AddRef)(ICreateTypeLib2 *);
 ULONG (*Release)(ICreateTypeLib2 *);
 HRESULT (*CreateTypeInfo)(ICreateTypeLib2 *,LPOLESTR,TYPEKIND,ICreateTypeInfo **);
 HRESULT (*SetName)(ICreateTypeLib2 *,LPOLESTR);
 HRESULT (*SetVersion)(ICreateTypeLib2 *,WORD,WORD);
 HRESULT (*SetGuid)(ICreateTypeLib2 *,REFGUID);
 HRESULT (*SetDocString)(ICreateTypeLib2 *,LPOLESTR);
 HRESULT (*SetHelpFileName)(ICreateTypeLib2 *,LPOLESTR);
 HRESULT (*SetHelpContext)(ICreateTypeLib2 *,DWORD);
 HRESULT (*SetLcid)(ICreateTypeLib2 *,LCID);
 HRESULT (*SetLibFlags)(ICreateTypeLib2 *,UINT);
 HRESULT (*SaveAllChanges)(ICreateTypeLib2 *);
 HRESULT (*DeleteTypeInfo)(ICreateTypeLib2 *,LPOLESTR);
 HRESULT (*SetCustData)(ICreateTypeLib2 *,REFGUID,VARIANT *);
 HRESULT (*SetHelpStringContext)(ICreateTypeLib2 *,ULONG);
 HRESULT (*SetHelpStringDll)(ICreateTypeLib2 *,LPOLESTR);
END_INTERFACE
} ICreateTypeLib2Vtbl;
interface ICreateTypeLib2
{
CONST_VTBL struct ICreateTypeLib2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICreateTypeLib2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICreateTypeLib2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICreateTypeLib2_Release(A) (A)->lpVtbl->Release(A)
#define ICreateTypeLib2_CreateTypeInfo(A,B,C,D) (A)->lpVtbl->CreateTypeInfo(A,B,C,D)
#define ICreateTypeLib2_SetName(A,B) (A)->lpVtbl->SetName(A,B)
#define ICreateTypeLib2_SetVersion(A,B,C) (A)->lpVtbl->SetVersion(A,B,C)
#define ICreateTypeLib2_SetGuid(A,B) (A)->lpVtbl->SetGuid(A,B)
#define ICreateTypeLib2_SetDocString(A,B) (A)->lpVtbl->SetDocString(A,B)
#define ICreateTypeLib2_SetHelpFileName(A,B) (A)->lpVtbl->SetHelpFileName(A,B)
#define ICreateTypeLib2_SetHelpContext(A,B) (A)->lpVtbl->SetHelpContext(A,B)
#define ICreateTypeLib2_SetLcid(A,B) (A)->lpVtbl->SetLcid(A,B)
#define ICreateTypeLib2_SetLibFlags(A,B) (A)->lpVtbl->SetLibFlags(A,B)
#define ICreateTypeLib2_SaveAllChanges(A) (A)->lpVtbl->SaveAllChanges(A)
#define ICreateTypeLib2_DeleteTypeInfo(A,B) (A)->lpVtbl->DeleteTypeInfo(A,B)
#define ICreateTypeLib2_SetCustData(A,B,C) (A)->lpVtbl->SetCustData(A,B,C)
#define ICreateTypeLib2_SetHelpStringContext(A,B) (A)->lpVtbl->SetHelpStringContext(A,B)
#define ICreateTypeLib2_SetHelpStringDll(A,B) (A)->lpVtbl->SetHelpStringDll(A,B)
#endif 
HRESULT ICreateTypeLib2_DeleteTypeInfo_Proxy(ICreateTypeLib2 *,LPOLESTR );
void ICreateTypeLib2_DeleteTypeInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib2_SetCustData_Proxy(ICreateTypeLib2 *,REFGUID ,VARIANT *);
void ICreateTypeLib2_SetCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib2_SetHelpStringContext_Proxy(ICreateTypeLib2 *,ULONG );
void ICreateTypeLib2_SetHelpStringContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateTypeLib2_SetHelpStringDll_Proxy(ICreateTypeLib2 *,LPOLESTR );
void ICreateTypeLib2_SetHelpStringDll_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IDispatch_INTERFACE_DEFINED__
#define __IDispatch_INTERFACE_DEFINED__
typedef  IDispatch *LPDISPATCH;
#define	DISPID_UNKNOWN	(-1)
#define	DISPID_VALUE	(0)
#define	DISPID_PROPERTYPUT	(-3)
#define	DISPID_NEWENUM	(-4)
#define	DISPID_EVALUATE	(-5)
#define	DISPID_CONSTRUCTOR	(-6)
#define	DISPID_DESTRUCTOR	(-7)
#define	DISPID_COLLECT	(-8)
EXTERN_C const IID IID_IDispatch;
typedef struct IDispatchVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IDispatch *,REFIID,void **);
 ULONG (*AddRef)(IDispatch *);
 ULONG (*Release)(IDispatch *);
 HRESULT (*GetTypeInfoCount)(IDispatch *,UINT *);
 HRESULT (*GetTypeInfo)(IDispatch *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IDispatch *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IDispatch *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
END_INTERFACE
} IDispatchVtbl;
interface IDispatch
{
CONST_VTBL struct IDispatchVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IDispatch_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IDispatch_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IDispatch_Release(A) (A)->lpVtbl->Release(A)
#define IDispatch_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IDispatch_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IDispatch_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IDispatch_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#endif 
HRESULT IDispatch_GetTypeInfoCount_Proxy(IDispatch *,UINT *);
void IDispatch_GetTypeInfoCount_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDispatch_GetTypeInfo_Proxy(IDispatch *,UINT ,LCID ,ITypeInfo **);
void IDispatch_GetTypeInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDispatch_GetIDsOfNames_Proxy(IDispatch *,REFIID ,LPOLESTR *,UINT ,LCID ,DISPID *);
void IDispatch_GetIDsOfNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IDispatch_RemoteInvoke_Proxy(IDispatch *,DISPID ,REFIID ,LCID ,DWORD ,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *,UINT ,UINT *,VARIANTARG *);
void IDispatch_RemoteInvoke_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IEnumVARIANT_INTERFACE_DEFINED__
#define __IEnumVARIANT_INTERFACE_DEFINED__
typedef  IEnumVARIANT *LPENUMVARIANT;
EXTERN_C const IID IID_IEnumVARIANT;
typedef struct IEnumVARIANTVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IEnumVARIANT *,REFIID,void **);
 ULONG (*AddRef)(IEnumVARIANT *);
 ULONG (*Release)(IEnumVARIANT *);
 HRESULT (*Next)(IEnumVARIANT *,ULONG,VARIANT *,ULONG *);
 HRESULT (*Skip)(IEnumVARIANT *,ULONG);
 HRESULT (*Reset)(IEnumVARIANT *);
 HRESULT (*Clone)(IEnumVARIANT *,IEnumVARIANT **);
END_INTERFACE
} IEnumVARIANTVtbl;
interface IEnumVARIANT
{
CONST_VTBL struct IEnumVARIANTVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IEnumVARIANT_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IEnumVARIANT_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IEnumVARIANT_Release(A) (A)->lpVtbl->Release(A)
#define IEnumVARIANT_Next(A,B,C,D) (A)->lpVtbl->Next(A,B,C,D)
#define IEnumVARIANT_Skip(A,B) (A)->lpVtbl->Skip(A,B)
#define IEnumVARIANT_Reset(A) (A)->lpVtbl->Reset(A)
#define IEnumVARIANT_Clone(A,B) (A)->lpVtbl->Clone(A,B)
#endif 
HRESULT IEnumVARIANT_RemoteNext_Proxy(IEnumVARIANT *,ULONG ,VARIANT *,ULONG *);
void IEnumVARIANT_RemoteNext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IEnumVARIANT_Skip_Proxy(IEnumVARIANT *,ULONG );
void IEnumVARIANT_Skip_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IEnumVARIANT_Reset_Proxy(IEnumVARIANT *);
void IEnumVARIANT_Reset_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IEnumVARIANT_Clone_Proxy(IEnumVARIANT *,IEnumVARIANT **);
void IEnumVARIANT_Clone_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ITypeComp_INTERFACE_DEFINED__
#define __ITypeComp_INTERFACE_DEFINED__
typedef  ITypeComp *LPTYPECOMP;
typedef  
enum tagDESCKIND
{	DESCKIND_NONE=0,
DESCKIND_FUNCDESC=DESCKIND_NONE + 1,
DESCKIND_VARDESC=DESCKIND_FUNCDESC + 1,
DESCKIND_TYPECOMP=DESCKIND_VARDESC + 1,
DESCKIND_IMPLICITAPPOBJ=DESCKIND_TYPECOMP + 1,
DESCKIND_MAX=DESCKIND_IMPLICITAPPOBJ + 1
} DESCKIND;
typedef union tagBINDPTR
{
FUNCDESC *lpfuncdesc;
VARDESC *lpvardesc;
ITypeComp *lptcomp;
} BINDPTR;
typedef union tagBINDPTR *LPBINDPTR;
EXTERN_C const IID IID_ITypeComp;
typedef struct ITypeCompVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ITypeComp *,REFIID,void **);
 ULONG (*AddRef)(ITypeComp *);
 ULONG (*Release)(ITypeComp *);
 HRESULT (*Bind)(ITypeComp *,LPOLESTR,ULONG,WORD,ITypeInfo **,DESCKIND *,BINDPTR *);
 HRESULT (*BindType)(ITypeComp *,LPOLESTR,ULONG,ITypeInfo **,ITypeComp **);
END_INTERFACE
} ITypeCompVtbl;
interface ITypeComp
{
CONST_VTBL struct ITypeCompVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITypeComp_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITypeComp_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITypeComp_Release(A) (A)->lpVtbl->Release(A)
#define ITypeComp_Bind(A,B,C,D,E,F,G) (A)->lpVtbl->Bind(A,B,C,D,E,F,G)
#define ITypeComp_BindType(A,B,C,D,E) (A)->lpVtbl->BindType(A,B,C,D,E)
#endif 
HRESULT ITypeComp_RemoteBind_Proxy(ITypeComp *,LPOLESTR ,ULONG ,WORD ,ITypeInfo **,DESCKIND *,LPFUNCDESC *,LPVARDESC *,ITypeComp **,CLEANLOCALSTORAGE *);
void ITypeComp_RemoteBind_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeComp_RemoteBindType_Proxy(ITypeComp *,LPOLESTR ,ULONG ,ITypeInfo **);
void ITypeComp_RemoteBindType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ITypeInfo_INTERFACE_DEFINED__
#define __ITypeInfo_INTERFACE_DEFINED__
typedef  ITypeInfo *LPTYPEINFO;
EXTERN_C const IID IID_ITypeInfo;
typedef struct ITypeInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ITypeInfo *,REFIID,void **);
 ULONG (*AddRef)(ITypeInfo *);
 ULONG (*Release)(ITypeInfo *);
 HRESULT (*GetTypeAttr)(ITypeInfo *,TYPEATTR **);
 HRESULT (*GetTypeComp)(ITypeInfo *,ITypeComp **);
 HRESULT (*GetFuncDesc)(ITypeInfo *,UINT,FUNCDESC **);
 HRESULT (*GetVarDesc)(ITypeInfo *,UINT,VARDESC **);
 HRESULT (*GetNames)(ITypeInfo *,MEMBERID,BSTR *,UINT,UINT *);
 HRESULT (*GetRefTypeOfImplType)(ITypeInfo *,UINT,HREFTYPE *);
 HRESULT (*GetImplTypeFlags)(ITypeInfo *,UINT,INT *);
 HRESULT (*GetIDsOfNames)(ITypeInfo *,LPOLESTR *,UINT,MEMBERID *);
 HRESULT (*Invoke)(ITypeInfo *,PVOID,MEMBERID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*GetDocumentation)(ITypeInfo *,MEMBERID,BSTR *,BSTR *,DWORD *,BSTR *);
 HRESULT (*GetDllEntry)(ITypeInfo *,MEMBERID,INVOKEKIND,BSTR *,BSTR *,WORD *);
 HRESULT (*GetRefTypeInfo)(ITypeInfo *,HREFTYPE,ITypeInfo **);
 HRESULT (*AddressOfMember)(ITypeInfo *,MEMBERID,INVOKEKIND,PVOID *);
 HRESULT (*CreateInstance)(ITypeInfo *,IUnknown *,REFIID,PVOID *);
 HRESULT (*GetMops)(ITypeInfo *,MEMBERID,BSTR *);
 HRESULT (*GetContainingTypeLib)(ITypeInfo *,ITypeLib **,UINT *);
 void (*ReleaseTypeAttr)(ITypeInfo *,TYPEATTR *);
 void (*ReleaseFuncDesc)(ITypeInfo *,FUNCDESC *);
 void (*ReleaseVarDesc)(ITypeInfo *,VARDESC *);
END_INTERFACE
} ITypeInfoVtbl;
interface ITypeInfo
{
CONST_VTBL struct ITypeInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITypeInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITypeInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITypeInfo_Release(A) (A)->lpVtbl->Release(A)
#define ITypeInfo_GetTypeAttr(A,B) (A)->lpVtbl->GetTypeAttr(A,B)
#define ITypeInfo_GetTypeComp(A,B) (A)->lpVtbl->GetTypeComp(A,B)
#define ITypeInfo_GetFuncDesc(A,B,C) (A)->lpVtbl->GetFuncDesc(A,B,C)
#define ITypeInfo_GetVarDesc(A,B,C) (A)->lpVtbl->GetVarDesc(A,B,C)
#define ITypeInfo_GetNames(A,B,C,D,E) (A)->lpVtbl->GetNames(A,B,C,D,E)
#define ITypeInfo_GetRefTypeOfImplType(A,B,C) (A)->lpVtbl->GetRefTypeOfImplType(A,B,C)
#define ITypeInfo_GetImplTypeFlags(A,B,C) (A)->lpVtbl->GetImplTypeFlags(A,B,C)
#define ITypeInfo_GetIDsOfNames(A,B,C,D) (A)->lpVtbl->GetIDsOfNames(A,B,C,D)
#define ITypeInfo_Invoke(A,B,C,D,E,F,G,H) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H)
#define ITypeInfo_GetDocumentation(A,B,C,D,E,F) (A)->lpVtbl->GetDocumentation(A,B,C,D,E,F)
#define ITypeInfo_GetDllEntry(A,B,C,D,E,F) (A)->lpVtbl->GetDllEntry(A,B,C,D,E,F)
#define ITypeInfo_GetRefTypeInfo(A,B,C) (A)->lpVtbl->GetRefTypeInfo(A,B,C)
#define ITypeInfo_AddressOfMember(A,B,C,D) (A)->lpVtbl->AddressOfMember(A,B,C,D)
#define ITypeInfo_CreateInstance(A,B,C,D) (A)->lpVtbl->CreateInstance(A,B,C,D)
#define ITypeInfo_GetMops(A,B,C) (A)->lpVtbl->GetMops(A,B,C)
#define ITypeInfo_GetContainingTypeLib(A,B,C) (A)->lpVtbl->GetContainingTypeLib(A,B,C)
#define ITypeInfo_ReleaseTypeAttr(A,B) (A)->lpVtbl->ReleaseTypeAttr(A,B)
#define ITypeInfo_ReleaseFuncDesc(A,B) (A)->lpVtbl->ReleaseFuncDesc(A,B)
#define ITypeInfo_ReleaseVarDesc(A,B) (A)->lpVtbl->ReleaseVarDesc(A,B)
#endif 
HRESULT ITypeInfo_RemoteGetTypeAttr_Proxy(ITypeInfo *,LPTYPEATTR *,CLEANLOCALSTORAGE *);
void ITypeInfo_RemoteGetTypeAttr_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_GetTypeComp_Proxy(ITypeInfo *,ITypeComp **);
void ITypeInfo_GetTypeComp_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_RemoteGetFuncDesc_Proxy(ITypeInfo *,UINT ,LPFUNCDESC *,CLEANLOCALSTORAGE *);
void ITypeInfo_RemoteGetFuncDesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_RemoteGetVarDesc_Proxy(ITypeInfo *,UINT ,LPVARDESC *,CLEANLOCALSTORAGE *);
void ITypeInfo_RemoteGetVarDesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_RemoteGetNames_Proxy(ITypeInfo *,MEMBERID ,BSTR *,UINT ,UINT *);
void ITypeInfo_RemoteGetNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_GetRefTypeOfImplType_Proxy(ITypeInfo *,UINT ,HREFTYPE *);
void ITypeInfo_GetRefTypeOfImplType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_GetImplTypeFlags_Proxy(ITypeInfo *,UINT ,INT *);
void ITypeInfo_GetImplTypeFlags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_LocalGetIDsOfNames_Proxy(ITypeInfo *);
void ITypeInfo_LocalGetIDsOfNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_LocalInvoke_Proxy(ITypeInfo *);
void ITypeInfo_LocalInvoke_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_RemoteGetDocumentation_Proxy(ITypeInfo *,MEMBERID ,DWORD ,BSTR *,BSTR *,DWORD *,BSTR *);
void ITypeInfo_RemoteGetDocumentation_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_RemoteGetDllEntry_Proxy(ITypeInfo *,MEMBERID ,INVOKEKIND ,DWORD ,BSTR *,BSTR *,WORD *);
void ITypeInfo_RemoteGetDllEntry_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_GetRefTypeInfo_Proxy(ITypeInfo *,HREFTYPE ,ITypeInfo **);
void ITypeInfo_GetRefTypeInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_LocalAddressOfMember_Proxy(ITypeInfo *);
void ITypeInfo_LocalAddressOfMember_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_RemoteCreateInstance_Proxy(ITypeInfo *,REFIID ,IUnknown **);
void ITypeInfo_RemoteCreateInstance_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_GetMops_Proxy(ITypeInfo *,MEMBERID ,BSTR *);
void ITypeInfo_GetMops_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_RemoteGetContainingTypeLib_Proxy(ITypeInfo *,ITypeLib **,UINT *);
void ITypeInfo_RemoteGetContainingTypeLib_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_LocalReleaseTypeAttr_Proxy(ITypeInfo *);
void ITypeInfo_LocalReleaseTypeAttr_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_LocalReleaseFuncDesc_Proxy(ITypeInfo *);
void ITypeInfo_LocalReleaseFuncDesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo_LocalReleaseVarDesc_Proxy(ITypeInfo *);
void ITypeInfo_LocalReleaseVarDesc_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ITypeInfo2_INTERFACE_DEFINED__
#define __ITypeInfo2_INTERFACE_DEFINED__
typedef  ITypeInfo2 *LPTYPEINFO2;
EXTERN_C const IID IID_ITypeInfo2;
typedef struct ITypeInfo2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ITypeInfo2 *,REFIID,void **);
 ULONG (*AddRef)(ITypeInfo2 *);
 ULONG (*Release)(ITypeInfo2 *);
 HRESULT (*GetTypeAttr)(ITypeInfo2 *,TYPEATTR **);
 HRESULT (*GetTypeComp)(ITypeInfo2 *,ITypeComp **);
 HRESULT (*GetFuncDesc)(ITypeInfo2 *,UINT,FUNCDESC **);
 HRESULT (*GetVarDesc)(ITypeInfo2 *,UINT,VARDESC **);
 HRESULT (*GetNames)(ITypeInfo2 *,MEMBERID,BSTR *,UINT,UINT *);
 HRESULT (*GetRefTypeOfImplType)(ITypeInfo2 *,UINT,HREFTYPE *);
 HRESULT (*GetImplTypeFlags)(ITypeInfo2 *,UINT,INT *);
 HRESULT (*GetIDsOfNames)(ITypeInfo2 *,LPOLESTR *,UINT,MEMBERID *);
 HRESULT (*Invoke)(ITypeInfo2 *,PVOID,MEMBERID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*GetDocumentation)(ITypeInfo2 *,MEMBERID,BSTR *,BSTR *,DWORD *,BSTR *);
 HRESULT (*GetDllEntry)(ITypeInfo2 *,MEMBERID,INVOKEKIND,BSTR *,BSTR *,WORD *);
 HRESULT (*GetRefTypeInfo)(ITypeInfo2 *,HREFTYPE,ITypeInfo **);
 HRESULT (*AddressOfMember)(ITypeInfo2 *,MEMBERID,INVOKEKIND,PVOID *);
 HRESULT (*CreateInstance)(ITypeInfo2 *,IUnknown *,REFIID,PVOID *);
 HRESULT (*GetMops)(ITypeInfo2 *,MEMBERID,BSTR *);
 HRESULT (*GetContainingTypeLib)(ITypeInfo2 *,ITypeLib **,UINT *);
 void (*ReleaseTypeAttr)(ITypeInfo2 *,TYPEATTR *);
 void (*ReleaseFuncDesc)(ITypeInfo2 *,FUNCDESC *);
 void (*ReleaseVarDesc)(ITypeInfo2 *,VARDESC *);
 HRESULT (*GetTypeKind)(ITypeInfo2 *,TYPEKIND *);
 HRESULT (*GetTypeFlags)(ITypeInfo2 *,ULONG *);
 HRESULT (*GetFuncIndexOfMemId)(ITypeInfo2 *,MEMBERID,INVOKEKIND,UINT *);
 HRESULT (*GetVarIndexOfMemId)(ITypeInfo2 *,MEMBERID,UINT *);
 HRESULT (*GetCustData)(ITypeInfo2 *,REFGUID,VARIANT *);
 HRESULT (*GetFuncCustData)(ITypeInfo2 *,UINT,REFGUID,VARIANT *);
 HRESULT (*GetParamCustData)(ITypeInfo2 *,UINT,UINT,REFGUID,VARIANT *);
 HRESULT (*GetVarCustData)(ITypeInfo2 *,UINT,REFGUID,VARIANT *);
 HRESULT (*GetImplTypeCustData)(ITypeInfo2 *,UINT,REFGUID,VARIANT *);
 HRESULT (*GetDocumentation2)(ITypeInfo2 *,MEMBERID,LCID,BSTR *,DWORD *,BSTR *);
 HRESULT (*GetAllCustData)(ITypeInfo2 *,CUSTDATA *);
 HRESULT (*GetAllFuncCustData)(ITypeInfo2 *,UINT,CUSTDATA *);
 HRESULT (*GetAllParamCustData)(ITypeInfo2 *,UINT,UINT,CUSTDATA *);
 HRESULT (*GetAllVarCustData)(ITypeInfo2 *,UINT,CUSTDATA *);
 HRESULT (*GetAllImplTypeCustData)(ITypeInfo2 *,UINT,CUSTDATA *);
END_INTERFACE
} ITypeInfo2Vtbl;
interface ITypeInfo2
{
CONST_VTBL struct ITypeInfo2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITypeInfo2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITypeInfo2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITypeInfo2_Release(A) (A)->lpVtbl->Release(A)
#define ITypeInfo2_GetTypeAttr(A,B) (A)->lpVtbl->GetTypeAttr(A,B)
#define ITypeInfo2_GetTypeComp(A,B) (A)->lpVtbl->GetTypeComp(A,B)
#define ITypeInfo2_GetFuncDesc(A,B,C) (A)->lpVtbl->GetFuncDesc(A,B,C)
#define ITypeInfo2_GetVarDesc(A,B,C) (A)->lpVtbl->GetVarDesc(A,B,C)
#define ITypeInfo2_GetNames(A,B,C,D,E) (A)->lpVtbl->GetNames(A,B,C,D,E)
#define ITypeInfo2_GetRefTypeOfImplType(A,B,C) (A)->lpVtbl->GetRefTypeOfImplType(A,B,C)
#define ITypeInfo2_GetImplTypeFlags(A,B,C) (A)->lpVtbl->GetImplTypeFlags(A,B,C)
#define ITypeInfo2_GetIDsOfNames(A,B,C,D) (A)->lpVtbl->GetIDsOfNames(A,B,C,D)
#define ITypeInfo2_Invoke(A,B,C,D,E,F,G,H) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H)
#define ITypeInfo2_GetDocumentation(A,B,C,D,E,F) (A)->lpVtbl->GetDocumentation(A,B,C,D,E,F)
#define ITypeInfo2_GetDllEntry(A,B,C,D,E,F) (A)->lpVtbl->GetDllEntry(A,B,C,D,E,F)
#define ITypeInfo2_GetRefTypeInfo(A,B,C) (A)->lpVtbl->GetRefTypeInfo(A,B,C)
#define ITypeInfo2_AddressOfMember(A,B,C,D) (A)->lpVtbl->AddressOfMember(A,B,C,D)
#define ITypeInfo2_CreateInstance(A,B,C,D) (A)->lpVtbl->CreateInstance(A,B,C,D)
#define ITypeInfo2_GetMops(A,B,C) (A)->lpVtbl->GetMops(A,B,C)
#define ITypeInfo2_GetContainingTypeLib(A,B,C) (A)->lpVtbl->GetContainingTypeLib(A,B,C)
#define ITypeInfo2_ReleaseTypeAttr(A,B) (A)->lpVtbl->ReleaseTypeAttr(A,B)
#define ITypeInfo2_ReleaseFuncDesc(A,B) (A)->lpVtbl->ReleaseFuncDesc(A,B)
#define ITypeInfo2_ReleaseVarDesc(A,B) (A)->lpVtbl->ReleaseVarDesc(A,B)
#define ITypeInfo2_GetTypeKind(A,B) (A)->lpVtbl->GetTypeKind(A,B)
#define ITypeInfo2_GetTypeFlags(A,B) (A)->lpVtbl->GetTypeFlags(A,B)
#define ITypeInfo2_GetFuncIndexOfMemId(A,B,C,D) (A)->lpVtbl->GetFuncIndexOfMemId(A,B,C,D)
#define ITypeInfo2_GetVarIndexOfMemId(A,B,C) (A)->lpVtbl->GetVarIndexOfMemId(A,B,C)
#define ITypeInfo2_GetCustData(A,B,C) (A)->lpVtbl->GetCustData(A,B,C)
#define ITypeInfo2_GetFuncCustData(A,B,C,D) (A)->lpVtbl->GetFuncCustData(A,B,C,D)
#define ITypeInfo2_GetParamCustData(A,B,C,D,E) (A)->lpVtbl->GetParamCustData(A,B,C,D,E)
#define ITypeInfo2_GetVarCustData(A,B,C,D) (A)->lpVtbl->GetVarCustData(A,B,C,D)
#define ITypeInfo2_GetImplTypeCustData(A,B,C,D) (A)->lpVtbl->GetImplTypeCustData(A,B,C,D)
#define ITypeInfo2_GetDocumentation2(A,B,C,D,E,F) (A)->lpVtbl->GetDocumentation2(A,B,C,D,E,F)
#define ITypeInfo2_GetAllCustData(A,B) (A)->lpVtbl->GetAllCustData(A,B)
#define ITypeInfo2_GetAllFuncCustData(A,B,C) (A)->lpVtbl->GetAllFuncCustData(A,B,C)
#define ITypeInfo2_GetAllParamCustData(A,B,C,D) (A)->lpVtbl->GetAllParamCustData(A,B,C,D)
#define ITypeInfo2_GetAllVarCustData(A,B,C) (A)->lpVtbl->GetAllVarCustData(A,B,C)
#define ITypeInfo2_GetAllImplTypeCustData(A,B,C) (A)->lpVtbl->GetAllImplTypeCustData(A,B,C)
#endif 
HRESULT ITypeInfo2_GetTypeKind_Proxy(ITypeInfo2 *,TYPEKIND *);
void ITypeInfo2_GetTypeKind_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetTypeFlags_Proxy(ITypeInfo2 *,ULONG *);
void ITypeInfo2_GetTypeFlags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetFuncIndexOfMemId_Proxy(ITypeInfo2 *,MEMBERID ,INVOKEKIND ,UINT *);
void ITypeInfo2_GetFuncIndexOfMemId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetVarIndexOfMemId_Proxy(ITypeInfo2 *,MEMBERID ,UINT *);
void ITypeInfo2_GetVarIndexOfMemId_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetCustData_Proxy(ITypeInfo2 *,REFGUID ,VARIANT *);
void ITypeInfo2_GetCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetFuncCustData_Proxy(ITypeInfo2 *,UINT ,REFGUID ,VARIANT *);
void ITypeInfo2_GetFuncCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetParamCustData_Proxy(ITypeInfo2 *,UINT ,UINT ,REFGUID ,VARIANT *);
void ITypeInfo2_GetParamCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetVarCustData_Proxy(ITypeInfo2 *,UINT ,REFGUID ,VARIANT *);
void ITypeInfo2_GetVarCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetImplTypeCustData_Proxy(ITypeInfo2 *,UINT ,REFGUID ,VARIANT *);
void ITypeInfo2_GetImplTypeCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_RemoteGetDocumentation2_Proxy(ITypeInfo2 *,MEMBERID ,LCID ,DWORD ,BSTR *,DWORD *,BSTR *);
void ITypeInfo2_RemoteGetDocumentation2_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetAllCustData_Proxy(ITypeInfo2 *,CUSTDATA *);
void ITypeInfo2_GetAllCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetAllFuncCustData_Proxy(ITypeInfo2 *,UINT ,CUSTDATA *);
void ITypeInfo2_GetAllFuncCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetAllParamCustData_Proxy(ITypeInfo2 *,UINT ,UINT ,CUSTDATA *);
void ITypeInfo2_GetAllParamCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetAllVarCustData_Proxy(ITypeInfo2 *,UINT ,CUSTDATA *);
void ITypeInfo2_GetAllVarCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeInfo2_GetAllImplTypeCustData_Proxy(ITypeInfo2 *,UINT ,CUSTDATA *);
void ITypeInfo2_GetAllImplTypeCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ITypeLib_INTERFACE_DEFINED__
#define __ITypeLib_INTERFACE_DEFINED__
typedef  
enum tagSYSKIND
{	SYS_WIN16=0,
SYS_WIN32=SYS_WIN16 + 1,
SYS_MAC=SYS_WIN32 + 1,
SYS_WIN64=SYS_MAC + 1
} SYSKIND;
typedef  
enum tagLIBFLAGS
{	LIBFLAG_FRESTRICTED=1,
LIBFLAG_FCONTROL=2,
LIBFLAG_FHIDDEN=4,
LIBFLAG_FHASDISKIMAGE=8
} LIBFLAGS;
typedef  ITypeLib *LPTYPELIB;
typedef struct tagTLIBATTR
{
GUID guid;
LCID lcid;
SYSKIND syskind;
WORD wMajorVerNum;
WORD wMinorVerNum;
WORD wLibFlags;
} TLIBATTR;
typedef struct tagTLIBATTR *LPTLIBATTR;
EXTERN_C const IID IID_ITypeLib;
typedef struct ITypeLibVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ITypeLib *,REFIID,void **);
 ULONG (*AddRef)(ITypeLib *);
 ULONG (*Release)(ITypeLib *);
 UINT (*GetTypeInfoCount)(ITypeLib *);
 HRESULT (*GetTypeInfo)(ITypeLib *,UINT,ITypeInfo **);
 HRESULT (*GetTypeInfoType)(ITypeLib *,UINT,TYPEKIND *);
 HRESULT (*GetTypeInfoOfGuid)(ITypeLib *,REFGUID,ITypeInfo **);
 HRESULT (*GetLibAttr)(ITypeLib *,TLIBATTR **);
 HRESULT (*GetTypeComp)(ITypeLib *,ITypeComp **);
 HRESULT (*GetDocumentation)(ITypeLib *,INT,BSTR *,BSTR *,DWORD *,BSTR *);
 HRESULT (*IsName)(ITypeLib *,LPOLESTR,ULONG,BOOL *);
 HRESULT (*FindName)(ITypeLib *,LPOLESTR,ULONG,ITypeInfo **,MEMBERID *,USHORT *);
 void (*ReleaseTLibAttr)(ITypeLib *,TLIBATTR *);
END_INTERFACE
} ITypeLibVtbl;
interface ITypeLib
{
CONST_VTBL struct ITypeLibVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITypeLib_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITypeLib_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITypeLib_Release(A) (A)->lpVtbl->Release(A)
#define ITypeLib_GetTypeInfoCount(A) (A)->lpVtbl->GetTypeInfoCount(A)
#define ITypeLib_GetTypeInfo(A,B,C) (A)->lpVtbl->GetTypeInfo(A,B,C)
#define ITypeLib_GetTypeInfoType(A,B,C) (A)->lpVtbl->GetTypeInfoType(A,B,C)
#define ITypeLib_GetTypeInfoOfGuid(A,B,C) (A)->lpVtbl->GetTypeInfoOfGuid(A,B,C)
#define ITypeLib_GetLibAttr(A,B) (A)->lpVtbl->GetLibAttr(A,B)
#define ITypeLib_GetTypeComp(A,B) (A)->lpVtbl->GetTypeComp(A,B)
#define ITypeLib_GetDocumentation(A,B,C,D,E,F) (A)->lpVtbl->GetDocumentation(A,B,C,D,E,F)
#define ITypeLib_IsName(A,B,C,D) (A)->lpVtbl->IsName(A,B,C,D)
#define ITypeLib_FindName(A,B,C,D,E,F) (A)->lpVtbl->FindName(A,B,C,D,E,F)
#define ITypeLib_ReleaseTLibAttr(A,B) (A)->lpVtbl->ReleaseTLibAttr(A,B)
#endif 
HRESULT ITypeLib_RemoteGetTypeInfoCount_Proxy(ITypeLib *,UINT *);
void ITypeLib_RemoteGetTypeInfoCount_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_GetTypeInfo_Proxy(ITypeLib *,UINT ,ITypeInfo **);
void ITypeLib_GetTypeInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_GetTypeInfoType_Proxy(ITypeLib *,UINT ,TYPEKIND *);
void ITypeLib_GetTypeInfoType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_GetTypeInfoOfGuid_Proxy(ITypeLib *,REFGUID ,ITypeInfo **);
void ITypeLib_GetTypeInfoOfGuid_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_RemoteGetLibAttr_Proxy(ITypeLib *,LPTLIBATTR *,CLEANLOCALSTORAGE *);
void ITypeLib_RemoteGetLibAttr_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_GetTypeComp_Proxy(ITypeLib *,ITypeComp **);
void ITypeLib_GetTypeComp_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_RemoteGetDocumentation_Proxy(ITypeLib *,INT ,DWORD ,BSTR *,BSTR *,DWORD *,BSTR *);
void ITypeLib_RemoteGetDocumentation_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_RemoteIsName_Proxy(ITypeLib *,LPOLESTR ,ULONG ,BOOL *,BSTR *);
void ITypeLib_RemoteIsName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_RemoteFindName_Proxy(ITypeLib *,LPOLESTR ,ULONG ,ITypeInfo **,MEMBERID *,USHORT *,BSTR *);
void ITypeLib_RemoteFindName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib_LocalReleaseTLibAttr_Proxy(ITypeLib *);
void ITypeLib_LocalReleaseTLibAttr_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ITypeLib2_INTERFACE_DEFINED__
#define __ITypeLib2_INTERFACE_DEFINED__
typedef  ITypeLib2 *LPTYPELIB2;
EXTERN_C const IID IID_ITypeLib2;
typedef struct ITypeLib2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ITypeLib2 *,REFIID,void **);
 ULONG (*AddRef)(ITypeLib2 *);
 ULONG (*Release)(ITypeLib2 *);
 UINT (*GetTypeInfoCount)(ITypeLib2 *);
 HRESULT (*GetTypeInfo)(ITypeLib2 *,UINT,ITypeInfo **);
 HRESULT (*GetTypeInfoType)(ITypeLib2 *,UINT,TYPEKIND *);
 HRESULT (*GetTypeInfoOfGuid)(ITypeLib2 *,REFGUID,ITypeInfo **);
 HRESULT (*GetLibAttr)(ITypeLib2 *,TLIBATTR **);
 HRESULT (*GetTypeComp)(ITypeLib2 *,ITypeComp **);
 HRESULT (*GetDocumentation)(ITypeLib2 *,INT,BSTR *,BSTR *,DWORD *,BSTR *);
 HRESULT (*IsName)(ITypeLib2 *,LPOLESTR,ULONG,BOOL *);
 HRESULT (*FindName)(ITypeLib2 *,LPOLESTR,ULONG,ITypeInfo **,MEMBERID *,USHORT *);
 void (*ReleaseTLibAttr)(ITypeLib2 *,TLIBATTR *);
 HRESULT (*GetCustData)(ITypeLib2 *,REFGUID,VARIANT *);
 HRESULT (*GetLibStatistics)(ITypeLib2 *,ULONG *,ULONG *);
 HRESULT (*GetDocumentation2)(ITypeLib2 *,INT,LCID,BSTR *,DWORD *,BSTR *);
 HRESULT (*GetAllCustData)(ITypeLib2 *,CUSTDATA *);
END_INTERFACE
} ITypeLib2Vtbl;
interface ITypeLib2
{
CONST_VTBL struct ITypeLib2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITypeLib2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITypeLib2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITypeLib2_Release(A) (A)->lpVtbl->Release(A)
#define ITypeLib2_GetTypeInfoCount(A) (A)->lpVtbl->GetTypeInfoCount(A)
#define ITypeLib2_GetTypeInfo(A,B,C) (A)->lpVtbl->GetTypeInfo(A,B,C)
#define ITypeLib2_GetTypeInfoType(A,B,C) (A)->lpVtbl->GetTypeInfoType(A,B,C)
#define ITypeLib2_GetTypeInfoOfGuid(A,B,C) (A)->lpVtbl->GetTypeInfoOfGuid(A,B,C)
#define ITypeLib2_GetLibAttr(A,B) (A)->lpVtbl->GetLibAttr(A,B)
#define ITypeLib2_GetTypeComp(A,B) (A)->lpVtbl->GetTypeComp(A,B)
#define ITypeLib2_GetDocumentation(A,B,C,D,E,F) (A)->lpVtbl->GetDocumentation(A,B,C,D,E,F)
#define ITypeLib2_IsName(A,B,C,D) (A)->lpVtbl->IsName(A,B,C,D)
#define ITypeLib2_FindName(A,B,C,D,E,F) (A)->lpVtbl->FindName(A,B,C,D,E,F)
#define ITypeLib2_ReleaseTLibAttr(A,B) (A)->lpVtbl->ReleaseTLibAttr(A,B)
#define ITypeLib2_GetCustData(A,B,C) (A)->lpVtbl->GetCustData(A,B,C)
#define ITypeLib2_GetLibStatistics(A,B,C) (A)->lpVtbl->GetLibStatistics(A,B,C)
#define ITypeLib2_GetDocumentation2(A,B,C,D,E,F) (A)->lpVtbl->GetDocumentation2(A,B,C,D,E,F)
#define ITypeLib2_GetAllCustData(A,B) (A)->lpVtbl->GetAllCustData(A,B)
#endif 
HRESULT ITypeLib2_GetCustData_Proxy(ITypeLib2 *,REFGUID ,VARIANT *);
void ITypeLib2_GetCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib2_RemoteGetLibStatistics_Proxy(ITypeLib2 *,ULONG *,ULONG *);
void ITypeLib2_RemoteGetLibStatistics_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib2_RemoteGetDocumentation2_Proxy(ITypeLib2 *,INT ,LCID ,DWORD ,BSTR *,DWORD *,BSTR *);
void ITypeLib2_RemoteGetDocumentation2_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeLib2_GetAllCustData_Proxy(ITypeLib2 *,CUSTDATA *);
void ITypeLib2_GetAllCustData_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ITypeChangeEvents_INTERFACE_DEFINED__
#define __ITypeChangeEvents_INTERFACE_DEFINED__
typedef  ITypeChangeEvents *LPTYPECHANGEEVENTS;
typedef 
enum tagCHANGEKIND
{	CHANGEKIND_ADDMEMBER=0,
CHANGEKIND_DELETEMEMBER=CHANGEKIND_ADDMEMBER + 1,
CHANGEKIND_SETNAMES=CHANGEKIND_DELETEMEMBER + 1,
CHANGEKIND_SETDOCUMENTATION=CHANGEKIND_SETNAMES + 1,
CHANGEKIND_GENERAL=CHANGEKIND_SETDOCUMENTATION + 1,
CHANGEKIND_INVALIDATE=CHANGEKIND_GENERAL + 1,
CHANGEKIND_CHANGEFAILED=CHANGEKIND_INVALIDATE + 1,
CHANGEKIND_MAX=CHANGEKIND_CHANGEFAILED + 1
} CHANGEKIND;
EXTERN_C const IID IID_ITypeChangeEvents;
typedef struct ITypeChangeEventsVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ITypeChangeEvents *,REFIID,void **);
 ULONG (*AddRef)(ITypeChangeEvents *);
 ULONG (*Release)(ITypeChangeEvents *);
 HRESULT (*RequestTypeChange)(ITypeChangeEvents *,CHANGEKIND,ITypeInfo *,LPOLESTR,INT *);
 HRESULT (*AfterTypeChange)(ITypeChangeEvents *,CHANGEKIND,ITypeInfo *,LPOLESTR);
END_INTERFACE
} ITypeChangeEventsVtbl;
interface ITypeChangeEvents
{
CONST_VTBL struct ITypeChangeEventsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITypeChangeEvents_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITypeChangeEvents_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITypeChangeEvents_Release(A) (A)->lpVtbl->Release(A)
#define ITypeChangeEvents_RequestTypeChange(A,B,C,D,E) (A)->lpVtbl->RequestTypeChange(A,B,C,D,E)
#define ITypeChangeEvents_AfterTypeChange(A,B,C,D) (A)->lpVtbl->AfterTypeChange(A,B,C,D)
#endif 
HRESULT ITypeChangeEvents_RequestTypeChange_Proxy(ITypeChangeEvents *,CHANGEKIND ,ITypeInfo *,LPOLESTR ,INT *);
void ITypeChangeEvents_RequestTypeChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeChangeEvents_AfterTypeChange_Proxy(ITypeChangeEvents *,CHANGEKIND ,ITypeInfo *,LPOLESTR );
void ITypeChangeEvents_AfterTypeChange_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IErrorInfo_INTERFACE_DEFINED__
#define __IErrorInfo_INTERFACE_DEFINED__
typedef  IErrorInfo *LPERRORINFO;
EXTERN_C const IID IID_IErrorInfo;
typedef struct IErrorInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IErrorInfo *,REFIID,void **);
 ULONG (*AddRef)(IErrorInfo *);
 ULONG (*Release)(IErrorInfo *);
 HRESULT (*GetGUID)(IErrorInfo *,GUID *);
 HRESULT (*GetSource)(IErrorInfo *,BSTR *);
 HRESULT (*GetDescription)(IErrorInfo *,BSTR *);
 HRESULT (*GetHelpFile)(IErrorInfo *,BSTR *);
 HRESULT (*GetHelpContext)(IErrorInfo *,DWORD *);
END_INTERFACE
} IErrorInfoVtbl;
interface IErrorInfo
{
CONST_VTBL struct IErrorInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IErrorInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IErrorInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IErrorInfo_Release(A) (A)->lpVtbl->Release(A)
#define IErrorInfo_GetGUID(A,B) (A)->lpVtbl->GetGUID(A,B)
#define IErrorInfo_GetSource(A,B) (A)->lpVtbl->GetSource(A,B)
#define IErrorInfo_GetDescription(A,B) (A)->lpVtbl->GetDescription(A,B)
#define IErrorInfo_GetHelpFile(A,B) (A)->lpVtbl->GetHelpFile(A,B)
#define IErrorInfo_GetHelpContext(A,B) (A)->lpVtbl->GetHelpContext(A,B)
#endif 
HRESULT IErrorInfo_GetGUID_Proxy(IErrorInfo *,GUID *);
void IErrorInfo_GetGUID_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IErrorInfo_GetSource_Proxy(IErrorInfo *,BSTR *);
void IErrorInfo_GetSource_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IErrorInfo_GetDescription_Proxy(IErrorInfo *,BSTR *);
void IErrorInfo_GetDescription_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IErrorInfo_GetHelpFile_Proxy(IErrorInfo *,BSTR *);
void IErrorInfo_GetHelpFile_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IErrorInfo_GetHelpContext_Proxy(IErrorInfo *,DWORD *);
void IErrorInfo_GetHelpContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ICreateErrorInfo_INTERFACE_DEFINED__
#define __ICreateErrorInfo_INTERFACE_DEFINED__
typedef  ICreateErrorInfo *LPCREATEERRORINFO;
EXTERN_C const IID IID_ICreateErrorInfo;
typedef struct ICreateErrorInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ICreateErrorInfo *,REFIID,void **);
 ULONG (*AddRef)(ICreateErrorInfo *);
 ULONG (*Release)(ICreateErrorInfo *);
 HRESULT (*SetGUID)(ICreateErrorInfo *,REFGUID);
 HRESULT (*SetSource)(ICreateErrorInfo *,LPOLESTR);
 HRESULT (*SetDescription)(ICreateErrorInfo *,LPOLESTR);
 HRESULT (*SetHelpFile)(ICreateErrorInfo *,LPOLESTR);
 HRESULT (*SetHelpContext)(ICreateErrorInfo *,DWORD);
END_INTERFACE
} ICreateErrorInfoVtbl;
interface ICreateErrorInfo
{
CONST_VTBL struct ICreateErrorInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ICreateErrorInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ICreateErrorInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ICreateErrorInfo_Release(A) (A)->lpVtbl->Release(A)
#define ICreateErrorInfo_SetGUID(A,B) (A)->lpVtbl->SetGUID(A,B)
#define ICreateErrorInfo_SetSource(A,B) (A)->lpVtbl->SetSource(A,B)
#define ICreateErrorInfo_SetDescription(A,B) (A)->lpVtbl->SetDescription(A,B)
#define ICreateErrorInfo_SetHelpFile(A,B) (A)->lpVtbl->SetHelpFile(A,B)
#define ICreateErrorInfo_SetHelpContext(A,B) (A)->lpVtbl->SetHelpContext(A,B)
#endif 
HRESULT ICreateErrorInfo_SetGUID_Proxy(ICreateErrorInfo *,REFGUID );
void ICreateErrorInfo_SetGUID_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateErrorInfo_SetSource_Proxy(ICreateErrorInfo *,LPOLESTR );
void ICreateErrorInfo_SetSource_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateErrorInfo_SetDescription_Proxy(ICreateErrorInfo *,LPOLESTR );
void ICreateErrorInfo_SetDescription_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateErrorInfo_SetHelpFile_Proxy(ICreateErrorInfo *,LPOLESTR );
void ICreateErrorInfo_SetHelpFile_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ICreateErrorInfo_SetHelpContext_Proxy(ICreateErrorInfo *,DWORD );
void ICreateErrorInfo_SetHelpContext_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ISupportErrorInfo_INTERFACE_DEFINED__
#define __ISupportErrorInfo_INTERFACE_DEFINED__
typedef  ISupportErrorInfo *LPSUPPORTERRORINFO;
EXTERN_C const IID IID_ISupportErrorInfo;
typedef struct ISupportErrorInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ISupportErrorInfo *,REFIID,void **);
 ULONG (*AddRef)(ISupportErrorInfo *);
 ULONG (*Release)(ISupportErrorInfo *);
 HRESULT (*InterfaceSupportsErrorInfo)(ISupportErrorInfo *,REFIID);
END_INTERFACE
} ISupportErrorInfoVtbl;
interface ISupportErrorInfo
{
CONST_VTBL struct ISupportErrorInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISupportErrorInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISupportErrorInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISupportErrorInfo_Release(A) (A)->lpVtbl->Release(A)
#define ISupportErrorInfo_InterfaceSupportsErrorInfo(A,B) (A)->lpVtbl->InterfaceSupportsErrorInfo(A,B)
#endif 
HRESULT ISupportErrorInfo_InterfaceSupportsErrorInfo_Proxy(ISupportErrorInfo *,REFIID );
void ISupportErrorInfo_InterfaceSupportsErrorInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ITypeFactory_INTERFACE_DEFINED__
#define __ITypeFactory_INTERFACE_DEFINED__
EXTERN_C const IID IID_ITypeFactory;
typedef struct ITypeFactoryVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ITypeFactory *,REFIID,void **);
 ULONG (*AddRef)(ITypeFactory *);
 ULONG (*Release)(ITypeFactory *);
 HRESULT (*CreateFromTypeInfo)(ITypeFactory *,ITypeInfo *,REFIID,IUnknown **);
END_INTERFACE
} ITypeFactoryVtbl;
interface ITypeFactory
{
CONST_VTBL struct ITypeFactoryVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITypeFactory_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITypeFactory_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITypeFactory_Release(A) (A)->lpVtbl->Release(A)
#define ITypeFactory_CreateFromTypeInfo(A,B,C,D) (A)->lpVtbl->CreateFromTypeInfo(A,B,C,D)
#endif 
HRESULT ITypeFactory_CreateFromTypeInfo_Proxy(ITypeFactory *,ITypeInfo *,REFIID ,IUnknown **);
void ITypeFactory_CreateFromTypeInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ITypeMarshal_INTERFACE_DEFINED__
#define __ITypeMarshal_INTERFACE_DEFINED__
EXTERN_C const IID IID_ITypeMarshal;
typedef struct ITypeMarshalVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ITypeMarshal *,REFIID,void **);
 ULONG (*AddRef)(ITypeMarshal *);
 ULONG (*Release)(ITypeMarshal *);
 HRESULT (*Size)(ITypeMarshal *,PVOID,DWORD,PVOID,ULONG *);
 HRESULT (*Marshal)(ITypeMarshal *,PVOID,DWORD,PVOID,ULONG,BYTE *,ULONG *);
 HRESULT (*Unmarshal)(ITypeMarshal *,PVOID,DWORD,ULONG,BYTE *,ULONG *);
 HRESULT (*Free)(ITypeMarshal *,PVOID);
END_INTERFACE
} ITypeMarshalVtbl;
interface ITypeMarshal
{
CONST_VTBL struct ITypeMarshalVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ITypeMarshal_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ITypeMarshal_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ITypeMarshal_Release(A) (A)->lpVtbl->Release(A)
#define ITypeMarshal_Size(A,B,C,D,E) (A)->lpVtbl->Size(A,B,C,D,E)
#define ITypeMarshal_Marshal(A,B,C,D,E,F,G) (A)->lpVtbl->Marshal(A,B,C,D,E,F,G)
#define ITypeMarshal_Unmarshal(A,B,C,D,E,F) (A)->lpVtbl->Unmarshal(A,B,C,D,E,F)
#define ITypeMarshal_Free(A,B) (A)->lpVtbl->Free(A,B)
#endif 
HRESULT ITypeMarshal_Size_Proxy(ITypeMarshal *,PVOID ,DWORD ,PVOID ,ULONG *);
void ITypeMarshal_Size_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeMarshal_Marshal_Proxy(ITypeMarshal *,PVOID ,DWORD ,PVOID ,ULONG ,BYTE *,ULONG *);
void ITypeMarshal_Marshal_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeMarshal_Unmarshal_Proxy(ITypeMarshal *,PVOID ,DWORD ,ULONG ,BYTE *,ULONG *);
void ITypeMarshal_Unmarshal_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ITypeMarshal_Free_Proxy(ITypeMarshal *,PVOID );
void ITypeMarshal_Free_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IRecordInfo_INTERFACE_DEFINED__
#define __IRecordInfo_INTERFACE_DEFINED__
typedef  IRecordInfo *LPRECORDINFO;
EXTERN_C const IID IID_IRecordInfo;
typedef struct IRecordInfoVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IRecordInfo *,REFIID,void **);
 ULONG (*AddRef)(IRecordInfo *);
 ULONG (*Release)(IRecordInfo *);
 HRESULT (*RecordInit)(IRecordInfo *,PVOID);
 HRESULT (*RecordClear)(IRecordInfo *,PVOID);
 HRESULT (*RecordCopy)(IRecordInfo *,PVOID,PVOID);
 HRESULT (*GetGuid)(IRecordInfo *,GUID *);
 HRESULT (*GetName)(IRecordInfo *,BSTR *);
 HRESULT (*GetSize)(IRecordInfo *,ULONG *);
 HRESULT (*GetTypeInfo)(IRecordInfo *,ITypeInfo **);
 HRESULT (*GetField)(IRecordInfo *,PVOID,LPCOLESTR,VARIANT *);
 HRESULT (*GetFieldNoCopy)(IRecordInfo *,PVOID,LPCOLESTR,VARIANT *,PVOID *);
 HRESULT (*PutField)(IRecordInfo *,ULONG,PVOID,LPCOLESTR,VARIANT *);
 HRESULT (*PutFieldNoCopy)(IRecordInfo *,ULONG,PVOID,LPCOLESTR,VARIANT *);
 HRESULT (*GetFieldNames)(IRecordInfo *,ULONG *,BSTR *);
 BOOL (*IsMatchingType)(IRecordInfo *,IRecordInfo *);
 PVOID (*RecordCreate)(IRecordInfo *);
 HRESULT (*RecordCreateCopy)(IRecordInfo *,PVOID,PVOID *);
 HRESULT (*RecordDestroy)(IRecordInfo *,PVOID);
END_INTERFACE
} IRecordInfoVtbl;
interface IRecordInfo
{
CONST_VTBL struct IRecordInfoVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IRecordInfo_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IRecordInfo_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IRecordInfo_Release(A) (A)->lpVtbl->Release(A)
#define IRecordInfo_RecordInit(A,B) (A)->lpVtbl->RecordInit(A,B)
#define IRecordInfo_RecordClear(A,B) (A)->lpVtbl->RecordClear(A,B)
#define IRecordInfo_RecordCopy(A,B,C) (A)->lpVtbl->RecordCopy(A,B,C)
#define IRecordInfo_GetGuid(A,B) (A)->lpVtbl->GetGuid(A,B)
#define IRecordInfo_GetName(A,B) (A)->lpVtbl->GetName(A,B)
#define IRecordInfo_GetSize(A,B) (A)->lpVtbl->GetSize(A,B)
#define IRecordInfo_GetTypeInfo(A,B) (A)->lpVtbl->GetTypeInfo(A,B)
#define IRecordInfo_GetField(A,B,C,D) (A)->lpVtbl->GetField(A,B,C,D)
#define IRecordInfo_GetFieldNoCopy(A,B,C,D,E) (A)->lpVtbl->GetFieldNoCopy(A,B,C,D,E)
#define IRecordInfo_PutField(A,B,C,D,E) (A)->lpVtbl->PutField(A,B,C,D,E)
#define IRecordInfo_PutFieldNoCopy(A,B,C,D,E) (A)->lpVtbl->PutFieldNoCopy(A,B,C,D,E)
#define IRecordInfo_GetFieldNames(A,B,C) (A)->lpVtbl->GetFieldNames(A,B,C)
#define IRecordInfo_IsMatchingType(A,B) (A)->lpVtbl->IsMatchingType(A,B)
#define IRecordInfo_RecordCreate(A) (A)->lpVtbl->RecordCreate(A)
#define IRecordInfo_RecordCreateCopy(A,B,C) (A)->lpVtbl->RecordCreateCopy(A,B,C)
#define IRecordInfo_RecordDestroy(A,B) (A)->lpVtbl->RecordDestroy(A,B)
#endif 
HRESULT IRecordInfo_RecordInit_Proxy(IRecordInfo *,PVOID );
void IRecordInfo_RecordInit_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_RecordClear_Proxy(IRecordInfo *,PVOID );
void IRecordInfo_RecordClear_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_RecordCopy_Proxy(IRecordInfo *,PVOID ,PVOID );
void IRecordInfo_RecordCopy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_GetGuid_Proxy(IRecordInfo *,GUID *);
void IRecordInfo_GetGuid_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_GetName_Proxy(IRecordInfo *,BSTR *);
void IRecordInfo_GetName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_GetSize_Proxy(IRecordInfo *,ULONG *);
void IRecordInfo_GetSize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_GetTypeInfo_Proxy(IRecordInfo *,ITypeInfo **);
void IRecordInfo_GetTypeInfo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_GetField_Proxy(IRecordInfo *,PVOID ,LPCOLESTR ,VARIANT *);
void IRecordInfo_GetField_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_GetFieldNoCopy_Proxy(IRecordInfo *,PVOID ,LPCOLESTR ,VARIANT *,PVOID *);
void IRecordInfo_GetFieldNoCopy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_PutField_Proxy(IRecordInfo *,ULONG ,PVOID ,LPCOLESTR ,VARIANT *);
void IRecordInfo_PutField_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_PutFieldNoCopy_Proxy(IRecordInfo *,ULONG ,PVOID ,LPCOLESTR ,VARIANT *);
void IRecordInfo_PutFieldNoCopy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_GetFieldNames_Proxy(IRecordInfo *,ULONG *,BSTR *);
void IRecordInfo_GetFieldNames_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
BOOL IRecordInfo_IsMatchingType_Proxy(IRecordInfo *,IRecordInfo *);
void IRecordInfo_IsMatchingType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
PVOID IRecordInfo_RecordCreate_Proxy(IRecordInfo *);
void IRecordInfo_RecordCreate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_RecordCreateCopy_Proxy(IRecordInfo *,PVOID ,PVOID *);
void IRecordInfo_RecordCreateCopy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IRecordInfo_RecordDestroy_Proxy(IRecordInfo *,PVOID );
void IRecordInfo_RecordDestroy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IErrorLog_INTERFACE_DEFINED__
#define __IErrorLog_INTERFACE_DEFINED__
typedef IErrorLog *LPERRORLOG;
EXTERN_C const IID IID_IErrorLog;
typedef struct IErrorLogVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IErrorLog *,REFIID,void **);
 ULONG (*AddRef)(IErrorLog *);
 ULONG (*Release)(IErrorLog *);
 HRESULT (*AddError)(IErrorLog *,LPCOLESTR,EXCEPINFO *);
END_INTERFACE
} IErrorLogVtbl;
interface IErrorLog
{
CONST_VTBL struct IErrorLogVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IErrorLog_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IErrorLog_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IErrorLog_Release(A) (A)->lpVtbl->Release(A)
#define IErrorLog_AddError(A,B,C) (A)->lpVtbl->AddError(A,B,C)
#endif 
HRESULT IErrorLog_AddError_Proxy(IErrorLog *,LPCOLESTR ,EXCEPINFO *);
void IErrorLog_AddError_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IPropertyBag_INTERFACE_DEFINED__
#define __IPropertyBag_INTERFACE_DEFINED__
typedef IPropertyBag *LPPROPERTYBAG;
EXTERN_C const IID IID_IPropertyBag;
typedef struct IPropertyBagVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IPropertyBag *,REFIID,void **);
 ULONG (*AddRef)(IPropertyBag *);
 ULONG (*Release)(IPropertyBag *);
 HRESULT (*Read)(IPropertyBag *,LPCOLESTR,VARIANT *,IErrorLog *);
 HRESULT (*Write)(IPropertyBag *,LPCOLESTR,VARIANT *);
END_INTERFACE
} IPropertyBagVtbl;
interface IPropertyBag
{
CONST_VTBL struct IPropertyBagVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPropertyBag_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IPropertyBag_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IPropertyBag_Release(A) (A)->lpVtbl->Release(A)
#define IPropertyBag_Read(A,B,C,D) (A)->lpVtbl->Read(A,B,C,D)
#define IPropertyBag_Write(A,B,C) (A)->lpVtbl->Write(A,B,C)
#endif 
HRESULT IPropertyBag_RemoteRead_Proxy(IPropertyBag *,LPCOLESTR ,VARIANT *,IErrorLog *,DWORD ,IUnknown *);
void IPropertyBag_RemoteRead_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IPropertyBag_Write_Proxy(IPropertyBag *,LPCOLESTR ,VARIANT *);
void IPropertyBag_Write_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#if (_MSC_VER >= 800)
#if _MSC_VER >= 1200
#else
#endif
#endif
extern RPC_IF_HANDLE __MIDL_itf_oaidl_0114_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_oaidl_0114_v0_0_s_ifspec;
unsigned long __RPC_USER BSTR_UserSize(unsigned long *,unsigned ,BSTR *); 
unsigned char * __RPC_USER BSTR_UserMarshal(unsigned long *,unsigned char *,BSTR *); 
unsigned char * __RPC_USER BSTR_UserUnmarshal(unsigned long *,unsigned char *,BSTR *); 
void __RPC_USER BSTR_UserFree(unsigned long *,BSTR *); 
unsigned long __RPC_USER CLEANLOCALSTORAGE_UserSize(unsigned long *,unsigned ,CLEANLOCALSTORAGE *); 
unsigned char * __RPC_USER CLEANLOCALSTORAGE_UserMarshal(unsigned long *,unsigned char *,CLEANLOCALSTORAGE *); 
unsigned char * __RPC_USER CLEANLOCALSTORAGE_UserUnmarshal(unsigned long *,unsigned char *,CLEANLOCALSTORAGE *); 
void __RPC_USER CLEANLOCALSTORAGE_UserFree(unsigned long *,CLEANLOCALSTORAGE *); 
unsigned long __RPC_USER VARIANT_UserSize(unsigned long *,unsigned ,VARIANT *); 
unsigned char * __RPC_USER VARIANT_UserMarshal(unsigned long *,unsigned char *,VARIANT *); 
unsigned char * __RPC_USER VARIANT_UserUnmarshal(unsigned long *,unsigned char *,VARIANT *); 
void __RPC_USER VARIANT_UserFree(unsigned long *,VARIANT *); 
HRESULT IDispatch_Invoke_Proxy(IDispatch *,DISPID ,REFIID ,LCID ,WORD ,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
HRESULT IDispatch_Invoke_Stub(IDispatch *,DISPID ,REFIID ,LCID ,DWORD ,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *,UINT ,UINT *,VARIANTARG *);
HRESULT IEnumVARIANT_Next_Proxy(IEnumVARIANT *,ULONG ,VARIANT *,ULONG *);
HRESULT IEnumVARIANT_Next_Stub(IEnumVARIANT *,ULONG ,VARIANT *,ULONG *);
HRESULT ITypeComp_Bind_Proxy(ITypeComp *,LPOLESTR ,ULONG ,WORD ,ITypeInfo **,DESCKIND *,BINDPTR *);
HRESULT ITypeComp_Bind_Stub(ITypeComp *,LPOLESTR ,ULONG ,WORD ,ITypeInfo **,DESCKIND *,LPFUNCDESC *,LPVARDESC *,ITypeComp **,CLEANLOCALSTORAGE *);
HRESULT ITypeComp_BindType_Proxy(ITypeComp *,LPOLESTR ,ULONG ,ITypeInfo **,ITypeComp **);
HRESULT ITypeComp_BindType_Stub(ITypeComp *,LPOLESTR ,ULONG ,ITypeInfo **);
HRESULT ITypeInfo_GetTypeAttr_Proxy(ITypeInfo *,TYPEATTR **);
HRESULT ITypeInfo_GetTypeAttr_Stub(ITypeInfo *,LPTYPEATTR *,CLEANLOCALSTORAGE *);
HRESULT ITypeInfo_GetFuncDesc_Proxy(ITypeInfo *,UINT ,FUNCDESC **);
HRESULT ITypeInfo_GetFuncDesc_Stub(ITypeInfo *,UINT ,LPFUNCDESC *,CLEANLOCALSTORAGE *);
HRESULT ITypeInfo_GetVarDesc_Proxy(ITypeInfo *,UINT ,VARDESC **);
HRESULT ITypeInfo_GetVarDesc_Stub(ITypeInfo *,UINT ,LPVARDESC *,CLEANLOCALSTORAGE *);
HRESULT ITypeInfo_GetNames_Proxy(ITypeInfo *,MEMBERID ,BSTR *,UINT ,UINT *);
HRESULT ITypeInfo_GetNames_Stub(ITypeInfo *,MEMBERID ,BSTR *,UINT ,UINT *);
HRESULT ITypeInfo_GetIDsOfNames_Proxy(ITypeInfo *,LPOLESTR *,UINT ,MEMBERID *);
HRESULT ITypeInfo_GetIDsOfNames_Stub(ITypeInfo *);
HRESULT ITypeInfo_Invoke_Proxy(ITypeInfo *,PVOID ,MEMBERID ,WORD ,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
HRESULT ITypeInfo_Invoke_Stub(ITypeInfo *);
HRESULT ITypeInfo_GetDocumentation_Proxy(ITypeInfo *,MEMBERID ,BSTR *,BSTR *,DWORD *,BSTR *);
HRESULT ITypeInfo_GetDocumentation_Stub(ITypeInfo *,MEMBERID ,DWORD ,BSTR *,BSTR *,DWORD *,BSTR *);
HRESULT ITypeInfo_GetDllEntry_Proxy(ITypeInfo *,MEMBERID ,INVOKEKIND ,BSTR *,BSTR *,WORD *);
HRESULT ITypeInfo_GetDllEntry_Stub(ITypeInfo *,MEMBERID ,INVOKEKIND ,DWORD ,BSTR *,BSTR *,WORD *);
HRESULT ITypeInfo_AddressOfMember_Proxy(ITypeInfo *,MEMBERID ,INVOKEKIND ,PVOID *);
HRESULT ITypeInfo_AddressOfMember_Stub(ITypeInfo *);
HRESULT ITypeInfo_CreateInstance_Proxy(ITypeInfo *,IUnknown *,REFIID ,PVOID *);
HRESULT ITypeInfo_CreateInstance_Stub(ITypeInfo *,REFIID ,IUnknown **);
HRESULT ITypeInfo_GetContainingTypeLib_Proxy(ITypeInfo *,ITypeLib **,UINT *);
HRESULT ITypeInfo_GetContainingTypeLib_Stub(ITypeInfo *,ITypeLib **,UINT *);
void ITypeInfo_ReleaseTypeAttr_Proxy(ITypeInfo *,TYPEATTR *);
HRESULT ITypeInfo_ReleaseTypeAttr_Stub(ITypeInfo *);
void ITypeInfo_ReleaseFuncDesc_Proxy(ITypeInfo *,FUNCDESC *);
HRESULT ITypeInfo_ReleaseFuncDesc_Stub(ITypeInfo *);
void ITypeInfo_ReleaseVarDesc_Proxy(ITypeInfo *,VARDESC *);
HRESULT ITypeInfo_ReleaseVarDesc_Stub(ITypeInfo *);
HRESULT ITypeInfo2_GetDocumentation2_Proxy(ITypeInfo2 *,MEMBERID ,LCID ,BSTR *,DWORD *,BSTR *);
HRESULT ITypeInfo2_GetDocumentation2_Stub(ITypeInfo2 *,MEMBERID ,LCID ,DWORD ,BSTR *,DWORD *,BSTR *);
UINT ITypeLib_GetTypeInfoCount_Proxy(ITypeLib *);
HRESULT ITypeLib_GetTypeInfoCount_Stub(ITypeLib *,UINT *);
HRESULT ITypeLib_GetLibAttr_Proxy(ITypeLib *,TLIBATTR **);
HRESULT ITypeLib_GetLibAttr_Stub(ITypeLib *,LPTLIBATTR *,CLEANLOCALSTORAGE *);
HRESULT ITypeLib_GetDocumentation_Proxy(ITypeLib *,INT ,BSTR *,BSTR *,DWORD *,BSTR *);
HRESULT ITypeLib_GetDocumentation_Stub(ITypeLib *,INT ,DWORD ,BSTR *,BSTR *,DWORD *,BSTR *);
HRESULT ITypeLib_IsName_Proxy(ITypeLib *,LPOLESTR ,ULONG ,BOOL *);
HRESULT ITypeLib_IsName_Stub(ITypeLib *,LPOLESTR ,ULONG ,BOOL *,BSTR *);
HRESULT ITypeLib_FindName_Proxy(ITypeLib *,LPOLESTR ,ULONG ,ITypeInfo **,MEMBERID *,USHORT *);
HRESULT ITypeLib_FindName_Stub(ITypeLib *,LPOLESTR ,ULONG ,ITypeInfo **,MEMBERID *,USHORT *,BSTR *);
void ITypeLib_ReleaseTLibAttr_Proxy(ITypeLib *,TLIBATTR *);
HRESULT ITypeLib_ReleaseTLibAttr_Stub(ITypeLib *);
HRESULT ITypeLib2_GetLibStatistics_Proxy(ITypeLib2 *,ULONG *,ULONG *);
HRESULT ITypeLib2_GetLibStatistics_Stub(ITypeLib2 *,ULONG *,ULONG *);
HRESULT ITypeLib2_GetDocumentation2_Proxy(ITypeLib2 *,INT ,LCID ,BSTR *,DWORD *,BSTR *);
HRESULT ITypeLib2_GetDocumentation2_Stub(ITypeLib2 *,INT ,LCID ,DWORD ,BSTR *,DWORD *,BSTR *);
HRESULT IPropertyBag_Read_Proxy(IPropertyBag *,LPCOLESTR ,VARIANT *,IErrorLog *);
HRESULT IPropertyBag_Read_Stub(IPropertyBag *,LPCOLESTR ,VARIANT *,IErrorLog *,DWORD ,IUnknown *);
#endif
