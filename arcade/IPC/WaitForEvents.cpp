#include "Windows.h"
#include "mex.h"
#include <map>
#include <string>
#include <stdexcept>      // std::out_of_range

using namespace std;

static DWORD nInitializedHandles = 0;
static map<string, HANDLE> eventsMap;
static HANDLE* pEventHandles;

void Delete(void)
{
    for (auto it = begin(eventsMap); it!=end(eventsMap); ++it)
    {
        CloseHandle(it->second);
    }
    eventsMap.clear();
    delete []pEventHandles;
    nInitializedHandles = 0;
}

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
    HANDLE eventHandle;
    char eventName[32];
    DWORD waitResult;
    DWORD nHandles;
    DWORD nKnownEvents;
    DWORD lastError;
    switch ((unsigned char) mxGetScalar(prhs[0]))
    {
        case 0: // Init (define events to be used)
//            mexLock();
            if (nInitializedHandles > 0) Delete();
            nInitializedHandles = (DWORD) mxGetNumberOfElements(prhs[1]);
            pEventHandles = new HANDLE[nInitializedHandles];
            for (unsigned char i=0; i<nInitializedHandles; i++)
            {
                if (mxGetString(mxGetCell(prhs[1], i), eventName, 32))
                {
                    mexErrMsgIdAndTxt("WaitForEvents:Init",
                            "Error reading event name.");
                    return;
                }
//                mexPrintf("Event name: %s\n", eventName);
                eventHandle = OpenEvent(
                        SYNCHRONIZE | EVENT_MODIFY_STATE,
                        false,  // don't inherit in subprocesses
                        eventName);
                if (eventHandle)
                {
                    eventsMap[eventName] = eventHandle;
                }
                else
                {
//                    lastError = GetLastError();
                    mexWarnMsgIdAndTxt("WaitForEvents:OpenEvent",
                            "Could not open event %s.", eventName);
                }
            }
            break;
        case 1: // WaitFor
            nHandles = (DWORD) mxGetNumberOfElements(prhs[1]);
            nKnownEvents = 0;
            for (unsigned char i=0; i<nHandles; i++)
            {
                if (mxGetString(mxGetCell(prhs[1], i), eventName, 32))
                {
                    mexErrMsgIdAndTxt("WaitForEvents:Init",
                            "Error reading event name.");
                    return;
                }
                try {
                    pEventHandles[nKnownEvents] = eventsMap.at(eventName);
                    nKnownEvents++;
                }
                catch (const out_of_range& oor) {
                    mexWarnMsgIdAndTxt("WaitForEvents:Event",
                            "Unknown event: %s", eventName);
                }
            }
            waitResult = WaitForMultipleObjects(
                    nKnownEvents,
                    pEventHandles,
                    (bool) mxGetScalar(prhs[2]),
                    (DWORD) mxGetScalar(prhs[3]));
            plhs[0] = mxCreateDoubleScalar(
                    waitResult < nHandles ? waitResult+1 : waitResult);
            break;
        case 2: // Reset
            switch (nrhs)
            {
                case 1: // reset all events
                    for (auto it = begin(eventsMap); it!=end(eventsMap); ++it)
                    {
                        if (!ResetEvent(it->second))
                        {
                            mexErrMsgIdAndTxt("WaitForEvents:Reset",
                                    "ResetEvent error.");
                            return;
                        }
                    }
                    break;
                case 2: // reset the requeseted events
                    nHandles = (DWORD) mxGetNumberOfElements(prhs[1]);
                    for (unsigned char i=0; i<nHandles; i++)
                    {
                        if (mxGetString(mxGetCell(prhs[1], i), eventName, 32))
                        {
                            mexErrMsgIdAndTxt("WaitForEvents:Init",
                                    "Error reading event name.");
                            return;
                        }
                        try {
                            if (!ResetEvent(eventsMap.at(eventName)))
                            {
                                mexErrMsgIdAndTxt("WaitForEvents:Reset",
                                        "ResetEvent error.");
                                return;
                            }
                        }
                        catch (const out_of_range& oor) {
                            mexWarnMsgIdAndTxt("WaitForEvents:Reset",
                                    "Unknown event: %s", eventName);
                        }
                    }
                    break;
            }
            break;
        case 3: // delete
            Delete();
    }
//    mexPrintf("Number of arguments: %i\n", nrhs);
    return;
}
