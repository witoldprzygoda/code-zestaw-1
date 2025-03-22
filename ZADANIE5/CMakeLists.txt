cmake_minimum_required(VERSION 3.10)
project(GeneratorZdan VERSION 1.0)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ustawienie flagi dla aplikacji konsolowej
set(CMAKE_WIN32_EXECUTABLE FALSE)

# Ustawienie ścieżki instalacyjnej jako podkatalogu projektu
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/bin" CACHE PATH "Installation directory" FORCE)

# Ścieżki do katalogów
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TXT_DIR ${SOURCE_DIR}/txt)
set(BIN_DIR ${CMAKE_INSTALL_PREFIX})

# Dodanie plików źródłowych
add_executable(generator_zdan
    main.cpp
    file_operations.cpp
    random_generators.cpp
    sentence_generator.cpp
)

# Włączenie testowania
enable_testing()

# Dodanie podstawowego testu
add_executable(test_basic tests/test_basic.cpp file_operations.cpp random_generators.cpp)
add_test(NAME BasicTest COMMAND test_basic)

# Cel do uruchomienia testów
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_basic
    COMMENT "Running tests"
)

# Instalacja programu
install(TARGETS generator_zdan DESTINATION ${BIN_DIR})

# Tworzenie katalogu txt w miejscu instalacji
install(DIRECTORY DESTINATION ${BIN_DIR}/txt)

# Instalacja plików tekstowych
install(DIRECTORY ${TXT_DIR}/ DESTINATION ${BIN_DIR}/txt
        FILES_MATCHING PATTERN "*.txt")

# Informacja dla użytkownika
message(STATUS "Katalog instalacyjny: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Program zostanie zainstalowany w: ${BIN_DIR}")
message(STATUS "Pliki tekstowe zostaną zainstalowane w: ${BIN_DIR}/txt")
