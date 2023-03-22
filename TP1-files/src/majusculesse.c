#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "majusculeLib.h"
#include <immintrin.h>


int main(void){ // 1,982467687 seconds time elapsed

    srand(time(NULL));
    int size = 1024*1024*128;
    char* str = _mm_malloc(size * sizeof(char), 16);
    init_str(str, size);
    char* res = majuscule_sse(str, size);
    if(res[0] == 'A'){
        return 0;
    }
}