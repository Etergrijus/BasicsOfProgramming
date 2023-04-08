#include <stdint.h>

#include "libs/data_structures/vector/vector.h"

void tests() {
    Vector v0 = createVector(SIZE_MAX);
    printf("%zu\n", v0.capacity);

    Vector v = createVector(7);
    reserve(&v, 0);
    fillPartOfVector(&v, 10);
    clear(&v);
    shrinkToFit(&v);
    outputVector(v);
    printf("\nCapacity of v - %zu\n", v.capacity);

    Vector v1 = createVector(0);
    fillPartOfVector(&v1, 6);
    reserve(&v1, 10);
    fillPartOfVector(&v1, 2);
    shrinkToFit(&v1);
    outputVector(v1);
    printf("\nCapacity of v1 - %zu\n", v1.capacity);

    Vector v2 = createVector(3);
    fillPartOfVector(&v2, 1);
    fillPartOfVector(&v2, 3);
    fillPartOfVector(&v2, 2);
    fillPartOfVector(&v2, 6);
    clear(&v2);
    fillPartOfVector(&v2, 4);
    outputVector(v2);
    printf("\n");

    Vector v3 = createVector(7);
    fillPartOfVector(&v3, 6);
    reserve(&v3, 2);
    outputVector(v3);
    printf("\n");
    deleteVector(&v3);
    outputVector(v3);
}

int main() {
    tests();

    return 0;
}
