#include "progress_bar.h"
#include <string>
#include <format>
#include <iostream> // dla std::flush

std::string createProgressBar(float progress, int barWidth) {
   // w tej funkcji nalezy zbudowac obiekt caly string paska postepu
   // w danym momencie zaawansowana (okreslonym przez parametr progress)
   // bardzo polecam uzyc do tego celu std::format (opisany na jednym 
   // ze slajdow "wykladowych", mozna taki obiekt zwrocic przez return
    


}

void printProgressBar(float progress, int barWidth) {
    // wywolanie createProgressBar
    
    // uwaga! nalezy teraz wydrukowac ten pasek poprzedzajac go \r


    // Oproznienie bufora przy uzyciu std::flush
    std::cout << std::flush;
}
