#include <stdio.h>

int main() {
	int K;
	scanf_s("%d", &K);
	for (int sum = 0; sum <= K; sum++) {
		for (int i = 0; i <= sum; i++) {
			printf("%d %d\n", i, sum - i);
		}
	}
	getchar();
	getchar();
}