#include <stdio.h>
#include <assert.h>
#include <string>
using namespace std;


class MyBitSet
{
	typedef char EType;
	int size;
	EType* data;

	void calIndex(int index, int& key, int& then) {
		key = index / sizeof(EType);
		then = index - key * sizeof(EType);
	}

public:
	MyBitSet(int size): size(size) {
		int len = (size+sizeof(EType)-1)/sizeof(EType);
		data = new EType[len];
		for (int i = 0; i < size; ++i)
			reset(i);
	}

	// set the bit to be 0
	void reset(int index) {
		assert(index >= 0 && index < size);

		int key, then;
		calIndex(index, key, then);
		data[key] &= ~(EType(1) << then);
	}

	// set the bit to be 1
	void set(int index) {
		assert(index >= 0 && index < size);

		int key, then;
		calIndex(index, key, then);
		data[key] |= (EType(1) << then);
	}

	// get the value of the bit
	bool get(int index) {
		assert(index >= 0 && index < size);

		int key, then;
		calIndex(index, key, then);
		return (data[key] & (EType(1) << then)) > 0;
	}

	// a shortcut to get the value of the bit
	bool operator [] (int index) {
		return get(index);
	}

	// transform the data into a string
	string str() {
		string ans(size, '0');
		for (int i = 0; i < size; ++i)
			if (get(i))
				ans[i] = '1';
		return ans;
	}

	// display the data
	void print() {
		printf("%s\n", str().data());
	}
};

int main() {
	int size = 25;
	MyBitSet s(size);

	s.print();
	for (int i = 0; i < size; ++i) {
		s.set(i);
		s.print();
		s.reset(i);
	}

	s.set(4);
	s.set(5);
	s.set(6);
	for (int i = 0; i < size; ++i)
		if (s[i])
			printf("1");
		else
			printf("0");
	printf("\n");

	return 0;
}