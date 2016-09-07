



%---------------------------------------------------%
% function description
%---------------------------------------------------%



%------------------------------------------%
% 17.4.2016 - Jarrod, wrote function 
% 21.4.2016 - Jarrod, added MovingBar and StaticBar
% 26.4.2016 - Jarrod, added Image and BitmapBrush


function newStimObj = createNewStimulus(objectName, params)
% wrapper for [HIGH LEVEL OBJECTS]

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

