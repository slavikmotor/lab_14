#include "digitToStart.h"
void digitToStartWithReverse(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}
void digitToStartWithReverseForEveryWord(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithReverse(word);
        beginSearch = word.end;
    }
}
void digitToStartWithSave(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin,
                               isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}
void digitToStartWithSaveForEveryWord(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithSave(word);
        beginSearch = word.end;
    }
}
void test_digitToStartWithReverseForEveryWord_nonWords() {
    char s[] = "";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("", s);
}
void test_digitToStartWithReverseForEveryWord_nonDigits() {
    char s[] = "abc adc";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("abc adc", s);
}
void test_digitToStartWithReverseForEveryWord_withDigits() {
    char s[] = "a12 b34 c56";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("21a 43b 65c", s);
}
void test_digitToStartWithReverseForEveryWord() {
    test_digitToStartWithReverseForEveryWord_nonWords();
    test_digitToStartWithReverseForEveryWord_nonDigits();
    test_digitToStartWithReverseForEveryWord_withDigits();
}
void test_digitToStartWithSaveForEveryWord_nonWords() {
    char s[] = "";
    digitToStartWithSaveForEveryWord(s);
    ASSERT_STRING("", s);
}
void test_digitToStartWithSaveForEveryWord_nonDigits() {
    char s[] = "anc hqd";
    digitToStartWithSaveForEveryWord(s);
    ASSERT_STRING("anc hqd", s);
}
void test_digitToStartWithSaveForEveryWord_withDigits() {
    char s[] = "a12 b34 45";
    digitToStartWithSaveForEveryWord(s);
    ASSERT_STRING("12a 34b 45", s);
}
void test_digitToStartWithSaveForEveryWord() {
    test_digitToStartWithSaveForEveryWord_nonDigits();
    test_digitToStartWithSaveForEveryWord_nonDigits();
    test_digitToStartWithSaveForEveryWord_withDigits();
}
int main() {
    test_digitToStartWithReverseForEveryWord();
    test_digitToStartWithSaveForEveryWord();
}
