function logmessage(message)
% LOGMESSAGE Write message with timestamp to command line and logfile
fprintf('%s %s\n',datestr(now,'HH:MM:SS'), message);
end
       
