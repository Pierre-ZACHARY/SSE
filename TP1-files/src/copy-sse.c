/**
 * Copy values from an array to another.
 */
#include <stdio.h>
#include <immintrin.h>
#include "lib.h"

int main(void) {
    // Static arrays are stored into the stack thus we need to add an alignment attribute to tell the compiler to correctly align both arrays.
//  float array0[ 4 ] __attribute__((aligned(16))) = { 0.0f, 1.0f, 2.0f, 3.0f };
//  float array1[ 4 ] __attribute__((aligned(16)));

    int size = 1024*1024*512;

    float *array0 = (float *) _mm_malloc(size * sizeof(float), 16);
    float *array1 = (float *) _mm_malloc(size * sizeof(float), 16);
    init_tab(array0, size);


    // Load 4 values from the first array into a SSE register.
    for(int i = 0; i < (size - size%4); i += 4) {

        __m128 reg = _mm_load_ps(&array0[i]);
        // Store the values from the SSE register into the second array.
        _mm_store_ps(&array1[i], reg);
    }

    for(int i = size - size%4; i < size; i++) {
        array1[i] = array0[i];
    }


    // make sure the two arrays are the same
    for(int i = 0; i < size; i++) {
        if(array0[i] != array1[i]) {
            printf("Error: array0[%d] = %f, array1[%d] = %f", i, array0[i], i, array1[i]);
            return 1;
        }
    }
    _mm_free(array0);
    _mm_free(array1);
    return 0;
}
