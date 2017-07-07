classdef EyelinkConfig < handle
    
    properties ( Access = public )
        
        
        
        % calibration
        calibration_type = 'HV5';
        
        
        enable_automatic_calibration = 'YES';
        randomize_calibration_order = 'NO';
       
        automatic_calibration_pacing = 1000; % ms
        randomize_validation_order = 'YES';
        cal_repeat_first_target = 'YES';
        val_repeat_first_target = 'YES';
        
        
        
        
        elcl_select_configuration = 'MTABLER';%'BLRR';
        
        
        % analog
        analog_dac_range = [-10 10];
        analog_out_data_type = 'GAZE';
        analog_binocular_mapping = 'NO';
        analog_no_pupil_value = 0.0;
        
        heuristic_filter = [2 0];
        aux_mouse_simulation = 'YES';
        
        % screen
        screen_phys_coords = [-238.38, 148.05, 238.38, -148.05]; % SAMSUNG 2233RZ
        screen_pixel_coords = [0 0 1680 1050]; % SAMSUNG 2233RZ
        
        
        file_event_data = 'GAZE,GAZERES,HREF,AREA,VELOCITY';
        link_event_data = 'GAZE,GAZERES,HREF,AREA,FIXAVG,NOSTART';
        file_sample_data = 'LEFT,RIGHT,GAZE,PUPIL,AREA,INPUT,STATUS';
        link_sample_data = 'LEFT,RIGHT,GAZE,PUPIL';
        
        % camera options
        binocular_enabled = 'NO';
        active_eye = 'LEFT';
        use_ellipse_fitter = 'NO';
        
        %  <pupil L> <hcam>  <pupil R> <CR L> <CR R>
        initial_thresholds = [80, 40, 80, 150, 150];
        
        % saccades
        saccade_velocity_threshold = 30;
        saccade_acceleration_threshold = 8000;
        saccade_motion_threshold = 0.1;
        
        % not functional
%         sample_rate = 500;
%         screen_distance = 600;
%         elcl_tt_power = 2;
%         calibration_samples = 15;
%         calibration_average = 'YES';
%         calibration_sequence = [0:4 0:4 0:4]
%         manual_collection_minimum_fixation = 100;
%         manual_collection_fixation_lookback = 50;
%         autocal_minimum_fixation = 500; % ms
%         autocal_minimum_saccade = 2.5; % degree
%         generate_default_targets = 'NO';
%         drift_correction_fraction = 1.0;
%         online_dcorr_button = 'ON';
%         normal_click_dcorr = 'ON';
%         calibration_targets = [336,525, 840,525  1344,525,  840,840 840,210];
        
    end
    
    methods
        function obj = EyelinkConfig()
            
        end
        
        function send_config_to_tracker(obj)
            cleanupObj = onCleanup(@() Eyelink('Shutdown'));
            if ~Eyelink('IsConnected')
                assert(Eyelink('Initialize') == 0, 'Eyelink: failed to initialize')
            end
            props = properties(obj);
            errs = {};
            nErrs = 0;
            for iProp = 1:length(props)
                name = props{iProp};
                value = obj.(name);
                try
                    EyelinkConfig.set_param(name, value);
                    pause(0.05);
                catch me
                    warning('Eyelink: failed to set %s on tracker', name)
                    nErrs = nErrs+1;
                    errs{nErrs} = me;
                    obj.(name) = [];
                end
                
            end
            
        end
        
        function read_config_from_tracker(obj)
            cleanupObj = onCleanup(@() Eyelink('Shutdown'));
            if ~Eyelink('IsConnected')
                assert(Eyelink('Initialize') == 0, 'Eyelink: failed to initialize')
            end
            props = properties(obj);
            errs = {};
            nErrs = 0;
            for iProp = 1:length(props)
                name = props{iProp};
                try
                    value = EyelinkConfig.read_param(name);
                    obj.(name) = value;
                    pause(0.05);
                catch me
                    warning('Eyelink: failed to read %s from tracker', name)
                    nErrs = nErrs+1;
                    errs{nErrs} = me;
                    obj.(name) = [];
                end
            end
            Eyelink('Shutdown')
        end
        
    end
    
    methods ( Static )
        
        function param = read_param(parameterName)
            [~, param] = Eyelink('ReadFromTracker', parameterName);
            switch param
                case 'Unknown Variable Name'
                    error('Eyelink: failed to read %s from tracker, unknown variable name', parameterName)
                case 'Variable read not supported'
                    error('Eyelink: failed to read %s from tracker, variable not supported', parameterName)
            end
            
        end
        
        function set_param(name, value)
            if ~ischar(value)
                value = sprintf('%g ', value);
            end
            assert(Eyelink('command',[name ' = ' value]) == 0, ...
                'Eyelink: could not set %s on tracker', name)
        end
        
    end
    
end
