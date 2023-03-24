#include <stdlib.h>
#include "matmul_scalaire_sse.h"


int main() { //real    0m11,573s

    size_t dim = 2048;

float *A = _mm_malloc(dim * dim * sizeof(float),16);
float *B = _mm_malloc(dim * dim * sizeof(float),16);
float *C = _mm_malloc(dim * dim * sizeof(float),16);

  for (size_t i = 0; i < dim * dim; i++) {
    A[i] = rand() % 5;
    B[i] = rand() % 5;
  }

  // your code or function here
  matmul_scalaire_sse_16(A, B, C, dim, dim);

  free(A);
  free(B);
  free(C);

  return 0;
}
