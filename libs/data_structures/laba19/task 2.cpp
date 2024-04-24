#ifndef CODE_CONVERT_FLOAT_H
#define CODE_CONVERT_FLOAT_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <assert.h>

#include "../../data_structures/string/string_.h"
#include "../../data_structures/vectorVoid/vectorVoid.h"


void generate_float(const char* filename, int n) {
    srand(time(NULL));

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    for (size_t i = 0; i < n; i++)
        fprintf(file, "%f ", 10.0 * rand() / RAND_MAX);

    fclose(file);
}


void convert_float(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    vectorVoid v = createVectorV(0, sizeof(float));

    while (!feof(file)) {
        float x;
        fscanf(file, "%f", &x);

        pushBackV(&v, &x);
    }

    fclose(file);


    file = fopen(filename, "w");

    for (size_t i = 0; i < v.size; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        fprintf(file, "%.2f ", x);
    }

    deleteVectorV(&v);
    fclose(file);
}


void test_convert_float_1_zero_quantity() {
    const char filename[] = "C:\\Users\\Компьютер\\CLionProjects\\untitled1\\libs\\data_structures\\laba19";

    FILE* file = fopen(filename, "w");
    fclose(file);


    convert_float(filename);


    file = fopen(filename, "r");

    char data[10] = "";
    fscanf(file, "%s", data);

    fclose(file);

    assert(strcmp_(data, "0.00") == 0);
}


void test_convert_float_2_one_element() {
    const char filename[] = "C:\\Users\\Компьютер\\CLionProjects\\untitled1\\libs\\data_structures\\laba19";

    float number = 10.123;

    FILE* file = fopen(filename, "w");

    fprintf(file, "%f", number);

    fclose(file);


    convert_float(filename);


    file = fopen(filename, "r");

    char data[10] = "";
    fscanf_s(file, "%s", data);

    fclose(file);


    char check[10] = "10.12";

    assert(strcmp_(data, check) == 0);
}


void test_convert_float_3_more_element() {
    const char filename[] = "C:\\Users\\Компьютер\\CLionProjects\\untitled1\\libs\\data_structures\\laba19";

    float f1 = 1.123123;
    float f2 = 2.232323;
    float f3 = 3.343434;


    FILE* file = fopen(filename, "w");

    fprintf(file, "%f %f %f", f1, f2,f3);

    fclose(file);


    convert_float(filename);

    file = fopen(filename, "r");

    char data[100] = "";
    fgets(data, sizeof(data), file);

    fclose(file);

    char check[100] = "1.12 2.23 3.34 ";

    assert(strcmp_(data, check) == 0);
}


void test_convert_float() {
    test_convert_float_1_zero_quantity();
    test_convert_float_2_one_element();
    test_convert_float_3_more_element();
}


#endif //CODE_CONVERT_FLOAT_H