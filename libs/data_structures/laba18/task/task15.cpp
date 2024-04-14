#ifndef CODE_GET_WORD_EXCEPT_LAST_H
#define CODE_GET_WORD_EXCEPT_LAST_H

#include "../string_.h"


void get_word_except_last(char* source, char* dest) {
    char* begin_search = source;

    while (get_word_without_space(begin_search, &_bag.words[_bag.size])) {
        begin_search = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    if (_bag.size == 0) {
        free_bag(&_bag);
        return;
    }

    word_descriptor last_word = _bag.words[_bag.size - 1];
    char* rec_ptr = dest;

    for (size_t i = 0; i < _bag.size - 1; i++) {
        if (!is_word_equal(_bag.words[i], last_word)) {
            rec_ptr = copy(_bag.words[i].begin, _bag.words[i].end + 1, rec_ptr);
            if (i != _bag.size - 2)
                *rec_ptr++ = ' ';
        }
    }

    *rec_ptr = '\0';

    free_bag(&_bag);
}

#endif //CODE_GET_WORD_EXCEPT_LAST_H
