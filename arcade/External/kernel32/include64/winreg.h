#ifndef _WINREG_
#define _WINREG_
#ifdef _MAC
#include <macwin32.h>
#endif
#ifndef WINVER
#define WINVER 1280 
#endif 
#define RRF_RT_REG_NONE 1 
#define RRF_RT_REG_SZ 2 
#define RRF_RT_REG_EXPAND_SZ 4 
#define RRF_RT_REG_BINARY 8 
#define RRF_RT_REG_DWORD 16 
#define RRF_RT_REG_MULTI_SZ 32 
#define RRF_RT_REG_QWORD 64 
#define RRF_RT_DWORD (RRF_RT_REG_BINARY|RRF_RT_REG_DWORD) 
#define RRF_RT_QWORD (RRF_RT_REG_BINARY|RRF_RT_REG_QWORD) 
#define RRF_RT_ANY 0xffff 
#define RRF_NOEXPAND 0x10000000 
#define RRF_ZEROONFAILURE 0x20000000 
typedef ACCESS_MASK REGSAM;
#define HKEY_CLASSES_ROOT ((HKEY ) (ULONG_PTR)((LONG)0x80000000) )
#define HKEY_CURRENT_USER ((HKEY ) (ULONG_PTR)((LONG)0x80000001) )
#define HKEY_LOCAL_MACHINE ((HKEY ) (ULONG_PTR)((LONG)0x80000002) )
#define HKEY_USERS ((HKEY ) (ULONG_PTR)((LONG)0x80000003) )
#define HKEY_PERFORMANCE_DATA ((HKEY ) (ULONG_PTR)((LONG)0x80000004) )
#define HKEY_PERFORMANCE_TEXT ((HKEY ) (ULONG_PTR)((LONG)0x80000050) )
#define HKEY_PERFORMANCE_NLSTEXT ((HKEY ) (ULONG_PTR)((LONG)0x80000060) )
#if(WINVER >=0x0400)
#define HKEY_CURRENT_CONFIG ((HKEY ) (ULONG_PTR)((LONG)0x80000005) )
#define HKEY_DYN_DATA ((HKEY ) (ULONG_PTR)((LONG)0x80000006) )
#define REG_SECURE_CONNECTION 1 
#ifndef _PROVIDER_STRUCTS_DEFINED
#define _PROVIDER_STRUCTS_DEFINED
#define PROVIDER_KEEPS_VALUE_LENGTH 1
struct val_context {
	int valuelen; 
	LPVOID value_context; 
	LPVOID val_buff_ptr; 
};
typedef struct val_context *PVALCONTEXT;
typedef struct pvalueA { 
	LPSTR pv_valuename; 
	int pv_valuelen;
	LPVOID pv_value_context;
	DWORD pv_type;
}PVALUEA,*PPVALUEA;
typedef struct pvalueW { 
	LPWSTR pv_valuename; 
	int pv_valuelen;
	LPVOID pv_value_context;
	DWORD pv_type;
}PVALUEW,*PPVALUEW;
#ifdef UNICODE
typedef PVALUEW PVALUE;
typedef PPVALUEW PPVALUE;
#else
typedef PVALUEA PVALUE;
typedef PPVALUEA PPVALUE;
#endif 
typedef DWORD _cdecl
QUERYHANDLER (LPVOID keycontext,PVALCONTEXT val_list,DWORD num_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD input_blen);
typedef QUERYHANDLER *PQUERYHANDLER;
typedef struct provider_info {
	PQUERYHANDLER pi_R0_1val;
	PQUERYHANDLER pi_R0_allvals;
	PQUERYHANDLER pi_R3_1val;
	PQUERYHANDLER pi_R3_allvals;
	DWORD pi_flags; 
	LPVOID pi_key_context;
}REG_PROVIDER;
typedef struct provider_info *PPROVIDER;
typedef struct value_entA {
	LPSTR ve_valuename;
	DWORD ve_valuelen;
	DWORD_PTR ve_valueptr;
	DWORD ve_type;
}VALENTA,*PVALENTA;
typedef struct value_entW {
	LPWSTR ve_valuename;
	DWORD ve_valuelen;
	DWORD_PTR ve_valueptr;
	DWORD ve_type;
}VALENTW,*PVALENTW;
#ifdef UNICODE
typedef VALENTW VALENT;
typedef PVALENTW PVALENT;
#else
typedef VALENTA VALENT;
typedef PVALENTA PVALENT;
#endif 
#endif 
#endif 
#define WIN31_CLASS NULL
WINADVAPI LONG APIENTRY RegCloseKey (HKEY hKey);
WINADVAPI LONG APIENTRY RegOverridePredefKey (HKEY hKey,HKEY hNewHKey);
WINADVAPI LONG APIENTRY RegOpenUserClassesRoot(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
WINADVAPI LONG APIENTRY RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
WINADVAPI LONG APIENTRY RegDisablePredefinedCache();
WINADVAPI LONG APIENTRY RegConnectRegistryA (LPCSTR lpMachineName,HKEY hKey,PHKEY phkResult);
WINADVAPI LONG APIENTRY RegConnectRegistryW (LPCWSTR lpMachineName,HKEY hKey,PHKEY phkResult);
#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#else
#define RegConnectRegistry RegConnectRegistryA
#endif 
WINADVAPI LONG APIENTRY RegConnectRegistryExA (LPCSTR lpMachineName,HKEY hKey,ULONG Flags,PHKEY phkResult);
WINADVAPI LONG APIENTRY RegConnectRegistryExW (LPCWSTR lpMachineName,HKEY hKey,ULONG Flags,PHKEY phkResult);
#ifdef UNICODE
#define RegConnectRegistryEx RegConnectRegistryExW
#else
#define RegConnectRegistryEx RegConnectRegistryExA
#endif 
WINADVAPI LONG APIENTRY RegCreateKeyA (HKEY hKey,LPCSTR lpSubKey,PHKEY phkResult);
WINADVAPI LONG APIENTRY RegCreateKeyW (HKEY hKey,LPCWSTR lpSubKey,PHKEY phkResult);
#ifdef UNICODE
#define RegCreateKey RegCreateKeyW
#else
#define RegCreateKey RegCreateKeyA
#endif 
WINADVAPI LONG APIENTRY RegCreateKeyExA (HKEY hKey,LPCSTR lpSubKey,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
WINADVAPI LONG APIENTRY RegCreateKeyExW (HKEY hKey,LPCWSTR lpSubKey,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
#ifdef UNICODE
#define RegCreateKeyEx RegCreateKeyExW
#else
#define RegCreateKeyEx RegCreateKeyExA
#endif 
WINADVAPI LONG APIENTRY RegDeleteKeyA (HKEY hKey,LPCSTR lpSubKey);
WINADVAPI LONG APIENTRY RegDeleteKeyW (HKEY hKey,LPCWSTR lpSubKey);
#ifdef UNICODE
#define RegDeleteKey RegDeleteKeyW
#else
#define RegDeleteKey RegDeleteKeyA
#endif 
WINADVAPI LONG APIENTRY RegDeleteKeyExA (HKEY hKey,LPCSTR lpSubKey,REGSAM samDesired,DWORD Reserved); 
WINADVAPI LONG APIENTRY RegDeleteKeyExW (HKEY hKey,LPCWSTR lpSubKey,REGSAM samDesired,DWORD Reserved); 
#ifdef UNICODE
#define RegDeleteKeyEx RegDeleteKeyExW
#else
#define RegDeleteKeyEx RegDeleteKeyExA
#endif 
WINADVAPI LONG APIENTRY RegDeleteValueA (HKEY hKey,LPCSTR lpValueName);
WINADVAPI LONG APIENTRY RegDeleteValueW (HKEY hKey,LPCWSTR lpValueName);
#ifdef UNICODE
#define RegDeleteValue RegDeleteValueW
#else
#define RegDeleteValue RegDeleteValueA
#endif 
WINADVAPI LONG APIENTRY RegEnumKeyA (HKEY hKey,DWORD dwIndex,LPSTR lpName,DWORD cchName);
WINADVAPI LONG APIENTRY RegEnumKeyW (HKEY hKey,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
#ifdef UNICODE
#define RegEnumKey RegEnumKeyW
#else
#define RegEnumKey RegEnumKeyA
#endif 
WINADVAPI LONG APIENTRY RegEnumKeyExA (HKEY hKey,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
WINADVAPI LONG APIENTRY RegEnumKeyExW (HKEY hKey,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
#ifdef UNICODE
#define RegEnumKeyEx RegEnumKeyExW
#else
#define RegEnumKeyEx RegEnumKeyExA
#endif 
WINADVAPI LONG APIENTRY RegEnumValueA (HKEY hKey,DWORD dwIndex,LPSTR lpValueName,LPDWORD lpcchValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
WINADVAPI LONG APIENTRY RegEnumValueW (HKEY hKey,DWORD dwIndex,LPWSTR lpValueName,LPDWORD lpcchValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
#ifdef UNICODE
#define RegEnumValue RegEnumValueW
#else
#define RegEnumValue RegEnumValueA
#endif 
WINADVAPI LONG APIENTRY RegFlushKey (HKEY hKey);
WINADVAPI LONG APIENTRY RegGetKeySecurity (HKEY hKey,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
WINADVAPI LONG APIENTRY RegLoadKeyA (HKEY hKey,LPCSTR lpSubKey,LPCSTR lpFile);
WINADVAPI LONG APIENTRY RegLoadKeyW (HKEY hKey,LPCWSTR lpSubKey,LPCWSTR lpFile);
#ifdef UNICODE
#define RegLoadKey RegLoadKeyW
#else
#define RegLoadKey RegLoadKeyA
#endif 
WINADVAPI LONG APIENTRY RegNotifyChangeKeyValue (HKEY hKey,BOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,BOOL fAsynchronous);
WINADVAPI LONG APIENTRY RegOpenKeyA (HKEY hKey,LPCSTR lpSubKey,PHKEY phkResult);
WINADVAPI LONG APIENTRY RegOpenKeyW (HKEY hKey,LPCWSTR lpSubKey,PHKEY phkResult);
#ifdef UNICODE
#define RegOpenKey RegOpenKeyW
#else
#define RegOpenKey RegOpenKeyA
#endif 
WINADVAPI LONG APIENTRY RegOpenKeyExA (HKEY hKey,LPCSTR lpSubKey,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
WINADVAPI LONG APIENTRY RegOpenKeyExW (HKEY hKey,LPCWSTR lpSubKey,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
#ifdef UNICODE
#define RegOpenKeyEx RegOpenKeyExW
#else
#define RegOpenKeyEx RegOpenKeyExA
#endif 
WINADVAPI LONG APIENTRY RegQueryInfoKeyA (HKEY hKey,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpcSubKeys,LPDWORD lpcbMaxSubKeyLen,LPDWORD lpcbMaxClassLen,LPDWORD lpcValues,LPDWORD lpcbMaxValueNameLen,LPDWORD lpcbMaxValueLen,LPDWORD lpcbSecurityDescriptor,
	PFILETIME lpftLastWriteTime);
WINADVAPI LONG APIENTRY RegQueryInfoKeyW (HKEY hKey,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpcSubKeys,LPDWORD lpcbMaxSubKeyLen,LPDWORD lpcbMaxClassLen,LPDWORD lpcValues,LPDWORD lpcbMaxValueNameLen,LPDWORD lpcbMaxValueLen,LPDWORD lpcbSecurityDescriptor,
	PFILETIME lpftLastWriteTime);
#ifdef UNICODE
#define RegQueryInfoKey RegQueryInfoKeyW
#else
#define RegQueryInfoKey RegQueryInfoKeyA
#endif 
WINADVAPI LONG APIENTRY RegQueryValueA (HKEY hKey,LPCSTR lpSubKey,LPSTR lpData,PLONG lpcbData);
WINADVAPI LONG APIENTRY RegQueryValueW (HKEY hKey,LPCWSTR lpSubKey,LPWSTR lpData,PLONG lpcbData);
#ifdef UNICODE
#define RegQueryValue RegQueryValueW
#else
#define RegQueryValue RegQueryValueA
#endif 
#if(WINVER >=0x0400)
WINADVAPI LONG APIENTRY RegQueryMultipleValuesA (HKEY hKey,PVALENTA val_list,DWORD num_vals,LPSTR lpValueBuf,LPDWORD ldwTotsize);
WINADVAPI LONG APIENTRY RegQueryMultipleValuesW (HKEY hKey,PVALENTW val_list,DWORD num_vals,LPWSTR lpValueBuf,LPDWORD ldwTotsize);
#ifdef UNICODE
#define RegQueryMultipleValues RegQueryMultipleValuesW
#else
#define RegQueryMultipleValues RegQueryMultipleValuesA
#endif 
#endif 
WINADVAPI LONG APIENTRY RegQueryValueExA (HKEY hKey,LPCSTR lpValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
WINADVAPI LONG APIENTRY RegQueryValueExW (HKEY hKey,LPCWSTR lpValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
#ifdef UNICODE
#define RegQueryValueEx RegQueryValueExW
#else
#define RegQueryValueEx RegQueryValueExA
#endif 
WINADVAPI LONG APIENTRY RegReplaceKeyA (HKEY hKey,LPCSTR lpSubKey,LPCSTR lpNewFile,LPCSTR lpOldFile);
WINADVAPI LONG APIENTRY RegReplaceKeyW (HKEY hKey,LPCWSTR lpSubKey,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
#ifdef UNICODE
#define RegReplaceKey RegReplaceKeyW
#else
#define RegReplaceKey RegReplaceKeyA
#endif 
WINADVAPI LONG APIENTRY RegRestoreKeyA (HKEY hKey,LPCSTR lpFile,DWORD dwFlags);
WINADVAPI LONG APIENTRY RegRestoreKeyW (HKEY hKey,LPCWSTR lpFile,DWORD dwFlags);
#ifdef UNICODE
#define RegRestoreKey RegRestoreKeyW
#else
#define RegRestoreKey RegRestoreKeyA
#endif 
WINADVAPI LONG APIENTRY RegSaveKeyA (HKEY hKey,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINADVAPI LONG APIENTRY RegSaveKeyW (HKEY hKey,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#ifdef UNICODE
#define RegSaveKey RegSaveKeyW
#else
#define RegSaveKey RegSaveKeyA
#endif 
WINADVAPI LONG APIENTRY RegSetKeySecurity (HKEY hKey,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
WINADVAPI LONG APIENTRY RegSetValueA (HKEY hKey,LPCSTR lpSubKey,DWORD dwType,LPCSTR lpData,DWORD cbData);
WINADVAPI LONG APIENTRY RegSetValueW (HKEY hKey,LPCWSTR lpSubKey,DWORD dwType,LPCWSTR lpData,DWORD cbData);
#ifdef UNICODE
#define RegSetValue RegSetValueW
#else
#define RegSetValue RegSetValueA
#endif 
WINADVAPI LONG APIENTRY RegSetValueExA (HKEY hKey,LPCSTR lpValueName,DWORD Reserved,DWORD dwType,CONST BYTE* lpData,DWORD cbData);
WINADVAPI LONG APIENTRY RegSetValueExW (HKEY hKey,LPCWSTR lpValueName,DWORD Reserved,DWORD dwType,CONST BYTE* lpData,DWORD cbData);
#ifdef UNICODE
#define RegSetValueEx RegSetValueExW
#else
#define RegSetValueEx RegSetValueExA
#endif 
WINADVAPI LONG APIENTRY RegUnLoadKeyA (HKEY hKey,LPCSTR lpSubKey);
WINADVAPI LONG APIENTRY RegUnLoadKeyW (HKEY hKey,LPCWSTR lpSubKey);
#ifdef UNICODE
#define RegUnLoadKey RegUnLoadKeyW
#else
#define RegUnLoadKey RegUnLoadKeyA
#endif 
WINADVAPI LONG APIENTRY RegGetValueA (HKEY hkey,LPCSTR lpSubKey,LPCSTR lpValue,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData );
WINADVAPI LONG APIENTRY RegGetValueW (HKEY hkey,LPCWSTR lpSubKey,LPCWSTR lpValue,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData );
#ifdef UNICODE
#define RegGetValue RegGetValueW
#else
#define RegGetValue RegGetValueA
#endif 
WINADVAPI BOOL APIENTRY InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,BOOL bForceAppsClosed,BOOL bRebootAfterShutdown);
WINADVAPI BOOL APIENTRY InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,BOOL bForceAppsClosed,BOOL bRebootAfterShutdown);
#ifdef UNICODE
#define InitiateSystemShutdown InitiateSystemShutdownW
#else
#define InitiateSystemShutdown InitiateSystemShutdownA
#endif 
WINADVAPI BOOL APIENTRY AbortSystemShutdownA(LPSTR lpMachineName);
WINADVAPI BOOL APIENTRY AbortSystemShutdownW(LPWSTR lpMachineName);
#ifdef UNICODE
#define AbortSystemShutdown AbortSystemShutdownW
#else
#define AbortSystemShutdown AbortSystemShutdownA
#endif 
#include <reason.h> 
#define REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#define REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#define REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#define REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#define REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#define REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#define REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#define REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#define REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED
#define MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60) 	
WINADVAPI BOOL APIENTRY InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,BOOL bForceAppsClosed,BOOL bRebootAfterShutdown,DWORD dwReason);
WINADVAPI BOOL APIENTRY InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,BOOL bForceAppsClosed,BOOL bRebootAfterShutdown,DWORD dwReason);
#ifdef UNICODE
#define InitiateSystemShutdownEx InitiateSystemShutdownExW
#else
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#endif 
WINADVAPI LONG APIENTRY RegSaveKeyExA (HKEY hKey,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
WINADVAPI LONG APIENTRY RegSaveKeyExW (HKEY hKey,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
#ifdef UNICODE
#define RegSaveKeyEx RegSaveKeyExW
#else
#define RegSaveKeyEx RegSaveKeyExA
#endif 
WINADVAPI LONG APIENTRY Wow64Win32ApiEntry (DWORD dwFuncNumber,DWORD dwFlag,DWORD dwRes);
#endif 
