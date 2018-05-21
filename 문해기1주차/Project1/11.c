#include <stdio.h>
int main() {
	int input = 0;
	scanf_s("%d", &input);
	for (int i = input; i >= 1; i /= 2) {
		printf("%d\n", i);
	}
	getchar();
	getchar();
}