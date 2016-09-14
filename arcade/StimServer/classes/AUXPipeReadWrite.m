classdef AUXPipeReadWrite < handle
    % [AUX] PIPE READ/WRITE handle class
    %   Base Class providing methods to
    %	communicate with the StimServer
    
    %----------------------------------%
    % 12.4.2016 - Jarrod
    % - changed method names 

    properties (...
            SetAccess = immutable)%,...
            %GetAccess = protected)
        hPipe % pipe handle
    end
    
    methods (Static)
        function this = AUXPipeReadWrite
            % fetch pipe handle
            pipeObj    = SGLOpenPipe.fetch;
            this.hPipe = pipeObj.hPipe;
        end
    end
    
    methods (Sealed = true)
        
        %# Read Object Key
        function key = mReadKey(this)
            key = ioread(this.hPipe,uint16(0)); 
        end
        
        %# Write Command Message
        function success = mWriteCommand(this, key, outstream)
            cmdMessage = [typecast(uint16(key), 'uint8'), uint8(outstream)];
            success = iowrite(this.hPipe,cmdMessage); 
        end
        
        %{
        %# Read Object Key
        function key = mReadObjectID(this)
            %[~,key] = this.iostimserver(typecast(uint16(0),'uint8'),'r');
            %key = typecast(key, 'uint16')
            key = ioread(this.hPipe,uint16(0)); % secondary function
        end
        
        %# Send Command Message
        function success = mSendCmdMessage(this, key, outstream)
            cmdMessage = [typecast(uint16(key), 'uint8'), uint8(outstream)];
            success = iowrite(this.hPipe,cmdMessage); % secondary function 
            %[success,~] = this.iostimserver(cmdMessage,'w');
        end
        %}
    end  
end %EOC

%# General Output
function success = iowrite(hPipe, bytearr)
nWritten = uint32(0);
[result, ~, bytearr, nWritten] = ...
    calllib('kernel32', 'WriteFile', ...
    hPipe, ...
    bytearr, ...
    length(bytearr), ...
    nWritten, ...
    []); %#ok<ASGLU>
% report success or fail
success = nWritten == length(bytearr);
% if ~success
%     disp(['Number of bytes written: ', int2str(nWritten), ', Number of msg: ', int2str(length(bytearr))]);
% end
end

%# General Input
function bytearr = ioread(hPipe, bytearr)
% get number of bytes in read type
nBytes = numel(typecast(bytearr,'uint8'));
nRead  = uint32(0); % number of bytes read

[result, ~, bytearr, nRead] = ...
    calllib('kernel32', 'ReadFile', ...
    hPipe, ...
    bytearr, ...
    nBytes, ...
    nRead, ...
    []); %#ok<NASGU,ASGLU>
end

      
