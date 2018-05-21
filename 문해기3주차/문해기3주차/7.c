#include <stdio.h>
#define MAX_INT 9999999
int main() {
	int before1 = MAX_INT, before2 = MAX_INT, now = 0, count = 0;
	while (1) {
		int t;
		scanf_s("%d", &t);
		if (t == -1)break;
		now = t;
		if (before2 <= before1 && before2 <= now) {
			count += 1;
		}
		before1 = before2;
		before2 = now;
	}
	if (before2 <= before1) {
		count += 1;
	}
	printf("%d", count);
	getchar();
	getchar();
}