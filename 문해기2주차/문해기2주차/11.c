#include <stdio.h>
int main() {
	int startX, startY, middleX, middleY, endX, endY;
	int isInError = 0;
	int inDir = 0, outDir = 0;//1:��,2:����,3:�Ʒ�,4:������
	//�Է�
	scanf_s("%d %d", &startX, &startY);
	scanf_s("%d %d", &middleX, &middleY);
	scanf_s("%d %d", &endX, &endY);
	//�Է� ��ȿ���˻�
	if ((startX != middleX && startY != middleY)|| (middleX != endX && middleY != endY)) isInError = 1;
	else {//ó�� �Է� ���� ���ϱ�
		if (startX == middleX) {
			if (startY > middleY) inDir = 3;
			else inDir = 1;
		}
		else {
			if (startY > middleY) inDir = 2;
			else inDir = 4;
		}//���� �Է� ���� ���ϱ�
		if (middleX == endX) {
			if (startY > middleY) outDir = 2;
			else outDir = 1;
		}
		else {
			if (middleY > endY) outDir = 3;
			else outDir = 4;
		}
	}
	//�� ������ ���� ȸ�� ��� �� ���
	if(isInError==1) printf("Input error");
	else if (inDir == outDir) printf("U-turn");
	else if (inDir%2 == outDir%2) printf("Straight");
	else if ((inDir + 1) % 4 == outDir % 4) printf("Left");
	else if ((inDir - 1) % 4 == outDir % 4) printf("Right");

}