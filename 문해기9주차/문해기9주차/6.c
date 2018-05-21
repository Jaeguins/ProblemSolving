#include <stdio.h>

int getPow(int i, int p) {
    int ret = 1;
    for (int j = 0; j < p; j++) {
        ret *= i;
    }
    return ret;
}

int main() {
    int field[1000][2];
    int n, x;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &field[i][0]);
        scanf_s("%d", &field[i][1]);
    }
    scanf_s("%d", &x);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret += field[i][0] * getPow(x, field[i][1]);
    }
    printf("%d", ret);
    getchar();
    getchar();
}