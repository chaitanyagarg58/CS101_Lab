#include <iostream>
#include <cmath>

const double PI = 3.14159265;

struct Complex
{
    double real;
    double imag;

    Complex conjugate()
    {
        Complex z;
        z.real = real;
        z.imag = -1 * imag;
        return z;
    }

    double modulus()
    {
        return sqrt(real * real + imag * imag);
    }

    double argument()
    {
        return atan2(imag, real);
    }

    Complex add(Complex c)
    {
        Complex z;
        z.real = real + c.real;
        z.imag = imag + c.imag;
        return z;
    }

    Complex multiply(Complex c)
    {
        Complex z;
        z.real = real * c.real - imag * c.imag;
        z.imag = real * c.imag + imag * c.real;
        return z;
    }

    double abs_angle_between(Complex c)
    {
        double arg = std::abs(c.argument() - argument());
        if (arg <= PI)
            return arg;
        else
            return 2 * PI - arg;
    }

    void print()
    {
        if (imag >= 0)
            std::cout << real << " + " << imag << "i" << std::endl;
        else
            std::cout << real << " - " << -1 * imag << "i" << std::endl;
    }
};