#include "vector.h"

Vector createVector (size_t n) {
    Vector v;
    v.capacity = n;
    v.size = 0;
    v.data = (int*)malloc(sizeof(int) * v.capacity);

    if (v.capacity == n)
        return v;
    else ERROR
}

void reserve(Vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    v->data = (int*)realloc(v->data, sizeof(int) * v->capacity);

    if (newCapacity < v->capacity)
        v->size = newCapacity;

    if (v->data == NULL && newCapacity != 0)
        ERROR
}

void fillPartOfVector(Vector *v, size_t sizeFillingPart) {
    size_t startPos = v->size;
    v->size = sizeFillingPart;

    if (v->size > v->capacity)
        reserve(v, v->size);

    for (int i = startPos; i < v->size; i++)
        scanf("%d", &v->data[i]);
}

void outputVector(Vector v) {
    for (int i = 0; i < v.size; i++)
        printf("%d ", v.data[i]);
}