class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> count1, count2;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                count1[nums[i]]++;
            } else {
                count2[nums[i]]++;
            }
        }
        pair<int, int> max11 = {0, 0}, max12 = {0, 0};
        for (auto& iter : count1) {
            if (iter.second > max11.second) {
                max12 = max11;
                max11 = iter;
            } else if (iter.second > max12.second) {
                max12 = iter;
            }
        }
        pair<int, int> max21 = {0, 0}, max22 = {0, 0};
        for (auto& iter : count2) {
            if (iter.second > max21.second) {
                max22 = max21;
                max21 = iter;
            } else if (iter.second > max22.second) {
                max22 = iter;
            }
        }
        int res = nums.size();
        if (max11.first != max21.first) {
            return res - max11.second - max21.second;
        }
        return min(res - max11.second - max22.second, res - max12.second - max21.second);
    }
};