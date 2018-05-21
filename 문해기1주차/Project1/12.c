#include<stdio.h>
int main() {
	float sum = 0;
	for (int i = 1; i <= 10; i++) {
		int tmp;
		scanf_s("%d", &tmp);
		sum += tmp;
		float avg = sum / i;
		printf("%f\n",avg);
	}
	getchar();
	getchar();
}