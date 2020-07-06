![ARCADE Logo](/arcade/Docs/html/arcade.png)


ARCADE
======

*ARCADE* is a modular suite of Applications for Real-time Control of subject
Actions and stimulus Diplay for behavioral Experiments. It consists of several
interacting modules that are running in parallel and take advantage of modern
multi-core CPU/GPU architectures.

Brief overview of modules
-------------------------
* The Core module controls and manages the flow of the experiment. A user-
  generated MATLAB task script defines all stimuli, conditions and experimental
  states. The sequence of states is what defines the flow of the experiment
* The StimServer module presents the stimuli on screen.
* The DaqServer handles digital input and output: eventmarkers, reward, digital input
* The EyeServer module (and further input devices in the future) handles eye
  tracking.
* The ControlScreen shows statistics about the current session.

Getting started
---------------
To get started add the ARCADE/arcade folder and its subfolders to your MATLAB
path. The tutorial documentation can then be found by opening the MATLAB help
browser under Supplemental Software or using the command 

	doc arcade

Alternatively, open the file arcade/Docs/html/ARCADE.html in a browser.

To start arcade, use arcade/start_arcade.bat

Requirements
------------
Currently ARCADE was only tested on

* Windows 7 with Windows Platform Update and Windows 10 (v1803)
* MATLAB 2014a (64-bit), MATLAB 2018b
* Eyelink 1000/2000 eye tracker
* National Instruments I/O devices PCI-6221, PCI-6503, PCIe-6251, PCIe-6323,
  PCIe-6321 and USB-6353


Authors and contributors
------------------------
The following people have contributed code and/or ideas to the current version
of ARCADE:

* Jarrod Dowdall (jarrod.dowdall@esi-frankfurt.de)
* Joscha Schmiedt (joscha.schmiedt@esi-frankfurt.de)
* Katharine Shapcott (katharine.shapcott@esi-frankfurt.de)
* Michael Stephan (michael.stephan@esi-frankfurt.de)
* Yufeng Zhang (yufeng.zhang@esi-frankfurt.de)

The ARCADE software is free but copyrighted software, distributed
under the terms of the GNU General Public Licence as published by
the Free Software Foundation (either version 3, or at your option
any later version). See the file LICENSE for more details.
