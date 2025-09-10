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


	template<
		class T,//元素类型
		class Container = std::vector<T>,//底层容器，默认为vector
		class Compare = std::less<typename Container::value_type>//比较方式，默认为<
	> class priority_queue;//一个新元素插入到堆的结尾，若原来的元素小于新元素则交换，因此默认为大根堆

	priority_queue 的第三个模板参数要求传入一个 类型（比较器类），而不是某个函数。
	这个比较器类必须实现 operator()，让它像函数一样被调用。

	struct cmp {
		bool operator()(ListNode* a, ListNode* b) {
			return a->val > b->val;
		}
	};



	//lambda构造法实例参考909_373
	using T = tuple<int, int, int>;//类型别名
	//tuple，元组，get<i>拿到元组中第i个元素
	auto cmp = [](const T& a, const T& b) {
		return get<0>(a) > get<0>(b);
		};
	priority_queue<T, vector<T>, decltype(cmp)> minHeap(cmp);//使用lambda，必须在minHeap 后面写 (cmp)

	//[]中填写外部传入的参数
	auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
		return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
		};


	tuple<int, double, string> t(10, 3.14, "hello");
	cout << get<0>(t) << endl; // 10
	cout << get<1>(t) << endl; // 3.14
	cout << get<2>(t) << endl; // hello






}