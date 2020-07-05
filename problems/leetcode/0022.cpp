/**
 * 22. 括号生成
 * 
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * https://leetcode-cn.com/problems/generate-parentheses/
 * 
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res, "", 0, 0, n);
        return res;
    }

    void func(vector<string>& res, string str, int l, int r, int n) {
        if (l > n || r > n || r > l) return;
        if (l == n && r == n) {
            res.push_back(str);
            return;
        }

        func(res, str + "(", l + 1, r, n);
        func(res, str + ")", l, r + 1, n);
    }
};


int main() {

    Solution solver;
    auto res = solver.generateParenthesis(3);
    for (auto s : res) {
        cout << s << endl;
    }

}

