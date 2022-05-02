#pragma once

#include <cstddef>
#include <complex>
#include <cmath>
#include <array>

#include "DensityMatrix.h"

/*template <typename T>
void RK4Step(T (*f)(const T), T &x, double &t, double dt)
{
    T k1 = f(x);
    T k2 = f(x + (T)(dt/2) * k1);
    T k3 = f(x + (T)(dt/2) * k2);
    T k4 = f(x + (T)dt * k3);
    x += (T)(dt/6)*(k1 + (T)2*k2 + (T)2*k3 + k4);
    t += dt;
    return;
}*/

void RK4Step(std::complex<double> (*f)(std::complex<double>), std::complex<double> &x, double &t, double dt);

void RK4Step(densityMatrix (*f)(const densityMatrix&), densityMatrix &x, double &t, double dt);