/**
 * 1. 两数之和
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * https://leetcode-cn.com/problems/two-sum/
 * 
 */

#include <vector>
#include <algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arg_index = argsort(nums);
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {

                int first = nums[arg_index[i]];
                int second = nums[arg_index[j]];

                if ((first + second) == target) {
                    res = {arg_index[i], arg_index[j]};
                    return res;
                }


                if ((first + second) > target) {
                    break;
                }

            }
        }
        return res;
    }
};


int main() {
    Solution solver;
    vector<int> test1 = {2, 7, 11, 15};

    vector<int> res = solver.twoSum(test1, 9);
    printIntVector(res);
    printf("\n");
}

