/**
 * 39. 组合总和
 * 
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，
 * 找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。
 * 
 * https://leetcode-cn.com/problems/combination-sum/
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    int count = 0;

    void dfs(int start, int target, vector<int>& stack, vector<int>& cand) {

        if (count == target) {
            res.push_back(stack);
        }

        if (count > target) {
            return;
        }

        for (int i = start; i < cand.size(); ++i) {
            count += cand[i];
            stack.push_back(cand[i]);
            dfs(start, target, stack, cand);

            count -= stack.back();
            stack.pop_back();
            start += 1;

            if (count + cand[i] > target) break;
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> stack;
        dfs(0, target, stack, candidates);
        return res;
    }
};



