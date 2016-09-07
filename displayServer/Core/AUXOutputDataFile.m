classdef AUXOutputDataFile < handle
    % [AUXILLARY]
    
    % ----- methods -----
    % mOpenFile(this,filename)
    % mCloseFile(this)
    % mWrite(this,data)
    % DAT = mESIRead(this,filename) 
    
    % store file with unique signature
    
    % start time
    % end time
    
    %timeNow    = datestr(now,'HH:MM PM');
    %today      = datestr(now,'ddmmyy');
    %timeString = [today,'_',datestr(timeNow,'HHMM')];
    
    %DD_MM_YY_HH_MM
    
    %TODO -> change the convert bhv file method
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    %  4.3.2015 - Jarrod, editted the file destination for the behavioural data
    % 24.4.2015 - Jarrod, small changes to the bhvfilename 
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 29.4.2016 - Jarrod, 
    %   - added some notes
    %   - removed mSplitFilepath() method (not used)
    
    properties (Access = protected)
        fid         % file handle
        fid_hdr     % header file handle
        bhvFilename % base filename 
    end
    
    properties (...
            Abstract  = true,...
            SetAccess = immutable)
        dataFileString % set in subclass 
        writeDirectory 
    end
    
    %# constructor
    methods (Static)
        function this = AUXOutputDataFile
        end
    end

    methods (Sealed = true)
        %# create file
        function mOpenFile(this,taskFile) % pass taskFile 
            % append task file name, and date string the writeDirectory
            [~,f_name,~] = fileparts(taskFile);
            
            % filepath, filename, date string 
            basepath = this.writeDirectory;
            filename = [f_name,'_',this.dataFileString];
            
            bhvFilename  = fullfile(basepath,filename);
            this.fid     = fopen([bhvFilename,'.esi'],'w'); % open data file
            this.fid_hdr = fopen([bhvFilename,'.hdr'],'w');

            this.bhvFilename = bhvFilename;
        end
        
        %# close file 
        function mCloseFile(this)
            fclose(this.fid);
            fclose(this.fid_hdr);
        end

        %# write data
        function mWriteFile(this,data)
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
        function mESIRead(this) 
            % simplest method, but get out of memory error sometimes with fread()
            % dat_ser  = fread(fid,[sum(count),1],'*uint8'); % read all
            % cellData = mat2cell(dat_ser,count); % chop into cells
            % Data = cellfun(@(m) hlp_deserialize(m),cellData,'unif',0);
            
            filename = this.bhvFilename;
            fid     = fopen([filename,'.esi'],'r'); %#ok<*PROP>
            fid_hdr = fopen([filename,'.hdr'],'r');

            try
                % get bit counts for each trial from header
                count = fread(fid_hdr,'uint32=>double'); % convert from uint32=>double implicitly
                %frewind(h_fid);
                nTrials = numel(count);
                disp('Reading Behvaioural file...')
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
            bhvData = this.mCombineStructArray(trlData); %#ok<NASGU>
            % save structure 
            save([filename,'.mat'],'-struct','bhvData');
            disp('Saved Behavioural File');
        end
    end
    
    
    methods (Access = private)
        %# 
        function bhvData = mCombineStructArray(this,trlData) %#ok<*INUSL>
            %trlcell = struct2cell(trlData{k});
            % assume same fields for all structs
            fnames = fieldnames(trlData{1});
            
            % create struture
            bhvData = [];
            for fn = 1:numel(fnames)
                bhvData.(fnames{fn}) = [];
            end
            
            %cell2mat(userVariables)

            ntrl = length(trlData);
            for k = 1:ntrl
                for fn = 1:numel(fnames)
                    data = trlData{k}.(fnames{fn});
                    if iscell(data) || isstruct(data) || numel(data)>1
                        bhvData.(fnames{fn}){k} = data;
                    else
                        bhvData.(fnames{fn})(k) = data;
                    end
                end
            end
        end
    end

    %# destructor 
    methods
        function delete(this)
            % flag for a close 
            % on delete should ensure file is closed
        end
    end
    
end

