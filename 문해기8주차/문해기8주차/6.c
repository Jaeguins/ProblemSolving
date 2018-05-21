#include <stdio.h>

int main() {
	FILE* file;
	fopen_s(&file, "input6.txt", "r");
	int N;
	int field[100][100];
	fscanf_s(file, "%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) fscanf_s(file, "%d", &field[i][j]);
	}
	int check = 1, x = 0, y = 0,tlvl=N-1, lvl = N - 1, direction = 1;
	for (int count=0;count<N*N;count++) {
		printf("%d ", field[y][x]);
		if (tlvl == 0) {
			direction = (direction + 1) % 4;
			if (check) {
				lvl -= 1;
				check = 0; 
			}
			else check = 1;
		}
		switch (direction) {
		case 0:
			y -= 1;
			break;
		case 1:
			x += 1;
			break;
		case 2:
			y += 1;
			break;
		case 3:
			x -= 1;
			break;
		}
		tlvl -= 1;
		if (tlvl < 0) tlvl = lvl;
	}
	getchar();
	getchar();
}