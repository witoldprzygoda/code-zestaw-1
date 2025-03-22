#include <iostream>
#include "fibonacci.h"

int main() {
    // Maksymalna wartość n, dla której F(n) mieści się w size_t na 64-bitowych systemach
    const size_t MAX_N = 93;
    
    // Wypisz wszystkie wyrazy ciągu od 1 do MAX_N
    for (size_t i = 1; i <= MAX_N; ++i) {
        std::cout << "F(" << i << ") = " << fib(i) << std::endl;
    }
    
    return 0;
}
