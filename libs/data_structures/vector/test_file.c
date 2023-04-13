#include "../vector/vector.h"

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
    func_name;
    Vector v = createVector(0);
    for (int i = 0; i < 10; i++)
        pushBack(&v);
    outputVector(v);
    separator;
}

void test_pushBack_fullVector() {
    func_name;
    Vector v = createVector(10);
    fillPartOfVector(&v, 10);

    for (int i = 0; i < 4; i++)
        pushBack(&v);
    outputVector(v);
    separator;
}

void test_popBack_notEmptyVector() {
    func_name;
    Vector v = createVector(0);
    pushBack(&v);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    printf("Tests are ok\n");

    deleteVector(&v);
    v = createVector(7);
    fillPartOfVector(&v, 9);
    for (int i = 0; i < 3; i++)
        popBack(&v);
    outputVector(v);
    separator;
}

void test_popBack_emptyVector() {
    func_name;
    Vector v = createVector(2);
    fillPartOfVector(&v, 2);
    for (int i = 0; i < 3; i++)
        popBack(&v);
    separator;
}

void test_atVector_notEmptyVector() {
    func_name;
    Vector v = createVector(7);
    fillPartOfVector(&v, 7);

    int index = 4;
    PTR_TESTS
    separator;
}

void test_atVector_requestToLastElement() {
    func_name;
    Vector v = createVector(5);
    fillPartOfVector(&v, 5);

    int index = (int) v.size - 1;

    PTR_TESTS
    separator;
}

void test_back_oneElementInVector() {
    func_name;
    Vector v = createVector(1);
    fillPartOfVector(&v, 1);

    int index = 0;
    PTR_TESTS
    separator;
}

void test_front_oneElementInVector() {
    func_name;
    Vector v = createVector(1);
    fillPartOfVector(&v, 1);

    int index = 0;
    PTR_TESTS
    separator;
}

void tests() {
    Vector v0 = createVector(SIZE_MAX);
    printf("first_test: %zu\n\n", v0.capacity);
    deleteVector(&v0);

    //Код имеет проблему, связанную с отображением
    //текста в консоли. Насколько я понял, это
    //происходит из-за того, что поток stdout является
    //буферизированным, а stderr лишь частично буферизированным,
    //что время от времени приводит к тому, что отображение текста с ошибкой
    //выводится в совершенно неподходящем для этого месте.
    //Как бы я не пытался это решить, у меня ничего не вышло, увы
    test_of_basic_functional_1();
    test_of_basic_functional_2();
    test_of_basic_functional_3();
    test_of_basic_functional_4();
    test_of_basic_functional_5();

    test_pushBack_emptyVector();
    test_pushBack_fullVector();

    test_popBack_notEmptyVector();

    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();

    test_popBack_emptyVector();
}
