classdef AUXUIControlFunctions < handle
    % [AUXILLARY] UICONTROL FUNCTIONS
    
    
    % SUBCLASSES:
    %   MSHightlightRequired 
    
    
    % METHODS:
    %   fullfilepath = mFilePrompt(fileType,msg,prompt)


    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 14.4.2015 - Jarrod, added multiselection to mFilePrompt()
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 27.2.2018 - Jarrod, change output of mFilePrompt() based on 'MultiSelect'
    
    methods (Static)
        %# constructor 
        function this = AUXUIControlFunctions
        end
    end
    
    methods (...
            Static = true,...
            Sealed = true)
        %# file prompt 
        % returns char if 'MultiSelect' is off
        % returns cell if 'MultiSelect' is on (regardless of number of files)
        function fullfilepath = mFilePrompt(fileType,msg,prompt,varargin)
            multiselect = 'off';
            defaultFile = '';
            
            % open file selection window
            switch prompt
                case 'open'
                    if ~isempty(varargin), multiselect = varargin{1}; end;
                    [fname,fpath] = uigetfile(fileType,msg,'MultiSelect',multiselect);
                case 'save'
                    if ~isempty(varargin), defaultFile = [varargin{1},fileType(2:end)]; end;
                    [fname,fpath] = uiputfile(fileType,msg,defaultFile);
                otherwise 
                    fullfilepath = nan(1);
                    return;
            end

            % did the user cancel or not
            if ~isequal(fname,0)
                switch multiselect
                    case 'on'
                        % one or many files can be returned
                        if ischar(fname), fname = {fname}; end;
                        fullfilepath = cellfun(@(ffile) [fpath,ffile], fname,'unif',0)';
                    case 'off'
                        % only one file can be returned 
                        fullfilepath = [fpath,fname];
                end
            else
                fullfilepath = [];
            end
                
            
        end
    end
end

