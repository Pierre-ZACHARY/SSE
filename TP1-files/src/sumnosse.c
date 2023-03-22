


#include <malloc.h>
#include "lib.h"

float sum_classique(float *pDouble, int size) {

    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += pDouble[i];
    }
    return sum;
}


int main(void){ //         9,054662424 seconds time elapsed
    // Static arrays are stored into the stack thus we need to add an alignment attribute to tell the compiler to correctly align both arrays.
    int size = 1024*1024*512;
    float *array0 = malloc(size * sizeof(float));
    init_tab(array0, size);

    float sum = sum_classique(array0, size);
    if(sum != 0){
        return 0;
    }
    free(array0);
    return 1;
}
