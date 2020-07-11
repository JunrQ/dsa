/**
 * 32. 最长有效括号
 * 
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * https://leetcode-cn.com/problems/longest-valid-parentheses/
 * 
 */

#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> mark(s.length(), 0);
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') st.push(i);
            else {
                if (st.empty()) mark[i] = 1;
                else {
                    st.pop();
                }
            }
        }

        while (!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }

        int len = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (mark[i]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};

