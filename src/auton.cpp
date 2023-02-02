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
    setIndexer(1);

    // drive to first roller
    driveForDistancePID(-15, 150, 1000);
    gyroTurn(90, 1000);

    // spin first roller
    driveForDistancePID(-2, 150);
    spinIntake(-80);
    chassisMoveIndividuals(-20, -20, -20, -20);
    pros::delay(500);
    spinIntake(0);
    driveForDistancePID(2, 150);
    gyroTurn(-55, 1000);

    // drive to firing spot
	setFlywheelSpeed(470);
	spinFlywheel(true);

    // driveForDistancePID(35, 200);
    driveForDistancePID(44, 175);
    // driveForDistancePID(5, 150);
    pros::delay(200);
    gyroTurn(105, 1800);

    // fire 2 disks
    setIndexer(0);
    pros::delay(200);
    setIndexer(1);

    pros::delay(2000);

    setIndexer(0);
    pros::delay(200);
    setIndexer(1);

	spinFlywheel(false);

    // tested code ends here, end here for just roller + 2 shots

    // drive to second roller

    // gyroTurn(92, 1500);
    gyroTurn(-103, 1800);

    // driveForDistancePID(-38, 200);
    driveForDistancePID(35, 200);

    // gyroTurn(-50, 1000);
    gyroTurn(130, 1000);

    // spin second roller
    spinIntake(80);
    // driveForDistancePID(-2, 100);
    chassisMoveIndividuals(-40, -40, -40, -40);
    pros::delay(1000);
    driveForDistancePID(1, 100);
    spinIntake(0);
    chassisStopDrive(pros::E_MOTOR_BRAKE_HOLD);
}

void autoBlue1() {

    resetGyro();
    setIndexer(1);

    // drive to first roller
    driveForDistancePID(-15, 150, 1000);
    gyroTurn(-90, 1000);

    // spin first roller
    driveForDistancePID(-2, 150);
    spinIntake(-80);
    chassisMoveIndividuals(-20, -20, -20, -20);
    pros::delay(500);
    spinIntake(0);
    driveForDistancePID(2, 150);
    gyroTurn(55, 1000);

    // drive to firing spot
	setFlywheelSpeed(470);
	spinFlywheel(true);

    // driveForDistancePID(35, 200);
    driveForDistancePID(44, 175);
    // driveForDistancePID(5, 150);
    pros::delay(200);
    gyroTurn(-105, 1800);

    // fire 2 disks
    setIndexer(0);
    pros::delay(200);
    setIndexer(1);

    pros::delay(2000);

    setIndexer(0);
    pros::delay(200);
    setIndexer(1);

	spinFlywheel(false);

    // tested code ends here, end here for just roller + 2 shots

    // drive to second roller

    // gyroTurn(-92, 1500);
    gyroTurn(103, 1800);

    // driveForDistancePID(-38, 200);
    driveForDistancePID(35, 200);

    // gyroTurn(50, 1000);
    gyroTurn(-130, 1000);

    // spin second roller
    spinIntake(80);
    // driveForDistancePID(-2, 100);
    chassisMoveIndividuals(-40, -40, -40, -40);
    pros::delay(1000);
    driveForDistancePID(1, 100);
    spinIntake(0);
    chassisStopDrive(pros::E_MOTOR_BRAKE_HOLD);
}

void autoRed2() {

    resetGyro();
    setIndexer(1);

    // drive to first roller
    driveForDistancePID(-15, 150, 1000);
    gyroTurn(90, 1000);

    // spin first roller
    driveForDistancePID(-2, 150);
    spinIntake(-80);
    chassisMoveIndividuals(-20, -20, -20, -20);
    pros::delay(500);
    spinIntake(0);
    driveForDistancePID(2, 150);
    gyroTurn(-55, 1000);

    // drive to firing spot
	setFlywheelSpeed(470);
	spinFlywheel(true);

    // driveForDistancePID(35, 200);
    driveForDistancePID(44, 175);
    // driveForDistancePID(5, 150);
    pros::delay(200);
    gyroTurn(105, 1800);

    // fire 2 disks
    setIndexer(0);
    pros::delay(200);
    setIndexer(1);

    pros::delay(2000);

    setIndexer(0);
    pros::delay(200);
    setIndexer(1);

	spinFlywheel(false);
}

void autoBlue2() {

    resetGyro();
    setIndexer(1);

    // drive to first roller
    driveForDistancePID(-15, 150, 1000);
    gyroTurn(-90, 1000);

    // spin first roller
    driveForDistancePID(-2, 150);
    spinIntake(-80);
    chassisMoveIndividuals(-20, -20, -20, -20);
    pros::delay(500);
    spinIntake(0);
    driveForDistancePID(2, 150);
    gyroTurn(55, 1000);

    // drive to firing spot
	setFlywheelSpeed(470);
	spinFlywheel(true);

    // driveForDistancePID(35, 200);
    driveForDistancePID(44, 175);
    // driveForDistancePID(5, 150);
    pros::delay(200);
    gyroTurn(-105, 1800);

    // fire 2 disks
    setIndexer(0);
    pros::delay(200);
    setIndexer(1);

    pros::delay(2000);

    setIndexer(0);
    pros::delay(200);
    setIndexer(1);

	spinFlywheel(false);
}

void autoRed3() {

}

void autoBlue3() {

}

void skillRun() {

    seek(0, 0, 10000);

}