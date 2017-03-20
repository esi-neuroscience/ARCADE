#ifndef __mprapi_h__
#define __mprapi_h__
#pragma once
#include <lmcons.h>
#include <ras.h>
#define RRAS_SERVICE_NAME TEXT("RemoteAccess")
#define PID_IPX 43
#define PID_IP 33
#define PID_NBF 63
#define PID_ATALK 41
#define MAX_INTERFACE_NAME_LEN 256
#define MAX_TRANSPORT_NAME_LEN 40
#define MAX_MEDIA_NAME 16
#define MAX_PORT_NAME 16
#define MAX_DEVICE_NAME 128
#define MAX_PHONE_NUMBER_LEN 128
#define MAX_DEVICETYPE_NAME 16
typedef enum _ROUTER_INTERFACE_TYPE {
	ROUTER_IF_TYPE_CLIENT,ROUTER_IF_TYPE_HOME_ROUTER,ROUTER_IF_TYPE_FULL_ROUTER,ROUTER_IF_TYPE_DEDICATED,ROUTER_IF_TYPE_INTERNAL,ROUTER_IF_TYPE_LOOPBACK,ROUTER_IF_TYPE_TUNNEL1,ROUTER_IF_TYPE_DIALOUT
}
ROUTER_INTERFACE_TYPE;
typedef enum _ROUTER_CONNECTION_STATE {
	ROUTER_IF_STATE_UNREACHABLE,ROUTER_IF_STATE_DISCONNECTED,ROUTER_IF_STATE_CONNECTING,ROUTER_IF_STATE_CONNECTED
}
ROUTER_CONNECTION_STATE;
#define MPR_INTERFACE_OUT_OF_RESOURCES 1
#define MPR_INTERFACE_ADMIN_DISABLED 2
#define MPR_INTERFACE_CONNECTION_FAILURE 4
#define MPR_INTERFACE_SERVICE_PAUSED 8
#define MPR_INTERFACE_DIALOUT_HOURS_RESTRICTION 16
#define MPR_INTERFACE_NO_MEDIA_SENSE 32
#define MPR_INTERFACE_NO_DEVICE 64
typedef struct _MPR_INTERFACE_0 {
	 WCHAR wszInterfaceName[MAX_INTERFACE_NAME_LEN+1];
	 HANDLE hInterface;
	 BOOL fEnabled;
	 ROUTER_INTERFACE_TYPE dwIfType;
	 ROUTER_CONNECTION_STATE dwConnectionState;
	 DWORD fUnReachabilityReasons;
	 DWORD dwLastError;
}
MPR_INTERFACE_0,*PMPR_INTERFACE_0;
typedef struct _MPR_IPINIP_INTERFACE_0 {
	WCHAR wszFriendlyName[MAX_INTERFACE_NAME_LEN+1];
	GUID Guid;
}MPR_IPINIP_INTERFACE_0,*PMPR_IPINIP_INTERFACE_0;
#if(WINVER >=0x0500)
typedef struct _MPR_INTERFACE_1 {
	 WCHAR wszInterfaceName[MAX_INTERFACE_NAME_LEN+1];
	 HANDLE hInterface;
	 BOOL fEnabled;
	 ROUTER_INTERFACE_TYPE dwIfType;
	 ROUTER_CONNECTION_STATE dwConnectionState;
	 DWORD fUnReachabilityReasons;
	 DWORD dwLastError;
	 LPWSTR lpwsDialoutHoursRestriction;
}
MPR_INTERFACE_1,*PMPR_INTERFACE_1;
#define MPR_MaxDeviceType RAS_MaxDeviceType
#define MPR_MaxPhoneNumber RAS_MaxPhoneNumber
#define MPR_MaxIpAddress RAS_MaxIpAddress
#define MPR_MaxIpxAddress RAS_MaxIpxAddress
#define MPR_MaxEntryName RAS_MaxEntryName
#define MPR_MaxDeviceName RAS_MaxDeviceName
#define MPR_MaxCallbackNumber RAS_MaxCallbackNumber
#define MPR_MaxAreaCode RAS_MaxAreaCode
#define MPR_MaxPadType RAS_MaxPadType
#define MPR_MaxX25Address RAS_MaxX25Address
#define MPR_MaxFacilities RAS_MaxFacilities
#define MPR_MaxUserData RAS_MaxUserData
#define MPRIO_SpecificIpAddr RASEO_SpecificIpAddr
#define MPRIO_SpecificNameServers RASEO_SpecificNameServers
#define MPRIO_IpHeaderCompression RASEO_IpHeaderCompression
#define MPRIO_RemoteDefaultGateway RASEO_RemoteDefaultGateway
#define MPRIO_DisableLcpExtensions RASEO_DisableLcpExtensions
#define MPRIO_SwCompression RASEO_SwCompression
#define MPRIO_RequireEncryptedPw RASEO_RequireEncryptedPw
#define MPRIO_RequireMsEncryptedPw RASEO_RequireMsEncryptedPw
#define MPRIO_RequireDataEncryption RASEO_RequireDataEncryption
#define MPRIO_NetworkLogon RASEO_NetworkLogon
#define MPRIO_PromoteAlternates RASEO_PromoteAlternates
#define MPRIO_SecureLocalFiles RASEO_SecureLocalFiles
#define MPRIO_RequireEAP RASEO_RequireEAP
#define MPRIO_RequirePAP RASEO_RequirePAP
#define MPRIO_RequireSPAP RASEO_RequireSPAP
#define MPRIO_SharedPhoneNumbers RASEO_SharedPhoneNumbers
#define MPRIO_RequireCHAP RASEO_RequireCHAP
#define MPRIO_RequireMsCHAP RASEO_RequireMsCHAP
#define MPRIO_RequireMsCHAP2 RASEO_RequireMsCHAP2
#if (WINVER >=0x501)
#define MPRIO_IpSecPreSharedKey 0x80000000
#endif
#define MPRNP_Ipx RASNP_Ipx
#define MPRNP_Ip RASNP_Ip
#define MPRDT_Modem RASDT_Modem
#define MPRDT_Isdn RASDT_Isdn
#define MPRDT_X25 RASDT_X25
#define MPRDT_Vpn RASDT_Vpn
#define MPRDT_Pad RASDT_Pad
#define MPRDT_Generic RASDT_Generic
#define MPRDT_Serial 			RASDT_Serial 			
#define MPRDT_FrameRelay RASDT_FrameRelay
#define MPRDT_Atm RASDT_Atm
#define MPRDT_Sonet RASDT_Sonet
#define MPRDT_SW56 RASDT_SW56
#define MPRDT_Irda RASDT_Irda
#define MPRDT_Parallel RASDT_Parallel
#define MPRET_Phone RASET_Phone
#define MPRET_Vpn RASET_Vpn
#define MPRET_Direct RASET_Direct
#define MPRDM_DialFirst 0
#define MPRDM_DialAll RASEDM_DialAll
#define MPRDM_DialAsNeeded RASEDM_DialAsNeeded
#define MPRIDS_Disabled RASIDS_Disabled
#define MPRIDS_UseGlobalValue RASIDS_UseGlobalValue
#define MPR_ET_None ET_None 
#define MPR_ET_Require ET_Require 
#define MPR_ET_RequireMax ET_RequireMax 
#define MPR_ET_Optional ET_Optional 
#define MPR_VS_Default		VS_Default		
#define MPR_VS_PptpOnly	VS_PptpOnly	
#define MPR_VS_PptpFirst	VS_PptpFirst	
#define MPR_VS_L2tpOnly 	VS_L2tpOnly 	
#define MPR_VS_L2tpFirst	VS_L2tpFirst	
typedef struct _MPR_INTERFACE_2 {
	 WCHAR wszInterfaceName[MAX_INTERFACE_NAME_LEN+1];
	 HANDLE hInterface;
	 BOOL fEnabled;
	 ROUTER_INTERFACE_TYPE dwIfType;
	 ROUTER_CONNECTION_STATE dwConnectionState;
	 DWORD fUnReachabilityReasons;
	 DWORD dwLastError;
	DWORD dwfOptions;
	WCHAR szLocalPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
	PWCHAR szAlternates;
	DWORD ipaddr;
	DWORD ipaddrDns;
	DWORD ipaddrDnsAlt;
	DWORD ipaddrWins;
	DWORD ipaddrWinsAlt;
	DWORD dwfNetProtocols;
	WCHAR szDeviceType[ MPR_MaxDeviceType + 1 ];
	WCHAR szDeviceName[ MPR_MaxDeviceName + 1 ];
	WCHAR szX25PadType[ MPR_MaxPadType + 1 ];
	WCHAR szX25Address[ MPR_MaxX25Address + 1 ];
	WCHAR szX25Facilities[ MPR_MaxFacilities + 1 ];
	WCHAR szX25UserData[ MPR_MaxUserData + 1 ];
	DWORD dwChannels;
	DWORD dwSubEntries;
	DWORD dwDialMode;
	DWORD dwDialExtraPercent;
	DWORD dwDialExtraSampleSeconds;
	DWORD dwHangUpExtraPercent;
	DWORD dwHangUpExtraSampleSeconds;
	DWORD dwIdleDisconnectSeconds;
	DWORD dwType;
	DWORD dwEncryptionType;
	DWORD dwCustomAuthKey;
	DWORD dwCustomAuthDataSize;
	LPBYTE lpbCustomAuthData;
	GUID guidId;
	DWORD dwVpnStrategy;
} MPR_INTERFACE_2,*PMPR_INTERFACE_2;
typedef struct _MPR_DEVICE_0 {
	WCHAR szDeviceType[ MPR_MaxDeviceType + 1 ];
	WCHAR szDeviceName[ MPR_MaxDeviceName + 1 ];
}
MPR_DEVICE_0,*PMPR_DEVICE_0;
typedef struct _MPR_DEVICE_1 {
	WCHAR szDeviceType[ MPR_MaxDeviceType + 1 ];
	WCHAR szDeviceName[ MPR_MaxDeviceName + 1 ];
	WCHAR szLocalPhoneNumber[ MPR_MaxPhoneNumber + 1 ];
	PWCHAR szAlternates;
}
MPR_DEVICE_1,*PMPR_DEVICE_1;
typedef struct _MPR_CREDENTIALSEX_0 {
	DWORD dwSize;
	LPBYTE lpbCredentialsInfo;
}
MPR_CREDENTIALSEX_0,*PMPR_CREDENTIALSEX_0;
typedef struct _MPR_CREDENTIALSEX_1 {
	DWORD dwSize;
	LPBYTE lpbCredentialsInfo;
}
MPR_CREDENTIALSEX_1,*PMPR_CREDENTIALSEX_1;
#endif 
typedef struct _MPR_TRANSPORT_0 {
	 DWORD dwTransportId;
	 HANDLE hTransport;
	 WCHAR wszTransportName[MAX_TRANSPORT_NAME_LEN+1];
}
MPR_TRANSPORT_0,*PMPR_TRANSPORT_0;
typedef struct _MPR_IFTRANSPORT_0 {
	 DWORD dwTransportId;
	 HANDLE hIfTransport;
	 WCHAR wszIfTransportName[MAX_TRANSPORT_NAME_LEN+1];
}
MPR_IFTRANSPORT_0,*PMPR_IFTRANSPORT_0;
typedef struct _MPR_SERVER_0 {
	 BOOL fLanOnlyMode;
	 DWORD dwUpTime; 
	 DWORD dwTotalPorts;
	 DWORD dwPortsInUse;
}
MPR_SERVER_0,*PMPR_SERVER_0;
#if (WINVER >=0x501)
#define MPR_ENABLE_RAS_ON_DEVICE 1
#define MPR_ENABLE_ROUTING_ON_DEVICE 2
typedef struct _MPR_SERVER_1 {
	 DWORD dwNumPptpPorts;
	 DWORD dwPptpPortFlags;
	 DWORD dwNumL2tpPorts;
	 DWORD dwL2tpPortFlags;
}
MPR_SERVER_1,*PMPR_SERVER_1;
#endif
typedef enum _RAS_PORT_CONDITION {
	RAS_PORT_NON_OPERATIONAL,RAS_PORT_DISCONNECTED,	
	RAS_PORT_CALLING_BACK,RAS_PORT_LISTENING,RAS_PORT_AUTHENTICATING,RAS_PORT_AUTHENTICATED,	
RAS_PORT_INITIALIZING 
}
RAS_PORT_CONDITION;
typedef enum _RAS_HARDWARE_CONDITION {
	RAS_HARDWARE_OPERATIONAL,RAS_HARDWARE_FAILURE
}
RAS_HARDWARE_CONDITION;
typedef struct _RAS_PORT_0 {
	 HANDLE hPort;
	 HANDLE hConnection;
	 RAS_PORT_CONDITION dwPortCondition;
	 DWORD dwTotalNumberOfCalls;
	 DWORD dwConnectDuration; 
	 WCHAR wszPortName[ MAX_PORT_NAME + 1 ];
	 WCHAR wszMediaName[ MAX_MEDIA_NAME + 1 ];
	 WCHAR wszDeviceName[ MAX_DEVICE_NAME + 1 ];
	 WCHAR wszDeviceType[ MAX_DEVICETYPE_NAME + 1 ];
}
RAS_PORT_0,*PRAS_PORT_0;
typedef struct _RAS_PORT_1 {
	 HANDLE hPort;
	 HANDLE hConnection;
	 RAS_HARDWARE_CONDITION dwHardwareCondition;
	 DWORD dwLineSpeed; 
	 DWORD dwBytesXmited;
	 DWORD dwBytesRcved;
	 DWORD dwFramesXmited;
	 DWORD dwFramesRcved;
	 DWORD dwCrcErr;
	 DWORD dwTimeoutErr;
	 DWORD dwAlignmentErr;
	 DWORD dwHardwareOverrunErr;
	 DWORD dwFramingErr;
	 DWORD dwBufferOverrunErr;
	 DWORD dwCompressionRatioIn;
	 DWORD dwCompressionRatioOut;
}
RAS_PORT_1,*PRAS_PORT_1;
#define IPADDRESSLEN 15
#define IPXADDRESSLEN 22
#define ATADDRESSLEN 32
typedef struct _PPP_NBFCP_INFO {
	 DWORD dwError;
	 WCHAR wszWksta[ NETBIOS_NAME_LEN + 1 ];
}
PPP_NBFCP_INFO;
typedef struct _PPP_IPCP_INFO {
	 DWORD dwError;
	 WCHAR wszAddress[ IPADDRESSLEN + 1 ];
	 WCHAR wszRemoteAddress[ IPADDRESSLEN + 1 ];
}
PPP_IPCP_INFO;
#define PPP_IPCP_VJ 1
typedef struct _PPP_IPCP_INFO2 {
	 DWORD dwError;
	 WCHAR wszAddress[ IPADDRESSLEN + 1 ];
	 WCHAR wszRemoteAddress[ IPADDRESSLEN + 1 ];
	 DWORD dwOptions;
	 DWORD dwRemoteOptions;
}
PPP_IPCP_INFO2;
typedef struct _PPP_IPXCP_INFO {
	 DWORD dwError;
	 WCHAR wszAddress[ IPXADDRESSLEN + 1 ];
}
PPP_IPXCP_INFO;
typedef struct _PPP_ATCP_INFO {
	 DWORD dwError;
	 WCHAR wszAddress[ ATADDRESSLEN + 1 ];
}
PPP_ATCP_INFO;
typedef struct _PPP_INFO {
	 PPP_NBFCP_INFO nbf;
	 PPP_IPCP_INFO ip;
	 PPP_IPXCP_INFO ipx;
	 PPP_ATCP_INFO at;
} PPP_INFO;
#if(WINVER >=0x0500)
#define RASCCPCA_MPPC 6
#define RASCCPCA_STAC 5
#define PPP_CCP_COMPRESSION 1
#define PPP_CCP_ENCRYPTION40BITOLD 16
#define PPP_CCP_ENCRYPTION40BIT 32
#define PPP_CCP_ENCRYPTION128BIT 64
#define PPP_CCP_ENCRYPTION56BIT 128
#define PPP_CCP_HISTORYLESS 0x1000000
typedef struct _PPP_CCP_INFO {
	 DWORD dwError;
	 DWORD dwCompressionAlgorithm;
	 DWORD dwOptions;
	 DWORD dwRemoteCompressionAlgorithm;
	 DWORD dwRemoteOptions;
}
PPP_CCP_INFO;
#define PPP_LCP_PAP 0xc023
#define PPP_LCP_SPAP 0xc027
#define PPP_LCP_CHAP 0xc223
#define PPP_LCP_EAP 0xc227
#define PPP_LCP_CHAP_MD5 5
#define PPP_LCP_CHAP_MS 128
#define PPP_LCP_CHAP_MSV2 129
#define PPP_LCP_MULTILINK_FRAMING 1
#define PPP_LCP_PFC 2
#define PPP_LCP_ACFC 4
#define PPP_LCP_SSHF 8
#define PPP_LCP_DES_56 16
#define PPP_LCP_3_DES 32
typedef struct _PPP_LCP_INFO {
	 DWORD dwError;
	 DWORD dwAuthenticationProtocol;
	 DWORD dwAuthenticationData;
	 DWORD dwRemoteAuthenticationProtocol;
	 DWORD dwRemoteAuthenticationData;
	 DWORD dwTerminateReason;
	 DWORD dwRemoteTerminateReason;
	 DWORD dwOptions;
	 DWORD dwRemoteOptions;
	 DWORD dwEapTypeId;
	 DWORD dwRemoteEapTypeId;
}
PPP_LCP_INFO;
typedef struct _PPP_INFO_2 {
	 PPP_NBFCP_INFO nbf;
	 PPP_IPCP_INFO2 ip;
	 PPP_IPXCP_INFO ipx;
	 PPP_ATCP_INFO at;
	 PPP_CCP_INFO ccp;
	 PPP_LCP_INFO lcp;
}
PPP_INFO_2;
#endif 
#define RAS_FLAGS_PPP_CONNECTION 1
#define RAS_FLAGS_MESSENGER_PRESENT 2
#if(WINVER < 0x0501)
#define RAS_FLAGS_RAS_CONNECTION 4
#endif
#define RAS_FLAGS_QUARANTINE_PRESENT 8
typedef struct _RAS_CONNECTION_0 {
	 HANDLE hConnection;
	 HANDLE hInterface;
	 DWORD dwConnectDuration; 
	 ROUTER_INTERFACE_TYPE dwInterfaceType;
	 DWORD dwConnectionFlags;
	 WCHAR wszInterfaceName[ MAX_INTERFACE_NAME_LEN + 1 ];
	 WCHAR wszUserName[ UNLEN + 1 ];
	 WCHAR wszLogonDomain[ DNLEN + 1 ];
	 WCHAR wszRemoteComputer[ NETBIOS_NAME_LEN + 1 ];
}
RAS_CONNECTION_0,*PRAS_CONNECTION_0;
typedef struct _RAS_CONNECTION_1 {
	 HANDLE hConnection;
	 HANDLE hInterface;
	 PPP_INFO PppInfo;
	 DWORD dwBytesXmited;
	 DWORD dwBytesRcved;
	 DWORD dwFramesXmited;
	 DWORD dwFramesRcved;
	 DWORD dwCrcErr;
	 DWORD dwTimeoutErr;
	 DWORD dwAlignmentErr;
	 DWORD dwHardwareOverrunErr;
	 DWORD dwFramingErr;
	 DWORD dwBufferOverrunErr;
	 DWORD dwCompressionRatioIn;
	 DWORD dwCompressionRatioOut;
}
RAS_CONNECTION_1,*PRAS_CONNECTION_1;
#if(WINVER >=0x0500)
typedef struct _RAS_CONNECTION_2 {
	 HANDLE hConnection;
	 WCHAR wszUserName[ UNLEN + 1 ];
	 ROUTER_INTERFACE_TYPE dwInterfaceType;
	 GUID guid;
	 PPP_INFO_2 PppInfo2;
}
RAS_CONNECTION_2,*PRAS_CONNECTION_2;
#endif 
#define RASPRIV_NoCallback 1
#define RASPRIV_AdminSetCallback 2
#define RASPRIV_CallerSetCallback 4
#define RASPRIV_DialinPrivilege 8
#define RASPRIV2_DialinPolicy 1 
#define RASPRIV_CallbackType (RASPRIV_AdminSetCallback|RASPRIV_CallerSetCallback|RASPRIV_NoCallback)
typedef struct _RAS_USER_0 {
	 BYTE bfPrivilege;
	 WCHAR wszPhoneNumber[ MAX_PHONE_NUMBER_LEN + 1];
}
RAS_USER_0,*PRAS_USER_0;
typedef struct _RAS_USER_1 {
	 BYTE bfPrivilege;
	 WCHAR wszPhoneNumber[ MAX_PHONE_NUMBER_LEN + 1];
	 BYTE bfPrivilege2;
} 
RAS_USER_1,*PRAS_USER_1;
typedef HANDLE RAS_SERVER_HANDLE;
typedef HANDLE MPR_SERVER_HANDLE;
typedef HANDLE MIB_SERVER_HANDLE;
DWORD APIENTRY
MprAdminConnectionEnum(RAS_SERVER_HANDLE hRasServer,DWORD dwLevel,LPBYTE * lplpbBuffer,DWORD dwPrefMaxLen,LPDWORD lpdwEntriesRead,LPDWORD lpdwTotalEntries,
	 LPDWORD lpdwResumeHandle OPTIONAL);
