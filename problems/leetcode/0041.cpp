/**
 * 41. 缺失的第一个正数
 * 
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
 * 
 * https://leetcode-cn.com/problems/first-missing-positive/
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

