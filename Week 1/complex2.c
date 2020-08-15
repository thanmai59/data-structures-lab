#include <stdio.h>
typedef struct complex {
    float real;
    float imag;
} complex;

complex sub(complex n1, complex n2);

int main() {
    complex n1, n2, result;


    scanf("%f %f", &n1.real, &n1.imag);
    scanf("%f %f", &n2.real, &n2.imag);

    result = sub(n1, n2);

    printf("y = %.1f - %.1fi", result.real, result.imag);
    return 0;
}

complex sub(complex n1, complex n2) {
    complex x;
    x.real = n1.real - n2.real;
    x.imag = n1.imag - n2.imag;
    return (x);
}