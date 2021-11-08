// tracked robot support
// Phil Jansen 2nov2021
//
#include <Arduino.h>
#include "Robot.h"
#include "RX.h"

////////////////////////////////////////////////////////////////////////////////
// convert radio channel value to +/- 100% range
int radioToPct(uint16_t servoSetting) {
    int percent =  map(servoSetting, CHANNEL_MIN_VALUE, CHANNEL_MAX_VALUE, -100, 100);
    return percent;
}

////////////////////////////////////////////////////////////////////////////////
// set new goals for robot
void robotControl(uint16_t rxChannels[], int numChannels) {
    int aDirection = 0;
    int aSpeed = 0;
    if (numChannels > 1) {
        aDirection = radioToPct(rxChannels[0]); // proportion left/right
        aSpeed = radioToPct(rxChannels[1]); // forward/backward
        // ...
    }
}

////////////////////////////////////////////////////////////////////////////////
// init robot HW and maintenance tasks
void robotSetup(void) {
    ; // init
}

////////////////////////////////////////////////////////////////////////////////
// update periodic maintenance tasks (e.g. slowly ramp up to max speed etc)
void robotUpdate(void) {
    ; // maintenance
}
