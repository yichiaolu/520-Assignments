#include <math.h>
#include "complex.h"

double add(struct Complex a, struct Complex b) {
    return a.real + b.real;

}
struct Complex negate(struct Complex a) {
    struct Complex result;
    result.real = -a.real;
    result.im = -a.im;
    return result;
}

double multiply(struct Complex a, struct Complex b) {
    return a.real * b.real - a.im * b.im;

}
double magnitude(struct Complex a) {
    return sqrt(a.real * a.real + a.im * a.im);
}
