#include <vector>
using namespace std;

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。

//分析：数组非零元素尽可能向前移动，被覆写的元素确定是0，在末尾补齐即可

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;//慢指针，总是指向紧凑的非零元素的下一个位置

        // Move all non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {//快指针，遍历数组元素
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }

        // Fill the rest with zeros
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};