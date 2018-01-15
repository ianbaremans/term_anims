#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <tuple>


std::tuple<int, int, int> rgb_id(int id) {
    if (id == 1) return std::make_tuple(255, 0, 0);
    if (id == 2) return std::make_tuple(255, 64, 0);
    if (id == 3) return std::make_tuple(255, 128, 0);
    if (id == 4) return std::make_tuple(255, 191, 0);
    if (id == 5) return std::make_tuple(255, 255, 0);
    if (id == 6) return std::make_tuple(191, 255, 0);
    if (id == 7) return std::make_tuple(128, 255, 0);
    if (id == 8) return std::make_tuple(64, 255, 0);
    if (id == 9) return std::make_tuple(0, 255, 0);
    if (id == 10) return std::make_tuple(0, 255, 64);
    if (id == 11) return std::make_tuple(0, 255, 128);
    if (id == 12) return std::make_tuple(0, 255, 191);
    if (id == 13) return std::make_tuple(0, 255, 255);
    if (id == 14) return std::make_tuple(0, 191, 255);
    if (id == 15) return std::make_tuple(0, 128, 255);
    if (id == 16) return std::make_tuple(0, 64, 255);
    if (id == 17) return std::make_tuple(0, 0, 255);
    if (id == 18) return std::make_tuple(64, 0, 255);
    if (id == 19) return std::make_tuple(128, 0, 255);
    if (id == 20) return std::make_tuple(191, 0, 255);
    if (id == 21) return std::make_tuple(255, 0, 255);
    if (id == 22) return std::make_tuple(255, 0, 191);
    if (id == 23) return std::make_tuple(255, 0, 128);
    if (id == 24) return std::make_tuple(255, 0, 64);
}

void rainbow (int temp_stage) {
    char buffer [1000];
    int clrbuff;
    system("clear");

    for (int i = 0; i < 5; ++i) {
        for (int i = 0; i < 60; ++i) {
            int id_temp = (temp_stage + i) % 25;
            int bgr = std::get<0>(rgb_id(id_temp));
            int bgg = std::get<1>(rgb_id(id_temp));
            int bgb = std::get<2>(rgb_id(id_temp));
            int fgr = bgr;
            int fgg = bgg;
            int fgb = bgb;

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
    int stage = 1;

    while (i = 1) {
        rainbow(stage);
        usleep(11000);
        if (stage < 24) {
            stage = stage + 1;
        } else {
            stage = 1;
        }
    }
}

