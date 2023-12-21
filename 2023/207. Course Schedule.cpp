class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> edges;
        vector<int> degrees(numCourses, 0);
        queue<int> queue;
        for (vector<int>& p : prerequisites) {
            degrees[p[1]]++;
            edges[p[0]].insert(p[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                queue.push(i);
            }
        }
        while (!queue.empty()) {
            int c = queue.front();
            queue.pop();
            numCourses -= 1;
            for (int next : edges[c]) {
                degrees[next] -= 1;
                if (degrees[next] == 0) {
                    queue.push(next);
                }
            }
        }
        return numCourses == 0;
    }
};