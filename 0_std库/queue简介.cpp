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


	template<
		class T,//Ԫ������
		class Container = std::vector<T>,//�ײ�������Ĭ��Ϊvector
		class Compare = std::less<typename Container::value_type>//�ȽϷ�ʽ��Ĭ��Ϊ<
	> class priority_queue;//һ����Ԫ�ز��뵽�ѵĽ�β����ԭ����Ԫ��С����Ԫ���򽻻������Ĭ��Ϊ�����

	priority_queue �ĵ�����ģ�����Ҫ����һ�� ���ͣ��Ƚ����ࣩ��������ĳ��������
	����Ƚ��������ʵ�� operator()����������һ�������á�

	struct cmp {
		bool operator()(ListNode* a, ListNode* b) {
			return a->val > b->val;
		}
	};






}