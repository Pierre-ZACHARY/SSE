//
// Created by o2183251@campus.univ-orleans.fr on 24/03/23.
//

#ifndef SSE_TP2_MATMUL_BLOC_SSE_H
#define SSE_TP2_MATMUL_BLOC_SSE_H

#include <string.h>
#include <stdio.h>
#include <immintrin.h>



void matmul_bloc_sse(float* A, float* B, float* C, size_t width, size_t height) {

    // print A and B
//    printf("A :\n");
//     for (size_t i = 0; i < height; i++) {
//         for (size_t j = 0; j < width; j++) {
//             printf("%f ", A[i * width + j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
//    printf("B :\n");
//    for (size_t i = 0; i < height; i++) {
//         for (size_t j = 0; j < width; j++) {
//             printf("%f ", B[i * width + j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
    size_t bloc_size = 4;

    for (size_t i = 0; i < height; i += 4) {
        for(size_t h=0; h<width; h+=4) {
            __m128 C_cell_1 = _mm_setzero_ps();
            __m128 C_cell_2 = _mm_setzero_ps();
            __m128 C_cell_3 = _mm_setzero_ps();
            __m128 C_cell_4 = _mm_setzero_ps();
            for (size_t j = 0; j < width; j += 4) {
                __m128 B_cell_sse_1 = _mm_load_ps( &B[(j + 0) * width + h]);
                __m128 B_cell_sse_2 = _mm_load_ps( &B[(j + 1) * width + h]);
                __m128 B_cell_sse_3 = _mm_load_ps( &B[(j + 2) * width + h]);
                __m128 B_cell_sse_4 = _mm_load_ps( &B[(j + 3) * width + h]);
                _MM_TRANSPOSE4_PS(B_cell_sse_1, B_cell_sse_2, B_cell_sse_3, B_cell_sse_4);
                for(size_t k=0; k<bloc_size; k++){ // pour chaque case de C
                    __m128 blocA = _mm_load_ps( &A[(i + k) * width + j]);
                    __m128 line1 = _mm_mul_ps(blocA, B_cell_sse_1);
                    __m128 line2 = _mm_mul_ps(blocA, B_cell_sse_2);
                    __m128 line3 = _mm_mul_ps(blocA, B_cell_sse_3);
                    __m128 line4 = _mm_mul_ps(blocA, B_cell_sse_4);
                    // print all lines
//                    float line[16];
//                    _mm_store_ps(line, line1);
//                    _mm_store_ps(line+4, line2);
//                    _mm_store_ps(line+8, line3);
//                    _mm_store_ps(line+12, line4);
//                    for(int i=0; i<16; i++){
//                        printf("%f ", line[i]);
//                    }
                    _MM_TRANSPOSE4_PS(line1, line2, line3, line4);
                    __m128 sum = _mm_add_ps(line1, line2);
                    sum = _mm_add_ps(sum, line3);
                    sum = _mm_add_ps(sum, line4);
                    switch (k) {
                        case 0:
                            C_cell_1 = _mm_add_ps(C_cell_1, sum);
                            break;
                        case 1:
                            C_cell_2 = _mm_add_ps(C_cell_2, sum);
                            break;
                        case 2:
                            C_cell_3 = _mm_add_ps(C_cell_3, sum);
                            break;
                        case 3:
                            C_cell_4 = _mm_add_ps(C_cell_4, sum);
                            break;
                    }
                }
            }
            _mm_store_ps( &C[(0 + i) * width + h], C_cell_1);
            _mm_store_ps( &C[(1 + i) * width + h], C_cell_2);
            _mm_store_ps( &C[(2 + i) * width + h], C_cell_3);
            _mm_store_ps( &C[(3 + i) * width + h], C_cell_4);

        }
    }
}

#endif //SSE_TP2_MATMUL_BLOC_SSE_H
