/**
 *  5. 最长回文子串
 * 
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 *   输入: "babad"
 *   输出: "bab"
 *   注意: "aba" 也是一个有效答案。
 * 
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;

        int n = s.length();
        bool flag[n][n];

        int left = 0, right = 0;

        for (int i = n - 2; i >= 0; i--) {
            flag[i][i] = true;

            for (int j = i + 1; j < n; j++) {

                flag[i][j] = 
                    (s[j] == s[i]) && (j - i < 3 || flag[i + 1][j - 1]);

                if (flag[i][j] && right - left < j - i) {
                    left = i;
                    right = j;
                }
            }
        }
        return string(s, left, right - left + 1);
    }
};


int main() {
    Solution solver;

    string test1 = "babad";
    cout << "Test1: " << solver.longestPalindrome(test1) << endl;

    string test2 = "cbbd";
    cout << "Test2: " << solver.longestPalindrome(test2) << endl;
}

