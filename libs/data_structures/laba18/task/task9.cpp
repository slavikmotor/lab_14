#include "combiningTwoStrings.h"
void combiningTwoStrings(char *s, char *s1, char *s2) {
    char *beginCopy = s;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    WordDescriptor word1, word2;
    bool isW1Found = true, isW2Found;
    while (isW1Found || isW2Found) {
        isW1Found = getWord(beginSearch1, &word1);
        isW2Found = getWord(beginSearch2, &word2);
        if (isW1Found) {
            beginCopy = copy(word1.begin, word1.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            beginCopy = copy(word2.begin, word2.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    *(beginCopy - 1) = '\0';
}
void test_combiningTwoStrings_differentSize() {
    char s1[] = "a b c q w e";
    char s2[] = "d f g";
    char s[15];
    combiningTwoStrings(s, s1, s2);
    ASSERT_STRING("a d b f c g q w e" , s);
}
void test_combiningTwoStrings_oneSize() {
    char s1[] = "a b c";
    char s2[] = "d f g";
    char s[10];
    combiningTwoStrings(s, s1, s2);
    ASSERT_STRING("a d b f c g", s);
}
void test_combiningTwoStrings() {
    test_combiningTwoStrings_oneSize();
    test_combiningTwoStrings_differentSize();
}
int main() {
    test_combiningTwoStrings();
    return 0;
}