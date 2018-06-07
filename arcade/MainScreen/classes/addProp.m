
% Written by Yair Altman pulished online 
% Wednesday, September 16th, 2015
% https://undocumentedmatlab.com/blog/adding-dynamic-properties-to-graphic-handles

%---------------------------------------------%
% changes:
% 20.2.2018 - Jarrod, 
%   - copied Yair's function
%   - modified set intialValue method to work with both HG1 and HG2
function addProp(hObject, propName, initialValue, isReadOnly)
    try
        hProp = addprop(hObject, propName);  % HG2
    catch
        try
            hProp = schema.prop(hObject, propName, 'mxArray');  % HG1
        catch
            hProp = findprop(hObject, propName);
        end
    end
    if nargin > 2
        try
            hProp.SetAccess = 'public';  % HG2
        catch
            hProp.AccessFlags.PublicSet = 'on';  % HG1
        end
        %hObject.(propName) = initialValue;    % HG2 syntax 
        set(hObject, propName, initialValue); % modified by Jarrod 20.2.2018
    end
    if nargin > 3 && isReadOnly
        try
            % Set the property as read-only
            hProp.SetAccess = 'private';  % HG2
        catch
            hProp.AccessFlags.PublicSet = 'off';  % HG1
        end
    end
end