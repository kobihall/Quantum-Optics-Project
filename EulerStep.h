#pragma once

template <typename T>
void eulerStep(T (*f)(const T), T &x, double &t, double dt)
{
    x += f(x)*(T)(dt);
    t += dt;
    return;
}