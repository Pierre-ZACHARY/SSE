


#include <stdlib.h>

void init_str(char* str, int size){
    for(int i = 0; i < size; i++){
        // generate random char minuscule or majuscule
        str[i] = (char) (rand() % 58 + 65);
    }
}

char* majuscule(char* str, int size){
    char* str2 = malloc(size * sizeof(char));
    for(int i = 0; i < size; i++){
        char c = str[i];
        char mask0 = ( c < 'a' || c > 'z' ) - 1;
        char mask1 = 32 & mask0;
        str2[i] = c - mask1;
    }
    return str2;
}