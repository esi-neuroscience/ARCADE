classdef EditableVariableEditor < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                    matlab.ui.Figure
        UITable                     matlab.ui.control.Table
        clicktoselect_cfgmatButton  matlab.ui.control.Button
        InsertAboveButton           matlab.ui.control.Button
        InsertBelowButton           matlab.ui.control.Button
        MoveToBottomButton          matlab.ui.control.Button
        DeleteButton                matlab.ui.control.Button
        MoveToTopButton             matlab.ui.control.Button
        DuplicateButton             matlab.ui.control.Button
        SaveButton                  matlab.ui.control.Button
        QuitButton                  matlab.ui.control.Button
        ReloadButton                matlab.ui.control.Button
        ClearAllButton_2            matlab.ui.control.Button
        ARCADEEditableVariableEditorLabel  matlab.ui.control.Label
    end

    
    properties (Access = private)
        activeIndice = []; % active table indice
        matObj = [];
    end
    
    methods (Access = private)
        
        function confirmSave(app,~,event)
            switch event.SelectedOption
                case 'Overwrite'
                    app.matObj.EditableVariables = app.UITable.Data;
                case 'Save as new'
                    oldfilePath = app.matObj.Properties.Source;              
                    newfilePath = inputdlg({'Enter new cfg file name below:'},'Save as',[1 80],{oldfilePath});
                    if ~isequal(oldfilePath,newfilePath{1})
                        copyfile(oldfilePath,newfilePath{1})
                        app.matObj = matfile(newfilePath{1},'Writable',true);
                        [~,activeFileName,~] = fileparts(app.matObj.Properties.Source);
                        app.clicktoselect_cfgmatButton.Text = activeFileName;    
                    end                   
                    app.matObj.EditableVariables = app.UITable.Data;                   
                case 'Cancel'
            end
        end
    end
    

    methods (Access = private)

        % Code that executes after component creation
        function startupFcn(app)
            app.UITable.Data = cell(10,numel(app.UITable.ColumnName));
            app.UITable.ColumnFormat = {[],[],{'Numeric','Logical','Text'}};
        end

        % Button pushed function: clicktoselect_cfgmatButton
        function clicktoselect_cfgmatButtonPushed(app, event)
            [file, path] = uigetfile('*_cfg.mat');
            try
                app.matObj = matfile(fullfile(path,file),'Writable',true);
                [~,activeFileName,~] = fileparts(app.matObj.Properties.Source);
                app.clicktoselect_cfgmatButton.Text = activeFileName;    
                app.UITable.Data = app.matObj.EditableVariables;
            catch
                uialert(app.UIFigure,'Invalid cfg fille','Invalid File'); 
            end

                                
        end

        % Cell selection callback: UITable
        function UITableCellSelection(app, event)
            app.activeIndice = event.Indices;
        end

        % Button pushed function: MoveToBottomButton
        function MoveToBottomButtonPushed(app, event)
            if isempty(app.activeIndice); return;end
            activeRows = sort((unique(app.activeIndice(:,1))));
            inactiveRows = setdiff(1:size(app.UITable.Data,1),activeRows);
            data = cell(size(app.UITable.Data));
            data(end-numel(activeRows)+1:end,:) = app.UITable.Data(activeRows,:);
            data(1:numel(inactiveRows),:) = app.UITable.Data(inactiveRows,:);
            app.UITable.Data = data;          
        end

        % Button pushed function: MoveToTopButton
        function MoveToTopButtonPushed(app, event)
            if isempty(app.activeIndice); return;end
            activeRows = sort((unique(app.activeIndice(:,1))));
            inactiveRows = setdiff(1:size(app.UITable.Data,1),activeRows);
            data = cell(size(app.UITable.Data));
            data(1:numel(activeRows),:) = app.UITable.Data(activeRows,:);
            data(numel(activeRows)+1:end,:) = app.UITable.Data(inactiveRows,:);
            app.UITable.Data = data;          
        end

        % Button pushed function: DuplicateButton
        function DuplicateButtonPushed(app, event)
            if isempty(app.activeIndice); return;end
            activeRows = sort((unique(app.activeIndice(:,1))));
            data = cell(size(app.UITable.Data,1)+numel(activeRows),size(app.UITable.Data,2));
            counter = 1;
            for ii = 1 : size(app.UITable.Data,1)
                data(counter,:) = app.UITable.Data(ii,:);
                counter = counter + 1;
                if ismember(ii, activeRows)
                    data(counter,:) = app.UITable.Data(ii,:);
                    counter = counter + 1;
                end
            end
            app.UITable.Data = data;
        end

        % Button pushed function: InsertAboveButton
        function InsertAboveButtonPushed(app, event)
            if isempty(app.activeIndice); return;end
            data = cell(size(app.UITable.Data,1)+1,size(app.UITable.Data,2));
            
            firstActiveRow = min(unique(app.activeIndice(:,1)));               
            
            if firstActiveRow ~= 1
                data(1:firstActiveRow-1,:) = app.UITable.Data(1:firstActiveRow-1,:);
            end            
            data(firstActiveRow+1:end,:) = app.UITable.Data(firstActiveRow:end,:);                        
            
            app.UITable.Data = data;
        end

        % Button pushed function: InsertBelowButton
        function InsertBelowButtonPushed(app, event)
            if isempty(app.activeIndice); return;end
            data = cell(size(app.UITable.Data,1)+1,size(app.UITable.Data,2));
            
            lastActiveRow = max(unique(app.activeIndice(:,1)));               
            
            data(1:lastActiveRow,:) = app.UITable.Data(1:lastActiveRow,:);
            if lastActiveRow ~= size(app.UITable.Data,1)
                data(lastActiveRow+2:end,:) = app.UITable.Data(lastActiveRow+1:end,:);
            end         
            app.UITable.Data = data;
        end

        % Button pushed function: DeleteButton
        function DeleteButtonPushed(app, event)
            if isempty(app.activeIndice); return;end
            activeRows = sort((unique(app.activeIndice(:,1))));
            inactiveRows = setdiff(1:size(app.UITable.Data,1),activeRows);
            data = app.UITable.Data(inactiveRows,:);
            if ~isempty(data)
                app.UITable.Data = data;
            else
                app.UITable.Data = cell(1,size(app.UITable.Data,2));
            end
        end

        % Button pushed function: ReloadButton
        function ReloadButtonPushed(app, event)
            if ~isempty(app.matObj)
                app.UITable.Data = app.matObj.EditableVariables;
            end
        end

        % Button pushed function: ClearAllButton_2
        function ClearAllButton_2Pushed(app, event)
            app.UITable.Data = cell(1,size(app.UITable.Data,2));
        end

        % Button pushed function: SaveButton
        function SaveButtonPushed(app, event)
            data = app.UITable.Data;
            data = data(all(~cellfun(@isempty,data),2),:);
            app.UITable.Data = data;
            if ~isempty(app.matObj)
                uiconfirm(app.UIFigure,'Saving changes will overwrite current cfg file','Confirm Save','Options',{'Overwrite','Save as new','Cancel'},...
                  'CloseFcn',@(src,event)confirmSave(app,src,event));
            else
                uialert(app.UIFigure,'Please first select an existing cfg file','File Not Imported');
            end
        end

        % Button pushed function: QuitButton
        function QuitButtonPushed(app, event)
            close(app.UIFigure);
        end
    end

    % App initialization and construction
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure
            app.UIFigure = uifigure;
            app.UIFigure.Position = [100 100 570 780];
            app.UIFigure.Name = 'UI Figure';

            % Create UITable
            app.UITable = uitable(app.UIFigure);
            app.UITable.ColumnName = {'Variable Name'; 'Value'; 'Format'};
            app.UITable.ColumnEditable = true;
            app.UITable.CellSelectionCallback = createCallbackFcn(app, @UITableCellSelection, true);
            app.UITable.Position = [47 57 381 649];

            % Create clicktoselect_cfgmatButton
            app.clicktoselect_cfgmatButton = uibutton(app.UIFigure, 'push');
            app.clicktoselect_cfgmatButton.ButtonPushedFcn = createCallbackFcn(app, @clicktoselect_cfgmatButtonPushed, true);
            app.clicktoselect_cfgmatButton.BackgroundColor = [0.8 0.8 0.8];
            app.clicktoselect_cfgmatButton.Position = [47 714 381 22];
            app.clicktoselect_cfgmatButton.Text = 'click to select *_cfg.mat';

            % Create InsertAboveButton
            app.InsertAboveButton = uibutton(app.UIFigure, 'push');
            app.InsertAboveButton.ButtonPushedFcn = createCallbackFcn(app, @InsertAboveButtonPushed, true);
            app.InsertAboveButton.HorizontalAlignment = 'left';
            app.InsertAboveButton.BackgroundColor = [0.8 0.8 0.8];
            app.InsertAboveButton.Position = [436 523 100 22];
            app.InsertAboveButton.Text = 'Insert Above';

            % Create InsertBelowButton
            app.InsertBelowButton = uibutton(app.UIFigure, 'push');
            app.InsertBelowButton.ButtonPushedFcn = createCallbackFcn(app, @InsertBelowButtonPushed, true);
            app.InsertBelowButton.HorizontalAlignment = 'left';
            app.InsertBelowButton.BackgroundColor = [0.8 0.8 0.8];
            app.InsertBelowButton.Position = [436 499 100 22];
            app.InsertBelowButton.Text = 'Insert Below';

            % Create MoveToBottomButton
            app.MoveToBottomButton = uibutton(app.UIFigure, 'push');
            app.MoveToBottomButton.ButtonPushedFcn = createCallbackFcn(app, @MoveToBottomButtonPushed, true);
            app.MoveToBottomButton.HorizontalAlignment = 'left';
            app.MoveToBottomButton.BackgroundColor = [0.8 0.8 0.8];
            app.MoveToBottomButton.Position = [436 611 102 22];
            app.MoveToBottomButton.Text = 'Move To Bottom';

            % Create DeleteButton
            app.DeleteButton = uibutton(app.UIFigure, 'push');
            app.DeleteButton.ButtonPushedFcn = createCallbackFcn(app, @DeleteButtonPushed, true);
            app.DeleteButton.HorizontalAlignment = 'left';
            app.DeleteButton.BackgroundColor = [0.8 0.8 0.8];
            app.DeleteButton.Position = [436 474 100 22];
            app.DeleteButton.Text = 'Delete';

            % Create MoveToTopButton
            app.MoveToTopButton = uibutton(app.UIFigure, 'push');
            app.MoveToTopButton.ButtonPushedFcn = createCallbackFcn(app, @MoveToTopButtonPushed, true);
            app.MoveToTopButton.HorizontalAlignment = 'left';
            app.MoveToTopButton.BackgroundColor = [0.8 0.8 0.8];
            app.MoveToTopButton.Position = [436 587 100 22];
            app.MoveToTopButton.Text = 'Move To Top';

            % Create DuplicateButton
            app.DuplicateButton = uibutton(app.UIFigure, 'push');
            app.DuplicateButton.ButtonPushedFcn = createCallbackFcn(app, @DuplicateButtonPushed, true);
            app.DuplicateButton.HorizontalAlignment = 'left';
            app.DuplicateButton.BackgroundColor = [0.8 0.8 0.8];
            app.DuplicateButton.Position = [436 563 100 22];
            app.DuplicateButton.Text = 'Duplicate';

            % Create SaveButton
            app.SaveButton = uibutton(app.UIFigure, 'push');
            app.SaveButton.ButtonPushedFcn = createCallbackFcn(app, @SaveButtonPushed, true);
            app.SaveButton.HorizontalAlignment = 'left';
            app.SaveButton.BackgroundColor = [0.8 0.8 0.8];
            app.SaveButton.Position = [436 86 100 22];
            app.SaveButton.Text = 'Save';

            % Create QuitButton
            app.QuitButton = uibutton(app.UIFigure, 'push');
            app.QuitButton.ButtonPushedFcn = createCallbackFcn(app, @QuitButtonPushed, true);
            app.QuitButton.HorizontalAlignment = 'left';
            app.QuitButton.BackgroundColor = [0.8 0.8 0.8];
            app.QuitButton.Position = [436 62 100 22];
            app.QuitButton.Text = 'Quit';

            % Create ReloadButton
            app.ReloadButton = uibutton(app.UIFigure, 'push');
            app.ReloadButton.ButtonPushedFcn = createCallbackFcn(app, @ReloadButtonPushed, true);
            app.ReloadButton.HorizontalAlignment = 'left';
            app.ReloadButton.BackgroundColor = [0.8 0.8 0.8];
            app.ReloadButton.Position = [436 424 100 22];
            app.ReloadButton.Text = 'Reload';

            % Create ClearAllButton_2
            app.ClearAllButton_2 = uibutton(app.UIFigure, 'push');
            app.ClearAllButton_2.ButtonPushedFcn = createCallbackFcn(app, @ClearAllButton_2Pushed, true);
            app.ClearAllButton_2.HorizontalAlignment = 'left';
            app.ClearAllButton_2.BackgroundColor = [0.8 0.8 0.8];
            app.ClearAllButton_2.Position = [436 397 100 22];
            app.ClearAllButton_2.Text = 'Clear All';

            % Create ARCADEEditableVariableEditorLabel
            app.ARCADEEditableVariableEditorLabel = uilabel(app.UIFigure);
            app.ARCADEEditableVariableEditorLabel.BackgroundColor = [0 0 1];
            app.ARCADEEditableVariableEditorLabel.HorizontalAlignment = 'center';
            app.ARCADEEditableVariableEditorLabel.FontSize = 24;
            app.ARCADEEditableVariableEditorLabel.FontWeight = 'bold';
            app.ARCADEEditableVariableEditorLabel.FontColor = [1 1 1];
            app.ARCADEEditableVariableEditorLabel.Position = [1 751 570 30];
            app.ARCADEEditableVariableEditorLabel.Text = 'ARCADE Editable Variable Editor';
        end
    end

    methods (Access = public)

        % Construct app
        function app = EditableVariableEditor

            % Create and configure components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            % Execute the startup function
            runStartupFcn(app, @startupFcn)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end