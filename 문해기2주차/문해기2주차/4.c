#include <stdio.h>
int main() {
	//�ʱ�ȭ-�ּڰ��� ���� �ʱ�ȭ�� int������ �ִ��� ū������
	int min = 2147483647;
	for (int i = 0; i < 10; i++) {
		//�Է�
		int t;
		scanf_s("%d", &t);
		//��g6 
		if (t < 0) continue;
		else if (t < min) min = t;
	}//���
	printf("%d", min);
}