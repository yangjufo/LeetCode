class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int moves = abs(target[0]) + abs(target[1]);
        for (vector<int>& g : ghosts) {
            if (abs(g[0] - target[0]) + abs(g[1] - target[1]) <= moves) {
                return false;
            }
        }
        return true;
    }
};