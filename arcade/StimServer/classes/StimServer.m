classdef (Sealed = true) StimServer < handle
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties (Constant, Access = private, Hidden = true)
        this = StimServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        %        hPipe = []
        hPipe = libpointer;
    end
    
    methods (Access = private, Hidden=true)
        
        % The 64 bit implementation of calllib does not accept char
        % arrays as arguments. Therefore we convert strings to uint8.
        function obj = StimServer()
            %                disp('Stimserver Konstruktor');
            %            if ~isempty(obj.hPipe); return; end;
            if ~obj.hPipe.isNull(); return; end;
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end;
            %             [result] = ...
            %                 calllib('kernel32', 'GetNamedPipeInfo', ...
            %                 obj.hPipe, ...
            %                 [], ...
            %                 [], ...
            %                 [], ...
            %                 []);
            %             if isequal(result, 0)
            GENERIC_READ_WRITE = uint32(hex2dec('C0000000'));
            obj.hPipe = calllib('kernel32', 'CreateFileA', ...
                uint8('\\.\pipe\StimServerPipe'), ...
                GENERIC_READ_WRITE, ...
                0, ...  % no sharing
                [], ...
                3, ...  % OPEN_EXISTING
                0, ...
                []);
            assert(~obj.hPipe.isNull());
            disp('Connected to pipe');
            result = calllib('kernel32', 'GetNamedPipeInfo', ...
                obj.hPipe, ...
                [], ...
                [], ...
                [], ...
                []);
            if isequal(result, 0)
                ConstructorResult = calllib('kernel32', 'GetLastError');
                if ~isequal(ConstructorResult, 0)
                    ConstructorResult
                end
                error('StimServer:Constructor:failed', ...
                    'Can''t connect to StimServer''s pipe. Is the server running ?');
            end
            %             end
            mlock;
        end
    end
    
    methods (Static)
        
        function delete()
            temp = StimServer.this;
            assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
            temp.hPipe = libpointer;
            disp('Disconnected from pipe');
            munlock;
            clear StimServer;
        end
        
        function SetBackgroundColor(color)
            StimServer.Command(0, uint8([0 color]));
        end
        
        function SetDefaultDrawColor(color)
            StimServer.Command(0, uint8([1 5 color]));
        end
        
        function PDshow(shown)
            StimServer.Command(0, uint8([0 shown]));
        end
        
        function PDlit(lit)
            StimServer.Command(0, uint8([16 lit]));
        end
        
        function Defer(deferred)
            StimServer.Command(0, uint8([1 deferred]));
        end
        
        function RemoveAll()
            StimServer.Command(0, uint8(0));
        end
        
        function ShowAll(visible)
            StimServer.Command(0, uint8([0 0 visible]));
        end
        
        function SetDefaultFinalAction(mask)
            StimServer.Command(0, uint8([1 3 mask]));
        end
        
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
            nWritten = uint32(0);
            [result, ~, cmdMessage, nWritten] = ...
                calllib('kernel32', 'WriteFile', ...
                StimServer.this.hPipe, ...
                cmdMessage, ...
                length(cmdMessage), ...
                nWritten, ...
                []);
            if isequal(result, 0)
                result = calllib('kernel32', 'GetLastError');
                assert(false);
            end
            assert(nWritten == length(cmdMessage));
        end
        
        function Command(key, bytearr)
            StimServer.Write([typecast(uint16(key), 'uint8') uint8(bytearr)]);
        end
        
        function key = ReadAck()
            key = uint16(0);
            nRead = uint32(0);
            [result, ~, key, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                StimServer.this.hPipe, ...
                key, ...
                2, ...
                nRead, ...
                []);
            assert(nRead == 2);
        end
        
        function pos = read2single()
            pos = uint64(0);
            nRead = uint32(0);
            [~, ~, pos, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                StimServer.this.hPipe, ...
                pos, ...
                8, ...
                nRead, ...
                []);
            assert(nRead == 8);
            pos = typecast(pos, 'single');
        end
        
    end
    
end

