#ifndef _OPCONTROL_H_
#define _OPCONTROL_H_

#include <iostream>
#include <vector>

using namespace std;

#define DRIVE_MODE 3          // 1 for x-drive TANK
                              // 2 for x-drive ARDCADE
                              // 3 for standard TANK
                              // 4 for standard ARCADE

#define JOY_SCALE 0.5          // scale the joysticks to 50% valid values are 0 - 1
                              // note: 0 will disable joysticks 0 * x = 0 always....

#define DEAD_STICK 10         // Dead stick zone - joystick movement between
                              // -DEAD_STICK and DEAD_STICK will result in a joystick
                              // value of 0 - dealing with slow creepign of robot when joysticks
                              // do not land perfectly in the center position

#define SCALING 1.0           // Constant that all chassis speeds are multiplied by, 
                              // used to scale all chassis movement. 

void control();

// Helper for calculating averages
int average(int x, int y);

#endif