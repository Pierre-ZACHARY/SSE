//
// Created by tpuser on 22/03/23.
//


#include <malloc.h>
#include <mm_malloc.h>
#include "lib.h"

int main(void) {
    // Static arrays are stored into the stack thus we need to add an alignment attribute to tell the compiler to correctly align both arrays.

    int size = 1024*1024*512;
    float *array0 = _mm_malloc(size * sizeof(float), 16);
    float *array1 = _mm_malloc(size * sizeof(float), 16);
    init_tab(array0, size);

    // make sure the two arrays are the same
    for(int i = 0; i < size; i++) {
        if(array0[i] != array1[i]) {
            printf("Error: array0[%d] = %f, array1[%d] = %f", i, array0[i], i, array1[i]);
            return 1;
        }
    }
    free(array0);
    free(array1);

    return 0;
}