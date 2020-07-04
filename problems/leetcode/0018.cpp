/**
 * 18. 四数之和
 * 
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
 * 判断 nums 中是否存在四个元素 a，b，c 和 d ，
 * 使得 a + b + c + d 的值与 target 相等？
 * 找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 *   答案中不可以包含重复的四元组。
 * 
 * https://leetcode-cn.com/problems/4sum/
 * 
 */


#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;

        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums.size() - 3; ++first) {
            if (nums[first] > target / 4) {
                break;
            }

            if (first > 0 && nums[first] == nums[first - 1] || nums[first] + 3 * nums[nums.size() - 1] < target) {
                continue;
            }

            for (int sec = first + 1; sec < nums.size() - 2; ++sec) {
                if (sec > first + 1 && nums[sec] == nums[sec - 1]) {
                    continue;
                }
                int front = sec + 1, back = nums.size() - 1;

                while (front < back) {
                    int tmp = nums[first] + nums[sec] + nums[front] + nums[back];

                    if (tmp == target) {
                        res.push_back(vector<int>({nums[first], nums[sec], nums[front], nums[back]}));
                        ++front;
                        while (front < back && nums[front] == nums[front - 1]) {
                            ++front;
                        }
                        --back;
                        while (front < back && nums[back] == nums[back + 1]) {
                            --back;
                        }
                    } else if (tmp < target) {
                        if (nums[back] < (target - nums[first] - nums[sec]) / 2) break;
                        ++front;
                        while (front < back && nums[front] == nums[front - 1]) {
                            ++front;
                        }
                    } else {
                        if (nums[front] > (target - nums[first] - nums[sec]) / 2) break;  
                        --back;
                        while (front < back && nums[back] == nums[back + 1]) {
                            --back;
                        }
                    }


                }
            }
        }
        return res;
    }
};


int main() {

}

