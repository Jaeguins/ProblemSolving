#include <stdio.h>


int main() {
	int N, K;
	int arr[2][100];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 100; j++) arr[i][j] = 0;
	}
	scanf_s("%d", &N);
	scanf_s("%d", &K);
	for (int i = 1; i < N + 2; i++) {
		for (int j = 0; j < i; j++) {
			if (i == j || j == 0) arr[i % 2][j] = 1;
			else arr[i % 2][j] = arr[(i + 1)%2][j] + arr[(i + 1)%2][j - 1];
		}
	}
	printf("%d\n", arr[(N + 1) % 2][K]);
	getchar();
	getchar();
}