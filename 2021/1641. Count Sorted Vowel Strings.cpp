class Solution {
public:    
    
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    
    int countVowelStrings(int n) {        
        int dp[n + 1][5];
        for (int j = 0; j < 5; j++) {
            dp[1][j] = 1;
        }
                
        for (int i = 2; i <= n; i++) {
            int total = 0;
            for (int j = 0; j < 5; j++) {
                total += dp[i - 1][j];
                dp[i][j] = total;                
            }
        }
        
        int count = 0;
        for (int j = 0; j < 5; j++) {
            count += dp[n][j];
        }
        
        return count;
    }        
};