#ifndef CODE_FIND_ANAGRAM_WORDS_H
#define CODE_FIND_ANAGRAM_WORDS_H

#include <stdlib.h>
#include <assert.h>
#include "../string_.h"


int compare_letters(const void* s1, const void* s2) {
    return *(char *) s1 - *(char *) s2;
}

void sort_word_letters(word_descriptor* word) {
    qsort(word->begin, word->end - word->begin, sizeof(char), compare_letters);
}


bool are_identical_words_in_string(char* s) {
    char* begin_buff = _string_buffer;

    copy(s, s + strlen_(s), _string_buffer);

    while (get_word_without_space(begin_buff, &_bag.words[_bag.size])) {
        begin_buff = _bag.words[_bag.size].end + 2;
        _bag.size++;
    }

    free_string(_string_buffer);

    if (_bag.size <= 1)
        return false;

    for (size_t i = 0; i < _bag.size; i++)
        sort_word_letters(&_bag.words[i]);

    for (size_t i = 0; i < _bag.size; i++)
        for (size_t j = i + 1; j < _bag.size; j++)
            if (is_word_equal(_bag.words[i], _bag.words[j])) {
                free_bag(&_bag);
                return true;
            }

    free_bag(&_bag);
    return false;
}

#endif //CODE_FIND_ANAGRAM_WORDS_H
