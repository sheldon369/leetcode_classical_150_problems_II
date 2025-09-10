#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

//实现 MedianFinder 类 :
//MedianFinder() 初始化 MedianFinder 对象。
//void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
//double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10 - 5 以内的答案将被接受。

//分析：维护一个大根堆存储小的一半元素，一个小根堆存储大的一半元素
//设一共有n个元素，小的存n/2 （+ 1）个元素，大的存 n/2 个元素
//一个新元素如果小于等于maxHeap.top，则存入maxHeap,否则存入minHeap
//在此过程中需严格保证两个heap的大小正确，否则删除堆顶加入另一个堆

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = 0;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        ++n;
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }
        if (num <= maxHeap.top()) {
            maxHeap.push(num);
            if (maxHeap.size() > (n % 2 ? n / 2 + 1 : n / 2)) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else {
            minHeap.push(num);
            if (minHeap.size() > n/2) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    double findMedian() {
        if (n % 2)
            return maxHeap.top();
        else
            return (static_cast<double> (maxHeap.top()) + static_cast<double> (minHeap.top())) / 2;

    }
};