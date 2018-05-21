#include <stdio.h>

int main()
{
	int field[10];
	for (int i = 0; i < 10; i++) {
		field[i] = 0;
	}
	char input;
	do {
		input = getchar();
		field[input - 48] += 1;
	} while (input != '\n');
	for (int i = 0; i < 10; i++) {
		printf("%d ", field[i]);
	}
	getchar();
	getchar();
}