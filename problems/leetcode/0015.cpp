/**
 * 15. 三数之和
 * 
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
 * 使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * https://leetcode-cn.com/problems/3sum/
 * 
 */

#include <vector>
#include <algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0) break;
            
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {

                if ((nums[i] + nums[l] + nums[r]) > 0) {
                    --r;
                } else if ((nums[i] + nums[l] + nums[r]) < 0) {
                    ++l;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        ++l;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        --r;
                    }
                    ++l;
                    --r;
                }
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++i;
            }
            ++i;
        }
        return ans;
    }
};


int main() {
    Solution solver;

    vector<int> test1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > ans1 = solver.threeSum(test1);
    for (int i = 0; i < ans1.size(); ++i) {
        printIntVector(ans1[i]);
        printf("\n");
    }
}

