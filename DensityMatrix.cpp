#include "DensityMatrix.h"
#include <iostream>
#include <stdexcept>

#include <complex>

/*void dmprint(const densityMatrix& r){
    std::cout << "[";
    for(int i = 0; i < r.size(); i++){
        std::cout << real(r[i]);
        if(imag(r[i]) != 0 ){
            if(imag(r[i]) > 0) std::cout << "+";
            else std::cout << "-";
            std::cout << imag(r[i]) << "i, m";
        }
    }
}*/

//default constructor
densityMatrix::densityMatrix()
{
    size = 1;
    data = new std::complex<double>[1];
}

//constructor
densityMatrix::densityMatrix(int N)
{
    size = N;
    data = new std::complex<double>[N];
}
//constructor
densityMatrix::densityMatrix(const std::complex<double>* r, int N)
{
    if(r){
        size = N;
        data = new std::complex<double>[size];
        for (int i = 0; i < N; i++) data[i] = r[i];
    }
    else{
        size = 1;
        data = new std::complex<double>[1];
    }
}

//copy contsructor
densityMatrix::densityMatrix(const densityMatrix& r)
{
    size = r.size;
    data = new std::complex<double>[size];
    for (int i = 0; i < size; i++) data[i] = r.data[i];
}

//copy assignment
densityMatrix& densityMatrix::operator=(const densityMatrix& rhs)
{
    if(this == &rhs){
        return *this;
    }

    delete[] data;
    size = rhs.size;
    data = new std::complex<double>[size];
    for (int i = 0; i < size; i++) data[i] = rhs.data[i];

    return *this;
}

//destructor
densityMatrix::~densityMatrix()
{
    delete[] data;
}

std::complex<double>& densityMatrix::operator[](int i)
{
    return data[i];
}

const std::complex<double>& densityMatrix::operator[](int i) const
{
    return ((densityMatrix&)*this)[i];
}

densityMatrix operator+(const densityMatrix& r1, const densityMatrix& r2)
{
    /*try{
        if(r1.size == r2.size){
            densityMatrix temp;
            delete[] temp.data;
            temp.size = r1.size;
            temp.data = r1.data;
            for (int i = 0; i < temp.size; i++) temp.data[i] += r2.data[i];
            return temp;
        }
        else throw(r1.size);
    }
    catch(int N) {
        std::cout << "addition failed. Density matrix sizes do not match \n";
    }*/

    if(r1.size == r2.size){
        densityMatrix temp(r1.size);
        //delete[] temp.data;
        //temp.size = r1.size;
        //temp.data = r1.data;
        for (int i = 0; i < temp.size; i++) temp.data[i] = r1.data[i] + r2.data[i];
        return temp;
    }
    std::cout << "addition failed. Density matrix sizes do not match \n";
    return densityMatrix();
}

densityMatrix& operator+=(densityMatrix& lhs, const densityMatrix& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

densityMatrix operator*(const std::complex<double> c, densityMatrix r)
{
    for(int i = 0; i < r.size; i++){
        r[i] = c*r[i];
    }
    return r;
}

densityMatrix operator*(const double c, densityMatrix r)
{
    for(int i = 0; i < r.size; i++){
        r[i] = c*r[i];
    }
    return r;
}