%% launch and connect to StimServer
cfg = ArcadeConfig;
cfg.ControlScreen = [];
cfg.DaqServer = [];
cfg.StimServer = 'StimServer.exe';
p = launch_processes(cfg);
 
 
%% determine colors to be measured
stepsize = 12;
rgb = 1:stepsize:255;
colors = [1 1 1].*(rgb)';
luminance = zeros(size(colors, 1), 1);
 
%% iterate through colors and enter measured brightness value
for iColor = 1:size(colors, 1)
    currentColor = colors(iColor, :);
    StimServer.SetBackgroundColor(currentColor)
    luminance(iColor) = input(sprintf('Brightness value at [%3d %3d %3d]: ', currentColor));
end

%% normalize

normRgb = rgb / max(rgb);
normLuminance = (luminance - min(luminance)) / max(luminance);

%% fit without curve fitting toolbox (usually bad fit)
logNormRgb = log(normRgb(normRgb > 0));
logNormLuminance = log(normLuminance(normLuminance > 0));
[P,S] = polyfit(logNormRgb, logNormLuminance, 1);
gamma = P(1);

figure
plot(logNormRgb, logNormLuminance, '.-')
hold on
plot(logNormRgb, gamma*logNormRgb, 'r.-')
title('Log-linear polyfit')
legend('data', sprintf('gamma = %.2f', gamma))
xlabel('log(norm. RGB)')
ylabel('log(norm. luminance)')


%% fit with curve fitting toolbox
[xData, yData] = prepareCurveData(...
    normRgb(normRgb > 0), ...
    normLuminance(normRgb > 0));    

% Set up fittype and options.
ft = fittype( 'power1' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';
opts.Lower = [1 0];
opts.StartPoint = [1 2];
opts.Upper = [1 Inf];

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts );
gamma = fitresult.b;

%% 
figure
plot(normRgb, normLuminance, '.-')
hold on
plot(normRgb, normRgb.^gamma, '-')

legend('data', sprintf('gamma = %.2f', gamma))
xlabel('RGB (norm.)')
ylabel('Luminance (norm.)')
titleStr = sprintf('%s measured by %s', now, getenv('username'));
title(titelStr)

