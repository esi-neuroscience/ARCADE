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
        function mOpenFile(this) % pass taskFile 
                                    
            basepath = this.writeDirectory;                        
            this.bhvFilename = fullfile(basepath,this.dataFileString);
            this.fid     = fopen([this.bhvFilename,'.esi'],'w'); % open data file
            this.fid_hdr = fopen([this.bhvFilename,'.hdr'],'w');

            
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
            convertEsiFile(this.bhvFilename)
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

