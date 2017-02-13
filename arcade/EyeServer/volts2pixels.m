function [xPx, yPx] = volts2pixels(xV, yV, gain, screenSize)

xPx = xV/gain(1) * screenSize(1)/2;
yPx = yV/gain(2) * screenSize(2)/2;