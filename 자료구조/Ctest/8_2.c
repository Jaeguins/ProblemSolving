#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char input[100];
        scanf("%s", input);
        int count = 1;
        int level[1000];
        int rear = 0;
        for (int j = 0; j < strlen(input); j++) {
            switch (input[j]) {
            case '(':
                level[rear++]=count;
                printf("%d ", count++);
                break;
            case ')':
                printf("%d ", level[--rear]);
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
    getchar();
    getchar();
}