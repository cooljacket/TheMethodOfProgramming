#include <stdio.h>
#include <string>
using namespace std;

void reverse(string& s, int beg, int end) {
	for (int i = beg, j = end-1; i < j; ++i, --j)
		swap(s[i], s[j]);
}

// shift the first m char to the right side, without breaking the relative order
void LeftRotateString(string& s, int m) {
	int size = s.size(), n = size - m;
	reverse(s, 0, size);
	reverse(s, 0, n);
	reverse(s, n, size);
}

int main() {
	string ori = "abcdefg";
	LeftRotateString(ori, 7);
	printf("%s\n", ori.data());
	return 0;
}