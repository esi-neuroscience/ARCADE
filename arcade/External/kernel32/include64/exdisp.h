#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif
#include "rpc.h"
#include "rpcndr.h"
#ifndef __exdisp_h__
#define __exdisp_h__
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#endif
#ifndef __IWebBrowser_FWD_DEFINED__
#define __IWebBrowser_FWD_DEFINED__
typedef interface IWebBrowser IWebBrowser;
#endif 
#ifndef __DWebBrowserEvents_FWD_DEFINED__
#define __DWebBrowserEvents_FWD_DEFINED__
typedef interface DWebBrowserEvents DWebBrowserEvents;
#endif 
#ifndef __IWebBrowserApp_FWD_DEFINED__
#define __IWebBrowserApp_FWD_DEFINED__
typedef interface IWebBrowserApp IWebBrowserApp;
#endif 
#ifndef __IWebBrowser2_FWD_DEFINED__
#define __IWebBrowser2_FWD_DEFINED__
typedef interface IWebBrowser2 IWebBrowser2;
#endif 
#ifndef __DWebBrowserEvents2_FWD_DEFINED__
#define __DWebBrowserEvents2_FWD_DEFINED__
typedef interface DWebBrowserEvents2 DWebBrowserEvents2;
#endif 
#ifndef __WebBrowser_V1_FWD_DEFINED__
#define __WebBrowser_V1_FWD_DEFINED__
typedef struct WebBrowser_V1 WebBrowser_V1;
#endif 
#ifndef __WebBrowser_FWD_DEFINED__
#define __WebBrowser_FWD_DEFINED__
typedef struct WebBrowser WebBrowser;
#endif 
#ifndef __InternetExplorer_FWD_DEFINED__
#define __InternetExplorer_FWD_DEFINED__
typedef struct InternetExplorer InternetExplorer;
#endif 
#ifndef __ShellBrowserWindow_FWD_DEFINED__
#define __ShellBrowserWindow_FWD_DEFINED__
typedef struct ShellBrowserWindow ShellBrowserWindow;
#endif 
#ifndef __DShellWindowsEvents_FWD_DEFINED__
#define __DShellWindowsEvents_FWD_DEFINED__
typedef interface DShellWindowsEvents DShellWindowsEvents;
#endif 
#ifndef __IShellWindows_FWD_DEFINED__
#define __IShellWindows_FWD_DEFINED__
typedef interface IShellWindows IShellWindows;
#endif 
#ifndef __ShellWindows_FWD_DEFINED__
#define __ShellWindows_FWD_DEFINED__
typedef struct ShellWindows ShellWindows;
#endif 
#ifndef __IShellUIHelper_FWD_DEFINED__
#define __IShellUIHelper_FWD_DEFINED__
typedef interface IShellUIHelper IShellUIHelper;
#endif 
#ifndef __ShellUIHelper_FWD_DEFINED__
#define __ShellUIHelper_FWD_DEFINED__
typedef struct ShellUIHelper ShellUIHelper;
#endif 
#ifndef __DShellNameSpaceEvents_FWD_DEFINED__
#define __DShellNameSpaceEvents_FWD_DEFINED__
typedef interface DShellNameSpaceEvents DShellNameSpaceEvents;
#endif 
#ifndef __IShellFavoritesNameSpace_FWD_DEFINED__
#define __IShellFavoritesNameSpace_FWD_DEFINED__
typedef interface IShellFavoritesNameSpace IShellFavoritesNameSpace;
#endif 
#ifndef __IShellNameSpace_FWD_DEFINED__
#define __IShellNameSpace_FWD_DEFINED__
typedef interface IShellNameSpace IShellNameSpace;
#endif 
#ifndef __ShellNameSpace_FWD_DEFINED__
#define __ShellNameSpace_FWD_DEFINED__
typedef struct ShellNameSpace ShellNameSpace;
#endif 
#ifndef __IScriptErrorList_FWD_DEFINED__
#define __IScriptErrorList_FWD_DEFINED__
typedef interface IScriptErrorList IScriptErrorList;
#endif 
#ifndef __CScriptErrorList_FWD_DEFINED__
#define __CScriptErrorList_FWD_DEFINED__
typedef struct CScriptErrorList CScriptErrorList;
#endif 
#ifndef __ISearch_FWD_DEFINED__
#define __ISearch_FWD_DEFINED__
typedef interface ISearch ISearch;
#endif 
#ifndef __ISearches_FWD_DEFINED__
#define __ISearches_FWD_DEFINED__
typedef interface ISearches ISearches;
#endif 
#ifndef __ISearchAssistantOC_FWD_DEFINED__
#define __ISearchAssistantOC_FWD_DEFINED__
typedef interface ISearchAssistantOC ISearchAssistantOC;
#endif 
#ifndef __ISearchAssistantOC2_FWD_DEFINED__
#define __ISearchAssistantOC2_FWD_DEFINED__
typedef interface ISearchAssistantOC2 ISearchAssistantOC2;
#endif 
#ifndef __ISearchAssistantOC3_FWD_DEFINED__
#define __ISearchAssistantOC3_FWD_DEFINED__
typedef interface ISearchAssistantOC3 ISearchAssistantOC3;
#endif 
#ifndef ___SearchAssistantEvents_FWD_DEFINED__
#define ___SearchAssistantEvents_FWD_DEFINED__
typedef interface _SearchAssistantEvents _SearchAssistantEvents;
#endif 
#ifndef __SearchAssistantOC_FWD_DEFINED__
#define __SearchAssistantOC_FWD_DEFINED__
typedef struct SearchAssistantOC SearchAssistantOC;
#endif 
#include "ocidl.h"
#include "docobj.h"
void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void *); 
#ifndef __SHDocVw_LIBRARY_DEFINED__
#define __SHDocVw_LIBRARY_DEFINED__
typedef   DECLSPEC_UUID("34A226E0-DF30-11CF-89A9-00A0C9054129") 
enum CommandStateChangeConstants
{	CSC_UPDATECOMMANDS=0xffffffff,
CSC_NAVIGATEFORWARD=1,
CSC_NAVIGATEBACK=2
} CommandStateChangeConstants;
typedef   DECLSPEC_UUID("65507BE0-91A8-11d3-A845-009027220E6D") 
enum SecureLockIconConstants
{	secureLockIconUnsecure=0,
secureLockIconMixed=1,
secureLockIconSecureUnknownBits=2,
secureLockIconSecure40Bit=3,
secureLockIconSecure56Bit=4,
secureLockIconSecureFortezza=5,
secureLockIconSecure128Bit=6
} SecureLockIconConstants;
typedef   DECLSPEC_UUID("F41E6981-28E5-11d0-82B4-00A0C90C29C5") 
enum ShellWindowTypeConstants
{	SWC_EXPLORER=0,
SWC_BROWSER=1,
SWC_3RDPARTY=2,
SWC_CALLBACK=4
} ShellWindowTypeConstants;
typedef   DECLSPEC_UUID("7716a370-38ca-11d0-a48b-00a0c90a8f39") 
enum ShellWindowFindWindowOptions
{	SWFO_NEEDDISPATCH=1,
SWFO_INCLUDEPENDING=2,
SWFO_COOKIEPASSED=4
} ShellWindowFindWindowOptions;
EXTERN_C const IID LIBID_SHDocVw;
#ifndef __IWebBrowser_INTERFACE_DEFINED__
#define __IWebBrowser_INTERFACE_DEFINED__
typedef   DECLSPEC_UUID("14EE5380-A378-11cf-A731-00A0C9082637") 
enum BrowserNavConstants
{	navOpenInNewWindow=1,
navNoHistory=2,
navNoReadFromCache=4,
navNoWriteToCache=8,
navAllowAutosearch=16,
navBrowserBar=32,
navHyperlink=64,
navEnforceRestricted=128
} BrowserNavConstants;
typedef   DECLSPEC_UUID("C317C261-A991-11cf-A731-00A0C9082637") 
enum RefreshConstants
{	REFRESH_NORMAL=0,
REFRESH_IFEXPIRED=1,
REFRESH_COMPLETELY=3
} RefreshConstants;
EXTERN_C const IID IID_IWebBrowser;
typedef struct IWebBrowserVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IWebBrowser *,REFIID,void **);
 ULONG (*AddRef)(IWebBrowser *);
 ULONG (*Release)(IWebBrowser *);
 HRESULT (*GetTypeInfoCount)(IWebBrowser *,UINT *);
 HRESULT (*GetTypeInfo)(IWebBrowser *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IWebBrowser *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IWebBrowser *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*GoBack)(IWebBrowser *);
 HRESULT (*GoForward)(IWebBrowser *);
 HRESULT (*GoHome)(IWebBrowser *);
 HRESULT (*GoSearch)(IWebBrowser *);
 HRESULT (*Navigate)(IWebBrowser *,BSTR,VARIANT *,VARIANT *,VARIANT *,VARIANT *);
 HRESULT (*Refresh)(IWebBrowser *);
 HRESULT (*Refresh2)(IWebBrowser *,VARIANT *);
 HRESULT (*Stop)(IWebBrowser *);
 HRESULT (*get_Application)(IWebBrowser *,IDispatch **);
 HRESULT (*get_Parent)(IWebBrowser *,IDispatch **);
 HRESULT (*get_Container)(IWebBrowser *,IDispatch **);
 HRESULT (*get_Document)(IWebBrowser *,IDispatch **);
 HRESULT (*get_TopLevelContainer)(IWebBrowser *,VARIANT_BOOL *);
 HRESULT (*get_Type)(IWebBrowser *,BSTR *);
 HRESULT (*get_Left)(IWebBrowser *,long *);
 HRESULT (*put_Left)(IWebBrowser *,long);
 HRESULT (*get_Top)(IWebBrowser *,long *);
 HRESULT (*put_Top)(IWebBrowser *,long);
 HRESULT (*get_Width)(IWebBrowser *,long *);
 HRESULT (*put_Width)(IWebBrowser *,long);
 HRESULT (*get_Height)(IWebBrowser *,long *);
 HRESULT (*put_Height)(IWebBrowser *,long);
 HRESULT (*get_LocationName)(IWebBrowser *,BSTR *);
 HRESULT (*get_LocationURL)(IWebBrowser *,BSTR *);
 HRESULT (*get_Busy)(IWebBrowser *,VARIANT_BOOL *);
