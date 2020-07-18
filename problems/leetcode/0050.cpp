/**
 * 50. Pow(x, n)
 * 
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * https://leetcode-cn.com/problems/powx-n/
 * 
 */

class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        double x_contrib = x;

        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x_contrib;
            }

            x_contrib *= x_contrib;
            N /= 2;
        }

        return ans;
    }


    double myPow(double x, int n) {
        long long N = n; // in case -n overflow
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
