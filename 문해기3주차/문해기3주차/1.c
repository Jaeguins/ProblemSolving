#include <stdio.h>
int main() {
	int odd = 0, even = 0, count = 0;
	do{
		int t;
		scanf_s("%d",&t);
		count += 1;
		if (t % 2) {
			odd += t;
		}
		else {
			even += t;
		}
	} while (odd != even);
	printf("%d", count);
	getchar();
	getchar();
}