DWORD APIENTRY
MprAdminPortEnum(RAS_SERVER_HANDLE hRasServer,DWORD dwLevel,HANDLE hConnection,LPBYTE * lplpbBuffer,DWORD dwPrefMaxLen,LPDWORD lpdwEntriesRead,LPDWORD lpdwTotalEntries,
	 LPDWORD lpdwResumeHandle OPTIONAL);
DWORD APIENTRY
MprAdminConnectionGetInfo(RAS_SERVER_HANDLE hRasServer,DWORD dwLevel,HANDLE hConnection,LPBYTE * lplpbBuffer);
DWORD APIENTRY
MprAdminPortGetInfo(RAS_SERVER_HANDLE hRasServer,DWORD dwLevel,HANDLE hPort,LPBYTE * lplpbBuffer);
DWORD APIENTRY
MprAdminConnectionClearStats(RAS_SERVER_HANDLE hRasServer,HANDLE hConnection);
DWORD APIENTRY
MprAdminPortClearStats(RAS_SERVER_HANDLE hRasServer,HANDLE hPort);
DWORD APIENTRY
MprAdminPortReset(RAS_SERVER_HANDLE hRasServer,HANDLE hPort);
DWORD APIENTRY
MprAdminPortDisconnect(RAS_SERVER_HANDLE hRasServer,HANDLE hPort);
BOOL APIENTRY
MprAdminAcceptNewConnection(RAS_CONNECTION_0 * pRasConnection0,RAS_CONNECTION_1 * pRasConnection1);
#if(WINVER >=0x0500)
BOOL APIENTRY
MprAdminAcceptNewConnection2(RAS_CONNECTION_0 * pRasConnection0,RAS_CONNECTION_1 * pRasConnection1,RAS_CONNECTION_2 * pRasConnection2);
#endif 
BOOL APIENTRY
MprAdminAcceptNewLink (RAS_PORT_0 * pRasPort0,RAS_PORT_1 * pRasPort1);
VOID APIENTRY
MprAdminConnectionHangupNotification(RAS_CONNECTION_0 * pRasConnection0,RAS_CONNECTION_1 * pRasConnection1);
#if(WINVER >=0x0500)
VOID APIENTRY
MprAdminConnectionHangupNotification2(RAS_CONNECTION_0 * pRasConnection0,RAS_CONNECTION_1 * pRasConnection1,RAS_CONNECTION_2 * pRasConnection2);
#endif 
#if (WINVER >=0x501)
DWORD APIENTRY
MprAdminConnectionRemoveQuarantine(HANDLE hRasServer,HANDLE hRasConnection,BOOL fIsIpAddress);
#endif
VOID APIENTRY
MprAdminLinkHangupNotification (RAS_PORT_0 * pRasPort0,RAS_PORT_1 * pRasPort1);
DWORD APIENTRY
MprAdminGetIpAddressForUser (WCHAR * lpwszUserName,WCHAR * lpwszPortName,DWORD * lpdwIpAddress,BOOL * bNotifyRelease);
VOID APIENTRY
MprAdminReleaseIpAddress (WCHAR * lpszUserName,WCHAR * lpszPortName,DWORD * lpdwIpAddress);
#if(WINVER >=0x0500)
DWORD APIENTRY
MprAdminInitializeDll(VOID);
DWORD APIENTRY
MprAdminTerminateDll(VOID);
#endif
DWORD APIENTRY
MprAdminUserGetInfo(const WCHAR * lpszServer,const WCHAR * lpszUser,DWORD dwLevel,LPBYTE lpbBuffer);
DWORD APIENTRY
MprAdminUserSetInfo(const WCHAR * lpszServer,const WCHAR * lpszUser,DWORD dwLevel,const LPBYTE lpbBuffer);
#if(WINVER >=0x0500)
DWORD APIENTRY
MprAdminSendUserMessage(MPR_SERVER_HANDLE hMprServer,HANDLE hConnection,LPWSTR lpwszMessage);
#endif 
DWORD APIENTRY
MprAdminGetPDCServer(const WCHAR * lpszDomain,const WCHAR * lpszServer,LPWSTR lpszPDCServer);
BOOL APIENTRY
MprAdminIsServiceRunning(LPWSTR lpwsServerName);
DWORD APIENTRY
MprAdminServerConnect(LPWSTR lpwsServerName,MPR_SERVER_HANDLE * phMprServer);
VOID APIENTRY
MprAdminServerDisconnect(MPR_SERVER_HANDLE hMprServer);
#if (WINVER >=0x501)
DWORD APIENTRY
MprAdminServerGetCredentials(MPR_SERVER_HANDLE hMprServer,DWORD dwLevel,LPBYTE * lplpbBuffer);
DWORD APIENTRY
MprAdminServerSetCredentials(MPR_SERVER_HANDLE hMprServer,DWORD dwLevel,LPBYTE lpbBuffer);
#endif
DWORD APIENTRY
MprAdminBufferFree(LPVOID pBuffer);
DWORD APIENTRY
MprAdminGetErrorString(DWORD dwError,LPWSTR * lpwsErrorString);
DWORD APIENTRY
MprAdminServerGetInfo(MPR_SERVER_HANDLE hMprServer,DWORD dwLevel,LPBYTE * lplpbBuffer);
#if (WINVER >=0x501)
DWORD APIENTRY
MprAdminServerSetInfo(MPR_SERVER_HANDLE hMprServer,DWORD dwLevel,LPBYTE lpbBuffer);
DWORD APIENTRY
MprAdminEstablishDomainRasServer (PWCHAR pszDomain,PWCHAR pszMachine,BOOL bEnable);
DWORD APIENTRY
MprAdminIsDomainRasServer (PWCHAR pszDomain,PWCHAR pszMachine,PBOOL pbIsRasServer);
#endif
#if(WINVER >=0x0500)
DWORD APIENTRY
MprAdminTransportCreate(MPR_SERVER_HANDLE hMprServer,DWORD dwTransportId,LPWSTR lpwsTransportName,LPBYTE pGlobalInfo,DWORD dwGlobalInfoSize,LPBYTE pClientInterfaceInfo,
	 DWORD dwClientInterfaceInfoSize,LPWSTR lpwsDLLPath);
