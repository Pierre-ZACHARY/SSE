
#include <immintrin.h>


void matmul_scalaire_sse(float* A, float* B, float* C, size_t width, size_t height) {
    for(size_t i=0; i<height; i++){
        for(size_t j=0; j<height; j++){
            float A_cell = A[i * width + j];
            __m128 a = _mm_set1_ps(A_cell);
            for(size_t k=0; k<width; k+=4) {
                __m128 b = _mm_load_ps(&B[j * width + k]);
                __m128 c = _mm_load_ps(&C[i * width + k]);
                _mm_store_ps(&C[i * width + k], _mm_add_ps(_mm_mul_ps(a, b), c));
            }
        }
    }
}

void matmul_scalaire_sse_8(float* A, float* B, float* C, size_t width, size_t height) {
    for(size_t i=0; i<height; i++){
        for(size_t j=0; j<height; j++){
            float A_cell = A[i * width + j];
            __m128 a = _mm_set1_ps(A_cell);
            for(size_t k=0; k<width; k+=8) {
                __m128 b = _mm_load_ps(&B[j * width + k]);
                __m128 b2 = _mm_load_ps(&B[j * width + k +4]);
                __m128 c = _mm_load_ps(&C[i * width + k]);
                __m128 c2 = _mm_load_ps(&C[i * width + k +4]);
                _mm_store_ps(&C[i * width + k], _mm_add_ps(_mm_mul_ps(a, b), c));
                _mm_store_ps(&C[i * width + k+4], _mm_add_ps(_mm_mul_ps(a, b2), c2));
            }
        }
    }
}

void matmul_scalaire_sse_16(float* A, float* B, float* C, size_t width, size_t height) {
    for(size_t i=0; i<height; i++){
        for(size_t j=0; j<height; j++){
            float A_cell = A[i * width + j];
            __m128 a = _mm_set1_ps(A_cell);
            for(size_t k=0; k<width; k+=16) {
                __m128 b = _mm_load_ps(&B[j * width + k]);
                __m128 b2 = _mm_load_ps(&B[j * width + k +4]);
                __m128 b3 = _mm_load_ps(&B[j * width + k +8]);
                __m128 b4 = _mm_load_ps(&B[j * width + k +12]);
                __m128 c = _mm_load_ps(&C[i * width + k]);
                __m128 c2 = _mm_load_ps(&C[i * width + k +4]);
                __m128 c3 = _mm_load_ps(&C[i * width + k +8]);
                __m128 c4 = _mm_load_ps(&C[i * width + k +12]);
                _mm_store_ps(&C[i * width + k], _mm_add_ps(_mm_mul_ps(a, b), c));
                _mm_store_ps(&C[i * width + k+4], _mm_add_ps(_mm_mul_ps(a, b2), c2));
                _mm_store_ps(&C[i * width + k+8], _mm_add_ps(_mm_mul_ps(a, b3), c3));
                _mm_store_ps(&C[i * width + k+12], _mm_add_ps(_mm_mul_ps(a, b4), c4));
            }
        }
    }
}