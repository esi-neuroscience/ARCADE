/*---------------------------------------------------------------------------*/
/* except.h - exception routine header file                                  */
/*---------------------------------------------------------------------------*/
/*
 * Exception handler return codes
 */
#define EXCEPTION_CONTINUE_EXECUTION     0
#define EXCEPTION_CONTINUE_SEARCH        1

/* Exception codes */
#define EXCEPTION_ACCESS_VIOLATION          ((DWORD   )0xC0000005L)
#define EXCEPTION_DATATYPE_MISALIGNMENT     ((DWORD   )0x80000002L)
#define EXCEPTION_BREAKPOINT                ((DWORD   )0x80000003L)
#define EXCEPTION_SINGLE_STEP               ((DWORD   )0x80000004L)
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED     ((DWORD   )0xC000008CL)
#define EXCEPTION_FLT_DENORMAL_OPERAND      ((DWORD   )0xC000008DL)
#define EXCEPTION_FLT_DIVIDE_BY_ZERO        ((DWORD   )0xC000008EL)
#define EXCEPTION_FLT_INEXACT_RESULT        ((DWORD   )0xC000008FL)
#define EXCEPTION_FLT_INVALID_OPERATION     ((DWORD   )0xC0000090L)
#define EXCEPTION_FLT_OVERFLOW              ((DWORD   )0xC0000091L)
#define EXCEPTION_FLT_STACK_CHECK           ((DWORD   )0xC0000092L)
#define EXCEPTION_FLT_UNDERFLOW             ((DWORD   )0xC0000093L)
#define EXCEPTION_INT_DIVIDE_BY_ZERO        ((DWORD   )0xC0000094L)
#define EXCEPTION_INT_OVERFLOW              ((DWORD   )0xC0000095L)
#define EXCEPTION_PRIV_INSTRUCTION          ((DWORD   )0xC0000096L)
#define EXCEPTION_IN_PAGE_ERROR             ((DWORD   )0xC0000006L)
#define EXCEPTION_ILLEGAL_INSTRUCTION       ((DWORD   )0xC000001DL)
#define EXCEPTION_NONCONTINUABLE_EXCEPTION  ((DWORD   )0xC0000025L)
#define EXCEPTION_STACK_OVERFLOW            ((DWORD   )0xC00000FDL)
#define EXCEPTION_INVALID_DISPOSITION       ((DWORD   )0xC0000026L)
#define EXCEPTION_GUARD_PAGE                ((DWORD   )0x80000001L)
#define CONTROL_C_EXIT                      ((DWORD   )0xC000013AL)

/* maximum number of exception parameters */
#define EXCEPTION_MAXIMUM_PARAMETERS 15

/*
 * Exception disposition return values.
 */
typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;

typedef struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    DWORD ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
    } EXCEPTION_RECORD;

struct _CONTEXT;

typedef EXCEPTION_DISPOSITION EXCEPTION_HANDLER (
    struct _EXCEPTION_RECORD *ExceptionRecord,
    void * EstablisherFrame,
    struct _CONTEXT *ContextRecord,
    void * DispatcherContext
    );

struct _REGISTRATION_RECORD
   {
   struct _REGISTRATION_RECORD * pPreviousSEH;
   EXCEPTION_HANDLER           * pExceptionHandler;
   };

typedef struct _REGISTRATION_RECORD REGISTRATION_RECORD;
typedef REGISTRATION_RECORD *PREGISTRATION_RECORD;

EXCEPTION_HANDLER _seh;
VOID _SetExceptionHandler(PREGISTRATION_RECORD);
BOOL __declspec(dllimport) _ceh(DWORD CtrlType);


