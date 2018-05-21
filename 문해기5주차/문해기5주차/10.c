#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	FILE *file = fopen("input10.txt", "r");
	int inputStream[101];
	int i = 0;
	int acquire = 0;
	int before;
	fscanf_s(file, "%d", &before);
	while (fscanf_s(file, "%d", &inputStream[i]) != EOF) {
		if (inputStream[i] > before) {
			acquire += (inputStream[i] - before);
		}
		before = inputStream[i];
		i++;
	}
	
	printf("%d", acquire);
	fclose(file);
	getchar();
	getchar();
}