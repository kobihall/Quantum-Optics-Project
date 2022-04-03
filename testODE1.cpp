#include <iostream>
#include <fstream>
#include <iomanip>
#include <complex>
#include <cmath>

#include "EulerStep.h"
#include "RK4Step.h"

static std::complex<double> eitODE(std::complex<double> x)
{
    std::complex<double> i (0,1);
    return i*x;
}

int main()
{
    std::complex<double> x (1,0);
    double t = 0;
    double dt = .001;

    std::ofstream dataFile;
    dataFile.open("testODE1.csv");
    dataFile << "x,t\n";
    dataFile << real(x) << "+" << imag(x) << "i ," << t << "\n";

    while(t < 3.141592){
        RK4Step<std::complex<double> >(eitODE, x, t, dt);
        //x = x/std::norm(x);
        dataFile << real(x) << "+" << imag(x) << "i ," << t << "\n";
    }
    dataFile.close();
    return 0;
}