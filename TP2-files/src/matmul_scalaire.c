#include <stdlib.h>
#include "matmul_scalaire.h"


int main() {
  size_t dim = 2048;

  float *A = malloc(dim * dim * sizeof(float));
  float *B = malloc(dim * dim * sizeof(float));
  float *C = malloc(dim * dim * sizeof(float));

  for (size_t i = 0; i < dim * dim; i++) {
    A[i] = rand() % 5;
    B[i] = rand() % 5;
  }

  // your code or function here
  matmul_scalaire(A, B, C, dim, dim);

  free(A);
  free(B);
  free(C);

  return 0;
}
