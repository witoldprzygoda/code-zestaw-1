#include <gtest/gtest.h>
#include "../compare_strings.h"
#include <string>

// Test dla przypadków kiedy ciągi są identyczne
TEST(CompareIgnoreCaseTest, IdenticalStrings) {
    EXPECT_TRUE(compareIgnoreCase("test", "test"));
    EXPECT_TRUE(compareIgnoreCase("", ""));
    EXPECT_TRUE(compareIgnoreCase("a", "a"));
}

// Test dla przypadków kiedy ciągi różnią się tylko wielkością liter
TEST(CompareIgnoreCaseTest, DifferentCaseStrings) {
    EXPECT_TRUE(compareIgnoreCase("test", "TEST"));
    EXPECT_TRUE(compareIgnoreCase("Test", "tESt"));
    EXPECT_TRUE(compareIgnoreCase("HELLO", "hello"));
    EXPECT_TRUE(compareIgnoreCase("AbCdEf", "aBcDeF"));
}

// Test dla przypadków kiedy ciągi są różne
TEST(CompareIgnoreCaseTest, DifferentStrings) {
    EXPECT_FALSE(compareIgnoreCase("test", "test1"));
    EXPECT_FALSE(compareIgnoreCase("test", "tast"));
    EXPECT_FALSE(compareIgnoreCase("", "a"));
    EXPECT_FALSE(compareIgnoreCase("abc", "def"));
}

// Test dla przypadków ze znakami specjalnymi i liczbami
TEST(CompareIgnoreCaseTest, SpecialCharactersAndNumbers) {
    EXPECT_TRUE(compareIgnoreCase("Test123", "tEST123"));
    EXPECT_TRUE(compareIgnoreCase("!@#$%", "!@#$%"));
    EXPECT_FALSE(compareIgnoreCase("Test123", "Test124"));
    EXPECT_FALSE(compareIgnoreCase("!@#$%", "!@#$&"));
}

// Test dla przypadków ze znakami diakrytycznymi
TEST(CompareIgnoreCaseTest, DiacriticCharacters) {
    EXPECT_TRUE(compareIgnoreCase("ąęźżćńłóś", "ąęźżćńłóś"));
    EXPECT_FALSE(compareIgnoreCase("ąęźżćńłóś", "aezzcnlos"));
}

// Test dla długich ciągów znaków
TEST(CompareIgnoreCaseTest, LongStrings) {
    std::string long1(1000, 'a');
    std::string long2(1000, 'A');
    EXPECT_TRUE(compareIgnoreCase(long1, long2));
    
    long2[500] = 'b';
    EXPECT_FALSE(compareIgnoreCase(long1, long2));
}

// Test dla ciągów o różnych długościach
TEST(CompareIgnoreCaseTest, DifferentLengths) {
    EXPECT_FALSE(compareIgnoreCase("test", "teste"));
    EXPECT_FALSE(compareIgnoreCase("", "test"));
    EXPECT_FALSE(compareIgnoreCase("test", "tes"));
}

