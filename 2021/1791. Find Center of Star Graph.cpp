class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> edgeMap;
        for (vector<int>& edge : edges) {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
            if (edgeMap[edge[0]].size() > 1) return edge[0];
            if (edgeMap[edge[1]].size() > 1) return edge[1];
        }
        return -1;
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};