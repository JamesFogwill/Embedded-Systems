#ifndef __TRAFFICLIGHT__
#define __TRAFFICLIGHT__

#include "mbed.h"
using namespace chrono;

#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

class TrafficLight 
{
    public:
    typedef enum {STOP, READY, GO, WARNING} LIGHT_STATE;

    private:
    DigitalOut redLED;
    DigitalOut yellowLED;
    DigitalOut greenLED;
    Ticker t;
    LIGHT_STATE State;
    double flashSpeedms = 200;

    void yellowFlashISR();
    void flashYellow(bool flash);
    void updateOutput();

    public:
    //Constructor
    TrafficLight(PinName redPin = TRAF_RED1_PIN, PinName yellowPin = TRAF_YEL1_PIN, PinName greenPin=TRAF_GRN1_PIN); 

    //Destructor
    ~TrafficLight();

    //Member function
    void stop();

    //member funciton
    void setFlashSpeed(double);

    //member function
    double getFlashSpeed();

    //Advance the traffic lights to the next state
    LIGHT_STATE nextState();

};


#endif