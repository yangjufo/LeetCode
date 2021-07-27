class Solution {
public:
    vector<vector<int>> mem;
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        mem.resize(s1.length(), vector<int>(s2.length(), -1));
        return isInterleave(s1, 0, s2, 0, s3, 0);
    }
    
    bool isInterleave(string& s1, int start1, string& s2, int start2, string& s3, int start3) {        
        if (start1 == s1.length()) return s2.substr(start2) == s3.substr(start3);
        if (start2 == s2.length()) return s1.substr(start1) == s3.substr(start3);
        
        if (mem[start1][start2] != -1) return mem[start1][start2] == 1 ? true : false;
        
        mem[start1][start2] = ((s1[start1] == s3[start3] && isInterleave(s1, start1 + 1, s2, start2, s3, start3 + 1)) || (s2[start2] == s3[start3] && isInterleave(s1, start1, s2, start2 + 1, s3, start3 + 1))) ? 1: 0;
        
        return mem[start1][start2] == 1 ? true : false;
    }
};


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        if (s3.empty()) return true;
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));         
        for (int i = 0; i <= s1.length(); i++) {            
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } 
                if (i == 0 && j != 0) {
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                }
                if (j == 0 && i != 0) {
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                } 
                if (i != 0 && j != 0) {
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }        
        
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;        
        vector<bool> dp(s2.length() + 1, false);
        for (int i = 0; i <= s1.length(); i++) {            
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } 
                if (i == 0 && j != 0) {
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                }
                if (j == 0 && i != 0) {
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                } 
                if (i != 0 && j != 0) {
                    dp[j] = (dp[j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s2.length()];
    }        
        
};

class Solution {
public:
    vector<vector<bool>> mem;
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        mem.resize(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        return isInterleave(s1, 0, s2, 0, s3, 0);
    }
    
    bool isInterleave(string& s1, int index1, string& s2, int index2, string& s3, int index3) {        
        if (index3 >= s3.length()) return true;
        if (mem[index1][index2]) return false;
        if ((index1 < s1.length() && s1[index1] == s3[index3] && isInterleave(s1, index1 + 1, s2, index2, s3, index3 + 1)) || (index2 < s2.length() && s2[index2] == s3[index3] && isInterleave(s1, index1, s2, index2 + 1, s3, index3 + 1))) {
            return true;
        }
        mem[index1][index2] = true;
        return false;
    }
};