class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.length(); i++) {            
            if (s[i] == '0') {
                if (i <= 0 || s[i-1] <= '0' || s[i-1] >= '3') {
                    return 0;
                }
                dp[i + 1] += dp[i - 1];
            } else {
                dp[i + 1] += dp[i];
            }
            if (i >= 1 && s[i] >= '1' && s[i] <= '6' && s[i - 1] >= '1' && s[i - 1] <='2') {
                dp[i + 1] += dp[i - 1];
            }
            if (i >= 1 && s[i] >= '7' && s[i] <= '9' && s[i - 1] == '1') {
                dp[i + 1] += dp[i - 1];
            }            
        }
        return dp[s.length()];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int prev2 = 1, prev1 = 1;
        for (int i = 0; i < s.length(); i++) {
            int curr = 0;
            if (s[i] == '0') {
                if (i == 0 || s[i - 1] < '1' || s[i - 1] >= '3') {
                    return 0;
                }
                curr = prev2;
            } else {
                curr += prev1;
                if (i > 0 && ((s[i] >= '1' && s[i] <= '6' && s[i - 1] == '2') || s[i - 1] == '1')) {
                    curr += prev2;
                }
            }
            prev2 = prev1; 
            prev1 = curr;
        }
        return prev1;
    }
};