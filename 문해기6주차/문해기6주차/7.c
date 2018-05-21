#include <stdio.h>

int main() {
	int A, B,arrA[20],arrB[20],lengA=-1,lengB=-1;
	scanf_s("%d %d", &A, &B);
	int tA = A, tB = B;
	for(int i=0;;i++) {
		arrA[i] = tA % 10;
		lengA += 1;
		tA /= 10;
		if (tA == 0) break;
	}
	for(int i=0;;i++) {
		arrB[i] = tB % 10;
		lengB += 1;
		tB /= 10;
		if (tB == 0) break;
	}
	int ret = 0;
	while (1) {
		if (arrA[lengA] < arrB[lengB]) {
			ret = 1;
			break;
		}
		else if (arrA[lengA] > arrB[lengB]) {
			ret = -1;
			break;
		}
		else {
			lengA -= 1;
			lengB -= 1;
			continue;
		}
	}
	if (ret == 1) {
		printf("%d %d\n", A, B);
	}
	else {
		printf("%d %d\n", B, A);
	}
	getchar();
	getchar();
}