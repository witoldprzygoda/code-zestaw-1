cmake_minimum_required(VERSION 3.16)
project(ProgressBarProject VERSION 1.0 LANGUAGES CXX)

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

# Budujemy bibliotekę zawierającą implementację funkcji paska postępu
add_library(progress_bar_lib progress_bar.cpp)

# Budujemy aplikację główną (progress_app) z pliku main.cpp
add_executable(progress_app main.cpp)
target_link_libraries(progress_app PRIVATE 
    progress_bar_lib 
    ${CMAKE_THREAD_LIBS_INIT}
    stdc++exp  # Eksperymentalna biblioteka dla C++23
)

# Budujemy program testowy (test_progress_bar) z pliku tests/test_progress_bar.cpp
add_executable(test_progress_bar tests/test_progress_bar.cpp)
target_link_libraries(test_progress_bar PRIVATE 
    progress_bar_lib 
    gtest 
    gtest_main
    stdc++exp  # Eksperymentalna biblioteka dla C++23
)

# Rejestrujemy test w CTest – uruchamia on program testowy
include(GoogleTest)
gtest_discover_tests(test_progress_bar)

# Reguła instalacji: instalujemy aplikację główną do katalogu instalacyjnym
install(TARGETS progress_app
        RUNTIME DESTINATION .)