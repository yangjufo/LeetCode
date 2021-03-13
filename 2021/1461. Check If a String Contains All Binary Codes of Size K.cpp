class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k, mask = need - 1, hashVal = 0;
        vector<bool> hashValSet(need, false);
        for (int i = 0; i < (int)s.length(); i++) {            
            hashVal = (hashVal << 1) & mask | (s[i] - '0');            
            if (i >= k - 1 && !hashValSet[hashVal]) {
                hashValSet[hashVal] = true;
                need--;
                if (need <= 0) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> substrs;
        for (int i = 0; i < (int)s.length() - k + 1; i++) {
            substrs.insert(s.substr(i, k));
        }                
        return substrs.size() == int(pow(2, k));
    }
};