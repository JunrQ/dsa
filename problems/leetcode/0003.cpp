/**
 * 3. 无重复字符的最长子串
 * 
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 *   输入: "abcabcbb"
 *   输出: 3 
 *   解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 示例 2:
 *   输入: "bbbbb"
 *   输出: 1
 *   解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 *   输入: "pwwkew"
 *   输出: 3
 *   解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *    请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 */


#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;

        unordered_set<char> bucket;
        int left_guard = 0;
        int max_size = 1;

        for (int i = 0; i < s.length(); ++i) {
            if (bucket.count(s[i])) {
                if (bucket.size() > max_size) {
                    max_size = bucket.size();
                }

                while (s[left_guard] != s[i]) {
                    bucket.erase(s[left_guard]);
                    left_guard++;
                }

                { // One more time
                    bucket.erase(s[left_guard]);
                    left_guard++;
                }

            }
            bucket.insert(s[i]);
        }

        if (bucket.size() > max_size) {
            max_size = bucket.size();
        }
        return max_size;
    }
};

int main() {
    Solution solver;

    string test1 = "aab";
    printf("Test1: %d\n", solver.lengthOfLongestSubstring(test1));

    string test2 = "pwwkew";
    printf("Test2: %d\n", solver.lengthOfLongestSubstring(test2));
}


