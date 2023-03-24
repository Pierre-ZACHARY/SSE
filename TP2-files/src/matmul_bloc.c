//
// Created by o2183251@campus.univ-orleans.fr on 24/03/23.
//
#include <stdlib.h>
#include "matmul_bloc.h"


int main(void){ //real    0m28,869s
    size_t dim = 2048;

    float *A = malloc(dim * dim * sizeof(float));
    float *B = malloc(dim * dim * sizeof(float));
    float *C = malloc(dim * dim * sizeof(float));

    for (size_t i = 0; i < dim * dim; i++) {
        A[i] = rand() % 5;
        B[i] = rand() % 5;
    }

    // your code or function here
    matmul_bloc(A, B, C, dim, dim);

    free(A);
    free(B);
    free(C);
}