

#include "../src/lib.h"
#include "../src/scalairelib.h"


int main(void) {

    int size = 1024;
    double *array0 = malloc(size * sizeof(double));
    double *array1 = malloc(size * sizeof(double));
    init_tab_double(array0, size);
    init_tab_double(array1, size);
    double scalar = standard_scalar_product(array0, array1, size);
    double scalarsse = sse_scalar_product(array0, array1, size);
    if(scalar != scalarsse){
        return 1;
    }
    printf("last double : %f / %f\n", array0[size-1], array1[size-1]);
    printf("scalar : %f / %f\n", scalar, scalarsse);
    free(array0);
    free(array1);
    return 0;
}
