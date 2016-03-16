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

vector<EType> Select_K_Small_Number(vector<EType>& data, int K) {
	sort(data.begin(), data.end());
	return vector<EType>(data.begin(), data.begin()+K);
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