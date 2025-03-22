#ifndef SENTENCE_GENERATOR_H
#define SENTENCE_GENERATOR_H

#include <string>
#include <vector>

// Funkcja generująca losowe zdanie
std::string generateRandomSentence(
    const std::vector<std::string>& adjectives,
    const std::vector<std::string>& nouns,
    const std::vector<std::string>& verbs,
    const std::vector<std::string>& adverbs,
    const std::vector<std::string>& placeAdverbs,
    const std::vector<std::string>& timeAdverbs
);

#endif // SENTENCE_GENERATOR_H
