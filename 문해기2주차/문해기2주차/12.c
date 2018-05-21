#include <stdio.h>
int main() {
	int N;
	int Straight = 0, Left = 0, Right = 0, Uturn = 0, formerX, formerY, laterX, laterY;
	int isInError = 0;
	int inDir = 0, outDir = 0;//1:위,2:왼쪽,3:아래,4:오른쪽
	//입력
	scanf_s("%d", &N);
	scanf_s("%d %d", &formerX, &formerY);
	scanf_s("%d %d", &laterX, &laterY);
	//입력 유효성 검사
	if (formerX != laterX && formerY != laterY) {
		isInError = 1;
	}
	else {//처음 입력값 방향 구하기
		if (formerX == laterX) {
			if (formerY > laterY) inDir = 3;
			else inDir = 1;
		}
		else {
			if (formerX > laterX) inDir = 2;
			else inDir = 4;
		}
	}
	formerX = laterX;
	formerY = laterY;
	for (int n = 0; n < N - 2; n++) {//향후 입력값 방향 구하기
		scanf_s("%d %d", &laterX, &laterY);
		if (formerX != laterX && formerY != laterY) isInError = 1;
		else {
			if (formerX == laterX) {
				if (laterY > formerY) outDir = 1;
				else outDir = 3;
			}
			else {
				if (formerX > laterX) outDir = 2;
				else outDir = 4;
			}
		}
		//입력값 비교를 통한 회전방향 계산
		if (isInError == 1) break;
		else if (inDir == outDir) Straight += 1;
		else if ((inDir+2) % 4 == outDir % 4) Uturn += 1;
		else if ((inDir + 1) % 4 == outDir % 4) Left += 1;
		else if ((inDir - 1) % 4 == outDir % 4) Right += 1;
		inDir = outDir;
		formerX = laterX;
		formerY = laterY;
	}
	//출력
	if (isInError == 1) {
		printf("Input error");
	}
	else {
		printf("%d %d %d %d", Left,Straight,Right,Uturn);
	}
	getchar();
	getchar();
}