clear all; clc;

T = readtable('testODE2.csv');
x0 = T.x0;
x1 = T.x1;
t = T.t;

plot(t,real(x1),t,real(x0))