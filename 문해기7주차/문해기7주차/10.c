#include <stdio.h>
int N, field[100];
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &field[i]);
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", getRoot(i));
	}

	getchar();
	getchar();
}
int getRoot(int i) {
	for (int j = 1;j<N-1; j++) {
		if (calcA(j, i) == calcA(j+1, i)) {
			return calcA(j, i);
		}
	}
	return -1;
}
int calcA(int k, int i) {
	if (k == 0) {
		return i;
	}
	else {
		return field[calcA(k - 1, i)];
	}
}