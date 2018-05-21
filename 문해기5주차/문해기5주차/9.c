#include <stdio.h>

int main() {
	FILE *file;
	fopen_s(&file,"input9.txt", "r");
	int index=0;
	int tmp,max=-999999999;
	int data[100];
	while (fscanf_s(file, "%d", &tmp) != EOF) {
		if (tmp > max) {
			data[index] = tmp;
			index += 1;
			max = tmp;
		}
	}
	printf("%d: ",index);
	for (int i = 0; i < index; i++) {
		printf("%d ", data[i]);
	}
	getchar();
	getchar();
}