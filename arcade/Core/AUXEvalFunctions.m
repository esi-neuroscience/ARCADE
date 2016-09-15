classdef AUXEvalFunctions < handle
    % [AUXILLARY] EVALUATE FUNCTIONS
    % used by State
    % used by GUIButtonFunctions
    
    %------------------------------%
    % Jarrod, wrote class

    methods (Static)
        function this = AUXEvalFunctions
        end
    end
    
    methods (...
            Access = protected,...
            Sealed = true)
        
        %# Evaluate functions 
        % input must be a cell vector of anonymous functions
        % will evaluate functions with no inputs or many
        % ** does not collect function output **
        % special case for the input string 'self'
        % 'self' is replaced with the this object
        % the 'self' functionality is useful when:
        % - the function is written before the object is created
        % - the function exists in a structure, such as in the task file
        
        % use function to set a property (need to add property first)
        % out = cellfun(@(func) func{1}(func{2:end}), funcs, 'unif',0);
            
        % TO DO:
        %  - implement return of function output
        function evalFunctions(this,funcs)

            for k = 1:numel(funcs)
                func_ = funcs{k};
                
                if length(func_)==1
                    func_{1}();
                else
                    % for set/get properties of self
                    self = strcmp(func_{2:end},'self'); % replace 'self' with this
                    if any(self), func_{find(self)+1} = this; end
                    func_{1}(func_{2:end});
                end
            end
        end
    end
    
end

