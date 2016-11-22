function newStimObj = createNewQuad4XStimulus(objectName, paramStruct, quadrant)

for iQuadrant = 1:length(quadrant)
    quadParamStruct = paramStruct;
    [x,y] = quad_coordinates(...
        paramStruct.position(1), paramStruct.position(2), quadrant(iQuadrant));
    quadParamStruct.position = [x y];
    newStimObj(iQuadrant) = createNewStimulus(objectName, quadParamStruct);
    
end