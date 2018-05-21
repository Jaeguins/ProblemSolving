#include <stdio.h>

int field[1000];
int N;
int max = 0;
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &field[i]);
	}
	int length = 1;
	for (int i = 1; i < N; i++) {
		length += 1;
		if (field[i - 1] <= field[i]) {
			if (length > max) {
				max = length;
			}
			continue;
		}
		length = 1;
	}
	printf("%d", max);
	getchar();
	getchar();
}