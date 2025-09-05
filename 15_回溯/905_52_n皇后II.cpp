#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

//n �ʺ����� �о�������ν� n ���ʺ������ n �� n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
//����һ������ n ������ n �ʺ����� ��ͬ�Ľ��������������

//�������ʺ�֮�䲻������Ҫ���У��У�˫б�߶����ܴ�����һ���ʺ󣬹��������������������еĻʺ���Ϣ
//���ǰ�����ӻʺ󣬴洢�У����Խ��ߣ����Խ����ϵĻʺ���Ϣ
//���赱ǰԪ��Ϊ(i,j),���Ӧ�� column[j],diagonals1[i-j](����Ϊ��),diagonals2[i+j] �Խ�����2n-1��

class Solution {
private:
    set<int> column;
    set<int> diagonals1;
    set<int> diagonals2;//ֻ��Ҫ���Ҵ����ԣ������и�Ԫ�أ�����ʹ��������������ʹ�ü���
    int ans{};

public:
    void dfs(int n, int currentRow) {
        if (currentRow == n) {
            ans++;
            return;
        }
        for (int j = 0;j < n;j++) {
            if (!column.count(j) && !diagonals1.count(currentRow - j) && !diagonals2.count(currentRow +j)) {//��ǰλ���������
                column.insert(j);
                diagonals1.insert(currentRow - j);
                diagonals2.insert(currentRow + j);
                dfs(n, currentRow + 1);
                column.erase(j);
                diagonals1.erase(currentRow - j);
                diagonals2.erase(currentRow + j);

            }
        }


    }



    int totalNQueens(int n) {
        dfs(n, 0);
        return ans;

    }
};
