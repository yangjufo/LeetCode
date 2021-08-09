class Solution {
public:
    unordered_map<int, int> parents;
    int islands = 0;
    int removeStones(vector<vector<int>>& stones) {
        for (vector<int>& s : stones) {
            merge(s[0], ~s[1]);
        }
        return stones.size() - islands;
    }
    
    int find(int x) {
        if (parents.find(x) == parents.end()) {
            parents[x] = x;
            islands++;            
        } else if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void merge(int x, int y) {
        int pX = find(x), pY = find(y);
        if (pX != pY) {
            parents[pX] = pY;
            islands--;
        }
    }
};