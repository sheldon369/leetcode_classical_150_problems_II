#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
	////����map
	//map<char, int> map1;// ���򣬲�������ظ�
	////map<��,ֵ>
	//multimap<char, int>  map2;//����������ظ�
	//unordered_map<char, int> map3;// ���򣬲������ظ���������ʹ�ã�ʱ�俪��С
	//unordered_multimap<char, int> map4;// ���������ظ�

	//// ��ֵ��
	//pair<char, int> pair1 = {'w',0};
	////first �����  second ���ֵ
	//printf("key = %c,value = %d\n", pair1.first, pair1.second);

	////��map������
	//map1.insert(pair1);
	//map2.insert(pair1);
	//map2.insert({ 'o',1 });

	////��map��ɾ��
	//map1.erase('w');//����ֻ��Ҫ��

	//map�ı���
	map<char, int> map1 = { {'w',0},{'0',1},{'r',2},{'l',3},{'d',4} };
	map<char, int>::iterator it;
	for (it = map1.begin(); it != map1.end(); it++) {
		printf("key = %c,value = %d\n", it->first, it->second);
	}

	//map�Ĳ��ҡ������ݼ�map[i]����ֵ
	printf("value = % d\n", map1['o']);
	printf("value = % d\n", map1['a']);//a�������ڣ���map���Զ�����a����Ĭ�ϳ�ʼֵΪ0

	//�������ʵ�� ���������Զ�������
	if (map1.find('a') == map1.end()) {//���a�����ڣ�endָ�����һ��ֵ�ĺ�һ��λ��
		printf("key is not in map");
	}
	if (!map1.count('a'))//map ͬ��֧��count������count�����find���޷���ȡֵ����Ϣ��ֻ���жϴ�����
		printf("key is not in map");
	else {
		printf("value = % d\n", map1['a']);
	}

	//map���޸�
	map1['o'] = 6;



	//multimap�Ĳ��ҡ���multimap��֧��[]
	//low_bound(key) ����key��Ӧ�ĵ�һ��ֵ��λ�á�����begin
	//upper_bound(key) ����key��Ӧ�����һ��ֵ�ĺ�һ��ֵ��λ�á�����end
	for (it = map1.lower_bound('o'); it != map1.upper_bound('o'); it++) {
		printf("key = %c,value = %d\n", it->first, it->second);
	}


	return 0;
}