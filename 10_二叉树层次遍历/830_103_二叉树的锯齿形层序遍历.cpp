#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
//（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

//分析：同830_102层序遍历，针对奇数链表执行翻转



class Solution {
public:
    void reverseVector(vector<int>& vec) {
        int n = vec.size(); 
        for (int i = 0;i < n / 2;i++) {
            int temp = vec[n - i - 1];
            vec[n - i - 1] = vec[i];
            vec[i] = temp;
        }   
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode*, int>> q;
        TreeNode* p = root;
        q.push({ root ,0 });
        pair<TreeNode*, int> pre{ nullptr,-1 };
        while (q.size()) {
            p = q.front().first;
            int curLevel = q.front().second;
            if (curLevel != pre.second) //p为当前层首个结点
                ans.push_back({ p->val });
            else {//非首结点加入当前数组
                ans[curLevel].push_back(p->val);
            }
            if (p->left)
                q.push({ p->left ,curLevel + 1 });
            if (p->right)
                q.push({ p->right ,curLevel + 1 });
            //最后一个点总要单独输出
            pre = q.front();
            q.pop();

        }
        for (int i = 0;i < ans.size();i++) {
            if (i % 2)
                reverseVector(ans[i]);
        }
        return ans;
    }

    //解2：设计双端队列deque
    vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList;//双端队列,deque一般是连续内存，list是双端链表,推荐用deque
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();//auto为自动类型
                nodeQueue.pop();
                if (isOrderLeft) {//还是只对读出答案做改变,使用deque暂存结果
                    levelList.push_back(node->val);
                }
                else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            //vector<int>{levelList.begin(), levelList.end()} 使用 levelList 的迭代器范围构造 vector
            //emplace_back 直接在 ans 的存储位置上构造，避免了一次临时对象拷贝（性能比push_back稍好一些）。
            //只有push_back接受初始化列表参数，如ans.push_back({1, 2, 3}); //✅ 直接支持初始化列表，ans.emplace_back(vector<int>{1, 2, 3}); // ✅ 必须显式写出来
            isOrderLeft = !isOrderLeft;
        }

        return ans;
    }


};