#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int arr[6] = { 2,4,6,1,3,5 };
	priority_queue<int> myPQueue;//�����
	for (int i = 0; i < 6; i++) {		myPQueue.push(arr[i]);
		printf("top = %d\n", myPQueue.top());
	}
	while (myPQueue.empty() == false) {
		printf("top = %d\n", myPQueue.top());
		myPQueue.pop();
	}

	//����ʵ��С����
	//��һ������Ԫ��ȫ��Ϊ�������ڴ洢����Ԫ�صĸ�ֵ��������ԽС��ֵԽ��
	//���������������
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;//Ĭ�����ȶ���ʹ�õıȽϺ���Ϊ std::less<typename Container::value_type>����Ϊgreater����
	for (int i = 0; i < 6; i++) {
		minHeap.push(arr[i]);
	}





}