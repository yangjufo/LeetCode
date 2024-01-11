class Solution {
public:
    int find(vector<int>& parents, int x) {
        if (parents[x] != x) {
            parents[x] = find(parents, parents[x]);
        }
        return parents[x];
    }

    bool merge(vector<int>& parents, vector<int>& ranks, int x, int y) {
        int px = find(parents, x), py = find(parents, y);
        if (px == py) {
            return false;
        }
        if (ranks[px] > ranks[py]) {
            parents[py] = px;
            ranks[px]++;
        } else {
            parents[px] = py;
            if (ranks[px] == ranks[py]) {
                ranks[py]++;
            }
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1), ranks(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parents[i] = i;
        }
        for (vector<int>& edge : edges) {
            if (!merge(parents, ranks, edge[0], edge[1])) {
                return edge;
            }
        }
        return {0, 0};
    }
};