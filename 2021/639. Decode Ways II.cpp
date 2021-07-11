class Solution {
public:
    int mod = 1'000'000'007;
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        long long prev2 = 1, prev1 = (s[0] == '*' ? 9 : 1);                
        for (int i = 1; i < s.length(); i++) {               
            long long curr = 0;
            if (s[i] == '0') {
                if (s[i - 1] != '1' && s[i - 1] != '2' && s[i - 1] != '*') {
                    return 0;
                }
                curr = (curr + prev2) % mod;
                if (s[i - 1] == '*') {
                    curr = (curr + prev2) % mod;
                }
            }
            else if (s[i] >= '1' && s[i] <= '9') {
                curr = (curr + prev1) % mod;                
                if (s[i - 1] == '1' || s[i - 1] == '*') {
                    curr = (curr + prev2) % mod;
                } 
                if ((s[i - 1] == '*' || s[i - 1] == '2') && s[i] >= '1' && s[i] <= '6') {
                    curr = (curr + prev2) % mod;
                }                
            }
            else if (s[i] == '*') {
                curr = (curr + prev1 * 9 % mod) % mod;                
                if (s[i - 1] == '1' || s[i - 1] == '*') {
                    curr = (curr + prev2 * 9 % mod) % mod;
                }
                if (s[i - 1] == '*' || s[i - 1] == '2') {
                    curr = (curr + prev2 * 6 % mod) % mod;
                }  
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};