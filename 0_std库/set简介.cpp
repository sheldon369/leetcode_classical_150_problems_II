#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector> 
#include <set> 
#include <unordered_set>
using namespace std;

//set�Զ����򣬵ײ��Ǻ������unordered_set��ʵ��O��1��ʱ��Ĳ�ѯ
//set��map�÷�����һ��
int main() {
	//����
	set<int> set1 = { 1,3,5 };
	multiset<int> set2 = { 1,3,5,1,3,5 };
	unordered_set<int> set3 = { 2,4,6 };
	unordered_multiset<int> set4 = { 2,4,6,2,4,6 };

	//����Ԫ��
	set1.insert(2);
	set1.insert(1);//set�������ظ������Ը������Ч  ����>set������ȥ��
	set2.insert(2);
	set2.insert(1);//multiset�����ظ����������Ч

	//ɾ��Ԫ��(����Ҫʹ�õ�����ָ����λ��)
	set1.erase(1);
	set2.erase(2);//���е�1����ɾ����

	//����set4
	unordered_multiset<int>::iterator it;
	for (it = set4.begin(); it != set4.end(); it++) {
		printf("%d ", *it);
	}

	//����
	//find ����Ԫ��λ�ã�����ֵΪ�����������Ҳ�������β�����������������ûʲô�ã���Ϊset�����Ĵ洢λ��
	if (set3.find(1) == set3.end()) {
		printf("1 is not in set\n");
	}
	else {
		printf("1 is in set\n");
	}
	//count ��ȡԪ�����������ڲ���Ԫ��
	printf("2 occurs %d times\n", set3.count(2));

	//set������ֱ���޸�,�粻�ܰ�set�е�1�ĳ�2��������ɾ���������



}
