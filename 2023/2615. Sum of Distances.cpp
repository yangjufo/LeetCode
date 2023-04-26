class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]].push_back(i);
        }
        vector<long long> res(nums.size());
        for (auto& [_, indexes] : numMap) {
            vector<long long> ldis(indexes.size(), 0), rdis(indexes.size(), 0);
            for (int i = 1; i < indexes.size(); i++) {
                ldis[i] = ldis[i - 1] + i * (indexes[i] - indexes[i - 1]);
            }
            for (int i = indexes.size() - 2; i > - 1; i--) {
                rdis[i] = rdis[i + 1] + (indexes.size() - 1 - i) * (indexes[i + 1] - indexes[i]);
            }
            for (int i = 0 ; i < indexes.size(); i++) {
                res[indexes[i]] = ldis[i] + rdis[i];
            }
        }
        return res;
    }
};