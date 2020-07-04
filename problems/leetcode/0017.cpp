/**
 * 17. 电话号码的字母组合
 * 
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * 
 */

#include <vector>
#include <string>
#include <unordered_map>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> letterMap {
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};
        vector<string> res;

        if (digits.empty()) return res;
        func(res, "", digits, letterMap, 0);
        return res;
    }

    void func(vector<string>& res, string str, string& digits,
              unordered_map<char, string>& map, int k) {
        if (str.size() == digits.size()) {
            res.push_back(str);
        }

        string tmp = map[digits[k]];
        for (char w : tmp) {
            str += w;
            func(res, str, digits, map, k + 1);
            str.pop_back();
        }
        return;
    }
};


int main() {
    Solution solver;

    string test1 = "23";
    auto res = solver.letterCombinations(test1);
    printStringVector(res);
    printf("\n");
}

