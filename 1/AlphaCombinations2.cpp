#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

typedef char EType;
typedef vector<EType> CombinationType;
const EType MAX = 'z';

void print(const CombinationType& v) {
	printf("(%c", v[0]);
	for (int i = 1; i < v.size(); ++i)
		printf(",%c", v[i]);
	printf(")");
}

bool nextOne(CombinationType& v, int pos, int size) {
	if (pos == -1)
		return false;
	if (v[pos] == MAX-(size-pos-1))
		return nextOne(v, pos-1, size);
	++v[pos];
	for (int i = pos+1; i < size; ++i)
		v[i] = v[i-1] + 1;
	return true;
}

void genHelper(int size) {
	CombinationType v(size);
	for (int i = 0; i < size; ++i)
		v[i] = 'a' + i;
	print(v);

	while (nextOne(v, v.size()-1, size)) {
		printf(",");
		print(v);
	}
	printf("\n");
}

void generate() {
	for (int i = 1; i <= 26; ++i) {
		genHelper(i);
		// int aaa; cin >> aaa;
	}
}


int main() {
	generate();
	return 0;
}