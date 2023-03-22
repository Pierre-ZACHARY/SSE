

#include <malloc.h>
#include <immintrin.h>
#include "lib.h"
float max_simd(const float* tab, size_t size) {
    __m128 maxmm = _mm_setzero_ps();
    for (int i = 0; i < (size-size%4); i+=4) {
        maxmm = _mm_max_ps(maxmm, _mm_load_ps(&tab[i]));
    }
    float max_array[4];
    _mm_store_ps(max_array, maxmm);
    float max = max_array[0];
    for (int i = 1; i < 4; ++i) {
        if (max_array[i] > max) {
            max = max_array[i];
        }
    }
    for (int i = size - size%4; i < size; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}

int main(void) { // 15,464707939 seconds time elapsed

    // Static arrays are stored into the stack thus we need to add an alignment attribute to tell the compiler to correctly align both arrays.
    int size = 1024*1024*512;
    float *array0 = malloc(size * sizeof(float));
    float *array1 = malloc(size * sizeof(float));
    init_tab(array0, size);
    init_tab(array1, size);

    float max = max_simd(array0, size);
    float max2 = max_simd(array1, size);
    if(max != max2){
        return 0;
    }
    _mm_free(array0);
    _mm_free(array1);
    return 1;

}