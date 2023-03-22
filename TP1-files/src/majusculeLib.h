


#include <stdlib.h>
#include <immintrin.h>

void init_str(char* str, int size){
    for(int i = 0; i < size; i++){
        // generate random char minuscule or majuscule
        str[i] = (char) (rand() % 58 + 65);
    }
}

char* majuscule(char* str, int size){
    char* str2 = malloc(size * sizeof(char));
    for(int i = 0; i < size; i++){
        char c = str[i];
        char mask0 = ( c < 'a' || c > 'z' ) - 1;
        char mask1 = 32 & mask0;
        str2[i] = c - mask1;
    }
    return str2;
}

char* majuscule_sse(char* str, int size){
    char* str2 = _mm_malloc(size * sizeof(char),16);
    __m128i mask1_32 = _mm_set1_epi8(32);
    __m128i z = _mm_set1_epi8( 'z');
    __m128i a = _mm_set1_epi8( 'a');
    for(int i = 0; i < (size-size%16); i+=16){
        __m128i c = _mm_set1_epi8(str[i]);
        __m128i mask0 = _mm_or_si128(_mm_cmpgt_epi8(c, z), _mm_cmplt_epi8(c, a));
        mask0 = _mm_sub_epi8(mask0, _mm_set1_epi8(1));
        __m128i mask1 = _mm_andnot_si128(mask1_32, mask0);
        __m128i res = _mm_andnot_si128(c, mask1);
        _mm_store_si128((__m128i *) &str2[i], res);
    }
    for(int i = size - size%16; i < size; i++){
        char c = str[i];
        char mask0 = ( c < 'a' || c > 'z' ) - 1;
        char mask1 = 32 & mask0;
        str2[i] = c - mask1;
    }
    return str2;
}