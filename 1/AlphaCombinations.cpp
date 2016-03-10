#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

typedef char EType;
typedef vector<EType> CombinationType;

void print(const CombinationType& v) {
	printf("(%c", v[0]);
	for (int i = 1; i < v.size(); ++i)
		printf(",%c", v[i]);
	printf(")");
}

void display(const vector<CombinationType>& v) {
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		print(v[i]);
		char ch = (i == len-1) ? '\n' : ',';
		printf("%c", ch);
	}
}

CombinationType merge(const CombinationType& a, const CombinationType& b) {
	CombinationType ab;
	int len = a.size();
	for (int i = 0; i < len-1; ++i) {
		if (a[i] != b[i]) 
			return CombinationType();
		ab.push_back(a[i]);
	}
	ab.push_back(min(a[len-1], b[len-1]));
	ab.push_back(max(a[len-1], b[len-1]));

	return ab;
}

void generate() {
	vector<CombinationType> v[2];
	int last = 0, cnt = 1;
	for (char ch = 'a'; ch <= 'z'; ++ch)
		v[last].push_back(CombinationType(1, ch));
	display(v[last]);

	while (cnt++ < 26) {
		int now = 1 - last;
		v[now].clear();
		for (int i = 0; i < v[last].size(); ++i)
			for (int j = i+1; j < v[last].size(); ++j) {
				CombinationType ab = merge(v[last][i], v[last][j]);
				if (ab.empty())
					continue;
				v[now].push_back(ab);
			}

		display(v[now]);
		last = now;
	}
}


int main() {
	generate();

	return 0;
}