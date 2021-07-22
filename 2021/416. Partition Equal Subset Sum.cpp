class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> count(101, 0);
        int sum = 0;
        for (int n : nums) {
            sum += n;
            count[n]++;
        }
        if (sum % 2 != 0) return false;
        vector<vector<int>> dp(sum / 2 + 1, vector<int>(102, 0));
        count.push_back(1);
        dp[0] = count;        
        for (int i = 0; i <= sum / 2; i++) {            
            for (int j = 0; j <= i; j++) {
                if (dp[j][101] == 1 && i - j <= 100 && dp[j][i - j] > 0) {
                    dp[i] = dp[j];                    
                    dp[i][i - j]--;
                    break;
                }
            }
        }
        return dp[sum / 2][101];
    }
};