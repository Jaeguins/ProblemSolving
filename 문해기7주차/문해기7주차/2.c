#include <stdio.h>
int field[100];
int count = 0;
int N;
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &field[i]);
	}
	for (int i = 0; i < N; i++) {
		getInvert(i, 1);
	}
	printf("%d", count);
	getchar();
	getchar();
}
void getInvert(int index, int lvl) {
	if (lvl == 3) {
		count += 1;
		return;
	}
	for (int i = index+1; i < N; i++) {
		if (field[index] > field[i]) {
			getInvert(i, lvl + 1);
		}
	}
}