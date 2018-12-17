#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int compare(char *str1, char* str2) {
    if (*str1 == '\0'&&*str2 == '\0') return 0;
    if (*str1 > *str2)return 1;
    if (*str1 < *str2)return -1;
    compare(++str1, ++str2);
}
int main() {
    char field[100][100];
    int rear = 0;
    printf("input words to compare. 'end' stops input.\n");
    for (int i = 0; i < 100; i++) {
        char buf[100];
        scanf("%s", buf);
        if (strcmp(buf, "end") == 0) break;
        strcpy(field[rear++], buf);
    }
    for (int i = 0; i < rear; i++)
        for (int j = 0; j < rear - i - 1; j++)
            if (compare(field[j],field[j + 1])==1)
            {
                char t[100];
                strcpy(t,field[j]);
                strcpy(field[j], field[j + 1]);
                strcpy(field[j + 1],t);
            }
    printf("\n\n");
    for (int i = 0; i < rear; i++) {
        printf("%s\n", field[i]);
    }
    getchar();
    getchar();
    getchar();
}