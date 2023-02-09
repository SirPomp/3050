#include "main.h"
#include "portdef.hpp"
#include "auton.hpp"
#include "chassis.hpp"
#include "flywheel.hpp"
#include "misc.hpp"
#include "screen.hpp"
#include "opcontrol.hpp"

void autoRed1() {

    resetGyro();
    setIndexer(0);

    // drive to first roller
    driveForDistancePID(-11, 150, 1000);
    gyroTurn(90, 1000);

	setFlywheelSpeed(505);
	spinFlywheel(true);

    // spin first roller
    driveForDistancePID(-2, 150);
    spinIntake(-80);
    chassisMoveIndividuals(-40, -40, -40, -40);
    pros::delay(500);
    spinIntake(0);
    driveForDistancePID(2, 150);

    gyroTurn(7, 1500);

    // fire 2 disks
    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

	setFlywheelSpeed(510);
    pros::delay(2000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

	spinFlywheel(false);

    gyroTurn(125, 1500);

    spinIntake(127);

    driveForDistancePID(-40, 75);

	setFlywheelSpeed(470);
	spinFlywheel(true);
    pros::delay(200);

    gyroTurn(-92, 1500);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    pros::delay(1000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    pros::delay(1000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    spinIntake(0);
    spinFlywheel(false);

}

void autoBlue1() {
    resetGyro();
    setIndexer(0);

    // drive to first roller
    driveForDistancePID(-11, 150, 1000);
    gyroTurn(-90, 1000);

	setFlywheelSpeed(505);
	spinFlywheel(true);

    // spin first roller
    driveForDistancePID(-2, 150);
    spinIntake(-80);
    chassisMoveIndividuals(-40, -40, -40, -40);
    pros::delay(500);
    spinIntake(0);
    driveForDistancePID(2, 150);

    gyroTurn(-7, 1500);

    // fire 2 disks
    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

	setFlywheelSpeed(510);
    pros::delay(2000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

	spinFlywheel(false);

    gyroTurn(-125, 1500);

    spinIntake(127);

    driveForDistancePID(-40, 75);

	setFlywheelSpeed(470);
	spinFlywheel(true);
    pros::delay(200);

    gyroTurn(92, 1500);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    pros::delay(1000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    pros::delay(1000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    spinIntake(0);
    spinFlywheel(false);

}
    
void autoRed2() {
resetGyro();

    // drive to corner 
    driveForDistancePID(12, 100);
    gyroTurn(-45, 1000);

  
    // fire endgame like 5 times 
    setEndgame(0);
    pros::delay(200);
    setEndgame(1);
    pros::delay(200);
    setEndgame(0);
    pros::delay(200);
    setEndgame(1);
    pros::delay(200);
    setEndgame(0);
    pros::delay(200);
    setEndgame(1);
    pros::delay(200);
    setEndgame(0);
    pros::delay(200);
    setEndgame(1);
    pros::delay(200);
    setEndgame(0);
    pros::delay(200);
    setEndgame(1);
    pros::delay(200);

}

void autoBlue2() {

}

void autoBlue2() {

}

void autoRed3() {

}

void autoBlue3() {

}

void skillRun() {

    resetGyro();
    setIndexer(0);

    // drive to first roller
    driveForDistancePID(-11, 150, 1000);
    gyroTurn(90, 1000);

	setFlywheelSpeed(505);
	spinFlywheel(true);

    // spin first roller
    driveForDistancePID(-2, 150);
    spinIntake(-80);
    chassisMoveIndividuals(-40, -40, -40, -40);
    pros::delay(675);
    spinIntake(0);
    driveForDistancePID(2, 150);

    gyroTurn(7, 1500);

    // fire 2 disks
    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

	setFlywheelSpeed(510);
    pros::delay(2000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

	spinFlywheel(false);

    gyroTurn(125, 1500);

    spinIntake(127);

    driveForDistancePID(-40, 75);

	setFlywheelSpeed(470);
	spinFlywheel(true);
    pros::delay(200);

    gyroTurn(-92, 1500);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    pros::delay(1000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    pros::delay(1000);

    setIndexer(1);
    pros::delay(200);
    setIndexer(0);

    spinIntake(0);
    spinFlywheel(false);

    gyroTurn(92, 1500);

    driveForDistancePID(-30, 75);

    setEndgame(1);
    pros::delay(200);
    setEndgame(0);
    pros::delay(200);
    setEndgame(1);
    pros::delay(200);
    setEndgame(0);
    pros::delay(200);
    setEndgame(1);
    pros::delay(200);
    setEndgame(0);
    pros::delay(200);
    setEndgame(1);
    pros::delay(200);
    setEndgame(0);

    driveForDistancePID(-10, 75);
}
