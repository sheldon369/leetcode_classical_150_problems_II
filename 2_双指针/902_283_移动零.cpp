#include <vector>
using namespace std;

//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//��ע�� �������ڲ���������������ԭ�ض�������в�����

//�������������Ԫ�ؾ�������ǰ�ƶ�������д��Ԫ��ȷ����0����ĩβ���뼴��

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;//��ָ�룬����ָ����յķ���Ԫ�ص���һ��λ��

        // Move all non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {//��ָ�룬��������Ԫ��
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