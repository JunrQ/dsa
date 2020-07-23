/**
 * 53. 最大子序和
 * 
 * 给定一个整数数组 nums ，
 * 找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * https://leetcode-cn.com/problems/maximum-subarray/
 * 
 */


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int pre = 0, maxAns = nums[0];
//         for (const auto &x: nums) {
//             pre = max(pre + x, x);
//             maxAns = max(maxAns, pre);
//         }
//         return maxAns;
//     }
// };


class Solution {
public:

    // lSum 表示 [l, r][l,r] 内以 ll 为左端点的最大子段和
    // rSum 表示 [l, r][l,r] 内以 rr 为右端点的最大子段和
    // mSum 表示 [l, r][l,r] 内的最大子段和
    // iSum 表示 [l, r][l,r] 的区间和
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) return (Status) {a[l], a[l], a[l], a[l]};
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

 
