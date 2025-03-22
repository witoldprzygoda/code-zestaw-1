#include <gtest/gtest.h>
#include <cmath>
#include "../pi_calculation.h"

// Test dla prostego przypadku z znanym wynikiem
TEST(PartialSumTest, SimpleCase) {
    double result = 0.0;
    double step = 1.0;
    
    partial_sum(0, 1, step, result);
    
    // Oczekiwane: 4.0 / (1.0 + 0.5^2) = 4.0 / 1.25 = 3.2
    EXPECT_NEAR(result, 3.2, 1e-10);
}

// Test dla wielu kroków
TEST(PartialSumTest, MultipleSteps) {
    double result = 0.0;
    double step = 0.5;
    
    // Dla dwóch kroków przy x=0.25 i x=0.75
    partial_sum(0, 2, step, result);
    
    // Oczekiwane: 4.0 / (1.0 + 0.25^2) + 4.0 / (1.0 + 0.75^2) ≈ 6.32471
    EXPECT_NEAR(result, 6.32471, 1e-5);
}

// Test z znanym wynikiem analitycznym
TEST(PartialSumTest, KnownResult) {
    double result = 0.0;
    long num_steps = 1000000;
    double step = 1.0 / num_steps;
    
    partial_sum(0, num_steps, step, result);
    double pi_approx = result * step;
    
    // Dla dużej liczby kroków, wynik powinien być w przybliżeniu π
    EXPECT_NEAR(pi_approx, M_PI, 1e-5);
}

// Test dla zerowej liczby kroków
TEST(PartialSumTest, ZeroSteps) {
    double result = 123.0;  // Inicjalizacja niezerową wartością
    double step = 0.1;
    
    partial_sum(0, 0, step, result);
    
    EXPECT_NEAR(result, 0.0, 1e-10);
}

// Test dla ekstremalnych indeksów
TEST(PartialSumTest, ExtremeIndices) {
    double result = 0.0;
    double step = 0.1;
    
    // Gdy start_idx równa się end_idx, nic się nie dzieje
    partial_sum(10, 10, step, result);
    
    EXPECT_NEAR(result, 0.0, 1e-10);
}

// Test dla ujemnych kroków
TEST(PartialSumTest, NegativeRange) {
    double result = 0.0;
    double step = 0.1;
    
    // Gdy end_idx < start_idx, suma powinna być 0
    partial_sum(10, 5, step, result);
    
    EXPECT_NEAR(result, 0.0, 1e-10);
}