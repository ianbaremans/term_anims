#include <iostream>
#include <random>
#include <string>
#include <stdio.h>
#include <unistd.h>

void anim () {
    std::random_device r;
    char buffer [1000];
    int clrbuff;
    system("clear");

    for (int i = 0; i < 5; ++i) {
        for (int i = 0; i < 60; ++i) {
            std::default_random_engine e1(r());
            std::uniform_int_distribution<int> uniform_dist(0,255);
            int fgr = uniform_dist(e1); //ForeGroundRed
            int fgg = uniform_dist(e1);
            int fgb = uniform_dist(e1);
            int bgr = uniform_dist(e1);
            int bgg = uniform_dist(e1);
            int bgb = uniform_dist(e1);

            clrbuff = snprintf(buffer, 1000,
                    "\033[48;2;%d;%d;%d;38;2;%d;%d;%dm",
                    bgr, bgg, bgb, fgr, fgg, fgb);

            const std::string color(buffer);
            const std::string reset("\033[0m");
            std::cout << color << "\u2584" << reset;
        }
        std::cout << "\n";
    }
}

int main () {
    int i = 1;
    while (i = 1) {
       anim();
       usleep(10000);
    }
}

