#include "main.h"
#include "portdef.hpp"
#include "chassis.hpp"
#include "flywheel.hpp"
#include "misc.hpp"
#include "screen.hpp"
#include "opcontrol.hpp"

extern int selection;

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	while (true) {
		
		control();
		pros::delay(20);

	}
}

void control() {
	int rightX = master.get_analog(ANALOG_RIGHT_X);
	int rightY = master.get_analog(ANALOG_RIGHT_Y);
	int leftX = master.get_analog(ANALOG_LEFT_X);
	int leftY = master.get_analog(ANALOG_LEFT_Y);

	if (abs(rightX) < DEAD_STICK) rightX = 0; 
	if (abs(rightY) < DEAD_STICK) rightY = 0; 
	if (abs(leftX) < DEAD_STICK) leftX = 0; 
	if (abs(leftY) < DEAD_STICK) leftY = 0; 
	rightX = (rightX * SCALING);
	rightY = (rightY * SCALING);
	leftX = (leftX * SCALING);
	leftY = (leftY * SCALING);

	if (DRIVE_MODE == 1) {
		// We want to do X-Drive TANK control

		chassisMoveIndividuals((rightY - average(rightX, leftX)),
							(leftY + average(rightX, leftX)),
							(rightY + average(rightX, leftX)),
							(leftY - average(rightX, leftX)));
	}
	else if (DRIVE_MODE == 2) {
		// We want to do X-Drive ARCADE control
		
		chassisMoveIndividuals((rightY - leftX - rightX),
							(rightY + leftX + rightX),
							(rightY - leftX + rightX),
							(rightY + leftX - rightX));
	}
	else if (DRIVE_MODE == 3) {
		// we are wanting to do standard TANK Control

        chassisMoveIndividuals(-rightY, -leftY, -rightY, -leftY);

	}
	else if (DRIVE_MODE == 4) {
		// We are wanting to do standard ARCADE control

		chassisMoveIndividuals(leftY - leftX, leftY + leftX, leftY - leftX, leftY + leftX);
	}
	
	if (partner.get_digital(DIGITAL_R1)) setFlywheelSpeed(500);
	if (partner.get_digital(DIGITAL_R2)) setFlywheelSpeed(450);
	if (partner.get_digital(DIGITAL_L1)) setFlywheelSpeed(400);
	if (partner.get_digital(DIGITAL_L2)) setFlywheelSpeed(360);

	// spinFlywheel(arrInputs[27] || arrInputs[26] || arrInputs[25] || arrInputs[24]);

	spinFlywheel(partner.get_digital(DIGITAL_R1) || partner.get_digital(DIGITAL_R2) || partner.get_digital(DIGITAL_L1) || partner.get_digital(DIGITAL_L2));

	if (master.get_digital(DIGITAL_R2)) {
		spinIntake(127);
	}
	else if (master.get_digital(DIGITAL_R1)) {
		spinIntake(-64);
	}
	else {
		spinIntake(0);
	}

	if (master.get_digital(DIGITAL_L1)) {
		spinIndexer(-64);
	}
	else {
		spinIndexer(0);
	}

	toggleIndexer(master.get_digital(DIGITAL_L2));

	// pollGps();
	pollGyro();

	if (master.get_digital(DIGITAL_RIGHT)) setEndgame(0);
	if (master.get_digital(DIGITAL_LEFT)) setEndgame(1);
	if (master.get_digital(DIGITAL_R2)) spinIndexer(1);

	// accumulateGyroOffset();
}

int average(int x, int y) {
  return((x + y) / 2);
}