#include <stdio.h>
#include <stdint.h>

#include "libs/data_structures/vector/vector.h"

int main() {
    Vector v = createVector(0);
    printf("%zu", v.capacity);

    return 0;
}
