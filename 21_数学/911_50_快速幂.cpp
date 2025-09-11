#include <cmath>
#include <iostream>
using namespace std;



//实现Pow(x,n)，即x的幂

//分析：使用快速幂算法，如求 x的77 次方   1 - 2 - 4 - 9 - 19 - 38 -77
//其中4 - 9多乘的x在后序平方了3次，贡献了8 ； 9 - 19多乘的x贡献了 4 ， 38 - 77 多乘的x贡献了 1
//观察到 77 = 1011001，故若n的二进制表示中对应一，则我们在计算完平方后还需再乘个x

//或
class Solution {
public:
    double myPow(double x, int n) {
        double res{ 1 };
        double base = x;
        long int target = abs(static_cast<long>(n));//注意，abs返回类型与接受类型一致，故如果我们只将target设为long,遇到2^31仍会失效
        while (target > 0) {
            if (target & 1)//如果当前幂次考察的低位为1
                res *= base;
            base *= base; //x^0 - x^1 -x^2......
            target >>= 1;
        }
        return n >= 0 ? res : 1 / res;
     


    }
};

int main(){
    Solution sol;
    cout <<sol.myPow(2.1, 3)<< '\n';

}