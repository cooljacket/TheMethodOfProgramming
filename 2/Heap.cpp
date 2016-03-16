#include <vector>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Heap.h"
using namespace std;


Heap::Heap(const vector<EType>& v) {
	data = vector<EType>(v.size() + 1);
	for (int i = 1; i < data.size(); ++i)
		data[i] = v[i-1];
	HEAP_SIZE = v.size();
	BUILD_MAX_HEAP();
}


void Heap::MAX_HEAPIFY(size_t i) {
	size_t left_index = Left(i), right_index = Right(i);
	size_t largest = i;
	if (left_index <= HEAP_SIZE && data[left_index] > data[largest])
		largest = left_index;
	if (right_index <= HEAP_SIZE && data[right_index] > data[largest])
		largest = right_index;

	if (largest != i) {
		swap(data[i], data[largest]);
		MAX_HEAPIFY(largest);
	}
}


void Heap::BUILD_MAX_HEAP() {
	for (size_t i = HEAP_SIZE/2; i >= 1; --i)
		MAX_HEAPIFY(i);
}


vector<EType> Heap::HEAPSORT() {
	for (size_t i = data.size()-1; i >= 1; --i) {
		swap(data[1], data[i]);
		--HEAP_SIZE;
		MAX_HEAPIFY(1);
	}

	return vector<EType>(data.begin()+1, data.end());
}


size_t Heap::Parent(size_t i) {
	return i >> 1;
}


size_t Heap::Left(size_t i) {
	return i << 1;
}


size_t Heap::Right(size_t i) {
	return (i << 1) + 1;
}


void Heap::display() {
	for (int i = 1; i < data.size(); ++i)
		printf("%d ", data[i]);
	printf("\n\n");
}