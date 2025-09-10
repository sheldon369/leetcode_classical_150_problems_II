#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//��λ�������������б��е��м�ֵ������б�Ĵ�С��ż������û���м�ֵ����λ���������м�ֵ��ƽ��ֵ��

//ʵ�� MedianFinder �� :
//MedianFinder() ��ʼ�� MedianFinder ����
//void addNum(int num) ���������е����� num ��ӵ����ݽṹ�С�
//double findMedian() ���ص�ĿǰΪֹ����Ԫ�ص���λ������ʵ�ʴ���� 10 - 5 ���ڵĴ𰸽������ܡ�

//������ά��һ������Ѵ洢С��һ��Ԫ�أ�һ��С���Ѵ洢���һ��Ԫ��
//��һ����n��Ԫ�أ�С�Ĵ�n/2 ��+ 1����Ԫ�أ���Ĵ� n/2 ��Ԫ��
//һ����Ԫ�����С�ڵ���maxHeap.top�������maxHeap,�������minHeap
//�ڴ˹��������ϸ�֤����heap�Ĵ�С��ȷ������ɾ���Ѷ�������һ����

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