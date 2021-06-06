class Solution {
public:
    int minFlips(string s) {
        int oneCount = 0, zeroCount = 0, n = s.length();
        for (int i = 0; i < s.length(); i++) {
            if ((i & 0x1) == 0) {
                if (s[i] != '1') {
                    oneCount++;
                } else {
                    zeroCount++;                
                }
            } else {
                if (s[i] != '0') {
                    oneCount++;
                } else {
                    zeroCount++;                
                }                
            }            
        }
        int res = min(zeroCount, oneCount);        
        for (int i = 0; i < s.length() && (n & 0x1) == 1; i++) {
            swap(zeroCount, oneCount);            
            if (s[i] == '0') {
                zeroCount -= 1;
                oneCount += 1;
            } else {
                oneCount -= 1;
                zeroCount += 1;
            }
            res = min(res, min(zeroCount, oneCount));
        }
        return res;
    }
};