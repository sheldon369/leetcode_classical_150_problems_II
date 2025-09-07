#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
//�������������е�һ���������֡�

//��1����̬�滮,f(i) = max(f(i-1)+nums(i),nums(i)),�����㷨������׸��
//��2�����Σ��߶���������һ������ get(a, l, r) ��ʾ��ѯ a ���� [l,r] �����ڵ�����Ӷκͣ��÷��ɶ����ݽ����޸ģ����Ҳ�ѯ�����Ӷ�
//����һ������ [l,r]������ȡ m= (l + r)/2,������[l, m] ��[m + 1, r] ������⡣���ݹ��������ֱ�����䳤����СΪ 1 ��ʱ�򣬵ݹ顸��ʼ��������

//����һ������[l, r]�����ǿ���ά���ĸ�����
//lSum ��ʾ[l, r] ���� l Ϊ��˵������Ӷκ�
//rSum ��ʾ[l, r] ���� r Ϊ�Ҷ˵������Ӷκ�
//mSum ��ʾ[l, r] �ڵ�����Ӷκ�
//iSum ��ʾ[l, r] �������

class Solution {
public:
    struct Node {//Segment tree
        int iSum;
        int lSum;
        int rSum;
        int mSum;
        Node(int _iSum, int _lSum, int _rSum, int _mSum) :iSum(_iSum), lSum(_lSum), rSum(_rSum), mSum(_mSum) {}
    };
    Node merge(Node a, Node b) {
        int iSum = a.iSum + b.iSum;
        int lSum = max(a.lSum, a.iSum + b.lSum);//���ֶ�ǰ׺�ͣ��������Ӷ�ȫ��+���Ӷ�ǰ׺��
        int rSum = max(b.rSum, b.iSum + a.rSum);
        int mSum = max(max(a.mSum, b.mSum), a.rSum + b.lSum);
        return Node(iSum, lSum, rSum, mSum);
    }

    Node get(const vector<int>& nums, int l, int r) {
        if (l == r)
            return Node(nums[l], nums[l], nums[l], nums[l]);
        int mid = (l + r) / 2;
        Node a = get(nums, l, mid);
        Node b = get(nums, mid + 1, r);
        return merge(a, b);
    }


    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;

    }
};





