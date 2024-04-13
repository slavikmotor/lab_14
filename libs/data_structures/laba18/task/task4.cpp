#include "replaceEachNumberWithSpaces.h"
void replaceEachNumberWithSpaces(char *s) {
    char *buffer = _stringBuffer;
    char *endString = getEndOfString(s);
    char *endOfBuffer = copy(s, endString, buffer);
    *endOfBuffer = '\0';
    while (*buffer != '\0') {
        if (!isdigit(*buffer)) {
            *s = *buffer;
            *s++;
        } else {
            int nSpaces = *buffer - '0';
            for (int i = 0; i < nSpaces; i++) {
                *s = ' ';
                *s++;
            }
        }
        buffer++;
    }
    *s = '\0';
}
void test_replaceEachNumberWithSpaces_nonWords() {
    char s[] = "";
    replaceEachNumberWithSpaces(s);
    ASSERT_STRING("", s);
}
void test_replaceEachNumberWithSpaces_nonDigits() {
    char s[] = "abc abc";
    replaceEachNumberWithSpaces(s);
    ASSERT_STRING("abc abc", s);
}
void test_replaceEachNumberWithSpaces_withDigits() {
    char s[] = "a1 b2";
    replaceEachNumberWithSpaces(s);
    ASSERT_STRING("a b ", s);
}
void test_replaceEachNumberWithSpaces() {
    test_replaceEachNumberWithSpaces_nonWords();
    test_replaceEachNumberWithSpaces_nonDigits();
    test_replaceEachNumberWithSpaces_withDigits();
}
int main() {
    test_replaceEachNumberWithSpaces();
    return 0;
}