#endif 
DWORD APIENTRY
MprAdminTransportSetInfo(MPR_SERVER_HANDLE hMprServer,DWORD dwTransportId,LPBYTE pGlobalInfo,DWORD dwGlobalInfoSize,LPBYTE pClientInterfaceInfo,
	 DWORD dwClientInterfaceInfoSize);
DWORD APIENTRY
MprAdminTransportGetInfo(MPR_SERVER_HANDLE hMprServer,DWORD dwTransportId,LPBYTE * ppGlobalInfo,LPDWORD lpdwGlobalInfoSize,LPBYTE * ppClientInterfaceInfo,
	 LPDWORD lpdwClientInterfaceInfoSize OPTIONAL);
#if(WINVER >=0x0500)
DWORD APIENTRY
MprAdminDeviceEnum(MPR_SERVER_HANDLE hMprServer,DWORD dwLevel,LPBYTE* lplpbBuffer,LPDWORD lpdwTotalEntries);
#endif 
DWORD APIENTRY
MprAdminInterfaceGetHandle(MPR_SERVER_HANDLE hMprServer,LPWSTR lpwsInterfaceName,HANDLE * phInterface,BOOL fIncludeClientInterfaces);
DWORD APIENTRY
MprAdminInterfaceCreate(MPR_SERVER_HANDLE hMprServer,DWORD dwLevel,LPBYTE lpbBuffer,HANDLE * phInterface);
DWORD APIENTRY
MprAdminInterfaceGetInfo(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwLevel,LPBYTE * lplpbBuffer);
DWORD APIENTRY
MprAdminInterfaceSetInfo(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwLevel,LPBYTE lpbBuffer);
DWORD APIENTRY
MprAdminInterfaceDelete(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface);
#if(WINVER >=0x0500)
DWORD APIENTRY
MprAdminInterfaceDeviceGetInfo(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwIndex,DWORD dwLevel,LPBYTE* lplpBuffer);
DWORD APIENTRY
MprAdminInterfaceDeviceSetInfo(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwIndex,DWORD dwLevel,LPBYTE lplpBuffer);
#endif 
DWORD APIENTRY
MprAdminInterfaceTransportRemove(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwTransportId);
DWORD APIENTRY
MprAdminInterfaceTransportAdd(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwTransportId,LPBYTE pInterfaceInfo,DWORD dwInterfaceInfoSize);
DWORD APIENTRY
MprAdminInterfaceTransportGetInfo(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwTransportId,LPBYTE * ppInterfaceInfo,LPDWORD lpdwpInterfaceInfoSize OPTIONAL);
DWORD APIENTRY
MprAdminInterfaceTransportSetInfo(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwTransportId,LPBYTE pInterfaceInfo,DWORD dwInterfaceInfoSize);
DWORD APIENTRY
MprAdminInterfaceEnum(MPR_SERVER_HANDLE hMprServer,DWORD dwLevel,LPBYTE * lplpbBuffer,DWORD dwPrefMaxLen,LPDWORD lpdwEntriesRead,LPDWORD lpdwTotalEntries,
	 LPDWORD lpdwResumeHandle OPTIONAL);
