#include <immintrin.h>

unsigned short * sum_uint16(const unsigned short * pUShort,const unsigned short * pUShort1, int size) {
    unsigned short* sum = malloc(sizeof(unsigned short)*size);
    for (int i = 0; i < size; i++) {
        sum[i] += pUShort[i] + pUShort1[i];
    }
    return sum;
}

unsigned short * sum_uint16_sse(const unsigned short * pUShort, const unsigned short * pUShort1, int size) {
    unsigned short * sum_array = _mm_malloc(sizeof(unsigned short)*size, 16);
    for (int i = 0; i < (size-size%8); i+=8) {
        __m128i sumMM = _mm_add_epi16(_mm_load_si128((__m128i*) &pUShort[i]), _mm_load_si128((__m128i*) &pUShort1[i]));
        _mm_store_si128((__m128i *) &sum_array[i], sumMM);
    }
    for (int i = size - size%8; i < size; i++) {
        sum_array[i] += pUShort[i] + pUShort1[i];
    }
    return sum_array;
}