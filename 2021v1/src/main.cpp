#include "main.h"
#include "init.h"
#include "portdef.h"
#include "auto.h"
#include "chassis.h"
#include "lift.h"
#include "roller.h"
#include "screen.h"

  lv_obj_t * autonButton;
	bool buttonToggle = false;
  lv_obj_t * autonButtunLabel;
  lv_obj_t * label;
  lv_obj_t * testImage;

	lv_style_t * defaultStyle = &lv_style_plain;
	lv_style_t * autonButtonStyle = createBtnStyle(defaultStyle, LV_COLOR_MAKE(235, 235, 52), LV_COLOR_MAKE(0, 0, 0),
	LV_COLOR_MAKE(255, 38, 0), LV_COLOR_MAKE(0, 255, 68), LV_COLOR_MAKE(0, 0, 0), LV_COLOR_MAKE(0, 0, 0));

	lv_obj_t * autonButtons = (lv_obj_t*)malloc(sizeof(lv_obj_t) * 8);


	for (int x = 0; x < 8; x++) {
		autonButtons[x] = lv_btn_create(parent, NULL);
	}

static lv_res_t btn_click_action(lv_obj_t * btn) {
		uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons

		if(id == 0) {
			char buffer[100];
		 sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
		 lv_label_set_text(label, buffer);
		 btnSetToggled(btn, buttonToggle);
		 buttonToggle = !buttonToggle;
		}
		return LV_RES_OK;
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	// Motor Setup
	// GEARSET_36 -- RED
	// GEARSET_18 -- GREEN (default)
	// GEARSET_6 -- BLUE

	pros::Motor front_right_motor(FRONT_RIGHT_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor front_left_motor(FRONT_LEFT_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor back_right_motor(BACK_RIGHT_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor back_left_motor(BACK_LEFT_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

	pros::Motor tray_motor(TRAY_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

	pros::Motor lift_motor(LIFT_MOTOR, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

	pros::Motor right_roller_motor(RIGHT_ROLLER_MOTOR, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor left_roller_motor(LEFT_ROLLER_MOTOR, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

	autonButtons[0] = createBtn(lv_scr_act(), 25, 25, 100, 50, 1, "butt1");
	autonButton = createBtn(lv_scr_act(), 25, 25, 100, 50, 2, "butt2");

	lv_obj_set_free_num(autonButton, 0);
	lv_btn_set_action(autonButton, LV_BTN_ACTION_CLICK, btn_click_action);
	setBtnStyle(autonButtonStyle, autonButton);

	label = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(label, "Button has not been clicked yet"); //sets label text
	lv_obj_align(label, NULL, LV_ALIGN_IN_LEFT_MID, 10, 0); //set the position to center

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void autonomous() {
	// We are calling a autonomous function based on the selection
  // we made on the LCD

	/*
	switch(selection) {
		case 0 :
			pros::lcd::print(4, "Script#: %d\n", selection);
      pros::lcd::print(5, titles[selection]);
      skillRun();
      break;

		case 1 :
			pros::lcd::print(4, "Script#: %d\n", selection);
      pros::lcd::print(5, titles[selection]);
      autoRedLeft();
      break;

    case 2 :
      pros::lcd::print(4, "Script#: %d\n", selection);
      pros::lcd::print(5, titles[selection]);
    	autoBlueLeft();
      break;

    case 3 :
    	pros::lcd::print(4, "Script#: %d\n", selection);
      pros::lcd::print(5, titles[selection]);
      autoRedRight();
      break;

    case 4 :
      pros::lcd::print(4, "Script#: %d\n", selection);
      pros::lcd::print(5, titles[selection]);
      autoBlueRight();
      break;

    default :
      // this should never happen as selection is alwasy inialized as 0
      // does the case of '0' is in essence the defualt.
      break;
  }
*/
}
