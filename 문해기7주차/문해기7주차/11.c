#include <stdio.h>
int combo = 0,precombo=0;
int maxCombo = -1;
int N;
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		int t;
		scanf_s("%d", &t);
		if (t) {
			precombo += 1;
			combo += 1;
			continue;
		}
		else {
			if (precombo > maxCombo) {
				maxCombo = precombo;
			}
			precombo = combo;
			combo = 0;
		}
	}
	if (precombo > maxCombo) {
		maxCombo = precombo;
	}
	precombo = combo;
	combo = 0;
	
	printf("%d", maxCombo+1);
	getchar();
	getchar();
}