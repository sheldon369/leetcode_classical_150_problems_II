#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int lhs, int rhs) {
	return lhs >= rhs;
}

struct Complex {
	int re;
	int im;
	//构造函数 简化初始化的过程
	//构造函数 在类的内部 名字和类名一样 没有返回值
	Complex(int _re, int _im) {
		re = _re;
		im = _im;
	}
};
// 自定义一个 < 运算符 ——运算符重载
// 重载 < 原本的小于号 有两个参数 返回值是bool
// 自定义一个函数 参数数量不变，返回值类型不变，名字是operator 运算符
// 若a<b 返回true 大根堆
// 若a<b 返回false 小根堆
bool operator < (Complex lhs, Complex rhs) {
	if (lhs.re * lhs.re + lhs.im * lhs.im < rhs.re * rhs.re + rhs.im * rhs.im) {
		return true;
	}
	else {
		return false;
	}
}

struct Project {
	int capital;
	int profit;
	// 重载 < 运算符
	bool operator < (const Project& other) const {
		return capital < other.capital; // 默认按 capital 升序
	}
};


int main() {
	//sort默认使用 < 比较，故默认为升序
	int arr[6] = { 2,4,6,1,3,5 };
	sort(arr, arr + 6);//sort第一个参数填起始地址，第二个参数填最后一个元素的后一个位置的地址

	vector<int> vec = { 2,4,6,1,3,5 };
	sort(vec.begin(), vec.end());

	//将vector从升序变为降序
	sort(vec.begin(), vec.end(), compare);//注意，compare不能是成员函数，即它不能写在类里

	return 0;
}
