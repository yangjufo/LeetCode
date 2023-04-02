class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int n : nums) {
            counts[n]++;
        }
        vector<vector<int>> res;
        for (auto& [num, count] : counts) {
            for (int i = 0; i < count; i++) {
                if (i >= res.size()) {
                    res.push_back({num});
                } else {
                    res[i].push_back(num);
                }
            }
        }
        return res;
    }
};