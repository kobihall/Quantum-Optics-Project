#include <iostream>
#include <fstream>
#include <iomanip>
#include <complex>
#include <cmath>
#include <array>

#include "DensityMatrix.h"
#include "EulerStep.h"
#include "RK4Step.h"

static densityMatrix shoODE(const densityMatrix& x)
{
    densityMatrix xd(2);
    xd[0] = x[1];
    xd[1] = -x[0];
    return xd;
}

int main()
{
    //densityMatrix rho({(1.,0.),(0.,0.)}, 2);
    densityMatrix rho(2);
    rho[0] = std::complex<double>(1.0, 0.0);
    //rho[1] = (0.0, 0.0);
    //std::complex<double> *rho = new std::complex<double>[2];
    double t = 0;
    double dt = .001;

    std::ofstream dataFile;
    dataFile.open("testODE2.csv");
    dataFile << "x0,x1,t\n";
    dataFile << real(rho[0]) << "+" << imag(rho[0]) << "i ," << real(rho[1]) << "+" << imag(rho[1]) << "i ," << t << "\n";
    std::cout << "x0,x1,t\n";
    std::cout << real(rho[0]) << "+" << imag(rho[0]) << "i ," << real(rho[1]) << "+" << imag(rho[1]) << "i ," << t << "\n";

    /*densityMatrix k1 = shoODE(rho);
    //rho = rho + dt/2 * k1;
    densityMatrix k2 = shoODE(rho + dt/2 * k1);
    densityMatrix k3 = shoODE(rho + dt/2 * k2);
    densityMatrix k4 = shoODE(rho + dt* k3);
    rho = rho + (dt/6)*(k1 + 2.*k2 + 2.*k3 + k4);
    std::cout << real(rho[0]) << "+" << imag(rho[0]) << "i ," << real(rho[1]) << "+" << imag(rho[1]) << "i ," << t << "\n";*/
    while(t < 3.141592){
        RK4Step(shoODE, rho, t, dt);
        //x = x/std::norm(x);
        dataFile << real(rho[0]) << "+" << imag(rho[0]) << "i ," << real(rho[1]) << "+" << imag(rho[1]) << "i ," << t << "\n";
        std::cout << real(rho[0]) << "+" << imag(rho[0]) << "i ," << real(rho[1]) << "+" << imag(rho[1]) << "i ," << t << "\n";
    }
    dataFile.close();
    return 0;
}