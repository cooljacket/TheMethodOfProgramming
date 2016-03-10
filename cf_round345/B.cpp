#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

const int MAX_BEAUTY = 1005;

int main() {
	int n;
	scanf("%d", &n);
	int* beauty = new int[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &beauty[i]);

	vector<int> cnt(MAX_BEAUTY);
	for (int i = 0; i < n; ++i)
		++cnt[beauty[i]];

	vector<int> num;
	for (int i = 0; i < MAX_BEAUTY; ++i)
		if (cnt[i] != 0)
			num.push_back(cnt[i]);

	int size = num.size(), ans = 0;
	while (size > 0) {
		int minN = MAX_BEAUTY, add = 0;
		for (int i = 0; i < num.size(); ++i)
			if (num[i] > 0 && num[i] < minN)
				minN = num[i];
		for (int i = 0; i < num.size(); ++i) {
			if (num[i] > 0) {
				num[i] -= minN;
				++add;
				if (num[i] == 0)
					--size;
				// printf("i=%d, num[i]=%d, minN=%d\n", i, num[i], minN);
			}
		}

		// printf("size=%d, add=%d, ans=%d\n", size, add, ans);
		ans += (add - 1) * minN;
	}

	printf("%d\n", ans);

	return 0;
}