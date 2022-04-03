#pragma once

template <typename T>
void RK4Step(T (*f)(const T), T &x, double &t, double dt)
{
    T k1 = f(x);
    T k2 = f(x + (T)(dt/2) * k1);
    T k3 = f(x + (T)(dt/2) * k2);
    T k4 = f(x + (T)dt * k3);
    x += (T)(dt/6)*(k1 + (T)2*k2 + (T)2*k3 + k4);
    t += dt;
    return;
}