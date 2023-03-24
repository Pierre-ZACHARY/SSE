


#include <malloc.h>
#include <time.h>
#include "../src/majusculeLib.h"

int main(void){
    srand(time(NULL));
    int size = 16;
    char* str = malloc(size * sizeof(char));
    init_str(str, size);

    char* res = majuscule(str, size);
    char* ressse = majuscule_sse(str, size);
    for(int i = 0; i < size; i++){
        if(res[i] != ressse[i]) {
            printf("error at index %d : %c / %c", i, res[i], ressse[i]);
            return 1;
        }
    }
    printf("%s / %s", res, ressse);
    return 0;
}