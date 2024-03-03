#include "vector.h"

vector createVector(size_t n) {
    int *memory = malloc(sizeof(int) * n);
    if (memory == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else
        return (vector) {memory, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if (newCapacity == 0)
        v->data = NULL;
    if (v->size > newCapacity)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity && v->size != 0;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "is empty");
        exit(1);
    } else
        v->size--;
}

int *atVector(vector *v, size_t index) {
    if (index > v->capacity)
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
    else if (v->capacity == 0 || index > v->size) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return &v->data[index];
}

int *back(vector *v) {
    return atVector(v, v->size - 1);
}

int *front(vector *v) {
    return v->data;
}