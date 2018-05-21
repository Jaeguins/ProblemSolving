#include <stdio.h>
#include <stdlib.h>
int main() {
	int N, T = 1000;
	long int sum = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < T; i++) {
		int x = 0, y = 0, count = 0;
		for (; (x < N && x > N * -1) && (y < N && y > N * -1);) {
			int random = rand() % 4;
			switch (random) {
			case 0:
				y += 1;
				break;
			case 1:
				x -= 1;
				break;
			case 2:
				y -= 1;
				break;
			case 3:
				x += 1;
				break;
			}
			count += 1;
		}
		sum += count;
	}
	printf("%d", sum / T);
	getchar();
	getchar();
}