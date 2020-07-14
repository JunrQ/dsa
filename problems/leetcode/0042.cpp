/**
 * 42. 接雨水
 * 
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
 * 计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * https://leetcode-cn.com/problems/trapping-rain-water/
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int ans = 0;
        int size = height.size();

        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; ++i) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }

        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }

        for (int i = 0; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }

        return ans;
    }
};

