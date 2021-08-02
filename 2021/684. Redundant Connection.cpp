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

class Solution {
public:
    vector<int> parents, ranks;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parents.push_back(0);
        ranks.push_back(0);
        for (int i = 1; i <= n; i++) {
            parents.push_back(i);
            ranks.push_back(0);
        }
        for (vector<int>& e : edges) {
            if (!merge(e[0], e[1])) {
                return e;
            }
        }
        return {-1, -1};
    }
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }   
    
    bool merge(int x, int y) {
        int pX = find(x), pY = find(y);
        if (pX == pY) return false;
        if (ranks[pX] > ranks[pY]) {
            parents[pY] = pX;
        } else {
            parents[pX] = pY;
            if (ranks[pX] == ranks[pY]) {
                ranks[pY]++;
            }
        }
        return true;
    }
};