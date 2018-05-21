#include <stdio.h>

int main() {
	int N= 0,formerX = 0, formerY = 0, dist = 0, isInError = 0;
	//�Է�
	scanf_s(" %d", &N);
	scanf_s(" %d %d", &formerX, &formerY);
	for (int i = 0; i < N - 1; i++) {

		int tmpX, tmpY;
		//�߰��Է�
		scanf_s(" %d %d", &tmpX, &tmpY);
		//�߰��Է� ��ȿ���˻�
		if (tmpX != formerX && tmpY != formerY) {
			isInError = 1;
			break;
		}
		else if (tmpX == formerX) {//X��ǥ�� ������
			int tmpAdd = formerY - tmpY;
			if (tmpAdd < 0)tmpAdd *= -1;
			dist += tmpAdd;
			formerX = tmpX;
			formerY = tmpY;
		}
		else if (tmpY == formerY) {//Y��ǥ�� ������
			int tmpAdd = formerX - tmpX;
			if (tmpAdd < 0)tmpAdd *= -1;
			dist += tmpAdd;
			formerX = tmpX;
			formerY = tmpY;
		}
	}
	//���
	if (!isInError) {
		printf("%d\n", dist);
	}
	else {
		printf("Input error\n");
	}
}