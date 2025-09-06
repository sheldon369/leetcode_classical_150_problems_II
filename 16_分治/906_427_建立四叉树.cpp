#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给你一个 n* n 矩阵 grid ，矩阵由若干 0 和 1 组成。请你用四叉树表示该矩阵 grid 。
//你需要返回能表示矩阵 grid 的 四叉树 的根结点。

//四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：
//val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False。注意，当 isLeaf 为 False 时，你可以把 True 或者 False 赋值给节点，两种值都会被判题机制 接受 。
//isLeaf : 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。

//我们可以按以下步骤为二维区域构建四叉树：
//如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null 然后停止。
//如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
//使用适当的子网格递归每个子节点。


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

//分析：我们使用正方形左上角坐标与右下角坐标访问正方形区间


class Solution {
public:
    Node* divide(const vector<vector<int>>& grid, int x0, int y0, int x1, int y1) {
        for (int i = x0;i <= x1;i++) {
            for (int j = y0;j <= y1;j++) {
                if (grid[i][j] != grid[x0][y0]) {//存在元素不一样，则递归构造孩子
                    return new Node(grid[x0][y0], false,
                        divide(grid,x0,y0,(x1+x0)/2,(y1+y0)/2),
                        divide(grid, x0, (y1 + y0) / 2+1, (x1 + x0) / 2, y1),
                        divide(grid, (x1 + x0) / 2+1, y0, x1, (y1 + y0) / 2),
                        divide(grid, (x1 + x0) / 2 + 1, (y1 + y0) / 2 + 1, x1, y1)
                        );
                }
                
            }
        }
        return new Node(grid[x0][y0], true);


    }


    Node* construct(vector<vector<int>>& grid) {
        return divide(grid, 0, 0, grid.size() - 1, grid.size() - 1);

    }
};