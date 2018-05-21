#include <stdio.h>
int main() {
	int startX, startY, middleX, middleY, endX, endY;
	int isInError = 0;
	int inDir = 0, outDir = 0;//1:위,2:왼쪽,3:아래,4:오른쪽
	//입력
	scanf_s("%d %d", &startX, &startY);
	scanf_s("%d %d", &middleX, &middleY);
	scanf_s("%d %d", &endX, &endY);
	//입력 유효성검사
	if ((startX != middleX && startY != middleY)|| (middleX != endX && middleY != endY)) isInError = 1;
	else {//처음 입력 방향 구하기
		if (startX == middleX) {
			if (startY > middleY) inDir = 3;
			else inDir = 1;
		}
		else {
			if (startY > middleY) inDir = 2;
			else inDir = 4;
		}//나중 입력 방향 구하기
		if (middleX == endX) {
			if (startY > middleY) outDir = 2;
			else outDir = 1;
		}
		else {
			if (middleY > endY) outDir = 3;
			else outDir = 4;
		}
	}
	//두 방향을 통해 회전 계산 및 출력
	if(isInError==1) printf("Input error");
	else if (inDir == outDir) printf("U-turn");
	else if (inDir%2 == outDir%2) printf("Straight");
	else if ((inDir + 1) % 4 == outDir % 4) printf("Left");
	else if ((inDir - 1) % 4 == outDir % 4) printf("Right");

}