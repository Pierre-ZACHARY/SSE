

#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "majusculeLib.h"

int main(void){ // 1,976723438 seconds time elapsed

    srand(time(NULL));
    int size = 1024*1024*128;
    char* str = malloc(size * sizeof(char));
    init_str(str, size);
    char* res = majuscule(str, size);
    if(res[0] == 'A'){
        return 0;
    }
    return 0;
}