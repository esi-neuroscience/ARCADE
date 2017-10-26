function stim = CalibrationStimulusGaussian()
stim = cell(1,2);
stim{1} = Gaussian;
stim{1}.color = [255 255 255]; 
stim{1}.sdx = 10; 
stim{1}.sdy = 10;

stim{2} = Gaussian;
stim{2}.color = [0 0 0]; 
stim{2}.sdx = 1; 
stim{2}.sdy = 1;