DWORD APIENTRY
MprSetupIpInIpInterfaceFriendlyNameEnum(PWCHAR pwszMachineName,LPBYTE* lplpBuffer,LPDWORD lpdwEntriesRead);
DWORD APIENTRY
MprSetupIpInIpInterfaceFriendlyNameFree(LPVOID lpBuffer);
DWORD APIENTRY
MprSetupIpInIpInterfaceFriendlyNameCreate(PWCHAR pwszMachineName,PMPR_IPINIP_INTERFACE_0 pNameInformation);
DWORD APIENTRY
MprSetupIpInIpInterfaceFriendlyNameDelete(PWCHAR pwszMachineName,GUID *pGuid);
DWORD APIENTRY
MprAdminInterfaceSetCredentials(LPWSTR lpwsServer,LPWSTR lpwsInterfaceName,LPWSTR lpwsUserName,LPWSTR lpwsDomainName,LPWSTR lpwsPassword OPTIONAL);
DWORD APIENTRY
MprAdminInterfaceGetCredentials(LPWSTR lpwsServer,LPWSTR lpwsInterfaceName,LPWSTR lpwsUserName,LPWSTR lpwsPassword,LPWSTR lpwsDomainName OPTIONAL);
#if(WINVER >=0x0500)
DWORD APIENTRY
MprAdminInterfaceSetCredentialsEx(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwLevel,LPBYTE lpbBuffer);
DWORD APIENTRY
MprAdminInterfaceGetCredentialsEx(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwLevel,LPBYTE * lplpbBuffer);
#endif 
DWORD APIENTRY
MprAdminInterfaceConnect(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,HANDLE hEvent,BOOL fSynchronous);
DWORD APIENTRY
MprAdminInterfaceDisconnect(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface);
DWORD APIENTRY
MprAdminInterfaceUpdateRoutes(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwProtocolId,HANDLE hEvent);
DWORD APIENTRY
MprAdminInterfaceQueryUpdateResult(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface,DWORD dwProtocolId,LPDWORD lpdwUpdateResult);
DWORD APIENTRY
MprAdminInterfaceUpdatePhonebookInfo(MPR_SERVER_HANDLE hMprServer,HANDLE hInterface);
#if(WINVER >=0x0500)
DWORD APIENTRY
MprAdminRegisterConnectionNotification(MPR_SERVER_HANDLE hMprServer,HANDLE hEventNotification);
DWORD APIENTRY
MprAdminDeregisterConnectionNotification(MPR_SERVER_HANDLE hMprServer,HANDLE hEventNotification);
#endif 
DWORD APIENTRY
MprAdminMIBServerConnect(LPWSTR lpwsServerName,MIB_SERVER_HANDLE * phMibServer);
VOID APIENTRY
MprAdminMIBServerDisconnect(MIB_SERVER_HANDLE hMibServer);
DWORD APIENTRY
MprAdminMIBEntryCreate(MIB_SERVER_HANDLE hMibServer,DWORD dwPid,DWORD dwRoutingPid,LPVOID lpEntry,DWORD dwEntrySize);
DWORD APIENTRY
MprAdminMIBEntryDelete(MIB_SERVER_HANDLE hMibServer,DWORD dwProtocolId,DWORD dwRoutingPid,LPVOID lpEntry,DWORD dwEntrySize);
DWORD APIENTRY
MprAdminMIBEntrySet(MIB_SERVER_HANDLE hMibServer,DWORD dwProtocolId,DWORD dwRoutingPid,LPVOID lpEntry,DWORD dwEntrySize);
DWORD APIENTRY
MprAdminMIBEntryGet(MIB_SERVER_HANDLE hMibServer,DWORD dwProtocolId,DWORD dwRoutingPid,LPVOID lpInEntry,DWORD dwInEntrySize,LPVOID* lplpOutEntry,LPDWORD lpOutEntrySize);
DWORD APIENTRY
MprAdminMIBEntryGetFirst(MIB_SERVER_HANDLE hMibServer,DWORD dwProtocolId,DWORD dwRoutingPid,LPVOID lpInEntry,DWORD dwInEntrySize,LPVOID* lplpOutEntry,
	 LPDWORD lpOutEntrySize);
