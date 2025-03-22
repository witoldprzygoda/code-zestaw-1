#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../file_operations.h"
#include "../random_generators.h"

// Funkcja pomocnicza do tworzenia tymczasowego pliku testowego
bool createTestFile(const std::string& filename, const std::vector<std::string>& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie można utworzyć pliku testowego: " << filename << std::endl;
        return false;
    }
    
    for (const auto& line : content) {
        file << line << std::endl;
    }
    
    file.close();
    return true;
}

int main() {
    // Test 1: Wczytywanie z plików
    const std::string testFile = "test_file.txt";
    const std::vector<std::string> testContent = {
        "linia1",
        "linia2",
        "linia3",
        "linia4",
        "linia5"
    };
    
    // Utwórz plik testowy
    if (!createTestFile(testFile, testContent)) {
        return 1;
    }
    
    // Wczytaj plik
    std::vector<std::string> loadedContent;
    loadFromFile(testFile, loadedContent);
    
    // Sprawdź czy zawartość się zgadza
    if (loadedContent.size() != testContent.size()) {
        std::cerr << "Błąd wczytywania: Nieprawidłowa liczba linii. Oczekiwano: " 
                  << testContent.size() << ", otrzymano: " << loadedContent.size() << std::endl;
        std::remove(testFile.c_str());
        return 1;
    }
    
    for (size_t i = 0; i < testContent.size(); ++i) {
        if (loadedContent[i] != testContent[i]) {
            std::cerr << "Błąd wczytywania: Nieprawidłowa zawartość linii " << i 
                      << ". Oczekiwano: '" << testContent[i] 
                      << "', otrzymano: '" << loadedContent[i] << "'" << std::endl;
            std::remove(testFile.c_str());
            return 1;
        }
    }
    
    // Usuń plik testowy
    std::remove(testFile.c_str());
    std::cout << "Test wczytywania plików: OK" << std::endl;
    
    // Test 2: Generator liczb losowych
    initializeRandomGenerator();
    
    // Test dla getRandomInt
    const std::size_t maxVal = 10;
    const int iterations = 1000;
    std::vector<int> counts(maxVal, 0);
    
    for (int i = 0; i < iterations; ++i) {
        std::size_t value = getRandomInt(maxVal);
        if (value >= maxVal) {
            std::cerr << "Błąd: getRandomInt(" << maxVal << ") zwrócił wartość poza zakresem: " 
                     << value << std::endl;
            return 1;
        }
        counts[value]++;
    }
    
    // Sprawdź czy każda liczba wystąpiła przynajmniej raz
    for (std::size_t i = 0; i < maxVal; ++i) {
        if (counts[i] == 0) {
            std::cerr << "Błąd: Liczba " << i 
                     << " nie wystąpiła ani razu w " << iterations << " próbach" << std::endl;
            return 1;
        }
    }
    
    // Test dla getRandomBool
    int trueCount = 0;
    
    for (int i = 0; i < iterations; ++i) {
        if (getRandomBool()) {
            trueCount++;
        }
    }
    
    // Sprawdź czy proporcja true/false jest rozsądna (30-70%)
    double trueRatio = static_cast<double>(trueCount) / iterations;
    if (trueRatio < 0.3 || trueRatio > 0.7) {
        std::cerr << "Błąd: Podejrzany rozkład wartości dla getRandomBool: " 
                  << (trueRatio * 100) << "% true, " 
                  << ((1 - trueRatio) * 100) << "% false" << std::endl;
        return 1;
    }
    
    std::cout << "Test generatorów losowych: OK" << std::endl;
    std::cout << "Wszystkie testy przeszły pomyślnie!" << std::endl;
    return 0;
}
