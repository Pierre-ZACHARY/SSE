

#include <malloc.h>
#include "lib.h"
#include "scalairelib.h"


int main(void){ //        4,167046057 seconds time elapsed

    int size = 1024*1024*128;
    double* array0 = malloc(size * sizeof(double));
    double* array1 = malloc(size * sizeof(double));
    init_tab_double(array0, size);
    init_tab_double(array1, size);

    double scalar = sse_scalar_product(array0, array1, size);
    free(array0);
    free(array1);

    if(scalar != 0){
        return 0;
    }
    return 1;
}