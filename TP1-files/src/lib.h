

#include <malloc.h>
#include <stdlib.h>

void init_tab(float* tab, int size){
    for(int i = 0; i < size; i++) {
        // random float 0-1000
        tab[i] = (double) (rand() % 1000);
    }
}

void init_tab_double(double* tab, int size){
    for(int i = 0; i < size; i++) {
        // random float 0-1000
        tab[i] = (double) (rand() % 1000);
    }
}

void init_tab_ui16(unsigned short* tab, int size){
    for(int i = 0; i < size; i++) {
        // random float 0-1000
        tab[i] = (unsigned short) (rand() % 1000);
    }
}