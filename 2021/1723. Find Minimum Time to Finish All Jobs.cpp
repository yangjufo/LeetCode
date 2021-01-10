class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        if (jobs.size() == k) {
            return *max_element(jobs.begin(), jobs.end());
        }
        vector<int> load(12, 0);
        int res = INT_MAX;        
        dfs(jobs, load, 0, k, 0, res);
        return res;
    }
    
    void dfs(vector<int>& jobs, vector<int>& load, int start, int k, int curr, int& res) {
        if (curr >= res) return;
        if (start >= jobs.size()) {            
            res = curr;
            return;
        }
        unordered_set<int> visited;
        for (int i = 0; i < k; i++) {
            if (visited.find(load[i]) != visited.end()) {
                continue;
            }
            visited.insert(load[i]);
            load[i] += jobs[start];
            dfs(jobs, load, start + 1, k, max(curr, load[i]), res);
            load[i] -= jobs[start];
        }
    }
};