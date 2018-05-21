#include <stdio.h>

int main() {
	int N= 0,formerX = 0, formerY = 0, dist = 0, isInError = 0;
	//입력
	scanf_s(" %d", &N);
	scanf_s(" %d %d", &formerX, &formerY);
	for (int i = 0; i < N - 1; i++) {

		int tmpX, tmpY;
		//추가입력
		scanf_s(" %d %d", &tmpX, &tmpY);
		//추가입력 유효성검사
		if (tmpX != formerX && tmpY != formerY) {
			isInError = 1;
			break;
		}
		else if (tmpX == formerX) {//X좌표가 같을떄
			int tmpAdd = formerY - tmpY;
			if (tmpAdd < 0)tmpAdd *= -1;
			dist += tmpAdd;
			formerX = tmpX;
			formerY = tmpY;
		}
		else if (tmpY == formerY) {//Y좌표가 같을때
			int tmpAdd = formerX - tmpX;
			if (tmpAdd < 0)tmpAdd *= -1;
			dist += tmpAdd;
			formerX = tmpX;
			formerY = tmpY;
		}
	}
	//출력
	if (!isInError) {
		printf("%d\n", dist);
	}
	else {
		printf("Input error\n");
	}
}