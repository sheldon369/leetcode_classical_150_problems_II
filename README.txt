2025年
上接原来的项目，但是目录过于混乱故重新编排

包括区间，栈，链表，二叉树，二叉树层次遍历，二叉搜索树，图，图的广度优先搜索，字典树，回溯，分治，Kadane算法，二分查找，堆，位运算，数学，一维动态规划，多维动态规划。

git维护代码

git init 
git add . 
git commit -m "第一次提交"
git remote add origin https://github.com/你的用户名/仓库名.git
git remote -v
git branch -M main
git push -u origin main

git status
git add .
git commit -m "说明你修改了什么"
git push origin main
git config --global --unset http.proxy 
git config --global --unset https.proxy
Test-NetConnection github.com -Port 443
git config --global http.proxy http://127.0.0.1:7890
git config --global https.proxy http://127.0.0.1:7890

std::cerr << "getUserInput() called\n"; //用于调试代码
#include <climits> INT_MIN INT_MAX
bool b{} //默认初始化为false
static_cast<int>(5.5);//显式类型转换
const double gravity { 9.8 };  // 使用 const 修饰常变量
std::getline(std::cin >> std::ws, name); // 将一整行输入读取到 name
std::unorder_map O(1)查找元素 count / find (map和set的使用基本一致，map的值字段可以设为结构体存储更多信息)
char数组实际上等价于一个%s类型的串
auto 为自动类型
vector<int>{levelList.begin(), levelList.end()}//levelist是一个deque<int>类型的双端队列，使用它的迭代器范围复制到vector身上

 unordered_set<pair<int,int>> isVisited 错误，因为c++中没用定义pair的哈希，改为set就对了
因为unordered_set 是 哈希表，平均复杂度 O(1) 查找/插入，但需要哈希函数。
set 是 有序树，查找/插入复杂度 O(log n)，不需要哈希函数。


string s.find("abcd") != string ::npos// find可用于字符串的模式匹配
assert(ptr); // 如果不应将空指针传递给函数，则可以使用断言：如果传了一个空指针，立即停止执行 (因为这种情况不应该发生)
