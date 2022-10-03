#include "mbed.h"
#include <cstdio>

typedef struct {
  double real;
  double imag;
} ComplexNumber_C;

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

ComplexNumber_C complexConjugate(const ComplexNumber_C a)
{
    ComplexNumber_C y;
    y = { a.real, a.imag*-1};
    return y;
}

ComplexNumber_C complexNegate(const ComplexNumber_C a)
{
    ComplexNumber_C y;
    y = {a.real*-1, a.imag*-1};
    return y;
}

ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b)
{
    ComplexNumber_C y;
    y  = {a.real - b.real, a.imag - b.imag};
    return y;
}

float complexMagnitude(const ComplexNumber_C a)
{
    float y;
    y = sqrt((a.real*a.real + a.imag*a.imag));
    return y;
}

ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b)
{
    ComplexNumber_C y;
    y.real = ((a.real*b.real) - (a.imag*b.imag));
    y.imag = ((a.real*b.imag) + (a.imag*b.real));
    return y;
}

ComplexNumber_C complexDivide(const ComplexNumber_C a, const ComplexNumber_C b)
{
    ComplexNumber_C y;
    y.real = ((a.real*b.real) + (a.imag*b.imag)) / ((b.real*b.real) + (b.imag*b.imag));
    y.imag = ((a.imag*b.real) + (a.real*b.imag)) / ((b.real*b.real) + (b.imag*b.imag));
    return y;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}



// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK312\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
    complexDisplay("p", p);
    complexDisplay("q", q);
 
    ComplexNumber_C sum = complexAdd(p, q);
    complexDisplay("p+q", sum);

    ComplexNumber_C subtract = complexSubtract(p, q);
    complexDisplay("p-q", subtract);

    ComplexNumber_C multiply = complexMultiply(p, q);
    complexDisplay("p*q", multiply);

    ComplexNumber_C divide = complexDivide(p, q);
    complexDisplay("p/q", divide);

    float magnitude = complexMagnitude(p);
    printf("magnitude of p %f", magnitude);

    ComplexNumber_C conjugate = complexConjugate(p);
    complexDisplay("p conjugate", conjugate);

    ComplexNumber_C negate = complexNegate(p);
    complexDisplay("p negate", negate);

    
    while (true) {
    }
}
