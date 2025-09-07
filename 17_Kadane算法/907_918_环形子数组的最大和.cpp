#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//����һ������Ϊ n �Ļ����������� nums ������ nums �ķǿ� ������ �������ܺ� ��

//��������������£� �����ܺ�������������е�ȫ��Ԫ��
//֮���Բ��ܰ�������Ԫ�أ�����Ϊ������ڸ������κ�һ�����䶼�ܽ����������Ϊ�����֣���������ĺ͹̶����ʵ�һ��ȡ������ʱ����һ�α�Ȼȡ����С��
//�����������ǻ�������[0,n-1]�е����ͣ��Լ�[1,n-2]��С�ͣ��ٳ����ߣ����������β�������ֵ�����

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
  
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int sum = 0;
        int pre = 0;
        int maximum = nums[0];
        for (int i = 0;i < n;i++) {
            sum += nums[i];
            pre = max(nums[i], pre + nums[i]);
            maximum = max(pre, maximum);
        }
        pre = 0;
        int minimum = nums[1];
        for (int i = 1;i < n - 1;i++) {
            pre = min(nums[i], pre + nums[i]);
            minimum = min( pre , minimum);
        }
        return max( maximum , sum - minimum);

    }
};