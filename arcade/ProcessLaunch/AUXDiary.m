classdef AUXDiary < handle
    % [AUXILLARY] DIARY
    
    % provide methods for creating and
    % managing a diary (essentially an error log)
    
    
    %------------------------------------------%
    % 16.5.2016 - Jarrod, wrote class
    
    
    properties (...
            AbortSet = true,...
            Access   = protected)
        isDiaryCreated % flag if diary has been initialized
    end
    
    methods (Static)
        function this = AUXDiary
            this.isDiaryCreated = false;
        end
    end
    
    
    methods (Sealed = true)
        
        %# create diary
        function mCreateDiary(this, diaryFilename, diaryDirectory)
            
            % if directory does not exist create it
            if ~exist(diaryDirectory,'dir'), mkdir(diaryDirectory); end;
            
            try
                % create diary
                diary(fullfile(diaryDirectory, diaryFilename));
                diary on;    % activate diary
                this.isDiaryCreated = true; % set flag true
            catch ME
                ME  %#ok<NOPRT>
            end
        end
        
        %# write to diary
        % may not be written to diary immediately unless flushed
        function mWriteToDiary(this, message, doFlush)
            % format -> message... [time now]
            fprintf('%s... %s\n',message,datestr(now,'HHMM'));
            if doFlush, this.mFlushDiary; end;
        end
        
        %# ensure what is writtent to command line is
        % written to the diary
        function mFlushDiary(this)
            if this.isDiaryCreated
                diary off;
                diary on;
            end
        end
        
    end
    
    methods
        %# delete function 
        function delete(this)
            if this.isDiaryCreated
                diary off;
            end
        end
    end
    
end