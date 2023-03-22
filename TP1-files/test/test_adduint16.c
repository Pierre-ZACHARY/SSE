

#include <immintrin.h>

#include "../src/lib.h"
#include "../src/uint16lib.h"

int main(void){ // 1,881067799 seconds time elapsed

    int size = 32;
    unsigned short *array0 = _mm_malloc(size * sizeof(unsigned short), 16);
    unsigned short *array1 = _mm_malloc(size * sizeof(unsigned short), 16);
    // init array0 and array1 to 0 to 7
    for (int i = 0; i < size; ++i) {
        array0[i] = i;
        array1[i] = i;
    }
    unsigned short * sum = sum_uint16(array0, array1, size);
    unsigned short * sum2 = sum_uint16_sse(array0, array1, size);
    free(array0);
    free(array1);
    // assert sum == sum2
    for(int i = 0; i < size; i++) {
        if (sum[i] != sum2[i]) {
            printf("sum[%d] = %d != sum2[%d] = %d\n", i, sum[i], i, sum2[i]);
            return 1;
        }
    }
    free(sum);
    free(sum2);
    return 0;
}