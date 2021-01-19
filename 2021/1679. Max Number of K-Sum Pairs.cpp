class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int ans = 0;
        for (int n : nums) {
            if (count[k - n] > 0) {
                count[k - n]--;
                ans++;
            } else {
                count[n]++;
            }
        }
        return ans;
    }
};