#include "sentence_generator.h"
#include "random_generators.h"
#include <cctype>  // dla toupper

// Funkcja dostosowująca przymiotnik do rzeczownika
std::string adjustAdjective(const std::string& adjective, const std::string& noun) {
    if (adjective.empty() || noun.empty()) return adjective;
    
    // Sprawdzamy ostatnią literę rzeczownika
    char lastNounChar = noun[noun.size() - 1];
    std::string result = adjective;
    
    // Jeśli przymiotnik ma przynajmniej 1 znak
    if (result.size() > 0) {
        // Jeśli rzeczownik kończy się na 'a', przymiotnik powinien też kończyć się na 'a'
        if (lastNounChar == 'a') {
            // Jeśli przymiotnik kończy się na 'y' lub 'i', zamieniamy je na 'a'
            char lastAdjChar = result[result.size() - 1];
            if (lastAdjChar == 'y' || lastAdjChar == 'i') {
                result[result.size() - 1] = 'a';
            }
        }
        // Inne przypadki (rzeczownik kończy się na spółgłoskę) - przymiotnik kończy się na 'y'
        else if (lastNounChar != 'a' && lastNounChar != 'o' && lastNounChar != 'e') {
            // Jeśli przymiotnik kończy się na 'a', zamieniamy na 'y'
            char lastAdjChar = result[result.size() - 1];
            if (lastAdjChar == 'a') {
                result[result.size() - 1] = 'y';
            }
        }
    }
    
    return result;
}

std::string generateRandomSentence(
    const std::vector<std::string>& adjectives,
    const std::vector<std::string>& nouns,
    const std::vector<std::string>& verbs,
    const std::vector<std::string>& adverbs,
    const std::vector<std::string>& placeAdverbs,
    const std::vector<std::string>& timeAdverbs
) {
    std::string sentence;
    
    // Najpierw wylosuj rzeczownik, by móc dostosować do niego przymiotnik
    std::string noun = nouns[getRandomInt(nouns.size())];
    std::string verb = verbs[getRandomInt(verbs.size())];
    
    // Losowanie czy dodać określenie podmiotu (element 1)
    if (getRandomBool() && !adjectives.empty()) {
        // Wybierz losowy przymiotnik
        std::string adjective = adjectives[getRandomInt(adjectives.size())];
        
        // Dostosuj przymiotnik do rzeczownika
        adjective = adjustAdjective(adjective, noun);
        
        sentence += adjective + " ";
    }
    
    // Dodanie podmiotu (element 2, obowiązkowy)
    sentence += noun + " ";
    
    // Dodanie orzeczenia (element 3, obowiązkowy)
    sentence += verb;
    
    // Losowanie czy dodać okolicznik sposobu (element 4)
    if (getRandomBool() && !adverbs.empty()) {
        sentence += " " + adverbs[getRandomInt(adverbs.size())];
    }
    
    // Losowanie czy dodać okolicznik miejsca (element 5)
    if (getRandomBool() && !placeAdverbs.empty()) {
        sentence += " " + placeAdverbs[getRandomInt(placeAdverbs.size())];
    }
    
    // Losowanie czy dodać okolicznik czasu (element 6)
    if (getRandomBool() && !timeAdverbs.empty()) {
        sentence += " " + timeAdverbs[getRandomInt(timeAdverbs.size())];
    }
    
    // Dodanie kropki na końcu zdania
    sentence += ".";
    
    // Pierwsza litera zdania powinna być wielka
    if (!sentence.empty()) {
        sentence[0] = toupper(sentence[0]);
    }
    
    return sentence;
}