#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <vector>
#include <string>

// Funkcja wczytująca dane z pliku do wektora
void loadFromFile(std::string_view filename, std::vector<std::string>& target);

#endif // FILE_OPERATIONS_H
