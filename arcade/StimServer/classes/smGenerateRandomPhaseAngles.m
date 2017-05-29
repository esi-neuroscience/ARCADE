function phi = smGenerateRandomPhaseAngles(R, N, theta, units)
%-----------------------------------------------%
% Inputs:
%   R     -> [numeric] phase coherence [0,1]
%   N     -> [numeric] number of phase angles >1
%   theta -> [numeric] mean phase angle [units assumed from 'units']
%   units -> [string]  'radians' or 'degrees', return units, and input

% Output:
%   phi   -> [Nx1 numeric] between [-180,180] or [-pi,pi]

%-----------------------------------------------%
% check N
if N<1
    error('Number of angles must be a positive integer > 1');
end

% check R, bound between 0 and 1
if R<0, R = 0; end;
if R>1, R = 1; end;

% check units
validUnits = {'radians', 'degrees'};
returnUnit = validatestring(units,validUnits);

convertUnits = 1; % stay radians
if strcmp(returnUnit, 'degrees')
    convertUnits = 180/pi; % radians to degrees
    % theta is in degrees, convert to radians
    theta = theta * pi/180;
end
%-----------------------------------------------%
%      compute phase angles is radians

phi = zeros(N,1); % to return

% check for simple cases
thresh = eps(single(5)); % relatively arbitrary decision, close to kappa < 1e-6

if R <= thresh       % uniform distribution
    phi = 2*pi*rand(N,1)-pi + theta;
elseif R >= 1-thresh % all same phase angle
    phi = phi + theta;
else                 % not a simple case
    
    % compute kappa
    if R < 0.53
        kappa = 2*R + R^3 + 5*R^5/6;
    elseif R>=0.53 && R<0.85
        kappa = -.4 + 1.39*R + 0.43/(1-R);
    else
        kappa = 1/(R^3 - 4*R^2 + 3*R);
    end
    
    % other cases
    a = 1 + sqrt((1+4*kappa.^2));
    b = (a - sqrt(2*a))/(2*kappa);
    r = (1 + b^2)/(2*b);
    
    phi = zeros(N,1);
    for j = 1:N
        while true
            u = rand(3,1);
            
            z = cos(pi*u(1));
            f = (1+r*z)/(r+z);
            c = kappa*(r-f);
            
            if u(2) < c * (2-c) || ~(log(c)-log(u(2)) + 1 -c < 0)
                break;
            end
        end
        phi(j) = theta +  sign(u(3) - 0.5) * acos(f);
    end
end
% ensure distribution is [-pi,pi]
% and convert if necessary
phi = angle(exp(1i*phi))*convertUnits;


end

