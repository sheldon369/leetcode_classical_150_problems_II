#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//给定一个  无重复元素 的 有序 整数数组 nums 。区间[a, b] 是从 a 到 b（包含）的所有整数的集合。
//返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。
//也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个区间但不属于 nums 的数字 x 。

//分析：nums已经是升序，只需要检索后一个元素是否是前一个元素的后继，
//如果不是将前一个元素写入前一段区间，该元素写入下一段的开头，结尾额外中断一下

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
                    i--;//抵消后面的i++，使重新进入循环
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