/**
 * 59. 螺旋矩阵 II
 * 
 * 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，
 * 且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * https://leetcode-cn.com/problems/spiral-matrix-ii/
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int num = n * n;
        int idx = 1;

        int l = 0, r = n - 1, t = 0, b = n - 1;

        while (idx <= num) {
            for (int i = l; i <= r; ++i) ans[t][i] = idx++;
            t++;
            for (int i = t; i <= b; ++i) ans[i][r] = idx++;
            r--;
            for (int i = r; i >= l; i--) ans[b][i] = idx++;
            b--;
            for (int i = b; i >= t; i--) ans[i][l] = idx++;
            l++;
        }

        return ans;
    }
};

