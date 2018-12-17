#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int checkPalindromeInternal(char*str, int length, int index) {
    if (index > length - index)return 1;
    if (str[index] == str[length - index])return checkPalindromeInternal(str, length, ++index);
    else return 0;
}

int checkPalindrome(char* str, int length) {
    return checkPalindromeInternal(str, length - 1, 0);
}

int main() {
    char string[100];
    while (1) {
        scanf("%s", string);
        printf("%s\n", checkPalindrome(string, strlen(string)) ? "YES" : "NO");
    }
    getchar();
}