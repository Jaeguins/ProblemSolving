#include <stdio.h>
int main() {
	int input = 0;
	scanf_s("%d", &input);
	float ret = 1.00;
	float lvl = 1.00;
	for (int i = 0; i < input;i++) {
		lvl = lvl / -2;
		ret =ret+lvl;
	}
	printf("%f",ret);
	getchar();
	getchar();
}

