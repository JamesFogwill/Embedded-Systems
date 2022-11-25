#include "mbed.h"
#include <cmath>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

class DoubleNumber {
private:

protected:
    double _real;

public:
    //Designated constructor
    DoubleNumber(double r) { // So this allows me to create a new doubleNumber and set its value by passing in an argument
        _real = r;
        cout << "This is the constructor of Base" << endl;
    }

    //Convenience constructor
    DoubleNumber() : DoubleNumber(0.0) { } //  this will initialise doubleNumber with argument 0.0 only when i use the funciton doubleNumber without adding an argument. Thats why its a convience, because i can just write doubleNumber() and it will run as if parameter r is 0.0.

    //Magnitude
    double magnitude() {
        return fabs(_real);
    }

    //Three overloaded functions
    // the functions all have the same name so what happens when you call it?
    // basically the correct function gets called depending on what parameter you pass in.
    //pretty cool right?!
    void setValue(double u) {
        _real = u;
    }
    void setValue(int u) {
        _real = (double)u;
    }
    void setValue(string strVal) {
        _real = stod(strVal);
    }
    //my way is below
    //void setValue(DoubleNumber u){
    //    _real = u._real;
    //}
    
    //This is nicks way
    void setValue(DoubleNumber& u) {
        this->setValue(u.getValue());
    }

    double getValue() {
        return _real;
    }

    string asString() {
        return to_string(_real);
    }
};


int main()
{
    //Constructor Function overloading 
    DoubleNumber n0(1.0);
    DoubleNumber n1(n0);
    DoubleNumber n2;

    //setValue function overloading  
    n1.setValue(10);
    n2.setValue("-3.0");

    cout << n0.getValue() + n1.getValue() + n2.getValue() << endl;
    
    while (true) {

    }
}

