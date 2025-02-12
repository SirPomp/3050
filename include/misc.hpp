#ifndef _MISC_H_
#define _MISC_H_

void initializeVision();

// Set pneumatics to extend (1) or retract (0)
void toggleIndexer(int toggle);

void setEndgame(int input);

void spinIntake(int speed);

void spinIndexer(int speed);

void stopIntakeDelayed(void* param);

#endif