DWORD APIENTRY
MprAdminMIBEntryGetNext(MIB_SERVER_HANDLE hMibServer,DWORD dwProtocolId,DWORD dwRoutingPid,LPVOID lpInEntry,DWORD dwInEntrySize,LPVOID* lplpOutEntry,
	 LPDWORD lpOutEntrySize);
DWORD APIENTRY
MprAdminMIBGetTrapInfo(MIB_SERVER_HANDLE hMibServer,DWORD dwProtocolId,DWORD dwRoutingPid,LPVOID lpInData,DWORD dwInDataSize,LPVOID* lplpOutData,LPDWORD lpOutDataSize);
DWORD APIENTRY
MprAdminMIBSetTrapInfo(DWORD dwProtocolId,DWORD dwRoutingPid,HANDLE hEvent,LPVOID lpInData,DWORD dwInDataSize,LPVOID* lplpOutData,LPDWORD lpOutDataSize);
DWORD APIENTRY
MprAdminMIBBufferFree(LPVOID pBuffer);
DWORD APIENTRY
MprConfigServerInstall(DWORD dwLevel,PVOID pBuffer);
DWORD APIENTRY
MprConfigServerConnect(LPWSTR lpwsServerName,HANDLE* phMprConfig);
VOID APIENTRY
MprConfigServerDisconnect(HANDLE hMprConfig);
DWORD APIENTRY
MprConfigServerRefresh(HANDLE hMprConfig);
DWORD APIENTRY
MprConfigBufferFree(LPVOID pBuffer);
DWORD APIENTRY
MprConfigServerGetInfo(HANDLE hMprConfig,DWORD dwLevel,LPBYTE * lplpbBuffer);
#if (WINVER >=0x501)
DWORD APIENTRY
MprConfigServerSetInfo(MPR_SERVER_HANDLE hMprServer,DWORD dwLevel,LPBYTE lpbBuffer);
#endif
DWORD APIENTRY
MprConfigServerBackup(HANDLE hMprConfig,LPWSTR lpwsPath);
DWORD APIENTRY
MprConfigServerRestore(HANDLE hMprConfig,LPWSTR lpwsPath);
DWORD APIENTRY
MprConfigTransportCreate(HANDLE hMprConfig,DWORD dwTransportId,LPWSTR lpwsTransportName,LPBYTE pGlobalInfo,DWORD dwGlobalInfoSize,LPBYTE pClientInterfaceInfo,
	 DWORD dwClientInterfaceInfoSize,LPWSTR lpwsDLLPath,HANDLE* phRouterTransport);
