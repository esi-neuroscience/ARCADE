function newStimObj = createNewStimulus(objectName, params)
% Create a new stimulus object
%
% INPUT
% -----
%   objectName : string indicating the type of the stimulus. Possible
%                options are 'FilledDot', 'StaticBar', 'MovingBar',
%                'MaskedGrating', 'RandomDots', 'Image'
%       params : struct with stimulus parameters as fields. See 
%                Docs/DOCAvailableStimuli or HLO classes for details.
% 
% OUTPUT
% ------
%   newStimObj : stimulus object that can be used to manipulate stimulus 
%                in trial states, e.g. change visibility

newStimObj = []; %#ok<NASGU>

switch objectName
    case 'FilledDot'
        % static solid filled dot
        newStimObj = HLOFilledDot;
    case 'StaticBar'
        % static bar
        newStimObj = HLOStaticBar;
    case 'MovingBar'
        % straight paths only
        newStimObj = HLOMovingBarLinearPath;
    case 'MaskedGrating'
        % static/moving, circle/ellipse/square,
        % color/bw, sine/squarewave gratings
        newStimObj = HLOMaskedGrating;
    case 'RandomDots'
        % moving/static random dots
        newStimObj = HLORandomDots;
    case 'Image'
        % images
        newStimObj = HLOImage;
    case 'BitmapBrush'
        % images that allow an opacity mask
        newStimObj = HLOBitmapBrush;
    case 'GratingCutout'
        newStimObj = HLOGratingCutout;
    otherwise
        error(['Unknown Stimulus Type: ', objectName]);
end

% if object was created, then create the stimuulus
if ~isempty(newStimObj)
    newStimObj.createStimulus(params);
end

end

