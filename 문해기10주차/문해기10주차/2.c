#include <stdio.h>
int find(int arr[], int length, int val) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}
void insert(int arr[], int* length, int val) {
    int i = 0;
    for (; i < *length; i++) {
        if (arr[i] > val) {
            break;
        }
    }
    for (int j = *length - 1; j >= i; j--) {
        arr[j+1] = arr[j];
    }
    arr[i] = val;
    *length += 1;
}
int main() {
    int field[1000], length = 0;
    int input = 0,duplicateCount=0;
    while (1) {
        scanf_s("%d", &input);
        if (input == -1) break;
        if (find(field, length, input) != -1) {
            duplicateCount += 1;
            printf("duplicate entry : %d\n", duplicateCount);
        }
        else {
            insert(field, &length, input);
            for (int i = 0; i < length; i++) {
                printf("%d ", field[i]);
            }
            printf("\n");
        }
    }
    getchar();
    getchar();
}