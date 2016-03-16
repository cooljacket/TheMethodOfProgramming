#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef int EType;

void genData(vector<EType>& v, int MAX = -1) {
	srand(time(NULL));

	for (int i = 0; i < v.size(); ++i) {
		v[i] = rand();
		if (MAX > 0)
			v[i] = v[i] % MAX;
	}
}

// 模拟插入排序的过程，然后只保留前K个就好啦
// 时间复杂度：O(nK)
vector<EType> Select_K_Small_Number(vector<EType>& data, int K) {
	for (int i = 1; i < data.size(); ++i) {
		int insert = min(i, K) - 1;
		int now = data[i];
		while (insert >= 0 && now < data[insert]) {
			data[insert+1] = data[insert];
			--insert;
		}
		data[++insert] = now;
	}
}

void display(const vector<EType>& v) {
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n\n");
}

int main() {
	vector<EType> v(30);
	genData(v, 100);

	display(v);

	int K = 10;
	v = Select_K_Small_Number(v, K);

	display(v);

	return 0;
}