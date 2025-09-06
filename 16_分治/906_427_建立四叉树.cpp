#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ�� n* n ���� grid ������������ 0 �� 1 ��ɡ��������Ĳ�����ʾ�þ��� grid ��
//����Ҫ�����ܱ�ʾ���� grid �� �Ĳ��� �ĸ���㡣

//�Ĳ������ݽṹ�У�ÿ���ڲ��ڵ�ֻ���ĸ��ӽڵ㡣���⣬ÿ���ڵ㶼���������ԣ�
//val������Ҷ�ӽ��������������ֵ��1 ��Ӧ True��0 ��Ӧ False��ע�⣬�� isLeaf Ϊ False ʱ������԰� True ���� False ��ֵ���ڵ㣬����ֵ���ᱻ������� ���� ��
//isLeaf : ������ڵ���һ��Ҷ�ӽ��ʱΪ True��������� 4 ���ӽڵ���Ϊ False ��

//���ǿ��԰����²���Ϊ��ά���򹹽��Ĳ�����
//�����ǰ�����ֵ��ͬ������ȫΪ 0 ����ȫΪ 1������ isLeaf ��Ϊ True ���� val ��Ϊ������Ӧ��ֵ�������ĸ��ӽڵ㶼��Ϊ Null Ȼ��ֹͣ��
//�����ǰ�����ֵ��ͬ���� isLeaf ��Ϊ False�� �� val ��Ϊ����ֵ��Ȼ������ͼ��ʾ������ǰ���񻮷�Ϊ�ĸ�������
//ʹ���ʵ���������ݹ�ÿ���ӽڵ㡣


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

//����������ʹ�����������Ͻ����������½������������������


class Solution {
public:
    Node* divide(const vector<vector<int>>& grid, int x0, int y0, int x1, int y1) {
        for (int i = x0;i <= x1;i++) {
            for (int j = y0;j <= y1;j++) {
                if (grid[i][j] != grid[x0][y0]) {//����Ԫ�ز�һ������ݹ鹹�캢��
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