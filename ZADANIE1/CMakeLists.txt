cmake_minimum_required(VERSION 3.16)
project(PiCalculationProject VERSION 1.0 LANGUAGES CXX)

# Ustawienie standardu C++ na C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ustawienie domyślnego katalogu instalacji na katalog 'bin' w katalogu głównym projektu
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/bin" CACHE PATH "Installation Directory" FORCE)

# Włączenie wsparcia dla testów (CTest)
enable_testing()

# Dodanie katalogu głównego jako miejsca na pliki nagłówkowe
include_directories(${PROJECT_SOURCE_DIR})

# Znalezienie biblioteki obsługującej wątki (potrzebne dla std::thread)
find_package(Threads REQUIRED)

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

# Budujemy bibliotekę zawierającą implementację funkcji partial_sum
add_library(pi_calculation_lib pi_calculation.cpp)

# Budujemy aplikację główną (pi_app) z pliku main.cpp
add_executable(pi_app main.cpp)
target_link_libraries(pi_app PRIVATE pi_calculation_lib ${CMAKE_THREAD_LIBS_INIT})

# Budujemy program testowy (test_partial_sum) z pliku tests/test_partial_sum.cpp
add_executable(test_partial_sum tests/test_partial_sum.cpp)
target_link_libraries(test_partial_sum PRIVATE pi_calculation_lib gtest gtest_main)

# Rejestrujemy test w CTest – uruchamia on program testowy
include(GoogleTest)
gtest_discover_tests(test_partial_sum)

# Reguła instalacji: instalujemy aplikację główną do katalogu instalacyjnym
install(TARGETS pi_app
        RUNTIME DESTINATION .)