END_INTERFACE
} IWebBrowserVtbl;
interface IWebBrowser
{
CONST_VTBL struct IWebBrowserVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWebBrowser_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWebBrowser_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWebBrowser_Release(A) (A)->lpVtbl->Release(A)
#define IWebBrowser_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IWebBrowser_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IWebBrowser_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IWebBrowser_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define IWebBrowser_GoBack(A) (A)->lpVtbl->GoBack(A)
#define IWebBrowser_GoForward(A) (A)->lpVtbl->GoForward(A)
#define IWebBrowser_GoHome(A) (A)->lpVtbl->GoHome(A)
#define IWebBrowser_GoSearch(A) (A)->lpVtbl->GoSearch(A)
#define IWebBrowser_Navigate(A,B,C,D,E,F) (A)->lpVtbl->Navigate(A,B,C,D,E,F)
#define IWebBrowser_Refresh(A) (A)->lpVtbl->Refresh(A)
#define IWebBrowser_Refresh2(A,B) (A)->lpVtbl->Refresh2(A,B)
#define IWebBrowser_Stop(A) (A)->lpVtbl->Stop(A)
#define IWebBrowser_get_Application(A,B) (A)->lpVtbl->get_Application(A,B)
#define IWebBrowser_get_Parent(A,B) (A)->lpVtbl->get_Parent(A,B)
#define IWebBrowser_get_Container(A,B) (A)->lpVtbl->get_Container(A,B)
#define IWebBrowser_get_Document(A,B) (A)->lpVtbl->get_Document(A,B)
#define IWebBrowser_get_TopLevelContainer(A,B) (A)->lpVtbl->get_TopLevelContainer(A,B)
#define IWebBrowser_get_Type(A,B) (A)->lpVtbl->get_Type(A,B)
#define IWebBrowser_get_Left(A,B) (A)->lpVtbl->get_Left(A,B)
#define IWebBrowser_put_Left(A,B) (A)->lpVtbl->put_Left(A,B)
#define IWebBrowser_get_Top(A,B) (A)->lpVtbl->get_Top(A,B)
#define IWebBrowser_put_Top(A,B) (A)->lpVtbl->put_Top(A,B)
#define IWebBrowser_get_Width(A,B) (A)->lpVtbl->get_Width(A,B)
#define IWebBrowser_put_Width(A,B) (A)->lpVtbl->put_Width(A,B)
#define IWebBrowser_get_Height(A,B) (A)->lpVtbl->get_Height(A,B)
#define IWebBrowser_put_Height(A,B) (A)->lpVtbl->put_Height(A,B)
#define IWebBrowser_get_LocationName(A,B) (A)->lpVtbl->get_LocationName(A,B)
#define IWebBrowser_get_LocationURL(A,B) (A)->lpVtbl->get_LocationURL(A,B)
#define IWebBrowser_get_Busy(A,B) (A)->lpVtbl->get_Busy(A,B)
#endif 
HRESULT IWebBrowser_GoBack_Proxy(IWebBrowser *);
void IWebBrowser_GoBack_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_GoForward_Proxy(IWebBrowser *);
void IWebBrowser_GoForward_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_GoHome_Proxy(IWebBrowser *);
void IWebBrowser_GoHome_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_GoSearch_Proxy(IWebBrowser *);
void IWebBrowser_GoSearch_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_Navigate_Proxy(IWebBrowser *,BSTR ,VARIANT *,VARIANT *,VARIANT *,VARIANT *);
void IWebBrowser_Navigate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_Refresh_Proxy(IWebBrowser *);
void IWebBrowser_Refresh_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_Refresh2_Proxy(IWebBrowser *,VARIANT *);
void IWebBrowser_Refresh2_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_Stop_Proxy(IWebBrowser *);
void IWebBrowser_Stop_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Application_Proxy(IWebBrowser *,IDispatch **);
void IWebBrowser_get_Application_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Parent_Proxy(IWebBrowser *,IDispatch **);
void IWebBrowser_get_Parent_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Container_Proxy(IWebBrowser *,IDispatch **);
void IWebBrowser_get_Container_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Document_Proxy(IWebBrowser *,IDispatch **);
void IWebBrowser_get_Document_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_TopLevelContainer_Proxy(IWebBrowser *,VARIANT_BOOL *);
void IWebBrowser_get_TopLevelContainer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Type_Proxy(IWebBrowser *,BSTR *);
void IWebBrowser_get_Type_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Left_Proxy(IWebBrowser *,long *);
void IWebBrowser_get_Left_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_put_Left_Proxy(IWebBrowser *,long );
void IWebBrowser_put_Left_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Top_Proxy(IWebBrowser *,long *);
void IWebBrowser_get_Top_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_put_Top_Proxy(IWebBrowser *,long );
void IWebBrowser_put_Top_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Width_Proxy(IWebBrowser *,long *);
void IWebBrowser_get_Width_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_put_Width_Proxy(IWebBrowser *,long );
void IWebBrowser_put_Width_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Height_Proxy(IWebBrowser *,long *);
void IWebBrowser_get_Height_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_put_Height_Proxy(IWebBrowser *,long );
void IWebBrowser_put_Height_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_LocationName_Proxy(IWebBrowser *,BSTR *);
void IWebBrowser_get_LocationName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_LocationURL_Proxy(IWebBrowser *,BSTR *);
void IWebBrowser_get_LocationURL_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser_get_Busy_Proxy(IWebBrowser *,VARIANT_BOOL *);
void IWebBrowser_get_Busy_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __DWebBrowserEvents_DISPINTERFACE_DEFINED__
#define __DWebBrowserEvents_DISPINTERFACE_DEFINED__
EXTERN_C const IID DIID_DWebBrowserEvents;
typedef struct DWebBrowserEventsVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(DWebBrowserEvents *,REFIID,void **);
 ULONG (*AddRef)(DWebBrowserEvents *);
 ULONG (*Release)(DWebBrowserEvents *);
 HRESULT (*GetTypeInfoCount)(DWebBrowserEvents *,UINT *);
 HRESULT (*GetTypeInfo)(DWebBrowserEvents *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(DWebBrowserEvents *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(DWebBrowserEvents *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
END_INTERFACE
} DWebBrowserEventsVtbl;
interface DWebBrowserEvents
{
CONST_VTBL struct DWebBrowserEventsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define DWebBrowserEvents_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define DWebBrowserEvents_AddRef(A) (A)->lpVtbl->AddRef(A)
#define DWebBrowserEvents_Release(A) (A)->lpVtbl->Release(A)
#define DWebBrowserEvents_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define DWebBrowserEvents_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define DWebBrowserEvents_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define DWebBrowserEvents_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#endif 
#endif 
#ifndef __IWebBrowserApp_INTERFACE_DEFINED__
#define __IWebBrowserApp_INTERFACE_DEFINED__
EXTERN_C const IID IID_IWebBrowserApp;
typedef struct IWebBrowserAppVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IWebBrowserApp *,REFIID,void **);
 ULONG (*AddRef)(IWebBrowserApp *);
 ULONG (*Release)(IWebBrowserApp *);
 HRESULT (*GetTypeInfoCount)(IWebBrowserApp *,UINT *);
 HRESULT (*GetTypeInfo)(IWebBrowserApp *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IWebBrowserApp *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IWebBrowserApp *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*GoBack)(IWebBrowserApp *);
 HRESULT (*GoForward)(IWebBrowserApp *);
 HRESULT (*GoHome)(IWebBrowserApp *);
 HRESULT (*GoSearch)(IWebBrowserApp *);
 HRESULT (*Navigate)(IWebBrowserApp *,BSTR,VARIANT *,VARIANT *,VARIANT *,VARIANT *);
 HRESULT (*Refresh)(IWebBrowserApp *);
 HRESULT (*Refresh2)(IWebBrowserApp *,VARIANT *);
 HRESULT (*Stop)(IWebBrowserApp *);
 HRESULT (*get_Application)(IWebBrowserApp *,IDispatch **);
 HRESULT (*get_Parent)(IWebBrowserApp *,IDispatch **);
 HRESULT (*get_Container)(IWebBrowserApp *,IDispatch **);
 HRESULT (*get_Document)(IWebBrowserApp *,IDispatch **);
 HRESULT (*get_TopLevelContainer)(IWebBrowserApp *,VARIANT_BOOL *);
 HRESULT (*get_Type)(IWebBrowserApp *,BSTR *);
 HRESULT (*get_Left)(IWebBrowserApp *,long *);
 HRESULT (*put_Left)(IWebBrowserApp *,long);
 HRESULT (*get_Top)(IWebBrowserApp *,long *);
 HRESULT (*put_Top)(IWebBrowserApp *,long);
 HRESULT (*get_Width)(IWebBrowserApp *,long *);
 HRESULT (*put_Width)(IWebBrowserApp *,long);
 HRESULT (*get_Height)(IWebBrowserApp *,long *);
 HRESULT (*put_Height)(IWebBrowserApp *,long);
 HRESULT (*get_LocationName)(IWebBrowserApp *,BSTR *);
 HRESULT (*get_LocationURL)(IWebBrowserApp *,BSTR *);
 HRESULT (*get_Busy)(IWebBrowserApp *,VARIANT_BOOL *);
 HRESULT (*Quit)(IWebBrowserApp *);
 HRESULT (*ClientToWindow)(IWebBrowserApp *,int *,int *);
 HRESULT (*PutProperty)(IWebBrowserApp *,BSTR,VARIANT);
 HRESULT (*GetProperty)(IWebBrowserApp *,BSTR,VARIANT *);
 HRESULT (*get_Name)(IWebBrowserApp *,BSTR *);
 HRESULT (*get_HWND)(IWebBrowserApp *,SHANDLE_PTR *);
 HRESULT (*get_FullName)(IWebBrowserApp *,BSTR *);
 HRESULT (*get_Path)(IWebBrowserApp *,BSTR *);
 HRESULT (*get_Visible)(IWebBrowserApp *,VARIANT_BOOL *);
 HRESULT (*put_Visible)(IWebBrowserApp *,VARIANT_BOOL);
 HRESULT (*get_StatusBar)(IWebBrowserApp *,VARIANT_BOOL *);
 HRESULT (*put_StatusBar)(IWebBrowserApp *,VARIANT_BOOL);
 HRESULT (*get_StatusText)(IWebBrowserApp *,BSTR *);
 HRESULT (*put_StatusText)(IWebBrowserApp *,BSTR);
 HRESULT (*get_ToolBar)(IWebBrowserApp *,int *);
 HRESULT (*put_ToolBar)(IWebBrowserApp *,int);
 HRESULT (*get_MenuBar)(IWebBrowserApp *,VARIANT_BOOL *);
 HRESULT (*put_MenuBar)(IWebBrowserApp *,VARIANT_BOOL);
 HRESULT (*get_FullScreen)(IWebBrowserApp *,VARIANT_BOOL *);
 HRESULT (*put_FullScreen)(IWebBrowserApp *,VARIANT_BOOL);
END_INTERFACE
} IWebBrowserAppVtbl;
interface IWebBrowserApp
{
CONST_VTBL struct IWebBrowserAppVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWebBrowserApp_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWebBrowserApp_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWebBrowserApp_Release(A) (A)->lpVtbl->Release(A)
#define IWebBrowserApp_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IWebBrowserApp_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IWebBrowserApp_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IWebBrowserApp_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define IWebBrowserApp_GoBack(A) (A)->lpVtbl->GoBack(A)
#define IWebBrowserApp_GoForward(A) (A)->lpVtbl->GoForward(A)
#define IWebBrowserApp_GoHome(A) (A)->lpVtbl->GoHome(A)
#define IWebBrowserApp_GoSearch(A) (A)->lpVtbl->GoSearch(A)
#define IWebBrowserApp_Navigate(A,B,C,D,E,F) (A)->lpVtbl->Navigate(A,B,C,D,E,F)
#define IWebBrowserApp_Refresh(A) (A)->lpVtbl->Refresh(A)
#define IWebBrowserApp_Refresh2(A,B) (A)->lpVtbl->Refresh2(A,B)
#define IWebBrowserApp_Stop(A) (A)->lpVtbl->Stop(A)
#define IWebBrowserApp_get_Application(A,B) (A)->lpVtbl->get_Application(A,B)
#define IWebBrowserApp_get_Parent(A,B) (A)->lpVtbl->get_Parent(A,B)
#define IWebBrowserApp_get_Container(A,B) (A)->lpVtbl->get_Container(A,B)
#define IWebBrowserApp_get_Document(A,B) (A)->lpVtbl->get_Document(A,B)
#define IWebBrowserApp_get_TopLevelContainer(A,B) (A)->lpVtbl->get_TopLevelContainer(A,B)
#define IWebBrowserApp_get_Type(A,B) (A)->lpVtbl->get_Type(A,B)
#define IWebBrowserApp_get_Left(A,B) (A)->lpVtbl->get_Left(A,B)
#define IWebBrowserApp_put_Left(A,B) (A)->lpVtbl->put_Left(A,B)
#define IWebBrowserApp_get_Top(A,B) (A)->lpVtbl->get_Top(A,B)
#define IWebBrowserApp_put_Top(A,B) (A)->lpVtbl->put_Top(A,B)
#define IWebBrowserApp_get_Width(A,B) (A)->lpVtbl->get_Width(A,B)
#define IWebBrowserApp_put_Width(A,B) (A)->lpVtbl->put_Width(A,B)
#define IWebBrowserApp_get_Height(A,B) (A)->lpVtbl->get_Height(A,B)
#define IWebBrowserApp_put_Height(A,B) (A)->lpVtbl->put_Height(A,B)
#define IWebBrowserApp_get_LocationName(A,B) (A)->lpVtbl->get_LocationName(A,B)
#define IWebBrowserApp_get_LocationURL(A,B) (A)->lpVtbl->get_LocationURL(A,B)
#define IWebBrowserApp_get_Busy(A,B) (A)->lpVtbl->get_Busy(A,B)
#define IWebBrowserApp_Quit(A) (A)->lpVtbl->Quit(A)
#define IWebBrowserApp_ClientToWindow(A,B,C) (A)->lpVtbl->ClientToWindow(A,B,C)
#define IWebBrowserApp_PutProperty(A,B,C) (A)->lpVtbl->PutProperty(A,B,C)
#define IWebBrowserApp_GetProperty(A,B,C) (A)->lpVtbl->GetProperty(A,B,C)
#define IWebBrowserApp_get_Name(A,B) (A)->lpVtbl->get_Name(A,B)
#define IWebBrowserApp_get_HWND(A,B) (A)->lpVtbl->get_HWND(A,B)
#define IWebBrowserApp_get_FullName(A,B) (A)->lpVtbl->get_FullName(A,B)
#define IWebBrowserApp_get_Path(A,B) (A)->lpVtbl->get_Path(A,B)
#define IWebBrowserApp_get_Visible(A,B) (A)->lpVtbl->get_Visible(A,B)
#define IWebBrowserApp_put_Visible(A,B) (A)->lpVtbl->put_Visible(A,B)
#define IWebBrowserApp_get_StatusBar(A,B) (A)->lpVtbl->get_StatusBar(A,B)
#define IWebBrowserApp_put_StatusBar(A,B) (A)->lpVtbl->put_StatusBar(A,B)
#define IWebBrowserApp_get_StatusText(A,B) (A)->lpVtbl->get_StatusText(A,B)
#define IWebBrowserApp_put_StatusText(A,B) (A)->lpVtbl->put_StatusText(A,B)
#define IWebBrowserApp_get_ToolBar(A,B) (A)->lpVtbl->get_ToolBar(A,B)
#define IWebBrowserApp_put_ToolBar(A,B) (A)->lpVtbl->put_ToolBar(A,B)
#define IWebBrowserApp_get_MenuBar(A,B) (A)->lpVtbl->get_MenuBar(A,B)
#define IWebBrowserApp_put_MenuBar(A,B) (A)->lpVtbl->put_MenuBar(A,B)
#define IWebBrowserApp_get_FullScreen(A,B) (A)->lpVtbl->get_FullScreen(A,B)
#define IWebBrowserApp_put_FullScreen(A,B) (A)->lpVtbl->put_FullScreen(A,B)
#endif 
HRESULT IWebBrowserApp_Quit_Proxy(IWebBrowserApp *);
void IWebBrowserApp_Quit_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_ClientToWindow_Proxy(IWebBrowserApp *,int *,int *);
void IWebBrowserApp_ClientToWindow_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_PutProperty_Proxy(IWebBrowserApp *,BSTR ,VARIANT );
void IWebBrowserApp_PutProperty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_GetProperty_Proxy(IWebBrowserApp *,BSTR ,VARIANT *);
void IWebBrowserApp_GetProperty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_Name_Proxy(IWebBrowserApp *,BSTR *);
void IWebBrowserApp_get_Name_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_HWND_Proxy(IWebBrowserApp *,SHANDLE_PTR *);
void IWebBrowserApp_get_HWND_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_FullName_Proxy(IWebBrowserApp *,BSTR *);
void IWebBrowserApp_get_FullName_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_Path_Proxy(IWebBrowserApp *,BSTR *);
void IWebBrowserApp_get_Path_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_Visible_Proxy(IWebBrowserApp *,VARIANT_BOOL *);
void IWebBrowserApp_get_Visible_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_put_Visible_Proxy(IWebBrowserApp *,VARIANT_BOOL );
void IWebBrowserApp_put_Visible_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_StatusBar_Proxy(IWebBrowserApp *,VARIANT_BOOL *);
void IWebBrowserApp_get_StatusBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_put_StatusBar_Proxy(IWebBrowserApp *,VARIANT_BOOL );
void IWebBrowserApp_put_StatusBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_StatusText_Proxy(IWebBrowserApp *,BSTR *);
void IWebBrowserApp_get_StatusText_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_put_StatusText_Proxy(IWebBrowserApp *,BSTR );
void IWebBrowserApp_put_StatusText_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_ToolBar_Proxy(IWebBrowserApp *,int *);
void IWebBrowserApp_get_ToolBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_put_ToolBar_Proxy(IWebBrowserApp *,int );
void IWebBrowserApp_put_ToolBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_MenuBar_Proxy(IWebBrowserApp *,VARIANT_BOOL *);
void IWebBrowserApp_get_MenuBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_put_MenuBar_Proxy(IWebBrowserApp *,VARIANT_BOOL );
void IWebBrowserApp_put_MenuBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_get_FullScreen_Proxy(IWebBrowserApp *,VARIANT_BOOL *);
void IWebBrowserApp_get_FullScreen_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowserApp_put_FullScreen_Proxy(IWebBrowserApp *,VARIANT_BOOL );
void IWebBrowserApp_put_FullScreen_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IWebBrowser2_INTERFACE_DEFINED__
#define __IWebBrowser2_INTERFACE_DEFINED__
EXTERN_C const IID IID_IWebBrowser2;
typedef struct IWebBrowser2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IWebBrowser2 *,REFIID,void **);
 ULONG (*AddRef)(IWebBrowser2 *);
 ULONG (*Release)(IWebBrowser2 *);
 HRESULT (*GetTypeInfoCount)(IWebBrowser2 *,UINT *);
 HRESULT (*GetTypeInfo)(IWebBrowser2 *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IWebBrowser2 *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IWebBrowser2 *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*GoBack)(IWebBrowser2 *);
 HRESULT (*GoForward)(IWebBrowser2 *);
 HRESULT (*GoHome)(IWebBrowser2 *);
 HRESULT (*GoSearch)(IWebBrowser2 *);
 HRESULT (*Navigate)(IWebBrowser2 *,BSTR,VARIANT *,VARIANT *,VARIANT *,VARIANT *);
 HRESULT (*Refresh)(IWebBrowser2 *);
 HRESULT (*Refresh2)(IWebBrowser2 *,VARIANT *);
 HRESULT (*Stop)(IWebBrowser2 *);
 HRESULT (*get_Application)(IWebBrowser2 *,IDispatch **);
 HRESULT (*get_Parent)(IWebBrowser2 *,IDispatch **);
 HRESULT (*get_Container)(IWebBrowser2 *,IDispatch **);
 HRESULT (*get_Document)(IWebBrowser2 *,IDispatch **);
 HRESULT (*get_TopLevelContainer)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*get_Type)(IWebBrowser2 *,BSTR *);
 HRESULT (*get_Left)(IWebBrowser2 *,long *);
 HRESULT (*put_Left)(IWebBrowser2 *,long);
 HRESULT (*get_Top)(IWebBrowser2 *,long *);
 HRESULT (*put_Top)(IWebBrowser2 *,long);
 HRESULT (*get_Width)(IWebBrowser2 *,long *);
 HRESULT (*put_Width)(IWebBrowser2 *,long);
 HRESULT (*get_Height)(IWebBrowser2 *,long *);
 HRESULT (*put_Height)(IWebBrowser2 *,long);
 HRESULT (*get_LocationName)(IWebBrowser2 *,BSTR *);
 HRESULT (*get_LocationURL)(IWebBrowser2 *,BSTR *);
 HRESULT (*get_Busy)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*Quit)(IWebBrowser2 *);
 HRESULT (*ClientToWindow)(IWebBrowser2 *,int *,int *);
 HRESULT (*PutProperty)(IWebBrowser2 *,BSTR,VARIANT);
 HRESULT (*GetProperty)(IWebBrowser2 *,BSTR,VARIANT *);
 HRESULT (*get_Name)(IWebBrowser2 *,BSTR *);
 HRESULT (*get_HWND)(IWebBrowser2 *,SHANDLE_PTR *);
 HRESULT (*get_FullName)(IWebBrowser2 *,BSTR *);
 HRESULT (*get_Path)(IWebBrowser2 *,BSTR *);
 HRESULT (*get_Visible)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_Visible)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_StatusBar)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_StatusBar)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_StatusText)(IWebBrowser2 *,BSTR *);
 HRESULT (*put_StatusText)(IWebBrowser2 *,BSTR);
 HRESULT (*get_ToolBar)(IWebBrowser2 *,int *);
 HRESULT (*put_ToolBar)(IWebBrowser2 *,int);
 HRESULT (*get_MenuBar)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_MenuBar)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_FullScreen)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_FullScreen)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*Navigate2)(IWebBrowser2 *,VARIANT *,VARIANT *,VARIANT *,VARIANT *,VARIANT *);
 HRESULT (*QueryStatusWB)(IWebBrowser2 *,OLECMDID,OLECMDF *);
 HRESULT (*ExecWB)(IWebBrowser2 *,OLECMDID,OLECMDEXECOPT,VARIANT *,VARIANT *);
 HRESULT (*ShowBrowserBar)(IWebBrowser2 *,VARIANT *,VARIANT *,VARIANT *);
 HRESULT (*get_ReadyState)(IWebBrowser2 *,READYSTATE *);
 HRESULT (*get_Offline)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_Offline)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_Silent)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_Silent)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_RegisterAsBrowser)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_RegisterAsBrowser)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_RegisterAsDropTarget)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_RegisterAsDropTarget)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_TheaterMode)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_TheaterMode)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_AddressBar)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_AddressBar)(IWebBrowser2 *,VARIANT_BOOL);
 HRESULT (*get_Resizable)(IWebBrowser2 *,VARIANT_BOOL *);
 HRESULT (*put_Resizable)(IWebBrowser2 *,VARIANT_BOOL);
