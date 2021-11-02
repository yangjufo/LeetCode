class Solution {
public:
    int numSquares(int n) {
        vector<int> sqs;
        for (int i = 1; i * i <= n; i++) {
            sqs.push_back(i * i);
        }
        
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < sqs.size() && sqs[j] <= i; j++) {
                dp[i] = min(dp[i], dp[i - sqs[j]] + 1);
            }            
        }
        return dp[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; i * i <= n; i++) {
            nums.push_back(i * i);
        }
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < nums.size() && nums[j] <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
            }
        }
        return dp[n];
    }
};