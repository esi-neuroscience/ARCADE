#ifndef _WINSPOOL_
#define _WINSPOOL_
#ifdef _WINUSER_
#include <prsht.h>
#endif
typedef struct _PRINTER_INFO_1A {
	DWORD Flags;
	LPSTR pDescription;
	LPSTR pName;
	LPSTR pComment;
} PRINTER_INFO_1A,*PPRINTER_INFO_1A,*LPPRINTER_INFO_1A;
typedef struct _PRINTER_INFO_1W {
	DWORD Flags;
	LPWSTR pDescription;
	LPWSTR pName;
	LPWSTR pComment;
} PRINTER_INFO_1W,*PPRINTER_INFO_1W,*LPPRINTER_INFO_1W;
#ifdef UNICODE
typedef PRINTER_INFO_1W PRINTER_INFO_1;
typedef PPRINTER_INFO_1W PPRINTER_INFO_1;
typedef LPPRINTER_INFO_1W LPPRINTER_INFO_1;
#else
typedef PRINTER_INFO_1A PRINTER_INFO_1;
typedef PPRINTER_INFO_1A PPRINTER_INFO_1;
typedef LPPRINTER_INFO_1A LPPRINTER_INFO_1;
#endif 
typedef struct _PRINTER_INFO_2A {
	LPSTR pServerName;
	LPSTR pPrinterName;
	LPSTR pShareName;
	LPSTR pPortName;
	LPSTR pDriverName;
	LPSTR pComment;
	LPSTR pLocation;
	LPDEVMODEA pDevMode;
	LPSTR pSepFile;
	LPSTR pPrintProcessor;
	LPSTR pDatatype;
	LPSTR pParameters;
	PSECURITY_DESCRIPTOR pSecurityDescriptor;
	DWORD Attributes;
	DWORD Priority;
	DWORD DefaultPriority;
	DWORD StartTime;
	DWORD UntilTime;
	DWORD Status;
	DWORD cJobs;
	DWORD AveragePPM;
} PRINTER_INFO_2A,*PPRINTER_INFO_2A,*LPPRINTER_INFO_2A;
typedef struct _PRINTER_INFO_2W {
	LPWSTR pServerName;
	LPWSTR pPrinterName;
	LPWSTR pShareName;
	LPWSTR pPortName;
	LPWSTR pDriverName;
	LPWSTR pComment;
	LPWSTR pLocation;
	LPDEVMODEW pDevMode;
	LPWSTR pSepFile;
	LPWSTR pPrintProcessor;
	LPWSTR pDatatype;
	LPWSTR pParameters;
	PSECURITY_DESCRIPTOR pSecurityDescriptor;
	DWORD Attributes;
	DWORD Priority;
	DWORD DefaultPriority;
	DWORD StartTime;
	DWORD UntilTime;
	DWORD Status;
	DWORD cJobs;
	DWORD AveragePPM;
} PRINTER_INFO_2W,*PPRINTER_INFO_2W,*LPPRINTER_INFO_2W;
#ifdef UNICODE
typedef PRINTER_INFO_2W PRINTER_INFO_2;
typedef PPRINTER_INFO_2W PPRINTER_INFO_2;
typedef LPPRINTER_INFO_2W LPPRINTER_INFO_2;
#else
typedef PRINTER_INFO_2A PRINTER_INFO_2;
typedef PPRINTER_INFO_2A PPRINTER_INFO_2;
typedef LPPRINTER_INFO_2A LPPRINTER_INFO_2;
#endif 
typedef struct _PRINTER_INFO_3 {
	PSECURITY_DESCRIPTOR pSecurityDescriptor;
} PRINTER_INFO_3,*PPRINTER_INFO_3,*LPPRINTER_INFO_3;
typedef struct _PRINTER_INFO_4A {
	LPSTR pPrinterName;
	LPSTR pServerName;
	DWORD Attributes;
} PRINTER_INFO_4A,*PPRINTER_INFO_4A,*LPPRINTER_INFO_4A;
typedef struct _PRINTER_INFO_4W {
	LPWSTR pPrinterName;
	LPWSTR pServerName;
	DWORD Attributes;
} PRINTER_INFO_4W,*PPRINTER_INFO_4W,*LPPRINTER_INFO_4W;
#ifdef UNICODE
typedef PRINTER_INFO_4W PRINTER_INFO_4;
typedef PPRINTER_INFO_4W PPRINTER_INFO_4;
typedef LPPRINTER_INFO_4W LPPRINTER_INFO_4;
#else
typedef PRINTER_INFO_4A PRINTER_INFO_4;
typedef PPRINTER_INFO_4A PPRINTER_INFO_4;
typedef LPPRINTER_INFO_4A LPPRINTER_INFO_4;
#endif 
typedef struct _PRINTER_INFO_5A {
	LPSTR pPrinterName;
	LPSTR pPortName;
	DWORD Attributes;
	DWORD DeviceNotSelectedTimeout;
	DWORD TransmissionRetryTimeout;
} PRINTER_INFO_5A,*PPRINTER_INFO_5A,*LPPRINTER_INFO_5A;
typedef struct _PRINTER_INFO_5W {
	LPWSTR pPrinterName;
	LPWSTR pPortName;
	DWORD Attributes;
	DWORD DeviceNotSelectedTimeout;
	DWORD TransmissionRetryTimeout;
} PRINTER_INFO_5W,*PPRINTER_INFO_5W,*LPPRINTER_INFO_5W;
#ifdef UNICODE
typedef PRINTER_INFO_5W PRINTER_INFO_5;
typedef PPRINTER_INFO_5W PPRINTER_INFO_5;
typedef LPPRINTER_INFO_5W LPPRINTER_INFO_5;
#else
typedef PRINTER_INFO_5A PRINTER_INFO_5;
typedef PPRINTER_INFO_5A PPRINTER_INFO_5;
typedef LPPRINTER_INFO_5A LPPRINTER_INFO_5;
#endif 
typedef struct _PRINTER_INFO_6 {
	DWORD dwStatus;
} PRINTER_INFO_6,*PPRINTER_INFO_6,*LPPRINTER_INFO_6;
typedef struct _PRINTER_INFO_7A {
 LPSTR pszObjectGUID;
 DWORD dwAction;
} PRINTER_INFO_7A,*PPRINTER_INFO_7A,*LPPRINTER_INFO_7A;
typedef struct _PRINTER_INFO_7W {
 LPWSTR pszObjectGUID;
 DWORD dwAction;
} PRINTER_INFO_7W,*PPRINTER_INFO_7W,*LPPRINTER_INFO_7W;
#ifdef UNICODE
typedef PRINTER_INFO_7W PRINTER_INFO_7;
typedef PPRINTER_INFO_7W PPRINTER_INFO_7;
typedef LPPRINTER_INFO_7W LPPRINTER_INFO_7;
#else
typedef PRINTER_INFO_7A PRINTER_INFO_7;
typedef PPRINTER_INFO_7A PPRINTER_INFO_7;
typedef LPPRINTER_INFO_7A LPPRINTER_INFO_7;
#endif 
#define DSPRINT_PUBLISH 1
#define DSPRINT_UPDATE 2
#define DSPRINT_UNPUBLISH 4
#define DSPRINT_REPUBLISH 8
#define DSPRINT_PENDING 0x80000000
typedef struct _PRINTER_INFO_8A {
	LPDEVMODEA pDevMode;
} PRINTER_INFO_8A,*PPRINTER_INFO_8A,*LPPRINTER_INFO_8A;
typedef struct _PRINTER_INFO_8W {
	LPDEVMODEW pDevMode;
} PRINTER_INFO_8W,*PPRINTER_INFO_8W,*LPPRINTER_INFO_8W;
#ifdef UNICODE
typedef PRINTER_INFO_8W PRINTER_INFO_8;
typedef PPRINTER_INFO_8W PPRINTER_INFO_8;
typedef LPPRINTER_INFO_8W LPPRINTER_INFO_8;
#else
typedef PRINTER_INFO_8A PRINTER_INFO_8;
typedef PPRINTER_INFO_8A PPRINTER_INFO_8;
typedef LPPRINTER_INFO_8A LPPRINTER_INFO_8;
#endif 
typedef struct _PRINTER_INFO_9A {
	LPDEVMODEA pDevMode;
} PRINTER_INFO_9A,*PPRINTER_INFO_9A,*LPPRINTER_INFO_9A;
typedef struct _PRINTER_INFO_9W {
	LPDEVMODEW pDevMode;
} PRINTER_INFO_9W,*PPRINTER_INFO_9W,*LPPRINTER_INFO_9W;
#ifdef UNICODE
typedef PRINTER_INFO_9W PRINTER_INFO_9;
typedef PPRINTER_INFO_9W PPRINTER_INFO_9;
typedef LPPRINTER_INFO_9W LPPRINTER_INFO_9;
#else
typedef PRINTER_INFO_9A PRINTER_INFO_9;
typedef PPRINTER_INFO_9A PPRINTER_INFO_9;
typedef LPPRINTER_INFO_9A LPPRINTER_INFO_9;
#endif 
#define PRINTER_CONTROL_PAUSE 1
#define PRINTER_CONTROL_RESUME 2
#define PRINTER_CONTROL_PURGE 3
#define PRINTER_CONTROL_SET_STATUS 4
#define PRINTER_STATUS_PAUSED 1
#define PRINTER_STATUS_ERROR 2
#define PRINTER_STATUS_PENDING_DELETION 4
#define PRINTER_STATUS_PAPER_JAM 8
#define PRINTER_STATUS_PAPER_OUT 16
#define PRINTER_STATUS_MANUAL_FEED 32
#define PRINTER_STATUS_PAPER_PROBLEM 64
#define PRINTER_STATUS_OFFLINE 128
#define PRINTER_STATUS_IO_ACTIVE 256
#define PRINTER_STATUS_BUSY 512
#define PRINTER_STATUS_PRINTING 1024
#define PRINTER_STATUS_OUTPUT_BIN_FULL 2048
#define PRINTER_STATUS_NOT_AVAILABLE 0x1000
#define PRINTER_STATUS_WAITING 0x2000
#define PRINTER_STATUS_PROCESSING 0x4000
#define PRINTER_STATUS_INITIALIZING 0x8000
#define PRINTER_STATUS_WARMING_UP 0x10000
#define PRINTER_STATUS_TONER_LOW 0x20000
#define PRINTER_STATUS_NO_TONER 0x40000
#define PRINTER_STATUS_PAGE_PUNT 0x80000
#define PRINTER_STATUS_USER_INTERVENTION 0x100000
#define PRINTER_STATUS_OUT_OF_MEMORY 0x200000
#define PRINTER_STATUS_DOOR_OPEN 0x400000
#define PRINTER_STATUS_SERVER_UNKNOWN 0x800000
#define PRINTER_STATUS_POWER_SAVE 0x1000000
#define PRINTER_ATTRIBUTE_QUEUED 1
#define PRINTER_ATTRIBUTE_DIRECT 2
#define PRINTER_ATTRIBUTE_DEFAULT 4
#define PRINTER_ATTRIBUTE_SHARED 8
#define PRINTER_ATTRIBUTE_NETWORK 16
#define PRINTER_ATTRIBUTE_HIDDEN 32
#define PRINTER_ATTRIBUTE_LOCAL 64
#define PRINTER_ATTRIBUTE_ENABLE_DEVQ 128
#define PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS 256
#define PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST 512
#define PRINTER_ATTRIBUTE_WORK_OFFLINE 1024
#define PRINTER_ATTRIBUTE_ENABLE_BIDI 2048
#define PRINTER_ATTRIBUTE_RAW_ONLY 0x1000
#define PRINTER_ATTRIBUTE_PUBLISHED 0x2000
#define PRINTER_ATTRIBUTE_FAX 0x4000
#define PRINTER_ATTRIBUTE_TS 0x8000
#define NO_PRIORITY 0
#define MAX_PRIORITY 99
#define MIN_PRIORITY 1
#define DEF_PRIORITY 1
typedef struct _JOB_INFO_1A {
 DWORD JobId;
 LPSTR pPrinterName;
 LPSTR pMachineName;
 LPSTR pUserName;
 LPSTR pDocument;
 LPSTR pDatatype;
 LPSTR pStatus;
 DWORD Status;
 DWORD Priority;
 DWORD Position;
 DWORD TotalPages;
 DWORD PagesPrinted;
 SYSTEMTIME Submitted;
} JOB_INFO_1A,*PJOB_INFO_1A,*LPJOB_INFO_1A;
typedef struct _JOB_INFO_1W {
 DWORD JobId;
 LPWSTR pPrinterName;
 LPWSTR pMachineName;
 LPWSTR pUserName;
 LPWSTR pDocument;
 LPWSTR pDatatype;
 LPWSTR pStatus;
 DWORD Status;
 DWORD Priority;
 DWORD Position;
 DWORD TotalPages;
 DWORD PagesPrinted;
 SYSTEMTIME Submitted;
} JOB_INFO_1W,*PJOB_INFO_1W,*LPJOB_INFO_1W;
#ifdef UNICODE
typedef JOB_INFO_1W JOB_INFO_1;
typedef PJOB_INFO_1W PJOB_INFO_1;
typedef LPJOB_INFO_1W LPJOB_INFO_1;
#else
typedef JOB_INFO_1A JOB_INFO_1;
typedef PJOB_INFO_1A PJOB_INFO_1;
typedef LPJOB_INFO_1A LPJOB_INFO_1;
#endif 
typedef struct _JOB_INFO_2A {
 DWORD JobId;
 LPSTR pPrinterName;
 LPSTR pMachineName;
 LPSTR pUserName;
 LPSTR pDocument;
 LPSTR pNotifyName;
 LPSTR pDatatype;
 LPSTR pPrintProcessor;
 LPSTR pParameters;
 LPSTR pDriverName;
 LPDEVMODEA pDevMode;
 LPSTR pStatus;
 PSECURITY_DESCRIPTOR pSecurityDescriptor;
 DWORD Status;
 DWORD Priority;
 DWORD Position;
 DWORD StartTime;
 DWORD UntilTime;
 DWORD TotalPages;
 DWORD Size;
 SYSTEMTIME Submitted; 
 DWORD Time; 
 DWORD PagesPrinted;
} JOB_INFO_2A,*PJOB_INFO_2A,*LPJOB_INFO_2A;
typedef struct _JOB_INFO_2W {
 DWORD JobId;
 LPWSTR pPrinterName;
 LPWSTR pMachineName;
 LPWSTR pUserName;
 LPWSTR pDocument;
 LPWSTR pNotifyName;
 LPWSTR pDatatype;
 LPWSTR pPrintProcessor;
 LPWSTR pParameters;
 LPWSTR pDriverName;
 LPDEVMODEW pDevMode;
 LPWSTR pStatus;
 PSECURITY_DESCRIPTOR pSecurityDescriptor;
 DWORD Status;
 DWORD Priority;
 DWORD Position;
 DWORD StartTime;
 DWORD UntilTime;
 DWORD TotalPages;
 DWORD Size;
 SYSTEMTIME Submitted; 
 DWORD Time; 
 DWORD PagesPrinted;
} JOB_INFO_2W,*PJOB_INFO_2W,*LPJOB_INFO_2W;
#ifdef UNICODE
typedef JOB_INFO_2W JOB_INFO_2;
typedef PJOB_INFO_2W PJOB_INFO_2;
typedef LPJOB_INFO_2W LPJOB_INFO_2;
#else
typedef JOB_INFO_2A JOB_INFO_2;
typedef PJOB_INFO_2A PJOB_INFO_2;
typedef LPJOB_INFO_2A LPJOB_INFO_2;
#endif 
typedef struct _JOB_INFO_3 {
	DWORD JobId;
	DWORD NextJobId;
	DWORD Reserved;
} JOB_INFO_3,*PJOB_INFO_3,*LPJOB_INFO_3;
#define JOB_CONTROL_PAUSE 1
#define JOB_CONTROL_RESUME 2
#define JOB_CONTROL_CANCEL 3
#define JOB_CONTROL_RESTART 4
#define JOB_CONTROL_DELETE 5
#define JOB_CONTROL_SENT_TO_PRINTER 6
#define JOB_CONTROL_LAST_PAGE_EJECTED 7
#define JOB_STATUS_PAUSED 1
#define JOB_STATUS_ERROR 2
#define JOB_STATUS_DELETING 4
#define JOB_STATUS_SPOOLING 8
#define JOB_STATUS_PRINTING 16
#define JOB_STATUS_OFFLINE 32
#define JOB_STATUS_PAPEROUT 64
#define JOB_STATUS_PRINTED 128
#define JOB_STATUS_DELETED 256
#define JOB_STATUS_BLOCKED_DEVQ 512
#define JOB_STATUS_USER_INTERVENTION 1024
#define JOB_STATUS_RESTART 2048
#define JOB_STATUS_COMPLETE 0x1000
#define JOB_POSITION_UNSPECIFIED 0
typedef struct _ADDJOB_INFO_1A {
	LPSTR Path;
	DWORD JobId;
} ADDJOB_INFO_1A,*PADDJOB_INFO_1A,*LPADDJOB_INFO_1A;
typedef struct _ADDJOB_INFO_1W {
	LPWSTR Path;
	DWORD JobId;
} ADDJOB_INFO_1W,*PADDJOB_INFO_1W,*LPADDJOB_INFO_1W;
#ifdef UNICODE
typedef ADDJOB_INFO_1W ADDJOB_INFO_1;
typedef PADDJOB_INFO_1W PADDJOB_INFO_1;
typedef LPADDJOB_INFO_1W LPADDJOB_INFO_1;
#else
typedef ADDJOB_INFO_1A ADDJOB_INFO_1;
typedef PADDJOB_INFO_1A PADDJOB_INFO_1;
typedef LPADDJOB_INFO_1A LPADDJOB_INFO_1;
#endif 
typedef struct _DRIVER_INFO_1A {
	LPSTR pName; 
} DRIVER_INFO_1A,*PDRIVER_INFO_1A,*LPDRIVER_INFO_1A;
typedef struct _DRIVER_INFO_1W {
	LPWSTR pName; 
} DRIVER_INFO_1W,*PDRIVER_INFO_1W,*LPDRIVER_INFO_1W;
#ifdef UNICODE
typedef DRIVER_INFO_1W DRIVER_INFO_1;
typedef PDRIVER_INFO_1W PDRIVER_INFO_1;
typedef LPDRIVER_INFO_1W LPDRIVER_INFO_1;
#else
typedef DRIVER_INFO_1A DRIVER_INFO_1;
typedef PDRIVER_INFO_1A PDRIVER_INFO_1;
typedef LPDRIVER_INFO_1A LPDRIVER_INFO_1;
#endif 
typedef struct _DRIVER_INFO_2A {
	DWORD cVersion;
	LPSTR pName; 
	LPSTR pEnvironment; 
	LPSTR pDriverPath; 
	LPSTR pDataFile; 
	LPSTR pConfigFile; 
} DRIVER_INFO_2A,*PDRIVER_INFO_2A,*LPDRIVER_INFO_2A;
typedef struct _DRIVER_INFO_2W {
	DWORD cVersion;
	LPWSTR pName; 
	LPWSTR pEnvironment; 
	LPWSTR pDriverPath; 
	LPWSTR pDataFile; 
	LPWSTR pConfigFile; 
} DRIVER_INFO_2W,*PDRIVER_INFO_2W,*LPDRIVER_INFO_2W;
#ifdef UNICODE
typedef DRIVER_INFO_2W DRIVER_INFO_2;
typedef PDRIVER_INFO_2W PDRIVER_INFO_2;
typedef LPDRIVER_INFO_2W LPDRIVER_INFO_2;
#else
typedef DRIVER_INFO_2A DRIVER_INFO_2;
typedef PDRIVER_INFO_2A PDRIVER_INFO_2;
typedef LPDRIVER_INFO_2A LPDRIVER_INFO_2;
#endif 
typedef struct _DRIVER_INFO_3A {
	DWORD cVersion;
	LPSTR pName; 
	LPSTR pEnvironment; 
	LPSTR pDriverPath; 
	LPSTR pDataFile; 
	LPSTR pConfigFile; 
	LPSTR pHelpFile; 
	LPSTR pDependentFiles; 
	LPSTR pMonitorName; 
	LPSTR pDefaultDataType; 
} DRIVER_INFO_3A,*PDRIVER_INFO_3A,*LPDRIVER_INFO_3A;
typedef struct _DRIVER_INFO_3W {
	DWORD cVersion;
	LPWSTR pName; 
	LPWSTR pEnvironment; 
	LPWSTR pDriverPath; 
	LPWSTR pDataFile; 
	LPWSTR pConfigFile; 
	LPWSTR pHelpFile; 
	LPWSTR pDependentFiles; 
	LPWSTR pMonitorName; 
	LPWSTR pDefaultDataType; 
} DRIVER_INFO_3W,*PDRIVER_INFO_3W,*LPDRIVER_INFO_3W;
#ifdef UNICODE
typedef DRIVER_INFO_3W DRIVER_INFO_3;
typedef PDRIVER_INFO_3W PDRIVER_INFO_3;
typedef LPDRIVER_INFO_3W LPDRIVER_INFO_3;
#else
typedef DRIVER_INFO_3A DRIVER_INFO_3;
typedef PDRIVER_INFO_3A PDRIVER_INFO_3;
typedef LPDRIVER_INFO_3A LPDRIVER_INFO_3;
#endif 
typedef struct _DRIVER_INFO_4A {
	DWORD cVersion;
	LPSTR pName; 
	LPSTR pEnvironment; 
	LPSTR pDriverPath; 
	LPSTR pDataFile; 
	LPSTR pConfigFile; 
	LPSTR pHelpFile; 
	LPSTR pDependentFiles; 
	LPSTR pMonitorName; 
	LPSTR pDefaultDataType; 
	LPSTR pszzPreviousNames; 
} DRIVER_INFO_4A,*PDRIVER_INFO_4A,*LPDRIVER_INFO_4A;
typedef struct _DRIVER_INFO_4W {
	DWORD cVersion;
	LPWSTR pName; 
	LPWSTR pEnvironment; 
	LPWSTR pDriverPath; 
	LPWSTR pDataFile; 
	LPWSTR pConfigFile; 
	LPWSTR pHelpFile; 
	LPWSTR pDependentFiles; 
	LPWSTR pMonitorName; 
	LPWSTR pDefaultDataType; 
	LPWSTR pszzPreviousNames; 
} DRIVER_INFO_4W,*PDRIVER_INFO_4W,*LPDRIVER_INFO_4W;
#ifdef UNICODE
typedef DRIVER_INFO_4W DRIVER_INFO_4;
typedef PDRIVER_INFO_4W PDRIVER_INFO_4;
typedef LPDRIVER_INFO_4W LPDRIVER_INFO_4;
#else
typedef DRIVER_INFO_4A DRIVER_INFO_4;
typedef PDRIVER_INFO_4A PDRIVER_INFO_4;
typedef LPDRIVER_INFO_4A LPDRIVER_INFO_4;
#endif 
typedef struct _DRIVER_INFO_5A {
	DWORD cVersion;
	LPSTR pName; 
	LPSTR pEnvironment; 
	LPSTR pDriverPath; 
	LPSTR pDataFile; 
	LPSTR pConfigFile; 
	DWORD dwDriverAttributes; 
	DWORD dwConfigVersion; 
	DWORD dwDriverVersion; 
} DRIVER_INFO_5A,*PDRIVER_INFO_5A,*LPDRIVER_INFO_5A;
typedef struct _DRIVER_INFO_5W {
	DWORD cVersion;
	LPWSTR pName; 
	LPWSTR pEnvironment; 
	LPWSTR pDriverPath; 
	LPWSTR pDataFile; 
	LPWSTR pConfigFile; 
	DWORD dwDriverAttributes; 
	DWORD dwConfigVersion; 
	DWORD dwDriverVersion; 
} DRIVER_INFO_5W,*PDRIVER_INFO_5W,*LPDRIVER_INFO_5W;
#ifdef UNICODE
typedef DRIVER_INFO_5W DRIVER_INFO_5;
typedef PDRIVER_INFO_5W PDRIVER_INFO_5;
typedef LPDRIVER_INFO_5W LPDRIVER_INFO_5;
#else
typedef DRIVER_INFO_5A DRIVER_INFO_5;
typedef PDRIVER_INFO_5A PDRIVER_INFO_5;
typedef LPDRIVER_INFO_5A LPDRIVER_INFO_5;
#endif 
typedef struct _DRIVER_INFO_6A {
	DWORD cVersion;
	LPSTR pName; 
	LPSTR pEnvironment; 
	LPSTR pDriverPath; 
	LPSTR pDataFile; 
	LPSTR pConfigFile; 
	LPSTR pHelpFile; 
	LPSTR pDependentFiles; 
	LPSTR pMonitorName; 
	LPSTR pDefaultDataType; 
	LPSTR pszzPreviousNames; 
	FILETIME ftDriverDate;
	DWORDLONG dwlDriverVersion;
	LPSTR pszMfgName;
	LPSTR pszOEMUrl;
	LPSTR pszHardwareID;
	LPSTR pszProvider;
} DRIVER_INFO_6A,*PDRIVER_INFO_6A,*LPDRIVER_INFO_6A;
typedef struct _DRIVER_INFO_6W {
	DWORD cVersion;
	LPWSTR pName; 
	LPWSTR pEnvironment; 
	LPWSTR pDriverPath; 
	LPWSTR pDataFile; 
	LPWSTR pConfigFile; 
	LPWSTR pHelpFile; 
	LPWSTR pDependentFiles; 
	LPWSTR pMonitorName; 
	LPWSTR pDefaultDataType; 
	LPWSTR pszzPreviousNames; 
	FILETIME ftDriverDate;
	DWORDLONG dwlDriverVersion;
	LPWSTR pszMfgName;
	LPWSTR pszOEMUrl;
	LPWSTR pszHardwareID;
	LPWSTR pszProvider;
} DRIVER_INFO_6W,*PDRIVER_INFO_6W,*LPDRIVER_INFO_6W;
#ifdef UNICODE
typedef DRIVER_INFO_6W DRIVER_INFO_6;
typedef PDRIVER_INFO_6W PDRIVER_INFO_6;
typedef LPDRIVER_INFO_6W LPDRIVER_INFO_6;
#else
typedef DRIVER_INFO_6A DRIVER_INFO_6;
typedef PDRIVER_INFO_6A PDRIVER_INFO_6;
typedef LPDRIVER_INFO_6A LPDRIVER_INFO_6;
#endif 
#define DRIVER_KERNELMODE 1
#define DRIVER_USERMODE 2
#define DPD_DELETE_UNUSED_FILES 1
#define DPD_DELETE_SPECIFIC_VERSION 2
#define DPD_DELETE_ALL_FILES 4
#define APD_STRICT_UPGRADE 1
#define APD_STRICT_DOWNGRADE 2
#define APD_COPY_ALL_FILES 4
#define APD_COPY_NEW_FILES 8
#define APD_COPY_FROM_DIRECTORY 16
typedef struct _DOC_INFO_1A {
	LPSTR pDocName;
	LPSTR pOutputFile;
	LPSTR pDatatype;
} DOC_INFO_1A,*PDOC_INFO_1A,*LPDOC_INFO_1A;
typedef struct _DOC_INFO_1W {
	LPWSTR pDocName;
	LPWSTR pOutputFile;
	LPWSTR pDatatype;
} DOC_INFO_1W,*PDOC_INFO_1W,*LPDOC_INFO_1W;
#ifdef UNICODE
typedef DOC_INFO_1W DOC_INFO_1;
typedef PDOC_INFO_1W PDOC_INFO_1;
typedef LPDOC_INFO_1W LPDOC_INFO_1;
#else
typedef DOC_INFO_1A DOC_INFO_1;
typedef PDOC_INFO_1A PDOC_INFO_1;
typedef LPDOC_INFO_1A LPDOC_INFO_1;
#endif 
typedef struct _FORM_INFO_1A {
	DWORD Flags;
	LPSTR pName;
	SIZEL Size;
	RECTL ImageableArea;
} FORM_INFO_1A,*PFORM_INFO_1A,*LPFORM_INFO_1A;
typedef struct _FORM_INFO_1W {
	DWORD Flags;
	LPWSTR pName;
	SIZEL Size;
	RECTL ImageableArea;
} FORM_INFO_1W,*PFORM_INFO_1W,*LPFORM_INFO_1W;
#ifdef UNICODE
typedef FORM_INFO_1W FORM_INFO_1;
typedef PFORM_INFO_1W PFORM_INFO_1;
typedef LPFORM_INFO_1W LPFORM_INFO_1;
#else
typedef FORM_INFO_1A FORM_INFO_1;
typedef PFORM_INFO_1A PFORM_INFO_1;
typedef LPFORM_INFO_1A LPFORM_INFO_1;
#endif 
typedef struct _DOC_INFO_2A {
	LPSTR pDocName;
	LPSTR pOutputFile;
	LPSTR pDatatype;
	DWORD dwMode;
	DWORD JobId;
} DOC_INFO_2A,*PDOC_INFO_2A,*LPDOC_INFO_2A;
typedef struct _DOC_INFO_2W {
	LPWSTR pDocName;
	LPWSTR pOutputFile;
	LPWSTR pDatatype;
	DWORD dwMode;
	DWORD JobId;
} DOC_INFO_2W,*PDOC_INFO_2W,*LPDOC_INFO_2W;
#ifdef UNICODE
typedef DOC_INFO_2W DOC_INFO_2;
typedef PDOC_INFO_2W PDOC_INFO_2;
typedef LPDOC_INFO_2W LPDOC_INFO_2;
#else
typedef DOC_INFO_2A DOC_INFO_2;
typedef PDOC_INFO_2A PDOC_INFO_2;
typedef LPDOC_INFO_2A LPDOC_INFO_2;
#endif 
#define DI_CHANNEL 1 
#define DI_READ_SPOOL_JOB 3
typedef struct _DOC_INFO_3A {
	LPSTR pDocName;
	LPSTR pOutputFile;
	LPSTR pDatatype;
	DWORD dwFlags;
} DOC_INFO_3A,*PDOC_INFO_3A,*LPDOC_INFO_3A;
typedef struct _DOC_INFO_3W {
	LPWSTR pDocName;
	LPWSTR pOutputFile;
	LPWSTR pDatatype;
	DWORD dwFlags;
} DOC_INFO_3W,*PDOC_INFO_3W,*LPDOC_INFO_3W;
#ifdef UNICODE
typedef DOC_INFO_3W DOC_INFO_3;
typedef PDOC_INFO_3W PDOC_INFO_3;
typedef LPDOC_INFO_3W LPDOC_INFO_3;
#else
typedef DOC_INFO_3A DOC_INFO_3;
typedef PDOC_INFO_3A PDOC_INFO_3;
typedef LPDOC_INFO_3A LPDOC_INFO_3;
#endif 
#define DI_MEMORYMAP_WRITE 1
#define FORM_USER 0
#define FORM_BUILTIN 1
#define FORM_PRINTER 2
typedef struct _PRINTPROCESSOR_INFO_1A {
	LPSTR pName;
} PRINTPROCESSOR_INFO_1A,*PPRINTPROCESSOR_INFO_1A,*LPPRINTPROCESSOR_INFO_1A;
typedef struct _PRINTPROCESSOR_INFO_1W {
	LPWSTR pName;
} PRINTPROCESSOR_INFO_1W,*PPRINTPROCESSOR_INFO_1W,*LPPRINTPROCESSOR_INFO_1W;
#ifdef UNICODE
typedef PRINTPROCESSOR_INFO_1W PRINTPROCESSOR_INFO_1;
typedef PPRINTPROCESSOR_INFO_1W PPRINTPROCESSOR_INFO_1;
typedef LPPRINTPROCESSOR_INFO_1W LPPRINTPROCESSOR_INFO_1;
#else
typedef PRINTPROCESSOR_INFO_1A PRINTPROCESSOR_INFO_1;
typedef PPRINTPROCESSOR_INFO_1A PPRINTPROCESSOR_INFO_1;
typedef LPPRINTPROCESSOR_INFO_1A LPPRINTPROCESSOR_INFO_1;
#endif 
typedef struct _PRINTPROCESSOR_CAPS_1 {
	DWORD dwLevel;
	DWORD dwNupOptions;
	DWORD dwPageOrderFlags;
	DWORD dwNumberOfCopies;
} PRINTPROCESSOR_CAPS_1,*PPRINTPROCESSOR_CAPS_1;
#define NORMAL_PRINT 0
#define REVERSE_PRINT 1
typedef struct _PORT_INFO_1A {
	LPSTR pName;
} PORT_INFO_1A,*PPORT_INFO_1A,*LPPORT_INFO_1A;
typedef struct _PORT_INFO_1W {
	LPWSTR pName;
} PORT_INFO_1W,*PPORT_INFO_1W,*LPPORT_INFO_1W;
#ifdef UNICODE
typedef PORT_INFO_1W PORT_INFO_1;
typedef PPORT_INFO_1W PPORT_INFO_1;
typedef LPPORT_INFO_1W LPPORT_INFO_1;
#else
typedef PORT_INFO_1A PORT_INFO_1;
typedef PPORT_INFO_1A PPORT_INFO_1;
typedef LPPORT_INFO_1A LPPORT_INFO_1;
#endif 
typedef struct _PORT_INFO_2A {
	LPSTR pPortName;
	LPSTR pMonitorName;
	LPSTR pDescription;
	DWORD fPortType;
	DWORD Reserved;
} PORT_INFO_2A,*PPORT_INFO_2A,*LPPORT_INFO_2A;
typedef struct _PORT_INFO_2W {
	LPWSTR pPortName;
	LPWSTR pMonitorName;
	LPWSTR pDescription;
	DWORD fPortType;
	DWORD Reserved;
} PORT_INFO_2W,*PPORT_INFO_2W,*LPPORT_INFO_2W;
#ifdef UNICODE
typedef PORT_INFO_2W PORT_INFO_2;
typedef PPORT_INFO_2W PPORT_INFO_2;
typedef LPPORT_INFO_2W LPPORT_INFO_2;
#else
typedef PORT_INFO_2A PORT_INFO_2;
typedef PPORT_INFO_2A PPORT_INFO_2;
typedef LPPORT_INFO_2A LPPORT_INFO_2;
#endif 
#define PORT_TYPE_WRITE 1
#define PORT_TYPE_READ 2
#define PORT_TYPE_REDIRECTED 4
#define PORT_TYPE_NET_ATTACHED 8
typedef struct _PORT_INFO_3A {
	DWORD dwStatus;
	LPSTR pszStatus;
	DWORD dwSeverity;
} PORT_INFO_3A,*PPORT_INFO_3A,*LPPORT_INFO_3A;
typedef struct _PORT_INFO_3W {
	DWORD dwStatus;
	LPWSTR pszStatus;
	DWORD dwSeverity;
} PORT_INFO_3W,*PPORT_INFO_3W,*LPPORT_INFO_3W;
#ifdef UNICODE
typedef PORT_INFO_3W PORT_INFO_3;
typedef PPORT_INFO_3W PPORT_INFO_3;
typedef LPPORT_INFO_3W LPPORT_INFO_3;
#else
typedef PORT_INFO_3A PORT_INFO_3;
typedef PPORT_INFO_3A PPORT_INFO_3;
typedef LPPORT_INFO_3A LPPORT_INFO_3;
#endif 
#define PORT_STATUS_TYPE_ERROR 1
#define PORT_STATUS_TYPE_WARNING 2
#define PORT_STATUS_TYPE_INFO 3
#define PORT_STATUS_OFFLINE 1
#define PORT_STATUS_PAPER_JAM 2
#define PORT_STATUS_PAPER_OUT 3
#define PORT_STATUS_OUTPUT_BIN_FULL 4
#define PORT_STATUS_PAPER_PROBLEM 5
#define PORT_STATUS_NO_TONER 6
#define PORT_STATUS_DOOR_OPEN 7
#define PORT_STATUS_USER_INTERVENTION 8
#define PORT_STATUS_OUT_OF_MEMORY 9
#define PORT_STATUS_TONER_LOW 10
#define PORT_STATUS_WARMING_UP 11
#define PORT_STATUS_POWER_SAVE 12
typedef struct _MONITOR_INFO_1A{
	LPSTR pName;
} MONITOR_INFO_1A,*PMONITOR_INFO_1A,*LPMONITOR_INFO_1A;
typedef struct _MONITOR_INFO_1W{
	LPWSTR pName;
} MONITOR_INFO_1W,*PMONITOR_INFO_1W,*LPMONITOR_INFO_1W;
#ifdef UNICODE
typedef MONITOR_INFO_1W MONITOR_INFO_1;
typedef PMONITOR_INFO_1W PMONITOR_INFO_1;
typedef LPMONITOR_INFO_1W LPMONITOR_INFO_1;
#else
typedef MONITOR_INFO_1A MONITOR_INFO_1;
typedef PMONITOR_INFO_1A PMONITOR_INFO_1;
typedef LPMONITOR_INFO_1A LPMONITOR_INFO_1;
#endif 
typedef struct _MONITOR_INFO_2A{
	LPSTR pName;
	LPSTR pEnvironment;
	LPSTR pDLLName;
} MONITOR_INFO_2A,*PMONITOR_INFO_2A,*LPMONITOR_INFO_2A;
typedef struct _MONITOR_INFO_2W{
	LPWSTR pName;
	LPWSTR pEnvironment;
	LPWSTR pDLLName;
} MONITOR_INFO_2W,*PMONITOR_INFO_2W,*LPMONITOR_INFO_2W;
#ifdef UNICODE
typedef MONITOR_INFO_2W MONITOR_INFO_2;
typedef PMONITOR_INFO_2W PMONITOR_INFO_2;
typedef LPMONITOR_INFO_2W LPMONITOR_INFO_2;
#else
typedef MONITOR_INFO_2A MONITOR_INFO_2;
typedef PMONITOR_INFO_2A PMONITOR_INFO_2;
typedef LPMONITOR_INFO_2A LPMONITOR_INFO_2;
#endif 
typedef struct _DATATYPES_INFO_1A{
	LPSTR pName;
} DATATYPES_INFO_1A,*PDATATYPES_INFO_1A,*LPDATATYPES_INFO_1A;
typedef struct _DATATYPES_INFO_1W{
	LPWSTR pName;
} DATATYPES_INFO_1W,*PDATATYPES_INFO_1W,*LPDATATYPES_INFO_1W;
#ifdef UNICODE
typedef DATATYPES_INFO_1W DATATYPES_INFO_1;
typedef PDATATYPES_INFO_1W PDATATYPES_INFO_1;
typedef LPDATATYPES_INFO_1W LPDATATYPES_INFO_1;
#else
typedef DATATYPES_INFO_1A DATATYPES_INFO_1;
typedef PDATATYPES_INFO_1A PDATATYPES_INFO_1;
typedef LPDATATYPES_INFO_1A LPDATATYPES_INFO_1;
#endif 
typedef struct _PRINTER_DEFAULTSA{
	LPSTR pDatatype;
	LPDEVMODEA pDevMode;
	ACCESS_MASK DesiredAccess;
} PRINTER_DEFAULTSA,*PPRINTER_DEFAULTSA,*LPPRINTER_DEFAULTSA;
typedef struct _PRINTER_DEFAULTSW{
	LPWSTR pDatatype;
	LPDEVMODEW pDevMode;
	ACCESS_MASK DesiredAccess;
} PRINTER_DEFAULTSW,*PPRINTER_DEFAULTSW,*LPPRINTER_DEFAULTSW;
#ifdef UNICODE
typedef PRINTER_DEFAULTSW PRINTER_DEFAULTS;
typedef PPRINTER_DEFAULTSW PPRINTER_DEFAULTS;
typedef LPPRINTER_DEFAULTSW LPPRINTER_DEFAULTS;
#else
typedef PRINTER_DEFAULTSA PRINTER_DEFAULTS;
typedef PPRINTER_DEFAULTSA PPRINTER_DEFAULTS;
typedef LPPRINTER_DEFAULTSA LPPRINTER_DEFAULTS;
#endif 
typedef struct _PRINTER_ENUM_VALUESA {
	LPSTR pValueName;
	DWORD cbValueName;
	DWORD dwType;
	LPBYTE pData;
	DWORD cbData;
} PRINTER_ENUM_VALUESA,*PPRINTER_ENUM_VALUESA,*LPPRINTER_ENUM_VALUESA;
typedef struct _PRINTER_ENUM_VALUESW {
	LPWSTR pValueName;
	DWORD cbValueName;
	DWORD dwType;
	LPBYTE pData;
	DWORD cbData;
} PRINTER_ENUM_VALUESW,*PPRINTER_ENUM_VALUESW,*LPPRINTER_ENUM_VALUESW;
#ifdef UNICODE
typedef PRINTER_ENUM_VALUESW PRINTER_ENUM_VALUES;
typedef PPRINTER_ENUM_VALUESW PPRINTER_ENUM_VALUES;
typedef LPPRINTER_ENUM_VALUESW LPPRINTER_ENUM_VALUES;
#else
typedef PRINTER_ENUM_VALUESA PRINTER_ENUM_VALUES;
typedef PPRINTER_ENUM_VALUESA PPRINTER_ENUM_VALUES;
typedef LPPRINTER_ENUM_VALUESA LPPRINTER_ENUM_VALUES;
#endif 
BOOL WINAPI EnumPrintersA(DWORD Flags,LPSTR Name,DWORD Level,LPBYTE pPrinterEnum,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
BOOL WINAPI EnumPrintersW(DWORD Flags,LPWSTR Name,DWORD Level,LPBYTE pPrinterEnum,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
#ifdef UNICODE
#define EnumPrinters EnumPrintersW
#else
#define EnumPrinters EnumPrintersA
#endif 
#define PRINTER_ENUM_DEFAULT 1
#define PRINTER_ENUM_LOCAL 2
#define PRINTER_ENUM_CONNECTIONS 4
#define PRINTER_ENUM_FAVORITE 4
#define PRINTER_ENUM_NAME 8
#define PRINTER_ENUM_REMOTE 16
#define PRINTER_ENUM_SHARED 32
#define PRINTER_ENUM_NETWORK 64
#define PRINTER_ENUM_EXPAND 0x4000
#define PRINTER_ENUM_CONTAINER 0x8000
#define PRINTER_ENUM_ICONMASK 0xff0000
#define PRINTER_ENUM_ICON1 0x10000
#define PRINTER_ENUM_ICON2 0x20000
#define PRINTER_ENUM_ICON3 0x40000
#define PRINTER_ENUM_ICON4 0x80000
#define PRINTER_ENUM_ICON5 0x100000
#define PRINTER_ENUM_ICON6 0x200000
#define PRINTER_ENUM_ICON7 0x400000
#define PRINTER_ENUM_ICON8 0x800000
#define PRINTER_ENUM_HIDE 0x1000000
#define SPOOL_FILE_PERSISTENT 1
#define SPOOL_FILE_TEMPORARY 2
BOOL WINAPI OpenPrinterA(LPSTR pPrinterName,LPHANDLE phPrinter,LPPRINTER_DEFAULTSA pDefault);
BOOL WINAPI OpenPrinterW(LPWSTR pPrinterName,LPHANDLE phPrinter,LPPRINTER_DEFAULTSW pDefault);
#ifdef UNICODE
#define OpenPrinter OpenPrinterW
#else
#define OpenPrinter OpenPrinterA
#endif 
BOOL WINAPI ResetPrinterA(HANDLE hPrinter,LPPRINTER_DEFAULTSA pDefault);
BOOL WINAPI ResetPrinterW(HANDLE hPrinter,LPPRINTER_DEFAULTSW pDefault);
#ifdef UNICODE
#define ResetPrinter ResetPrinterW
#else
#define ResetPrinter ResetPrinterA
#endif 
BOOL WINAPI SetJobA(HANDLE hPrinter,DWORD JobId,DWORD Level,LPBYTE pJob,DWORD Command);
BOOL WINAPI SetJobW(HANDLE hPrinter,DWORD JobId,DWORD Level,LPBYTE pJob,DWORD Command);
#ifdef UNICODE
#define SetJob SetJobW
#else
#define SetJob SetJobA
#endif 
BOOL WINAPI GetJobA(HANDLE hPrinter,DWORD JobId,DWORD Level,LPBYTE pJob,DWORD cbBuf,LPDWORD pcbNeeded);
BOOL WINAPI GetJobW(HANDLE hPrinter,DWORD JobId,DWORD Level,LPBYTE pJob,DWORD cbBuf,LPDWORD pcbNeeded);
#ifdef UNICODE
#define GetJob GetJobW
#else
#define GetJob GetJobA
#endif 
BOOL WINAPI EnumJobsA(HANDLE hPrinter,DWORD FirstJob,DWORD NoJobs,DWORD Level,LPBYTE pJob,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
BOOL WINAPI EnumJobsW(HANDLE hPrinter,DWORD FirstJob,DWORD NoJobs,DWORD Level,LPBYTE pJob,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
#ifdef UNICODE
#define EnumJobs EnumJobsW
#else
#define EnumJobs EnumJobsA
#endif 
HANDLE WINAPI AddPrinterA(LPSTR pName,DWORD Level,LPBYTE pPrinter);
HANDLE WINAPI AddPrinterW(LPWSTR pName,DWORD Level,LPBYTE pPrinter);
#ifdef UNICODE
#define AddPrinter AddPrinterW
#else
#define AddPrinter AddPrinterA
#endif 
BOOL WINAPI DeletePrinter(HANDLE hPrinter);
BOOL WINAPI SetPrinterA(HANDLE hPrinter,DWORD Level,LPBYTE pPrinter,DWORD Command);
BOOL WINAPI SetPrinterW(HANDLE hPrinter,DWORD Level,LPBYTE pPrinter,DWORD Command);
#ifdef UNICODE
#define SetPrinter SetPrinterW
#else
#define SetPrinter SetPrinterA
#endif 
BOOL WINAPI GetPrinterA(HANDLE hPrinter,DWORD Level,LPBYTE pPrinter,DWORD cbBuf,LPDWORD pcbNeeded);
BOOL WINAPI GetPrinterW(HANDLE hPrinter,DWORD Level,LPBYTE pPrinter,DWORD cbBuf,LPDWORD pcbNeeded);
#ifdef UNICODE
#define GetPrinter GetPrinterW
#else
#define GetPrinter GetPrinterA
#endif 
BOOL WINAPI AddPrinterDriverA(LPSTR pName,DWORD Level,LPBYTE pDriverInfo);
BOOL WINAPI AddPrinterDriverW(LPWSTR pName,DWORD Level,LPBYTE pDriverInfo);
#ifdef UNICODE
#define AddPrinterDriver AddPrinterDriverW
#else
#define AddPrinterDriver AddPrinterDriverA
#endif 
BOOL WINAPI AddPrinterDriverExA(LPSTR pName,DWORD Level,LPBYTE pDriverInfo,DWORD dwFileCopyFlags);
BOOL WINAPI AddPrinterDriverExW(LPWSTR pName,DWORD Level,LPBYTE pDriverInfo,DWORD dwFileCopyFlags);
#ifdef UNICODE
#define AddPrinterDriverEx AddPrinterDriverExW
#else
#define AddPrinterDriverEx AddPrinterDriverExA
#endif 
BOOL WINAPI EnumPrinterDriversA(LPSTR pName,LPSTR pEnvironment,DWORD Level,LPBYTE pDriverInfo,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
BOOL WINAPI EnumPrinterDriversW(LPWSTR pName,LPWSTR pEnvironment,DWORD Level,LPBYTE pDriverInfo,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
#ifdef UNICODE
#define EnumPrinterDrivers EnumPrinterDriversW
#else
#define EnumPrinterDrivers EnumPrinterDriversA
#endif 
BOOL WINAPI GetPrinterDriverA(HANDLE hPrinter,LPSTR pEnvironment,DWORD Level,LPBYTE pDriverInfo,DWORD cbBuf,LPDWORD pcbNeeded);
BOOL WINAPI GetPrinterDriverW(HANDLE hPrinter,LPWSTR pEnvironment,DWORD Level,LPBYTE pDriverInfo,DWORD cbBuf,LPDWORD pcbNeeded);
#ifdef UNICODE
#define GetPrinterDriver GetPrinterDriverW
#else
#define GetPrinterDriver GetPrinterDriverA
#endif 
BOOL WINAPI GetPrinterDriverDirectoryA(LPSTR pName,LPSTR pEnvironment,DWORD Level,LPBYTE pDriverDirectory,DWORD cbBuf,LPDWORD pcbNeeded);
BOOL WINAPI GetPrinterDriverDirectoryW(LPWSTR pName,LPWSTR pEnvironment,DWORD Level,LPBYTE pDriverDirectory,DWORD cbBuf,LPDWORD pcbNeeded);
#ifdef UNICODE
#define GetPrinterDriverDirectory GetPrinterDriverDirectoryW
#else
#define GetPrinterDriverDirectory GetPrinterDriverDirectoryA
#endif 
BOOL WINAPI DeletePrinterDriverA(LPSTR pName,LPSTR pEnvironment,LPSTR pDriverName);
BOOL WINAPI DeletePrinterDriverW(LPWSTR pName,LPWSTR pEnvironment,LPWSTR pDriverName);
#ifdef UNICODE
#define DeletePrinterDriver DeletePrinterDriverW
#else
#define DeletePrinterDriver DeletePrinterDriverA
#endif 
BOOL WINAPI DeletePrinterDriverExA(LPSTR pName,LPSTR pEnvironment,LPSTR pDriverName,DWORD dwDeleteFlag,DWORD dwVersionFlag);
BOOL WINAPI DeletePrinterDriverExW(LPWSTR pName,LPWSTR pEnvironment,LPWSTR pDriverName,DWORD dwDeleteFlag,DWORD dwVersionFlag);
#ifdef UNICODE
#define DeletePrinterDriverEx DeletePrinterDriverExW
#else
#define DeletePrinterDriverEx DeletePrinterDriverExA
#endif 
BOOL WINAPI AddPrintProcessorA(LPSTR pName,LPSTR pEnvironment,LPSTR pPathName,LPSTR pPrintProcessorName);
BOOL WINAPI AddPrintProcessorW(LPWSTR pName,LPWSTR pEnvironment,LPWSTR pPathName,LPWSTR pPrintProcessorName);
#ifdef UNICODE
#define AddPrintProcessor AddPrintProcessorW
#else
#define AddPrintProcessor AddPrintProcessorA
#endif 
BOOL WINAPI EnumPrintProcessorsA(LPSTR pName,LPSTR pEnvironment,DWORD Level,LPBYTE pPrintProcessorInfo,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
BOOL WINAPI EnumPrintProcessorsW(LPWSTR pName,LPWSTR pEnvironment,DWORD Level,LPBYTE pPrintProcessorInfo,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
#ifdef UNICODE
#define EnumPrintProcessors EnumPrintProcessorsW
#else
#define EnumPrintProcessors EnumPrintProcessorsA
#endif 
BOOL WINAPI GetPrintProcessorDirectoryA(LPSTR pName,LPSTR pEnvironment,DWORD Level,LPBYTE pPrintProcessorInfo,DWORD cbBuf,LPDWORD pcbNeeded);
BOOL WINAPI GetPrintProcessorDirectoryW(LPWSTR pName,LPWSTR pEnvironment,DWORD Level,LPBYTE pPrintProcessorInfo,DWORD cbBuf,LPDWORD pcbNeeded);
#ifdef UNICODE
#define GetPrintProcessorDirectory GetPrintProcessorDirectoryW
#else
#define GetPrintProcessorDirectory GetPrintProcessorDirectoryA
#endif 
BOOL WINAPI EnumPrintProcessorDatatypesA(LPSTR pName,LPSTR pPrintProcessorName,DWORD Level,LPBYTE pDatatypes,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
BOOL WINAPI EnumPrintProcessorDatatypesW(LPWSTR pName,LPWSTR pPrintProcessorName,DWORD Level,LPBYTE pDatatypes,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
#ifdef UNICODE
#define EnumPrintProcessorDatatypes EnumPrintProcessorDatatypesW
#else
#define EnumPrintProcessorDatatypes EnumPrintProcessorDatatypesA
#endif 
BOOL WINAPI DeletePrintProcessorA(LPSTR pName,LPSTR pEnvironment,LPSTR pPrintProcessorName);
BOOL WINAPI DeletePrintProcessorW(LPWSTR pName,LPWSTR pEnvironment,LPWSTR pPrintProcessorName);
#ifdef UNICODE
#define DeletePrintProcessor DeletePrintProcessorW
#else
#define DeletePrintProcessor DeletePrintProcessorA
#endif 
DWORD WINAPI StartDocPrinterA(HANDLE hPrinter,DWORD Level,LPBYTE pDocInfo);
DWORD WINAPI StartDocPrinterW(HANDLE hPrinter,DWORD Level,LPBYTE pDocInfo);
#ifdef UNICODE
#define StartDocPrinter StartDocPrinterW
#else
#define StartDocPrinter StartDocPrinterA
#endif 
BOOL WINAPI StartPagePrinter(HANDLE hPrinter);
BOOL WINAPI WritePrinter(HANDLE hPrinter,LPVOID pBuf,DWORD cbBuf,LPDWORD pcWritten);
BOOL WINAPI FlushPrinter(HANDLE hPrinter,LPVOID pBuf,DWORD cbBuf,LPDWORD pcWritten,DWORD cSleep);
BOOL WINAPI EndPagePrinter(HANDLE hPrinter);
BOOL WINAPI AbortPrinter(HANDLE hPrinter);
BOOL WINAPI ReadPrinter(HANDLE hPrinter,LPVOID pBuf,DWORD cbBuf,LPDWORD pNoBytesRead);
BOOL WINAPI EndDocPrinter(HANDLE hPrinter);
BOOL WINAPI AddJobA(HANDLE hPrinter,DWORD Level,LPBYTE pData,DWORD cbBuf,LPDWORD pcbNeeded);
BOOL WINAPI AddJobW(HANDLE hPrinter,DWORD Level,LPBYTE pData,DWORD cbBuf,LPDWORD pcbNeeded);
#ifdef UNICODE
#define AddJob AddJobW
#else
#define AddJob AddJobA
#endif 
BOOL WINAPI ScheduleJob(HANDLE hPrinter,DWORD JobId);
BOOL WINAPI PrinterProperties(HWND hWnd,HANDLE hPrinter);
LONG WINAPI DocumentPropertiesA(HWND hWnd,HANDLE hPrinter,LPSTR pDeviceName,PDEVMODEA pDevModeOutput,PDEVMODEA pDevModeInput,DWORD fMode);
LONG WINAPI DocumentPropertiesW(HWND hWnd,HANDLE hPrinter,LPWSTR pDeviceName,PDEVMODEW pDevModeOutput,PDEVMODEW pDevModeInput,DWORD fMode);
#ifdef UNICODE
#define DocumentProperties DocumentPropertiesW
#else
#define DocumentProperties DocumentPropertiesA
#endif 
LONG WINAPI AdvancedDocumentPropertiesA(HWND hWnd,HANDLE hPrinter,LPSTR pDeviceName,PDEVMODEA pDevModeOutput,PDEVMODEA pDevModeInput);
LONG WINAPI AdvancedDocumentPropertiesW(HWND hWnd,HANDLE hPrinter,LPWSTR pDeviceName,PDEVMODEW pDevModeOutput,PDEVMODEW pDevModeInput);
#ifdef UNICODE
#define AdvancedDocumentProperties AdvancedDocumentPropertiesW
#else
#define AdvancedDocumentProperties AdvancedDocumentPropertiesA
#endif 
LONG ExtDeviceMode(HWND hWnd,HANDLE hInst,LPDEVMODEA pDevModeOutput,LPSTR pDeviceName,LPSTR pPort,LPDEVMODEA pDevModeInput,LPSTR pProfile,DWORD fMode);
DWORD WINAPI GetPrinterDataA(HANDLE hPrinter,LPSTR pValueName,LPDWORD pType,LPBYTE pData,DWORD nSize,LPDWORD pcbNeeded);
DWORD WINAPI GetPrinterDataW(HANDLE hPrinter,LPWSTR pValueName,LPDWORD pType,LPBYTE pData,DWORD nSize,LPDWORD pcbNeeded);
#ifdef UNICODE
#define GetPrinterData GetPrinterDataW
#else
#define GetPrinterData GetPrinterDataA
#endif 
DWORD WINAPI GetPrinterDataExA(HANDLE hPrinter,LPCSTR pKeyName,LPCSTR pValueName,LPDWORD pType,LPBYTE pData,DWORD nSize,LPDWORD pcbNeeded);
DWORD WINAPI GetPrinterDataExW(HANDLE hPrinter,LPCWSTR pKeyName,LPCWSTR pValueName,LPDWORD pType,LPBYTE pData,DWORD nSize,LPDWORD pcbNeeded);
#ifdef UNICODE
#define GetPrinterDataEx GetPrinterDataExW
#else
#define GetPrinterDataEx GetPrinterDataExA
#endif 
DWORD WINAPI EnumPrinterDataA(HANDLE hPrinter,DWORD dwIndex,LPSTR pValueName,DWORD cbValueName,LPDWORD pcbValueName,LPDWORD pType,LPBYTE pData,DWORD cbData,LPDWORD pcbData);
DWORD WINAPI EnumPrinterDataW(HANDLE hPrinter,DWORD dwIndex,LPWSTR pValueName,DWORD cbValueName,LPDWORD pcbValueName,LPDWORD pType,LPBYTE pData,DWORD cbData,LPDWORD pcbData);
#ifdef UNICODE
#define EnumPrinterData EnumPrinterDataW
#else
#define EnumPrinterData EnumPrinterDataA
#endif 
DWORD WINAPI EnumPrinterDataExA(HANDLE hPrinter,LPCSTR pKeyName,LPBYTE pEnumValues,DWORD cbEnumValues,LPDWORD pcbEnumValues,LPDWORD pnEnumValues);
DWORD WINAPI EnumPrinterDataExW(HANDLE hPrinter,LPCWSTR pKeyName,LPBYTE pEnumValues,DWORD cbEnumValues,LPDWORD pcbEnumValues,LPDWORD pnEnumValues);
#ifdef UNICODE
#define EnumPrinterDataEx EnumPrinterDataExW
#else
#define EnumPrinterDataEx EnumPrinterDataExA
#endif 
DWORD WINAPI EnumPrinterKeyA(HANDLE hPrinter,LPCSTR pKeyName,LPSTR pSubkey,DWORD cbSubkey,LPDWORD pcbSubkey);
DWORD WINAPI EnumPrinterKeyW(HANDLE hPrinter,LPCWSTR pKeyName,LPWSTR pSubkey,DWORD cbSubkey,LPDWORD pcbSubkey);
#ifdef UNICODE
#define EnumPrinterKey EnumPrinterKeyW
#else
#define EnumPrinterKey EnumPrinterKeyA
#endif 
DWORD WINAPI SetPrinterDataA(HANDLE hPrinter,LPSTR pValueName,DWORD Type,LPBYTE pData,DWORD cbData);
DWORD WINAPI SetPrinterDataW(HANDLE hPrinter,LPWSTR pValueName,DWORD Type,LPBYTE pData,DWORD cbData);
#ifdef UNICODE
#define SetPrinterData SetPrinterDataW
#else
#define SetPrinterData SetPrinterDataA
#endif 
DWORD WINAPI SetPrinterDataExA(HANDLE hPrinter,LPCSTR pKeyName,LPCSTR pValueName,DWORD Type,LPBYTE pData,DWORD cbData);
DWORD WINAPI SetPrinterDataExW(HANDLE hPrinter,LPCWSTR pKeyName,LPCWSTR pValueName,DWORD Type,LPBYTE pData,DWORD cbData);
#ifdef UNICODE
#define SetPrinterDataEx SetPrinterDataExW
#else
#define SetPrinterDataEx SetPrinterDataExA
#endif 
DWORD WINAPI DeletePrinterDataA(HANDLE hPrinter,LPSTR pValueName);
DWORD WINAPI DeletePrinterDataW(HANDLE hPrinter,LPWSTR pValueName);
#ifdef UNICODE
#define DeletePrinterData DeletePrinterDataW
#else
#define DeletePrinterData DeletePrinterDataA
#endif 
DWORD WINAPI DeletePrinterDataExA(HANDLE hPrinter,LPCSTR pKeyName,LPCSTR pValueName);
DWORD WINAPI DeletePrinterDataExW(HANDLE hPrinter,LPCWSTR pKeyName,LPCWSTR pValueName);
#ifdef UNICODE
#define DeletePrinterDataEx DeletePrinterDataExW
#else
#define DeletePrinterDataEx DeletePrinterDataExA
#endif 
DWORD WINAPI DeletePrinterKeyA(HANDLE hPrinter,LPCSTR pKeyName);
DWORD WINAPI DeletePrinterKeyW(HANDLE hPrinter,LPCWSTR pKeyName);
#ifdef UNICODE
#define DeletePrinterKey DeletePrinterKeyW
#else
#define DeletePrinterKey DeletePrinterKeyA
#endif 
#define PRINTER_NOTIFY_TYPE 0
#define JOB_NOTIFY_TYPE 1
#define PRINTER_NOTIFY_FIELD_SERVER_NAME 0
#define PRINTER_NOTIFY_FIELD_PRINTER_NAME 1
#define PRINTER_NOTIFY_FIELD_SHARE_NAME 2
#define PRINTER_NOTIFY_FIELD_PORT_NAME 3
#define PRINTER_NOTIFY_FIELD_DRIVER_NAME 4
#define PRINTER_NOTIFY_FIELD_COMMENT 5
#define PRINTER_NOTIFY_FIELD_LOCATION 6
#define PRINTER_NOTIFY_FIELD_DEVMODE 7
#define PRINTER_NOTIFY_FIELD_SEPFILE 8
#define PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR 9
#define PRINTER_NOTIFY_FIELD_PARAMETERS 10
#define PRINTER_NOTIFY_FIELD_DATATYPE 11
#define PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR 12
#define PRINTER_NOTIFY_FIELD_ATTRIBUTES 13
#define PRINTER_NOTIFY_FIELD_PRIORITY 14
#define PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY 15
#define PRINTER_NOTIFY_FIELD_START_TIME 16
#define PRINTER_NOTIFY_FIELD_UNTIL_TIME 17
#define PRINTER_NOTIFY_FIELD_STATUS 18
#define PRINTER_NOTIFY_FIELD_STATUS_STRING 19
#define PRINTER_NOTIFY_FIELD_CJOBS 20
#define PRINTER_NOTIFY_FIELD_AVERAGE_PPM 21
#define PRINTER_NOTIFY_FIELD_TOTAL_PAGES 22
#define PRINTER_NOTIFY_FIELD_PAGES_PRINTED 23
#define PRINTER_NOTIFY_FIELD_TOTAL_BYTES 24
#define PRINTER_NOTIFY_FIELD_BYTES_PRINTED 25
#define PRINTER_NOTIFY_FIELD_OBJECT_GUID 26
#define JOB_NOTIFY_FIELD_PRINTER_NAME 0
#define JOB_NOTIFY_FIELD_MACHINE_NAME 1
#define JOB_NOTIFY_FIELD_PORT_NAME 2
#define JOB_NOTIFY_FIELD_USER_NAME 3
#define JOB_NOTIFY_FIELD_NOTIFY_NAME 4
#define JOB_NOTIFY_FIELD_DATATYPE 5
#define JOB_NOTIFY_FIELD_PRINT_PROCESSOR 6
#define JOB_NOTIFY_FIELD_PARAMETERS 7
#define JOB_NOTIFY_FIELD_DRIVER_NAME 8
#define JOB_NOTIFY_FIELD_DEVMODE 9
#define JOB_NOTIFY_FIELD_STATUS 10
#define JOB_NOTIFY_FIELD_STATUS_STRING 11
#define JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR 12
#define JOB_NOTIFY_FIELD_DOCUMENT 13
#define JOB_NOTIFY_FIELD_PRIORITY 14
#define JOB_NOTIFY_FIELD_POSITION 15
#define JOB_NOTIFY_FIELD_SUBMITTED 16
#define JOB_NOTIFY_FIELD_START_TIME 17
#define JOB_NOTIFY_FIELD_UNTIL_TIME 18
#define JOB_NOTIFY_FIELD_TIME 19
#define JOB_NOTIFY_FIELD_TOTAL_PAGES 20
#define JOB_NOTIFY_FIELD_PAGES_PRINTED 21
#define JOB_NOTIFY_FIELD_TOTAL_BYTES 22
#define JOB_NOTIFY_FIELD_BYTES_PRINTED 23
typedef struct _PRINTER_NOTIFY_OPTIONS_TYPE {
	WORD Type;
	WORD Reserved0;
	DWORD Reserved1;
	DWORD Reserved2;
	DWORD Count;
	PWORD pFields;
} PRINTER_NOTIFY_OPTIONS_TYPE,*PPRINTER_NOTIFY_OPTIONS_TYPE,*LPPRINTER_NOTIFY_OPTIONS_TYPE;
#define PRINTER_NOTIFY_OPTIONS_REFRESH 1
typedef struct _PRINTER_NOTIFY_OPTIONS {
	DWORD Version;
	DWORD Flags;
	DWORD Count;
	PPRINTER_NOTIFY_OPTIONS_TYPE pTypes;
} PRINTER_NOTIFY_OPTIONS,*PPRINTER_NOTIFY_OPTIONS,*LPPRINTER_NOTIFY_OPTIONS;
#define PRINTER_NOTIFY_INFO_DISCARDED 1
typedef struct _PRINTER_NOTIFY_INFO_DATA {
	WORD Type;
	WORD Field;
	DWORD Reserved;
	DWORD Id;
	union {
		DWORD adwData[2];
		struct {
			DWORD cbBuf;
			LPVOID pBuf;
		} Data;
	} NotifyData;
} PRINTER_NOTIFY_INFO_DATA,*PPRINTER_NOTIFY_INFO_DATA,*LPPRINTER_NOTIFY_INFO_DATA;
typedef struct _PRINTER_NOTIFY_INFO {
	DWORD Version;
	DWORD Flags;
	DWORD Count;
	PRINTER_NOTIFY_INFO_DATA aData[1];
} PRINTER_NOTIFY_INFO,*PPRINTER_NOTIFY_INFO,*LPPRINTER_NOTIFY_INFO;
typedef struct _BINARY_CONTAINER{
	DWORD cbBuf;
	LPBYTE pData;
} BINARY_CONTAINER,*PBINARY_CONTAINER;
typedef struct _BIDI_DATA{
	DWORD dwBidiType;
	union {
		BOOL bData;
		LONG iData;
		LPWSTR sData;
		FLOAT fData;
		BINARY_CONTAINER biData;
		}u;
} BIDI_DATA,*PBIDI_DATA,*LPBIDI_DATA;
typedef struct _BIDI_REQUEST_DATA{
	DWORD dwReqNumber;
	LPWSTR pSchema;
	BIDI_DATA data;
} BIDI_REQUEST_DATA,*PBIDI_REQUEST_DATA,*LPBIDI_REQUEST_DATA;
typedef struct _BIDI_REQUEST_CONTAINER{
	DWORD Version;
	DWORD Flags;
	DWORD Count;
	BIDI_REQUEST_DATA aData[ 1 ];
}BIDI_REQUEST_CONTAINER,*PBIDI_REQUEST_CONTAINER,*LPBIDI_REQUEST_CONTAINER;
typedef struct _BIDI_RESPONSE_DATA{
	DWORD dwResult;
	DWORD dwReqNumber;
	LPWSTR pSchema;
	BIDI_DATA data;
} BIDI_RESPONSE_DATA,*PBIDI_RESPONSE_DATA,*LPBIDI_RESPONSE_DATA;
typedef struct _BIDI_RESPONSE_CONTAINER{
	DWORD Version;
	DWORD Flags;
	DWORD Count;
	BIDI_RESPONSE_DATA aData[ 1 ];
} BIDI_RESPONSE_CONTAINER,*PBIDI_RESPONSE_CONTAINER,*LPBIDI_RESPONSE_CONTAINER;
#define BIDI_ACTION_ENUM_SCHEMA L"EnumSchema"
#define BIDI_ACTION_GET L"Get"
#define BIDI_ACTION_SET L"Set"
#define BIDI_ACTION_GET_ALL L"GetAll"
typedef enum {
	BIDI_NULL=0,BIDI_INT=1,BIDI_FLOAT=2,BIDI_BOOL=3,BIDI_STRING=4,BIDI_TEXT=5,BIDI_ENUM=6,BIDI_BLOB=7
} BIDI_TYPE;
#define BIDI_ACCESS_ADMINISTRATOR 1
#define BIDI_ACCESS_USER 2
#define ERROR_BIDI_STATUS_OK 0
#define ERROR_BIDI_NOT_SUPPORTED ERROR_NOT_SUPPORTED
#define ERROR_BIDI_ERROR_BASE 13000
#define ERROR_BIDI_STATUS_WARNING (ERROR_BIDI_ERROR_BASE + 1)
#define ERROR_BIDI_SCHEMA_READ_ONLY (ERROR_BIDI_ERROR_BASE + 2)
#define ERROR_BIDI_SERVER_OFFLINE (ERROR_BIDI_ERROR_BASE + 3)
#define ERROR_BIDI_DEVICE_OFFLINE (ERROR_BIDI_ERROR_BASE + 4)
#define ERROR_BIDI_SCHEMA_NOT_SUPPORTED (ERROR_BIDI_ERROR_BASE + 5)
DWORD WINAPI WaitForPrinterChange(HANDLE hPrinter,DWORD Flags);
HANDLE WINAPI FindFirstPrinterChangeNotification(HANDLE hPrinter,DWORD fdwFlags,DWORD fdwOptions,LPVOID pPrinterNotifyOptions);
BOOL WINAPI FindNextPrinterChangeNotification(HANDLE hChange,PDWORD pdwChange,LPVOID pvReserved,LPVOID *ppPrinterNotifyInfo);
BOOL WINAPI FreePrinterNotifyInfo(PPRINTER_NOTIFY_INFO pPrinterNotifyInfo);
BOOL WINAPI FindClosePrinterChangeNotification(HANDLE hChange);
#define PRINTER_CHANGE_ADD_PRINTER 1
#define PRINTER_CHANGE_SET_PRINTER 2
#define PRINTER_CHANGE_DELETE_PRINTER 4
#define PRINTER_CHANGE_FAILED_CONNECTION_PRINTER 8
#define PRINTER_CHANGE_PRINTER 255
#define PRINTER_CHANGE_ADD_JOB 256
#define PRINTER_CHANGE_SET_JOB 512
#define PRINTER_CHANGE_DELETE_JOB 1024
#define PRINTER_CHANGE_WRITE_JOB 2048
#define PRINTER_CHANGE_JOB 0xff00
#define PRINTER_CHANGE_ADD_FORM 0x10000
#define PRINTER_CHANGE_SET_FORM 0x20000
#define PRINTER_CHANGE_DELETE_FORM 0x40000
#define PRINTER_CHANGE_FORM 0x70000
#define PRINTER_CHANGE_ADD_PORT 0x100000
#define PRINTER_CHANGE_CONFIGURE_PORT 0x200000
#define PRINTER_CHANGE_DELETE_PORT 0x400000
#define PRINTER_CHANGE_PORT 0x700000
#define PRINTER_CHANGE_ADD_PRINT_PROCESSOR 0x1000000
#define PRINTER_CHANGE_DELETE_PRINT_PROCESSOR 0x4000000
#define PRINTER_CHANGE_PRINT_PROCESSOR 0x7000000
#define PRINTER_CHANGE_ADD_PRINTER_DRIVER 0x10000000
#define PRINTER_CHANGE_SET_PRINTER_DRIVER 0x20000000
#define PRINTER_CHANGE_DELETE_PRINTER_DRIVER 0x40000000
#define PRINTER_CHANGE_PRINTER_DRIVER 0x70000000
#define PRINTER_CHANGE_TIMEOUT 0x80000000
#define PRINTER_CHANGE_ALL 0x7777ffff
DWORD WINAPI PrinterMessageBoxA(HANDLE hPrinter,DWORD Error,HWND hWnd,LPSTR pText,LPSTR pCaption,DWORD dwType);
DWORD WINAPI PrinterMessageBoxW(HANDLE hPrinter,DWORD Error,HWND hWnd,LPWSTR pText,LPWSTR pCaption,DWORD dwType);
#ifdef UNICODE
#define PrinterMessageBox PrinterMessageBoxW
#else
#define PrinterMessageBox PrinterMessageBoxA
#endif 
#define PRINTER_ERROR_INFORMATION 0x80000000
#define PRINTER_ERROR_WARNING 0x40000000
#define PRINTER_ERROR_SEVERE 0x20000000
#define PRINTER_ERROR_OUTOFPAPER 1
#define PRINTER_ERROR_JAM 2
#define PRINTER_ERROR_OUTOFTONER 4
BOOL WINAPI ClosePrinter(HANDLE hPrinter);
BOOL WINAPI AddFormA(HANDLE hPrinter,DWORD Level,LPBYTE pForm);
BOOL WINAPI AddFormW(HANDLE hPrinter,DWORD Level,LPBYTE pForm);
#ifdef UNICODE
#define AddForm AddFormW
#else
#define AddForm AddFormA
#endif 
BOOL WINAPI DeleteFormA(HANDLE hPrinter,LPSTR pFormName);
BOOL WINAPI DeleteFormW(HANDLE hPrinter,LPWSTR pFormName);
#ifdef UNICODE
#define DeleteForm DeleteFormW
#else
#define DeleteForm DeleteFormA
#endif 
BOOL WINAPI GetFormA(HANDLE hPrinter,LPSTR pFormName,DWORD Level,LPBYTE pForm,DWORD cbBuf,LPDWORD pcbNeeded);
BOOL WINAPI GetFormW(HANDLE hPrinter,LPWSTR pFormName,DWORD Level,LPBYTE pForm,DWORD cbBuf,LPDWORD pcbNeeded);
#ifdef UNICODE
#define GetForm GetFormW
#else
#define GetForm GetFormA
#endif 
BOOL WINAPI SetFormA(HANDLE hPrinter,LPSTR pFormName,DWORD Level,LPBYTE pForm);
BOOL WINAPI SetFormW(HANDLE hPrinter,LPWSTR pFormName,DWORD Level,LPBYTE pForm);
#ifdef UNICODE
#define SetForm SetFormW
#else
#define SetForm SetFormA
#endif 
BOOL WINAPI EnumFormsA(HANDLE hPrinter,DWORD Level,LPBYTE pForm,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
BOOL WINAPI EnumFormsW(HANDLE hPrinter,DWORD Level,LPBYTE pForm,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
#ifdef UNICODE
#define EnumForms EnumFormsW
#else
#define EnumForms EnumFormsA
#endif 
BOOL WINAPI EnumMonitorsA(LPSTR pName,DWORD Level,LPBYTE pMonitors,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
BOOL WINAPI EnumMonitorsW(LPWSTR pName,DWORD Level,LPBYTE pMonitors,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
#ifdef UNICODE
#define EnumMonitors EnumMonitorsW
#else
#define EnumMonitors EnumMonitorsA
#endif 
BOOL WINAPI AddMonitorA(LPSTR pName,DWORD Level,LPBYTE pMonitors);
BOOL WINAPI AddMonitorW(LPWSTR pName,DWORD Level,LPBYTE pMonitors);
#ifdef UNICODE
#define AddMonitor AddMonitorW
#else
#define AddMonitor AddMonitorA
#endif 
BOOL WINAPI DeleteMonitorA(LPSTR pName,LPSTR pEnvironment,LPSTR pMonitorName);
BOOL WINAPI DeleteMonitorW(LPWSTR pName,LPWSTR pEnvironment,LPWSTR pMonitorName);
#ifdef UNICODE
#define DeleteMonitor DeleteMonitorW
#else
#define DeleteMonitor DeleteMonitorA
#endif 
BOOL WINAPI EnumPortsA(LPSTR pName,DWORD Level,LPBYTE pPorts,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
BOOL WINAPI EnumPortsW(LPWSTR pName,DWORD Level,LPBYTE pPorts,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned);
#ifdef UNICODE
#define EnumPorts EnumPortsW
#else
#define EnumPorts EnumPortsA
#endif 
BOOL WINAPI AddPortA(LPSTR pName,HWND hWnd,LPSTR pMonitorName);
BOOL WINAPI AddPortW(LPWSTR pName,HWND hWnd,LPWSTR pMonitorName);
#ifdef UNICODE
#define AddPort AddPortW
#else
#define AddPort AddPortA
#endif 
BOOL WINAPI ConfigurePortA(LPSTR pName,HWND hWnd,LPSTR pPortName);
BOOL WINAPI ConfigurePortW(LPWSTR pName,HWND hWnd,LPWSTR pPortName);
#ifdef UNICODE
#define ConfigurePort ConfigurePortW
#else
#define ConfigurePort ConfigurePortA
#endif 
BOOL WINAPI DeletePortA(LPSTR pName,HWND hWnd,LPSTR pPortName);
BOOL WINAPI DeletePortW(LPWSTR pName,HWND hWnd,LPWSTR pPortName);
#ifdef UNICODE
#define DeletePort DeletePortW
#else
#define DeletePort DeletePortA
#endif 
BOOL WINAPI XcvDataW(HANDLE hXcv,PCWSTR pszDataName,PBYTE pInputData,DWORD cbInputData,PBYTE pOutputData,DWORD cbOutputData,PDWORD pcbOutputNeeded,PDWORD pdwStatus);
#define XcvData XcvDataW
BOOL WINAPI GetDefaultPrinterA(LPSTR pszBuffer,LPDWORD pcchBuffer);
BOOL WINAPI GetDefaultPrinterW(LPWSTR pszBuffer,LPDWORD pcchBuffer);
#ifdef UNICODE
#define GetDefaultPrinter GetDefaultPrinterW
#else
#define GetDefaultPrinter GetDefaultPrinterA
#endif 
BOOL WINAPI SetDefaultPrinterA(LPCSTR pszPrinter);
BOOL WINAPI SetDefaultPrinterW(LPCWSTR pszPrinter);
#ifdef UNICODE
#define SetDefaultPrinter SetDefaultPrinterW
#else
#define SetDefaultPrinter SetDefaultPrinterA
#endif 
BOOL WINAPI SetPortA(LPSTR pName,LPSTR pPortName,DWORD dwLevel,LPBYTE pPortInfo);
BOOL WINAPI SetPortW(LPWSTR pName,LPWSTR pPortName,DWORD dwLevel,LPBYTE pPortInfo);
#ifdef UNICODE
#define SetPort SetPortW
#else
#define SetPort SetPortA
#endif 
BOOL WINAPI AddPrinterConnectionA(LPSTR pName);
BOOL WINAPI AddPrinterConnectionW(LPWSTR pName);
#ifdef UNICODE
#define AddPrinterConnection AddPrinterConnectionW
#else
#define AddPrinterConnection AddPrinterConnectionA
#endif 
BOOL WINAPI DeletePrinterConnectionA(LPSTR pName);
BOOL WINAPI DeletePrinterConnectionW(LPWSTR pName);
#ifdef UNICODE
#define DeletePrinterConnection DeletePrinterConnectionW
#else
#define DeletePrinterConnection DeletePrinterConnectionA
#endif 
HANDLE WINAPI ConnectToPrinterDlg(HWND hwnd,DWORD Flags);
typedef struct _PROVIDOR_INFO_1A{
	LPSTR pName;
	LPSTR pEnvironment;
	LPSTR pDLLName;
} PROVIDOR_INFO_1A,*PPROVIDOR_INFO_1A,*LPPROVIDOR_INFO_1A;
typedef struct _PROVIDOR_INFO_1W{
	LPWSTR pName;
	LPWSTR pEnvironment;
	LPWSTR pDLLName;
} PROVIDOR_INFO_1W,*PPROVIDOR_INFO_1W,*LPPROVIDOR_INFO_1W;
#ifdef UNICODE
typedef PROVIDOR_INFO_1W PROVIDOR_INFO_1;
typedef PPROVIDOR_INFO_1W PPROVIDOR_INFO_1;
typedef LPPROVIDOR_INFO_1W LPPROVIDOR_INFO_1;
#else
typedef PROVIDOR_INFO_1A PROVIDOR_INFO_1;
typedef PPROVIDOR_INFO_1A PPROVIDOR_INFO_1;
typedef LPPROVIDOR_INFO_1A LPPROVIDOR_INFO_1;
#endif 
typedef struct _PROVIDOR_INFO_2A{
	LPSTR pOrder;
} PROVIDOR_INFO_2A,*PPROVIDOR_INFO_2A,*LPPROVIDOR_INFO_2A;
typedef struct _PROVIDOR_INFO_2W{
	LPWSTR pOrder;
} PROVIDOR_INFO_2W,*PPROVIDOR_INFO_2W,*LPPROVIDOR_INFO_2W;
#ifdef UNICODE
typedef PROVIDOR_INFO_2W PROVIDOR_INFO_2;
typedef PPROVIDOR_INFO_2W PPROVIDOR_INFO_2;
typedef LPPROVIDOR_INFO_2W LPPROVIDOR_INFO_2;
#else
typedef PROVIDOR_INFO_2A PROVIDOR_INFO_2;
typedef PPROVIDOR_INFO_2A PPROVIDOR_INFO_2;
typedef LPPROVIDOR_INFO_2A LPPROVIDOR_INFO_2;
#endif 
BOOL WINAPI AddPrintProvidorA(LPSTR pName,DWORD level,LPBYTE pProvidorInfo);
BOOL WINAPI AddPrintProvidorW(LPWSTR pName,DWORD level,LPBYTE pProvidorInfo);
#ifdef UNICODE
#define AddPrintProvidor AddPrintProvidorW
#else
#define AddPrintProvidor AddPrintProvidorA
#endif 
BOOL WINAPI DeletePrintProvidorA(LPSTR pName,LPSTR pEnvironment,LPSTR pPrintProvidorName);
BOOL WINAPI DeletePrintProvidorW(LPWSTR pName,LPWSTR pEnvironment,LPWSTR pPrintProvidorName);
#ifdef UNICODE
#define DeletePrintProvidor DeletePrintProvidorW
#else
#define DeletePrintProvidor DeletePrintProvidorA
#endif 
BOOL WINAPI IsValidDevmodeA(PDEVMODEA pDevmode,size_t DevmodeSize);
BOOL WINAPI IsValidDevmodeW(PDEVMODEW pDevmode,size_t DevmodeSize);
#ifdef UNICODE
#define IsValidDevmode IsValidDevmodeW
#else
#define IsValidDevmode IsValidDevmodeA
#endif 
#define SPLREG_DEFAULT_SPOOL_DIRECTORY TEXT("DefaultSpoolDirectory")
#define SPLREG_PORT_THREAD_PRIORITY_DEFAULT TEXT("PortThreadPriorityDefault")
#define SPLREG_PORT_THREAD_PRIORITY TEXT("PortThreadPriority")
#define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT TEXT("SchedulerThreadPriorityDefault")
#define SPLREG_SCHEDULER_THREAD_PRIORITY TEXT("SchedulerThreadPriority")
#define SPLREG_BEEP_ENABLED TEXT("BeepEnabled")
#define SPLREG_NET_POPUP TEXT("NetPopup")
#define SPLREG_RETRY_POPUP TEXT("RetryPopup")
#define SPLREG_NET_POPUP_TO_COMPUTER TEXT("NetPopupToComputer")
#define SPLREG_EVENT_LOG TEXT("EventLog")
#define SPLREG_MAJOR_VERSION TEXT("MajorVersion")
#define SPLREG_MINOR_VERSION TEXT("MinorVersion")
#define SPLREG_ARCHITECTURE TEXT("Architecture")
#define SPLREG_OS_VERSION TEXT("OSVersion")
#define SPLREG_OS_VERSIONEX TEXT("OSVersionEx")
#define SPLREG_DS_PRESENT TEXT("DsPresent")
#define SPLREG_DS_PRESENT_FOR_USER TEXT("DsPresentForUser")
#define SPLREG_REMOTE_FAX TEXT("RemoteFax")
#define SPLREG_RESTART_JOB_ON_POOL_ERROR TEXT("RestartJobOnPoolError")
#define SPLREG_RESTART_JOB_ON_POOL_ENABLED TEXT("RestartJobOnPoolEnabled")
#define SPLREG_DNS_MACHINE_NAME TEXT("DNSMachineName")
#define SPLREG_WEBSHAREMGMT TEXT("WebShareMgmt")
#define SERVER_ACCESS_ADMINISTER 1
#define SERVER_ACCESS_ENUMERATE 2
#define PRINTER_ACCESS_ADMINISTER 4
#define PRINTER_ACCESS_USE 8
#define JOB_ACCESS_ADMINISTER 16
#define JOB_ACCESS_READ 32
#define SERVER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SERVER_ACCESS_ADMINISTER|SERVER_ACCESS_ENUMERATE)
#define SERVER_READ (STANDARD_RIGHTS_READ|SERVER_ACCESS_ENUMERATE)
#define SERVER_WRITE (STANDARD_RIGHTS_WRITE|SERVER_ACCESS_ADMINISTER|SERVER_ACCESS_ENUMERATE)
#define SERVER_EXECUTE (STANDARD_RIGHTS_EXECUTE|SERVER_ACCESS_ENUMERATE)
#define PRINTER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|PRINTER_ACCESS_ADMINISTER|PRINTER_ACCESS_USE)
#define PRINTER_READ (STANDARD_RIGHTS_READ|PRINTER_ACCESS_USE)
#define PRINTER_WRITE (STANDARD_RIGHTS_WRITE|PRINTER_ACCESS_USE)
#define PRINTER_EXECUTE (STANDARD_RIGHTS_EXECUTE|PRINTER_ACCESS_USE)
#define JOB_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|JOB_ACCESS_ADMINISTER|JOB_ACCESS_READ)
#define JOB_READ (STANDARD_RIGHTS_READ|JOB_ACCESS_READ)
#define JOB_WRITE (STANDARD_RIGHTS_WRITE|JOB_ACCESS_ADMINISTER)
#define JOB_EXECUTE (STANDARD_RIGHTS_EXECUTE|JOB_ACCESS_ADMINISTER)
#define SPLDS_SPOOLER_KEY TEXT("DsSpooler")
#define SPLDS_DRIVER_KEY TEXT("DsDriver")
#define SPLDS_USER_KEY TEXT("DsUser")
#define SPLDS_ASSET_NUMBER TEXT("assetNumber")
#define SPLDS_BYTES_PER_MINUTE TEXT("bytesPerMinute")
#define SPLDS_DESCRIPTION TEXT("description")
#define SPLDS_DRIVER_NAME TEXT("driverName")
#define SPLDS_DRIVER_VERSION TEXT("driverVersion")
#define SPLDS_LOCATION TEXT("location")
#define SPLDS_PORT_NAME TEXT("portName")
#define SPLDS_PRINT_ATTRIBUTES TEXT("printAttributes")
#define SPLDS_PRINT_BIN_NAMES TEXT("printBinNames")
#define SPLDS_PRINT_COLLATE TEXT("printCollate")
#define SPLDS_PRINT_COLOR TEXT("printColor")
#define SPLDS_PRINT_DUPLEX_SUPPORTED TEXT("printDuplexSupported")
#define SPLDS_PRINT_END_TIME TEXT("printEndTime")
#define SPLDS_PRINTER_CLASS TEXT("printQueue")
#define SPLDS_PRINTER_NAME TEXT("printerName")
#define SPLDS_PRINT_KEEP_PRINTED_JOBS TEXT("printKeepPrintedJobs")
#define SPLDS_PRINT_LANGUAGE TEXT("printLanguage")
#define SPLDS_PRINT_MAC_ADDRESS TEXT("printMACAddress")
#define SPLDS_PRINT_MAX_X_EXTENT TEXT("printMaxXExtent")
#define SPLDS_PRINT_MAX_Y_EXTENT TEXT("printMaxYExtent")
#define SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED TEXT("printMaxResolutionSupported")
#define SPLDS_PRINT_MEDIA_READY TEXT("printMediaReady")
#define SPLDS_PRINT_MEDIA_SUPPORTED TEXT("printMediaSupported")
#define SPLDS_PRINT_MEMORY TEXT("printMemory")
#define SPLDS_PRINT_MIN_X_EXTENT TEXT("printMinXExtent")
#define SPLDS_PRINT_MIN_Y_EXTENT TEXT("printMinYExtent")
#define SPLDS_PRINT_NETWORK_ADDRESS TEXT("printNetworkAddress")
#define SPLDS_PRINT_NOTIFY TEXT("printNotify")
#define SPLDS_PRINT_NUMBER_UP TEXT("printNumberUp")
#define SPLDS_PRINT_ORIENTATIONS_SUPPORTED TEXT("printOrientationsSupported")
#define SPLDS_PRINT_OWNER TEXT("printOwner")
#define SPLDS_PRINT_PAGES_PER_MINUTE TEXT("printPagesPerMinute")
#define SPLDS_PRINT_RATE TEXT("printRate")
#define SPLDS_PRINT_RATE_UNIT TEXT("printRateUnit")
#define SPLDS_PRINT_SEPARATOR_FILE TEXT("printSeparatorFile")
#define SPLDS_PRINT_SHARE_NAME TEXT("printShareName")
#define SPLDS_PRINT_SPOOLING TEXT("printSpooling")
#define SPLDS_PRINT_STAPLING_SUPPORTED TEXT("printStaplingSupported")
#define SPLDS_PRINT_START_TIME TEXT("printStartTime")
#define SPLDS_PRINT_STATUS TEXT("printStatus")
#define SPLDS_PRIORITY TEXT("priority")
#define SPLDS_SERVER_NAME TEXT("serverName")
#define SPLDS_SHORT_SERVER_NAME TEXT("shortServerName")
#define SPLDS_UNC_NAME TEXT("uNCName")
#define SPLDS_URL TEXT("url")
#define SPLDS_FLAGS TEXT("flags")
#define SPLDS_VERSION_NUMBER TEXT("versionNumber")
#define SPLDS_PRINTER_NAME_ALIASES TEXT("printerNameAliases") 
#define SPLDS_PRINTER_LOCATIONS TEXT("printerLocations") 
#define SPLDS_PRINTER_MODEL TEXT("printerModel") 
#endif 
