#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE* f = fopen("input1.txt", "r");
    int N = 0;
    fscanf(f, "%d", &N);
    for (int l = 0; l < N; l++) {
        int sum =0, num = 0;
        fscanf(f, "%d", &num);
        int* field = malloc(sizeof(int)*num);

        for (int i = 0; i < num; i++) fscanf(f, "%d", &field[i]);
        int* stack = malloc(sizeof(int)*num);
        int stackInd = 0;
        stack[0] = field[num - 1];
        for (int i = num - 2; i >= 0; i--) {
            while (1) {
                if (field[i] <= stack[stackInd]) {
                    stackInd++;
                    stack[stackInd] = field[i];
                    break;
                }
                else if (stackInd < 0) {
                    stackInd = 0;
                    stack[stackInd] = field[i];
                    break;
                }
                else stackInd--;
            }
            sum += stackInd;
            sum %= 1000000;
        }
        printf("%d\n", sum % 1000000);
        free(field);
        free(stack);
    }
    getchar();
}
