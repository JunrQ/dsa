/**
 * 31. 下一个排列
 * 
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 *   1,2,3 → 1,3,2
 *   3,2,1 → 1,2,3
 *   1,1,5 → 1,5,1
 *
 * https://leetcode-cn.com/problems/next-permutation/
 * 
 */

#include <vector>
#include "utils.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        bool flag = false;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            --i;
        }

        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                --j;
            }
            if (j > i) {
                flag = true;
                swap(nums, i, j);
            }
        }

        if (flag) {
            reverse(nums, i + 1);
        } else {
            reverse(nums, 0);
        }
    }

    inline void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    inline void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            ++i; --j;
        }
    }
};


int main() {
    Solution solver;

    vector<int> test1 = {2,2,7,5,4,3,2,2,1};
    solver.nextPermutation(test1);

    printIntVector(test1);
}

