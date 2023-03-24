

void naive_mul(float *A, float *B, float *res, size_t width, size_t height) {
    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < height; j++) {
            float sum = 0;
            for (size_t k = 0; k < width; k++) {
                sum += A[i * width + k] * B[k * width + j];
            }
            res[i * width + j] = sum;
        }
    }
}