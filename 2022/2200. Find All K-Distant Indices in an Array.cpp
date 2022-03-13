class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = -k; j <= k; j++) {
                if (i + j < 0 || i + j >= nums.size()) {
                    continue;
                }
                if (nums[i + j] == key) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};