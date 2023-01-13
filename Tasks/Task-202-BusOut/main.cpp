#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define BOARD_LED1 PB_0
#define BOARD_LED2 PB_7
#define BOARD_LED3 PB_14
// Objects
// DigitalOut grn(TRAF_GRN1_PIN);
// DigitalOut yel(TRAF_YEL1_PIN);
// DigitalOut red(TRAF_RED1_PIN,1);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN, BOARD_LED1,BOARD_LED2,BOARD_LED3);

int main()
{
    while (true) {
        leds = 0;   //Binary 000
        wait_us(500000);
        leds = 0b111110;   //Binary 111
        wait_us(500000);    
    }
}


