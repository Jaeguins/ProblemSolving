#include <stdio.h>
#include <stdlib.h>
int main() {
	int T = 1000000,countA=0,countB=0;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 6; j++) {
			int tRandom = rand() % 6;
			if (tRandom == 0) {
				countA += 1;
				break;
			}
		}
		int tmp = 0;
		for (int j = 0; j < 12; j++) {
			int tRandom = rand() % 6;
			if (tRandom == 0) {
				tmp += 1;
				if (tmp == 2) {
					countB += 1;
					break;
				}
			}
		}
	}
	printf("%d\n%d", countA, countB);
	getchar();
	getchar();
}