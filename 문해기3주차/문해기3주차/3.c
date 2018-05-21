#include <stdio.h>

int getGCD(int x,int y) {
	if (x%y==0) {
		return y;
	}
	else {
		if (x>y) {
			return getGCD(x%y, y);
		}
		else {
			return getGCD(y%x,x);
		}
	}
}
int main() {
	int inX, inY;
	scanf_s("%d %d", &inX, &inY);
	int gcd=getGCD(inX,inY);
	
	printf("%d", gcd);
	getchar();
	getchar();
}