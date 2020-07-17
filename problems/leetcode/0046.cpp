/**
 * 46. 全排列
 * 
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * https://leetcode-cn.com/problems/permutations/
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& output,
                   int first, int len) {
        if (first == len - 1) {
            res.push_back(output);
            return;
        }
        auto swap = [](int i, int j, vector<int>& array) {
            if (i == j) return;
            auto tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        };
        for (int i = first; i < len; ++i) {

            swap(first, i, output);
            backtrack(res, output, first + 1, len);
            swap(i, first, output);
        }

    }
};

