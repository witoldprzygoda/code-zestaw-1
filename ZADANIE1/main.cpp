#include <iostream>
#include <thread>
#include "pi_calculation.h"

int main() {
    double suma1 {0.}, suma2 {0.};    
    const long num_steps = 300'000'000;
    double step = 1.0 / (double)num_steps;
    
    // utworzyc dwa obiekty watkow (potem poinformowac o tym main), kazdy wykona funkcje partial_sum
    // z polowa obliczen, nalezy pamietac o przekazaniu suma1 i suma2 przez std::ref
    



    double pi = (suma1 + suma2) * step;
    std::cout << "PI = " << pi << " (obliczone na 2 watkach)" << std::endl;
}
