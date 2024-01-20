#ifndef COMPLEX_H
#define COMPLEX_H
struct Complex {
    double real;
    double im;
};
double add(struct Complex a, struct Complex b);
struct Complex negate(struct Complex a);
double multiply(struct Complex a, struct Complex b);
double magnitude(struct Complex a);

#endif
