#include <stdio.h>

int main() {
	int date[2];
	//입력 8자리 int로 입력-ex) 2018년 3월 19일 : 20180319 (각 단위의 우선순위를 자릿수로 결정)
	for (int i = 0; i < 2; i++) {
		for (int j = 10000; j >= 1; j /= 100) {
			int t;
			scanf_s("%d", &t);
			date[i] += (t*j);
		}
	}
	//비교
	int result = date[0] - date[1] > 0;
	if (result>0) printf("1");
	else if (result == 0) printf("0");
	else printf("-1");
}