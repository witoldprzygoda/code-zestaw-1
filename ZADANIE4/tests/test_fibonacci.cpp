#include <iostream>
#include <cassert>
#include "../fibonacci.h"

void test_fibonacci() {
    // Test znanych wartości ciągu Fibonacciego
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    assert(fib(5) == 5);
    assert(fib(6) == 8);
    assert(fib(7) == 13);
    assert(fib(8) == 21);
    assert(fib(9) == 34);
    assert(fib(10) == 55);
    
    // Test większych wartości
    assert(fib(20) == 6765);
    assert(fib(30) == 832040);
    assert(fib(40) == 102334155);
    assert(fib(50) == 12586269025UL);
    
    // Test relacji rekurencyjnej dla losowych wartości
    for (size_t i = 3; i <= 60; i++) {
        assert(fib(i) == fib(i-1) + fib(i-2));
    }
    
    std::cout << "Wszystkie testy przeszły pomyślnie!" << std::endl;
}

int main() {
    test_fibonacci();
    return 0;
}
