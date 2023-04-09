#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define ERROR {fprintf(stderr, "bad alloc"); \
exit(1); \
};

#define filename "inf.txt"

#define separator printf("---------------\n")

typedef struct Vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

static fpos_t pos;

Vector createVector(size_t n);

void reserve(Vector *v, size_t newCapacity);

void fillPartOfVector(Vector *v, size_t sizeFillingPart);

void clear(Vector *v);

void shrinkToFit(Vector *v);

void deleteVector(Vector *v);

bool isEmpty(Vector v);

bool isFull(Vector v);

int getVectorValue(Vector v, size_t i);

void pushBack(Vector *v);

void outputVector(Vector v);

#endif //VECTOR_VECTOR_H