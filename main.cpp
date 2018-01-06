#include <iostream>

int main () {
    for (int i = 0; i < 5; ++i) {
        for (int i = 0; i < 60; ++i) {
            const std::string color("\033[48;2;0;0;0;38;2;0;0;0m");
            const std::string reset("\033[0m");
            std::cout << color << "\u2584" << reset;
        }
        std::cout << "\n";
    }
}

