#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000
#define INT_MAX 0x7FFFFFFF
int field[MAX];
int memo[MAX];
int N,M;
int rangeQuery(int start, int end) {
    int circulation = 0;
    int startBuf = 0, endBuf = 0;
    int minimum = INT_MAX;
    int i = start;
    while (i <= end) {
        circulation++;
        if ((i / M + 1) < end / M) {
            if (memo[i/M] < minimum)minimum = memo[i/M];
            i += M;
        }
        if (field[i] < minimum)minimum = field[i];
        i++;
    }
    /*
    int memoStart=start/M, memoEnd=end/M;
    if (start / M * M != start) {
        memoStart++;
        for (int i = start; i < ((start / M) + 1)*M; i++) {
            circulation++;
            startBuf++;
            if (field[i] < minimum)minimum = field[i];
        }
    }
    if (end / M * M != end-M+1) {
        memoEnd--;
        for (int i = end/M*M; i <= end; i++) {
            endBuf++;
            circulation++;
            if (field[i] < minimum)minimum = field[i];
        }
    }
    for (int i = memoStart; i < memoEnd; i++) {
        circulation++;
        if (memo[i] < minimum)minimum = memo[i];
    }
    */
    ///*detailed value visualizing code
    
    printf(" circulation : %d, ",circulation);
    //*/
    
    return minimum;
}
int main(){
    FILE* fp = fopen("data_12.txt", "r");
    fscanf(fp, " %d", &N);
    M = (int)pow(N, 0.5);
    int flag = 0;
    for (int i = 0; i < N; i++) {
        fscanf(fp, " %d", &field[i]);
        if (i / M * M == i)memo[i / M] = INT_MAX;
        if (memo[i / M] > field[i])memo[i / M] = field[i];
    }
    printf("loading finished, input range (start end):\n");
    while (1) {
        int start, end;
        scanf(" %d %d", &start, &end);
        printf("result : %d\n",rangeQuery(start, end));
    }
}
