

#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "majusculeLib.h"

int main(void){
    srand(time(NULL));
    int size = 8;
    char* str = malloc(size * sizeof(char));
    init_str(str, size);
    printf("str : %s\n", str);
    char* res = majuscule(str, size);
    printf("res : %s\n", res);
}