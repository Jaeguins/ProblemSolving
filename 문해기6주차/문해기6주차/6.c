#include <stdio.h>
int N;
int field[100] = { 0 }, footstep[100] = { 0 };
int countSycle() {
	int index = 0, count = 0;

	while (index < N) {
		if (sycle(index)) {
			count += 1;
		}
		index += 1;
	}
	return count;
}
int sycle(int startInd) {
	int check[100] = { 0 };
	int index = startInd;
	do {
		if (index >= N || footstep[index] == 1) {
			footstep[startInd] = 1;
			return 0;
		}
		check[index] = 1;
		index = field[index];
	} while (index != startInd);
	for (int i = 0; i < 100; i++) {
		if (check[i]) {
			footstep[i] = 1;
		}
	}
	return 1;
}
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &field[i]);
	}
	printf("%d", countSycle());
	getchar();
	getchar();
}
