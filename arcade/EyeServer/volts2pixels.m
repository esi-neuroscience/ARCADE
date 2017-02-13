function [xPx yPx] = volts2pixels(xV, xV, gain, screenSize)

xPx = xV/gain(1) * screenSize(1)/2;
yPx = xV/gain(2) * screenSize(2)/2;