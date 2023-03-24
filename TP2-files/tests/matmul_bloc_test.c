
#include <stdio.h>
#include <stdlib.h>
#include "../src/matmul.h"
#include "../src/matmul_bloc.h"

#define CHECK_MUL

void check(float *A, float *B, float *res, size_t dim) {
    float *exp = malloc(dim * dim * sizeof(float));

    naive_mul(A, B, exp, dim, dim);
    for(size_t i=0; i<dim; i++){
        for(size_t j=0; j<dim; j++){
            printf("%f ", exp[i*dim+j]);
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

    float *A = malloc(dim * dim * sizeof(float));
    float *B = malloc(dim * dim * sizeof(float));
    float *C = malloc(dim * dim * sizeof(float));

    for (size_t i = 0; i < dim * dim; i++) {
        A[i] = rand() % 5;
        B[i] = rand() % 5;
    }

    // your code or function here
    matmul_bloc(A, B, C, dim, dim);
    for(size_t i=0; i<dim; i++){
        for(size_t j=0; j<dim; j++){
            printf("%f ", A[i*dim+j]);
        }
        printf("\n");
    }
    for(size_t i=0; i<dim; i++){
        for(size_t j=0; j<dim; j++){
            printf("%f ", B[i*dim+j]);
        }
        printf("\n");
    }
    for(size_t i=0; i<dim; i++){
        for(size_t j=0; j<dim; j++){
            printf("%f ", C[i*dim+j]);
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
