#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
    Complex(double re = 0.0, double im = 0.0);

    double real() const;
    double imaginary() const;
    double magnitude() const;
    Complex conjugate() const;
    Complex operator+(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;
    bool operator==(const Complex& rhs) const;

private:
    double re, im;
};

bool operator<(const Complex& a, const Complex& b);

#endif 
