classdef MSWindow < handle 
    % [MICROSOFT]
    % meant to be inherited by a GUI 

    % ShowWindow
    % BringWindowToTop
    % GetFocus
    % SetFocus
    % GetActiveWindow
    % SetActiveWindow
    % GetForegroundWindow
    % SetForegroundWindow
    
    % GetClassNameA
    % CloseWindow
    % DestroyWIndow
    
    % GetDesktopWindow
    
    % SUBCLASSES:
    %   PauseScreen 
    
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static)
        %# constructor 
        function this = MSWindow
            if ~libisloaded('user32'); loadlibrary('user32', @win_user32); end;
        end
 
        %------------------------------------------------%
        %              Getting a Window [hwnd]
        %# FindWindow
        function hwnd = mFindWindow(winClass,winName)
            % 'SunAwtFrame' -> java windows 
            hwnd = libpointer('voidPtr');   %#ok<*NASGU>
            hwnd = calllib('user32', 'FindWindowA',winClass,winName);
        end
        
        %# GetForegroundWindow
        function hwnd = mGetForegroundWindow
            % Retrieves a handle to the foreground window
            hwnd = calllib('user32','GetForegroundWindow');
        end
        
        %# GetActiveWindow
        function hwnd = mGetActiveWindow
            % Retrieves the window handle to the active window attached to the calling thread's message queue.
            hwnd = calllib('user32','GetActiveWindow');
        end
        
        %# GetFocus
        function hwnd = mGetFocus
            % Retrieves the handle to the window that has the keyboard focus
            hwnd = calllib('user32','GetFocus');
        end
        
        %# GetWindowTextLength
        function nLen = mGetWindowTextLength(hwnd)
            nLen = calllib('user32','GetWindowTextLengthA',hwnd);
        end

        %# GetWindowText
        function name = mGetWindowText(hwnd,nBuf)
            buffer   = repmat('0',1,nBuf+1);
            nBuf     = int32(nBuf+1);
            nWRITTEN = int32(0);
            [nWRITTEN, ~, buffer] = calllib('user32', 'GetWindowTextA', hwnd, buffer, nBuf+1);
            if nWRITTEN>0
                name = buffer;
            end
        end

        %# GetClassName of HWND
        function name = mGetClassName(hwnd)
            name = [];
            buffer   = char(zeros(1,40));
            nBuf     = int32(length(buffer));
            nWRITTEN = int32(0);
            [nWRITTEN, ~, buffer] = calllib('user32', 'GetClassNameA', hwnd, buffer, nBuf);
            if nWRITTEN>0
                name = buffer;
            end
        end
        
        
        
        
        %------------------------------------------------%
        %              Setting a Window [hwnd]
        %# SetFocus
        function hwnd_ = mSetFocus(hwnd)
            % Sets the keyboard focus to the specified window.
            % handle to original window if success, else Null
            hwnd_ = calllib('user32', 'SetFocus',hwnd);
        end
        
        %# BringWindowToTop
        function result = mBringWindowToTop(hwnd)
            % If the function succeeds, the return value is nonzero
            result = calllib('user32', 'BringWindowToTop',hwnd);
        end
        
        %# SetActiveWindow
        function hwnd_ = mSetActiveWindow(hwnd)
            % handle to original window if success, else Null
            hwnd_ = calllib('user32', 'SetActiveWindow',hwnd);
        end

        %# SetForegroundWindow
        function result = mSetForegroundWindow(hwnd)
            result = calllib('user32', 'SetForegroundWindow',hwnd);
        end
        
        %# ShowWindow
        function result = mShowWindow(hwnd, Cmd)
            % https://msdn.microsoft.com/en-us/library/windows/desktop/ms633548%28v=vs.85%29.aspx
            switch upper(Cmd)
                case 'HIDE'                  % Hides the window and activates another window.
                    nCmdShow = 0; 
                case {'SHOWNORMAL','NORMAL'} % Activates and displays a window.
                    nCmdShow = 1;
                case 'SHOWMINIMIZED'         % Activates the window and displays it as a minimized window.
                    nCmdShow = 2;
                case 'MAXIMIZE'              % Maximizes the specified window.
                    nCmdShow = 3;
                case 'SHOWNOACTIVATE'        % Displays a window in its most recent size and position. 
                    nCmdShow = 4;
                case 'SHOW'                  % Activates the window and displays it in its current size and position. 
                    nCmdShow = 5;
                case 'MINIMIZE'              % Minimizes the specified window and activates the next top-level window in the Z order.
                    nCmdShow = 6;
                case 'SHOWMINNOACTIVE'       % Displays the window as a minimized window. Window NOT activated
                    nCmdShow = 7;
                case 'SHOWNA'                % Displays the window in its current size and position. Window NOT activated
                    nCmdShow = 8;
                case 'RESTORE'               % Activates and displays the window.
                    nCmdShow = 9;
                case 'SHOWDEFAULT'           % Sets the show state based on the value passed by the rogram that started the application
                    nCmdShow = 10;
                case 'FORCEMINIMIZE'         % Minimizes a window, even if the thread that owns the window is not responding.
                    nCmdShow = 11;
                otherwise
                    nCmdShow = 1;
            end

            result = calllib('user32', 'ShowWindow', hwnd, nCmdShow);
        end
        

        %------------------------------------------------%
        %              Destroying a Window [hwnd]

        %# CloseWindow
        function result = mCloseWindow(hwnd)
            % A handle to the window to be minimized.
            result = calllib('user32', 'CloseWindow',hwnd); 
        end
        
        %# DestroyWindow
        function result = mDestroyWindow(hwnd)
            % A handle to the window to be destroyed.
            result = calllib('user32', 'DestroyWindow',hwnd);  
        end
    end 
end

