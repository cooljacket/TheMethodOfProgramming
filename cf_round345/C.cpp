#include <stdio.h>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<int, int> PAIR;

inline LL cal(LL x) {
	return x*(x-1) / 2;
}

LL count(map<int, int>& m) {
	LL ans = 0;
	map<int, int>::iterator it = m.begin();
	while (it != m.end()) {
		ans += cal(it->second);
		++it;
	}

	return ans;
}

int main() {
	int n, x, y;
	scanf("%d", &n);
	map<int, int> px, py;
	map<PAIR, int> pxy;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		++px[x];
		++py[y];
		++pxy[make_pair(x, y)];
	}

	LL ans = count(px) + count(py);
	map<PAIR, int>::iterator it = pxy.begin();
	while (it != pxy.end()) {
		if (it->second > 1)
			ans -= cal(it->second);
		++it;
	}

	printf("%I64d\n", ans);

	return 0;
}