DWORD APIENTRY
MprConfigTransportDelete(HANDLE hMprConfig,HANDLE hRouterTransport);
DWORD APIENTRY
MprConfigTransportGetHandle(HANDLE hMprConfig,DWORD dwTransportId,HANDLE* phRouterTransport);
DWORD APIENTRY
MprConfigTransportSetInfo(HANDLE hMprConfig,HANDLE hRouterTransport,LPBYTE pGlobalInfo,DWORD dwGlobalInfoSize,LPBYTE pClientInterfaceInfo,
	 DWORD dwClientInterfaceInfoSize,LPWSTR lpwsDLLPath OPTIONAL);
DWORD APIENTRY
MprConfigTransportGetInfo(HANDLE hMprConfig,HANDLE hRouterTransport,LPBYTE* ppGlobalInfo,LPDWORD lpdwGlobalInfoSize,LPBYTE* ppClientInterfaceInfo,
	 LPDWORD lpdwClientInterfaceInfoSize,LPWSTR* lplpwsDLLPath OPTIONAL);
DWORD APIENTRY
MprConfigTransportEnum(HANDLE hMprConfig,DWORD dwLevel,LPBYTE* lplpBuffer,DWORD dwPrefMaxLen,LPDWORD lpdwEntriesRead,LPDWORD lpdwTotalEntries,
	 LPDWORD lpdwResumeHandle OPTIONAL);
