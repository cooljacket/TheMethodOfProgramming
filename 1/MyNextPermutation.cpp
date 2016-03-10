#include <stdio.h>
#include <vector>
using namespace std;

typedef char EType;
typedef vector<EType> PermutationType;

void print(const PermutationType& v) {
	for (int i = 0; i < v.size(); ++i)
		printf("%c", v[i]);
	printf("\n");
}

bool myNextPermutaionHelper(PermutationType& v, int beg, int end) {
	if (beg >= end)
		return true;

	int i, j;
	for (i = end-1; i >= beg; --i)
		if (v[i] < v[i+1])
			break;
	if (i < beg)
		return false;

	for (j = end; j > i; --j)
		if (v[j] > v[i])
			break;
	swap(v[i], v[j]);
	
	for (int k = i+1, m = end; k < m; ++k, --m)
		swap(v[k], v[m]);

	return true;
}

bool myNextPermutaion(PermutationType& v) {
	return myNextPermutaionHelper(v, 0, v.size()-1);
}

int main() {
	PermutationType v;
	for (int i = 1; i < 4; ++i)
		v.push_back(char(i+'0'));

	print(v);
	while (myNextPermutaion(v))
		print(v);

	return 0;
}