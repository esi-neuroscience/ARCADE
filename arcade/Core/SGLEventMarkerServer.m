classdef (Sealed) SGLEventMarkerServer < handle
    
    
    properties (SetAccess = immutable)
        filename = [];
        fileHandle = [];
    end
    
    properties ( Access = private )
        timestamps = uint64(zeros(1,1000))
        values = uint64(zeros(1,1000))
        lastEvent = 0;  
    end
    
    properties ( Access = public )
        tStart
    end
    
    methods (Static)
        function this = launch(filename)
            if nargin == 0
                filename = [];
            end
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEventMarkerServer(filename);
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLEventMarkerServer(filename)
            
            this.tStart = tic;
            if ~isempty(filename)
                this.filename = filename;
                h = fopen(this.filename, 'w');
                assert(h ~= -1);
                this.fileHandle = h;
            end
        end
    end
    
    methods
        
        function storeEvent(this,value)
            
            this.timestamps(this.lastEvent+1) = uint64(toc(this.tStart)*1E6);
            this.values(this.lastEvent+1) = uint64(value);
            this.lastEvent = this.lastEvent+1;
            if this.lastEvent > 1000
                this.writeEvents()
            end
            
        end
        
        function writeEvents(this)
            if ~isempty(this.filename)
                writeArray = [this.timestamps(1:this.lastEvent); this.values(1:this.lastEvent)];
                nWritten = fwrite(this.fileHandle, writeArray, 'uint64');
                assert(nWritten == this.lastEvent*2)
                this.lastEvent = 0;
                this.timestamps(:) = 0;
                this.values(:) = 0;
            end
        end
        
        function delete(this) 
            if ~isempty(this.filename)
                fclose(this.fileHandle);
            end
        end
    end   
end