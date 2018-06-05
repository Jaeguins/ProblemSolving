#include <stdio.h>

int main() {
    FILE* f;
    fopen_s(&f,"input.txt", "r");
    int lineSize = 0;
    while (1) {
        char field[100];
        int size = 0;
        while (1) {
            char k;
            fscanf_s(f, "%c", &k);
            if (k == ' ') break;
            else field[size++] = k;
        }
        if (size + lineSize > 80) {
            printf("\n");
            lineSize = 0;
        }
        lineSize += size;
        for (int i = 0; i < size; i++) {
            printf("%c", field[i]);
        }
        printf(" ");
        if (feof(f)) {
            break;
        }
    }
    getchar();
    getchar();
}