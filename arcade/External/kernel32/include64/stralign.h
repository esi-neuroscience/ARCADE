#if !defined(__STRALIGN_H_) && !defined(MIDL_PASS)
#define __STRALIGN_H_
#if 1
#define WSTR_ALIGNED(s) TRUE
#define ua_CharUpperW CharUpperW
#define ua_lstrcmpiW lstrcmpiW
#define ua_lstrcmpW lstrcmpW
#define ua_lstrlenW lstrlenW
#define ua_wcschr wcschr
#define ua_wcscpy wcscpy
#define ua_wcslen wcslen
#define ua_wcsrchr wcsrchr
#else
#define WSTR_ALIGNED(s) (((DWORD_PTR)(s) & (sizeof(WCHAR)-1))==0)
LPUWSTR WINAPI uaw_CharUpperW(LPUWSTR String);
int APIENTRY uaw_lstrcmpW(PCUWSTR String1,PCUWSTR String2);
int APIENTRY uaw_lstrcmpiW(PCUWSTR String1,PCUWSTR String2);
int WINAPI uaw_lstrlenW(LPCUWSTR String);
PUWSTR uaw_wcschr(PCUWSTR String,WCHAR Character);
PUWSTR _cdecl uaw_wcscpy(PUWSTR Destination,PCUWSTR Source);
size_t uaw_wcslen(PCUWSTR String);
PUWSTR uaw_wcsrchr(PCUWSTR String,WCHAR Character);
#if defined(CharUpper)
__inline LPUWSTR static ua_CharUpperW(LPUWSTR String) {
	if (WSTR_ALIGNED(String)) {
		return CharUpperW((PWSTR)String );
	} else {
		return uaw_CharUpperW(String );
	}
}
#endif
#if defined(lstrcmp)
__inline int static ua_lstrcmpW(LPCUWSTR String1,LPCUWSTR String2) {
	if (WSTR_ALIGNED(String1) && WSTR_ALIGNED(String2)) {
		return lstrcmpW((LPCWSTR)String1,(LPCWSTR)String2);
	} else {
		return uaw_lstrcmpW(String1,String2 );
	}
}
#endif
#if defined(lstrcmpi)
__inline int static ua_lstrcmpiW(LPCUWSTR String1,LPCUWSTR String2) {
	if (WSTR_ALIGNED(String1) && WSTR_ALIGNED(String2)) {
		return lstrcmpiW((LPCWSTR)String1,(LPCWSTR)String2 );
	} else {
		return uaw_lstrcmpiW(String1,String2 );
	}
}
#endif
#if defined(lstrlen)
__inline int static ua_lstrlenW(LPCUWSTR String) {
	if (WSTR_ALIGNED(String)) {
		return lstrlenW((PCWSTR)String );
	} else {
		return uaw_lstrlenW(String );
	}
}
#endif
#if defined(_WSTRING_DEFINED)
#if defined(_WConst_return) 
typedef _WConst_return WCHAR UNALIGNED *PUWSTR_C;
#else
typedef WCHAR UNALIGNED *PUWSTR_C;
#endif
__inline PUWSTR_C static ua_wcschr(PCUWSTR String,WCHAR Character) {
	if (WSTR_ALIGNED(String)) {
		return wcschr((PCWSTR)String,Character);
	} else {
		return (PUWSTR_C)uaw_wcschr(String,Character);
	}
}
__inline PUWSTR_C static ua_wcsrchr(PCUWSTR String,WCHAR Character) {
	if (WSTR_ALIGNED(String)) {
		return wcsrchr((PCWSTR)String,Character);
	} else {
		return (PUWSTR_C)uaw_wcsrchr(String,Character);
	}
}
#if defined(__cplusplus) && defined(_WConst_Return)
__inline PUWSTR static ua_wcschr(PUWSTR String,WCHAR Character) {
	if (WSTR_ALIGNED(String)) {
		return wcschr(String,Character);
	} else {
		return uaw_wcschr((PCUWSTR)String,Character);
	}
}
__inline PUWSTR static ua_wcsrchr(PUWSTR String,WCHAR Character) {
	if (WSTR_ALIGNED(String)) {
		return wcsrchr(String,Character);
	} else {
		return uaw_wcsrchr((PCUWSTR)String,Character);
	}
}
#endif 
__inline PUWSTR static ua_wcscpy(PUWSTR Destination,PCUWSTR Source) {
	if (WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) {
		return wcscpy((PWSTR)Destination,(PCWSTR)Source );
	} else {
		return uaw_wcscpy(Destination,Source );
	}
}
__inline size_t static ua_wcslen(PCUWSTR String) {
	if (WSTR_ALIGNED(String)) {
		return wcslen((PCWSTR)String );
	} else {
		return uaw_wcslen(String );
	}
}
#endif 
#endif 
#if !defined(__UA_WCSLEN)
#define __UA_WCSLEN ua_wcslen
#endif
#define __UA_WSTRSIZE(s)((__UA_WCSLEN(s)+1)*sizeof(WCHAR))
#define __UA_STACKCOPY(p,s) memcpy(_alloca(s),p,s)
#if defined(_X86_)
#define WSTR_ALIGNED_STACK_COPY(d,s) (*(d)=(PCWSTR)(s))
#else
#define WSTR_ALIGNED_STACK_COPY(d,s) { PCUWSTR __ua_src; ULONG __ua_size; PWSTR __ua_dst; __ua_src=(s); if (WSTR_ALIGNED(__ua_src)) { __ua_dst=(PWSTR)__ua_src; } else { __ua_size=__UA_WSTRSIZE(__ua_src); __ua_dst=(PWSTR)_alloca(__ua_size); memcpy(__ua_dst,__ua_src,__ua_size); } *(d)=(PCWSTR)__ua_dst; }
#endif
#define ASTR_ALIGNED_STACK_COPY(d,s) (*(d)=(PCSTR)(s))
#if !defined(_X86_)
#define __UA_STRUC_ALIGNED(t,s)(((DWORD_PTR)(s) & (TYPE_ALIGNMENT(t)-1))==0)
#define STRUC_ALIGNED_STACK_COPY(t,s) __UA_STRUC_ALIGNED(t,s) ?((t const *)(s)) :((t const *)__UA_STACKCOPY((s),sizeof(t)))
#else
#define STRUC_ALIGNED_STACK_COPY(t,s) ((CONST t *)(s))
#endif
#if defined(UNICODE)
#define TSTR_ALIGNED_STACK_COPY(d,s) WSTR_ALIGNED_STACK_COPY(d,s)
#define TSTR_ALIGNED(x) WSTR_ALIGNED(x)
#define ua_CharUpper ua_CharUpperW
#define ua_lstrcmp ua_lstrcmpW
#define ua_lstrcmpi ua_lstrcmpiW
#define ua_lstrlen ua_lstrlenW
#define ua_tcscpy ua_wcscpy
#else
#define TSTR_ALIGNED_STACK_COPY(d,s) ASTR_ALIGNED_STACK_COPY(d,s)
#define TSTR_ALIGNED(x) TRUE
#define ua_CharUpper CharUpperA
#define ua_lstrcmp lstrcmpA
#define ua_lstrcmpi lstrcmpiA
#define ua_lstrlen lstrlenA
#define ua_tcscpy strcpy
#endif 
#endif 
