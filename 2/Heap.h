#include <vector>
using namespace std;

// EType表示element type，即堆的元素类型
typedef int EType;

class Heap
{
private:
	vector<EType> data;
	size_t HEAP_SIZE;

	size_t Parent(size_t i);
	size_t Left(size_t i);
	size_t Right(size_t i);

public:
	// 构造函数
	Heap(const vector<EType>& v);

	// 维护最大堆的性质，假设i处的左右子结点都是一个最大堆了
	// 而 i 可能得往下移动才能保持整个堆是最大堆
	void MAX_HEAPIFY(size_t i);

	// 建堆的操作，算法在具体实现时有介绍
	void BUILD_MAX_HEAP();

	// 堆排序
	vector<EType> HEAPSORT();

	// 展示堆的这个数组的数据
	void display();
};