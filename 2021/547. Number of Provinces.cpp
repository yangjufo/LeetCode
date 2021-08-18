class Solution {
public:
    vector<int> parents, ranks;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
            ranks.push_back(0);
        }
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] && merge(i, j)) {
                    n--;
                }
            }
        }
        return n;
    }
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    bool merge(int x, int y) {
        int pX = find(x), pY = find(y);
        if (pX == pY) {
            return false;
        }
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