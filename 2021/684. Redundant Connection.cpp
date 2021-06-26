class Solution {
public:
    vector<int> parents, ranks;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i < 1001; i++) {
            parents.push_back(i);
            ranks.push_back(0);
        }
        for (vector<int>& edge : edges) {
            if (!merge(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
    
    int find(int node) {
        if (parents[node] != node) {
            parents[node] = find(parents[node]);
        }
        return parents[node];
    }
    
    bool merge(int left, int right) {
        int lp = find(left), rp = find(right);
        if (lp == rp) return false;
        if (ranks[lp] < ranks[rp]) {
            parents[lp] = rp;
        } else {
            if (ranks[lp] == ranks[rp]) {
                ranks[lp]++;
            }
            parents[rp] = lp;
        }
        return true;
    }
};