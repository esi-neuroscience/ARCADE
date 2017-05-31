ARCADE
======

*ARCADE* is a modular suite of Applications for Real-time Control of subject
Actions and stimulus Diplay for behavioral Experiments. It consists of several
interacting modules that are running in parallel and take advantage of modern
multi-core CPU architectures.

The software is developed by Jarrod Dowdall (jarrod.dowdall@esi-frankfurt.de),
Joscha Schmiedt (joscha.schmiedt@esi-frankfurt.de) and Michael Stephan
(michael.stephan@esi-frankfurt.de)


Brief overview of modules
-------------------------
* The Core module controls and manages the flow of the experiment. A user-
generated MATLAB task script defines all stimuli, conditions and experimental
states. The sequence of states is what defines the flow of the experiment
* The StimServer module presents the stimuli on screen.
* The EyeServer module (and further input devices in the future) handles eye tracking.
* The ControlScreen shows statistics about the current session.

Getting started
---------------

To get started add the ARCADE folder and its subfolders to your MATLAB path.
The tutorial documentaiton can then be found by opening the MATLAB help
browser under Supplemental Software. Alternatively, open arcade/Docs/html/ARCADE.html
in a browser. 

To start arcade, use arcade/start_arcade.bat

Requirements
------------
Currently ARCADE can only run on

* Windows 7 with Windows Platform Update (https://www.microsoft.com/en-us/download/details.aspx?id=36805)
* MATLAB 2014a, 64-bit
* Eyelink eye tracker or eye signal via National Instruments PCI card.
