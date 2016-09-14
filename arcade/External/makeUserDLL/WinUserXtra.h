#include <limits.h>
#include <stdarg.h>
#include <win.h>

/*
EnumDisplayDevicesA(
    __in_opt LPCSTR lpDevice,
    __in DWORD iDevNum,
    __inout PDISPLAY_DEVICEA lpDisplayDevice,
    __in DWORD dwFlags);

EnumDisplayDevicesW(
    __in_opt LPCWSTR lpDevice,
    __in DWORD iDevNum,
    __inout PDISPLAY_DEVICEW lpDisplayDevice,
    __in DWORD dwFlags);
*/

BOOL STDCALL EnumDisplayDevicesA(LPCSTR, DWORD, PDISPLAY_DEVICE, DWORD)        
BOOL STDCALL EnumDisplayDevicesW(LPCWSTR,DWORD, PDISPLAY_DEVICE, DWORD)        
        
#ifdef UNICODE
#define EnumDisplaySettings  EnumDisplayDevicesW
#else
#define EnumDisplaySettings  EnumDisplayDevicesA
#endif // !UNICODE        
        
typedef struct _DISPLAY_DEVICE {
  DWORD cb;
  TCHAR DeviceName[32];
  TCHAR DeviceString[128];
  DWORD StateFlags;
  TCHAR DeviceID[128];
  TCHAR DeviceKey[128];
} DISPLAY_DEVICE, *PDISPLAY_DEVICE;        
        
        

// LONG STDCALL ChangeDisplaySettingsW(LPDEVMODE,DWORD); // matlab
ChangeDisplaySettingsW(                // windows 
    __in_opt DEVMODEW* lpDevMode,
    __in DWORD dwFlags);




        
        
        








