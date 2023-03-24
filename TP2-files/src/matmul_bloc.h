//
// Created by o2183251@campus.univ-orleans.fr on 24/03/23.
//

#ifndef SSE_TP1_MATMUL_BLOC_H
#define SSE_TP1_MATMUL_BLOC_H

#include <string.h>
#include <stdio.h>

static inline void mul_bloc(float* blocA, float* blocB, float* blocC, size_t bloc_size, size_t width){
    for(size_t i=0; i<bloc_size; i++){
        for(size_t j=0; j<bloc_size; j++){
            float sum = 0.0f;
            for(size_t k=0; k<bloc_size; k++){
                sum += blocA[i*bloc_size + k] * blocB[k*bloc_size + j];
            }
            blocC[j*bloc_size+i] += sum;
        }
    }

}

void matmul_bloc(float* A, float* B, float* C, size_t width, size_t height) {

    size_t bloc_size = 4;


    for (size_t i = 0; i < height; i += 4) {
        for(size_t h=0; h<width; h+=4) {
            float C_cell[bloc_size * bloc_size];
            for (size_t j = 0; j < bloc_size * bloc_size; j++) {
                C_cell[j] = 0;
            }
            for (size_t j = 0; j < width; j += 4) {
                float A_cell[bloc_size][bloc_size];
                float B_cell[bloc_size][bloc_size];
                for (size_t k = 0; k < bloc_size; k++) {
                    memcpy(B_cell[k], &B[(j + k) * width + i + h], bloc_size * sizeof(float));
                    memcpy(A_cell[k], &A[(i + k) * width + j], bloc_size * sizeof(float));
                }
                mul_bloc((float *) A_cell, (float *) B_cell, C_cell, bloc_size, width);
            }
            for (size_t j = 0; j < bloc_size * bloc_size; j++) {
                size_t ligne = j % bloc_size;
                C[(ligne + h) * width + j / bloc_size + i] = C_cell[j];
            }
        }
    }
}

#endif //SSE_TP1_MATMUL_BLOC_H
