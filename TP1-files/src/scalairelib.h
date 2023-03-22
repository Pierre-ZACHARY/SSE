#include <immintrin.h>


double sse_scalar_product(double* array0, double* array1, int size){
    __m128d summm = _mm_setzero_pd();
    double scalar = 0;
    for (int i = 0; i < (size-size%2); i+=2) {
        // mm reduce sum
        summm= _mm_add_pd(summm, _mm_mul_pd(_mm_load_pd(&array0[i]), _mm_load_pd(&array1[i])));
    }
    double sum_array[2];
    _mm_store_pd(sum_array, summm);
    for (int i = 0; i < 2; ++i) {
        scalar += sum_array[i];
    }
    for (int i = size - size%2; i < size; i++) {
        scalar += array0[i] * array1[i];
    }
    return scalar;
}

double standard_scalar_product(double *array0, double *array1, int size) {
    double scalar = 0;
    for (int i = 0; i < size; ++i) {
        scalar += array0[i] * array1[i];
    }
    return scalar;
}