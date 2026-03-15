#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
//两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：




class Solution {
public:
	//解1：回溯，部分测试数据超时
	bool DFS(string s1, string s2, string s3, int i1, int i2, int i3) {
		if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size())
			return true;

		bool DFS_a = (i3 < s3.size() && i1 < s1.size() && s3[i3] == s1[i1]) ? DFS(s1, s2, s3, i1 + 1, i2, i3 + 1) : false;
		bool DFS_b = (i3 < s3.size() && i2 < s2.size() && s3[i3] == s2[i2]) ? DFS(s1, s2, s3, i1, i2 + 1, i3 + 1) : false;
		return DFS_a || DFS_b;

	}

	//优化：dp
	//首先若|s3|不等于|s1| + |s2|，必然不可能构成
	//其次定义f(i,j)表示s1前i个元素和s2前j个元素能够构成s3前i+j个元素,f(0,0) = true
	//f(i+1,j) = f(i,j) && s1[i+1] == s3[i+j+1]
	//f(i,j+1) = f(i,j) && s2[j+1] == s3[i+j+1]
	//相当于搜索路径，只能向右和向下转移
	//分析：逐行生成，可以优化为O(n)空间
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size();
		int n = s2.size();
		if (s3.size() != m + n)
			return false;

		vector<bool> dp(n + 1, false); // i,dp[j]对应 f(i,j)
		dp[0] = true;
		for (int j = 1;j <= n;j++) //初始化第一行
			dp[j] = dp[j - 1] && s2[j - 1] == s3[0 + j - 1];//第一行只能由左边转移而来,同时需匹配s2中第j个元素和s3中第i+j个元素，由于索引从0开始，所以第j个元素对应n[j-1]
		int i = 1;
		while (i <= m) {
			dp[0] = dp[0] && s1[i - 1] == s3[i + 0 - 1];

			for (int j = 1;j <= n;j++)
				dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);//针对第一列单独判定

			++i;
		}
		return dp[n];

	}
};