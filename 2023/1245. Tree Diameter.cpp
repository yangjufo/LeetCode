class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n);
        for (vector<int>& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        int maxLen = 0;
        dfs(0, -1, tree, maxLen);
        return maxLen;
    }

    int dfs(int node, int parent, vector<vector<int>>& tree, int& maxLen) {
        int max1 = 0, max2 = 0;
        for (int child : tree[node]) {
            if (child == parent) {
                continue;
            }
            int childLen = dfs(child, node, tree, maxLen);
            if (childLen > max1) {
                max2 = max1;
                max1 = childLen;
            } else if (childLen > max2) {
                max2 = childLen;
            }
        }
        maxLen = max(maxLen, max1 + max2);
        return max1 + 1;
    }
};