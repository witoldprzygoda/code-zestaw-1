#ifndef RANDOM_GENERATORS_H
#define RANDOM_GENERATORS_H

#include <cstddef>  // dla std::size_t

// Inicjalizacja generatora liczb losowych
void initializeRandomGenerator();

// Funkcja zwracająca losową liczbę całkowitą z zakresu [0, max-1]
std::size_t getRandomInt(std::size_t max);

// Funkcja losująca wartość binarną (true/false) z równym prawdopodobieństwem
bool getRandomBool();

#endif // RANDOM_GENERATORS_H