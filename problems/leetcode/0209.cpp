/**
 * 209. 长度最小的子数组
 * 
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，
 * 并返回其长度。如果不存在符合条件的连续子数组，返回 0。
 * 
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int j = 0;
        int i = 0;
        int min_count = nums.size();
        for (; i < nums.size(); i++) {
            sum += nums[i];

            if (sum >= s) {
                while ((sum - nums[j]) >= s) {
                    sum -= nums[j];
                    j++;
                }

                if ((i - j + 1) < min_count) {
                    min_count = (i - j + 1);
                }
            }
            
        }
        if (sum < s) {
            return 0;
        } else {
            return min_count;
        }
    }
};


int main() {
    Solution solver;
    vector<int> test1 = {5,1,3,5,10,7,4,9,2,8};
    printf("Test1: %d\n", solver.minSubArrayLen(15, test1));

    vector<int> test2 = {2,3,1,2,4,3};
    printf("Test2: %d\n", solver.minSubArrayLen(7, test2));
}
