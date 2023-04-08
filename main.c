#include <stdio.h>
#include <stdint.h>

#include "libs/data_structures/vector/vector.h"

int main() {
    Vector v = createVector(7);
    reserve(&v, 0);
    fillPartOfVector(&v, 10);
    outputVector(v);
    printf("\n");
/*
    fillPartOfVector(&v, 16);
    outputVector(v);*/

    //printf("%zu", v.capacity);

    return 0;
}
