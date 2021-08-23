class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }
        int prev2 = 0, prev1 = 0;
        for (auto iter = count.begin(); iter != count.end(); iter++) {
            int curr = 0;
            if (iter == count.begin() || iter->first != prev(iter)->first + 1) {
                curr = max(prev2, prev1) + iter->first * iter->second;
            } else {
                curr = max(prev2 + iter->first * iter->second, prev1);
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};