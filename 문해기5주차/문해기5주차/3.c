#include <stdio.h>
#include <math.h>

int main() {
	int N;
	float field[100], sum = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%f", &field[i]);
		sum += field[i];
	}
	float avg = sum / N,sD=0;
	for (int i = 0; i < N; i++) {
		sD += pow(avg - field[i], 2);
	}
	sD=sqrt(sD / N);
	printf("%6f, %6f",avg,sD);
	getchar();
	getchar();
}