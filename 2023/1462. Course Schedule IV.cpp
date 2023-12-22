class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> edges;
        unordered_map<int, unordered_set<int>> pres;
        vector<int> degrees(numCourses, 0);
        for (vector<int>& p : prerequisites) {
            degrees[p[1]] += 1;
            edges[p[0]].insert(p[1]);
            pres[p[1]].insert(p[0]);
        }
        queue<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                queue.push(i);
            }
        }
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop();
            for (int n : edges[curr]) {
                pres[n].insert(pres[curr].begin(), pres[curr].end());
                degrees[n] -= 1;
                if (degrees[n] == 0) {
                    queue.push(n);
                }
            }
        }
        vector<bool> res;
        for (vector<int>& q : queries) {
            res.push_back(pres[q[1]].find(q[0]) != pres[q[1]].end());
        }
        return res;
    }
};