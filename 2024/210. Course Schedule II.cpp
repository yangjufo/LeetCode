class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        vector<int> degrees(numCourses, 0);
        for (vector<int>& pre : prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            degrees[pre[0]] += 1;
        }
        queue<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                queue.push(i);
            }
        }
        vector<int> res;
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop();
            res.push_back(curr);
            for (int next : edges[curr]) {
                degrees[next] -= 1;
                if (degrees[next] == 0) {
                    queue.push(next);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};