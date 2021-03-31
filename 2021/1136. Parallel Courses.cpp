class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> degrees(n + 1, 0);
        unordered_map<int, vector<int>> edges;        
        for (auto& rel : relations) {
            edges[rel[0]].push_back(rel[1]);
            degrees[rel[1]] += 1;
        }
        
        int count = n;
        queue<int> nodes;
        for (int i = 1; i <= n; i++) {
            if (degrees[i] == 0) {
                nodes.push(i);
                count--;
            }                        
        }
        
        int semesters = 0;
        while (!nodes.empty()) {
            semesters++;
            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                int course = nodes.front();
                nodes.pop();
                for (int neigh : edges[course]) {
                    degrees[neigh]--;
                    if (degrees[neigh] == 0) {
                        nodes.push(neigh);
                        count--;
                    }
                }
            }
        }
        return count == 0 ? semesters : -1;
    }
};