/**
 * 43. 字符串相乘
 * 
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，
 * 返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * https://leetcode-cn.com/problems/multiply-strings/
 * 
 */

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        auto judge = [](string& s) -> bool {
            if (s.length() == 1 && s[0] == '0') {
                return true;
            } else {
                return false;
            }
        };

        if (judge(num1) || judge(num2)) {
            return string("0");
        }
        
        vector<int> res(num1.length() + num2.length(), 0);
        for (int i = num1.length() - 1; i >= 0; --i) {
            int n1 = num1[i] - '0';
            for (int j = num2.length() - 1; j >= 0; --j) {
                
                int n2 = num2[j] - '0';
                int sum = (res[i + j + 1] + n1 * n2);

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        stringstream ss;
        for (int i = 0; i < res.size(); ++i) {
            if (i == 0 && res[i] == 0) {
                continue;
            }
            ss << res[i];
        }

        return ss.str();
    }
};


int main() {
    Solution solver;

    cout << solver.multiply(string("123"), string("456")) << endl;

    cout << solver.multiply(string("123"), string("0")) << endl;
}

