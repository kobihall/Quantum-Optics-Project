#pragma once

#include <cstddef>
#include <complex>
#include <cmath>
#include <array>

//void dmprint(const densityMatrix& r);

class densityMatrix {
public:
    densityMatrix(); //default constructor
    densityMatrix(int N); //constructor
    densityMatrix(const std::complex<double>*,int N); //constructor
    densityMatrix(const densityMatrix& r); //copy constructor
    densityMatrix& operator=(const densityMatrix& rhs); //copy assignment

    ~densityMatrix(); //destructor

    std::complex<double>& operator[](int i);
    const std::complex<double>& operator[](int i) const;
    friend densityMatrix operator+(const densityMatrix& r1, const densityMatrix& r2);
    friend densityMatrix& operator+=(densityMatrix& lhs, const densityMatrix& rhs);
    friend densityMatrix operator*(const std::complex<double> c, densityMatrix r);
    friend densityMatrix operator*(const double c, densityMatrix r);
private:
    std::complex<double>* data;
    std::size_t size;
};