END_INTERFACE
} IWebBrowser2Vtbl;
interface IWebBrowser2
{
CONST_VTBL struct IWebBrowser2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWebBrowser2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IWebBrowser2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IWebBrowser2_Release(A) (A)->lpVtbl->Release(A)
#define IWebBrowser2_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IWebBrowser2_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IWebBrowser2_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IWebBrowser2_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define IWebBrowser2_GoBack(A) (A)->lpVtbl->GoBack(A)
#define IWebBrowser2_GoForward(A) (A)->lpVtbl->GoForward(A)
#define IWebBrowser2_GoHome(A) (A)->lpVtbl->GoHome(A)
#define IWebBrowser2_GoSearch(A) (A)->lpVtbl->GoSearch(A)
#define IWebBrowser2_Navigate(A,B,C,D,E,F) (A)->lpVtbl->Navigate(A,B,C,D,E,F)
#define IWebBrowser2_Refresh(A) (A)->lpVtbl->Refresh(A)
#define IWebBrowser2_Refresh2(A,B) (A)->lpVtbl->Refresh2(A,B)
#define IWebBrowser2_Stop(A) (A)->lpVtbl->Stop(A)
#define IWebBrowser2_get_Application(A,B) (A)->lpVtbl->get_Application(A,B)
#define IWebBrowser2_get_Parent(A,B) (A)->lpVtbl->get_Parent(A,B)
#define IWebBrowser2_get_Container(A,B) (A)->lpVtbl->get_Container(A,B)
#define IWebBrowser2_get_Document(A,B) (A)->lpVtbl->get_Document(A,B)
#define IWebBrowser2_get_TopLevelContainer(A,B) (A)->lpVtbl->get_TopLevelContainer(A,B)
#define IWebBrowser2_get_Type(A,B) (A)->lpVtbl->get_Type(A,B)
#define IWebBrowser2_get_Left(A,B) (A)->lpVtbl->get_Left(A,B)
#define IWebBrowser2_put_Left(A,B) (A)->lpVtbl->put_Left(A,B)
#define IWebBrowser2_get_Top(A,B) (A)->lpVtbl->get_Top(A,B)
#define IWebBrowser2_put_Top(A,B) (A)->lpVtbl->put_Top(A,B)
#define IWebBrowser2_get_Width(A,B) (A)->lpVtbl->get_Width(A,B)
#define IWebBrowser2_put_Width(A,B) (A)->lpVtbl->put_Width(A,B)
#define IWebBrowser2_get_Height(A,B) (A)->lpVtbl->get_Height(A,B)
#define IWebBrowser2_put_Height(A,B) (A)->lpVtbl->put_Height(A,B)
#define IWebBrowser2_get_LocationName(A,B) (A)->lpVtbl->get_LocationName(A,B)
#define IWebBrowser2_get_LocationURL(A,B) (A)->lpVtbl->get_LocationURL(A,B)
#define IWebBrowser2_get_Busy(A,B) (A)->lpVtbl->get_Busy(A,B)
#define IWebBrowser2_Quit(A) (A)->lpVtbl->Quit(A)
#define IWebBrowser2_ClientToWindow(A,B,C) (A)->lpVtbl->ClientToWindow(A,B,C)
#define IWebBrowser2_PutProperty(A,B,C) (A)->lpVtbl->PutProperty(A,B,C)
#define IWebBrowser2_GetProperty(A,B,C) (A)->lpVtbl->GetProperty(A,B,C)
#define IWebBrowser2_get_Name(A,B) (A)->lpVtbl->get_Name(A,B)
#define IWebBrowser2_get_HWND(A,B) (A)->lpVtbl->get_HWND(A,B)
#define IWebBrowser2_get_FullName(A,B) (A)->lpVtbl->get_FullName(A,B)
#define IWebBrowser2_get_Path(A,B) (A)->lpVtbl->get_Path(A,B)
#define IWebBrowser2_get_Visible(A,B) (A)->lpVtbl->get_Visible(A,B)
#define IWebBrowser2_put_Visible(A,B) (A)->lpVtbl->put_Visible(A,B)
#define IWebBrowser2_get_StatusBar(A,B) (A)->lpVtbl->get_StatusBar(A,B)
#define IWebBrowser2_put_StatusBar(A,B) (A)->lpVtbl->put_StatusBar(A,B)
#define IWebBrowser2_get_StatusText(A,B) (A)->lpVtbl->get_StatusText(A,B)
#define IWebBrowser2_put_StatusText(A,B) (A)->lpVtbl->put_StatusText(A,B)
#define IWebBrowser2_get_ToolBar(A,B) (A)->lpVtbl->get_ToolBar(A,B)
#define IWebBrowser2_put_ToolBar(A,B) (A)->lpVtbl->put_ToolBar(A,B)
#define IWebBrowser2_get_MenuBar(A,B) (A)->lpVtbl->get_MenuBar(A,B)
#define IWebBrowser2_put_MenuBar(A,B) (A)->lpVtbl->put_MenuBar(A,B)
#define IWebBrowser2_get_FullScreen(A,B) (A)->lpVtbl->get_FullScreen(A,B)
#define IWebBrowser2_put_FullScreen(A,B) (A)->lpVtbl->put_FullScreen(A,B)
#define IWebBrowser2_Navigate2(A,B,C,D,E,F) (A)->lpVtbl->Navigate2(A,B,C,D,E,F)
#define IWebBrowser2_QueryStatusWB(A,B,C) (A)->lpVtbl->QueryStatusWB(A,B,C)
#define IWebBrowser2_ExecWB(A,B,C,D,E) (A)->lpVtbl->ExecWB(A,B,C,D,E)
#define IWebBrowser2_ShowBrowserBar(A,B,C,D) (A)->lpVtbl->ShowBrowserBar(A,B,C,D)
#define IWebBrowser2_get_ReadyState(A,B) (A)->lpVtbl->get_ReadyState(A,B)
#define IWebBrowser2_get_Offline(A,B) (A)->lpVtbl->get_Offline(A,B)
#define IWebBrowser2_put_Offline(A,B) (A)->lpVtbl->put_Offline(A,B)
#define IWebBrowser2_get_Silent(A,B) (A)->lpVtbl->get_Silent(A,B)
#define IWebBrowser2_put_Silent(A,B) (A)->lpVtbl->put_Silent(A,B)
#define IWebBrowser2_get_RegisterAsBrowser(A,B) (A)->lpVtbl->get_RegisterAsBrowser(A,B)
#define IWebBrowser2_put_RegisterAsBrowser(A,B) (A)->lpVtbl->put_RegisterAsBrowser(A,B)
#define IWebBrowser2_get_RegisterAsDropTarget(A,B) (A)->lpVtbl->get_RegisterAsDropTarget(A,B)
#define IWebBrowser2_put_RegisterAsDropTarget(A,B) (A)->lpVtbl->put_RegisterAsDropTarget(A,B)
#define IWebBrowser2_get_TheaterMode(A,B) (A)->lpVtbl->get_TheaterMode(A,B)
#define IWebBrowser2_put_TheaterMode(A,B) (A)->lpVtbl->put_TheaterMode(A,B)
#define IWebBrowser2_get_AddressBar(A,B) (A)->lpVtbl->get_AddressBar(A,B)
#define IWebBrowser2_put_AddressBar(A,B) (A)->lpVtbl->put_AddressBar(A,B)
#define IWebBrowser2_get_Resizable(A,B) (A)->lpVtbl->get_Resizable(A,B)
#define IWebBrowser2_put_Resizable(A,B) (A)->lpVtbl->put_Resizable(A,B)
#endif 
HRESULT IWebBrowser2_Navigate2_Proxy(IWebBrowser2 *,VARIANT *,VARIANT *,VARIANT *,VARIANT *,VARIANT *);
void IWebBrowser2_Navigate2_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_QueryStatusWB_Proxy(IWebBrowser2 *,OLECMDID ,OLECMDF *);
void IWebBrowser2_QueryStatusWB_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_ExecWB_Proxy(IWebBrowser2 *,OLECMDID ,OLECMDEXECOPT ,VARIANT *,VARIANT *);
void IWebBrowser2_ExecWB_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_ShowBrowserBar_Proxy(IWebBrowser2 *,VARIANT *,VARIANT *,VARIANT *);
void IWebBrowser2_ShowBrowserBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_get_ReadyState_Proxy(IWebBrowser2 *,READYSTATE *);
void IWebBrowser2_get_ReadyState_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_get_Offline_Proxy(IWebBrowser2 *,VARIANT_BOOL *);
void IWebBrowser2_get_Offline_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_put_Offline_Proxy(IWebBrowser2 *,VARIANT_BOOL );
void IWebBrowser2_put_Offline_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_get_Silent_Proxy(IWebBrowser2 *,VARIANT_BOOL *);
void IWebBrowser2_get_Silent_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_put_Silent_Proxy(IWebBrowser2 *,VARIANT_BOOL );
void IWebBrowser2_put_Silent_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_get_RegisterAsBrowser_Proxy(IWebBrowser2 *,VARIANT_BOOL *);
void IWebBrowser2_get_RegisterAsBrowser_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_put_RegisterAsBrowser_Proxy(IWebBrowser2 *,VARIANT_BOOL );
void IWebBrowser2_put_RegisterAsBrowser_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_get_RegisterAsDropTarget_Proxy(IWebBrowser2 *,VARIANT_BOOL *);
void IWebBrowser2_get_RegisterAsDropTarget_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_put_RegisterAsDropTarget_Proxy(IWebBrowser2 *,VARIANT_BOOL );
void IWebBrowser2_put_RegisterAsDropTarget_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_get_TheaterMode_Proxy(IWebBrowser2 *,VARIANT_BOOL *);
void IWebBrowser2_get_TheaterMode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_put_TheaterMode_Proxy(IWebBrowser2 *,VARIANT_BOOL );
void IWebBrowser2_put_TheaterMode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_get_AddressBar_Proxy(IWebBrowser2 *,VARIANT_BOOL *);
void IWebBrowser2_get_AddressBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_put_AddressBar_Proxy(IWebBrowser2 *,VARIANT_BOOL );
void IWebBrowser2_put_AddressBar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_get_Resizable_Proxy(IWebBrowser2 *,VARIANT_BOOL *);
void IWebBrowser2_get_Resizable_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IWebBrowser2_put_Resizable_Proxy(IWebBrowser2 *,VARIANT_BOOL );
void IWebBrowser2_put_Resizable_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __DWebBrowserEvents2_DISPINTERFACE_DEFINED__
#define __DWebBrowserEvents2_DISPINTERFACE_DEFINED__
EXTERN_C const IID DIID_DWebBrowserEvents2;
typedef struct DWebBrowserEvents2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(DWebBrowserEvents2 *,REFIID,void **);
 ULONG (*AddRef)(DWebBrowserEvents2 *);
 ULONG (*Release)(DWebBrowserEvents2 *);
 HRESULT (*GetTypeInfoCount)(DWebBrowserEvents2 *,UINT *);
 HRESULT (*GetTypeInfo)(DWebBrowserEvents2 *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(DWebBrowserEvents2 *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(DWebBrowserEvents2 *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
END_INTERFACE
} DWebBrowserEvents2Vtbl;
interface DWebBrowserEvents2
{
CONST_VTBL struct DWebBrowserEvents2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define DWebBrowserEvents2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define DWebBrowserEvents2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define DWebBrowserEvents2_Release(A) (A)->lpVtbl->Release(A)
#define DWebBrowserEvents2_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define DWebBrowserEvents2_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define DWebBrowserEvents2_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define DWebBrowserEvents2_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#endif 
#endif 
EXTERN_C const CLSID CLSID_WebBrowser_V1;
EXTERN_C const CLSID CLSID_WebBrowser;
EXTERN_C const CLSID CLSID_InternetExplorer;
EXTERN_C const CLSID CLSID_ShellBrowserWindow;
#ifndef __DShellWindowsEvents_DISPINTERFACE_DEFINED__
#define __DShellWindowsEvents_DISPINTERFACE_DEFINED__
EXTERN_C const IID DIID_DShellWindowsEvents;
typedef struct DShellWindowsEventsVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(DShellWindowsEvents *,REFIID,void **);
 ULONG (*AddRef)(DShellWindowsEvents *);
 ULONG (*Release)(DShellWindowsEvents *);
 HRESULT (*GetTypeInfoCount)(DShellWindowsEvents *,UINT *);
 HRESULT (*GetTypeInfo)(DShellWindowsEvents *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(DShellWindowsEvents *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(DShellWindowsEvents *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
END_INTERFACE
} DShellWindowsEventsVtbl;
interface DShellWindowsEvents
{
CONST_VTBL struct DShellWindowsEventsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define DShellWindowsEvents_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define DShellWindowsEvents_AddRef(A) (A)->lpVtbl->AddRef(A)
#define DShellWindowsEvents_Release(A) (A)->lpVtbl->Release(A)
#define DShellWindowsEvents_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define DShellWindowsEvents_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define DShellWindowsEvents_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define DShellWindowsEvents_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#endif 
#endif 
#ifndef __IShellWindows_INTERFACE_DEFINED__
#define __IShellWindows_INTERFACE_DEFINED__
EXTERN_C const IID IID_IShellWindows;
typedef struct IShellWindowsVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IShellWindows *,REFIID,void **);
 ULONG (*AddRef)(IShellWindows *);
 ULONG (*Release)(IShellWindows *);
 HRESULT (*GetTypeInfoCount)(IShellWindows *,UINT *);
 HRESULT (*GetTypeInfo)(IShellWindows *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IShellWindows *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IShellWindows *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*get_Count)(IShellWindows *,long *);
 HRESULT (*Item)(IShellWindows *,VARIANT,IDispatch **);
 HRESULT (*_NewEnum)(IShellWindows *,IUnknown **);
 HRESULT (*Register)(IShellWindows *,IDispatch *,long,int,long *);
 HRESULT (*RegisterPending)(IShellWindows *,long,VARIANT *,VARIANT *,int,long *);
 HRESULT (*Revoke)(IShellWindows *,long);
 HRESULT (*OnNavigate)(IShellWindows *,long,VARIANT *);
 HRESULT (*OnActivated)(IShellWindows *,long,VARIANT_BOOL);
 HRESULT (*FindWindowSW)(IShellWindows *,VARIANT *,VARIANT *,int,long *,int,IDispatch **);
 HRESULT (*OnCreated)(IShellWindows *,long,IUnknown *);
 HRESULT (*ProcessAttachDetach)(IShellWindows *,VARIANT_BOOL);
END_INTERFACE
} IShellWindowsVtbl;
interface IShellWindows
{
CONST_VTBL struct IShellWindowsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IShellWindows_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IShellWindows_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IShellWindows_Release(A) (A)->lpVtbl->Release(A)
#define IShellWindows_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IShellWindows_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IShellWindows_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IShellWindows_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define IShellWindows_get_Count(A,B) (A)->lpVtbl->get_Count(A,B)
#define IShellWindows_Item(A,B,C) (A)->lpVtbl->Item(A,B,C)
#define IShellWindows__NewEnum(A,B) (A)->lpVtbl->_NewEnum(A,B)
#define IShellWindows_Register(A,B,C,D,E) (A)->lpVtbl->Register(A,B,C,D,E)
#define IShellWindows_RegisterPending(A,B,C,D,E,F) (A)->lpVtbl->RegisterPending(A,B,C,D,E,F)
#define IShellWindows_Revoke(A,B) (A)->lpVtbl->Revoke(A,B)
#define IShellWindows_OnNavigate(A,B,C) (A)->lpVtbl->OnNavigate(A,B,C)
#define IShellWindows_OnActivated(A,B,C) (A)->lpVtbl->OnActivated(A,B,C)
#define IShellWindows_FindWindowSW(A,B,C,D,E,F,G) (A)->lpVtbl->FindWindowSW(A,B,C,D,E,F,G)
#define IShellWindows_OnCreated(A,B,C) (A)->lpVtbl->OnCreated(A,B,C)
#define IShellWindows_ProcessAttachDetach(A,B) (A)->lpVtbl->ProcessAttachDetach(A,B)
#endif 
HRESULT IShellWindows_get_Count_Proxy(IShellWindows *,long *);
void IShellWindows_get_Count_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_Item_Proxy(IShellWindows *,VARIANT ,IDispatch **);
void IShellWindows_Item_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows__NewEnum_Proxy(IShellWindows *,IUnknown **);
void IShellWindows__NewEnum_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_Register_Proxy(IShellWindows *,IDispatch *,long ,int ,long *);
void IShellWindows_Register_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_RegisterPending_Proxy(IShellWindows *,long ,VARIANT *,VARIANT *,int ,long *);
void IShellWindows_RegisterPending_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_Revoke_Proxy(IShellWindows *,long );
void IShellWindows_Revoke_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_OnNavigate_Proxy(IShellWindows *,long ,VARIANT *);
void IShellWindows_OnNavigate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_OnActivated_Proxy(IShellWindows *,long ,VARIANT_BOOL );
void IShellWindows_OnActivated_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_FindWindowSW_Proxy(IShellWindows *,VARIANT *,VARIANT *,int ,long *,int ,IDispatch **);
void IShellWindows_FindWindowSW_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_OnCreated_Proxy(IShellWindows *,long ,IUnknown *);
void IShellWindows_OnCreated_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellWindows_ProcessAttachDetach_Proxy(IShellWindows *,VARIANT_BOOL );
void IShellWindows_ProcessAttachDetach_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
EXTERN_C const CLSID CLSID_ShellWindows;
#ifndef __IShellUIHelper_INTERFACE_DEFINED__
#define __IShellUIHelper_INTERFACE_DEFINED__
EXTERN_C const IID IID_IShellUIHelper;
typedef struct IShellUIHelperVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IShellUIHelper *,REFIID,void **);
 ULONG (*AddRef)(IShellUIHelper *);
 ULONG (*Release)(IShellUIHelper *);
 HRESULT (*GetTypeInfoCount)(IShellUIHelper *,UINT *);
 HRESULT (*GetTypeInfo)(IShellUIHelper *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IShellUIHelper *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IShellUIHelper *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*ResetFirstBootMode)(IShellUIHelper *);
 HRESULT (*ResetSafeMode)(IShellUIHelper *);
 HRESULT (*RefreshOfflineDesktop)(IShellUIHelper *);
 HRESULT (*AddFavorite)(IShellUIHelper *,BSTR,VARIANT *);
 HRESULT (*AddChannel)(IShellUIHelper *,BSTR);
 HRESULT (*AddDesktopComponent)(IShellUIHelper *,BSTR,BSTR,VARIANT *,VARIANT *,VARIANT *,VARIANT *);
 HRESULT (*IsSubscribed)(IShellUIHelper *,BSTR,VARIANT_BOOL *);
 HRESULT (*NavigateAndFind)(IShellUIHelper *,BSTR,BSTR,VARIANT *);
 HRESULT (*ImportExportFavorites)(IShellUIHelper *,VARIANT_BOOL,BSTR);
 HRESULT (*AutoCompleteSaveForm)(IShellUIHelper *,VARIANT *);
 HRESULT (*AutoScan)(IShellUIHelper *,BSTR,BSTR,VARIANT *);
 HRESULT (*AutoCompleteAttach)(IShellUIHelper *,VARIANT *);
 HRESULT (*ShowBrowserUI)(IShellUIHelper *,BSTR,VARIANT *,VARIANT *);
END_INTERFACE
} IShellUIHelperVtbl;
interface IShellUIHelper
{
CONST_VTBL struct IShellUIHelperVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IShellUIHelper_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IShellUIHelper_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IShellUIHelper_Release(A) (A)->lpVtbl->Release(A)
#define IShellUIHelper_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IShellUIHelper_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IShellUIHelper_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IShellUIHelper_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define IShellUIHelper_ResetFirstBootMode(A) (A)->lpVtbl->ResetFirstBootMode(A)
#define IShellUIHelper_ResetSafeMode(A) (A)->lpVtbl->ResetSafeMode(A)
#define IShellUIHelper_RefreshOfflineDesktop(A) (A)->lpVtbl->RefreshOfflineDesktop(A)
#define IShellUIHelper_AddFavorite(A,B,C) (A)->lpVtbl->AddFavorite(A,B,C)
#define IShellUIHelper_AddChannel(A,B) (A)->lpVtbl->AddChannel(A,B)
#define IShellUIHelper_AddDesktopComponent(A,B,C,D,E,F,G) (A)->lpVtbl->AddDesktopComponent(A,B,C,D,E,F,G)
#define IShellUIHelper_IsSubscribed(A,B,C) (A)->lpVtbl->IsSubscribed(A,B,C)
#define IShellUIHelper_NavigateAndFind(A,B,C,D) (A)->lpVtbl->NavigateAndFind(A,B,C,D)
#define IShellUIHelper_ImportExportFavorites(A,B,C) (A)->lpVtbl->ImportExportFavorites(A,B,C)
#define IShellUIHelper_AutoCompleteSaveForm(A,B) (A)->lpVtbl->AutoCompleteSaveForm(A,B)
#define IShellUIHelper_AutoScan(A,B,C,D) (A)->lpVtbl->AutoScan(A,B,C,D)
#define IShellUIHelper_AutoCompleteAttach(A,B) (A)->lpVtbl->AutoCompleteAttach(A,B)
#define IShellUIHelper_ShowBrowserUI(A,B,C,D) (A)->lpVtbl->ShowBrowserUI(A,B,C,D)
#endif 
HRESULT IShellUIHelper_ResetFirstBootMode_Proxy(IShellUIHelper *);
void IShellUIHelper_ResetFirstBootMode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_ResetSafeMode_Proxy(IShellUIHelper *);
void IShellUIHelper_ResetSafeMode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_RefreshOfflineDesktop_Proxy(IShellUIHelper *);
void IShellUIHelper_RefreshOfflineDesktop_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_AddFavorite_Proxy(IShellUIHelper *,BSTR ,VARIANT *);
void IShellUIHelper_AddFavorite_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_AddChannel_Proxy(IShellUIHelper *,BSTR );
void IShellUIHelper_AddChannel_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_AddDesktopComponent_Proxy(IShellUIHelper *,BSTR ,BSTR ,VARIANT *,VARIANT *,VARIANT *,VARIANT *);
void IShellUIHelper_AddDesktopComponent_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_IsSubscribed_Proxy(IShellUIHelper *,BSTR ,VARIANT_BOOL *);
void IShellUIHelper_IsSubscribed_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_NavigateAndFind_Proxy(IShellUIHelper *,BSTR ,BSTR ,VARIANT *);
void IShellUIHelper_NavigateAndFind_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_ImportExportFavorites_Proxy(IShellUIHelper *,VARIANT_BOOL ,BSTR );
void IShellUIHelper_ImportExportFavorites_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_AutoCompleteSaveForm_Proxy(IShellUIHelper *,VARIANT *);
void IShellUIHelper_AutoCompleteSaveForm_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_AutoScan_Proxy(IShellUIHelper *,BSTR ,BSTR ,VARIANT *);
void IShellUIHelper_AutoScan_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_AutoCompleteAttach_Proxy(IShellUIHelper *,VARIANT *);
void IShellUIHelper_AutoCompleteAttach_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellUIHelper_ShowBrowserUI_Proxy(IShellUIHelper *,BSTR ,VARIANT *,VARIANT *);
void IShellUIHelper_ShowBrowserUI_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
EXTERN_C const CLSID CLSID_ShellUIHelper;
#ifndef __DShellNameSpaceEvents_DISPINTERFACE_DEFINED__
#define __DShellNameSpaceEvents_DISPINTERFACE_DEFINED__
EXTERN_C const IID DIID_DShellNameSpaceEvents;
typedef struct DShellNameSpaceEventsVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(DShellNameSpaceEvents *,REFIID,void **);
 ULONG (*AddRef)(DShellNameSpaceEvents *);
 ULONG (*Release)(DShellNameSpaceEvents *);
 HRESULT (*GetTypeInfoCount)(DShellNameSpaceEvents *,UINT *);
 HRESULT (*GetTypeInfo)(DShellNameSpaceEvents *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(DShellNameSpaceEvents *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(DShellNameSpaceEvents *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
END_INTERFACE
} DShellNameSpaceEventsVtbl;
interface DShellNameSpaceEvents
{
CONST_VTBL struct DShellNameSpaceEventsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define DShellNameSpaceEvents_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define DShellNameSpaceEvents_AddRef(A) (A)->lpVtbl->AddRef(A)
#define DShellNameSpaceEvents_Release(A) (A)->lpVtbl->Release(A)
#define DShellNameSpaceEvents_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define DShellNameSpaceEvents_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define DShellNameSpaceEvents_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define DShellNameSpaceEvents_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#endif 
#endif 
#ifndef __IShellFavoritesNameSpace_INTERFACE_DEFINED__
#define __IShellFavoritesNameSpace_INTERFACE_DEFINED__
EXTERN_C const IID IID_IShellFavoritesNameSpace;
typedef struct IShellFavoritesNameSpaceVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IShellFavoritesNameSpace *,REFIID,void **);
 ULONG (*AddRef)(IShellFavoritesNameSpace *);
 ULONG (*Release)(IShellFavoritesNameSpace *);
 HRESULT (*GetTypeInfoCount)(IShellFavoritesNameSpace *,UINT *);
 HRESULT (*GetTypeInfo)(IShellFavoritesNameSpace *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IShellFavoritesNameSpace *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IShellFavoritesNameSpace *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*MoveSelectionUp)(IShellFavoritesNameSpace *);
 HRESULT (*MoveSelectionDown)(IShellFavoritesNameSpace *);
 HRESULT (*ResetSort)(IShellFavoritesNameSpace *);
 HRESULT (*NewFolder)(IShellFavoritesNameSpace *);
 HRESULT (*Synchronize)(IShellFavoritesNameSpace *);
 HRESULT (*Import)(IShellFavoritesNameSpace *);
 HRESULT (*Export)(IShellFavoritesNameSpace *);
 HRESULT (*InvokeContextMenuCommand)(IShellFavoritesNameSpace *,BSTR);
 HRESULT (*MoveSelectionTo)(IShellFavoritesNameSpace *);
 HRESULT (*get_SubscriptionsEnabled)(IShellFavoritesNameSpace *,VARIANT_BOOL *);
 HRESULT (*CreateSubscriptionForSelection)(IShellFavoritesNameSpace *,VARIANT_BOOL *);
 HRESULT (*DeleteSubscriptionForSelection)(IShellFavoritesNameSpace *,VARIANT_BOOL *);
 HRESULT (*SetRoot)(IShellFavoritesNameSpace *,BSTR);
END_INTERFACE
} IShellFavoritesNameSpaceVtbl;
interface IShellFavoritesNameSpace
{
CONST_VTBL struct IShellFavoritesNameSpaceVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IShellFavoritesNameSpace_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IShellFavoritesNameSpace_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IShellFavoritesNameSpace_Release(A) (A)->lpVtbl->Release(A)
#define IShellFavoritesNameSpace_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IShellFavoritesNameSpace_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IShellFavoritesNameSpace_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IShellFavoritesNameSpace_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define IShellFavoritesNameSpace_MoveSelectionUp(A) (A)->lpVtbl->MoveSelectionUp(A)
#define IShellFavoritesNameSpace_MoveSelectionDown(A) (A)->lpVtbl->MoveSelectionDown(A)
#define IShellFavoritesNameSpace_ResetSort(A) (A)->lpVtbl->ResetSort(A)
#define IShellFavoritesNameSpace_NewFolder(A) (A)->lpVtbl->NewFolder(A)
#define IShellFavoritesNameSpace_Synchronize(A) (A)->lpVtbl->Synchronize(A)
#define IShellFavoritesNameSpace_Import(A) (A)->lpVtbl->Import(A)
#define IShellFavoritesNameSpace_Export(A) (A)->lpVtbl->Export(A)
#define IShellFavoritesNameSpace_InvokeContextMenuCommand(A,B) (A)->lpVtbl->InvokeContextMenuCommand(A,B)
#define IShellFavoritesNameSpace_MoveSelectionTo(A) (A)->lpVtbl->MoveSelectionTo(A)
#define IShellFavoritesNameSpace_get_SubscriptionsEnabled(A,B) (A)->lpVtbl->get_SubscriptionsEnabled(A,B)
#define IShellFavoritesNameSpace_CreateSubscriptionForSelection(A,B) (A)->lpVtbl->CreateSubscriptionForSelection(A,B)
#define IShellFavoritesNameSpace_DeleteSubscriptionForSelection(A,B) (A)->lpVtbl->DeleteSubscriptionForSelection(A,B)
#define IShellFavoritesNameSpace_SetRoot(A,B) (A)->lpVtbl->SetRoot(A,B)
#endif 
HRESULT IShellFavoritesNameSpace_MoveSelectionUp_Proxy(IShellFavoritesNameSpace *);
void IShellFavoritesNameSpace_MoveSelectionUp_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_MoveSelectionDown_Proxy(IShellFavoritesNameSpace *);
void IShellFavoritesNameSpace_MoveSelectionDown_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_ResetSort_Proxy(IShellFavoritesNameSpace *);
void IShellFavoritesNameSpace_ResetSort_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_NewFolder_Proxy(IShellFavoritesNameSpace *);
void IShellFavoritesNameSpace_NewFolder_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_Synchronize_Proxy(IShellFavoritesNameSpace *);
void IShellFavoritesNameSpace_Synchronize_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_Import_Proxy(IShellFavoritesNameSpace *);
void IShellFavoritesNameSpace_Import_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_Export_Proxy(IShellFavoritesNameSpace *);
void IShellFavoritesNameSpace_Export_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_InvokeContextMenuCommand_Proxy(IShellFavoritesNameSpace *,BSTR );
void IShellFavoritesNameSpace_InvokeContextMenuCommand_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_MoveSelectionTo_Proxy(IShellFavoritesNameSpace *);
void IShellFavoritesNameSpace_MoveSelectionTo_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_get_SubscriptionsEnabled_Proxy(IShellFavoritesNameSpace *,VARIANT_BOOL *);
void IShellFavoritesNameSpace_get_SubscriptionsEnabled_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_CreateSubscriptionForSelection_Proxy(IShellFavoritesNameSpace *,VARIANT_BOOL *);
void IShellFavoritesNameSpace_CreateSubscriptionForSelection_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_DeleteSubscriptionForSelection_Proxy(IShellFavoritesNameSpace *,VARIANT_BOOL *);
void IShellFavoritesNameSpace_DeleteSubscriptionForSelection_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellFavoritesNameSpace_SetRoot_Proxy(IShellFavoritesNameSpace *,BSTR );
void IShellFavoritesNameSpace_SetRoot_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __IShellNameSpace_INTERFACE_DEFINED__
#define __IShellNameSpace_INTERFACE_DEFINED__
EXTERN_C const IID IID_IShellNameSpace;
typedef struct IShellNameSpaceVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IShellNameSpace *,REFIID,void **);
 ULONG (*AddRef)(IShellNameSpace *);
 ULONG (*Release)(IShellNameSpace *);
 HRESULT (*GetTypeInfoCount)(IShellNameSpace *,UINT *);
 HRESULT (*GetTypeInfo)(IShellNameSpace *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IShellNameSpace *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IShellNameSpace *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*MoveSelectionUp)(IShellNameSpace *);
 HRESULT (*MoveSelectionDown)(IShellNameSpace *);
 HRESULT (*ResetSort)(IShellNameSpace *);
 HRESULT (*NewFolder)(IShellNameSpace *);
 HRESULT (*Synchronize)(IShellNameSpace *);
 HRESULT (*Import)(IShellNameSpace *);
 HRESULT (*Export)(IShellNameSpace *);
 HRESULT (*InvokeContextMenuCommand)(IShellNameSpace *,BSTR);
 HRESULT (*MoveSelectionTo)(IShellNameSpace *);
 HRESULT (*get_SubscriptionsEnabled)(IShellNameSpace *,VARIANT_BOOL *);
 HRESULT (*CreateSubscriptionForSelection)(IShellNameSpace *,VARIANT_BOOL *);
 HRESULT (*DeleteSubscriptionForSelection)(IShellNameSpace *,VARIANT_BOOL *);
 HRESULT (*SetRoot)(IShellNameSpace *,BSTR);
 HRESULT (*get_EnumOptions)(IShellNameSpace *,LONG *);
 HRESULT (*put_EnumOptions)(IShellNameSpace *,LONG);
 HRESULT (*get_SelectedItem)(IShellNameSpace *,IDispatch **);
 HRESULT (*put_SelectedItem)(IShellNameSpace *,IDispatch *);
 HRESULT (*get_Root)(IShellNameSpace *,VARIANT *);
 HRESULT (*put_Root)(IShellNameSpace *,VARIANT);
 HRESULT (*get_Depth)(IShellNameSpace *,int *);
 HRESULT (*put_Depth)(IShellNameSpace *,int);
 HRESULT (*get_Mode)(IShellNameSpace *,UINT *);
 HRESULT (*put_Mode)(IShellNameSpace *,UINT);
 HRESULT (*get_Flags)(IShellNameSpace *,DWORD *);
 HRESULT (*put_Flags)(IShellNameSpace *,DWORD);
 HRESULT (*put_TVFlags)(IShellNameSpace *,DWORD);
 HRESULT (*get_TVFlags)(IShellNameSpace *,DWORD *);
 HRESULT (*get_Columns)(IShellNameSpace *,BSTR *);
 HRESULT (*put_Columns)(IShellNameSpace *,BSTR);
 HRESULT (*get_CountViewTypes)(IShellNameSpace *,int *);
 HRESULT (*SetViewType)(IShellNameSpace *,int);
 HRESULT (*SelectedItems)(IShellNameSpace *,IDispatch **);
 HRESULT (*Expand)(IShellNameSpace *,VARIANT,int);
 HRESULT (*UnselectAll)(IShellNameSpace *);
END_INTERFACE
} IShellNameSpaceVtbl;
interface IShellNameSpace
{
CONST_VTBL struct IShellNameSpaceVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IShellNameSpace_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IShellNameSpace_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IShellNameSpace_Release(A) (A)->lpVtbl->Release(A)
#define IShellNameSpace_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IShellNameSpace_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IShellNameSpace_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IShellNameSpace_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define IShellNameSpace_MoveSelectionUp(A) (A)->lpVtbl->MoveSelectionUp(A)
#define IShellNameSpace_MoveSelectionDown(A) (A)->lpVtbl->MoveSelectionDown(A)
#define IShellNameSpace_ResetSort(A) (A)->lpVtbl->ResetSort(A)
#define IShellNameSpace_NewFolder(A) (A)->lpVtbl->NewFolder(A)
#define IShellNameSpace_Synchronize(A) (A)->lpVtbl->Synchronize(A)
#define IShellNameSpace_Import(A) (A)->lpVtbl->Import(A)
#define IShellNameSpace_Export(A) (A)->lpVtbl->Export(A)
#define IShellNameSpace_InvokeContextMenuCommand(A,B) (A)->lpVtbl->InvokeContextMenuCommand(A,B)
#define IShellNameSpace_MoveSelectionTo(A) (A)->lpVtbl->MoveSelectionTo(A)
#define IShellNameSpace_get_SubscriptionsEnabled(A,B) (A)->lpVtbl->get_SubscriptionsEnabled(A,B)
#define IShellNameSpace_CreateSubscriptionForSelection(A,B) (A)->lpVtbl->CreateSubscriptionForSelection(A,B)
#define IShellNameSpace_DeleteSubscriptionForSelection(A,B) (A)->lpVtbl->DeleteSubscriptionForSelection(A,B)
#define IShellNameSpace_SetRoot(A,B) (A)->lpVtbl->SetRoot(A,B)
#define IShellNameSpace_get_EnumOptions(A,B) (A)->lpVtbl->get_EnumOptions(A,B)
#define IShellNameSpace_put_EnumOptions(A,B) (A)->lpVtbl->put_EnumOptions(A,B)
#define IShellNameSpace_get_SelectedItem(A,B) (A)->lpVtbl->get_SelectedItem(A,B)
#define IShellNameSpace_put_SelectedItem(A,B) (A)->lpVtbl->put_SelectedItem(A,B)
#define IShellNameSpace_get_Root(A,B) (A)->lpVtbl->get_Root(A,B)
#define IShellNameSpace_put_Root(A,B) (A)->lpVtbl->put_Root(A,B)
#define IShellNameSpace_get_Depth(A,B) (A)->lpVtbl->get_Depth(A,B)
#define IShellNameSpace_put_Depth(A,B) (A)->lpVtbl->put_Depth(A,B)
#define IShellNameSpace_get_Mode(A,B) (A)->lpVtbl->get_Mode(A,B)
#define IShellNameSpace_put_Mode(A,B) (A)->lpVtbl->put_Mode(A,B)
#define IShellNameSpace_get_Flags(A,B) (A)->lpVtbl->get_Flags(A,B)
#define IShellNameSpace_put_Flags(A,B) (A)->lpVtbl->put_Flags(A,B)
#define IShellNameSpace_put_TVFlags(A,B) (A)->lpVtbl->put_TVFlags(A,B)
#define IShellNameSpace_get_TVFlags(A,B) (A)->lpVtbl->get_TVFlags(A,B)
#define IShellNameSpace_get_Columns(A,B) (A)->lpVtbl->get_Columns(A,B)
#define IShellNameSpace_put_Columns(A,B) (A)->lpVtbl->put_Columns(A,B)
#define IShellNameSpace_get_CountViewTypes(A,B) (A)->lpVtbl->get_CountViewTypes(A,B)
#define IShellNameSpace_SetViewType(A,B) (A)->lpVtbl->SetViewType(A,B)
#define IShellNameSpace_SelectedItems(A,B) (A)->lpVtbl->SelectedItems(A,B)
#define IShellNameSpace_Expand(A,B,C) (A)->lpVtbl->Expand(A,B,C)
#define IShellNameSpace_UnselectAll(A) (A)->lpVtbl->UnselectAll(A)
#endif 
HRESULT IShellNameSpace_get_EnumOptions_Proxy(IShellNameSpace *,LONG *);
void IShellNameSpace_get_EnumOptions_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_put_EnumOptions_Proxy(IShellNameSpace *,LONG );
void IShellNameSpace_put_EnumOptions_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_get_SelectedItem_Proxy(IShellNameSpace *,IDispatch **);
void IShellNameSpace_get_SelectedItem_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_put_SelectedItem_Proxy(IShellNameSpace *,IDispatch *);
void IShellNameSpace_put_SelectedItem_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_get_Root_Proxy(IShellNameSpace *,VARIANT *);
void IShellNameSpace_get_Root_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_put_Root_Proxy(IShellNameSpace *,VARIANT );
void IShellNameSpace_put_Root_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_get_Depth_Proxy(IShellNameSpace *,int *);
void IShellNameSpace_get_Depth_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_put_Depth_Proxy(IShellNameSpace *,int );
void IShellNameSpace_put_Depth_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_get_Mode_Proxy(IShellNameSpace *,UINT *);
void IShellNameSpace_get_Mode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_put_Mode_Proxy(IShellNameSpace *,UINT );
void IShellNameSpace_put_Mode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_get_Flags_Proxy(IShellNameSpace *,DWORD *);
void IShellNameSpace_get_Flags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_put_Flags_Proxy(IShellNameSpace *,DWORD );
void IShellNameSpace_put_Flags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_put_TVFlags_Proxy(IShellNameSpace *,DWORD );
void IShellNameSpace_put_TVFlags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_get_TVFlags_Proxy(IShellNameSpace *,DWORD *);
void IShellNameSpace_get_TVFlags_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_get_Columns_Proxy(IShellNameSpace *,BSTR *);
void IShellNameSpace_get_Columns_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_put_Columns_Proxy(IShellNameSpace *,BSTR );
void IShellNameSpace_put_Columns_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_get_CountViewTypes_Proxy(IShellNameSpace *,int *);
void IShellNameSpace_get_CountViewTypes_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_SetViewType_Proxy(IShellNameSpace *,int );
void IShellNameSpace_SetViewType_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_SelectedItems_Proxy(IShellNameSpace *,IDispatch **);
void IShellNameSpace_SelectedItems_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_Expand_Proxy(IShellNameSpace *,VARIANT ,int );
void IShellNameSpace_Expand_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IShellNameSpace_UnselectAll_Proxy(IShellNameSpace *);
void IShellNameSpace_UnselectAll_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
EXTERN_C const CLSID CLSID_ShellNameSpace;
#ifndef __IScriptErrorList_INTERFACE_DEFINED__
#define __IScriptErrorList_INTERFACE_DEFINED__
EXTERN_C const IID IID_IScriptErrorList;
typedef struct IScriptErrorListVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(IScriptErrorList *,REFIID,void **);
 ULONG (*AddRef)(IScriptErrorList *);
 ULONG (*Release)(IScriptErrorList *);
 HRESULT (*GetTypeInfoCount)(IScriptErrorList *,UINT *);
 HRESULT (*GetTypeInfo)(IScriptErrorList *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(IScriptErrorList *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(IScriptErrorList *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*advanceError)(IScriptErrorList *);
 HRESULT (*retreatError)(IScriptErrorList *);
 HRESULT (*canAdvanceError)(IScriptErrorList *,BOOL *);
 HRESULT (*canRetreatError)(IScriptErrorList *,BOOL *);
 HRESULT (*getErrorLine)(IScriptErrorList *,LONG *);
 HRESULT (*getErrorChar)(IScriptErrorList *,LONG *);
 HRESULT (*getErrorCode)(IScriptErrorList *,LONG *);
 HRESULT (*getErrorMsg)(IScriptErrorList *,BSTR *);
 HRESULT (*getErrorUrl)(IScriptErrorList *,BSTR *);
 HRESULT (*getAlwaysShowLockState)(IScriptErrorList *,BOOL *);
 HRESULT (*getDetailsPaneOpen)(IScriptErrorList *,BOOL *);
 HRESULT (*setDetailsPaneOpen)(IScriptErrorList *,BOOL);
 HRESULT (*getPerErrorDisplay)(IScriptErrorList *,BOOL *);
 HRESULT (*setPerErrorDisplay)(IScriptErrorList *,BOOL);
END_INTERFACE
} IScriptErrorListVtbl;
interface IScriptErrorList
{
CONST_VTBL struct IScriptErrorListVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IScriptErrorList_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define IScriptErrorList_AddRef(A) (A)->lpVtbl->AddRef(A)
#define IScriptErrorList_Release(A) (A)->lpVtbl->Release(A)
#define IScriptErrorList_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define IScriptErrorList_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define IScriptErrorList_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define IScriptErrorList_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define IScriptErrorList_advanceError(A) (A)->lpVtbl->advanceError(A)
#define IScriptErrorList_retreatError(A) (A)->lpVtbl->retreatError(A)
#define IScriptErrorList_canAdvanceError(A,B) (A)->lpVtbl->canAdvanceError(A,B)
#define IScriptErrorList_canRetreatError(A,B) (A)->lpVtbl->canRetreatError(A,B)
#define IScriptErrorList_getErrorLine(A,B) (A)->lpVtbl->getErrorLine(A,B)
#define IScriptErrorList_getErrorChar(A,B) (A)->lpVtbl->getErrorChar(A,B)
#define IScriptErrorList_getErrorCode(A,B) (A)->lpVtbl->getErrorCode(A,B)
#define IScriptErrorList_getErrorMsg(A,B) (A)->lpVtbl->getErrorMsg(A,B)
#define IScriptErrorList_getErrorUrl(A,B) (A)->lpVtbl->getErrorUrl(A,B)
#define IScriptErrorList_getAlwaysShowLockState(A,B) (A)->lpVtbl->getAlwaysShowLockState(A,B)
#define IScriptErrorList_getDetailsPaneOpen(A,B) (A)->lpVtbl->getDetailsPaneOpen(A,B)
#define IScriptErrorList_setDetailsPaneOpen(A,B) (A)->lpVtbl->setDetailsPaneOpen(A,B)
#define IScriptErrorList_getPerErrorDisplay(A,B) (A)->lpVtbl->getPerErrorDisplay(A,B)
#define IScriptErrorList_setPerErrorDisplay(A,B) (A)->lpVtbl->setPerErrorDisplay(A,B)
#endif 
HRESULT IScriptErrorList_advanceError_Proxy(IScriptErrorList *);
void IScriptErrorList_advanceError_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_retreatError_Proxy(IScriptErrorList *);
void IScriptErrorList_retreatError_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_canAdvanceError_Proxy(IScriptErrorList *,BOOL *);
void IScriptErrorList_canAdvanceError_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_canRetreatError_Proxy(IScriptErrorList *,BOOL *);
void IScriptErrorList_canRetreatError_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_getErrorLine_Proxy(IScriptErrorList *,LONG *);
void IScriptErrorList_getErrorLine_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_getErrorChar_Proxy(IScriptErrorList *,LONG *);
void IScriptErrorList_getErrorChar_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_getErrorCode_Proxy(IScriptErrorList *,LONG *);
void IScriptErrorList_getErrorCode_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_getErrorMsg_Proxy(IScriptErrorList *,BSTR *);
void IScriptErrorList_getErrorMsg_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_getErrorUrl_Proxy(IScriptErrorList *,BSTR *);
void IScriptErrorList_getErrorUrl_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_getAlwaysShowLockState_Proxy(IScriptErrorList *,BOOL *);
void IScriptErrorList_getAlwaysShowLockState_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_getDetailsPaneOpen_Proxy(IScriptErrorList *,BOOL *);
void IScriptErrorList_getDetailsPaneOpen_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_setDetailsPaneOpen_Proxy(IScriptErrorList *,BOOL );
void IScriptErrorList_setDetailsPaneOpen_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_getPerErrorDisplay_Proxy(IScriptErrorList *,BOOL *);
void IScriptErrorList_getPerErrorDisplay_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT IScriptErrorList_setPerErrorDisplay_Proxy(IScriptErrorList *,BOOL );
void IScriptErrorList_setPerErrorDisplay_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
EXTERN_C const CLSID CLSID_CScriptErrorList;
#ifndef __ISearch_INTERFACE_DEFINED__
#define __ISearch_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISearch;
typedef struct ISearchVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ISearch *,REFIID,void **);
 ULONG (*AddRef)(ISearch *);
 ULONG (*Release)(ISearch *);
 HRESULT (*GetTypeInfoCount)(ISearch *,UINT *);
 HRESULT (*GetTypeInfo)(ISearch *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(ISearch *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(ISearch *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*get_Title)(ISearch *,BSTR *);
 HRESULT (*get_Id)(ISearch *,BSTR *);
 HRESULT (*get_Url)(ISearch *,BSTR *);
END_INTERFACE
} ISearchVtbl;
interface ISearch
{
CONST_VTBL struct ISearchVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISearch_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISearch_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISearch_Release(A) (A)->lpVtbl->Release(A)
#define ISearch_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define ISearch_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define ISearch_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define ISearch_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define ISearch_get_Title(A,B) (A)->lpVtbl->get_Title(A,B)
#define ISearch_get_Id(A,B) (A)->lpVtbl->get_Id(A,B)
#define ISearch_get_Url(A,B) (A)->lpVtbl->get_Url(A,B)
#endif 
HRESULT ISearch_get_Title_Proxy(ISearch *,BSTR *);
void ISearch_get_Title_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearch_get_Id_Proxy(ISearch *,BSTR *);
void ISearch_get_Id_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearch_get_Url_Proxy(ISearch *,BSTR *);
void ISearch_get_Url_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ISearches_INTERFACE_DEFINED__
#define __ISearches_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISearches;
typedef struct ISearchesVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ISearches *,REFIID,void **);
 ULONG (*AddRef)(ISearches *);
 ULONG (*Release)(ISearches *);
 HRESULT (*GetTypeInfoCount)(ISearches *,UINT *);
 HRESULT (*GetTypeInfo)(ISearches *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(ISearches *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(ISearches *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*get_Count)(ISearches *,long *);
 HRESULT (*get_Default)(ISearches *,BSTR *);
 HRESULT (*Item)(ISearches *,VARIANT,ISearch **);
 HRESULT (*_NewEnum)(ISearches *,IUnknown **);
END_INTERFACE
} ISearchesVtbl;
interface ISearches
{
CONST_VTBL struct ISearchesVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISearches_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISearches_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISearches_Release(A) (A)->lpVtbl->Release(A)
#define ISearches_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define ISearches_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define ISearches_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define ISearches_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define ISearches_get_Count(A,B) (A)->lpVtbl->get_Count(A,B)
#define ISearches_get_Default(A,B) (A)->lpVtbl->get_Default(A,B)
#define ISearches_Item(A,B,C) (A)->lpVtbl->Item(A,B,C)
#define ISearches__NewEnum(A,B) (A)->lpVtbl->_NewEnum(A,B)
#endif 
HRESULT ISearches_get_Count_Proxy(ISearches *,long *);
void ISearches_get_Count_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearches_get_Default_Proxy(ISearches *,BSTR *);
void ISearches_get_Default_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearches_Item_Proxy(ISearches *,VARIANT ,ISearch **);
void ISearches_Item_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearches__NewEnum_Proxy(ISearches *,IUnknown **);
void ISearches__NewEnum_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ISearchAssistantOC_INTERFACE_DEFINED__
#define __ISearchAssistantOC_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISearchAssistantOC;
typedef struct ISearchAssistantOCVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ISearchAssistantOC *,REFIID,void **);
 ULONG (*AddRef)(ISearchAssistantOC *);
 ULONG (*Release)(ISearchAssistantOC *);
 HRESULT (*GetTypeInfoCount)(ISearchAssistantOC *,UINT *);
 HRESULT (*GetTypeInfo)(ISearchAssistantOC *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(ISearchAssistantOC *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(ISearchAssistantOC *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*AddNextMenuItem)(ISearchAssistantOC *,BSTR,long);
 HRESULT (*SetDefaultSearchUrl)(ISearchAssistantOC *,BSTR);
 HRESULT (*NavigateToDefaultSearch)(ISearchAssistantOC *);
 HRESULT (*IsRestricted)(ISearchAssistantOC *,BSTR,VARIANT_BOOL *);
 HRESULT (*get_ShellFeaturesEnabled)(ISearchAssistantOC *,VARIANT_BOOL *);
 HRESULT (*get_SearchAssistantDefault)(ISearchAssistantOC *,VARIANT_BOOL *);
 HRESULT (*get_Searches)(ISearchAssistantOC *,ISearches **);
 HRESULT (*get_InWebFolder)(ISearchAssistantOC *,VARIANT_BOOL *);
 HRESULT (*PutProperty)(ISearchAssistantOC *,VARIANT_BOOL,BSTR,BSTR);
 HRESULT (*GetProperty)(ISearchAssistantOC *,VARIANT_BOOL,BSTR,BSTR *);
 HRESULT (*put_EventHandled)(ISearchAssistantOC *,VARIANT_BOOL);
 HRESULT (*ResetNextMenu)(ISearchAssistantOC *);
 HRESULT (*FindOnWeb)(ISearchAssistantOC *);
 HRESULT (*FindFilesOrFolders)(ISearchAssistantOC *);
 HRESULT (*FindComputer)(ISearchAssistantOC *);
 HRESULT (*FindPrinter)(ISearchAssistantOC *);
 HRESULT (*FindPeople)(ISearchAssistantOC *);
 HRESULT (*GetSearchAssistantURL)(ISearchAssistantOC *,VARIANT_BOOL,VARIANT_BOOL,BSTR *);
 HRESULT (*NotifySearchSettingsChanged)(ISearchAssistantOC *);
 HRESULT (*put_ASProvider)(ISearchAssistantOC *,BSTR);
 HRESULT (*get_ASProvider)(ISearchAssistantOC *,BSTR *);
 HRESULT (*put_ASSetting)(ISearchAssistantOC *,int);
 HRESULT (*get_ASSetting)(ISearchAssistantOC *,int *);
 HRESULT (*NETDetectNextNavigate)(ISearchAssistantOC *);
 HRESULT (*PutFindText)(ISearchAssistantOC *,BSTR);
 HRESULT (*get_Version)(ISearchAssistantOC *,int *);
 HRESULT (*EncodeString)(ISearchAssistantOC *,BSTR,BSTR,VARIANT_BOOL,BSTR *);
END_INTERFACE
} ISearchAssistantOCVtbl;
interface ISearchAssistantOC
{
CONST_VTBL struct ISearchAssistantOCVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISearchAssistantOC_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISearchAssistantOC_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISearchAssistantOC_Release(A) (A)->lpVtbl->Release(A)
#define ISearchAssistantOC_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define ISearchAssistantOC_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define ISearchAssistantOC_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define ISearchAssistantOC_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define ISearchAssistantOC_AddNextMenuItem(A,B,C) (A)->lpVtbl->AddNextMenuItem(A,B,C)
#define ISearchAssistantOC_SetDefaultSearchUrl(A,B) (A)->lpVtbl->SetDefaultSearchUrl(A,B)
#define ISearchAssistantOC_NavigateToDefaultSearch(A) (A)->lpVtbl->NavigateToDefaultSearch(A)
#define ISearchAssistantOC_IsRestricted(A,B,C) (A)->lpVtbl->IsRestricted(A,B,C)
#define ISearchAssistantOC_get_ShellFeaturesEnabled(A,B) (A)->lpVtbl->get_ShellFeaturesEnabled(A,B)
#define ISearchAssistantOC_get_SearchAssistantDefault(A,B) (A)->lpVtbl->get_SearchAssistantDefault(A,B)
#define ISearchAssistantOC_get_Searches(A,B) (A)->lpVtbl->get_Searches(A,B)
#define ISearchAssistantOC_get_InWebFolder(A,B) (A)->lpVtbl->get_InWebFolder(A,B)
#define ISearchAssistantOC_PutProperty(A,B,C,D) (A)->lpVtbl->PutProperty(A,B,C,D)
#define ISearchAssistantOC_GetProperty(A,B,C,D) (A)->lpVtbl->GetProperty(A,B,C,D)
#define ISearchAssistantOC_put_EventHandled(A,B) (A)->lpVtbl->put_EventHandled(A,B)
#define ISearchAssistantOC_ResetNextMenu(A) (A)->lpVtbl->ResetNextMenu(A)
#define ISearchAssistantOC_FindOnWeb(A) (A)->lpVtbl->FindOnWeb(A)
#define ISearchAssistantOC_FindFilesOrFolders(A) (A)->lpVtbl->FindFilesOrFolders(A)
#define ISearchAssistantOC_FindComputer(A) (A)->lpVtbl->FindComputer(A)
#define ISearchAssistantOC_FindPrinter(A) (A)->lpVtbl->FindPrinter(A)
#define ISearchAssistantOC_FindPeople(A) (A)->lpVtbl->FindPeople(A)
#define ISearchAssistantOC_GetSearchAssistantURL(A,B,C,D) (A)->lpVtbl->GetSearchAssistantURL(A,B,C,D)
#define ISearchAssistantOC_NotifySearchSettingsChanged(A) (A)->lpVtbl->NotifySearchSettingsChanged(A)
#define ISearchAssistantOC_put_ASProvider(A,B) (A)->lpVtbl->put_ASProvider(A,B)
#define ISearchAssistantOC_get_ASProvider(A,B) (A)->lpVtbl->get_ASProvider(A,B)
#define ISearchAssistantOC_put_ASSetting(A,B) (A)->lpVtbl->put_ASSetting(A,B)
#define ISearchAssistantOC_get_ASSetting(A,B) (A)->lpVtbl->get_ASSetting(A,B)
#define ISearchAssistantOC_NETDetectNextNavigate(A) (A)->lpVtbl->NETDetectNextNavigate(A)
#define ISearchAssistantOC_PutFindText(A,B) (A)->lpVtbl->PutFindText(A,B)
#define ISearchAssistantOC_get_Version(A,B) (A)->lpVtbl->get_Version(A,B)
#define ISearchAssistantOC_EncodeString(A,B,C,D,E) (A)->lpVtbl->EncodeString(A,B,C,D,E)
#endif 
HRESULT ISearchAssistantOC_AddNextMenuItem_Proxy(ISearchAssistantOC *,BSTR ,long );
void ISearchAssistantOC_AddNextMenuItem_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_SetDefaultSearchUrl_Proxy(ISearchAssistantOC *,BSTR );
void ISearchAssistantOC_SetDefaultSearchUrl_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_NavigateToDefaultSearch_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_NavigateToDefaultSearch_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_IsRestricted_Proxy(ISearchAssistantOC *,BSTR ,VARIANT_BOOL *);
void ISearchAssistantOC_IsRestricted_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_get_ShellFeaturesEnabled_Proxy(ISearchAssistantOC *,VARIANT_BOOL *);
void ISearchAssistantOC_get_ShellFeaturesEnabled_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_get_SearchAssistantDefault_Proxy(ISearchAssistantOC *,VARIANT_BOOL *);
void ISearchAssistantOC_get_SearchAssistantDefault_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_get_Searches_Proxy(ISearchAssistantOC *,ISearches **);
void ISearchAssistantOC_get_Searches_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_get_InWebFolder_Proxy(ISearchAssistantOC *,VARIANT_BOOL *);
void ISearchAssistantOC_get_InWebFolder_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_PutProperty_Proxy(ISearchAssistantOC *,VARIANT_BOOL ,BSTR ,BSTR );
void ISearchAssistantOC_PutProperty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_GetProperty_Proxy(ISearchAssistantOC *,VARIANT_BOOL ,BSTR ,BSTR *);
void ISearchAssistantOC_GetProperty_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_put_EventHandled_Proxy(ISearchAssistantOC *,VARIANT_BOOL );
void ISearchAssistantOC_put_EventHandled_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_ResetNextMenu_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_ResetNextMenu_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_FindOnWeb_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_FindOnWeb_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_FindFilesOrFolders_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_FindFilesOrFolders_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_FindComputer_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_FindComputer_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_FindPrinter_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_FindPrinter_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_FindPeople_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_FindPeople_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_GetSearchAssistantURL_Proxy(ISearchAssistantOC *,VARIANT_BOOL ,VARIANT_BOOL ,BSTR *);
void ISearchAssistantOC_GetSearchAssistantURL_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_NotifySearchSettingsChanged_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_NotifySearchSettingsChanged_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_put_ASProvider_Proxy(ISearchAssistantOC *,BSTR );
void ISearchAssistantOC_put_ASProvider_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_get_ASProvider_Proxy(ISearchAssistantOC *,BSTR *);
void ISearchAssistantOC_get_ASProvider_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_put_ASSetting_Proxy(ISearchAssistantOC *,int );
void ISearchAssistantOC_put_ASSetting_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_get_ASSetting_Proxy(ISearchAssistantOC *,int *);
void ISearchAssistantOC_get_ASSetting_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_NETDetectNextNavigate_Proxy(ISearchAssistantOC *);
void ISearchAssistantOC_NETDetectNextNavigate_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_PutFindText_Proxy(ISearchAssistantOC *,BSTR );
void ISearchAssistantOC_PutFindText_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_get_Version_Proxy(ISearchAssistantOC *,int *);
void ISearchAssistantOC_get_Version_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC_EncodeString_Proxy(ISearchAssistantOC *,BSTR ,BSTR ,VARIANT_BOOL ,BSTR *);
void ISearchAssistantOC_EncodeString_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ISearchAssistantOC2_INTERFACE_DEFINED__
#define __ISearchAssistantOC2_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISearchAssistantOC2;
typedef struct ISearchAssistantOC2Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ISearchAssistantOC2 *,REFIID,void **);
 ULONG (*AddRef)(ISearchAssistantOC2 *);
 ULONG (*Release)(ISearchAssistantOC2 *);
 HRESULT (*GetTypeInfoCount)(ISearchAssistantOC2 *,UINT *);
 HRESULT (*GetTypeInfo)(ISearchAssistantOC2 *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(ISearchAssistantOC2 *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(ISearchAssistantOC2 *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*AddNextMenuItem)(ISearchAssistantOC2 *,BSTR,long);
 HRESULT (*SetDefaultSearchUrl)(ISearchAssistantOC2 *,BSTR);
 HRESULT (*NavigateToDefaultSearch)(ISearchAssistantOC2 *);
 HRESULT (*IsRestricted)(ISearchAssistantOC2 *,BSTR,VARIANT_BOOL *);
 HRESULT (*get_ShellFeaturesEnabled)(ISearchAssistantOC2 *,VARIANT_BOOL *);
 HRESULT (*get_SearchAssistantDefault)(ISearchAssistantOC2 *,VARIANT_BOOL *);
 HRESULT (*get_Searches)(ISearchAssistantOC2 *,ISearches **);
 HRESULT (*get_InWebFolder)(ISearchAssistantOC2 *,VARIANT_BOOL *);
 HRESULT (*PutProperty)(ISearchAssistantOC2 *,VARIANT_BOOL,BSTR,BSTR);
 HRESULT (*GetProperty)(ISearchAssistantOC2 *,VARIANT_BOOL,BSTR,BSTR *);
 HRESULT (*put_EventHandled)(ISearchAssistantOC2 *,VARIANT_BOOL);
 HRESULT (*ResetNextMenu)(ISearchAssistantOC2 *);
 HRESULT (*FindOnWeb)(ISearchAssistantOC2 *);
 HRESULT (*FindFilesOrFolders)(ISearchAssistantOC2 *);
 HRESULT (*FindComputer)(ISearchAssistantOC2 *);
 HRESULT (*FindPrinter)(ISearchAssistantOC2 *);
 HRESULT (*FindPeople)(ISearchAssistantOC2 *);
 HRESULT (*GetSearchAssistantURL)(ISearchAssistantOC2 *,VARIANT_BOOL,VARIANT_BOOL,BSTR *);
 HRESULT (*NotifySearchSettingsChanged)(ISearchAssistantOC2 *);
 HRESULT (*put_ASProvider)(ISearchAssistantOC2 *,BSTR);
 HRESULT (*get_ASProvider)(ISearchAssistantOC2 *,BSTR *);
 HRESULT (*put_ASSetting)(ISearchAssistantOC2 *,int);
 HRESULT (*get_ASSetting)(ISearchAssistantOC2 *,int *);
 HRESULT (*NETDetectNextNavigate)(ISearchAssistantOC2 *);
 HRESULT (*PutFindText)(ISearchAssistantOC2 *,BSTR);
 HRESULT (*get_Version)(ISearchAssistantOC2 *,int *);
 HRESULT (*EncodeString)(ISearchAssistantOC2 *,BSTR,BSTR,VARIANT_BOOL,BSTR *);
 HRESULT (*get_ShowFindPrinter)(ISearchAssistantOC2 *,VARIANT_BOOL *);
END_INTERFACE
} ISearchAssistantOC2Vtbl;
interface ISearchAssistantOC2
{
CONST_VTBL struct ISearchAssistantOC2Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISearchAssistantOC2_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISearchAssistantOC2_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISearchAssistantOC2_Release(A) (A)->lpVtbl->Release(A)
#define ISearchAssistantOC2_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define ISearchAssistantOC2_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define ISearchAssistantOC2_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define ISearchAssistantOC2_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define ISearchAssistantOC2_AddNextMenuItem(A,B,C) (A)->lpVtbl->AddNextMenuItem(A,B,C)
#define ISearchAssistantOC2_SetDefaultSearchUrl(A,B) (A)->lpVtbl->SetDefaultSearchUrl(A,B)
#define ISearchAssistantOC2_NavigateToDefaultSearch(A) (A)->lpVtbl->NavigateToDefaultSearch(A)
#define ISearchAssistantOC2_IsRestricted(A,B,C) (A)->lpVtbl->IsRestricted(A,B,C)
#define ISearchAssistantOC2_get_ShellFeaturesEnabled(A,B) (A)->lpVtbl->get_ShellFeaturesEnabled(A,B)
#define ISearchAssistantOC2_get_SearchAssistantDefault(A,B) (A)->lpVtbl->get_SearchAssistantDefault(A,B)
#define ISearchAssistantOC2_get_Searches(A,B) (A)->lpVtbl->get_Searches(A,B)
#define ISearchAssistantOC2_get_InWebFolder(A,B) (A)->lpVtbl->get_InWebFolder(A,B)
#define ISearchAssistantOC2_PutProperty(A,B,C,D) (A)->lpVtbl->PutProperty(A,B,C,D)
#define ISearchAssistantOC2_GetProperty(A,B,C,D) (A)->lpVtbl->GetProperty(A,B,C,D)
#define ISearchAssistantOC2_put_EventHandled(A,B) (A)->lpVtbl->put_EventHandled(A,B)
#define ISearchAssistantOC2_ResetNextMenu(A) (A)->lpVtbl->ResetNextMenu(A)
#define ISearchAssistantOC2_FindOnWeb(A) (A)->lpVtbl->FindOnWeb(A)
#define ISearchAssistantOC2_FindFilesOrFolders(A) (A)->lpVtbl->FindFilesOrFolders(A)
#define ISearchAssistantOC2_FindComputer(A) (A)->lpVtbl->FindComputer(A)
#define ISearchAssistantOC2_FindPrinter(A) (A)->lpVtbl->FindPrinter(A)
#define ISearchAssistantOC2_FindPeople(A) (A)->lpVtbl->FindPeople(A)
#define ISearchAssistantOC2_GetSearchAssistantURL(A,B,C,D) (A)->lpVtbl->GetSearchAssistantURL(A,B,C,D)
#define ISearchAssistantOC2_NotifySearchSettingsChanged(A) (A)->lpVtbl->NotifySearchSettingsChanged(A)
#define ISearchAssistantOC2_put_ASProvider(A,B) (A)->lpVtbl->put_ASProvider(A,B)
#define ISearchAssistantOC2_get_ASProvider(A,B) (A)->lpVtbl->get_ASProvider(A,B)
#define ISearchAssistantOC2_put_ASSetting(A,B) (A)->lpVtbl->put_ASSetting(A,B)
#define ISearchAssistantOC2_get_ASSetting(A,B) (A)->lpVtbl->get_ASSetting(A,B)
#define ISearchAssistantOC2_NETDetectNextNavigate(A) (A)->lpVtbl->NETDetectNextNavigate(A)
#define ISearchAssistantOC2_PutFindText(A,B) (A)->lpVtbl->PutFindText(A,B)
#define ISearchAssistantOC2_get_Version(A,B) (A)->lpVtbl->get_Version(A,B)
#define ISearchAssistantOC2_EncodeString(A,B,C,D,E) (A)->lpVtbl->EncodeString(A,B,C,D,E)
#define ISearchAssistantOC2_get_ShowFindPrinter(A,B) (A)->lpVtbl->get_ShowFindPrinter(A,B)
#endif 
HRESULT ISearchAssistantOC2_get_ShowFindPrinter_Proxy(ISearchAssistantOC2 *,VARIANT_BOOL *);
void ISearchAssistantOC2_get_ShowFindPrinter_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef __ISearchAssistantOC3_INTERFACE_DEFINED__
#define __ISearchAssistantOC3_INTERFACE_DEFINED__
EXTERN_C const IID IID_ISearchAssistantOC3;
typedef struct ISearchAssistantOC3Vtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(ISearchAssistantOC3 *,REFIID,void **);
 ULONG (*AddRef)(ISearchAssistantOC3 *);
 ULONG (*Release)(ISearchAssistantOC3 *);
 HRESULT (*GetTypeInfoCount)(ISearchAssistantOC3 *,UINT *);
 HRESULT (*GetTypeInfo)(ISearchAssistantOC3 *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(ISearchAssistantOC3 *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(ISearchAssistantOC3 *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
 HRESULT (*AddNextMenuItem)(ISearchAssistantOC3 *,BSTR,long);
 HRESULT (*SetDefaultSearchUrl)(ISearchAssistantOC3 *,BSTR);
 HRESULT (*NavigateToDefaultSearch)(ISearchAssistantOC3 *);
 HRESULT (*IsRestricted)(ISearchAssistantOC3 *,BSTR,VARIANT_BOOL *);
 HRESULT (*get_ShellFeaturesEnabled)(ISearchAssistantOC3 *,VARIANT_BOOL *);
 HRESULT (*get_SearchAssistantDefault)(ISearchAssistantOC3 *,VARIANT_BOOL *);
 HRESULT (*get_Searches)(ISearchAssistantOC3 *,ISearches **);
 HRESULT (*get_InWebFolder)(ISearchAssistantOC3 *,VARIANT_BOOL *);
 HRESULT (*PutProperty)(ISearchAssistantOC3 *,VARIANT_BOOL,BSTR,BSTR);
 HRESULT (*GetProperty)(ISearchAssistantOC3 *,VARIANT_BOOL,BSTR,BSTR *);
 HRESULT (*put_EventHandled)(ISearchAssistantOC3 *,VARIANT_BOOL);
 HRESULT (*ResetNextMenu)(ISearchAssistantOC3 *);
 HRESULT (*FindOnWeb)(ISearchAssistantOC3 *);
 HRESULT (*FindFilesOrFolders)(ISearchAssistantOC3 *);
 HRESULT (*FindComputer)(ISearchAssistantOC3 *);
 HRESULT (*FindPrinter)(ISearchAssistantOC3 *);
 HRESULT (*FindPeople)(ISearchAssistantOC3 *);
 HRESULT (*GetSearchAssistantURL)(ISearchAssistantOC3 *,VARIANT_BOOL,VARIANT_BOOL,BSTR *);
 HRESULT (*NotifySearchSettingsChanged)(ISearchAssistantOC3 *);
 HRESULT (*put_ASProvider)(ISearchAssistantOC3 *,BSTR);
 HRESULT (*get_ASProvider)(ISearchAssistantOC3 *,BSTR *);
 HRESULT (*put_ASSetting)(ISearchAssistantOC3 *,int);
 HRESULT (*get_ASSetting)(ISearchAssistantOC3 *,int *);
 HRESULT (*NETDetectNextNavigate)(ISearchAssistantOC3 *);
 HRESULT (*PutFindText)(ISearchAssistantOC3 *,BSTR);
 HRESULT (*get_Version)(ISearchAssistantOC3 *,int *);
 HRESULT (*EncodeString)(ISearchAssistantOC3 *,BSTR,BSTR,VARIANT_BOOL,BSTR *);
 HRESULT (*get_ShowFindPrinter)(ISearchAssistantOC3 *,VARIANT_BOOL *);
 HRESULT (*get_SearchCompanionAvailable)(ISearchAssistantOC3 *,VARIANT_BOOL *);
 HRESULT (*put_UseSearchCompanion)(ISearchAssistantOC3 *,VARIANT_BOOL);
 HRESULT (*get_UseSearchCompanion)(ISearchAssistantOC3 *,VARIANT_BOOL *);
END_INTERFACE
} ISearchAssistantOC3Vtbl;
interface ISearchAssistantOC3
{
CONST_VTBL struct ISearchAssistantOC3Vtbl *lpVtbl;
};
#ifdef COBJMACROS
#define ISearchAssistantOC3_QueryInterface(A,B,C) (A)->lpVtbl->QueryInterface(A,B,C)
#define ISearchAssistantOC3_AddRef(A) (A)->lpVtbl->AddRef(A)
#define ISearchAssistantOC3_Release(A) (A)->lpVtbl->Release(A)
#define ISearchAssistantOC3_GetTypeInfoCount(A,B) (A)->lpVtbl->GetTypeInfoCount(A,B)
#define ISearchAssistantOC3_GetTypeInfo(A,B,C,D) (A)->lpVtbl->GetTypeInfo(A,B,C,D)
#define ISearchAssistantOC3_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->GetIDsOfNames(A,B,C,D,E,F)
#define ISearchAssistantOC3_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->Invoke(A,B,C,D,E,F,G,H,I)
#define ISearchAssistantOC3_AddNextMenuItem(A,B,C) (A)->lpVtbl->AddNextMenuItem(A,B,C)
#define ISearchAssistantOC3_SetDefaultSearchUrl(A,B) (A)->lpVtbl->SetDefaultSearchUrl(A,B)
#define ISearchAssistantOC3_NavigateToDefaultSearch(A) (A)->lpVtbl->NavigateToDefaultSearch(A)
#define ISearchAssistantOC3_IsRestricted(A,B,C) (A)->lpVtbl->IsRestricted(A,B,C)
#define ISearchAssistantOC3_get_ShellFeaturesEnabled(A,B) (A)->lpVtbl->get_ShellFeaturesEnabled(A,B)
#define ISearchAssistantOC3_get_SearchAssistantDefault(A,B) (A)->lpVtbl->get_SearchAssistantDefault(A,B)
#define ISearchAssistantOC3_get_Searches(A,B) (A)->lpVtbl->get_Searches(A,B)
#define ISearchAssistantOC3_get_InWebFolder(A,B) (A)->lpVtbl->get_InWebFolder(A,B)
#define ISearchAssistantOC3_PutProperty(A,B,C,D) (A)->lpVtbl->PutProperty(A,B,C,D)
#define ISearchAssistantOC3_GetProperty(A,B,C,D) (A)->lpVtbl->GetProperty(A,B,C,D)
#define ISearchAssistantOC3_put_EventHandled(A,B) (A)->lpVtbl->put_EventHandled(A,B)
#define ISearchAssistantOC3_ResetNextMenu(A) (A)->lpVtbl->ResetNextMenu(A)
#define ISearchAssistantOC3_FindOnWeb(A) (A)->lpVtbl->FindOnWeb(A)
#define ISearchAssistantOC3_FindFilesOrFolders(A) (A)->lpVtbl->FindFilesOrFolders(A)
#define ISearchAssistantOC3_FindComputer(A) (A)->lpVtbl->FindComputer(A)
#define ISearchAssistantOC3_FindPrinter(A) (A)->lpVtbl->FindPrinter(A)
#define ISearchAssistantOC3_FindPeople(A) (A)->lpVtbl->FindPeople(A)
#define ISearchAssistantOC3_GetSearchAssistantURL(A,B,C,D) (A)->lpVtbl->GetSearchAssistantURL(A,B,C,D)
#define ISearchAssistantOC3_NotifySearchSettingsChanged(A) (A)->lpVtbl->NotifySearchSettingsChanged(A)
#define ISearchAssistantOC3_put_ASProvider(A,B) (A)->lpVtbl->put_ASProvider(A,B)
#define ISearchAssistantOC3_get_ASProvider(A,B) (A)->lpVtbl->get_ASProvider(A,B)
#define ISearchAssistantOC3_put_ASSetting(A,B) (A)->lpVtbl->put_ASSetting(A,B)
#define ISearchAssistantOC3_get_ASSetting(A,B) (A)->lpVtbl->get_ASSetting(A,B)
#define ISearchAssistantOC3_NETDetectNextNavigate(A) (A)->lpVtbl->NETDetectNextNavigate(A)
#define ISearchAssistantOC3_PutFindText(A,B) (A)->lpVtbl->PutFindText(A,B)
#define ISearchAssistantOC3_get_Version(A,B) (A)->lpVtbl->get_Version(A,B)
#define ISearchAssistantOC3_EncodeString(A,B,C,D,E) (A)->lpVtbl->EncodeString(A,B,C,D,E)
#define ISearchAssistantOC3_get_ShowFindPrinter(A,B) (A)->lpVtbl->get_ShowFindPrinter(A,B)
#define ISearchAssistantOC3_get_SearchCompanionAvailable(A,B) (A)->lpVtbl->get_SearchCompanionAvailable(A,B)
#define ISearchAssistantOC3_put_UseSearchCompanion(A,B) (A)->lpVtbl->put_UseSearchCompanion(A,B)
#define ISearchAssistantOC3_get_UseSearchCompanion(A,B) (A)->lpVtbl->get_UseSearchCompanion(A,B)
#endif 
HRESULT ISearchAssistantOC3_get_SearchCompanionAvailable_Proxy(ISearchAssistantOC3 *,VARIANT_BOOL *);
void ISearchAssistantOC3_get_SearchCompanionAvailable_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC3_put_UseSearchCompanion_Proxy(ISearchAssistantOC3 *,VARIANT_BOOL );
void ISearchAssistantOC3_put_UseSearchCompanion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
HRESULT ISearchAssistantOC3_get_UseSearchCompanion_Proxy(ISearchAssistantOC3 *,VARIANT_BOOL *);
void ISearchAssistantOC3_get_UseSearchCompanion_Stub(IRpcStubBuffer *,IRpcChannelBuffer *,PRPC_MESSAGE ,DWORD *);
#endif 
#ifndef ___SearchAssistantEvents_DISPINTERFACE_DEFINED__
#define ___SearchAssistantEvents_DISPINTERFACE_DEFINED__
EXTERN_C const IID DIID__SearchAssistantEvents;
typedef struct _SearchAssistantEventsVtbl
{
 BEGIN_INTERFACE
 HRESULT (*QueryInterface)(_SearchAssistantEvents *,REFIID,void **);
 ULONG (*AddRef)(_SearchAssistantEvents *);
 ULONG (*Release)(_SearchAssistantEvents *);
 HRESULT (*GetTypeInfoCount)(_SearchAssistantEvents *,UINT *);
 HRESULT (*GetTypeInfo)(_SearchAssistantEvents *,UINT,LCID,ITypeInfo **);
 HRESULT (*GetIDsOfNames)(_SearchAssistantEvents *,REFIID,LPOLESTR *,UINT,LCID,DISPID *);
 HRESULT (*Invoke)(_SearchAssistantEvents *,DISPID,REFIID,LCID,WORD,DISPPARAMS *,VARIANT *,EXCEPINFO *,UINT *);
END_INTERFACE
} _SearchAssistantEventsVtbl;
interface _SearchAssistantEvents
{
CONST_VTBL struct _SearchAssistantEventsVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define _SearchAssistantEvents_QueryInterface(A,B,C) (A)->lpVtbl->SearchAssistantEvents_QueryInterface(A,B,C)
#define _SearchAssistantEvents_AddRef(A) (A)->lpVtbl->SearchAssistantEvents_AddRef(A)
#define _SearchAssistantEvents_Release(A) (A)->lpVtbl->SearchAssistantEvents_Release(A)
#define _SearchAssistantEvents_GetTypeInfoCount(A,B) (A)->lpVtbl->SearchAssistantEvents_GetTypeInfoCount(A,B)
#define _SearchAssistantEvents_GetTypeInfo(A,B,C,D) (A)->lpVtbl->SearchAssistantEvents_GetTypeInfo(A,B,C,D)
#define _SearchAssistantEvents_GetIDsOfNames(A,B,C,D,E,F) (A)->lpVtbl->SearchAssistantEvents_GetIDsOfNames(A,B,C,D,E,F)
#define _SearchAssistantEvents_Invoke(A,B,C,D,E,F,G,H,I) (A)->lpVtbl->SearchAssistantEvents_Invoke(A,B,C,D,E,F,G,H,I)
#endif 
#endif 
EXTERN_C const CLSID CLSID_SearchAssistantOC;
#endif 
#endif
