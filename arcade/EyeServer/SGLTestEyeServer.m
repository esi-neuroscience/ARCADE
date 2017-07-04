classdef SGLTestEyeServer < ABSEyeServer
    % SGLTESTEYESERVER - Eye server class for testing purposes. 
    % Eye position can be set by mouse click in a figure with screen
    % coordinates.
    properties
        fig
        ax
        dot        
    end
   
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLTestEyeServer;
            end
            this = thisObj;
        end
    end
    
    
    methods ( Access = private )
        function obj = SGLTestEyeServer
            obj = obj@ABSEyeServer;
                        
            
            obj.fig = figure('WindowStyle', 'normal', 'MenuBar', 'None', ...
                'Color', 'white');
            set(obj.fig, 'Units', 'normalized', 'Position', [0.65 0.65 0.33 0.33], ...
                'Resize', 'off')

            obj.ax = axes('SortMethod','childorder');
           axis(obj.ax, 'equal')
            set(obj.ax, 'XGrid', 'on', 'YGrid', 'on',  ...
                'XTick', -1000:100:1000, 'YTick', -1000:100:1000, ...
                'XLim', [-1920 1920]/2, 'YLim', [-1080 1080]/2)
            
            title(obj.ax, 'Eye Position')
            xlabel(obj.ax, 'x [px]')
            ylabel(obj.ax, 'y [px]')
            
            obj.dot = line('XData', 0,'YData', 0,...
                'Marker','o','color','k', 'MarkerSize', 20);
            set(obj.fig,'Pointer','circle', 'NumberTitle', 'off', ...
                'Name', 'EyeServer');
            
            set(obj.fig, 'WindowButtonDownFcn', @obj.onClick, ...
                'CloseRequestFcn', @obj.onClose)
            
        end
    end
    methods
        
        
        function onClick(obj, src, callbackdata)
            seltype = get(src,'SelectionType');
            
            if strcmp(seltype,'normal')
                
                
                cp = get(obj.ax,'CurrentPoint');
                x = cp(1,1);
                y = cp(1,2);
                
                set(obj.dot, 'XData', x, 'YData', y)
                
            end
            
        end
        
        function onClose(obj, src, callbackdata)
            stopEvent = IPCEvent('StopEyeServer');
            stopEvent.trigger();   
            
        end
        
        
        function initialize(obj)
            
        end
        
        function eyePosition = acquire_eye_position(obj)
            x = get(obj.dot, 'XData');
            y = get(obj.dot, 'yData');
            titleString = sprintf('x=%.1f, y=%.1f', x, y);
            title(obj.ax, titleString)
            eyePosition = [x y];
            
            pause(0.01)
        end
                
        
        function obj = stop(obj)
            
        end
        
            
        function delete(obj)
            delete(obj.fig)
            % close(obj.fig)
        end
    end
end
