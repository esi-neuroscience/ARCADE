classdef AUXGridDisplay < handle
    % [AUXILLARY] GRID DISPLAY 
    % - provide grid plotting functions 

    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    % User editable 
    properties (AbortSet = true)
        gridtype@char    = 'circle';         % 'circle', 'square', 'cartesian','none'
        %gridtype@char    = 'cartesian';
        fixtype@char     = 'both';           % 'xcross','+cross','both','none'
        fixcolor@double  = [0.70,0.70,0.70]; % color of center fix
        gridcolor@double = [0.70,0.70,0.70]; % color of grid 
        
        % add special eccentricty 
        % 3*ppd, + 1*ppd
    end
    
    properties (...
            AbortSet = true,...
            Access = private)
        hgrid % grid marker handle
        hfix  % fixation marker handle
    end
    
    methods (Static = true)
        function this =  AUXGridDisplay
            %this = this@AUXMarkerObject;
        end
    end

    methods (...
            Sealed = true,...
            Access = protected)
        %# DRAW GRID
        function mDrawGrid(this, parent_ax, screensize, pixelspacing)

            gridType = this.gridtype; % property 
            fixType  = this.fixtype;  % property
            
            % -- get size of axis
            % get physical pixel size on control screen
            % to compute a mapping between the whole display and this
            % scaled version (shown on the control screen)
            parent_pos = get(parent_ax,'Position'); 

            % Draw Grid
            if ~isempty(gridType) && ~strcmp(gridType,'none')
                
                % calculate grid lines
                [grid, grid_y] = this.mComputeGrid(...
                    screensize,pixelspacing,...
                    gridType,parent_pos(3:4));
                
                switch gridType
                    case 'circle'
                        this.hgrid = this.mGridCircle(...
                            parent_ax, grid, this.gridcolor);
                    case 'square'
                        this.hgrid = this.mGridSquare(...
                            parent_ax, grid, this.gridcolor);
                    case 'cartesian'
                        this.mGridCartesian(...
                            parent_ax, grid, grid_y, this.gridcolor);
                    otherwise
                end
            end
            
            % Draw fixation
            if ~isempty(fixType) && ~strcmp(fixType,'none')
                switch fixType
                    case '+cross'
                        marker = '+';
                    case 'xcross'
                        marker = 'x';
                    case 'both'
                        marker = '*';
                    otherwise
                end
                
                fixsize = max(parent_pos(3:4));
                
                this.hfix = AUXMarkerObject.mDrawMarker(...
                    parent_ax,...      % parent axis
                    [0,0],...          % position
                    this.fixcolor,...  % color
                    fixsize,....       % markersize
                    marker,...         % marker
                    'none');           % erasemode
            end
        end
      
    end
    
    methods (...
            Static = true,...
            Sealed = true,...
            Access = protected)
        
        %# CIRCLE ECCENTRIC GRID
        function hm = mGridCircle(parent_ax,rings,gridcolor)
            % fixed properties:
            position = [0,0];
            erase    = 'none';
            marker   = 'o';
           
            for k = 1:numel(rings)
                hm(k) = AUXMarkerObject.mDrawMarker(...
                    parent_ax,...
                    position,...
                    gridcolor,...
                    rings(k),....
                    marker,...
                    erase); %#ok<AGROW>
            end
        end
        
        %# SQUARE ECCENTRIC GRID
        function hm = mGridSquare(parent_ax,rings,gridcolor)
            % fixed properties:
            position = [0,0];
            erase    = 'none';
            marker   = 's';

            for k = 1:numel(rings)
                hm(k) = AUXMarkerObject.mDrawMarker(...
                    parent_ax,...
                    position,...
                    gridcolor,...
                    rings(k),....
                    marker,...
                    erase); %#ok<AGROW>
            end
        end
        
        %# CARTESIAN GRID
        function mGridCartesian(parent_ax,xlines,ylines,gridcolor) 
            % uses built in axis grid lines 
            set(parent_ax,...
                'XTick',xlines,...
                'YTick',ylines,...
                'YGrid','on',...
                'XGrid','on',...
                'XTickLabel',[],...
                'YTickLabel',[],...
                'YMinorGrid','off',...
                'XMinorGrid','off',...
                'YColor',gridcolor,...
                'XColor',gridcolor);            
        end
        
        function [grid, grid_y] = mComputeGrid(pSize,pSpace,gridType,axsize)
            % Cartersian is inherently mapped to the pixels of the screen
            % through xlim/ylim
            % The other two grids use markers, and thus must be scaled
            
            % Cartesian:
            % plot size     -> pSize  = display screen size
            % pixel spacing -> pSpace = pixels per deg
            
            % Circle/Square
            % plot size     -> pSize  = axis size
            % pixel spacing -> pSpace = pixels per deg scaled by axis ratio

            %pSpace = 52.18;
            %pSize  = [1680,1050]; 
            
            if strcmp(gridType,'cartesian')
                % do not include fixation
                grid = (1:floor(pSize(1)/(pSpace*2)))*pSpace;
                grid = [-fliplr(grid), grid]';
                
                grid_y = (1:floor(pSize(2)/(pSpace*2)))*pSpace;
                grid_y = [-fliplr(grid_y), grid_y]';
               
            else
                grid_y = [];
                % adjust the pixels in screen size to plot size 
                screen2plot_ratio = pSize./axsize;
                pSize  = axsize;
                pSpace = pSpace/screen2plot_ratio(1);
                
                % must be diameter, not radius
                grid = (1:floor(max(pSize)/(pSpace*2)))*pSpace*2;
            end
        end
    end
end

