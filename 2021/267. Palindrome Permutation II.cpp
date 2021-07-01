class Solution {
public:
    vector<string> res;
    vector<string> generatePalindromes(string s) {
        int count[26];
        fill(count, count + 26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }        
        string base;
        for (int i = 0; i < 26; i++) {
            if ((count[i] & 0x1) == 1) {
                if (!base.empty()) return {};
                base += i + 'a';
            }            
        }                
        if (!base.empty()) {
            count[base[0] - 'a']--;
        }
        backtrack(count, base, s.length());
        return res;
    }
    
    void backtrack(int count[], string curr, int n) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                count[i] -= 2;
                backtrack(count, string(1, i + 'a') + curr + string(1, i + 'a'), n);
                count[i] += 2;
            }
        }
    }
    
};