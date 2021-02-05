class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n , false));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j <= n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : true;
                } else{
                    dp[i][j] = false;
                }
            }
        }                
        
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, dp, res, curr);
        
        return res;
    }
    
    void backtrack(string& s, int start, vector<vector<bool>>& dp, vector<vector<string>>& res, vector<string>& curr) {        
        if (start >= s.length()) {
            res.push_back(curr);
        }
        string str;
        for (int i = start; i < s.length(); i++) {
            str += s[i];
            if (dp[start][i]) {
                curr.push_back(str);
                backtrack(s, i + 1, dp, res, curr);
                curr.pop_back();
            }
        }        
    }
    
    
    
};