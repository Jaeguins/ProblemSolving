#include <stdio.h>
int check(char checkF[1000][1000], int nowX, int nowY, int dir, int dist) {
    for (int i = 0; i < dist; i++) {
        switch (dir) {
        case 0:
            nowY += 1;
            break;
        case 1:
            nowX += 1;
            break;
        case 2:
            nowY -= 1;
            break;
        case 3:
            nowX -= 1;
            break;
        }
        if (!checkF[nowX][nowY]) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char checkField[1000][1000];
    int inDir = 0, inDist = 0, nowX = 250, nowY = 250;
    while (1) {
        scanf_s("%d", &inDir);
        scanf_s("%d", &inDist);
        if (inDist == -1) {
            break;
        }
        if (check(checkField, nowX, nowY, inDir, inDist)) {
            for (int k = 0; k < inDist; k++) {
                checkField[nowX][nowY] = 0;
                switch (inDir) {
                case 0:
                    nowY += 1;
                    break;
                case 1:
                    nowX += 1;
                    break;
                case 2:
                    nowY -= 1;
                    break;
                case 3:
                    nowX -= 1;
                    break;
                }
            }
            printf("%d %d\n", nowX-250, nowY-250);
        }
        else {
            printf("invalid move\n");
        }
    }
    getchar();
    getchar();
}