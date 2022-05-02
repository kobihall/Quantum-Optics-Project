clear all; clc;

T = readtable('testODE1.csv');
x = T.x;
t = T.t;

plot(t,abs(x),t,real(x),t,imag(x))