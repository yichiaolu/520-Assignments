#include <stdio.h>
#include "complex.h"

int main() {

    struct Complex a = {1.0, 2.0};
    struct Complex b = {3.0, 4.0};

    printf("Addition: %f\n", add(a, b));
    printf("Negation: %f + %fi\n", negate(a).real, negate(a).im);
    printf("Multiplication: %f\n", multiply(a, b));
    printf("Magnitude: %f\n", magnitude(a));
    return 0;
}
