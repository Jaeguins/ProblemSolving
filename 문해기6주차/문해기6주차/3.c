#include <stdio.h>
int field[100];
int length=0;
int getMaxInd(int range) {
	int ret = 0;
	for (int i = range; i >= 1; i--) {
		if (field[i] > field[ret]) {
			ret = i;
		}
	}
	return ret;
}
int swap(int ind1, int ind2) {
	int tmp = field[ind1];
	field[ind1] = field[ind2];
	field[ind2] = tmp;
}
void insertionSort() {
	for (int i = length - 1; i >= 1; i--) {
		int t = getMaxInd(i);
		swap(t, i);
	}
}
int main() {
	FILE* input;
	fopen_s(&input, "input3.txt", "r");
	int t;
	while(fscanf_s(input, "%d", &t)!=EOF){
		field[length] = t;
		length += 1;
	}
	insertionSort();
	for (int i = 0; i < length; i++) {
		printf("%d ", field[i]);
	}
	getchar();
	getchar();
}