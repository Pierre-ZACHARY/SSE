//
// Created by o2183251@campus.univ-orleans.fr on 24/03/23.
//

#ifndef SSE_TP1_MATMUL_BLOC_H
#define SSE_TP1_MATMUL_BLOC_H

#include <string.h>
#include <stdio.h>

static inline void mul_bloc(float* blocA, float* blocB, float* blocC, size_t bloc_size){
    for(size_t i=0; i<bloc_size; i++){
        for(size_t j=0; j<bloc_size; j++){
            float sum = 0.0f;
            for(size_t k=0; k<bloc_size; k++){
                sum += blocA[i*bloc_size + k] * blocB[k*bloc_size + j];
            }
            blocC[i*bloc_size+j] += sum;
        }
    }

}


void matmul_bloc(float* A, float* B, float* C, size_t width, size_t height) {

    size_t bloc_size = 4;

    for (size_t i = 0; i < height; i += 4) {
        for(size_t h=0; h<width; h+=4) {
            float C_cell[16] = {0.0f};
            for (size_t j = 0; j < width; j += 4) {
                float A_cell[4][4];
                float B_cell[4][4];
                for (size_t k = 0; k < bloc_size; k++) {
                    memcpy(B_cell[k], &B[(j + k) * width + h], bloc_size * sizeof(float));
                    memcpy(A_cell[k], &A[(i + k) * width + j], bloc_size * sizeof(float));
                }
                mul_bloc((float *) A_cell, (float *) B_cell, C_cell, bloc_size);
            }
            for (size_t j = 0; j < bloc_size * bloc_size; j++) {
                size_t colonne_local = j % bloc_size;
                size_t ligne_local = j / bloc_size;
                C[(ligne_local + i) * width + colonne_local + h] = C_cell[j];
            }
        }
    }
}

#endif //SSE_TP1_MATMUL_BLOC_H
