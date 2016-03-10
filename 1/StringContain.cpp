#include <stdio.h>
#include <string>
#include <assert.h>
using namespace std;

inline int toInt(char c) {
	return int(c) + 128;
}

// check if each char in b is also in a
/*
1) a sort of like couting sort
2) 
*/
bool StringContain(const string& a, const string& b) {
	int count[256] = {0};

	for (int i = 0; i < a.size(); ++i)
		++count[toInt(a[i])];

	for (int i = 0; i < b.size(); ++i)
		if (count[toInt(b[i])] == 0)
			return false;

	return true;
}

int main() {
	string a = "hello jacket", b = "hello", c = "jazz";
	assert(StringContain(a, b) == true);
	assert(StringContain(a, c) == false);

	return 0;
}