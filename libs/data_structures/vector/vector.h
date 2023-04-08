#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdlib.h>
#include <stdio.h>

#define ERROR {fprintf(stderr, "bad alloc"); \
exit(1); \
};

typedef struct Vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector createVector (size_t n);

void reserve(Vector *v, size_t newCapacity);

void fillPartOfVector(Vector *v, size_t sizeFillingPart);

void outputVector(Vector v);

#endif //VECTOR_VECTOR_H
