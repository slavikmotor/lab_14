#include "libs/data_structures/vector/vector.h"
void test_createVector1() {
    vector v = createVector(3);
    assert(v.size == 0);
    assert(v.capacity == 3);
    deleteVector(&v);
}
void test_createVector2() {
    vector v = createVector(0);
    assert(v.size == 0);
    assert(v.capacity == 0);
    deleteVector(&v);
}
void test_createVector() {
    test_createVector1();
    test_createVector2();
}
void test_reserve1() {
    vector v = createVector(7);
    v.size = 5;
    reserve(&v, 6);
    assert(v.size == 5);
    assert(v.capacity == 6);
    deleteVector(&v);
}
void test_reserve2() {
    vector v = createVector(7);
    v.size = 5;
    reserve(&v, 4);
    assert(v.size == 4);
    assert(v.capacity == 4);
    deleteVector(&v);
}
void test_reserve() {
    test_reserve1();
    test_reserve2();
}
void test_shrinkToFit1() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    shrinkToFit(&v);
    assert(v.size == v.capacity);
    deleteVector(&v);
}
void test_shrinkToFit2() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    shrinkToFit(&v);
    assert(v.size == v.capacity);
    deleteVector(&v);
}
void test_shrinkToFit() {
    test_shrinkToFit1();
    test_shrinkToFit2();
}
void test_isFull2() {
    vector v = createVector(5);
    v.size = 4;
    assert(!isFull(&v));
    deleteVector(&v);
}
void test_isFull1() {
    vector v = createVector(2);
    v.size = 2;
    assert(isFull(&v));
    deleteVector(&v);
}
void test_isFull() {
    test_isFull2();
    test_isFull1();
}
void test_isEmpty1() {
    vector v = createVector(4);
    v.size = 3;
    assert(!isEmpty(&v));
    deleteVector(&v);
}
void test_isEmpty2() {
    vector v = createVector(4);
    v.size = 0;
    assert(isEmpty(&v));
    deleteVector(&v);
}
void test_isEmpty() {
    test_isEmpty1();
    test_isEmpty2();
}
void test_getVectorValue1() {
    vector v = createVector(4);
    pushBack(&v, 3);
    pushBack(&v, 2);
    assert(getVectorValue(&v, 0) == v.data[0]);
    deleteVector(&v);
}
void test_getVectorValue2() {
    vector v = createVector(4);
    pushBack(&v, 3);
    pushBack(&v, 2);
    assert(getVectorValue(&v, 1) == v.data[1]);
    deleteVector(&v);
}
void test_getVectorValue() {
    test_getVectorValue1();
    test_getVectorValue2();
}
void test_pushBack1() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(v.data[v.size - 1] == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}
void test_pushBack2() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(v.data[v.size - 1] == 2);
    assert(v.capacity == 2);
    deleteVector(&v);
}
void test_pushBack() {
    test_pushBack1();
    test_pushBack2();
}
void test_popBack1() {
    vector v = createVector(0);
    pushBack(&v, 10);
    popBack(&v);
    assert(isEmpty(&v));
    assert(v.size == 0);
    deleteVector(&v);
}
void test_popBack2() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    popBack(&v);
    assert(v.data[v.size - 1] == 1);
    assert(v.size == 1);
    deleteVector(&v);
}
void test_popBack() {
    test_popBack1();
    test_popBack2();
}
void test_atVector1() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(atVector(&v, 0) == &v.data[0]);
    deleteVector(&v);
}
void test_atVector2() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(atVector(&v, 1) == &v.data[1]);
    deleteVector(&v);
}
void test_atVector3() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(atVector(&v, 2) == &v.data[2]);
    deleteVector(&v);
}
void test_atVector() {
    test_atVector1();
    test_atVector2();
    test_atVector3();
}
void test_back1() {
    vector v = createVector(0);
    pushBack(&v, 2);
    assert(back(&v) == &v.data[0]);
    deleteVector(&v);
}
void test_back2() {
    vector v = createVector(0);
    pushBack(&v, 7);
    pushBack(&v, 7);
    pushBack(&v, 7);
    assert(back(&v) == &v.data[2]);
    deleteVector(&v);
}
void test_back() {
    test_back1();
    test_back2();
}
void test_front1() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(front(&v) == &v.data[0]);
    deleteVector(&v);
}
void test_front2() {
    vector v = createVector(0);
    pushBack(&v, 7);
    pushBack(&v, 7);
    pushBack(&v, 7);
    assert(front(&v) == &v.data[0]);
    deleteVector(&v);
}
void test_front() {
    test_front1();
    test_front2();
}
void test() {
    test_createVector();
    test_reserve();
    test_shrinkToFit();
    test_isFull();
    test_isEmpty();
    test_getVectorValue();
    test_pushBack();
    test_popBack();
    test_atVector();
    test_back();
    test_front();
}
int main() {
    test();
    return 0;
}
Какие функции у вас реализуют строгое и нестрогое включение? Остальные вроде нашел - объединение, пересечение, дополнение, симметрическую разность.