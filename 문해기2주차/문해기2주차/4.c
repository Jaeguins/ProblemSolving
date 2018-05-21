#include <stdio.h>
int main() {
	//초기화-최솟값을 위해 초기화를 int범위내 최대한 큰값으로
	int min = 2147483647;
	for (int i = 0; i < 10; i++) {
		//입력
		int t;
		scanf_s("%d", &t);
		//비g6 
		if (t < 0) continue;
		else if (t < min) min = t;
	}//출력
	printf("%d", min);
}