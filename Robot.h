// Robot.h -- robot motor control code
// Phil Jansen 2nov2021
//
#ifndef ROBOT_H
#define ROBOT_H

#define IS_ROBOT true

void robotControl(uint16_t channelValues[], int numChannels); // command updates

void robotSetup(void); // init
void robotUpdate(void); // maintenance

#endif
