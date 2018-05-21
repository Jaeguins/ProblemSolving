#include <stdio.h>
#include <time.h>
int main() {
	int field[100][100];
	int N;
	srand(time(NULL));
	scanf_s("%d", &N);
	double count = 0;
	for (int n = 0; n < 10000; n++) {
		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) field[i][j] = 0;
		}
		int x = N / 2, y = N / 2;
		field[x][y] = 1;
		while (1) {
			if (x < 0 || x >= N || y < 0 || y >= N) {
				result = 1;
				break;
			}
			if (field[x][y - 1] == 1 && field[x][y + 1] == 1 && field[x - 1][y] == 1 && field[x + 1][y] == 1) break;
			field[x][y] = 1;
			int tmp = rand() % 4;
			switch (tmp) {//위 오른쪽 아래 왼쪽
			case 0:
				if (field[x][y - 1] == 1) continue;
				else y -= 1;
				break;
			case 1:
				if (field[x + 1][y] == 1) continue;
				else x += 1;
				break;
			case 2:
				if (field[x][y + 1] == 1) continue;
				else y += 1;
				break;
			case 3:
				if (field[x - 1][y] == 1) continue;
				else x -= 1;
				break;
			}
		}
		count += result;
	}
	printf("%f",count / 10000);
	getchar();
	getchar();
}