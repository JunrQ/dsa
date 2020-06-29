/**
 * 现在你总共有 n 门课需要选，记为 0 到 n-1。
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
 * 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
 * 
 * https://leetcode-cn.com/problems/course-schedule-ii/
 */

#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        unordered_map<int, vector<int> > graph;

        for (auto & edge : prerequisites) {
            in_degree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
        }

        stack<int> stk;
        for (int i = 0; i < in_degree.size(); i++) {
            if (!in_degree[i]) stk.push(i);
        }

        stack<int> res;
        while(!stk.empty()) {
            int c = stk.top();
            stk.pop();
            res.push(c);

            for (auto & pre : graph[c]) {
                in_degree[pre]--;
                if (!in_degree[pre]) {
                    stk.push(pre);
                }
            }
        }

        vector<int> res0;
        if (res.size() < numCourses) return res0;

        while(!res.empty()) {
            res0.push_back(res.top());
            res.pop();
        }
        return res0;
    }
};


int main() {
    Solution solver;
    vector<vector<int>> test1;

    test1.push_back({1, 0});
    test1.push_back({2, 0});
    test1.push_back({3, 1});
    test1.push_back({3, 2});

    vector<int> res = solver.findOrder(4, test1);
    for (int& v : res) {
        printf("%d ", v);
    }
    printf("\n");

}
