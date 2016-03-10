#include <stdio.h>
#include <cmath>
using namespace std;

int cal(int a, int b) {
	return abs((a+1) - (b-2));
}


int simulate(int a1, int a2) {
	int time = 0;
	while (a1 > 0 && a2 > 0 && a1+a2 > 2) {
		int x = cal(a1, a2);
		int y = cal(a2, a1);
		if (x <= y) {
			++a1;
			a2 -= 2;
		} else {
			++a2;
			a1 -= 2;
		}

		++time;
	}

	return time;
}

int main() {
	int a1, a2;
	scanf("%d%d", &a1, &a2);
	printf("%d\n", simulate(a1, a2));

	return 0;
}