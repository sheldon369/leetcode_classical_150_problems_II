#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target�������ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//��������в�����Ŀ��ֵ target������[-1, -1]��
//�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

//���������ֲ������ҵ���Ԫ�أ�����ǰ�������ҷ�Χ
//�����ҵ���һ�����ڵ���target���±�,�Լ���һ������target���±�
//�Ż���ֱ��������Ԫ��target - 0.5, target + 0.5������ʧ��ʱ��l����ָ��Ŀ��ñ������λ��

class Solution {
public:
    //��2��ֱ�Ӳ��ң�ע������㷨�е��б�����
    int binarySearch(vector<int>& nums, int target, bool lower) {//lower���ҪѰ����˵㻹���Ҷ˵�
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;//����
                ans = mid;//����ʱ��¼��ֱ���ݹ���֣�������¼��Ϊ���������ĵ�һ�������һ��Ԫ��
            }
            else {
                left = mid + 1;//����
            }
        }
        return ans;
    }

    int binarySearchVirtual(vector<int>& nums, float target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
        //lΪ����Ԫ��Ӧ�ò����λ��
        //����target - 0.5ʱ,���ָ���׸�target��������Ϊa
        //����target + 0.5ʱ�����ָ���׸�����target������,��Ϊb�����-1�õ�target��ĩβλ��

        //�����target���ڣ�a < b ,���� {a,b-1}


        //��target�����ڣ����ʱa = b,����{-1��-1}

    }



    vector<int> searchRange(vector<int>& nums, int target) {
        return (binarySearchVirtual(nums, target - 0.5) != binarySearchVirtual(nums, target + 0.5)) ?
            vector<int>{binarySearchVirtual(nums, target - 0.5), binarySearchVirtual(nums, target + 0.5) - 1} :
            vector<int>{ -1,-1 };

    }
};