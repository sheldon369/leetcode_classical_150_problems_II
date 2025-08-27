#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector> //vector不需要.h
using namespace std;
struct MyType {
	int val1;
	double val2;
};
int main() {
	//1.初始化&构造
	//vector<int> vec1;//vector不是类型 vector<type>才是类型
	//vector<int> vec2(100);// vec2 一开始就有100个元素，里面存的全是0
	//vector<double> vec2;
	//vector<MyType> vec3;
	//vector<vector<int>> vec4; // 动态数组的动态数组 二维数组 #不推荐
	//vector<int> arr[10]; //机试推荐的用法 动态数组的静态数组 图算法 邻接表法


	//2.push_back 往动态数组的末尾插入
	/*int a;
	while (scanf("%d", &a) != EOF) {
		vec1.push_back(a);
	}*/

	////3.依下标访问数组,使用vec[]
	//vector<int> vec1 = { 1,3,5,7,9 };
	//int i = 0;
	//printf("vec[i] = %d\n", vec1[i]);

	////4.遍历数组
	//int size = vec1.size();
	//for (int i = 0; i < size; i++) {
	//	printf("vec[%d] = %d\n", i,vec1[i]);
	//}

	//5.迭代器的使用
	vector<int> vec1 = { 1,3,5,7,9 };
	vector<int>::iterator it;//定义迭代器
	/*for (it = vec1.begin(); it != vec1.end(); it++) {
		printf("*it = %d\n",*it);
	}*/

	//6.中间某个位置的插入
	//it = vec1.begin();//迭代器获取元素位置
	//vec1.insert(it, 2);//insert会修改动态数组结构，插入完成后it指向无意义,在it前插入
	//it = vec1.begin();
	//it = it + 3;//it + 3 相当于3次++，但只能在vector中使用——加n相当于下标为n
	//vec1.insert(it, 6);

	//7.数组的删除
	//vec1.clear();//清空所有数据
	//vec1.pop_back();//弹出最后一个元素——推荐 O（1）
	it = vec1.begin() + 2;
	vec1.erase(it);//某位置数组元素的删除


	return 0;
}