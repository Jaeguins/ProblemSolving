#include <stdio.h>
#include <math.h>
int main() {
	int field[100][100];
	FILE *file;
	fopen_s(&file, "input4.txt", "r");
	int N;
	fscanf_s(file, "%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {fscanf_s(file, "%d", &field[i][j]);
	}
	fclose(file);
	float rowAvg[100], colAvg[100], rowDev[100], colDev[100];
	for (int i = 0; i < N; i++) {
		float rowSum = 0, colSum = 0;
		float rowT = 0, colT = 0;
		for (int j = 0; j < N; j++) {
			rowSum += field[i][j];
			colSum += field[j][i];
		}
		rowAvg[i] = rowSum / N;
		colAvg[i] = colSum / N;
		for (int j = 0; j < N; j++) {
			rowT += (field[i][j] - rowAvg[i])*(field[i][j] - rowAvg[i]);
			colT += (field[j][i] - colAvg[i])*(field[j][i] - colAvg[i]);
		}
		rowDev[i] = sqrt(rowT / N);
		colDev[i] = sqrt(colT / N);
	}
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			if (i < N&&j < N) printf("%d ", field[i][j]);
			else if(j==N&&i<N) {printf("%f ", rowAvg[i]);
			else if (j == N + 1&&i<N) printf("%f ", rowDev[i]);
			else if(i==N && j<N) printf("%f ", colAvg[j]);
			else if (i == N + 1 && j<N) printf("%f ", colDev[j]);
			else continue;
		}
		printf("\n");
	}
	getchar();
	getchar();
}