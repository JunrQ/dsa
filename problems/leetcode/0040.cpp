/**
 * 40. 组合总和 II
 * 
 * 给定一个数组 candidates 和一个目标数 target ，
 * 找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * https://leetcode-cn.com/problems/combination-sum-ii/
 * 
 */


#include <vector>
#include <algorithm>

#include "utils.h"

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

            if (i > start && cand[i] == cand[i - 1]) {
                continue;
            }

            count += cand[i];
            stack.push_back(cand[i]);
            dfs(i + 1, target, stack, cand);

            count -= stack.back();
            stack.pop_back();

            if (count + cand[i] >= target) break;
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> stack;
        dfs(0, target, stack, candidates);
        return res;
    }
};


int main() {
    Solution solver;

    vector<int> test1 = {10 ,1, 2, 7, 6, 1, 5};
    auto res1 = solver.combinationSum2(test1, 8);

    for (auto i : res1) {
        printIntVector(i);
        printf("\n");
    }
}