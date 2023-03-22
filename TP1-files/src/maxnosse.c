
#include "lib.h"

float max_classique(float* tab, int size){
    float max = tab[0];
    for (int i = 1; i < size; ++i) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}


int main(void) { //             16,031866258 seconds time elapsed
    // Static arrays are stored into the stack thus we need to add an alignment attribute to tell the compiler to correctly align both arrays.

    int size = 1024*1024*512;
    float *array0 = malloc(size * sizeof(float));
    float *array1 = malloc(size * sizeof(float));
    init_tab(array0, size);
    init_tab(array1, size);

    float max = max_classique(array0, size);
    float max2 = max_classique(array1, size);
    if(max != max2){
        return 0;
    }
    free(array0);
    free(array1);
    return 1;
}