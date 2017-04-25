clear
close all

EyeServer = SGLEyelinkEyeServer.launch();

%% test fetching
nMin = 60*24*5; % 5 days
% nMin = 1;
plotEyePosition = true;

if plotEyePosition
    figure('WindowStyle', 'normal')
    ax = axes('position', [0.07 0.07 0.9 0.9]);
    set(ax, 'NextPlot', 'replacechildren', 'XLim', [-0.5 0.5]*1680, 'YLim', [-0.5 0.5]*1050)
end

client = EyeClient;
nSamples = 0;
tic
while toc<nMin*60
    eye_pos = client.eyePosition;
    if plotEyePosition
        plot(eye_pos(1), eye_pos(2), 'o')
        drawnow()
    end
    if mod(nSamples, 1000) == 0
        fprintf('%g s, %u samples\n',toc, nSamples)
    end
    nSamples = nSamples+1;
    java.lang.Thread.sleep(10)
    
    
end
duration = toc;
fprintf('Sampled %u datapoints in %g min\n', nSamples, duration/60)
nIdealSamples = nMin*60*100