#include "libs/data_structures/string_/string_.h"

void test_findNonSpace() {
    char c[] = " a b c";
    char *res = findNonSpace(c);
    assert(*res == 'a');
    assert(res == &c[1]);
}

void test_findSpace() {
    char c[] = "1234 abcd";
    char *res = findSpace(c);
    assert(*res == ' ');
    assert(res == &c[4]);
}

void test_findNonSpaceReverse() {
    char c[] = "cool ";
    char *res = findNonSpaceReverse(&c[4], &c[-1]);
    assert(*res == 'l');
    assert(res == &c[3]);
}

void test_findSpaceReverse() {
    char c[] = "i love programming";
    char *res = findSpaceReverse(&c[17], &c[-1]);
    assert(*res == ' ');
    assert(res == &c[6]);
}

void test_strcmp_equal() {
    char c1[] = "abc";
    char c2[] = "abc";
    assert(strcmp(c1, c2) == 0);
}

void test_strcmp_lesser() {
    char c1[] = "abc";
    char c2[] = "ccd";
    assert(strcmp(c1, c2) == -2);
}

void test_strcmp_bigger() {
    char c1[] = "bcd";
    char c2[] = "abc";
    assert(strcmp(c1, c2) == 1);
}


void test_strcmp() {
    test_strcmp_equal();
    test_strcmp_lesser();
    test_strcmp_bigger();
}

void test_copy() {
    char c1[] = "mongol";
    char c2[7];
    char *cc = copy(c1, &c1[6], c2);
    assert(c2[0] == 'm');
    assert(c2[1] == 'o');
    assert(c2[2] == 'n');
    assert(c2[3] == 'g');
    assert(c2[4] == 'o');
    assert(c2[5] == 'l');
    assert(cc == &c2[6] && c2[6] != '\0');
}

void test_copyIf() {
    char c1[] = "big brain";
    char c2[10] = "1234";
    char *c3 = copyIf(c1, &c1[9], c2 + 4, isspace);
    assert(c2[4] == ' ');
    assert(c3 == &c2[5]);
}

bool isNumber(char letter) {
    return letter >= '0' && letter <= '9';
}

void test_copyIfReverse() {
    char c1[] = "1a2b3c";
    char c2[10];
    char *c3 = copyIfReverse(&c1[6], c1, c2, isNumber);
    assert(c2[0] == '3');
    assert(c3 = &c2[3]);
}

void test_string() {
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}
void test_19_empty() {
    char string[] = "";
    word_descriptor word;
    get_word("", &word);

    assert(!letters_belong_string(string, word));
}


void test_19_empty_word() {
    char string[] = "word";
    word_descriptor word;
    get_word("", &word);

    assert(!letters_belong_string(string, word));
}


void test_19_empty_string() {
    char string[] = "";
    word_descriptor word;
    get_word("word", &word);

    assert(!letters_belong_string(string, word));
}


void test_19_letters_not_in_string() {
    char string[] = "abc";
    word_descriptor word;
    get_word("word", &word);

    assert(!letters_belong_string(string, word));
}


void test_19_letters_in_string() {
    char string[] = "world";
    word_descriptor word;
    get_word("word", &word);

    assert(letters_belong_string(string, word));
}


void test_19_letters_belong_string() {
    test_19_empty();
    test_19_empty_word();
    test_19_empty_string();
    test_19_letters_not_in_string();
    test_19_letters_in_string();
}
void test_18_empty() {
    char s1[100] = "";
    size_t n1 = 0;

    char s2[100] = "";
    size_t n2 = 0;

    balance_string(s1, n1, s2, n2);

    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
}


void test_18_first_empty() {
    char s1[100] = "";
    size_t n1 = 0;

    char s2[100] = "two word";
    size_t n2 = 2;

    balance_string(s1, n1, s2, n2);

    ASSERT_STRING(" two word", s1);
    ASSERT_STRING("two word", s2);
}


void test_18_second_empty() {
    char s1[100] = "three word";
    size_t n1 = 2;

    char s2[100] = "";
    size_t n2 = 0;

    balance_string(s1, n1, s2, n2);

    ASSERT_STRING("three word", s1);
    ASSERT_STRING(" three word", s2);
}


void test_18_equal_length() {
    char s1[100] = "three word";
    size_t n1 = 2;

    char s2[100] = "two man";
    size_t n2 = 2;

    balance_string(s1, n1, s2, n2);

    ASSERT_STRING("three word", s1);
    ASSERT_STRING("two man", s2);
}


