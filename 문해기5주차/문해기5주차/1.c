#include <stdio.h>

int main() {
	int field[100];
	int N, K;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &field[i]);
	}
	scanf_s("%d", &K);
	int max = -9999999, index;
	for (int i = 0; i < N; i++) {
		if (field[i] <= K && field[i]>max) {
			index = i;
			max = field[i];
		}
	}
	printf("%d %d %d", index, max, K - max);
	getchar();
	getchar();
}