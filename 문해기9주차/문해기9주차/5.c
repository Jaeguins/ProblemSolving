#include <stdio.h>
int compareLexicographic(int a, int b) {
	if (a == b)return 0;
	int  arrA[20], arrB[20], lengA = -1, lengB = -1;
	for (int i = 0;a>0; i++) {
		arrA[i] = a % 10;
		lengA += 1;
		a /= 10;
	}
	for (int i = 0;b>0; i++) {
		arrB[i] = b % 10;
		lengB += 1;
        b /= 10;
	}
    while (1) {
        if (arrA[lengA] < arrB[lengB]) return 1;
        else if (arrA[lengA] > arrB[lengB]) return -1;
        else {
            lengA -= 1;
            lengB -= 1;
            continue;
        }
    }
}
int main() {
	int field[1000];
	FILE* input;
	fopen_s(&input, "input5.txt", "r");
	int t, length = 0;
	while (fscanf_s(input, "%d", &t) != EOF) {
		field[length] = t;
		length += 1;
	}
	for (int i = 0; i < length-1; i++) {
		for (int j = i; j >= 0; j--) {
			if (compareLexicographic(field[j], field[j + 1]) == -1)
			{
				int t = field[j];
				field[j] = field[j + 1];
				field[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < length; i++) {
		printf("%d ", field[i]);
	}
	getchar();
	getchar();
}