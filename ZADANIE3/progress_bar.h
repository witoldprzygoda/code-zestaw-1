#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <string>

// Funkcja tworząca ciąg znaków reprezentujący pasek postępu
std::string createProgressBar(float progress, int barWidth = 50);

// Funkcja wyświetlająca pasek postępu
void printProgressBar(float progress, int barWidth = 50);

#endif // PROGRESS_BAR_H