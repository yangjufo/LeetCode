class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> zCount(nums.size(), 0), oCount(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            zCount[i] = i == 0 ? 0 : zCount[i - 1];
            if (nums[i] == 0) {
                zCount[i]++;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            oCount[i] = oCount[i + 1];
            if (nums[i] == 1) {
                oCount[i]++;
            }
        }
        int maxScore = 0;
        vector<int> res;
        for (int i = 0; i <= nums.size(); i++) {
            int score = (i == 0 ? 0 : zCount[i - 1]) + oCount[i];
            if (score > maxScore) {
                res.clear();
                res.push_back(i);
                maxScore = score;
            } else if (score == maxScore) {
                res.push_back(i);
            }
        }
        return res;
    }
};