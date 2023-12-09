class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int maxCount = 0;
        for (int n : nums) {
            counts[n]++;
            maxCount = max(maxCount, counts[n]);
        }
        vector<vector<int>> freq(maxCount + 1);
        for (auto& [n, c] : counts) {
            freq[c].push_back(n);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i >= 0 && res.size() < k; i--) {
           for (int j = 0; j < freq[i].size() && res.size() < k; j++) {
                res.push_back(freq[i][j]);
            }
        }
        return res;
    }
};