#include "main.h"
#include "portdef.hpp"
#include "auton.hpp"
#include "chassis.hpp"
#include "flywheel.hpp"
#include "misc.hpp"
#include "file.hpp"
#include "screen.hpp"
#include "opcontrol.hpp"

extern int selection;
extern pros::Mutex mutex;
bool recAutonActive;
/**
 * This is where all the various autonomous routines are located
 * and subsequently called by the autonomous() selector based on GUI input
 **/
void recordableAuton() {
    //printVectors();
    recAutonActive = true;
    pros::Task recAutonThread(recAutonLoop);

    while (true) {}
}

void recAutonLoop(void * param) {
	std::cout << "recAutonLoop started" << std::endl;
    // char filename[20];
    // sprintf(filename, "/usd/RecAuton%i.txt", selection);
    // readFromFile(filename);

    int interations = getVectorSize();
    int recOutputs[28];
    double cords[3];
    int starttime = pros::millis();
    if (interations > 0) {
        for (int index = 0; index < interations; index++) {
            updateVecs(index, &recOutputs[0]);
            updateLocation(index, &cords[0]);

            mutex.take(25);
            // courseCorrect(index, &recOutputs[0], &cords[0]);
            processInput(&recOutputs[0]);
            mutex.give();

            pros::delay(20);
        }
    }

    std::cout << "auton run time ellapsed: " << pros::millis() - starttime << std::endl;
}

    // pros::Task thread1(closeBackClaw, (void*)500);

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

}

void autoBlue2() {

}

void autoRed3() {

}

void autoBlue3() {

}

void skillRun() {

    seek(0, 0, 10000);

}