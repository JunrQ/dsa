/**
 * 6. Z 字形变换
 * 
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * string convert(string s, int numRows);
 * 
 * https://leetcode-cn.com/problems/zigzag-conversion/
 * 
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> tmp(numRows);

        string res;
        if (s.empty() || !numRows) return res;
        if (numRows == 1) return s;

        for (int i = 0; i < s.size(); i++) {
            int ans = i / (numRows - 1);
            int cur = i % (numRows - 1);
            if (ans % 2 == 0){
                tmp[cur].push_back(s[i]);
            }
            if (ans % 2 != 0){
                tmp[numRows - cur - 1].push_back(s[i]);
            }
        }
        for (int i = 0; i < tmp.size(); i++){
               res += tmp[i];
        }
        return res;
    }
};


int main() {
    Solution solver;

    string test1 = "LEETCODEISHIRING";
    cout << "Test1: " << solver.convert(test1, 3) << endl;
}