DWORD APIENTRY
MprConfigInterfaceCreate(HANDLE hMprConfig,DWORD dwLevel,LPBYTE lpbBuffer,HANDLE* phRouterInterface);
DWORD APIENTRY
MprConfigInterfaceDelete(HANDLE hMprConfig,HANDLE hRouterInterface);
DWORD APIENTRY
MprConfigInterfaceGetHandle(HANDLE hMprConfig,LPWSTR lpwsInterfaceName,HANDLE* phRouterInterface);
DWORD APIENTRY
MprConfigInterfaceGetInfo(HANDLE hMprConfig,HANDLE hRouterInterface,DWORD dwLevel,LPBYTE* lplpBuffer,LPDWORD lpdwBufferSize);
DWORD APIENTRY
MprConfigInterfaceSetInfo(HANDLE hMprConfig,HANDLE hRouterInterface,DWORD dwLevel,LPBYTE lpbBuffer);
DWORD APIENTRY
MprConfigInterfaceEnum(HANDLE hMprConfig,DWORD dwLevel,LPBYTE* lplpBuffer,DWORD dwPrefMaxLen,LPDWORD lpdwEntriesRead,LPDWORD lpdwTotalEntries,
	 LPDWORD lpdwResumeHandle OPTIONAL);
DWORD APIENTRY
MprConfigInterfaceTransportAdd(HANDLE hMprConfig,HANDLE hRouterInterface,DWORD dwTransportId,LPWSTR lpwsTransportName,LPBYTE pInterfaceInfo,DWORD dwInterfaceInfoSize,
	 HANDLE* phRouterIfTransport);
