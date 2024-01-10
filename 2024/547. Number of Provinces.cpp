class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parents(n), ranks(n, 0);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        int count = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    if (merge(parents, ranks, i, j)) {
                        count -= 1;
                    }
                }
            }
        }
        return count;
    }

    int find(vector<int>& parents, int x) {
        if (parents[x] != x) {
            parents[x] = find(parents, parents[x]);
        }
        return parents[x];
    }

    bool merge(vector<int>& parents, vector<int>& ranks, int x , int y) {
        int px = find(parents, x), py = find(parents, y);
        if (px == py) {
            return false;
        }
        if (ranks[px] > ranks[py]) {
            parents[py] = px;
        } else {
            parents[px] = py;
            if (ranks[px] == ranks[py]) {
                ranks[py] += 1;
            }
        }
        return true;
    }
};