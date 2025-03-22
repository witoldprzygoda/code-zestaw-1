cmake_minimum_required(VERSION 3.10)
project(FibonacciProject VERSION 1.0)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ustawienie domyślnego katalogu instalacji na katalog 'bin' w katalogu głównym projektu
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/bin" CACHE PATH "Installation Directory" FORCE)

# Dodanie biblioteki fibonacci
add_library(fibonacci_lib fibonacci.cpp)

# Kompilacja programu głównego
add_executable(fibonacci_app main.cpp)
target_link_libraries(fibonacci_app PRIVATE fibonacci_lib)

# Kompilacja programu testowego
add_executable(fibonacci_test tests/test_fibonacci.cpp)
target_link_libraries(fibonacci_test PRIVATE fibonacci_lib)

# Włączenie testowania CTest
enable_testing()
add_test(NAME FibonacciTest COMMAND fibonacci_test)

# Instalacja programu do katalogu bin
install(TARGETS fibonacci_app
        RUNTIME DESTINATION .)

# Opcjonalnie: instalacja pliku README, jeśli istnieje
install(FILES README.md DESTINATION . OPTIONAL)

# Dodajemy cel do uruchomienia testów
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS fibonacci_test
    COMMENT "Running all tests"
)
