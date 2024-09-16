class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        vector<int> inDegrees(numCourses, 0);
        queue<int> takes;
        for (vector<int>& pre : prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            inDegrees[pre[0]] += 1;
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                takes.push(i);
            }
        }
        while (!takes.empty()) {
            int curr = takes.front();
            takes.pop();
            numCourses -= 1;
            for (int next : edges[curr]) {
                inDegrees[next] -= 1;
                if (inDegrees[next] == 0) {
                    takes.push(next);
                }
            }
        }
        return numCourses == 0;
    }
};