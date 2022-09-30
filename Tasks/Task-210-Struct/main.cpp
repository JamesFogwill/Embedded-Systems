#include "mbed.h"
#include <cstdio>

// Date Type ComplexNumber_C
typedef struct {
  double real;
  double imag;
} ComplexNumber_C;


int main() {

    //Create instance of a complex number
    ComplexNumber_C p;

    //Initialise each attribute 
    p.real = 2.0;
    p.imag = 3.0;
    
    //Create and Initialise 
    ComplexNumber_C q = {1.0, 1.0};

    // TASK:
    // Create another complex number y
    // Calculate the complex sum of p and q and store in y
    // Use printf to display as a complex number (hint: you need two placeholders)
    
    ComplexNumber_C y;

    y  = {p.real + q.real, p.imag + q.imag};
     

    int i = 0;

    while (i == 0) {
        printf("%f, %f\r\n" , y.real, y.imag); // %f is for a double data type which is defined in the creation of the complex number data type at the top. 
        // ask the lectureer why it prints "3." in the terminal before the actual complex number...
        i++;
    }
}
