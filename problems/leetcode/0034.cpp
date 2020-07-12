/**
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 * 
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。
 * 找出给定目标值在数组中的开始位置和结束位置。
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 
 */

#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range = {-1, 1};
        int leftIdx = extremeInsertIndex(nums, target, true);

        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return range;
        }

        range[0] = leftIdx;
        range[1] = extremeInsertIndex(nums, target, false) - 1;

        return range;
    }

    int extremeInsertIndex(vector<int>& nums, int target, bool left) {
        int lo = 0;
        int hi = nums.size();

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};


