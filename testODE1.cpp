#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>

#include "EulerStep.h"

int main()
{
    std::complex<double> i (0,1);
    std::complex<double> x (1,0);
    double t = 0;
    double dt = .01;
    while(t < 3.141592){
        eulerStep(i, x, t, dt);
        std::cout << x << std::endl;
    }
    return 0;
}