class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> edges(quiet.size());
        for (vector<int>& r : richer) {
            edges[r[1]].push_back(r[0]);
        }
        vector<int> res(quiet.size(), -1);
        for (int i = 0; i < quiet.size(); i++) {
            dfs(edges, quiet, i, res);
        }
        return res;
    }

    int dfs(unordered_map<int, vector<int>>& edges, vector<int>& quiet, int person, vector<int>& res) {
        if (res[person] != -1) {
            return res[person];
        }
        res[person] = person;
        for (int next : edges[person]) {
            int cand = dfs(edges, quiet, next, res);
            if (quiet[cand] < quiet[res[person]]) {
                res[person] = cand;
            }
        }
        return res[person];
    }
};