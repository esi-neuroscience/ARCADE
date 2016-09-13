classdef NumericBinaryFile < handle
    %UNTITLED3 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties (Constant = true)
        version = uint8(0);
    end
        
    properties (SetAccess = immutable)
        filename
    end
    
    properties (Access = private, ...
            Transient = true)
        fid
    end
    
    methods
        function obj = NumericBinaryFile(filename, var)
            %disp(filename);
            obj.filename = filename;
            obj.fid = fopen(filename, 'w');
            obj.write(var);
            fclose(obj.fid);
        end
        
        function write(obj, var)
            numClass = class(var);
            switch numClass
                case 'int8'
                    type = 1;
                case 'uint8'
                    type = 2;
                case 'int16'
                    type = 3;
                case 'uint16'
                    type = 4;
                case 'int32'
                    type = 5;
                case 'uint32'
                    type = 6;
                case 'int64'
                    type = 7;
                case 'uint64'
                    type = 8;
                case 'single'
                    type = 9;
                case 'double'
                    type = 10;
                case 'cell'
                    type = 16;
            end
            if isnumeric(var) && ~isreal(var); type = type+128; end
            nDims = ndims(var);
            fwrite(obj.fid, [obj.version type nDims], 'uint8');
            fwrite(obj.fid, size(var), 'uint64');
            if isequal(numClass, 'cell')
                for k = 1:numel(var)
                    obj.write(var{k})
                end
            else
                if isreal(var)
                    fwrite(obj.fid, var, numClass);
                else
                    fwrite(obj.fid, real(var), numClass);
                    fwrite(obj.fid, imag(var), numClass);
                end
            end
        end
        
        function result = load(obj)
            obj.fid = fopen(obj.filename, 'r');
            result = obj.read();
        end
        
        function result = read(obj)
            header = fread(obj.fid, 3, 'uint8=>uint8');
            type = header(2);
            nDims = header(3);
            dims = fread(obj.fid, nDims, 'uint64=>uint64');
            if isequal(type, 16)    % cell array
                result = cell(double(dims'));
                for i = 1:numel(result)
                    result{i} = obj.read();
                end
            else
                types = {'int8' 'uint8' 'int16' 'uint16' 'int32' 'uint32' 'int64' 'uint64' 'single' 'double'};
                typeName = types(bitand(type, 127));
                precision = [char(typeName) '=>' char(typeName)];
                numEl = uint64(prod(double(dims)));
                if type < 128
                    result = fread(obj.fid, numEl, precision);
                else
                    realPart = fread(obj.fid, numEl, precision);
                    imPart = fread(obj.fid, numEl, precision);
                    result = complex(realPart, imPart);
                end
            end
            result = reshape(result, dims');
        end
    end
    
end