DWORD APIENTRY
MprConfigInterfaceTransportRemove(HANDLE hMprConfig,HANDLE hRouterInterface,HANDLE hRouterIfTransport);
DWORD APIENTRY
MprConfigInterfaceTransportGetHandle(HANDLE hMprConfig,HANDLE hRouterInterface,DWORD dwTransportId,HANDLE* phRouterIfTransport);
DWORD APIENTRY
MprConfigInterfaceTransportGetInfo(HANDLE hMprConfig,HANDLE hRouterInterface,HANDLE hRouterIfTransport,LPBYTE* ppInterfaceInfo,LPDWORD lpdwInterfaceInfoSize OPTIONAL);
DWORD APIENTRY
MprConfigInterfaceTransportSetInfo(HANDLE hMprConfig,HANDLE hRouterInterface,HANDLE hRouterIfTransport,LPBYTE pInterfaceInfo,DWORD dwInterfaceInfoSize OPTIONAL);
DWORD APIENTRY
MprConfigInterfaceTransportEnum(HANDLE hMprConfig,HANDLE hRouterInterface,DWORD dwLevel,LPBYTE* lplpBuffer,DWORD dwPrefMaxLen,LPDWORD lpdwEntriesRead,
	 LPDWORD lpdwTotalEntries,LPDWORD lpdwResumeHandle OPTIONAL);
DWORD APIENTRY MprConfigGetFriendlyName(HANDLE,PWCHAR ,PWCHAR ,DWORD);
DWORD APIENTRY MprConfigGetGuidName(HANDLE ,PWCHAR ,PWCHAR,DWORD);
DWORD APIENTRY MprInfoCreate(DWORD dwVersion,LPVOID*);
DWORD APIENTRY MprInfoDelete(LPVOID);
DWORD APIENTRY MprInfoRemoveAll(LPVOID lpHeader,LPVOID* );
DWORD APIENTRY MprInfoDuplicate(LPVOID ,LPVOID*);
DWORD APIENTRY MprInfoBlockAdd(LPVOID,DWORD,DWORD,DWORD,LPBYTE,LPVOID*);
DWORD APIENTRY MprInfoBlockRemove(LPVOID,DWORD ,LPVOID*);
DWORD APIENTRY MprInfoBlockSet(LPVOID,DWORD,DWORD,DWORD,LPBYTE,LPVOID*);
DWORD APIENTRY MprInfoBlockFind(LPVOID,DWORD,LPDWORD,LPDWORD,LPBYTE*);
DWORD APIENTRY MprInfoBlockQuerySize(LPVOID lpHeader);
#define MprInfoBlockExists(h,t)(MprInfoBlockFind((h),(t),NULL,NULL,NULL)==NO_ERROR)
#endif 
