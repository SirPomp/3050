#ifndef _LIFT_H_
#define _LIFT_H_

#include "api.h"

// spin the Fhywheel, range: +-600
void spinFlywheel(bool pressed, int speed);

// stop the flywheel with the given brake mode
void stopFlywheel(pros::motor_brake_mode_e_t brakeType);

void resetFlywheelEncoders();

// Get the current lift lock mode of the break
pros::motor_brake_mode_e_t getliftLockMode();

void displayFlywheelData();

void toggleVariableFlywheel(bool input);

#endif
