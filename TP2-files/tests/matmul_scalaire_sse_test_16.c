
#include <stdio.h>
#include <stdlib.h>
#include "../src/matmul_scalaire_sse.h"
#include "../src/matmul.h"

#define CHECK_MUL

void check(float *A, float *B, float *res, size_t dim) {
    float *exp = malloc(dim * dim * sizeof(float));

    naive_mul(A, B, exp, dim, dim);

    for (size_t i = 0; i < dim * dim; i++) {
        if (exp[i] != res[i]) {
            printf("Value at %lu differs: %f\n", i, exp[i] - res[i]);
            exit(1);
        }
    }
}

int main() {
    size_t dim = 128;

    float *A = _mm_malloc(dim * dim * sizeof(float),16);
    float *B = _mm_malloc(dim * dim * sizeof(float),16);
    float *C = _mm_malloc(dim * dim * sizeof(float),16);

    for (size_t i = 0; i < dim * dim; i++) {
        A[i] = rand() % 5;
        B[i] = rand() % 5;
    }

    // your code or function here
    matmul_scalaire_sse_16(A, B, C, dim, dim);

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
