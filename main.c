#include <stdint.h>

#include "libs/data_structures/vector/vector.h"

void test_of_basic_functional_1() {
    printf("first_test_of_basic_functional:\n");
    Vector v = createVector(7);
    reserve(&v, 0);
    fillPartOfVector(&v, 10);
    printf("checkOfFullness - %d\n", isFull(v));
    outputVector(v);

    clear(&v);
    printf("checkOfEmptiness - %d\n", isEmpty(v));
    shrinkToFit(&v);
    printf("anotherCheckOfFullness - %d\n", isFull(v));
    outputVector(v);
    printf("Capacity of v - %zu\n", v.capacity);
    separator;
}

void test_of_basic_functional_2() {
    printf("second_test_of_basic_functional:\n");
    Vector v = createVector(0);
    fillPartOfVector(&v, 6);

    reserve(&v, 10);
    fillPartOfVector(&v, 2);
    shrinkToFit(&v);
    printf("checkOfEmptiness - %d\n", isEmpty(v));
    printf("checkOfFullness - %d\n", isFull(v));
    outputVector(v);
    printf("Capacity of v - %zu\n", v.capacity);
    separator;
}

void test_of_basic_functional_3() {
    printf("third_test_of_basic_functional:\n");
    Vector v = createVector(3);
    fillPartOfVector(&v, 1);
    fillPartOfVector(&v, 3);
    printf("checkOfFullness - %d\n", isFull(v));
    fillPartOfVector(&v, 2);
    fillPartOfVector(&v, 6);
    outputVector(v);

    clear(&v);
    fillPartOfVector(&v, 4);
    outputVector(v);
    separator;
}

void test_of_basic_functional_4() {
    printf("fourth_test_of_basic_functional:\n");
    Vector v = createVector(7);
    fillPartOfVector(&v, 6);
    reserve(&v, 2);
    outputVector(v);

    deleteVector(&v);
    printf("checkOfEmptiness - %d\n", isEmpty(v));
    outputVector(v);
    separator;
}

void test_of_basic_functional_5() {
    printf("fifth_test_of_basic_functional:\n");
    Vector v = createVector(3);
    fillPartOfVector(&v, 2);
    reserve(&v, 12);
    fillPartOfVector(&v, 9);

    int i = 4;
    printf("%d-th element of vector - %d\n", i, getVectorValue(v, i));
    i = 12;
    printf("%d-th element of vector - %d\n", i, getVectorValue(v, i));

    deleteVector(&v);
    v = createVector(2);
    fillPartOfVector(&v, 2);
    outputVector(v);
    separator;
}

void test_pushBack_emptyVector() {
    Vector v = createVector(0);
    for (int i = 0; i < 10; i++)
        pushBack(&v);
    outputVector(v);
    separator;
}

void test_pushBack_fullVector() {
    Vector v = createVector(10);
    fillPartOfVector(&v, 10);

    for (int i = 0; i < 4; i++)
        pushBack(&v);
    outputVector(v);
}

void tests() {
    Vector v0 = createVector(SIZE_MAX);
    printf("first_test: %zu\n\n", v0.capacity);

    test_of_basic_functional_1();
    test_of_basic_functional_2();
    test_of_basic_functional_3();
    test_of_basic_functional_4();
    test_of_basic_functional_5();

    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

int main() {
    tests();

    return 0;
}
