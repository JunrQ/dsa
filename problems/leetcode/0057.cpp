/**
 * 57. 插入区间
 * 
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠
 * （如果有必要的话，可以合并区间）。
 * 
 * https://leetcode-cn.com/problems/insert-interval/
 * 
 */


#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            return {newInterval};
        }

        vector<vector<int>> ans;

        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            ++i;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        ans.push_back(newInterval);

        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            ++i;
        }
        return ans;
    }
};
