class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }
        vector<int> res;
        for (auto& iter : count) {
            if (iter.second == 1 && count.find(iter.first - 1) == count.end() && count.find(iter.first + 1) == count.end()) {
                res.push_back(iter.first);
            }
        }
        return res;
    }
};