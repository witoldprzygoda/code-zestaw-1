#include "progress_bar.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // Symulacja operacji z postępem
    for (int i = 0; i <= 100; ++i) {
        printProgressBar(i/100.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Symulacja pracy
    }
    std::cout << std::endl;
}
