#include <cstring>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

const double Pi = 3.14159265358979323;

void Circle(int string, std::string storage[]){

}

void Triangle(int string, std::string storage[]){
    
}

int main(){
    int counter = 0;
    int storage_size = 100;
    std::string storage[storage_size];
    std::string line;
    std::ifstream in("wkt.wkt");
    if (in.is_open()) {
        while (getline(in, line)) {
            storage[counter] = line;
            counter++;
        }
    } else {
        printf("Open File Error");
    }
    
    int verif_counter = 0;
    for (int counter_f = 0; counter_f < counter; counter_f++) {
        std::size_t found;
        found = storage[counter_f].find("circle");
        if (found != std::string::npos) {
            verif_counter++;
            Circle(counter_f, storage);
        }

        found = storage[counter_f].find("triangle");
        if (found != std::string::npos) {
            verif_counter++;
            Triangle(counter_f, storage);
        }

        if (verif_counter == 0) {
            printf("\nError in %d line", counter_f + 1);
        }
        verif_counter = 0;
    }
    return 0;
}
