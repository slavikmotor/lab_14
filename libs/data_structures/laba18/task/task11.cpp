#ifndef CODE_GET_WORD_BEFORE_FIRST_WORD_WITH_A_H
#define CODE_GET_WORD_BEFORE_FIRST_WORD_WITH_A_H

#include <assert.h>
#include "../string_.h"


typedef enum word_before_first_word_with_a_return_code {
    EMPTY_STRING,
    NOT_FOUND_A_WORD_WITH_A,
    FIRST_WORD_WITH_A,
    WORD_FOUND
} word_before_first_word_with_a_return_code;


bool is_letters_in_word(word_descriptor word, char letters) {
    char* start = word.begin;

    while (start != word.end) {
        if (*start == letters)
            return true;

        start++;
    }

    return false;
}


word_before_first_word_with_a_return_code get_word_before_first_word_a(char* s, word_descriptor* word) {
    char* begin_search = s;

    word_descriptor word1;
    if (!get_word(begin_search, &word1)) {
        return EMPTY_STRING;
    }
    begin_search = word1.end + 1;



    if (is_letters_in_word(word1, 'a') || is_letters_in_word(word1, 'A')) {
        return FIRST_WORD_WITH_A;
    }

    word_descriptor word2;
    while (get_word(begin_search, &word2)) {
        if (is_letters_in_word(word2, 'a') || is_letters_in_word(word2, 'A')) {
            *word = word1;
            return WORD_FOUND;
        }

        word1 = word2;

        begin_search = word2.end + 1;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}


void test_11_all_test_get_before_first_word_with_a() {
    word_descriptor word;

    char s1[] = "";
    assert(get_word_before_first_word_a(s1, &word) == EMPTY_STRING);

    char s2[] = "abc";
    assert(get_word_before_first_word_a(s2, &word) == FIRST_WORD_WITH_A);

    char s3[] = "bc a";
    assert(get_word_before_first_word_a(s3, &word) == WORD_FOUND);

    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("bc", got);

    char s4[] = "b q we nw";
    assert(get_word_before_first_word_a(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}


#endif //CODE_GET_WORD_BEFORE_FIRST_WORD_WITH_A_H
