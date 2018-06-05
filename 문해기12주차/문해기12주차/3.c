#include <stdio.h>

int main() {
    int field[26] = { 0 };
    while (1) {
        char k = getchar();
        if (k == ' ')break;
        if (k > 96)k -= 32;
        field[k-65] += 1;
    }
    while (1) {
        char k = getchar();
        if (k == '\n')break;
        if (k > 96)k -= 32;
        field[k-65] -= 1;
    }
    int result = 1;
    for (int i = 0; i < 26; i++) {
        if (field[i]) {
            result = 0;
            break;
        }
    }
    if (result) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    getchar();
    getchar();
}