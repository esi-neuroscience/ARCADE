EyeServer = SGLEyeServer.launch();


%% test fetching
dt = 0.001;
nMin = 60*24*5;
nSamples = round(nMin*60/dt);
plotEyePosition = true;

tic



if plotEyePosition
    figure('WindowStyle', 'normal')
    ax = axes('position', [0.07 0.07 0.9 0.9]);
%     axis equal
    set(ax, 'NextPlot', 'replacechildren', 'XLim', [-0.5 0.5]*1680, 'YLim', [-0.5 0.5]*1050)
end    

for iSample = 1:nSamples
    eye_pos = EyeServer.mFetchEyePosition();
    plot(eye_pos(1), eye_pos(2), 'o')
    pause(dt);
end
toc