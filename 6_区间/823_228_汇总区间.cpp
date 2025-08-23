#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//����һ��  ���ظ�Ԫ�� �� ���� �������� nums ������[a, b] �Ǵ� a �� b�������������������ļ��ϡ�
//���� ǡ�ø����������������� �� ��С���� ���䷶Χ�б� ��
//Ҳ����˵��nums ��ÿ��Ԫ�ض�ǡ�ñ�ĳ�����䷶Χ�����ǣ����Ҳ���������ĳ�����䵫������ nums ������ x ��

//������nums�Ѿ�������ֻ��Ҫ������һ��Ԫ���Ƿ���ǰһ��Ԫ�صĺ�̣�
//������ǽ�ǰһ��Ԫ��д��ǰһ�����䣬��Ԫ��д����һ�εĿ�ͷ����β�����ж�һ��

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string s{};
        int length = 0;
        int i = 0;
        while (i < nums.size()) {
            if (length == 0) {
                s = to_string(nums[i]);
                length++;
            }
            else {
                if (nums[i] == nums[i - 1] + 1) {
                    length++;
                }
                else {
                    if (length > 1) {
                        s = s + "->";
                        s = s + to_string(nums[i - 1]);
                    }
                    ans.push_back(s);
                    s.clear();
                    length = 0;
                    i--;//���������i++��ʹ���½���ѭ��
                }
            }
            i++;
        }
        if (nums.size()) {
            if (s != to_string(nums[nums.size() - 1])) {
                s = s + "->";
                s = s + to_string(nums[nums.size() - 1]);
            }
            ans.push_back(s);
            s.clear();

        }


        return ans;



    }
};