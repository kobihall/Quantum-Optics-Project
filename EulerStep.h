#pragma once

template <typename T>
void eulerStep(T f, T &x, double &t, double dt)
{
    x += x*(T)(f*dt);
    t += dt;
    return;
}