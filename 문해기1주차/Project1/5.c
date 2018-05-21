#include <stdio.h>
int main() {
	int N = 0;
	scanf_s("%d", &N);
	int before1=1, before2=1, now=2, after=2;
	for (int i = 3; i < N; i++) {
		before1 = before2;
		before2 = now;
		now = after;
		after = before1 + before2;
	}
	printf("%d", now);
	getchar();
	getchar();
}