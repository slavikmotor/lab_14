#ifndef CODE_LETTERS_BELONG_STRING_H
#define CODE_LETTERS_BELONG_STRING_H

#include <assert.h>
#include "../string_.h"

#define LETTERS_SHIFT 97


bool letters_belong_string(char* string, word_descriptor word) {
    bool include[26] = {0};

    char* start = string;
    char* end = get_end_of_string(string);

    while (start != end) {
        if (isalpha(*start))
            include[*start - LETTERS_SHIFT] = true;

        start++;
    }

    while (word.begin != word.end) {
        if (!include[*word.begin - LETTERS_SHIFT])
            return false;

        word.begin++;
    }

    return true;
}
#endif //CODE_LETTERS_BELONG_STRING_H
