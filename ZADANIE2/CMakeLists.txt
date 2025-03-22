cmake_minimum_required(VERSION 3.16)
project(StringCompareProject VERSION 1.0 LANGUAGES CXX)
# Ustawienie standardu C++ na C++17 (ze względu na string_view)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Ustawienie domyślnego katalogu instalacji na katalog 'bin' w katalogu głównym projektu
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/bin" CACHE PATH "Installation Directory" FORCE)
# Włączenie wsparcia dla testów (CTest)
enable_testing()
# Dodanie katalogu głównego jako miejsca na pliki nagłówkowe
include_directories(${PROJECT_SOURCE_DIR})
# Automatyczne pobranie i skonfigurowanie najnowszej wersji Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main  # Użycie najnowszej wersji z głównej gałęzi
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# Budujemy bibliotekę zawierającą implementację funkcji compareIgnoreCase
add_library(string_compare_lib compare_strings.cpp)
# Budujemy aplikację główną z pliku main.cpp
add_executable(string_compare_app main.cpp)
target_link_libraries(string_compare_app PRIVATE string_compare_lib)
# Budujemy program testowy z pliku tests/compare_strings_test.cpp
add_executable(test_compare_strings tests/compare_strings_test.cpp)
target_link_libraries(test_compare_strings PRIVATE string_compare_lib gtest gtest_main)
# Rejestrujemy test w CTest – uruchamia on program testowy
include(GoogleTest)
gtest_discover_tests(test_compare_strings)
# Reguła instalacji: instalujemy aplikację główną do katalogu instalacyjnym
install(TARGETS string_compare_app
        RUNTIME DESTINATION .)
