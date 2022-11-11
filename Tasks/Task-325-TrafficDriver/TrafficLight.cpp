#include "TrafficLight.h"

//Contructor
TrafficLight::TrafficLight(PinName redPin, PinName yellowPin, PinName greenPin) 
                                                        : redLED(redPin), yellowLED(yellowPin), greenLED(greenPin)
// redPin (say pin 4) gets passed into traffic light as a parameter and initialised.
// the initialisation happens by passing pin 4 into the Object redLED of class DigitalOut. then pin 4 is initialised with //the constructor of Digital out.
{
    // These objects are already initialised in the member initialisation list above
    redLED = 1;
    yellowLED = 0;
    greenLED = 0;
    // Timer off
    flashYellow(false);
}

//Destructor
TrafficLight::~TrafficLight()
{
    redLED = 1;
    yellowLED = 0;
    greenLED = 0;
} 

// Interrupt Service Routine (ISR)
void TrafficLight::yellowFlashISR() {
    yellowLED = !yellowLED;
}

// Private member function to switch flasher on or off
void TrafficLight::flashYellow(bool flash) {
    t.detach(); //Turn off ticker
    if (flash) {
        //Turn on ticker ..... Hmmm, interrupts!
        t.attach(callback(this, &TrafficLight::yellowFlashISR), flashSpeedms);
    }
}

void TrafficLight::stop() {
    redLED = 1;
    yellowLED = 0;
    greenLED = 0;
}

void TrafficLight::setFlashSpeed(double flashSpeed) {
    flashSpeedms = flashSpeed;
    TrafficLight::flashYellow(true);
}

double TrafficLight::getFlashSpeed() {
    return flashSpeedms;
}

// Moore Machine - update outputs
void TrafficLight::updateOutput()
{
    switch (State)
    {
        case STOP:
            flashYellow(false);
            redLED = 1;
            yellowLED = 0;
            greenLED = 0;
            break;
        case READY:
            flashYellow(false);
            redLED = 1;
            yellowLED = 1;
            greenLED = 0;
            break;
        case GO:
            flashYellow(false);
            redLED = 0;
            yellowLED = 0;
            greenLED = 1;
            break;
        case WARNING:
            redLED = 0;
            flashYellow(true);
            greenLED = 0;
            break;                
    }       
}

// Moore machine - next state logic
TrafficLight::LIGHT_STATE TrafficLight::nextState()
{
    // Update State
    switch (State)
    {
        case STOP:
            State = READY;
            break;
        case READY:
            State = GO;
            break;
        case GO:
            State = WARNING;
            break;
        case WARNING:
            State = STOP;
            break;
    }

    //As it says
    updateOutput();

    //Return the current state (for information)
    return State; 
} 