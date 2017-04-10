classdef SGLTestEyeServer
    
    properties
        fig
        ax
        dot
        sharedMemoryName = 'EyePosition'; % name for memory mapping to be used in EyeClient
    end
    
    properties ( Access = private )
        sharedMemory
    end
    
    methods
        function obj = SGLTestEyeServer
            
            obj.fig = figure('WindowStyle', 'normal');
            obj.ax = axes('SortMethod','childorder', 'XLim', [-1920 1920]/2, 'YLim', [-1080 1080]/2);
            grid on
            
            obj.dot = line('XData', 0,'YData', 0,...
                'Marker','o','color','k', 'MarkerSize', 40);
            set(obj.fig,'Pointer','circle');
            set(obj.fig, 'WindowButtonDownFcn', @obj.onClick)
            
            sharedObject = MSNamedSharedMemory;
            sharedObject.mCreateFileMapping(obj.sharedMemoryName, 16);
            setdatatype(sharedObject.pointer, 'doublePtr', 2);
            sharedObject.pointer.Value = [0.0; 0.0];
            obj.sharedMemory = sharedObject;     
            
            
        end
        
        
        
        function obj = onClick(obj, src, callbackdata)
            seltype = get(src,'SelectionType');
            
            if strcmp(seltype,'normal')
                
                
                cp = get(obj.ax,'CurrentPoint');
                x = cp(1,1);
                y = cp(1,2);
                
                set(obj.dot, 'XData', x, 'YData', y)
                obj.update()
            end
            
        end
        
        function obj = update(obj)
            x = get(obj.dot, 'XData');
            y = get(obj.dot, 'yData');
            titleString = sprintf('x=%.1f, y=%.1f', x, y);
            title(obj.ax, titleString)
            obj.sharedMemory.pointer.Value = [x; y];
        end
    end
end