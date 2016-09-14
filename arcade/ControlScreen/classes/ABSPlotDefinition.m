classdef ABSPlotDefinition < handle
    % [ABSTRACT] Plot [PLT] Definition Class
    % - for the classes: PLT(Classname)
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (...
            Abstract  = true,...
            SetAccess = immutable)
        parent
    end

    methods (Abstract = true)
        % the same number of input/outputs need not be the same
        % nor do the argument names need to be the same 
        mUpdate(this) % update plot method
        mCreate(this) % create plot method 
    end
    
    methods
        function delete(this)
            % if still valid delete
            if ishghandle(this.parent) 
                delete(allchild(this.parent));
            end
        end
    end
end
    
