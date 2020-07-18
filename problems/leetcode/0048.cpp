/**
 * 48. 旋转图像
 * 
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 将图像顺时针旋转 90 度。
 * 
 * 说明：
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。
 * 请不要使用另一个矩阵来旋转图像。
 * 
 * https://leetcode-cn.com/problems/rotate-image/
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                auto tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                auto tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
};
