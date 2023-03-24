
#include <stdio.h>
#include <stdlib.h>
#include "../src/matmul.h"
#include "../src/matmul_bloc_sse.h"

#define CHECK_MUL

void check(float *A, float *B, float *res, size_t dim) {
    float *exp = malloc(dim * dim * sizeof(float));

    naive_mul(A, B, exp, dim, dim);
    printf("Matrix exp:\n");
    for (size_t i = 0; i < dim; i++) {
        for (size_t j = 0; j < dim; j++) {
            printf("%f ", exp[i * dim + j]);
        }
        printf("\n");
    }

    for (size_t i = 0; i < dim * dim; i++) {
        if (exp[i] != res[i]) {
            printf("Value at %lu differs: %f\n", i, exp[i] - res[i]);
            exit(1);
        }
    }
}

int main() {
    size_t dim = 8;

    float *A = _mm_malloc(dim * dim * sizeof(float),16);
    float *B = _mm_malloc(dim * dim * sizeof(float),16);
    float *C = _mm_malloc(dim * dim * sizeof(float),16);

    for (size_t i = 0; i < dim * dim; i++) {
        A[i] = rand() % 5;
        B[i] = rand() % 5;
    }

    // your code or function here
    matmul_bloc_sse(A, B, C, dim, dim);

    // print matrix
    printf("Matrix C:\n");
    for (size_t i = 0; i < dim; i++) {
        for (size_t j = 0; j < dim; j++) {
            printf("%f ", C[i * dim + j]);
        }
        printf("\n");
    }

// you can activate check by adding -DCHECK_MUL to your command line
#ifdef CHECK_MUL
    printf("Checking result...\n");
    check(A, B, C, dim);
#endif

    free(A);
    free(B);
    free(C);

    return 0;
}
