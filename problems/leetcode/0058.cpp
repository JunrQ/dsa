/**
 * 58. 最后一个单词的长度
 * 
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，
 * 返回其最后一个单词的长度。如果字符串从左向右滚动显示，
 * 那么最后一个单词就是最后出现的单词。如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * 
 * https://leetcode-cn.com/problems/length-of-last-word/
 * 
 */

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0) return 0;
        int i = s.length() - 1;
        int l = 0;
        while (i >= 0 && s[i] == ' ') {
            --i;
        }

        while (i >= 0 && s[i] != ' ') {
            ++l;
            --i;
        }

        return l;
    }
};


