#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100


int field[MAX_SIZE][MAX_SIZE];
int N;
int count = 0;

int MazePath(int x, int y, int dist) {
    if (x < 0 || y < 0 || x >= N || y >= N || field[x][y] != 0)
        return 0;
    else if (x == N - 1 && y == N - 1) {
        return 1;
    }
    else {
        int ret = 0;
        field[x][y] = 2;
        ret += MazePath(x - 1, y, dist + 1);
        ret += MazePath(x, y + 1, dist + 1);
        ret += MazePath(x + 1, y, dist + 1);
        ret += MazePath(x, y - 1, dist + 1);
        field[x][y] = 0;
        return ret;
    }
}
int main() {
    int result = 0;
    while (1) {
        /*custom size
            
            scanf("%d", &N);
        */
        N = 8;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                field[i][j] = (rand() % 2) ? 0 : 1;
                /*custom maze
                
                scanf("%d", &field[i][j]);
                */
            }
            
        }
        field[0][0] = 0;
        field[N - 1][N - 1] = 0;
        /*visualizing code
        
        system("cls");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%s", (field[i][j] ? "бс" : "бр"));
            }
            printf("\n");
        }
        
        */
        result = MazePath(0, 0, 0);
        printf("result : %d\n", result);
        /*skip when random generated maze is blocking way
        
        if(result)
        */
        getchar();
    }
}