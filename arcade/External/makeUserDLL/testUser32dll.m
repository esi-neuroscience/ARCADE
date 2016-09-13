close all
clear all
clc

addpath('H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\External\makeUserDLL');

addpath('H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\External\gethwnd');
% ChangeDisplaySettingsA
% PeekNamedPipe
% ImpersonateNamedPipeClient
% ShowWindow 
% CloseWindow
% BringWindowToTop
% SetFocus 
% GetActiveWindow

% GetActiveWindow

% AbortProc
%GetDesktopWindow
%ShowCursor 

cd(fileparts(mfilename('fullpath')));

% SetForegroundWindow

% - SetFocus - 
%Sets the keyboard focus to the specified window.
%The window must be attached to the calling thread's message queue. 

% - GetFocus -
% The return value is the handle to the window with the keyboard focus. 
% If the calling thread's message queue does not have an associated 
% window with the keyboard focus, the return value is NULL. 

% - SetForegroundWindow - 
% Brings the thread that created the specified window into the foreground 
% and activates the window. Keyboard input is directed to the window, 
% and various visual cues are changed for the user. The system assigns 
% a slightly higher priority to the thread that created the foreground 
% window than it does to other threads. 


% - ShowWindow
%unloadlibrary('user32')

addpath('H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\dll_interfaces');
if ~libisloaded('user32'); loadlibrary('user32', @win_user32); end;


hwnd = calllib('user32', 'FindWindowA',[],'Command Window');
calllib('user32', 'SetForegroundWindow',hwnd) 

% If the function succeeds, the return value is nonzero
result = calllib('user32', 'BringWindowToTop',hwnd) 
% handle to original window if success, else Null
hwnd_ = calllib('user32', 'SetActiveWindow',hwnd) 


% Retrieves the window handle to the active window attached to the calling thread's message queue. 
hwnd_ = calllib('user32','GetActiveWindow');
% Retrieves the handle to the window that has the keyboard focus
hwnd_ = calllib('user32','GetFocus');

% Retrieves a handle to the foreground window
hwnd_ = calllib('user32','GetForegroundWindow');

% Sets the keyboard focus to the specified window. 
% handle to original window if success, else Null
hwnd_ = calllib('user32', 'SetFocus',hwnd); 

result = calllib('user32', 'CloseWindow',hwnd); % A handle to the window to be minimized. 

result = calllib('user32', 'DestroyWindow',hwnd); % A handle to the window to be destroyed. 








buffer   = char(zeros(1,40));
nBuf     = int32(length(buffer));
nWRITTEN = int32(0);
[nWRITTEN, ~, buffer] = calllib('user32', 'GetClassNameA', hwnd, buffer, nBuf);

nWRITTEN = calllib('user32', 'GetClassNameA', hwnd, buffer, nBuf);


% 'SunAwtFrame' -> command window 

hfig = figure(100);
hwnd2 = calllib('user32', 'FindWindowA','SunAwtFrame','Figure 100');





buffer2   = char(zeros(1,40));
nBuf2     = int32(length(buffer2));
nWRITTEN = int32(0);
[nWRITTEN, ~, buffer2] = calllib('user32', 'GetClassNameA', hwnd2, buffer2, nBuf2);


hfig = figure(10);
% give it soem time after the figure has been created 
hwnd3 = calllib('user32', 'FindWindowA','SunAwtFrame','Figure 10');
calllib('user32', 'SetForegroundWindow',hwnd3) 


SW_MINIMIZE = 6;
SW_HIDE     = 0;
SW_FORCEMINIMIZE = 11;
SW_RESTORE  = 9;

result = calllib('user32', 'ShowWindow',hwnd3, SW_RESTORE); % restores window 
result = calllib('user32', 'ShowWindow',hwnd3, SW_HIDE);    % window not visible at all
result = calllib('user32', 'ShowWindow',hwnd3, SW_MINIMIZE); % minimizes window 

result = calllib('user32', 'ShowWindow',hwnd3, SW_FORCEMINIMIZE); % when not calling for the owner thread


hfig = figure;


hWnd = gethwnd(hfig);

hWndt = libpointer('voidPtr',hWnd);

calllib('user32', 'SetForegroundWindow',hWndt) 




calllib('user32', 'BringWindowToTop',uint32(hWnd)) % does not work 
calllib('user32', 'SetForegroundWindow',int32(hWnd))

callBringWindowToTop(hWnd)


hwnd = int32(0); 
hwnd = calllib('user32', 'GetFocus');


calllib('user32', 'SetForegroundWindow',hwnd) % works 


%jf = get(handle(hfig),'JavaFrame')

%jframe = jf.fFigureClient.getWindow
%jframe = jf.fHG1Client.getWindow


% works 
hwnd2 = libpointer('voidPtr'); 
hwnd2 = calllib('user32', 'FindWindowA',[],'Figure 2');

calllib('user32', 'SetForegroundWindow',hwnd2) 
calllib('user32', 'BringWindowToTop',hwnd2)
calllib('user32', 'SetFocus',hwnd2)

calllib('user32', 'CloseWindow',hwnd2) % minimizes the window 


% finds the window regardless if
% it is in anothe thread

hwnd1 = libpointer('voidPtr'); 
hwnd1 = calllib('user32', 'FindWindowA',[],'Figure 100')

calllib('user32', 'SetForegroundWindow',hwnd1)












% get monitor settings 
% screen resolution 

EnumDisplaySettingsA
EnumDisplayDevices
ChangeDisplaySettingsA
DeviceCapabilitiesA 














