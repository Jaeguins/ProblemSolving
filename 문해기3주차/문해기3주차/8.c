#include <stdio.h>

int input;
float tax = 0;
void calc(int base, float taxRate) {
	if (input <= base) {
		tax += input * taxRate;
		input = 0;
	}
	else {
		tax += base * taxRate;
		input -= base;
	}
}
int main() {
	scanf_s("%d", &input);
	calc(12000000, 0.06);
	calc(34000000, 0.15);
	calc(42000000, 0.24);
	calc(62000000, 0.35);
	calc(350000000, 0.38);
	tax += input * 0.4;
	printf("%f", tax);
	getchar();
	getchar();
}