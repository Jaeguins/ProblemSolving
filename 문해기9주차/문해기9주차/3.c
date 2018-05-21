#include <stdio.h>
int lenOfOverlap(int sa, int ta, int sb, int tb) {
	if (ta < sa) {
		int t = sa;
		sa = ta;
		ta = t;
    }
	if (tb < sb) {
		int t = sb;
		sb = tb;
		tb = t;
	}
	if (sb > ta || tb < sa) return 0;
	else {
		int ret;
		if (tb > ta)ret = ta;
		else ret = tb;
		if (sb > sa)ret -= sb;
		else ret -= sa;
		return ret;
	}
}
int main() {
	int inputs[4][2];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &inputs[i][j]);
		}
	}
	printf("%d", lenOfOverlap(inputs[0][0], inputs[1][0], inputs[2][0], inputs[3][0])*lenOfOverlap(inputs[0][1], inputs[1][1], inputs[2][1], inputs[3][1]));
	getchar();
	getchar();
}
