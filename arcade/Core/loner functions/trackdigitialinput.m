function trackdigitalinput(lineNumber, eventName)
% TRACKDIGITALINPUT - Tell DaqServer to signal events when digitial input line
% state changes
% 
% INPUT
% -----
%   lineNumber  : input line of DAQ card to be tracked. For PCI-6221 cards
% 				  this can be 0-7 of port 2, for PCI-6503 only lines 4-7 of
% 				  port 2a re available as input
%	eventName   : event name to be triggered when pulse arrives on input line
% 				  or 2-element cell array with event names for line on and off
% 
% 	or
% 
% 	'start'     : start tracking of digitial input. Call trackdigitalinput
% 	              with this option after all lines were added.
% 
% 
% EXAMPLE
% -------
%
% Track state of button connected to line 2 of port 2.
%
% 	if TrialData.currentTrial == 1
%   	trackdigitalinput(2, {'leverOn', 'leverOff'})
%		trackdigitalinput('start')
%	end
% 
% 
% Notes: 
%   * To add more than one input position, trackdigitalinput has to be called repeatedly.  
%   * Before calling trackdigitalinput, the pipe to the DaqServer has to be opened
%     (done automatically by ARCADE).
% 
% See also State
persistent wasStarted
if isempty(wasStarted)
	wasStarted = false;
end
if wasStarted
	warning('Digital input tracking was already started. Ignoring this call.')
	return
end
if nargin == 1 & strcmp(lineNumber, 'start')
	DaqServer.Start()
	wasStarted = true;
elseif nargin == 2 && iscell(eventName)
	DaqServer.Addline(lineNumber, eventName{:})
elseif nargin == 2 && ischar(eventName)
	DaqServer.Addline(lineNumber, eventName)
end