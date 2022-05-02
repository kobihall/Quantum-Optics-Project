#include"RK4Step.h"

void RK4Step(std::complex<double> (*f)(std::complex<double>), std::complex<double> &x, double &t, double dt)
{
    std::complex<double> k1 = f(x);
    std::complex<double> k2 = f(x + (dt/2) * k1);
    std::complex<double> k3 = f(x + (dt/2) * k2);
    std::complex<double> k4 = f(x + dt * k3);
    x += (dt/6)*(k1 + 2.*k2 + 2.*k3 + k4);
    t += dt;
    return;
}

void RK4Step(densityMatrix (*f)(const densityMatrix&), densityMatrix &x, double &t, double dt)
{
    densityMatrix k1 = f(x);
    densityMatrix k2 = f(x + (dt/2) * k1);
    densityMatrix k3 = f(x + (dt/2) * k2);
    densityMatrix k4 = f(x + dt * k3);
    x += (dt/6)*(k1 + 2.*k2 + 2.*k3 + k4);
    t += dt;
    return;
}