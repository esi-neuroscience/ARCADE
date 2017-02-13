#ifndef _WINSOCK2API_
#define _WINSOCK2API_
#define _WINSOCKAPI_ 
#if !defined(WIN32) && !defined(_WIN64)
#include <pshpack4.h>
#endif
#ifndef INCL_WINSOCK_API_PROTOTYPES
#define INCL_WINSOCK_API_PROTOTYPES 1
#endif
#ifndef INCL_WINSOCK_API_TYPEDEFS
#define INCL_WINSOCK_API_TYPEDEFS 0
#endif
#ifndef _INC_WINDOWS
#include <windows.h>
#endif 
#if !defined(MAKEWORD)
#define MAKEWORD(low,high)((WORD)(((BYTE)(low))|((WORD)((BYTE)(high))) << 8))
#endif
#ifndef WINSOCK_VERSION
#define WINSOCK_VERSION MAKEWORD(2,2)
#endif
#ifndef WINSOCK_API_LINKAGE
#ifdef DECLSPEC_IMPORT
#define WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#else
#define WINSOCK_API_LINKAGE
#endif
#endif
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef unsigned __int64 u_int64;
typedef UINT_PTR SOCKET;
#ifndef FD_SETSIZE
#define FD_SETSIZE 64
#endif 
typedef struct fd_set {
		u_int fd_count; 
		SOCKET fd_array[FD_SETSIZE]; 
} fd_set;
extern int PASCAL __WSAFDIsSet(SOCKET,fd_set *);
#define FD_CLR(fd,set) do { u_int __i; for (__i=0; __i < ((fd_set FAR *)(set))->fd_count ; __i++) { if (((fd_set FAR *)(set))->fd_array[__i]==fd) { while (__i < ((fd_set FAR *)(set))->fd_count-1) {((fd_set FAR *)(set))->fd_array[__i]=((fd_set FAR *)(set))->fd_array[__i+1]; __i++; }((fd_set FAR *)(set))->fd_count--; break; } } } while(0)
#define FD_SET(fd,set) do { u_int __i; for (__i=0; __i < ((fd_set FAR *)(set))->fd_count; __i++) { if (((fd_set FAR *)(set))->fd_array[__i]==(fd)) { break; } } if ((set))->fd_count) { if (((fd_set FAR *)(set))->fd_count < FD_SETSIZE) {((fd_set FAR *)(set))->fd_array[__i]=(fd);((fd_set FAR *)(set))->fd_count++; } } } while(0)
#define FD_ZERO(set) (((fd_set FAR *)(set))->fd_count=0)
#define FD_ISSET(fd,set) __WSAFDIsSet((SOCKET)(fd),(fd_set FAR *)(set))
struct timeval {
		long tv_sec; 
		long tv_usec; 
};
#define timerisset(tvp)((tvp)->tv_sec||(tvp)->tv_usec)
#define timercmp(tvp,uvp,cmp)((tvp)->tv_sec cmp (uvp)->tv_sec||(tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#define timerclear(tvp)(tvp)->tv_sec=(tvp)->tv_usec=0
#define IOCPARM_MASK 127 
#define IOC_VOID 0x20000000 
#define IOC_OUT 0x40000000 
#define IOC_IN 0x80000000 
#define IOC_INOUT (IOC_IN|IOC_OUT)
#define _IO(x,y)(IOC_VOID|((x)<<8)|(y))
#define _IOR(x,y,t)(IOC_OUT|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define _IOW(x,y,t)(IOC_IN|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define FIONREAD _IOR('f',127,u_long) 
#define FIONBIO _IOW('f',126,u_long) 
#define FIOASYNC _IOW('f',125,u_long) 
#define SIOCSHIWAT _IOW('s',0,u_long) 
#define SIOCGHIWAT _IOR('s',1,u_long) 
#define SIOCSLOWAT _IOW('s',2,u_long) 
#define SIOCGLOWAT _IOR('s',3,u_long) 
#define SIOCATMARK _IOR('s',7,u_long) 
struct hostent {
		char * h_name; 
		char * * h_aliases; 
		short h_addrtype; 
		short h_length; 
		char * * h_addr_list; 
#define h_addr h_addr_list[0] 
};
struct netent {
		char * n_name; 
		char * * n_aliases; 
		short n_addrtype; 
		u_long n_net; 
};
struct servent {
		char * s_name; 
		char * * s_aliases; 
#ifdef _WIN64
		char * s_proto; 
		short s_port; 
#else
		short s_port; 
		char * s_proto; 
#endif
};
struct protoent {
		char * p_name; 
		char * * p_aliases; 
		short p_proto; 
};
#define IPPROTO_IP 0 
#define IPPROTO_HOPOPTS 0 
#define IPPROTO_ICMP 1 
#define IPPROTO_IGMP 2 
#define IPPROTO_GGP 3 
#define IPPROTO_IPV4 4 
#define IPPROTO_TCP 6 
#define IPPROTO_PUP 12 
#define IPPROTO_UDP 17 
#define IPPROTO_IDP 22 
#define IPPROTO_IPV6 41 
#define IPPROTO_ROUTING 43 
#define IPPROTO_FRAGMENT 44 
#define IPPROTO_ESP 50 
#define IPPROTO_AH 51 
#define IPPROTO_ICMPV6 58 
#define IPPROTO_NONE 59 
#define IPPROTO_DSTOPTS 60 
#define IPPROTO_ND 77 
#define IPPROTO_ICLFXBM 78
#define IPPROTO_RAW 255 
#define IPPROTO_MAX 256
#define IPPORT_ECHO 7
#define IPPORT_DISCARD 9
#define IPPORT_SYSTAT 11
#define IPPORT_DAYTIME 13
#define IPPORT_NETSTAT 15
#define IPPORT_FTP 21
#define IPPORT_TELNET 23
#define IPPORT_SMTP 25
#define IPPORT_TIMESERVER 37
#define IPPORT_NAMESERVER 42
#define IPPORT_WHOIS 43
#define IPPORT_MTP 57
#define IPPORT_TFTP 69
#define IPPORT_RJE 77
#define IPPORT_FINGER 79
#define IPPORT_TTYLINK 87
#define IPPORT_SUPDUP 95
#define IPPORT_EXECSERVER 512
#define IPPORT_LOGINSERVER 513
#define IPPORT_CMDSERVER 514
#define IPPORT_EFSSERVER 520
#define IPPORT_BIFFUDP 512
#define IPPORT_WHOSERVER 513
#define IPPORT_ROUTESERVER 520
#define IPPORT_RESERVED 1024
#define IMPLINK_IP 155
#define IMPLINK_LOWEXPER 156
#define IMPLINK_HIGHEXPER 158
#ifndef s_addr
struct in_addr {
		union {
				struct { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
				struct { u_short s_w1,s_w2; } S_un_w;
				u_long S_addr;
		} S_un;
#define s_addr S_un.S_addr
#define s_host S_un.S_un_b.s_b2
#define s_net S_un.S_un_b.s_b1
#define s_imp S_un.S_un_w.s_w2
#define s_impno S_un.S_un_b.s_b4
#define s_lh S_un.S_un_b.s_b3
};
#endif
#define IN_CLASSA(i)(((long)(i) & 0x80000000)==0)
#define IN_CLASSA_NET 0xff000000
#define IN_CLASSA_NSHIFT 24
#define IN_CLASSA_HOST 0xffffff
#define IN_CLASSA_MAX 128
#define IN_CLASSB(i)(((long)(i) & 0xc0000000)==0x80000000)
#define IN_CLASSB_NET 0xffff0000
#define IN_CLASSB_NSHIFT 16
#define IN_CLASSB_HOST 0xffff
#define IN_CLASSB_MAX 65536
#define IN_CLASSC(i)(((long)(i) & 0xe0000000)==0xc0000000)
#define IN_CLASSC_NET 0xffffff00
#define IN_CLASSC_NSHIFT 8
#define IN_CLASSC_HOST 255
#define IN_CLASSD(i)(((long)(i) & 0xf0000000)==0xe0000000)
#define IN_CLASSD_NET 0xf0000000 
#define IN_CLASSD_NSHIFT 28 
#define IN_CLASSD_HOST 0xfffffff 
#define IN_MULTICAST(i) IN_CLASSD(i)
#define INADDR_ANY (u_long)0x00000000
#define INADDR_LOOPBACK 0x7f000001
#define INADDR_BROADCAST (u_long)0xffffffff
#define INADDR_NONE 0xffffffff
#define ADDR_ANY INADDR_ANY
struct sockaddr_in {
		short sin_family;
		u_short sin_port;
		struct in_addr sin_addr;
		char sin_zero[8];
};
#define WSADESCRIPTION_LEN 256
#define WSASYS_STATUS_LEN 128
typedef struct WSAData {
		WORD wVersion;
		WORD wHighVersion;
#ifdef _WIN64
		unsigned short iMaxSockets;
		unsigned short iMaxUdpDg;
		char * lpVendorInfo;
		char szDescription[WSADESCRIPTION_LEN+1];
		char szSystemStatus[WSASYS_STATUS_LEN+1];
#else
		char szDescription[WSADESCRIPTION_LEN+1];
		char szSystemStatus[WSASYS_STATUS_LEN+1];
		unsigned short iMaxSockets;
		unsigned short iMaxUdpDg;
		char * lpVendorInfo;
#endif
} WSADATA,* LPWSADATA;
#define INVALID_SOCKET (SOCKET)(~0)
#define SOCKET_ERROR (-1)
#define FROM_PROTOCOL_INFO (-1)
#define SOCK_STREAM 1 
#define SOCK_DGRAM 2 
#define SOCK_RAW 3 
#define SOCK_RDM 4 
#define SOCK_SEQPACKET 5 
#define SO_DEBUG 1 
#define SO_ACCEPTCONN 2 
#define SO_REUSEADDR 4 
#define SO_KEEPALIVE 8 
#define SO_DONTROUTE 16 
#define SO_BROADCAST 32 
#define SO_USELOOPBACK 64 
#define SO_LINGER 128 
#define SO_OOBINLINE 256 
#define SO_DONTLINGER (int)(~SO_LINGER)
#define SO_EXCLUSIVEADDRUSE ((int)(~SO_REUSEADDR)) 
#define SO_SNDBUF 0x1001 
#define SO_RCVBUF 0x1002 
#define SO_SNDLOWAT 0x1003 
#define SO_RCVLOWAT 0x1004 
#define SO_SNDTIMEO 0x1005 
#define SO_RCVTIMEO 0x1006 
#define SO_ERROR 0x1007 
#define SO_TYPE 0x1008 
#define SO_GROUP_ID 0x2001 
#define SO_GROUP_PRIORITY 0x2002 
#define SO_MAX_MSG_SIZE 0x2003 
#define SO_PROTOCOL_INFOA 0x2004 
#define SO_PROTOCOL_INFOW 0x2005 
#ifdef UNICODE
#define SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#else
#define SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#endif 
#define PVD_CONFIG 0x3001 
#define SO_CONDITIONAL_ACCEPT 0x3002 
#define TCP_NODELAY 1
#define AF_UNSPEC 0 
#define AF_UNIX 1 
#define AF_INET 2 
#define AF_IMPLINK 3 
#define AF_PUP 4 
#define AF_CHAOS 5 
#define AF_NS 6 
#define AF_IPX AF_NS 
#define AF_ISO 7 
#define AF_OSI AF_ISO 
#define AF_ECMA 8 
#define AF_DATAKIT 9 
#define AF_CCITT 10 
#define AF_SNA 11 
#define AF_DECnet 12 
#define AF_DLI 13 
#define AF_LAT 14 
#define AF_HYLINK 15 
#define AF_APPLETALK 16 
#define AF_NETBIOS 17 
#define AF_VOICEVIEW 18 
#define AF_FIREFOX 19 
#define AF_UNKNOWN1 20 
#define AF_BAN 21 
#define AF_ATM 22 
#define AF_INET6 23 
#define AF_CLUSTER 24 
#define AF_12844 25 
#define AF_IRDA 26 
#define AF_NETDES 28 
#define AF_TCNPROCESS 29
#define AF_TCNMESSAGE 30
#define AF_ICLFXBM 31
#define AF_MAX 32
struct sockaddr {
		u_short sa_family; 
		char sa_data[14]; 
};
#define _SS_MAXSIZE 128 
#define _SS_ALIGNSIZE (sizeof(__int64)) 
#define _SS_PAD1SIZE (_SS_ALIGNSIZE - sizeof (short))
#define _SS_PAD2SIZE (_SS_MAXSIZE - (sizeof (short) + _SS_PAD1SIZE + _SS_ALIGNSIZE))
struct sockaddr_storage {
	short ss_family; 
	char __ss_pad1[_SS_PAD1SIZE]; 
	__int64 __ss_align; 
	char __ss_pad2[_SS_PAD2SIZE]; 
};
struct sockproto {
		u_short sp_family; 
		u_short sp_protocol; 
};
#define PF_UNSPEC AF_UNSPEC
#define PF_UNIX AF_UNIX
#define PF_INET AF_INET
#define PF_IMPLINK AF_IMPLINK
#define PF_PUP AF_PUP
#define PF_CHAOS AF_CHAOS
#define PF_NS AF_NS
#define PF_IPX AF_IPX
#define PF_ISO AF_ISO
#define PF_OSI AF_OSI
#define PF_ECMA AF_ECMA
#define PF_DATAKIT AF_DATAKIT
#define PF_CCITT AF_CCITT
#define PF_SNA AF_SNA
#define PF_DECnet AF_DECnet
#define PF_DLI AF_DLI
#define PF_LAT AF_LAT
#define PF_HYLINK AF_HYLINK
#define PF_APPLETALK AF_APPLETALK
#define PF_VOICEVIEW AF_VOICEVIEW
#define PF_FIREFOX AF_FIREFOX
#define PF_UNKNOWN1 AF_UNKNOWN1
#define PF_BAN AF_BAN
#define PF_ATM AF_ATM
#define PF_INET6 AF_INET6
#define PF_MAX AF_MAX
struct linger {
		u_short l_onoff; 
		u_short l_linger; 
};
#define SOL_SOCKET 0xffff 
#define SOMAXCONN 0x7fffffff
#define MSG_OOB 1 
#define MSG_PEEK 2 
#define MSG_DONTROUTE 4 
#define MSG_WAITALL 8 
#define MSG_PARTIAL 0x8000 
#define MSG_INTERRUPT 16 
#define MSG_MAXIOVLEN 16
#define MAXGETHOSTSTRUCT 1024
#define FD_READ_BIT 0
#define FD_READ (1 << FD_READ_BIT)
#define FD_WRITE_BIT 1
#define FD_WRITE (1 << FD_WRITE_BIT)
#define FD_OOB_BIT 2
#define FD_OOB (1 << FD_OOB_BIT)
#define FD_ACCEPT_BIT 3
#define FD_ACCEPT (1 << FD_ACCEPT_BIT)
#define FD_CONNECT_BIT 4
#define FD_CONNECT (1 << FD_CONNECT_BIT)
#define FD_CLOSE_BIT 5
#define FD_CLOSE (1 << FD_CLOSE_BIT)
#define FD_QOS_BIT 6
#define FD_QOS (1 << FD_QOS_BIT)
#define FD_GROUP_QOS_BIT 7
#define FD_GROUP_QOS (1 << FD_GROUP_QOS_BIT)
#define FD_ROUTING_INTERFACE_CHANGE_BIT 8
#define FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)
#define FD_ADDRESS_LIST_CHANGE_BIT 9
#define FD_ADDRESS_LIST_CHANGE (1 << FD_ADDRESS_LIST_CHANGE_BIT)
#define FD_MAX_EVENTS 10
#define FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)
#ifndef WSABASEERR
#define WSABASEERR 10000
#define WSAEINTR (WSABASEERR+4)
#define WSAEBADF (WSABASEERR+9)
#define WSAEACCES (WSABASEERR+13)
#define WSAEFAULT (WSABASEERR+14)
#define WSAEINVAL (WSABASEERR+22)
#define WSAEMFILE (WSABASEERR+24)
#define WSAEWOULDBLOCK (WSABASEERR+35)
#define WSAEINPROGRESS (WSABASEERR+36)
#define WSAEALREADY (WSABASEERR+37)
#define WSAENOTSOCK (WSABASEERR+38)
#define WSAEDESTADDRREQ (WSABASEERR+39)
#define WSAEMSGSIZE (WSABASEERR+40)
#define WSAEPROTOTYPE (WSABASEERR+41)
#define WSAENOPROTOOPT (WSABASEERR+42)
#define WSAEPROTONOSUPPORT (WSABASEERR+43)
#define WSAESOCKTNOSUPPORT (WSABASEERR+44)
#define WSAEOPNOTSUPP (WSABASEERR+45)
#define WSAEPFNOSUPPORT (WSABASEERR+46)
#define WSAEAFNOSUPPORT (WSABASEERR+47)
#define WSAEADDRINUSE (WSABASEERR+48)
#define WSAEADDRNOTAVAIL (WSABASEERR+49)
#define WSAENETDOWN (WSABASEERR+50)
#define WSAENETUNREACH (WSABASEERR+51)
#define WSAENETRESET (WSABASEERR+52)
#define WSAECONNABORTED (WSABASEERR+53)
#define WSAECONNRESET (WSABASEERR+54)
#define WSAENOBUFS (WSABASEERR+55)
#define WSAEISCONN (WSABASEERR+56)
#define WSAENOTCONN (WSABASEERR+57)
#define WSAESHUTDOWN (WSABASEERR+58)
#define WSAETOOMANYREFS (WSABASEERR+59)
#define WSAETIMEDOUT (WSABASEERR+60)
#define WSAECONNREFUSED (WSABASEERR+61)
#define WSAELOOP (WSABASEERR+62)
#define WSAENAMETOOLONG (WSABASEERR+63)
#define WSAEHOSTDOWN (WSABASEERR+64)
#define WSAEHOSTUNREACH (WSABASEERR+65)
#define WSAENOTEMPTY (WSABASEERR+66)
#define WSAEPROCLIM (WSABASEERR+67)
#define WSAEUSERS (WSABASEERR+68)
#define WSAEDQUOT (WSABASEERR+69)
#define WSAESTALE (WSABASEERR+70)
#define WSAEREMOTE (WSABASEERR+71)
#define WSASYSNOTREADY (WSABASEERR+91)
#define WSAVERNOTSUPPORTED (WSABASEERR+92)
#define WSANOTINITIALISED (WSABASEERR+93)
#define WSAEDISCON (WSABASEERR+101)
#define WSAENOMORE (WSABASEERR+102)
#define WSAECANCELLED (WSABASEERR+103)
#define WSAEINVALIDPROCTABLE (WSABASEERR+104)
#define WSAEINVALIDPROVIDER (WSABASEERR+105)
#define WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#define WSASYSCALLFAILURE (WSABASEERR+107)
#define WSASERVICE_NOT_FOUND (WSABASEERR+108)
#define WSATYPE_NOT_FOUND (WSABASEERR+109)
#define WSA_E_NO_MORE (WSABASEERR+110)
#define WSA_E_CANCELLED (WSABASEERR+111)
#define WSAEREFUSED (WSABASEERR+112)
#define WSAHOST_NOT_FOUND (WSABASEERR+1001)
#define WSATRY_AGAIN (WSABASEERR+1002)
#define WSANO_RECOVERY (WSABASEERR+1003)
#define WSANO_DATA (WSABASEERR+1004)
#define WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#define WSA_QOS_SENDERS (WSABASEERR + 1006)
#define WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#define WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#define WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#define WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#define WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#define WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#define WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#define WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#define WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#define WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#define WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#define WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#define WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#define WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#define WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#define WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#define WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#define WSA_QOS_EUNKOWNPSOBJ (WSABASEERR + 1024)
#define WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#define WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#define WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#define WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#define WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#define WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#define WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#endif 
#define h_errno WSAGetLastError()
#define HOST_NOT_FOUND WSAHOST_NOT_FOUND
#define TRY_AGAIN WSATRY_AGAIN
#define NO_RECOVERY WSANO_RECOVERY
#define NO_DATA WSANO_DATA
#define WSANO_ADDRESS WSANO_DATA
#define NO_ADDRESS WSANO_ADDRESS
#if 0
#define EWOULDBLOCK WSAEWOULDBLOCK
#define EINPROGRESS WSAEINPROGRESS
#define EALREADY WSAEALREADY
#define ENOTSOCK WSAENOTSOCK
#define EDESTADDRREQ WSAEDESTADDRREQ
#define EMSGSIZE WSAEMSGSIZE
#define EPROTOTYPE WSAEPROTOTYPE
#define ENOPROTOOPT WSAENOPROTOOPT
#define EPROTONOSUPPORT WSAEPROTONOSUPPORT
#define ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#define EOPNOTSUPP WSAEOPNOTSUPP
#define EPFNOSUPPORT WSAEPFNOSUPPORT
#define EAFNOSUPPORT WSAEAFNOSUPPORT
#define EADDRINUSE WSAEADDRINUSE
#define EADDRNOTAVAIL WSAEADDRNOTAVAIL
#define ENETDOWN WSAENETDOWN
#define ENETUNREACH WSAENETUNREACH
#define ENETRESET WSAENETRESET
#define ECONNABORTED WSAECONNABORTED
#define ECONNRESET WSAECONNRESET
#define ENOBUFS WSAENOBUFS
#define EISCONN WSAEISCONN
#define ENOTCONN WSAENOTCONN
#define ESHUTDOWN WSAESHUTDOWN
#define ETOOMANYREFS WSAETOOMANYREFS
#define ETIMEDOUT WSAETIMEDOUT
#define ECONNREFUSED WSAECONNREFUSED
#define ELOOP WSAELOOP
#define ENAMETOOLONG WSAENAMETOOLONG
#define EHOSTDOWN WSAEHOSTDOWN
#define EHOSTUNREACH WSAEHOSTUNREACH
#define ENOTEMPTY WSAENOTEMPTY
#define EPROCLIM WSAEPROCLIM
#define EUSERS WSAEUSERS
#define EDQUOT WSAEDQUOT
#define ESTALE WSAESTALE
#define EREMOTE WSAEREMOTE
#endif
#ifdef WIN32
#define WSAAPI FAR PASCAL
#define WSAEVENT HANDLE
#define LPWSAEVENT LPHANDLE
#define WSAOVERLAPPED OVERLAPPED
typedef struct _OVERLAPPED * LPWSAOVERLAPPED;
#define WSA_IO_PENDING (ERROR_IO_PENDING)
#define WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#define WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#define WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#define WSA_NOT_ENOUGH_MEMORY (ERROR_NOT_ENOUGH_MEMORY)
#define WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)
#define WSA_INVALID_EVENT ((WSAEVENT)NULL)
#define WSA_MAXIMUM_WAIT_EVENTS (MAXIMUM_WAIT_OBJECTS)
#define WSA_WAIT_FAILED (WAIT_FAILED)
#define WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#define WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#define WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#define WSA_INFINITE (INFINITE)
#else 
#define WSAAPI FAR PASCAL
typedef DWORD WSAEVENT,* LPWSAEVENT;
typedef struct _WSAOVERLAPPED {
	DWORD Internal;
	DWORD InternalHigh;
	DWORD Offset;
	DWORD OffsetHigh;
	WSAEVENT hEvent;
} WSAOVERLAPPED,* LPWSAOVERLAPPED;
#define WSA_IO_PENDING (WSAEWOULDBLOCK)
#define WSA_IO_INCOMPLETE (WSAEWOULDBLOCK)
#define WSA_INVALID_HANDLE (WSAENOTSOCK)
#define WSA_INVALID_PARAMETER (WSAEINVAL)
#define WSA_NOT_ENOUGH_MEMORY (WSAENOBUFS)
#define WSA_OPERATION_ABORTED (WSAEINTR)
#define WSA_INVALID_EVENT ((WSAEVENT)NULL)
#define WSA_MAXIMUM_WAIT_EVENTS (MAXIMUM_WAIT_OBJECTS)
#define WSA_WAIT_FAILED ((DWORD)-1L)
#define WSA_WAIT_EVENT_0 ((DWORD)0)
#define WSA_WAIT_TIMEOUT ((DWORD)0x102L)
#define WSA_INFINITE ((DWORD)-1L)
#endif 
typedef struct _WSABUF {
	u_long len; 
	char * buf; 
} WSABUF,* LPWSABUF;
#include <qos.h>
typedef struct _QualityOfService {
	FLOWSPEC SendingFlowspec; 
	FLOWSPEC ReceivingFlowspec; 
	WSABUF ProviderSpecific; 
} QOS,* LPQOS;
#define CF_ACCEPT 0
#define CF_REJECT 1
#define CF_DEFER 2
#define SD_RECEIVE 0
#define SD_SEND 1
#define SD_BOTH 2
typedef unsigned int GROUP;
#define SG_UNCONSTRAINED_GROUP 1
#define SG_CONSTRAINED_GROUP 2
typedef struct _WSANETWORKEVENTS {
	 long lNetworkEvents;
	 int iErrorCode[FD_MAX_EVENTS];
} WSANETWORKEVENTS,* LPWSANETWORKEVENTS;
#ifndef GUID_DEFINED
#include <guiddef.h>
#endif 
#define MAX_PROTOCOL_CHAIN 7
#define BASE_PROTOCOL 1
#define LAYERED_PROTOCOL 0
typedef struct _WSAPROTOCOLCHAIN {
	int ChainLen; 
	DWORD ChainEntries[MAX_PROTOCOL_CHAIN]; 
} WSAPROTOCOLCHAIN,* LPWSAPROTOCOLCHAIN;
#define WSAPROTOCOL_LEN 255
typedef struct _WSAPROTOCOL_INFOA {
	DWORD dwServiceFlags1;
	DWORD dwServiceFlags2;
	DWORD dwServiceFlags3;
	DWORD dwServiceFlags4;
	DWORD dwProviderFlags;
	GUID ProviderId;
	DWORD dwCatalogEntryId;
	WSAPROTOCOLCHAIN ProtocolChain;
	int iVersion;
	int iAddressFamily;
	int iMaxSockAddr;
	int iMinSockAddr;
	int iSocketType;
	int iProtocol;
	int iProtocolMaxOffset;
	int iNetworkByteOrder;
	int iSecurityScheme;
	DWORD dwMessageSize;
	DWORD dwProviderReserved;
	CHAR szProtocol[WSAPROTOCOL_LEN+1];
} WSAPROTOCOL_INFOA,* LPWSAPROTOCOL_INFOA;
typedef struct _WSAPROTOCOL_INFOW {
	DWORD dwServiceFlags1;
	DWORD dwServiceFlags2;
	DWORD dwServiceFlags3;
	DWORD dwServiceFlags4;
	DWORD dwProviderFlags;
	GUID ProviderId;
	DWORD dwCatalogEntryId;
	WSAPROTOCOLCHAIN ProtocolChain;
	int iVersion;
	int iAddressFamily;
	int iMaxSockAddr;
	int iMinSockAddr;
	int iSocketType;
	int iProtocol;
	int iProtocolMaxOffset;
	int iNetworkByteOrder;
	int iSecurityScheme;
	DWORD dwMessageSize;
	DWORD dwProviderReserved;
	WCHAR szProtocol[WSAPROTOCOL_LEN+1];
} WSAPROTOCOL_INFOW,* LPWSAPROTOCOL_INFOW;
#ifdef UNICODE
typedef WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
typedef LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#else
typedef WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
typedef LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#endif 
#define PFL_MULTIPLE_PROTO_ENTRIES 1
#define PFL_RECOMMENDED_PROTO_ENTRY 2
#define PFL_HIDDEN 4
#define PFL_MATCHES_PROTOCOL_ZERO 8
#define XP1_CONNECTIONLESS 1
#define XP1_GUARANTEED_DELIVERY 2
#define XP1_GUARANTEED_ORDER 4
#define XP1_MESSAGE_ORIENTED 8
#define XP1_PSEUDO_STREAM 16
#define XP1_GRACEFUL_CLOSE 32
#define XP1_EXPEDITED_DATA 64
#define XP1_CONNECT_DATA 128
#define XP1_DISCONNECT_DATA 256
#define XP1_SUPPORT_BROADCAST 512
#define XP1_SUPPORT_MULTIPOINT 1024
#define XP1_MULTIPOINT_CONTROL_PLANE 2048
#define XP1_MULTIPOINT_DATA_PLANE 0x1000
#define XP1_QOS_SUPPORTED 0x2000
#define XP1_INTERRUPT 0x4000
#define XP1_UNI_SEND 0x8000
#define XP1_UNI_RECV 0x10000
#define XP1_IFS_HANDLES 0x20000
#define XP1_PARTIAL_MESSAGE 0x40000
#define BIGENDIAN 0
#define LITTLEENDIAN 1
#define SECURITY_PROTOCOL_NONE 0
#define JL_SENDER_ONLY 1
#define JL_RECEIVER_ONLY 2
#define JL_BOTH 4
#define WSA_FLAG_OVERLAPPED 1
#define WSA_FLAG_MULTIPOINT_C_ROOT 2
#define WSA_FLAG_MULTIPOINT_C_LEAF 4
#define WSA_FLAG_MULTIPOINT_D_ROOT 8
#define WSA_FLAG_MULTIPOINT_D_LEAF 16
#define IOC_UNIX 0
#define IOC_WS2 0x8000000
#define IOC_PROTOCOL 0x10000000
#define IOC_VENDOR 0x18000000
#define _WSAIO(x,y)(IOC_VOID|(x)|(y))
#define _WSAIOR(x,y)(IOC_OUT|(x)|(y))
#define _WSAIOW(x,y)(IOC_IN|(x)|(y))
#define _WSAIORW(x,y)(IOC_INOUT|(x)|(y))
#define SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#define SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#define SIO_FIND_ROUTE _WSAIOR(IOC_WS2,3)
#define SIO_FLUSH _WSAIO(IOC_WS2,4)
#define SIO_GET_BROADCAST_ADDRESS _WSAIOR(IOC_WS2,5)
#define SIO_GET_EXTENSION_FUNCTION_POINTER _WSAIORW(IOC_WS2,6)
#define SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#define SIO_GET_GROUP_QOS _WSAIORW(IOC_WS2,8)
#define SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#define SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#define SIO_SET_QOS _WSAIOW(IOC_WS2,11)
#define SIO_SET_GROUP_QOS _WSAIOW(IOC_WS2,12)
#define SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#define SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#define SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#define SIO_ADDRESS_LIST_QUERY _WSAIOR(IOC_WS2,22)
#define SIO_ADDRESS_LIST_CHANGE _WSAIO(IOC_WS2,23)
#define SIO_QUERY_TARGET_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#define SIO_ADDRESS_LIST_SORT _WSAIORW(IOC_WS2,25)
typedef int 
(CALLBACK * LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lpCallerData,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lpCalleeData,GROUP * g,DWORD_PTR dwCallbackData);
typedef void 
(CALLBACK * LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);
#define SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)
typedef enum _WSACOMPLETIONTYPE {
	NSP_NOTIFY_IMMEDIATELY=0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_PORT,NSP_NOTIFY_APC,} WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,* LPWSACOMPLETIONTYPE;
typedef struct _WSACOMPLETION {
	WSACOMPLETIONTYPE Type;
	union {
		struct {
			HWND hWnd;
			UINT uMsg;
			WPARAM context;
		} WindowMessage;
		struct {
			LPWSAOVERLAPPED lpOverlapped;
		} Event;
		struct {
			LPWSAOVERLAPPED lpOverlapped;
			LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
		} Apc;
		struct {
			LPWSAOVERLAPPED lpOverlapped;
			HANDLE hPort;
			ULONG_PTR Key;
		} Port;
	} Parameters;
} WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;
#define TH_NETDEV 1
#define TH_TAPI 2
typedef struct sockaddr SOCKADDR;
typedef struct sockaddr *PSOCKADDR;
typedef struct sockaddr *LPSOCKADDR;
typedef struct sockaddr_storage SOCKADDR_STORAGE;
typedef struct sockaddr_storage *PSOCKADDR_STORAGE;
typedef struct sockaddr_storage *LPSOCKADDR_STORAGE;
#ifndef _tagBLOB_DEFINED
#define _tagBLOB_DEFINED
#define _BLOB_DEFINED
#define _LPBLOB_DEFINED
typedef struct _BLOB {
	ULONG cbSize ;
#ifdef MIDL_PASS
	[size_is(cbSize)] BYTE *pBlobData;
#else 
	BYTE *pBlobData ;
#endif 
} BLOB,*LPBLOB ;
#endif
#define SERVICE_MULTIPLE 1
#define NS_ALL (0)
#define NS_SAP (1)
#define NS_NDS (2)
#define NS_PEER_BROWSE (3)
#define NS_SLP (5)
#define NS_DHCP (6)
#define NS_TCPIP_LOCAL (10)
#define NS_TCPIP_HOSTS (11)
#define NS_DNS (12)
#define NS_NETBT (13)
#define NS_WINS (14)
#define NS_NLA (15) 
#define NS_NBP (20)
#define NS_MS (30)
#define NS_STDA (31)
#define NS_NTDS (32)
#define NS_X500 (40)
#define NS_NIS (41)
#define NS_NISPLUS (42)
#define NS_WRQ (50)
#define NS_NETDES (60) 
#define RES_UNUSED_1 1
#define RES_FLUSH_CACHE 2
#ifndef RES_SERVICE
#define RES_SERVICE 4
#endif 
#define SERVICE_TYPE_VALUE_IPXPORTA "IpxSocket"
#define SERVICE_TYPE_VALUE_IPXPORTW L"IpxSocket"
#define SERVICE_TYPE_VALUE_SAPIDA "SapId"
#define SERVICE_TYPE_VALUE_SAPIDW L"SapId"
#define SERVICE_TYPE_VALUE_TCPPORTA "TcpPort"
#define SERVICE_TYPE_VALUE_TCPPORTW L"TcpPort"
#define SERVICE_TYPE_VALUE_UDPPORTA "UdpPort"
#define SERVICE_TYPE_VALUE_UDPPORTW L"UdpPort"
#define SERVICE_TYPE_VALUE_OBJECTIDA "ObjectId"
#define SERVICE_TYPE_VALUE_OBJECTIDW L"ObjectId"
#ifdef UNICODE
#define SERVICE_TYPE_VALUE_SAPID SERVICE_TYPE_VALUE_SAPIDW
#define SERVICE_TYPE_VALUE_TCPPORT SERVICE_TYPE_VALUE_TCPPORTW
#define SERVICE_TYPE_VALUE_UDPPORT SERVICE_TYPE_VALUE_UDPPORTW
#define SERVICE_TYPE_VALUE_OBJECTID SERVICE_TYPE_VALUE_OBJECTIDW
#else 
#define SERVICE_TYPE_VALUE_SAPID SERVICE_TYPE_VALUE_SAPIDA
#define SERVICE_TYPE_VALUE_TCPPORT SERVICE_TYPE_VALUE_TCPPORTA
#define SERVICE_TYPE_VALUE_UDPPORT SERVICE_TYPE_VALUE_UDPPORTA
#define SERVICE_TYPE_VALUE_OBJECTID SERVICE_TYPE_VALUE_OBJECTIDA
#endif
#ifndef __CSADDR_DEFINED__
#define __CSADDR_DEFINED__
typedef struct _SOCKET_ADDRESS {
	LPSOCKADDR lpSockaddr ;
	INT iSockaddrLength ;
} SOCKET_ADDRESS,*PSOCKET_ADDRESS,* LPSOCKET_ADDRESS ;
typedef struct _CSADDR_INFO {
	SOCKET_ADDRESS LocalAddr ;
	SOCKET_ADDRESS RemoteAddr ;
	INT iSocketType ;
	INT iProtocol ;
} CSADDR_INFO,*PCSADDR_INFO,* LPCSADDR_INFO ;
#endif 
typedef struct _SOCKET_ADDRESS_LIST {
	INT iAddressCount;
	SOCKET_ADDRESS Address[1];
} SOCKET_ADDRESS_LIST,* LPSOCKET_ADDRESS_LIST;
typedef struct _AFPROTOCOLS {
	INT iAddressFamily;
	INT iProtocol;
} AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;
typedef enum _WSAEcomparator {
	COMP_EQUAL=0,COMP_NOTLESS
} WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;
typedef struct _WSAVersion {
	DWORD dwVersion;
	WSAECOMPARATOR ecHow;
}WSAVERSION,*PWSAVERSION,*LPWSAVERSION;
typedef struct _WSAQuerySetA {
	DWORD dwSize;
	LPSTR lpszServiceInstanceName;
	LPGUID lpServiceClassId;
	LPWSAVERSION lpVersion;
	LPSTR lpszComment;
	DWORD dwNameSpace;
	LPGUID lpNSProviderId;
	LPSTR lpszContext;
	DWORD dwNumberOfProtocols;
	LPAFPROTOCOLS lpafpProtocols;
	LPSTR lpszQueryString;
	DWORD dwNumberOfCsAddrs;
	LPCSADDR_INFO lpcsaBuffer;
	DWORD dwOutputFlags;
	LPBLOB lpBlob;
} WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;
typedef struct _WSAQuerySetW {
	DWORD dwSize;
	LPWSTR lpszServiceInstanceName;
	LPGUID lpServiceClassId;
	LPWSAVERSION lpVersion;
	LPWSTR lpszComment;
	DWORD dwNameSpace;
	LPGUID lpNSProviderId;
	LPWSTR lpszContext;
	DWORD dwNumberOfProtocols;
	LPAFPROTOCOLS lpafpProtocols;
	LPWSTR lpszQueryString;
	DWORD dwNumberOfCsAddrs;
	LPCSADDR_INFO lpcsaBuffer;
	DWORD dwOutputFlags;
	LPBLOB lpBlob;
} WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;
#ifdef UNICODE
typedef WSAQUERYSETW WSAQUERYSET;
typedef PWSAQUERYSETW PWSAQUERYSET;
typedef LPWSAQUERYSETW LPWSAQUERYSET;
#else
typedef WSAQUERYSETA WSAQUERYSET;
typedef PWSAQUERYSETA PWSAQUERYSET;
typedef LPWSAQUERYSETA LPWSAQUERYSET;
#endif 
#define LUP_DEEP 1
#define LUP_CONTAINERS 2
#define LUP_NOCONTAINERS 4
#define LUP_NEAREST 8
#define LUP_RETURN_NAME 16
#define LUP_RETURN_TYPE 32
#define LUP_RETURN_VERSION 64
#define LUP_RETURN_COMMENT 128
#define LUP_RETURN_ADDR 256
#define LUP_RETURN_BLOB 512
#define LUP_RETURN_ALIASES 1024
#define LUP_RETURN_QUERY_STRING 2048
#define LUP_RETURN_ALL 4080
#define LUP_RES_SERVICE 0x8000
#define LUP_FLUSHCACHE 0x1000
#define LUP_FLUSHPREVIOUS 0x2000
#define RESULT_IS_ALIAS 1
#define RESULT_IS_ADDED 16
#define RESULT_IS_CHANGED 32
#define RESULT_IS_DELETED 64
typedef enum _WSAESETSERVICEOP {
	RNRSERVICE_REGISTER=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
} WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;
typedef struct _WSANSClassInfoA {
	LPSTR lpszName;
	DWORD dwNameSpace;
	DWORD dwValueType;
	DWORD dwValueSize;
	LPVOID lpValue;
}WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;
typedef struct _WSANSClassInfoW {
	LPWSTR lpszName;
	DWORD dwNameSpace;
	DWORD dwValueType;
	DWORD dwValueSize;
	LPVOID lpValue;
}WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;
#ifdef UNICODE
typedef WSANSCLASSINFOW WSANSCLASSINFO;
typedef PWSANSCLASSINFOW PWSANSCLASSINFO;
typedef LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#else
typedef WSANSCLASSINFOA WSANSCLASSINFO;
typedef PWSANSCLASSINFOA PWSANSCLASSINFO;
typedef LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#endif 
typedef struct _WSAServiceClassInfoA {
	LPGUID lpServiceClassId;
	LPSTR lpszServiceClassName;
	DWORD dwCount;
	LPWSANSCLASSINFOA lpClassInfos;
}WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;
typedef struct _WSAServiceClassInfoW {
	LPGUID lpServiceClassId;
	LPWSTR lpszServiceClassName;
	DWORD dwCount;
	LPWSANSCLASSINFOW lpClassInfos;
}WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;
#ifdef UNICODE
typedef WSASERVICECLASSINFOW WSASERVICECLASSINFO;
typedef PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
typedef LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#else
typedef WSASERVICECLASSINFOA WSASERVICECLASSINFO;
typedef PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
typedef LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#endif 
typedef struct _WSANAMESPACE_INFOA {
	GUID NSProviderId;
	DWORD dwNameSpace;
	BOOL fActive;
	DWORD dwVersion;
	LPSTR lpszIdentifier;
} WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;
typedef struct _WSANAMESPACE_INFOW {
	GUID NSProviderId;
	DWORD dwNameSpace;
	BOOL fActive;
	DWORD dwVersion;
	LPWSTR lpszIdentifier;
} WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;
#ifdef UNICODE
typedef WSANAMESPACE_INFOW WSANAMESPACE_INFO;
typedef PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
typedef LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#else
typedef WSANAMESPACE_INFOA WSANAMESPACE_INFO;
typedef PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
typedef LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,struct sockaddr * addr,int * addrlen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef SOCKET 
(WSAAPI * LPFN_ACCEPT)(SOCKET s,struct sockaddr * addr,int * addrlen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI bind(SOCKET s,const struct sockaddr * name,int namelen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_BIND)(SOCKET s,const struct sockaddr * name,int namelen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI closesocket(SOCKET s);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_CLOSESOCKET)(SOCKET s);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI connect(SOCKET s,const struct sockaddr * name,int namelen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_CONNECT)(SOCKET s,const struct sockaddr * name,int namelen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI ioctlsocket(SOCKET s,long cmd,u_long * argp);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_IOCTLSOCKET)(SOCKET s,long cmd,u_long * argp);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI getpeername(SOCKET s,struct sockaddr * name,int * namelen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_GETPEERNAME)(SOCKET s,struct sockaddr * name,int * namelen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI getsockname(SOCKET s,struct sockaddr * name,int * namelen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_GETSOCKNAME)(SOCKET s,struct sockaddr * name,int * namelen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI getsockopt(SOCKET s,int level,int optname,char * optval,int * optlen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_GETSOCKOPT)(SOCKET s,int level,int optname,char * optval,int * optlen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef u_long 
(WSAAPI * LPFN_HTONL)(u_long hostlong);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef u_short 
(WSAAPI * LPFN_HTONS)(u_short hostshort);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE unsigned long
WSAAPI inet_addr(const char * cp);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef unsigned long
(WSAAPI * LPFN_INET_ADDR)(const char * cp);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE char *
WSAAPI inet_ntoa(struct in_addr in);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef char *
(WSAAPI * LPFN_INET_NTOA)(struct in_addr in);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI listen(SOCKET s,int backlog);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_LISTEN)(SOCKET s,int backlog);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef u_long 
(WSAAPI * LPFN_NTOHL)(u_long netlong);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef u_short 
(WSAAPI * LPFN_NTOHS)(u_short netshort);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI recv(SOCKET s,char * buf,int len,int flags);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_RECV)(SOCKET s,char * buf,int len,int flags);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI recvfrom(SOCKET s,char * buf,int len,int flags,struct sockaddr * from,int * fromlen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_RECVFROM)(SOCKET s,char * buf,int len,int flags,struct sockaddr * from,int * fromlen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI select(int nfds,fd_set * readfds,fd_set * writefds,fd_set *exceptfds,const struct timeval * timeout);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_SELECT)(int nfds,fd_set * readfds,fd_set * writefds,fd_set *exceptfds,const struct timeval * timeout);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI send(SOCKET s,const char * buf,int len,int flags);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_SEND)(SOCKET s,const char * buf,int len,int flags);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI sendto(SOCKET s,const char * buf,int len,int flags,const struct sockaddr * to,int tolen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_SENDTO)(SOCKET s,const char * buf,int len,int flags,const struct sockaddr * to,int tolen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI setsockopt(SOCKET s,int level,int optname,const char * optval,int optlen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_SETSOCKOPT)(SOCKET s,int level,int optname,const char * optval,int optlen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI shutdown(SOCKET s,int how);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_SHUTDOWN)(SOCKET s,int how);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE SOCKET WSAAPI socket(int af,int type,int protocol);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef SOCKET 
(WSAAPI * LPFN_SOCKET)(int af,int type,int protocol);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE struct hostent *
WSAAPI gethostbyaddr(const char * addr,int len,int type);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef struct hostent *
(WSAAPI * LPFN_GETHOSTBYADDR)(const char * addr,int len,int type);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE struct hostent *
WSAAPI gethostbyname(const char * name);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef struct hostent *
(WSAAPI * LPFN_GETHOSTBYNAME)(const char * name);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI gethostname(char * name,int namelen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_GETHOSTNAME)(char * name,int namelen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE struct servent *
WSAAPI getservbyport(int port,const char * proto);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef struct servent *
(WSAAPI * LPFN_GETSERVBYPORT)(int port,const char * proto);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE struct servent *
WSAAPI getservbyname(const char * name,const char * proto);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef struct servent *
(WSAAPI * LPFN_GETSERVBYNAME)(const char * name,const char * proto);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE struct protoent *
WSAAPI getprotobynumber(int number);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef struct protoent *
(WSAAPI * LPFN_GETPROTOBYNUMBER)(int number);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE struct protoent *
WSAAPI getprotobyname(const char * name);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef struct protoent *
(WSAAPI * LPFN_GETPROTOBYNAME)(const char * name);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAStartup(WORD wVersionRequested,LPWSADATA lpWSAData);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSASTARTUP)(WORD wVersionRequested,LPWSADATA lpWSAData);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSACleanup(void);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSACLEANUP)(void);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE void WSAAPI WSASetLastError(int iError);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef void 
(WSAAPI * LPFN_WSASETLASTERROR)(int iError);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAGetLastError(void);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAGETLASTERROR)(void);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE BOOL WSAAPI WSAIsBlocking(void);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef BOOL 
(WSAAPI * LPFN_WSAISBLOCKING)(void);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAUnhookBlockingHook(void);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAUNHOOKBLOCKINGHOOK)(void);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lpBlockFunc);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef FARPROC 
(WSAAPI * LPFN_WSASETBLOCKINGHOOK)(FARPROC lpBlockFunc);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSACancelBlockingCall(void);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSACANCELBLOCKINGCALL)(void);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int wMsg,const char * name,const char * proto,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef HANDLE 
(WSAAPI * LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int wMsg,const char * name,const char * proto,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByPort(HWND hWnd,u_int wMsg,int port,const char * proto,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef HANDLE 
(WSAAPI * LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int wMsg,int port,const char * proto,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int wMsg,const char * name,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef HANDLE 
(WSAAPI * LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int wMsg,const char * name,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByNumber(HWND hWnd,u_int wMsg,int number,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef HANDLE 
(WSAAPI * LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int wMsg,int number,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int wMsg,const char * name,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef HANDLE 
(WSAAPI * LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int wMsg,const char * name,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int wMsg,const char * addr,int len,int type,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef HANDLE 
(WSAAPI * LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int wMsg,const char * addr,int len,int type,char * buf,int buflen);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int wMsg,long lEvent);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int wMsg,long lEvent);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,struct sockaddr * addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dwCallbackData);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef SOCKET 
(WSAAPI * LPFN_WSAACCEPT)(SOCKET s,struct sockaddr * addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dwCallbackData);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE BOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef BOOL 
(WSAAPI * LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAConnect(SOCKET s,const struct sockaddr * name,int namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSACONNECT)(SOCKET s,const struct sockaddr * name,int namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(void);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef WSAEVENT 
(WSAAPI * LPFN_WSACREATEEVENT)(void);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
WINSOCK_API_LINKAGE int WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
#ifdef UNICODE
#define WSADuplicateSocket WSADuplicateSocketW
#else
#define WSADuplicateSocket WSADuplicateSocketA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
typedef int 
(WSAAPI * LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
#ifdef UNICODE
#define LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#else
#define LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAEnumNetworkEvents(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lpNetworkEvents);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lpNetworkEvents);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lpProtocolBuffer,LPDWORD lpdwBufferLength);
WINSOCK_API_LINKAGE int WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lpProtocolBuffer,LPDWORD lpdwBufferLength);
#ifdef UNICODE
#define WSAEnumProtocols WSAEnumProtocolsW
#else
#define WSAEnumProtocols WSAEnumProtocolsA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lpProtocolBuffer,LPDWORD lpdwBufferLength);
typedef int 
(WSAAPI * LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lpProtocolBuffer,LPDWORD lpdwBufferLength);
#ifdef UNICODE
#define LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#else
#define LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,long lNetworkEvents);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,long lNetworkEvents);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE BOOL WSAAPI WSAGetOverlappedResult(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,BOOL fWait,LPDWORD lpdwFlags);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef BOOL 
(WSAAPI * LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,BOOL fWait,LPDWORD lpdwFlags);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE BOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef BOOL 
(WSAAPI * LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long * lpnetlong);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long * lpnetlong);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short * lpnetshort);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short * lpnetshort);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSAIoctl(SOCKET s,DWORD dwIoControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSAIOCTL)(SOCKET s,DWORD dwIoControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoinLeaf(SOCKET s,const struct sockaddr * name,int namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef SOCKET 
(WSAAPI * LPFN_WSAJOINLEAF)(SOCKET s,const struct sockaddr * name,int namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long * lphostlong);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long * lphostlong);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short * lphostshort);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short * lphostshort);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesRecvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesRecvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lpInboundDisconnectData);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lpInboundDisconnectData);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesRecvd,LPDWORD lpFlags,struct sockaddr * lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesRecvd,LPDWORD lpFlags,struct sockaddr * lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE BOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef BOOL 
(WSAAPI * LPFN_WSARESETEVENT)(WSAEVENT hEvent);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesSent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesSent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lpOutboundDisconnectData);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lpOutboundDisconnectData);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE int WSAAPI WSASendTo(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesSent,DWORD dwFlags,const struct sockaddr * lpTo,int iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef int 
(WSAAPI * LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesSent,DWORD dwFlags,const struct sockaddr * lpTo,int iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE BOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef BOOL 
(WSAAPI * LPFN_WSASETEVENT)(WSAEVENT hEvent);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(int af,int type,int protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,GROUP g,DWORD dwFlags);
WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(int af,int type,int protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,GROUP g,DWORD dwFlags);
#ifdef UNICODE
#define WSASocket WSASocketW
#else
#define WSASocket WSASocketA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef SOCKET 
(WSAAPI * LPFN_WSASOCKETA)(int af,int type,int protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,GROUP g,DWORD dwFlags);
typedef SOCKET 
(WSAAPI * LPFN_WSASOCKETW)(int af,int type,int protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,GROUP g,DWORD dwFlags);
#ifdef UNICODE
#define LPFN_WSASOCKET LPFN_WSASOCKETW
#else
#define LPFN_WSASOCKET LPFN_WSASOCKETA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE DWORD WSAAPI WSAWaitForMultipleEvents(DWORD cEvents,const WSAEVENT * lphEvents,BOOL fWaitAll,DWORD dwTimeout,BOOL fAlertable);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef DWORD 
(WSAAPI * LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,const WSAEVENT * lphEvents,BOOL fWaitAll,DWORD dwTimeout,BOOL fAlertable);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSAAddressToStringA(LPSOCKADDR lpsaAddress,DWORD dwAddressLength,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpszAddressString,LPDWORD lpdwAddressStringLength);
WINSOCK_API_LINKAGE INT WSAAPI WSAAddressToStringW(LPSOCKADDR lpsaAddress,DWORD dwAddressLength,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpszAddressString,LPDWORD lpdwAddressStringLength);
#ifdef UNICODE
#define WSAAddressToString WSAAddressToStringW
#else
#define WSAAddressToString WSAAddressToStringA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsaAddress,DWORD dwAddressLength,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpszAddressString,LPDWORD lpdwAddressStringLength);
typedef INT 
(WSAAPI * LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsaAddress,DWORD dwAddressLength,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpszAddressString,LPDWORD lpdwAddressStringLength);
#ifdef UNICODE
#define LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#else
#define LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSAStringToAddressA(LPSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lpAddressLength);
WINSOCK_API_LINKAGE INT WSAAPI WSAStringToAddressW(LPWSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lpAddressLength);
#ifdef UNICODE
#define WSAStringToAddress WSAStringToAddressW
#else
#define WSAStringToAddress WSAStringToAddressA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSASTRINGTOADDRESSA)(LPSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lpAddressLength);
typedef INT 
(WSAAPI * LPFN_WSASTRINGTOADDRESSW)(LPWSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lpAddressLength);
#ifdef UNICODE
#define LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#else
#define LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
#ifdef UNICODE
#define WSALookupServiceBegin WSALookupServiceBeginW
#else
#define WSALookupServiceBegin WSALookupServiceBeginA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
typedef INT 
(WSAAPI * LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
#ifdef UNICODE
#define LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#else
#define LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceNextA(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdwBufferLength,LPWSAQUERYSETA lpqsResults);
WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceNextW(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdwBufferLength,LPWSAQUERYSETW lpqsResults);
#ifdef UNICODE
#define WSALookupServiceNext WSALookupServiceNextW
#else
#define WSALookupServiceNext WSALookupServiceNextA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdwBufferLength,LPWSAQUERYSETA lpqsResults);
typedef INT 
(WSAAPI * LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdwBufferLength,LPWSAQUERYSETW lpqsResults);
#ifdef UNICODE
#define LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#else
#define LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dwControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSACOMPLETION lpCompletion);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dwControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSACOMPLETION lpCompletion);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceEnd(HANDLE hLookup);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
#ifdef UNICODE
#define WSAInstallServiceClass WSAInstallServiceClassW
#else
#define WSAInstallServiceClass WSAInstallServiceClassA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
typedef INT 
(WSAAPI * LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
#ifdef UNICODE
#define LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#else
#define LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdwBufSize,LPWSASERVICECLASSINFOA lpServiceClassInfo);
WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdwBufSize,LPWSASERVICECLASSINFOW lpServiceClassInfo);
#ifdef UNICODE
#define WSAGetServiceClassInfo WSAGetServiceClassInfoW
#else
#define WSAGetServiceClassInfo WSAGetServiceClassInfoA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdwBufSize,LPWSASERVICECLASSINFOA lpServiceClassInfo);
typedef INT 
(WSAAPI * LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdwBufSize,LPWSASERVICECLASSINFOW lpServiceClassInfo);
#ifdef UNICODE
#define LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#else
#define LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdwBufferLength,LPWSANAMESPACE_INFOA lpnspBuffer);
WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdwBufferLength,LPWSANAMESPACE_INFOW lpnspBuffer);
#ifdef UNICODE
#define WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#else
#define WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdwBufferLength,LPWSANAMESPACE_INFOA lpnspBuffer);
typedef INT 
(WSAAPI * LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdwBufferLength,LPWSANAMESPACE_INFOW lpnspBuffer);
#ifdef UNICODE
#define LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#else
#define LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdwBufferLength);
WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdwBufferLength);
#ifdef UNICODE
#define WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#else
#define WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdwBufferLength);
typedef INT 
(WSAAPI * LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdwBufferLength);
#ifdef UNICODE
#define LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#else
#define LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
#ifdef UNICODE
#define WSASetService WSASetServiceW
#else
#define WSASetService WSASetServiceA
#endif 
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
typedef INT 
(WSAAPI * LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
#ifdef UNICODE
#define LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#else
#define LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#endif 
#endif 
#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
#if INCL_WINSOCK_API_TYPEDEFS
typedef INT 
(WSAAPI * LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif 
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr_in *PSOCKADDR_IN;
typedef struct sockaddr_in *LPSOCKADDR_IN;
typedef struct linger LINGER;
typedef struct linger *PLINGER;
typedef struct linger *LPLINGER;
typedef struct in_addr IN_ADDR;
typedef struct in_addr *PIN_ADDR;
typedef struct in_addr *LPIN_ADDR;
typedef struct fd_set FD_SET;
typedef struct fd_set *PFD_SET;
typedef struct fd_set *LPFD_SET;
typedef struct hostent HOSTENT;
typedef struct hostent *PHOSTENT;
typedef struct hostent *LPHOSTENT;
typedef struct servent SERVENT;
typedef struct servent *PSERVENT;
typedef struct servent *LPSERVENT;
typedef struct protoent PROTOENT;
typedef struct protoent *PPROTOENT;
typedef struct protoent *LPPROTOENT;
typedef struct timeval TIMEVAL;
typedef struct timeval *PTIMEVAL;
typedef struct timeval *LPTIMEVAL;
#define WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#define WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#define WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#define WSAGETASYNCERROR(lParam) HIWORD(lParam)
#define WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#define WSAGETSELECTERROR(lParam) HIWORD(lParam)
#if !defined(WIN32) && !defined(_WIN64)
#include <poppack.h>
#endif
#ifdef IPV6STRICT
#include <wsipv6ok.h>
#endif 
#endif 
