#ifndef PORT_DEF_H_
#define PORT_DEF_H_

// Motor Port Assignments
// Drive Base Motors
#define FRONT_RIGHT_DRIVE_MOTOR 3
#define FRONT_LEFT_DRIVE_MOTOR 5
#define BACK_RIGHT_DRIVE_MOTOR 8
#define BACK_LEFT_DRIVE_MOTOR 10

// Lift Motor
#define FLYWHEEL_1 15
#define FLYWHEEL_2 16

// Radio and Controllers Port Definitions
#define VEX_RADIO 20

// V5 Sensors
#define VISION_PORT 21
#define GPS_PORT 17
#define INERTIAL_PORT 7

// Tri Port Assignments, Ports A-H are mapped to 1-8
#define PNEUMATIC_LIFT_CLAW 1
#define PNEUMATIC_BACK_CLAW 2

#define LATERAL_BASE_ENCODER_TOP 3
#define LATERAL_BASE_ENCODER_BOTTOM 4

// Define Default Autonomous Behavior
#define DEFAULT_RECAUTON false
#define DEFAULT_SELECTION 0

#define VEXNET_MANUAL true        // turns opcontrol into allowing for
                                  // testing autonomous code

#endif
