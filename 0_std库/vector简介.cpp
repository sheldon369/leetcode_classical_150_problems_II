#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector> //vector����Ҫ.h
using namespace std;
struct MyType {
	int val1;
	double val2;
};
int main() {
	//1.��ʼ��&����
	//vector<int> vec1;//vector�������� vector<type>��������
	//vector<int> vec2(100);// vec2 һ��ʼ����100��Ԫ�أ�������ȫ��0
	//vector<double> vec2;
	//vector<MyType> vec3;
	//vector<vector<int>> vec4; // ��̬����Ķ�̬���� ��ά���� #���Ƽ�
	//vector<int> arr[10]; //�����Ƽ����÷� ��̬����ľ�̬���� ͼ�㷨 �ڽӱ�


	//2.push_back ����̬�����ĩβ����
	/*int a;
	while (scanf("%d", &a) != EOF) {
		vec1.push_back(a);
	}*/

	////3.���±��������,ʹ��vec[]
	//vector<int> vec1 = { 1,3,5,7,9 };
	//int i = 0;
	//printf("vec[i] = %d\n", vec1[i]);

	////4.��������
	//int size = vec1.size();
	//for (int i = 0; i < size; i++) {
	//	printf("vec[%d] = %d\n", i,vec1[i]);
	//}

	//5.��������ʹ��
	vector<int> vec1 = { 1,3,5,7,9 };
	vector<int>::iterator it;//���������
	/*for (it = vec1.begin(); it != vec1.end(); it++) {
		printf("*it = %d\n",*it);
	}*/

	//6.�м�ĳ��λ�õĲ���
	//it = vec1.begin();//��������ȡԪ��λ��
	//vec1.insert(it, 2);//insert���޸Ķ�̬����ṹ��������ɺ�itָ��������,��itǰ����
	//it = vec1.begin();
	//it = it + 3;//it + 3 �൱��3��++����ֻ����vector��ʹ�á�����n�൱���±�Ϊn
	//vec1.insert(it, 6);

	//7.�����ɾ��
	//vec1.clear();//�����������
	//vec1.pop_back();//�������һ��Ԫ�ء����Ƽ� O��1��
	it = vec1.begin() + 2;
	vec1.erase(it);//ĳλ������Ԫ�ص�ɾ��


	return 0;
}