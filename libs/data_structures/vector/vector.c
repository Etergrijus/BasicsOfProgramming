#include "vector.h"

Vector createVector (size_t n) {
    Vector v;
    v.capacity = n;
    v.data = (int*)malloc(sizeof(int) * v.capacity);

    if (v.capacity == n)
        return v;
    else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}