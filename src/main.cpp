#include "main.h"
#include "pros/apix.h"

LV_IMG_DECLARE(a);
LV_IMG_DECLARE(b);
LV_IMG_DECLARE(l); // gets mad about c
LV_IMG_DECLARE(d);
LV_IMG_DECLARE(e);
LV_IMG_DECLARE(f);
LV_IMG_DECLARE(g);
LV_IMG_DECLARE(h);

lv_obj_t *images[8];


void updateScreen(void*){
    int i = 0;
    while (true) {
        i = 0;
        lv_img_set_src(images[i], &a);
        lv_obj_align(images[i], NULL, LV_ALIGN_CENTER, 0, 0);

        delay(142);

        i++;
        lv_img_set_src(images[i], &b);
        lv_obj_align(images[i], NULL, LV_ALIGN_CENTER, 0, 0);
        delay(142);

        i++;
        lv_img_set_src(images[i], &l);
        lv_obj_align(images[i], NULL, LV_ALIGN_CENTER, 0, 0);

        i++;
        lv_img_set_src(images[i], &d);
        lv_obj_align(images[i], NULL, LV_ALIGN_CENTER, 0, 0);

        delay(142);
        i++;
        lv_img_set_src(images[i], &e);
        lv_obj_align(images[i], NULL, LV_ALIGN_CENTER, 0, 0);

        delay(142);
        i++;
        lv_img_set_src(images[i], &f);
        lv_obj_align(images[i], NULL, LV_ALIGN_CENTER, 0, 0);

        delay(142);
        i++;
        lv_img_set_src(images[i], &g);
        lv_obj_align(images[i], NULL, LV_ALIGN_CENTER, 0, 0);

        delay(142);
        i++;
        lv_img_set_src(images[i], &h);
        lv_obj_align(images[i], NULL, LV_ALIGN_CENTER, 0, 0);
        
        delay(142);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    for (int i = 0; i < 8; i++){
        images[i] = lv_img_create(lv_scr_act(), NULL);
    }

    Task my_task(updateScreen, (void*)"parameter(s) here", "My Task Name");
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
void autonomous() {}

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
    pros::Controller master(pros::E_CONTROLLER_MASTER);

    while (true) {
        //pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
        //                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
        //                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

        //Brain.Screen.drawImageFromFile("field.png", 0, 0);

        pros::delay(20);
    }
}