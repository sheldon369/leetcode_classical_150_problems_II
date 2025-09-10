#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//���������� �ǵݼ�˳������ ���������� nums1 �� nums2, �Լ�һ������ k ��
//����һ��ֵ(u, v)�����е�һ��Ԫ������ nums1���ڶ���Ԫ������ nums2 ��
//���ҵ�����С�� k ������(u1, v1), (u2, v2)  ...  (uk, vk) ��

//���������ƹ鲢����ÿ��ȡ����ǰָ��ָ���λ�ã�Ȼ����һλ���н�С��ָ�����λ�ã� --����ָ�벢�����������ƣ��п���һ�����ң���һ������

//ʹ��С���ѣ���ʼʱ�ѶѶ�Ԫ��Ԫ�ط�����У�ÿ�δӶ���ȡ���Ѷ���Ȼ������ڶ��м������������������¼���������Ǳ���ȡ�ĸ�����֮�䲻����û�п��ǹ������



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        using T = tuple<int, int, int>;//ʹ�� T ��ָĳ����
        auto cmp = [](const T& a, const T& b) {
            return get<0>(a) > get<0>(b);
            };
        priority_queue<T, vector<T>, decltype(cmp)> minHeap(cmp);
        minHeap.push({ nums1[0] + nums2[0],0,0,});

        set<pair<int,int>> isVisited;
        //isVisited.insert({ 0,0 });
        while (!minHeap.empty() && k > 0) {

            auto cur = minHeap.top();
            res.push_back({ nums1[get<1>(cur)],nums2[get<2>(cur)] });
            minHeap.pop();
            k--;
            if (get<1>(cur) + 1 < nums1.size() && !isVisited.count({ get<1>(cur) + 1 , get<2>(cur) })) {
                minHeap.push({ nums1[get<1>(cur) + 1] + nums2[get<2>(cur)],get<1>(cur) + 1 ,get<2>(cur) });
                isVisited.insert({ get<1>(cur) + 1 , get<2>(cur) });

            }
     
            if (get<2>(cur) + 1 < nums2.size() && !isVisited.count({ get<1>(cur)  , get<2>(cur) + 1 })) {
                minHeap.push({ nums1[get<1>(cur)] + nums2[get<2>(cur) + 1],get<1>(cur) ,get<2>(cur) + 1 });
                isVisited.insert({ get<1>(cur) , get<2>(cur) + 1 });


            }
               
        }

        return res;

    }
};

int main() {
    vector<int> nums1{ 1,7,11 };
    vector<int> nums2{ 2,4,6 };
    Solution sol;
    sol.kSmallestPairs(nums1,nums2, 3);
}