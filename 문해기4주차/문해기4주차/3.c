#include <stdio.h>

int main() {
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i <= N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j <= N; j++) {
				printf("%d %d\n", j, i);
			}
		}
		else {
			for (int j = N; j >= 0; j--) {
				printf("%d %d\n", j, i);
			}
		}
	}
	getchar();
	getchar();
}