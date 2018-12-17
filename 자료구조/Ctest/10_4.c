#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int data[100];
int target,length;
 int floor(int index) {
     if (index < 0)return -1;
     if (data[index] <= target)return data[index];
     else return floor(index - 1);
}
int ceiling(int index){
    if (index >= length)return -1;
    if (data[index] >= target)return data[index];
    else return ceiling(index + 1);
}


int main() {
    while (1) {
        scanf("%d", &length);
        for (int i = 0; i < length; i++) {
            scanf("%d", &data[i]);
        }
        scanf("%d", &target);
        printf("\nfloor : %d\nceiling : %d\n", floor(length - 1), ceiling(0));
    }
}