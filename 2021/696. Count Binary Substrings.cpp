class Solution {
public:
    int countBinarySubstrings(string s) {
        int total = 0, zeroCount = 0, oneCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '1') {
                    zeroCount = 0;
                }                    
                zeroCount++;                
                if (zeroCount <= oneCount) {
                     total += 1;
                }
            } else {
                if (i > 0 && s[i - 1] == '0') {
                    oneCount = 0;
                }
                oneCount++;                
                if (oneCount <= zeroCount) {
                    total += 1;
                }
            }               
        }
        return total;
    }
};