void test_18_different_length_1() {
    char s1[100] = "max";
    size_t n1 = 1;

    char s2[100] = "equal top moment";
    size_t n2 = 3;

    balance_string(s1, n1, s2, n2);

    ASSERT_STRING("max top moment", s1);
    ASSERT_STRING("equal top moment", s2);
}


void test_18_different_length_2() {
    char s1[100] = "equal top moment";
    size_t n1 = 3;

    char s2[100] = "max";
    size_t n2 = 1;

    balance_string(s1, n1, s2, n2);

    ASSERT_STRING("equal top moment", s1);
    ASSERT_STRING("max top moment", s2);
}


void test_18_balance_string() {
    test_18_empty();
    test_18_first_empty();
    test_18_second_empty();
    test_18_equal_length();
    test_18_different_length_1();
    test_18_different_length_2();
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
void test_16_empty() {
    char s1[] = "";
    char s2[] = "";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_first_empty() {
    char s1[] = "";
    char s2[] = "word";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}


void test_16_second_empty() {
    char s1[] = "i love";
    char s2[] = "";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}

void test_16_not_in_string() {
    char s1[] = "i love python";
    char s2[] = "hate c";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}

void test_16_first_in_string() {
    char s1[] = "i love python";
    char s2[] = "is love butterfly";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("i", dest);
}

void test_16_find_preceding_word() {
    test_16_empty();
    test_16_first_empty();
    test_16_second_empty();
    test_16_not_in_string();
    test_16_first_in_string();
}
void test_15_empty() {
    char source[] = "";
    char dest[40] = "";

    get_word_except_last(source, dest);

    ASSERT_STRING("", dest);
}


void test_15_one_word() {
    char source[] = "word";
    char dest[40] = "";

    get_word_except_last(source, dest);

    ASSERT_STRING("", dest);
}


void test_15_last_unique() {
    char source[] = "word map";
    char dest[40] = "";

    get_word_except_last(source, dest);

    ASSERT_STRING("word", dest);
}


void test_15_last_not_unique() {
    char source[] = "word map is map";
    char dest[40] = "";

    get_word_except_last(source, dest);

    ASSERT_STRING("word is", dest);
}


void test_15_get_word_except_last() {
    test_15_empty();
    test_15_one_word();
    test_15_last_unique();
    test_15_last_not_unique();
}
void test_14_empty() {
    char s[] = "";
    assert(!are_identical_words_in_string(s));
}


void test_14_one_word() {
    char s[] = "word";
    assert(!are_identical_words_in_string(s));
}


void test_14_anagram_not_in_string() {
    char s[] = "duplicate not in string";
    assert(!are_identical_words_in_string(s));
}


void test_14_anagram_in_string() {
    char s[] = "string in string";
    assert(are_identical_words_in_string(s));
}


void test_14_find_anagram_words() {
    test_14_empty();
    test_14_one_word();
    test_14_anagram_not_in_string();
    test_14_anagram_in_string();
}

void test_13_empty() {
    char s[] = "";
    assert(!are_equal_words_in_string(s));
}


void test_13_one_word() {
    char s[] = "word";
    assert(!are_equal_words_in_string(s));
}


void test_13_duplicate_not_in_string() {
    char s[] = "duplicate not in string";
    assert(!are_equal_words_in_string(s));
}


void test_13_duplicate_in_string() {
    char s[] = "string in string";
    assert(are_equal_words_in_string(s));
}


void test_13_find_duplicate_words() {
    test_13_empty();
    test_13_one_word();
    test_13_duplicate_not_in_string();
    test_13_duplicate_in_string();
}
void test_12_word_at_end() {
    char s1[] = "i love python";
    char s2[] = "python is cool";

    char dest[MAX_WORD_SIZE] = "";
    word_descriptor word = find_last_common_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("python", dest);
}


void test_12_no_common_word() {
    char s1[] = "i love";
    char s2[] = "python is cool";

    char dest[MAX_WORD_SIZE] = "";
    word_descriptor word = find_last_common_word(s1, s2);

    assert(word.begin == NULL && word.end == NULL);
}


void test_12_word_at_start() {
    char s1[] = "python my love";
    char s2[] = "python is cool";

    char dest[MAX_WORD_SIZE] = "";
    word_descriptor word = find_last_common_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("python", dest);
}


void test_12_single_word_strings() {
    char s1[] = "my";
    char s2[] = "my";

    char dest[MAX_WORD_SIZE] = "";
    word_descriptor word = find_last_common_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("my", dest);
}


void test_12_find_last_common_word() {
    test_12_word_at_end();
    test_12_word_at_start();
    test_12_no_common_word();
    test_12_single_word_strings();
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




int main() {
    test_string();

    return 0;
}