#include <stdio.h>
#define MIN_INT -9999999;
int main() {
	int max = MIN_INT;
	int sec = MIN_INT;
	while (1) {
		int t;
		scanf_s("%d", &t);
		if (t == -1)break;
		if (t > max) {
			sec = max;
			max = t;
			continue;
		}
		else if (t > sec) {
			sec = t;
			continue;
		}
	}
	printf("%d %d", max, sec);
	getchar();
	getchar();
}