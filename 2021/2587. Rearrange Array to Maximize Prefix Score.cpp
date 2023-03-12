class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long prefix = 0, i = 0;
        while((i == 0 || prefix > 0) && i < nums.size()) {
            prefix += nums[i];
            i++;
        }
        return prefix > 0 ? i : i - 1;
    }
};