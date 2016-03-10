#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

void str_out(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
		printf("%c", str[i]);
	printf("\n");
}

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

void CalcAllPermutation(char* perm, int from, int to) {
	if (to <= 1)
		return ;
	if (from == to-1) 
		str_out(perm);
	else {
		for (int j = from; j < to; ++j) {
			swap(perm[from], perm[j]);
			CalcAllPermutation(perm, from+1, to);
			swap(perm[from], perm[j]);
		}
	}
}

int main() {
	char str[] = "1234";
	CalcAllPermutation(str, 0, strlen(str));
	return 0;
}