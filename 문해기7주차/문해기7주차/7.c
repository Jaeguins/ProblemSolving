#include <stdio.h>
int field[1000][2];
int length = 0;
int maxA, maxB, dist= 0;
int main() {
	FILE* input;
	fopen_s(&input, "input7.txt", "r");
	int t;
	while (fscanf_s(input, "%d", &t) != EOF) {
		field[length][0] = t;
		fscanf_s(input, "%d", &field[length][1]);
		length += 1;
	}
	//input from files
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			int tmp = getDist(i, j);
			if (tmp > dist) {
				dist = tmp;
				maxA = i;
				maxB = j;
			}
		}
	}
	printf("[%d, %d], [%d, %d]", field[maxA][0], field[maxA][1], field[maxB][0], field[maxB][1]);
	getchar();
	getchar();
}
int getDist(int indA, int indB) {
	int ret=0;
	if (field[indA][1] - field[indB][0] < 0|| field[indB][1] - field[indA][0] < 0) {
		return -1;
	}
	if (field[indB][1] - field[indA][0] < field[indA][1]-field[indB][0]) {
		ret = field[indB][1] - field[indA][0];
	}
	else {
		ret = field[indA][1] - field[indB][0];
	}
	return ret;
}