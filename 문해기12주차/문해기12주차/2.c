#include <stdio.h>
void insertionSort(int field[],int size) {
    for (int i = 0; i<size; i++) {
        int t = i;
        for (int j = i + 1; j<size; j++) if (field[t]>field[j])t = j;
        if (t != i) {
            int tmp = field[i];
            field[i] = field[t];
            field[t] = tmp;
        }
    }
}
int main() {
    int field[100], size = 0;
    while (1) {
        char k = getchar();
        if (k == '\n') break;
        field[size] = k;
        size += 1;
        insertionSort(field, size);
    }
    for (int i = 0; i < size; i++) printf("%c", field[i]);
    getchar();
    getchar();
}