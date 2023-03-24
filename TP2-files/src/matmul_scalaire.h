


void matmul_scalaire(float* A, float* B, float* C, size_t width, size_t height) {
    for(size_t i=0; i<height; i++){
        for(size_t j=0; j<height; j++){
            float A_cell = A[i * width + j];
            for(size_t k=0; k<width; k++) {
                C[i * width + k] += A_cell * B[j * width + k];
            }
        }
    }
}