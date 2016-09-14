classdef (Sealed) SGLSessionDataFile < handle
    % [SINGLETON]
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    properties (Access = private)
        fid     % file handle
        fid_hdr % header file handle
    end
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLSessionDataFile;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLSessionDataFile
        end
    end
    
    
    methods (Sealed = true)
        %# create file
        function mOpenFile(this,filename)
            %[f_path,f_name,~] = fileparts(data);
            this.fid = fopen([filename,'.esi'],'w'); % open data file
            this.fid_hdr = fopen([filename,'.hdr'],'w');
        end
        %# close file 
        function mCloseFile(this)
            fclose(this.fid);
            fclose(this.fid_hdr);
        end

        %# write data
        function mWrite(this,data)
            % write data to file
            data_ser = hlp_serialize(data);              % serialize structure to uint8
            count = fwrite(this.fid,data_ser,'uint8');
            if numel(data_ser) ~= count
                disp('Error writing to file.');
            end
            % write count to header file
            
            % bit count per trial, uint32 vector
            if count>realmax('single'), disp('Data too large'); end;
            fwrite(this.fid_hdr,uint32(count),'uint32');
        end

        %# read data file 
        function DAT = mESIRead(this,filename) 
            % simplest method, but get out of memory error sometimes with fread()
            % dat_ser  = fread(fid,[sum(count),1],'*uint8'); % read all
            % cellData = mat2cell(dat_ser,count); % chop into cells
            % Data = cellfun(@(m) hlp_deserialize(m),cellData,'unif',0);
            
            %[f_path,f_name,~] = fileparts(filename);
            
            fid = fopen([filename,'.esi'],'r'); %#ok<*PROP>
            fid_hdr = fopen([filename,'.hdr'],'r');
            
            
            try
                % get bit counts for each trial from header
                count = fread(fid_hdr,'uint32=>double'); % convert from uint32=>double implicitly
                %frewind(h_fid);
                nTrials = numel(count);
                disp(['Reading ', num2str(nTrials), ' trials...']);
                
                trlSer = cell(nTrials,1);
                % loop over trials
                for k = 1:nTrials
                    trlSer{k} = fread(fid,count(k),'*uint8'); % read all
                end
                
            catch ME
                ME %#ok<NOPRT>
                %error('readData',ME);
                %error(ME);
                fclose(fid);
                fclose(fid_hdr);
            end
            
            % close files
            fclose(fid);
            fclose(fid_hdr);
            
            % deserialize
            trlData = cellfun(@(m) hlp_deserialize(m),trlSer,'unif',0)';
            
            % combine structure array
            DAT =this.mCombineStructArray(trlData);
            
        end
    end
    
    
    methods (Access = private)

        function DAT = mCombineStructArray(this,trlData) %#ok<*INUSL>
            %trlcell = struct2cell(trlData{k});
            % assume same fields for all structs
            fnames = fieldnames(trlData{1});
            
            % create struture
            DAT = [];
            for fn = 1:numel(fnames)
                DAT.(fnames{fn}) = [];
            end
            
            ntrl = length(trlData);
            for k = 1:ntrl
                for fn = 1:numel(fnames)
                    data = trlData{k}.(fnames{fn});
                    if iscell(data) || isstruct(data) || numel(data)>1
                        DAT.(fnames{fn}){k} = data;
                    else
                        DAT.(fnames{fn})(k) = data;
                    end
                end
            end
        end
    end
    
    methods
        function delete(this)  %#ok<INUSD>
        end
    end
    
end

