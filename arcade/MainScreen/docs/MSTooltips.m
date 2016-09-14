
% --------------------------- %
%        MAIN SCREEN

% TOOLTIPs (set in CreateFcn)

% Secondary Monitor 
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Secondary Monitor Refresh Rate'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Secondary Monitor Pixel Width'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Secondary Monitor Pixel Height'))}

% backup 
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Backup files attached in this GUI\n(e.g., Task File, Condition Selection File, etc)'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Backup all files in Task file directory'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Backup StimServer stimulus files (e.g., .fx file, etc)'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('User added files to backup\n'))}

% load buttons 
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Set a Condition selection function)'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Set a Block selection function'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Set a Event Markers script'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Load a Config file'))}

% trial error labels
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Set labels for Trial Errors in Trial Error Legend\n(has no functional consequence)'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Correct Trial Definition\n(cannot be changed)'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Default Trial Error Definition\n(cannot be changed)'))}

% event markers 
%{@(hObj,evt)set(hObj,'TooltipString',sprintf('Event Marker sent when "Pause" button is pressed\n'))}
%{@(hObj,evt)set(hObj,'TooltipString',sprintf('Event Marker sent when "Resume" or "Quit"\nbutton pressed during Pause'))}

% recording strings 
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Subject identification'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Experiment name or identification'))}
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Session identification'))}

% Editable variables
{@(hObj,evt)set(hObj,'TooltipString',sprintf('Editable variables\nCan be used in Task Script'))}



