#include <iostream>
#include <vector>
#include <string>
#include "file_operations.h"
#include "random_generators.h"
#include "sentence_generator.h"

int main() {

    initializeRandomGenerator();

    // Wektory na części zdania
    std::vector<std::string> adjectives;      // określenia podmiotu
    std::vector<std::string> nouns;           // podmioty
    std::vector<std::string> verbs;           // orzeczenia
    std::vector<std::string> adverbs;         // okoliczniki sposobu
    std::vector<std::string> placeAdverbs;    // okoliczniki miejsca
    std::vector<std::string> timeAdverbs;     // okoliczniki czasu
    
    
    // Wczytanie danych z plików
    loadFromFile("txt/okreslenia.txt", adjectives);
    loadFromFile("txt/podmioty.txt", nouns);
    loadFromFile("txt/orzeczenia.txt", verbs);
    loadFromFile("txt/okoliczniki_sposobu.txt", adverbs);
    loadFromFile("txt/okoliczniki_miejsca.txt", placeAdverbs);
    loadFromFile("txt/okoliczniki_czasu.txt", timeAdverbs);
    
    
    // Generowanie 10 losowych zdań
    std::cout << "Wygenerowane losowe zdania:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << i+1 << ". " << generateRandomSentence(adjectives, nouns, verbs, adverbs, placeAdverbs, timeAdverbs) << std::endl;
    }
}
