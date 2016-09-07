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
    
    methods (Static)
        %# constructor 
        function this = AUXUIControlFunctions
        end
    end
    
    methods (...
            Static = true,...
            Sealed = true)
        %# file prompt 
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
                
                %[fname,fpath] = uigetfile('*.*','','MultiSelect','on');
                %[fname,fpath] = uiputfile('*_cfg.mat','','');
                
                if iscell(fname)
                    fullfilepath = cellfun(@(ffile) [fpath,ffile], fname,'unif',0)';
                else
                    fullfilepath = [fpath,fname];
                end
            else
                fullfilepath = [];
            end
            
        end
    end
end

