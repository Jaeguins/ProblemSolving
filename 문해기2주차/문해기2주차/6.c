#include <stdio.h>

int main() {
	int date[2];
	//�Է� 8�ڸ� int�� �Է�-ex) 2018�� 3�� 19�� : 20180319 (�� ������ �켱������ �ڸ����� ����)
	for (int i = 0; i < 2; i++) {
		for (int j = 10000; j >= 1; j /= 100) {
			int t;
			scanf_s("%d", &t);
			date[i] += (t*j);
		}
	}
	//��
	int result = date[0] - date[1] > 0;
	if (result>0) printf("1");
	else if (result == 0) printf("0");
	else printf("-1");
}