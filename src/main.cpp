#include "main.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <chrono>
#include <thread>
#include <cstdio>
#include <iostream>

struct button {
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
    char[16] identifier;
}

button buttons[2] = {
    (button){0, 0, 60, 120, "button1"},
    (button){0, 120, 60, 120, "button2"},
};

void updateScreen(void*){
	int width,height,n;

    const int numofimages = 1;
    std::string images[numofimages] = {"/usd/image.png"}; // list of images to animate
    unsigned char *data = stbi_load(images[0].c_str(), &width, &height, &n, 0);

    int x = 0;
    int y = 0;
    int i = 0;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    long long int numofpixels = width * height;
    int start, end;
    int color = 0;

    uint32_t fps = 1000 / ( 12 );
    switch (n){
        case 1:
            while (true){
                start = pros::millis();

                if (i == numofimages){
                    i = 0;
                }
                data = stbi_load(images[i].c_str(), &width, &height, &n, 0);


                for (int y = 0; y < height; y++){
                    for (int x = 0; x < width; x++){
                        r = data[((x) + (y*width))];
                        color = 0;
                        color |= r << 16;
                        color |= r << 8;
                        color |= r;
                        pros::screen::set_pen(color);
                        pros::screen::draw_pixel(x,y);
                        //printf("%x\n", color);
                        //DrawPixel(x, y, (Color){r,r,r,255});            //replace with vex pros version of draw pixel
                    }
                }
                stbi_image_free(data);
                i++;

                end = pros::millis();

                pros::delay(fps - (end-start));
            }
            break;
        case 2:
            while (true){
                if (i == numofimages){
                    i = 0;
                }
                data = stbi_load(images[i].c_str(), &width, &height, &n, 0);


                for (int y = 0; y < height; y++){
                    for (int x = 0; x < width; x++){
                        r = data[((x) + (y*width))*2];
                        a = data[((x) + (y*width))*2 + 1];
                        color = 0;
                        color |= r << 16;
                        color |= r << 8;
                        color |= r;
                        pros::screen::set_pen(color);
                        pros::screen::draw_pixel(x,y);
                        //printf("%x\n", color);
                        //DrawPixel(x, y, (Color){r,r,r,a});            //replace with vex pros version of draw pixel
                    }
                }
                stbi_image_free(data);
                i++;
            }
            break;
        case 3:
            while (true){
                if (i == numofimages){
                    i = 0;
                }
                data = stbi_load(images[i].c_str(), &width, &height, &n, 0);


                for (int y = 0; y < height; y++){
                    for (int x = 0; x < width; x++){
                        r = data[((x) + (y*width))*3];
                        g = data[((x) + (y*width))*3 + 1];
                        b = data[((x) + (y*width))*3 + 2];
                        color = 0;
                        color |= r << 16;
                        color |= g << 8;
                        color |= b;
                        pros::screen::set_pen(color);
                        pros::screen::draw_pixel(x,y);
                        //printf("%d\n", color);
                        //DrawPixel(x, y, (Color){r,g,b,255});            //replace with vex pros version of draw pixel
                    }
                }
                stbi_image_free(data);
                i++;
            }
            break;
        case 4:
            while (true){
                if (i == numofimages){
                    i = 0;
                }
                data = stbi_load(images[i].c_str(), &width, &height, &n, 0);


                for (int y = 0; y < height; y++){
                    for (int x = 0; x < width; x++){
                        r = data[((x) + (y*width))*4];
                        g = data[((x) + (y*width))*4 + 1];
                        b = data[((x) + (y*width))*4 + 2];
                        a = data[((x) + (y*width))*4 + 3];
                        color = 0;
                        color |= r << 16;
                        color |= g << 8;
                        color |= b;
                        pros::screen::set_pen(color);
                        pros::screen::draw_pixel(x,y);
                        //printf("%x\n", color);
                        //DrawPixel(x, y, (Color){r,g,b,a});            //replace with vex pros version of draw pixel
                    }
                }
                stbi_image_free(data);
                i++;

                for (int i = 0; i < sizeof(buttons) / sizeof(button); i++) {
                    //(const std::int16_t x0, const std::int16_t y0, const std::int16_t x1, const std::int16_t y1)
                    pros::screen::fill_rect(buttons[i].x, buttons[i].y, buttons[i].x + buttons[i].width, buttons[i].y + buttons[i].height);
                }
            }
            break;
    }
}


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::Task mytask(updateScreen);
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
void changePixel() {
    pros::screen_touch_status_s_t status = pros::screen::touch_status();
    for (int i = 0; i < sizeof(buttons) / sizeof(button); i++) {
        if (status.x > buttons[i].x && status.y > buttons[i].y && status.x < buttons[i].x + buttons[i].width && status.y < buttons[i].y + buttons[i].height){
            printf("button pressed");
        }
    }
}

void opcontrol() {
    pros::screen::touch_callback(changePixel, TOUCH_PRESSED);
    while(1) {
        pros::delay(20);
    }
}