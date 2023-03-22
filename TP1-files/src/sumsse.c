

#include <malloc.h>
#include "lib.h"
#include <immintrin.h>

float sum_sse(float *pDouble, int size) {
    __m128 summm = _mm_setzero_ps();
    float sum = 0;
    for (int i = 0; i < (size-size%4); i+=4) {
        // mm reduce sum
        summm= _mm_hadd_ps(summm, _mm_load_ps(&pDouble[i]));
    }
    float sum_array[4];
    _mm_store_ps(sum_array, summm);
    for (int i = 0; i < 4; ++i) {
        sum += sum_array[i];
    }
    for (int i = size - size%4; i < size; i++) {
        sum += pDouble[i];
    }
    return sum;
}


int main(void){ //              8,011399466 seconds time elapsed
    int size = 1024*1024*512;
    float *array0 = malloc(size * sizeof(float));
    init_tab(array0, size);
    float sum = sum_sse(array0, size);
    if(sum != 0){
        return 0;
    }

    _mm_free(array0);
    return 0;
}