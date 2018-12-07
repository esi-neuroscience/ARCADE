

StimServer.Connect();


%%
clear
fxFile = fullfile(arcaderoot, 'arcade', 'StimServer', 'classes', 'Stimuli', 'BentGrating.fx');

s = PixelShader(fxFile);
s.setParameter(1, 300);
s.setParameter(2, 250);
s.setParameter(3, 0);
s.setParameter(4, 0);
s.setParameter(5, 10);
s.setParameter(6, 250);
s.setParameter(7, 720)
s.setParameter(8, 45)

s.setColor(1, [0 0 0 255])
s.setColor(2, [255 255 255 255])
s.visible = true;

% pause(1)
% s.setParameter(8,0.15)

%%

maxRadialSlope = 1;
pause(5)

a1 = LinearRange(0, maxRadialSlope, 0.2, 8);
a2 = LinearRange(maxRadialSlope, 0, 0.2, 8);

pause(1);
s.play_animation(a1)
pause(0.1)
% s.play_animation(a2)



% pause(5)
% s.setParameter(8, 0.8);
% pause(5)
% s.setParameter(8,0)

