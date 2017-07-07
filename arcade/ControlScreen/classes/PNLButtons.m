classdef PNLButtons < handle
    
    methods (Static = true)
        function this = PNLButtons(hfig)
            %gdata = guidata(hfig); % gui data
            
            Tags = {...
                'btn_pause';...
                'btn_reward'; ...
                'btn_skiptrial'; ...
                };
            % get handles
            % other functions using the handles expect a double vector
            btns = cell2mat(AUXAuxMethods.mGetHandles(hfig,Tags));
            set(btns(1), 'Callback', @PNLButtons.pauseButtonCallback);
            set(btns(2), 'Callback', @PNLButtons.rewardButtonCallback);
            set(btns(3), 'Callback', @PNLButtons.skipButtonCallback);
            
        end
        
         function pauseButtonCallback(src, event, handles)
             pauseEvent = IPCEvent('PauseCoreRequested');
             pauseEvent.trigger();
             logmessage('Pause requested')
         end

         function rewardButtonCallback(src, event, handles)
             rewardEvent = IPCEvent('Reward');
             rewardEvent.trigger();
             logmessage('Manual  reward')
         end

        function skipButtonCallback(src, event, handles)
             skipEvent = IPCEvent('SkipTrial');
             skipEvent.trigger();
             logmessage('Set SkipTrial event')
         end


        
    end
        
end
