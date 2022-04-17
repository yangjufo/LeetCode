class Solution {
public:
    int maxL = 0;
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> children(parent.size());
        for (int i = 1; i < parent.size(); i++) {
            children[parent[i]].push_back(i);
        }
        return max(dfs(children, 0, s), maxL);
    }

    int dfs(vector<vector<int>>& children, int curr, string& s) {
        if (children[curr].empty()) {
            return 1;
        } else {
            int max1 = 0, max2 = 0;
            for (int c : children[curr]) {
                int cL = dfs(children, c, s);
                if (s[c] != s[curr]) {
                    if (cL > max1) {
                        max2 = max1;
                        max1 = cL;
                    } else if (cL > max2) {
                        max2 = cL;
                    }
                }
            }
            maxL = max(maxL, max1 + max2 + 1);
            return max1 + 1;
        }
    }
};