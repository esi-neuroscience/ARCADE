#ifndef NCB_INCLUDED
#define NCB_INCLUDED
#pragma once
#define NCBNAMSZ 16 
#define MAX_LANA 254 
typedef struct _NCB {
	UCHAR ncb_command; 
	UCHAR ncb_retcode; 
	UCHAR ncb_lsn; 
	UCHAR ncb_num; 
	PUCHAR ncb_buffer; 
	WORD ncb_length; 
	UCHAR ncb_callname[NCBNAMSZ]; 
	UCHAR ncb_name[NCBNAMSZ]; 
	UCHAR ncb_rto; 
	UCHAR ncb_sto; 
	//void (CALLBACK *ncb_post)(struct _NCB * ); 
	UCHAR ncb_lana_num; 
	UCHAR ncb_cmd_cplt; 
#ifdef _WIN64
	UCHAR ncb_reserve[18]; 
#else
	UCHAR ncb_reserve[10]; 
#endif
	HANDLE ncb_event; 
} NCB,*PNCB;
typedef struct _ADAPTER_STATUS {
	UCHAR adapter_address[6];
	UCHAR rev_major;
	UCHAR reserved0;
	UCHAR adapter_type;
	UCHAR rev_minor;
	WORD duration;
	WORD frmr_recv;
	WORD frmr_xmit;
	WORD iframe_recv_err;
	WORD xmit_aborts;
	DWORD xmit_success;
	DWORD recv_success;
	WORD iframe_xmit_err;
	WORD recv_buff_unavail;
	WORD t1_timeouts;
	WORD ti_timeouts;
	DWORD reserved1;
	WORD free_ncbs;
	WORD max_cfg_ncbs;
	WORD max_ncbs;
	WORD xmit_buf_unavail;
	WORD max_dgram_size;
	WORD pending_sess;
	WORD max_cfg_sess;
	WORD max_sess;
	WORD max_sess_pkt_size;
	WORD name_count;
} ADAPTER_STATUS,*PADAPTER_STATUS;
typedef struct _NAME_BUFFER {
	UCHAR name[NCBNAMSZ];
	UCHAR name_num;
	UCHAR name_flags;
} NAME_BUFFER,*PNAME_BUFFER;
#define NAME_FLAGS_MASK 135
#define GROUP_NAME 128
#define UNIQUE_NAME 0
#define REGISTERING 0
#define REGISTERED 4
#define DEREGISTERED 5
#define DUPLICATE 6
#define DUPLICATE_DEREG 7
typedef struct _SESSION_HEADER {
	UCHAR sess_name;
	UCHAR num_sess;
	UCHAR rcv_dg_outstanding;
	UCHAR rcv_any_outstanding;
} SESSION_HEADER,*PSESSION_HEADER;
typedef struct _SESSION_BUFFER {
	UCHAR lsn;
	UCHAR state;
	UCHAR local_name[NCBNAMSZ];
	UCHAR remote_name[NCBNAMSZ];
	UCHAR rcvs_outstanding;
	UCHAR sends_outstanding;
} SESSION_BUFFER,*PSESSION_BUFFER;
#define LISTEN_OUTSTANDING 1
#define CALL_PENDING 2
#define SESSION_ESTABLISHED 3
#define HANGUP_PENDING 4
#define HANGUP_COMPLETE 5
#define SESSION_ABORTED 6
typedef struct _LANA_ENUM {
	UCHAR length; 
	UCHAR lana[MAX_LANA+1];
} LANA_ENUM,*PLANA_ENUM;
typedef struct _FIND_NAME_HEADER {
	WORD node_count;
	UCHAR reserved;
	UCHAR unique_group;
} FIND_NAME_HEADER,*PFIND_NAME_HEADER;
typedef struct _FIND_NAME_BUFFER {
	UCHAR length;
	UCHAR access_control;
	UCHAR frame_control;
	UCHAR destination_addr[6];
	UCHAR source_addr[6];
	UCHAR routing_info[18];
} FIND_NAME_BUFFER,*PFIND_NAME_BUFFER;
typedef struct _ACTION_HEADER {
	ULONG transport_id;
	USHORT action_code;
	USHORT reserved;
} ACTION_HEADER,*PACTION_HEADER;
#define ALL_TRANSPORTS "M000"
#define MS_NBF "MNBF"
#define NCBCALL 16 
#define NCBLISTEN 17 
#define NCBHANGUP 18 
#define NCBSEND 20 
#define NCBRECV 21 
#define NCBRECVANY 22 
#define NCBCHAINSEND 23 
#define NCBDGSEND 32 
#define NCBDGRECV 33 
#define NCBDGSENDBC 34 
#define NCBDGRECVBC 35 
#define NCBADDNAME 48 
#define NCBDELNAME 49 
#define NCBRESET 50 
#define NCBASTAT 51 
#define NCBSSTAT 52 
#define NCBCANCEL 53 
#define NCBADDGRNAME 54 
#define NCBENUM 55 
#define NCBUNLINK 112 
#define NCBSENDNA 113 
#define NCBCHAINSENDNA 114 
#define NCBLANSTALERT 115 
#define NCBACTION 119 
#define NCBFINDNAME 120 
#define NCBTRACE 121 
#define ASYNCH 128 
#define NRC_GOODRET 0 
#define NRC_BUFLEN 1 
#define NRC_ILLCMD 3 
#define NRC_CMDTMO 5 
#define NRC_INCOMP 6 
#define NRC_BADDR 7 
#define NRC_SNUMOUT 8 
#define NRC_NORES 9 
#define NRC_SCLOSED 10 
#define NRC_CMDCAN 11 
#define NRC_DUPNAME 13 
#define NRC_NAMTFUL 14 
#define NRC_ACTSES 15 
#define NRC_LOCTFUL 17 
#define NRC_REMTFUL 18 
#define NRC_ILLNN 19 
#define NRC_NOCALL 20 
#define NRC_NOWILD 21 
#define NRC_INUSE 22 
#define NRC_NAMERR 23 
#define NRC_SABORT 24 
#define NRC_NAMCONF 25 
#define NRC_IFBUSY 33 
#define NRC_TOOMANY 34 
#define NRC_BRIDGE 35 
#define NRC_CANOCCR 36 
#define NRC_CANCEL 38 
#define NRC_DUPENV 48 
#define NRC_ENVNOTDEF 52 
#define NRC_OSRESNOTAV 53 
#define NRC_MAXAPPS 54 
#define NRC_NOSAPS 55 
#define NRC_NORESOURCES 56 
#define NRC_INVADDRESS 57 
#define NRC_INVDDID 59 
#define NRC_LOCKFAIL 60 
#define NRC_OPENERR 63 
#define NRC_SYSTEM 64 
#define NRC_PENDING 255 
UCHAR APIENTRY Netbios(PNCB pncb);
#define NCB_POST void CALLBACK
#endif 
