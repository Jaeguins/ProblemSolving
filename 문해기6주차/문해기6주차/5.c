#include <stdio.h>
int field[100][2];
int length;
int getMaxInd(int range) {
	int ret = 0;
	for (int i = 0; i <= range; i++) {
		if (field[i][0] > field[ret][0]) {
			ret = i;
		}
		else if (field[i][0] == field[ret][0]&& field[i][1] > field[ret][1]) {
			ret = i;
		}
	}
	return ret;
}
int swap(int ind1, int ind2) {
	int tmp[2];
	tmp[0] = field[ind1][0];
	tmp[1] = field[ind1][1];
	field[ind1][0] = field[ind2][0];
	field[ind1][1] = field[ind2][1];
	field[ind2][0] = tmp[0];
	field[ind2][1] = tmp[1];
}
void insertionSort() {
	for (int i = length - 1; i >= 0; i--) {
		int t = getMaxInd(i);
		swap(t, i);
	}
}
int main() {
	scanf_s("%d", &length);
	for (int i = 0; i < length; i++) {
		scanf_s("%d %d", &field[i][0], &field[i][1]);
	}
	insertionSort();
	for (int i = 0; i < length; i++) {
		printf("%d %d\n", field[i][0], field[i][1]);
	}
	getchar();
	getchar();
}