#include "replaceWords1ToWord2.h"
void replaceWord1ToWord2(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *writePtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        writePtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        writePtr = source;
    }
    while (*readPtr != '\0') {
        if (*readPtr == *word1.begin) {
            if (areWordsEqual(word1, (WordDescriptor) {readPtr, readPtr +
                                                                w1Size}) <= 0) {
                copy(word2.begin, word2.end, writePtr);
                readPtr += w1Size;
                writePtr += w2Size;
            } else
                *writePtr++ = *readPtr++;
        } else
            *writePtr++ = *readPtr++;
    }
    *writePtr = '\0';
}
void test_replaceWord1ToWord2_nonWords() {
    char s[] ="";
    replaceWord1ToWord2(s, "Barcelona", "Madrid");
    ASSERT_STRING("", s);
}
void test_replaceWord1ToWord2_nonWord1() {
    char s[] ="Hala Liverpool";
    replaceWord1ToWord2(s, "Barcelona", "Madrid");
    ASSERT_STRING("Hala Liverpool", s);
}
void test_replaceWord1ToWord2_withWord1() {
    char s[] ="Hala Barcelona";
    replaceWord1ToWord2(s, "Barcelona", "Madrid");
    ASSERT_STRING("Hala Madrid", s);
}
void test_replaceWord1ToWord2() {
    test_replaceWord1ToWord2_nonWords();
    test_replaceWord1ToWord2_nonWord1();
    test_replaceWord1ToWord2_withWord1();
}
int main() {
    test_replaceWord1ToWord2();
    return 0;
}