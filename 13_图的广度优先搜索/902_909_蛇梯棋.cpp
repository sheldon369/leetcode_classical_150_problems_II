#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//����һ����СΪ n x n ���������� board �����񰴴� 1 �� n2 ��ţ������ѭ ת�н��淽ʽ �������½ǿ�ʼ �������� board[n - 1][0] ��ʼ����ÿһ�иı䷽��
//��һ��ʼλ�������ϵķ���  1��ÿһ�غϣ������Ҫ�ӵ�ǰ���� curr ��ʼ������������Ҫ��ǰ����
//ѡ��Ŀ�귽�� next ��Ŀ�귽��ı���ڷ�Χ[curr + 1, min(curr + 6, n2)] ��
//��ѡ��ģ������ ���������� ���龰���������̴�С��Σ�������ֻ���� 6 ��Ŀ�ĵء�
//������ң����Ŀ�귽�� next �������߻����ӣ���ô��һᴫ�͵��߻����ӵ�Ŀ�ĵء�������Ҵ��͵�Ŀ�귽�� next ��
//����ҵ����� n2 �ķ���ʱ����Ϸ������
//��� board[r][c] != -1 ��λ�� r �� c �е����̸��п��ܴ��� ���ߡ� �� �����ӡ����Ǹ��߻����ӵ�Ŀ�ĵؽ����� board[r][c]�����Ϊ 1 �� n2 �ķ������κ��߻����ӵ���㡣
//ע�⣬�����ÿ��������ǰ�����������ֻ�������߻�����һ�Σ�����Ŀ�ĵ�����һ���߻����ӵ���㣬���Ҳ ���� �����ƶ���
//�ٸ����ӣ����������� [[-1, 4], [-1, 3]] ����һ���ƶ�����ҵ�Ŀ�귽���� 2 ����ô�����ҽ���˳�����ӵ��﷽�� 3 ���� ���� ˳�ŷ��� 3 �ϵ�����ǰ������ 4 ��������˵�����Ʒ����壬����������ӵ������ƶ���Ӧ���������������·���������ӻ��ߣ�����ֱ������·�����յ㣬��������·����β������Ҳ�������������·����
//���شﵽ���Ϊ n2 �ķ������������������������������ܣ��򷵻� - 1��

//������BFS��������һ�㵽���������·������˵������״η���һ�����ʱ����Ȼ�Ǵ���ʼ�㵽�ý������·�������isVisited������������������defaultֵ 0 ����

class Solution {
public:
    void reverse(vector<int>& vec) {
        int n = vec.size();
        for (int i = 0;i < n/2;i++) {
            int temp = vec[n - 1 - i];
            vec[n - 1 - i] = vec[i];
            vec[i] = temp;
        }

    }
    vector<int> boardToLine(vector<vector<int>>& board) {//������ά����һά�б��ӳ�䣬��1��ʼ
        int n = board.size();
        vector<int> ans;
        ans.push_back(0);//��Ԫ��
        //nΪż����ż���з�ת��nΪ�棬�������з�ת
        for (int i = n - 1;i >= 0;i--) {
            if (n % 2) {//nΪ��
                if (i % 2)
                    reverse(board[i]);
                ans.insert(ans.end(), board[i].begin(), board[i].end());//����������insert
            }
            else {
                if (!(i % 2)) //ע�⣺!�����ȼ��ǳ���
                    reverse(board[i]);
                ans.insert(ans.end(), board[i].begin(), board[i].end());
            }

        }
        return ans;
    }



    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> line = boardToLine(board);
        int n = board.size();
        map<int, int> step;
        for (int i = 1;i <= n * n;i++) {
            step[i] = -1;
        }
        queue<int> q;
        step[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 1;i <= 6;i++) {
                if (cur + i > n * n) break;
                int new_cur = (line[cur + i] == -1) ? (cur + i) : line[cur + i];//�µķ��ʵ�ַ
                if (step[new_cur] != -1)//���״η���
                    continue;
                step[new_cur] = step[cur] + 1;
                if (new_cur == n * n)
                    return step[new_cur];
                q.push(new_cur);
 
            }
        }
        return -1;
        
    }
};

int main() {
    Solution sol;

    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };

    int result = sol.snakesAndLadders(board);
    cout << "Result: " << result << endl;

    return 0;
}