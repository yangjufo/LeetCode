class Solution {
public:    
    int countHomogenous(string s) {
        int mod = 1'000'000'000 + 7, count = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != s[start]) {
                start = i;
            }
            count = (count + (i - start + 1)) % mod;                
        }
        return count;
    }       
    
};