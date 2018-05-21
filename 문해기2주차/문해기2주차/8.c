#include <stdio.h>

int main(void) {
	int minA, minB, maxA, maxB;
	//입력
	scanf_s("%d %d %d %d", &minA, &maxA, &minB, &maxB);
	//유효성검사
	if (minA > maxA || minB > maxB) printf("Input error\n");
	//확인 및 출력
	else if (minB > maxA || maxB < minA) printf("No\n");
	else printf("Yes\n");
}