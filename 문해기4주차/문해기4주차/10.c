#include <stdio.h>

int getCommon(int aMin,int aMax,int bMin,int bMax) {
	if (aMax < aMin) {
		int t = aMin;
		aMin = aMax;
		aMax = t;
	}
	if (bMax < bMin) {
		int t = bMin;
		bMin = bMax;
		bMax = t;
	}
	if (bMin > aMax || bMax < aMin) return 0;
	else {
		int ret;
		if (bMax > aMax)ret = aMax;
		else ret = bMax;
		if (bMin > aMin)ret -= bMin;
		else ret -= aMin;
		return ret;
	}
}
int main() {
	while (1) {
	int xA1, xA2, yA1, yA2, xB1, xB2, yB1, yB2;
	scanf_s("%d %d %d %d %d %d %d %d", &xA1, &yA1, &xA2, &yA2, &xB1, &yB1, &xB2, &yB2);
	printf("%d\n\n", getCommon(xA1, xA2, xB1, xB2)*getCommon(yA1, yA2, yB1, yB2));
	}
	
	getchar();
	getchar();
}