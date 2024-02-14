#include <iostream>
#include "stb_image.h"
#include "raylib.h" 
#include <chrono>
#include <thread>
#include <cstdio>

int main(int argc, char const *argv[]){

    int width,height,n;

    const int numofimages = 1;
    std::string images[numofimages] = {"image.png"}; // list of images to animate
    unsigned char *data = stbi_load(images[0].c_str(), &width, &height, &n, 0);

    InitWindow(width, height, "image");

    printf("width:%d  height:%d\n", width, height);
    printf("%d\n", n);


    // ... process data if not NULL ..
    if (data == nullptr || width <= 0 || height <= 0)
    {
        return -1;
    }
    int x = 0;
    int y = 0;
    int i = 0;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    long long int numofpixels = width * height;

    int fps = 1000 / ( 12 );
    std::chrono::system_clock::time_point o = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
    switch (n){
        case 1:
            while (!WindowShouldClose()){
                if (i == numofimages){
                    i = 0;
                }
                data = stbi_load(images[i].c_str(), &width, &height, &n, 0);
                o = std::chrono::system_clock::now();
                std::chrono::duration<double, std::milli> work_time = o - p;

                if (work_time.count() < fps)
                {
                    std::chrono::duration<double, std::milli> delta_ms(fps - work_time.count());
                    auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
                }

                p = std::chrono::system_clock::now();
                std::chrono::duration<double, std::milli> sleep_time = p - o;

                BeginDrawing();
                ClearBackground((Color){0, 0, 0, 255});
                for (int y = 0; y < height; y++){
                    for (int x = 0; x < width; x++){
                        r = data[((x) + (y*width))];
                        DrawPixel(x, y, (Color){r,r,r,255});            //replace with vex pros version of draw pixel
                    }
                }
                EndDrawing();

                printf("Time: %f \n", (work_time + sleep_time).count());
                stbi_image_free(data);
                i++;

            }
            break;
        case 2:
            while (!WindowShouldClose()){
                if (i == numofimages){
                    i = 0;
                }
                data = stbi_load(images[i].c_str(), &width, &height, &n, 0);
                o = std::chrono::system_clock::now();
                std::chrono::duration<double, std::milli> work_time = o - p;

                if (work_time.count() < fps)
                {
                    std::chrono::duration<double, std::milli> delta_ms(fps - work_time.count());
                    auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
                }

                p = std::chrono::system_clock::now();
                std::chrono::duration<double, std::milli> sleep_time = p - o;

                BeginDrawing();
                ClearBackground((Color){0, 0, 0, 255});
                for (int y = 0; y < height; y++){
                    for (int x = 0; x < width; x++){
                        r = data[((x) + (y*width))*2];
                        a = data[((x) + (y*width))*2 + 1];
                        DrawPixel(x, y, (Color){r,r,r,a});            //replace with vex pros version of draw pixel
                    }
                }
                EndDrawing();
                printf("Time: %f \n", (work_time + sleep_time).count());
                stbi_image_free(data);
                i++;
            }
            break;
        case 3:
            while (!WindowShouldClose()){
                if (i == numofimages){
                    i = 0;
                }
                data = stbi_load(images[i].c_str(), &width, &height, &n, 0);
                o = std::chrono::system_clock::now();
                std::chrono::duration<double, std::milli> work_time = o - p;

                if (work_time.count() < fps)
                {
                    std::chrono::duration<double, std::milli> delta_ms(fps - work_time.count());
                    auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
                }

                p = std::chrono::system_clock::now();
                std::chrono::duration<double, std::milli> sleep_time = p - o;

                BeginDrawing();
                ClearBackground((Color){0, 0, 0, 255});
                for (int y = 0; y < height; y++){
                    for (int x = 0; x < width; x++){
                        r = data[((x) + (y*width))*3];
                        g = data[((x) + (y*width))*3 + 1];
                        b = data[((x) + (y*width))*3 + 2];
                        DrawPixel(x, y, (Color){r,g,b,255});            //replace with vex pros version of draw pixel
                    }
                }
                EndDrawing();
                printf("Time: %f \n", (work_time + sleep_time).count());
                stbi_image_free(data);
                i++;
            }
            break;
        case 4:
            while (!WindowShouldClose()){
                if (i == numofimages){
                    i = 0;
                }
                data = stbi_load(images[i].c_str(), &width, &height, &n, 0);
                o = std::chrono::system_clock::now();
                std::chrono::duration<double, std::milli> work_time = o - p;

                if (work_time.count() < fps)
                {
                    std::chrono::duration<double, std::milli> delta_ms(fps - work_time.count());
                    auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
                }

                p = std::chrono::system_clock::now();
                std::chrono::duration<double, std::milli> sleep_time = p - o;

                BeginDrawing();
                ClearBackground((Color){0, 0, 0, 255});
                for (int y = 0; y < height; y++){
                    for (int x = 0; x < width; x++){
                        r = data[((x) + (y*width))*4];
                        g = data[((x) + (y*width))*4 + 1];
                        b = data[((x) + (y*width))*4 + 2];
                        a = data[((x) + (y*width))*4 + 3];
                        DrawPixel(x, y, (Color){r,g,b,a});            //replace with vex pros version of draw pixel
                    }
                }
                EndDrawing();
                printf("Time: %f \n", (work_time + sleep_time).count());
                stbi_image_free(data);
                i++;
            }
            break;
    }
}