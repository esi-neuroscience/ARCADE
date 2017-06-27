function [xPx, yPx] = volts2pixels(xV, yV, gain, screenSize)
% VOLTS2PIXELS - Convert analog voltage to screen coordinates based on gain
% and screensize in px

xPx = xV/gain(1) * screenSize(1)/2;
yPx = yV/gain(2) * screenSize(2)/2;