


#include <mm_malloc.h>
#include "lib.h"
#include "uint16lib.h"

int main(void){ // 1,881067799 seconds time elapsed

    int size = 1024*1024*128;
    unsigned short *array0 = _mm_malloc(size * sizeof(unsigned short), 16);
    unsigned short *array1 = _mm_malloc(size * sizeof(unsigned short), 16);
    init_tab_ui16(array0, size);
    init_tab_ui16(array1, size);
    unsigned short * sum = sum_uint16(array0, array1, size);
    free(array0);
    free(array1);
    free(sum);
    return 0;
}