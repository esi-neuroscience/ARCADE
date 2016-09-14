

%---------------------------------------------------%
% function description
%---------------------------------------------------%



%------------------------------------------%
% 15.4.2016 - Jarrod, wrote function 
function rString = smGenerateRandomString(N)

tmp = [48:57, 65:90, 97:122]; % 1:9, A:Z, a:z
rString = char(tmp(randi(length(tmp),1,N)));

end

