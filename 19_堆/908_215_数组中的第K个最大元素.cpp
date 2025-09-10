#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

//分析：解1：基于快速排序的选择方法
//每次完成划分操作，都可以确定一个元素的最终位置，我们只搜索想要的区间，并不用递归去搜索另一个待排序区间 ——>平均复杂度为线性
//Quicksort 每层要处理n个元素的分区，深度为logn，故总体时间为 nlogn
//Quickselect 每次分区后只会递归到一边，因此期望递归的子问题规模是原问题的常数比例，形成 n+3/4 n + 9/16 n+....  = O(n)

//解2：基于堆排序的选择方法
//建大根堆，执行k次删除, O(n + klogn) = O(n)
//或建立大小为k的小根堆，堆满之后，若当前元素大于k，则删除堆顶，加入该元素 O(k + (n-k)logk)

//建堆(Build - Heap)	给定一个数组，调整成堆 𝑂(𝑛)
//插入(Insert)	在堆尾加一个元素，然后上浮 𝑂(log𝑛)
//取最大 / 最小值(Peek)	直接返回堆顶元素 𝑂(1)
//删除堆顶(Extract - Max / Min)	把堆顶与末尾交换，删除，再下沉 𝑂(log𝑛)
//删除任意元素	交换待删元素与堆尾，下沉或上浮修复 𝑂(log𝑛)
//增加 / 减少键值(Increase / Decrease - Key)	修改值，然后上浮或下沉修复 𝑂(log𝑛)
//堆排序 每次将堆顶与堆尾交换，删除加入数组，再调整堆  𝑂(𝑛) + (n-1)𝑂(log𝑛) = 𝑂(𝑛logn)


//解3：题目限制了-10^4 <= nums[i] <= 10^4，且不对空间进行限制，使用桶排序

class Solution {
public:
    //常规快排，总是选取首个元素，但很可能面对完全有序数组，导致性能大幅退化
    int QuickSelect1(vector<int>& nums, int k, int l, int r) {
        int i = l;
        int j = r;
        int pivot = nums[i];
        while (i < j) {
            while (nums[j] >= pivot && j > i) j--;//右边找到首个小于pivot的元素
            nums[i] = nums[j];
            while (nums[i] <= pivot && i < j) i++;//左边找到首个大于pivot的元素
            nums[j] = nums[i];
        }//退出循环时
        nums[i] = pivot;
        if (i == nums.size() - k)
            return pivot;
        else if (i < nums.size() - k)
            return QuickSelect(nums, k, i + 1, r);
        else
            return QuickSelect(nums, k, l, i - 1);
    }



    //优化:采用更稳健的partition方式
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[l + (r - l) / 2]; // 改进: 中点作为 pivot
        int i = l - 1, j = r + 1;
        while (true) {
            do { i++; } while (nums[i] < pivot);//每次i至少增加一，结束后停在大于等于pivot的元素身上
            do { j--; } while (nums[j] > pivot);//每次j至少减少一，结束后停在小于等于pivot的元素身上
            if (i >= j) return j;//退出while循环时，总是有已排序元素的index 为j
            swap(nums[i], nums[j]);

        }
    }

    int QuickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];

        int pivotIndex = partition(nums, l, r);

        if (k <= pivotIndex)
            return QuickSelect(nums, l, pivotIndex, k);
        else
            return QuickSelect(nums, pivotIndex + 1, r, k);
    }

    //自己构建堆的代码
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;//堆的底层是vector构造的二叉数
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    //主函数
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSelect(nums, nums.size() - k, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums{ 7,6,5,4,3,2,1 };
    Solution sol;
    sol.findKthLargest(nums, 2);
}