#include<stdio.h>
int main() {
	float input;
	scanf_s("%f", &input);
	long float factorial = 1.0;
	long float inputPow = 1 / input;
	float PM = -1.0;
	long float sinX = input, cosX = 1.0;
	for (int i = 2; i <= 198; i+=2) {
		inputPow /= input;
		factorial /= i;
		cosX += (PM*factorial / inputPow);
		inputPow /= input;
		factorial /= (i + 1);
		sinX += (PM*factorial / inputPow);
		PM *= -1;
		
	}
	printf("SIN X : %f\nCOS X : %f\n", sinX, cosX);
	getchar();
	getchar();
}