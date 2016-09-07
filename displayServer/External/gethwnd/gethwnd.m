function hWnd = gethwnd(hFig)
% gethwnd Retrieves the underlying Windows handle for Matlab figures
%
% Syntax:
%    hWnd = gethwnd(hFig)
%
% Description:
%    GETHWND retrieves the current figure (gcf)'s underlying Windows handle,
%    thus enabling integration of Matlab GUI in C/C++/C# programs.
%
%    GETHWND(hFig) retrieves a specific figure's underlying Windows handle.
%    hFig is a Matlab handle, or a list of handles (not necessarily figure
%    handle(s) - the handles' containing figure is used).
%
% Limitations:
%    Windows-only (duh!); Java must be enabled
%
% Warning:
%    This code heavily relies on undocumented and unsupported Matlab
%    functionality. It works on Matlab 7+, but use at your own risk!
%
% Bugs and suggestions:
%    Please send to Yair Altman (altmany at gmail dot com)
%
% Change log:
%    2007-10-08: First version posted on <a href="http://www.mathworks.com/matlabcentral/fileexchange/loadAuthor.do?objectType=author&mfx=1&objectId=1096533#">MathWorks File Exchange</a>
%    2011-10-14: Fix for R2011b
%
% See also:
%    gcf, getjframe, findjobj (last 2 on the File Exchange)

% Programmed by Yair M. Altman: altmany(at)gmail.com
% $Revision: 1.1 $  $Date: 2011/10/14 03:41:21 $

% Algorithm:
%    loop over all supplied figure handles
%       jFrame = get(hFig(idx),'JavaFrame')
%       hWnd(idx) = jFrame.fFigureClient.getWindow.getHWnd
%    end

  try
      % Default figure = current (gcf)
      if nargin < 1 || ~all(ishghandle(hFig))
          if nargin && ~all(ishghandle(hFig))
              error('hFig must be a valid GUI handle or array of handles');
          end
          hFig = gcf;
      end

      % Require Java engine to run
      if ~usejava('jvm')
          error([mfilename ' requires Java to run.']);
      end

      % Initialize output var (needed in case hFig is empty)
      hWnd = [];

      % Loop over all requested figures
      for figIdx = 1 : length(hFig)
          % Get the root Java frame
          jff = getJFrame(hFig(figIdx));
          % Get the HWnd value from the root Java Frame
          hWnd(figIdx) = jff.getHWnd;
      end

  % Error handling
  catch
      v = version;
      if v(1)<='6'
          err.message = lasterr;  % no lasterror function...
      else
          err = lasterror;
      end
      try
          err.message = regexprep(err.message,'Error using ==> [^\n]+\n','');
      catch
          try
              % Another approach, used in Matlab 6 (where regexprep is unavailable)
              startIdx = findstr(err.message,'Error using ==> ');
              stopIdx = findstr(err.message,char(10));
              for idx = length(startIdx) : -1 : 1
                  idx2 = min(find(stopIdx > startIdx(idx)));  %#ok ML6
                  err.message(startIdx(idx):stopIdx(idx2)) = [];
              end
          catch
              % never mind...
          end
      end
      if isempty(findstr(mfilename,err.message))
          % Indicate error origin, if not already stated within the error message
          err.message = [mfilename ': ' err.message];
      end
      if v(1)<='6'
          while err.message(end)==char(10)
              err.message(end) = [];  % strip excessive Matlab 6 newlines
          end
          error(err.message);
      else
          rethrow(err);
      end
  end

%% Get the root Java frame (up to 10 tries, to wait for figure to become responsive)
function jframe = getJFrame(hFigHandle)

  % Ensure that hFig is a figure handle...
  hFig = ancestor(hFigHandle,'figure');
  if isempty(hFig)
      error(['Cannot retrieve the figure handle for handle ' num2str(hFigHandle)]);
  end

  jframe = [];
  maxTries = 10;
  while maxTries > 0
      try
          % Get the figure's underlying Java frame
          jf = get(handle(hFig),'JavaFrame');

          % Get the Java frame's root frame handle
          %jframe = jf.getFigurePanelContainer.getComponent(0).getRootPane.getParent;
          %jframe = jf.getFigurePanelContainer.getParent.getTopLevelAncestor;
          try
              jframe = jf.fFigureClient.getWindow;  % equivalent to above...
          catch
              jframe = jf.fHG1Client.getWindow;  % equivalent to above...
          end
          if ~isempty(jframe)
              break;
          else
              maxTries = maxTries - 1;
              drawnow; pause(0.1);
          end
      catch
          maxTries = maxTries - 1;
          drawnow; pause(0.1);
      end
  end
  if isempty(jframe)
      error(['Cannot retrieve the java frame for handle ' num2str(hFigHandle)]);
  end
