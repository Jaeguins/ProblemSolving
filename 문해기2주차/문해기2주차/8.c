#include <stdio.h>

int main(void) {
	int minA, minB, maxA, maxB;
	//�Է�
	scanf_s("%d %d %d %d", &minA, &maxA, &minB, &maxB);
	//��ȿ���˻�
	if (minA > maxA || minB > maxB) printf("Input error\n");
	//Ȯ�� �� ���
	else if (minB > maxA || maxB < minA) printf("No\n");
	else printf("Yes\n");
}