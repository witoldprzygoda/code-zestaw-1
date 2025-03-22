#include "random_generators.h"
#include <random>
#include <chrono>

// Statyczny generator liczb losowych (widoczny tylko w tym pliku)
static std::mt19937 rng;

// Funkcja inicjalizująca generator losowy
void initializeRandomGenerator() {
    // Inicjalizacja generatora przy użyciu aktualnego czasu jako ziarna
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng.seed(seed);
}

std::size_t getRandomInt(std::size_t max) {
   // wyolsuj z rozkladu jednorodnego liczbe w zakresie [0, max-1] i zwroc 


}

bool getRandomBool() {
    // tutaj zrob losowanie 0 lub 1 i zwracanie true dla 1, false dla 0


}
