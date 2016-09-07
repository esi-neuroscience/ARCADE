#include <Windows.h> 
#include <WinBase.h> 
#include <WinUser.h> 
//#include <stdlib.h>
#include "mex.h"
//#include <stdint.h> // for 32-bit int

//#include <string.h>
//#include <limits.h>
//#include <malloc.h>


struct myMonitor{
    int xPos;
    int yPos;
    int xPix;
    int yPix;
} monitors[5]; // assume num of monitors
// can make malloc later 


void assignMonitorSpec(struct myMonitor *ptrMonitor, int xPos, int yPos, int xPix, int yPix){
    ptrMonitor -> xPos = xPos;
    ptrMonitor -> yPos = yPos;
    ptrMonitor -> xPix = xPix;
    ptrMonitor -> yPix = yPix;
}

void secondMonitorWindow(void){
    
    // window handle 
    HWND hwnd;
    
    // get monitors
    int secondaryMonitors = 0; // total monitors is +1
    int assignMonitor     = 0;
    
    DWORD adapterIndex    = 0;

    for (;;){
        
        DISPLAY_DEVICE adapter, display;
        DEVMODE settings;
        
        ZeroMemory(&adapter, sizeof(DISPLAY_DEVICE));
        adapter.cb = sizeof(DISPLAY_DEVICE);

        // is not a monitor
        if (!EnumDisplayDevices(NULL, adapterIndex, &adapter, 0))
            break;
        
        adapterIndex++;

        // is a monitor
        if ((adapter.StateFlags & DISPLAY_DEVICE_MIRRORING_DRIVER) ||
            !(adapter.StateFlags & DISPLAY_DEVICE_ACTIVE)){
            continue;
        }
        
        ZeroMemory(&display, sizeof(DISPLAY_DEVICE));
        display.cb = sizeof(DISPLAY_DEVICE);
        
        // get display
        EnumDisplayDevices(adapter.DeviceName, 0, &display, 0);

        if (adapter.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE){
            assignMonitor = 0; // reserve the first position for the primary monitor 
            mexPrintf("Found primary monitor");
        }
        else{ 
            // increment count for secondary monitor
            mexPrintf("Found secondary monitor");
            secondaryMonitors++; 
            assignMonitor = secondaryMonitors;
        } 
        
        // get device size and position 
        ZeroMemory(&settings, sizeof(DEVMODE));
        settings.dmSize = sizeof(DEVMODE);
        
        EnumDisplaySettingsEx(adapter.DeviceName,
                ENUM_CURRENT_SETTINGS,
                &settings,
                EDS_ROTATEDMODE);
    
        // assign size and position
        assignMonitorSpec(&monitors[assignMonitor], 
                          settings.dmPosition.x, 
                          settings.dmPosition.y,
                          settings.dmPelsWidth,
                          settings.dmPelsHeight);
    }
    
    // check if any secondary monitors 
    if (!secondaryMonitors)
        useMon = 0; // switch to primary monitor 
    
    
    
    
}


void mexFunction(int nlhs, mxArray *plhs[],
        int nrhs, const mxArray *prhs[]) {


//int numdisplays = 0;

    secondMonitorWindow();
    
   
    
}


















