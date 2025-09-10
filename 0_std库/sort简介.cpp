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
	//���캯�� �򻯳�ʼ���Ĺ���
	//���캯�� ������ڲ� ���ֺ�����һ�� û�з���ֵ
	Complex(int _re, int _im) {
		re = _re;
		im = _im;
	}
};
// �Զ���һ�� < ����� �������������
// ���� < ԭ����С�ں� ���������� ����ֵ��bool
// �Զ���һ������ �����������䣬����ֵ���Ͳ��䣬������operator �����
// ��a<b ����true �����
// ��a<b ����false С����
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
	// ���� < �����
	bool operator < (const Project& other) const {
		return capital < other.capital; // Ĭ�ϰ� capital ����
	}
};


int main() {
	//sortĬ��ʹ�� < �Ƚϣ���Ĭ��Ϊ����
	int arr[6] = { 2,4,6,1,3,5 };
	sort(arr, arr + 6);//sort��һ����������ʼ��ַ���ڶ������������һ��Ԫ�صĺ�һ��λ�õĵ�ַ

	vector<int> vec = { 2,4,6,1,3,5 };
	sort(vec.begin(), vec.end());

	//��vector�������Ϊ����
	sort(vec.begin(), vec.end(), compare);//ע�⣬compare�����ǳ�Ա��������������д������

	return 0;
}
