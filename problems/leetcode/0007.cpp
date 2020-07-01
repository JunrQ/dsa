/**
 * 7. 整数反转
 * 
 *  给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 *   输入: 123
 *   输出: 321
 * 
 * https://leetcode-cn.com/problems/reverse-integer/
 *
 */


class Solution {
public:
    int reverse(int x) {
        int max = 0x7fffffff, min = 0x80000000;
        long rs = 0;
        for ( ; x; rs = rs * 10 + x % 10, x /= 10);
        return rs > max || rs < min ? 0 : rs;
    }
};


int main() {

}

