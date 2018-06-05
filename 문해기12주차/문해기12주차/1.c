#include <stdio.h>

int main() {
    char field[100];
    int length = 0;
    while (1) {
        char k;
        scanf_s("%c", &k);
        if (k == '\n') {
            break;
        }
        else {
            field[length] = k;
            length += 1;
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", field[i]);
    }
    getchar();
    getchar();
}