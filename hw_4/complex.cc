#include <cmath>
#include <cfloat> // For DBL_EPSILON
#include "complex.h"


Complex::Complex(double re, double im) : re(re), im(im) {}

double Complex::real() const {
    return re;
}

double Complex::imaginary() const {
    return im;
}

Complex Complex::conjugate() const {
    return Complex(re, -im);
}

Complex Complex::operator+(const Complex& rhs) const {
    return Complex(re + rhs.re, im + rhs.im);
}

Complex Complex::operator*(const Complex& rhs) const {
    return Complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
}

bool Complex::operator==(const Complex& rhs) const {
    return std::abs(re - rhs.re) < DBL_EPSILON && std::abs(im - rhs.im) < DBL_EPSILON;
}

double Complex::magnitude() const {
    return sqrt(re*re + im*im);
}

bool operator<(const Complex& a, const Complex& b) {
    return a.magnitude() < b.magnitude();
}
