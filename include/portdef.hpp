#ifndef PORT_DEF_H_
#define PORT_DEF_H_

// Motor Port Assignments
// Drive Base Motors
#define FRONT_RIGHT_DRIVE_MOTOR 2
#define FRONT_LEFT_DRIVE_MOTOR 19
#define BACK_RIGHT_DRIVE_MOTOR 11
#define BACK_LEFT_DRIVE_MOTOR 17

// Lift Motor
#define FLYWHEEL_1 7
#define FLYWHEEL_2 18

// Indexer Motor
#define INDEXER 5

// Intake Motor
#define INTAKE 10

// Radio and Controllers Port Definitions
#define VEX_RADIO 11

// V5 Sensors
#define VISION_PORT 22
#define GPS_PORT 20
#define GYRO_PORT 14

// Tri Port Assignments, Ports A-H are mapped to 1-8
#define PNEUMATIC_INDEXER 8
#define PNEUMATIC_END_GAME 6

#define LATERAL_BASE_ENCODER_TOP 3
#define LATERAL_BASE_ENCODER_BOTTOM 4

// Define Default Autonomous Behavior
#define DEFAULT_SELECTION 0

#define VEXNET_MANUAL true        // turns opcontrol into allowing for
                                  // testing autonomous code

#endif
