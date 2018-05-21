#include <stdio.h>
int main() {
	float remain = 0.00;
	float add = 0.00;
	scanf_s("%f", &add);
	add += 1.00;
	for (int i = 0; i < 12; i++) {
		int tmpIn;
		scanf_s("%d", &tmpIn);
		remain += tmpIn;
		remain *= add;
		printf("%f\n", remain);
	}
	getchar();
	getchar();
}