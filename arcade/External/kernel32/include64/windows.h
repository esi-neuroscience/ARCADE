#ifndef __windows_h__
#define __windows_h__
#ifndef WINVER
#define WINVER 1281
#else
#if defined(_WIN32_WINNT) && (WINVER < 0x0400) && (_WIN32_WINNT > 0x0400)
#error WINVER setting conflicts with _WIN32_WINNT setting
#endif
#endif	// WINVER
#ifndef _INC_WINDOWS
#define _INC_WINDOWS
#pragma once
#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#define NODESKTOP
#define NOWINRES
#define NOWINDOWSTATION
#define NOSECURITY
#define NOCLIPBOARD
#define NOWINSTYLES
#define NOMSG
#define NOGDI
#define NOCTLMGR
#define NODRAWTEXT
#define NOSCROLL
#define NOWINOFFSETS
#define NOWH
#define NOHELP
#define NOSYSPARAMSINFO
#define NOWINABLE

#if defined(RC_INVOKED) && !defined(NOWINRES)
#include <winresrc.h>
#else
#if defined(RC_INVOKED)
#define NOATOM
#define NOGDI
#define NOGDICAPMASKS
#define NOMETAFILE
#define NOMINMAX
#define NOMSG
#define NOOPENFILE
#define NORASTEROPS
#define NOSCROLL
#define NOSOUND
#define NOSYSMETRICS
#define NOTEXTMETRIC
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOCRYPT
#define NOMCX
#endif	// RC_INVOKED
#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(_M_IX86)
#define _X86_
#endif
#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(_M_AMD64)
#define _AMD64_
#endif
#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(_M_M68K)
#define _68K_
#endif
#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(_M_MPPC)
#define _MPPC_
#endif
#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_M_IX86) && !defined(_AMD64_) && defined(_M_IA64)
#if !defined(_IA64_)
#define _IA64_
#endif 
#endif
#ifndef _MAC
#if defined(_68K_) || defined(_MPPC_)
#define _MAC
#endif
#endif
#if defined (_MSC_VER)
#if (_MSC_VER >= 800)
#ifndef __cplusplus
#pragma warning(disable:4116) 
#endif
#endif
#endif
#ifndef RC_INVOKED
#if (_MSC_VER >= 800)
#pragma warning(disable:4514)
#ifndef __WINDOWS_DONT_DISABLE_PRAGMA_PACK_WARNING__
#pragma warning(disable:4103)
#endif
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4001)
#pragma warning(disable:4201)
#pragma warning(disable:4214)
#endif
#include <excpt.h>
#include <stdarg.h>
#endif 
#include <windef.h>
#include <winbase.h>
// #include <wingdi.h>
#include <winuser.h>
#if !defined(_MAC) || defined(_WIN32NLS)
//#include <winnls.h>
#endif
#ifndef _MAC
//#include <wincon.h>
//#include <winver.h>
#endif
#if !defined(_MAC) || defined(_WIN32REG)
//#include <winreg.h>
#endif
#ifndef _MAC
//#include <winnetwk.h>
#endif
#ifndef WIN32_LEAN_AND_MEAN
//#include <cderr.h>
//#include <dde.h>
//#include <ddeml.h>
//#include <dlgs.h>
#ifndef _MAC
//#include <lzexpand.h>
//#include <mmsystem.h>
//#include <nb30.h>
//#include <rpc.h>
#endif
//#include <shellapi.h>
#ifndef _MAC
//#include <winperf.h>
//#include <winsock.h>
#endif
#ifndef NOCRYPT
//#include <wincrypt.h>
//#include <winefs.h>
//#include <winscard.h>
#endif
#ifndef NOGDI
#ifndef _MAC
//#include <winspool.h>
#ifdef INC_OLE1
//#include <ole.h>
#else
//#include <ole2.h>
#endif 
#endif 
//#include <commdlg.h>
#endif 
#endif 
//#include <stralign.h>
#ifdef _MAC
//#include <winwlm.h>
#endif
#ifdef INC_OLE2
//#include <ole2.h>
#endif 
#ifndef _MAC
#ifndef NOSERVICE
//#include <winsvc.h>
#endif
#if(WINVER >= 0x0400)
#ifndef NOMCX
//#include <mcx.h>
#endif 
#ifndef NOIME
//#include <imm.h>
#endif
#endif 
#endif
#ifndef RC_INVOKED
#if (_MSC_VER >= 800)
#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4001)
#pragma warning(default:4201)
#pragma warning(default:4214)
#endif
#endif
#endif 
#endif 
#endif 
#endif 
