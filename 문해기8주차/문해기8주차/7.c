#include <stdio.h>
int N,max=0,count=0;
int field[1000000];
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &field[i]);
		if (field[i] > max) max = field[i];
	}
	for (int i = 0; i < max; i++) {
		int isStart = 0,firstInd=0,lastInd = 0, numOfWall = 0;
		for (int j = 0; j < N; j++) {
			if (field[j] >= i) {
				if (!isStart) {
					isStart = 1;
					firstInd = j;
				}
				else {
					numOfWall += 1;
					lastInd = j;
				}

			}
		}
		count += (lastInd - numOfWall-firstInd);
	}
	printf("%d", count);
	getchar();
	getchar();
}