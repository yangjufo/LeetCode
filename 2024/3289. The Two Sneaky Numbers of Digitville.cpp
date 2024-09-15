class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> res;
        for (int n : nums) {
            counts[n] += 1;
            if (counts[n] > 1) {
                res.push_back(n);
            }
        }
        return res;
    }
};