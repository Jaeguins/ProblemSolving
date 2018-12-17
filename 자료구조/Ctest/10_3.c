#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 1000
int data[MAX];
int N, K;
int recursion(int start, int end) {
    if (start >= end)return 0;
    int sum = data[start] + data[end];
    if (sum > K)
        return recursion(start, end - 1);
    else if (sum < K)
        return recursion(start + 1, end);
    else {
        return recursion(start + 1, end - 1) + 1;
    }
}


int main() {
    while(1) {
        scanf("%d", &N);
        int start = 0, end = N - 1;
        int count = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &data[i]);
        }
        scanf("%d", &K);
        printf("\n%d\n", recursion(start,end));
    }
}
