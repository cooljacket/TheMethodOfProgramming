#include <vector>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Heap.h"
using namespace std;


void genData(vector<EType>& v, int MAX = -1) {
	srand(time(NULL));

	for (int i = 0; i < v.size(); ++i) {
		v[i] = rand();
		if (MAX > 0)
			v[i] = v[i] % MAX;
	}
}


int main() {
	vector<EType> v(20);
	genData(v, 15);

	Heap h(v);
	h.display();
	h.HEAPSORT();
	h.display();

	return 0;
}