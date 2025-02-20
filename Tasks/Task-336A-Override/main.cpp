#include "DoubleNumber.hpp"
#include "ComplexNumber.hpp"

int main()
{
    //Constructor Function overloading 
    ComplexNumber c0(1.0, 2.0);
    DoubleNumber  d0(3.0);
    ComplexNumber c1;
    DoubleNumber  d1;
    
    //This uses the operator= function
    d1 = 5.0;

    //Write the value as a string
    cout << d1.asString() << endl;

    //Now overrides the default =
    c1 = c0;

    //Now overrides the parent asString
    cout << c1.asString() << endl;

    //Challenge - try and understand this ;)
    cout << c1.asDoubleNumber().asString() << endl;
    //the above line takes the double number c1 and outputs its own address, then if the asString has a parameter that is complex or imaginary it will add that part and output the numbers together in complex number form so with the + and j. Check with Nick if this is correct.

    //TODO - write an overloaded + operator
    DoubleNumber sum1 = c0 + c1 + d0 + d1;
    cout << sum1 << endl;

    while (true) {

    }
}

