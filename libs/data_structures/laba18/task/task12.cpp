#ifndef CODE_FIND_LAST_COMMON_WORD_H
#define CODE_FIND_LAST_COMMON_WORD_H

#include "../string_.h"


word_descriptor find_last_common_word(char* s1, char* s2) {
    char* begin_search_1 = s1;
    char* begin_search_2 = s2;

    while (get_word_without_space(begin_search_1, &_bag.words[_bag.size])) {
        begin_search_1 = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    while (get_word_without_space(begin_search_2, &_bag2.words[_bag2.size])) {
        begin_search_2 = _bag2.words[_bag2.size].end + 1;
        _bag2.size++;
    }

    word_descriptor word = {.begin = NULL, .end = NULL};
    for (int i = (int) _bag.size - 1; i >= 0; i--)
        for (int j = 0; j < _bag2.size; j++)
            if (is_word_equal(_bag.words[i], _bag2.words[j])) {
                word = _bag.words[i];

                free_bag(&_bag);
                free_bag(&_bag2);

                return word;
            }

    return word;
}
#endif //CODE_FIND_LAST_COMMON_WORD_H

