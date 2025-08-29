#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int arr[6] = { 2,4,6,1,3,5 };
	priority_queue<int> myPQueue;//大根堆
	for (int i = 0; i < 6; i++) {		myPQueue.push(arr[i]);
		printf("top = %d\n", myPQueue.top());
	}
	while (myPQueue.empty() == false) {
		printf("top = %d\n", myPQueue.top());
		myPQueue.pop();
	}

	//若想实现小根堆
	//法一：堆内元素全都为正，堆内存储所有元素的负值，则正数越小负值越大
	//法二：运算符重载
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;//默认优先队列使用的比较函数为 std::less<typename Container::value_type>，改为greater即可
	for (int i = 0; i < 6; i++) {
		minHeap.push(arr[i]);
	}





}