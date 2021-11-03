class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp; // the maximum subsequence length ending with the key 
        int res = 0;
        for (int i = 0; i < (int)arr.size(); i++) {            
            if (dp.find(arr[i] - difference) != dp.end()) {
                dp[arr[i]] = max(dp[arr[i]], dp[arr[i] - difference] + 1);
            }
            dp[arr[i]] = dp.find(arr[i]) == dp.end() ? 1 : dp[arr[i]];
            res = max(res, dp[arr[i]]);
        }        
        return res;
    }
};