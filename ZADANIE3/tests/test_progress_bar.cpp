#include <gtest/gtest.h>
#include "progress_bar.h"
#include <string>

// Test paska postępu przy 0%
TEST(ProgressBarTest, ZeroProgress) {
    std::string result = createProgressBar(0.0);
    // Pasek postępu powinien zawierać tylko znaki '-' i "0%"
    EXPECT_EQ(result.find('='), std::string::npos);
    EXPECT_NE(result.find('-'), std::string::npos);
    EXPECT_NE(result.find("0%"), std::string::npos);
}

// Test paska postępu przy 50%
TEST(ProgressBarTest, HalfProgress) {
    std::string result = createProgressBar(0.5);
    // Pasek postępu powinien zawierać zarówno znaki '=' jak i '-' oraz "50%"
    EXPECT_NE(result.find('='), std::string::npos);
    EXPECT_NE(result.find('-'), std::string::npos);
    EXPECT_NE(result.find("50%"), std::string::npos);
}

// Test paska postępu przy 100%
TEST(ProgressBarTest, FullProgress) {
    std::string result = createProgressBar(1.0);
    // Pasek postępu powinien zawierać tylko znaki '=' i "100%"
    EXPECT_NE(result.find('='), std::string::npos);
    EXPECT_EQ(result.find('-'), std::string::npos);
    EXPECT_NE(result.find("100%"), std::string::npos);
}

// Test paska postępu z niestandardową szerokością
TEST(ProgressBarTest, CustomWidth) {
    int customWidth = 20;
    std::string result = createProgressBar(0.5, customWidth);
    // Liczba znaków '=' i '-' powinna odpowiadać niestandardowej szerokości
    int equalCount = 0;
    int dashCount = 0;
    for (char c : result) {
        if (c == '=') equalCount++;
        if (c == '-') dashCount++;
    }
    EXPECT_EQ(equalCount + dashCount, customWidth);
}

// Test poprawności pozycji znaku '='
TEST(ProgressBarTest, CorrectProgress) {
    int width = 100;
    float progress = 0.75;
    std::string result = createProgressBar(progress, width);
    
    // Liczba znaków '=' powinna być równa progress * width
    int equalCount = 0;
    for (char c : result) {
        if (c == '=') equalCount++;
    }
    EXPECT_EQ(equalCount, int(progress * width));
}