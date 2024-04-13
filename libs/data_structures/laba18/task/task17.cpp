#ifndef CODE_REMOVE_PALINDROME_WORD_H
#define CODE_REMOVE_PALINDROME_WORD_H

#include "../string_.h"


void remove_palindrome_word(char* s) {
    char* read_begin = _string_buffer;
    char* read_end = copy(s, s + strlen_(s), _string_buffer);
    char* rec_ptr = s;

    word_descriptor word;
    while (get_word(read_begin, &word)) {
        if (!is_palindrome_word(&word)) {
            rec_ptr = copy(word.begin, word.end, rec_ptr);

            if (word.end !=  read_end)
                *rec_ptr++ = ' ';
        }
        read_begin = word.end + 1;
    }

    *rec_ptr = '\0';

    free_string(_string_buffer);
}


void test_17_empty() {
    char s[] = "";
    remove_palindrome_word(s);
    ASSERT_STRING("", s);
}


void test_17_non_palindrome() {
    char s[] = "none palindrome words";
    remove_palindrome_word(s);
    ASSERT_STRING("none palindrome words", s);
}


void test_17_only_letters() {
    char s[] = "a b c d";
    remove_palindrome_word(s);
    ASSERT_STRING("", s);
}


void test_17_different_string() {
    char s[] = "radar is word a b is letters";
    remove_palindrome_word(s);
    ASSERT_STRING("is word is letters", s);
}


void test_17_remove_palindrome_word() {
    test_17_empty();
    test_17_non_palindrome();
    test_17_only_letters();
    test_17_different_string();
}


#endif //CODE_REMOVE_PALINDROME_WORD_H
