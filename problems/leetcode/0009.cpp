/**
 * 9. 回文数
 * 
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 *   输入: 121
 *   输出: true
 * 
 * 示例 2:
 *   输入: -121
 *   输出: false
 *   解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 */



class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0 || x % 10 == 0) return false;

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return x == reversed || x == reversed / 10;
    }
};

