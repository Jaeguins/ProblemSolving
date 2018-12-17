#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int size = 0;
int field[15][15];
int count = 0;
char buffer[512];
int direction[3][2] = {
    {1,1},
    {1,0},
    {1,-1}
};

int isInBound(int x, int y) {
    return x >= 0 && x < size&&y >= 0 && y < size ? 1 : 0;
}


void drawLoc(int index, int y, int val) {
    for (int i = 1; i < size-index; i++) {
        for (int j = 0; j < 3; j++) {
            if (isInBound(index + direction[j][0] * i, y + direction[j][1] * i))
                field[index + direction[j][0] * i][y + direction[j][1] * i] += val;
                
        }
    }
    
}
int recursive(int index, int level) {
    
    if (level == size) {
        return 1;
    }
    int sum=0;
    for (int i = 0; i < size; i++) {
        if (!field[index][i]) {
            field[index][i] = 1;
            drawLoc(index,i, 1);
            sum+=recursive(index+1, level + 1);
            field[index][i] = 0;
            drawLoc(index,i, -1);
        }
    }
    return sum;
}
int main() {
    for (int N = 1; N <= 15; N++) {
        size = N;
        count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                field[i][j] = 0;
            }
        }
        printf("N : %d - Result : %d\n", size, recursive(0, 0));
    }
    getchar();
    
}