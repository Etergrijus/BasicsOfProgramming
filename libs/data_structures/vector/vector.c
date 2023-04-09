#include "vector.h"

Vector createVector(size_t n) {
    Vector v;
    v.capacity = n;
    v.size = 0;
    v.data = (int *) malloc(sizeof(int) * v.capacity);

    if (v.capacity == n)
        return v;
    else ERROR_OF_ALLOCATION
}

void reserve(Vector *v, size_t newCapacity) {
    if (newCapacity < v->capacity)
        v->size = newCapacity;

    v->capacity = newCapacity;
    v->data = (int *) realloc(v->data, sizeof(int) * v->capacity);

    if (v->data == NULL && newCapacity != 0) ERROR_OF_ALLOCATION
}

void fillPartOfVector(Vector *v, size_t sizeFillingPart) {
    size_t startPos = v->size;
    v->size += sizeFillingPart;

    if (v->size > v->capacity)
        reserve(v, v->size);

    FILE *f = fopen(filename, "r");
    assert(f != NULL);
    fsetpos(f, &pos);
    for (int i = startPos; i < v->size; i++)
        fscanf(f, "%d", &v->data[i]);
    fgetpos(f, &pos);
    fclose(f);
}

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    reserve(v, v->size);
}

void deleteVector(Vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(Vector v) {
    return v.size == 0 ? 1 : 0;
}

bool isFull(Vector v) {
    return v.size == v.capacity ? 1 : 0;
}

int getVectorValue(Vector v, size_t i) {
    return v.data[i];
}

//Так получилось, что я задался вопросом
//"а как добавить элементы?" раньше того, как
//это задание появилось в лабораторной.
//Это привело к тому, что я реализовал этот функционал самостоятельно,
//не используя некоторые правила из пособия - например про увеличение памяти вдвое
//при расширении вектора. Потом в дело вступила уже моя лень - и я так же самостоятельно
//реализовал считывание тестовых данных из файла.
//Теперь же пришло время "официального" способа добавления элементов в вектор и я очень не хочу
//сносить то, что уже сделано. Поэтому я буду отталкиваться от компромиссного решения, комбинируя
//свои функции и то, что есть в пособии.
void pushBack(Vector *v) {
    fillPartOfVector(v, 1);
}

void popBack(Vector *v) {
    if (v->size > 0)
        v->size--;
    else ERROR_OF_DELETING_OF_LAST
}

void outputVector(Vector v) {
    for (int i = 0; i < v.size; i++)
        printf("%d ", v.data[i]);
    printf("\n");
}