#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 256
#define FIELD_SIZE 16
int stack = 1;
int field[FIELD_SIZE][FIELD_SIZE], check[FIELD_SIZE][FIELD_SIZE];

typedef struct  queue {
    int queueX[QUEUE_SIZE], queueY[QUEUE_SIZE];
    int rear, front;
}Queue;

Queue* queue;

Queue* queueInit() {
    Queue* ret= malloc(sizeof(Queue));
    ret->rear = 0;
    ret->front = 0;
    return ret;
}
void push(Queue* queue,int x, int y) {
    queue->queueX[queue->rear] = x;
    queue->queueY[queue->rear] = y;
    queue->rear++;
    if (queue->rear == QUEUE_SIZE)queue->rear = 0;
}
void pop(Queue* queue, int*x, int*y) {
    *x = queue->queueX[queue->front];
    *y = queue->queueY[queue->front];
    queue->front++;
    if (queue->front == QUEUE_SIZE)queue->front = 0;
}
int isEmpty(Queue* queue) {
    if (queue->rear == queue->front)return 1;
    else return 0;
}
int search(int x, int y) {
    check[x][y] = stack;
    push(queue, x, y);
    int count=0;
    while (!isEmpty(queue)){
        int tX = -1, tY = -1;
        pop(queue, &tX, &tY);
        count++;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (checkBound(tX + i, tY + j) && !check[tX + i][tY + j]&&field[tX+i][tY+j]) {
                    push(queue, tX + i, tY + j);
                    check[tX + i][tY + j] = stack;
                }
            }
        }
    }
    stack++;
    return count;
}
int checkBound(int x, int y) {
    if (x >= 0 && x < FIELD_SIZE&&y >= 0 && y < FIELD_SIZE)return 1;
    else return 0;
}
int main() {
    queue = queueInit();
    FILE* f = fopen("input9_1.txt", "r");
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            fscanf(f, "%d", &field[i][j]);
        }
    }
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (!check[i][j]&&field[i][j]) {
                printf("%d ", search(i, j));
            }
        }
    }
    
    //debugging print code
    /*printf("\n");
    for (int j = 0; j < FIELD_SIZE; j++)printf("池式式");
    printf("早\n");
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (check[i][j]) {
                printf("早%2d", check[i][j]);
            }
            else {
                printf("早  ");
            }
        }
        printf("早\n");
        for (int j = 0; j < FIELD_SIZE; j++)printf("池式式");
        printf("此\n");
    }
    */
    getchar();
}