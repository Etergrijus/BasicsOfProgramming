#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

#define ERROR_OF_ALLOCATION {fprintf(stderr, "bad alloc"); \
exit(1); \
};

#define ERROR_OF_DELETING_OF_LAST {fprintf( stderr, "Attempt to reduce an empty vector"); \
exit(1); \
};


#define ERROR_OF_ACCESSING_BY_INDEX {fprintf(stderr, "IndexError: a[%d] is not exists", index); \
exit(1); \
};

#define PTR_TESTS {printf("%p\n", front(&v)); \
printf("%p\n", atVector(&v, index)); \
printf("%p\n", back(&v)); \
};

#define filename "inf.txt"

#define separator printf("---------------\n")

#define func_name printf("%s:\n", __func__)

typedef struct Vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

static fpos_t pos;

//Возвращает структуру-дескриптор вектора из n значений
Vector createVector(size_t n);

//Изменяет количество памяти,
//выделенное под хранение вектора v
void reserve(Vector *v, size_t newCapacity);

//Заполняет часть памяти, выделенной
//под хранение вектора v, размера sizeFillingPart
//из файла
void fillPartOfVector(Vector *v, size_t sizeFillingPart);

//Удаляет элементы из контейнера,
//но не освобождает выделенную память
void clear(Vector *v);

//Освобождает память, выделенную под
//неиспользуемые элементы
void shrinkToFit(Vector *v);

//Освобождает память, выделенную вектору v
void deleteVector(Vector *v);

//Возвращается значение "истина",
//если вектор v является пустым, и "ложь"
//в противном случае
bool isEmpty(Vector v);

//Возвращается значение "истина",
//если вектор v является полным, и "ложь"
//в противном случае
bool isFull(Vector v);

//Возвращает i-ый элемент вектора v
int getVectorValue(Vector v, size_t i);

//добавляет один элемент из файла в конец вектора v
void pushBack(Vector *v);

//Удаляет последний элемент вектора v
void popBack(Vector *v);


//– возвращает указатель на
//index-ый элемент вектора
int* atVector(Vector *v, size_t index);

//возвращает указатель на последний элемент вектора
int* back(Vector *v);

//возвращает указатель на нулевой элемент вектора
int* front(Vector *v);

//Выводит элементы вектора v
//на экран пользователя
void outputVector(Vector v);

#endif //VECTOR_VECTOR_H