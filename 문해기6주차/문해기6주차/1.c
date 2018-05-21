#include <stdio.h>
int field[100];
void push(int val, int ind, int length, int field[]) {
	for (int i = length - 1; i >= ind; i--) {
		field[i + 1] = field[i];
	}
	field[ind] = val;
}
int main() {
	int input, length = 1;
	scanf_s("%d", &input);
	field[0] = input;
	for (int j = 0; j < length; j++) {
		printf("%d ", field[j]);
	}
	printf("\n");
	scanf_s("%d", &input);
	while (input != -1) {
		for (int i = 0; i < length; i++) {
			if (field[i] > input) {
				push(input, i, length, field);
				length += 1;
				for (int j = 0; j < length; j++) {
					printf("%d ", field[j]);
				}
				printf("\n");
				break;
			}
			else if(field[i]==input) {
				printf("duplicate entry\n");
				break;
			}
		}
		scanf_s("%d", &input);
	}
	getchar();
	getchar();
}