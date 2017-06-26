function logmessage(message)
% Write message with timestamp to terminal and log
fprintf('%s %s\n',datestr(now,'HH:MM:SS'), message);
end
       