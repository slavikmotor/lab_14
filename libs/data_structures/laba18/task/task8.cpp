#include "countPalindromes.h"
int countPalindromes(char *s) {
    char *endSearch = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPalindromes = 0;
    char *commaPos = find(beginSearch, endSearch, ',');
    bool isLastComma = *commaPos == '\0' && endSearch != beginSearch;
    while (*commaPos != '\0' || isLastComma) {
        beginSearch = findNonSpace(beginSearch);
        countPalindromes += isPalindrome(beginSearch, commaPos);
        beginSearch = commaPos + 1;
        if (isLastComma)
            break;
        commaPos = find(beginSearch, endSearch, ',');
        isLastComma = *commaPos == '\0';
    }
    return countPalindromes;
}
void test_countPalindromes_nonWords() {
    char s[] = "";
    assert(countPalindromes(s) == 0);
}
void test_countPalindromes_nonPalindromes() {
    char s[] = "abccfa,asccba";
    assert(countPalindromes(s) == 0);
}
void test_countPalindromes_manyPalindromes() {
    char s[] = "abccba,abccba";
    assert(countPalindromes(s) == 2);
}
void test_countPalindromes() {
    test_countPalindromes_nonWords();
    test_countPalindromes_nonPalindromes();
    test_countPalindromes_manyPalindromes();
}
int main() {
    test_countPalindromes();
    return 0;
}
