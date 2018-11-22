#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 256
int stack = 1;
int* field, *check;
int size = 0;
typedef struct  queue {
    int queueX[QUEUE_SIZE], queueY[QUEUE_SIZE];
    int rear, front;
}Queue;

Queue* queue;

Queue* queueInit() {
    Queue* ret = malloc(sizeof(Queue));
    ret->rear = 0;
    ret->front = 0;
    return ret;
}
void push(Queue* queue, int x, int y) {
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
    return queue->rear == queue->front ? 1 : 0;
}
int search(int x, int y) {
    check[x*size + y] = stack;
    push(queue, x, y);
    int count = 0;
    while (!isEmpty(queue)) {
        int tX = -1, tY = -1;
        pop(queue, &tX, &tY);
        count++;
        for (int i = -1; i < 2; i++)
            for (int j = -1; j < 2; j++)
                if (checkBound(tX + i, tY + j) && !check[(tX + i)*size + tY + j] && field[(tX + i)*size + tY + j]) {
                    push(queue, tX + i, tY + j);
                    check[(tX + i)*size + tY + j] = stack;
                }
    }
    stack++;
    return count;
}
int checkBound(int x, int y) {
    return (x >= 0 && x < size&&y >= 0 && y < size) ? 1 : 0;
}
int main() {
    queue = queueInit();
    FILE* f = fopen("input9_1.txt", "r");

    fscanf(f, "%d", &size);
    field = malloc(sizeof(int)*size*size);
    check = malloc(sizeof(int)*size*size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            fscanf(f, "%d", &field[i*size + j]);
            check[i*size + j] = 0;
        }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (!check[i*size + j] && field[i*size + j])
                printf("%d ", search(i, j));

    //debugging print code
    printf("\n");
    for (int j = 0; j < size; j++)
        printf("池式式");
    printf("早\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            if (check[i*size + j]) printf("早%2d", check[i*size + j]);
            else printf("早  ");
        printf("早\n");
        for (int j = 0; j < size; j++)
            printf("池式式");
        printf("此\n");
    }
    free(field);
    free(check);
    getchar();
}