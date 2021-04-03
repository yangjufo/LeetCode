class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (string& s : strs) {
            pair<int, int> count = countZeroOnes(s);
            for (int zeroes = m; zeroes >= count.first; zeroes--) {
                for (int ones = n; ones >= count.second; ones--) {
                    dp[zeroes][ones] = max(1 + dp[zeroes - count.first][ones - count.second], dp[zeroes][ones]);
                }
            }
        }            
        return dp[m][n];
    }
    
    pair<int, int> countZeroOnes(string& s) {
        pair<int, int> count;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                count.first++;
            } else {
                count.second++;
            }
        }
        return count;
    }
};