class Solution {
public:
    int maxProduct(string s) {
        unordered_map<int, vector<int>> count;        
        backtrack(s, 0, "", 0, count);
        int maxPro = 0;
        for (int i = (int)s.length(); i >= 1; i--) {
            for (int a : count[i]) {
                // cout << i << " " << bitset<4>(a) << endl;
                for (int j = i; j >= 1; j--) {
                    for (int b : count[j]) {
                        // cout << j << " " << bitset<4>(b) << " " << (a & b) << endl;
                        if ((a & b) == 0) {
                            maxPro = max(maxPro, i * j);
                        }
                    }
                }
            }            
        }
        return maxPro;
    }
    
    void backtrack(string& s, int index, string curr, int bits, unordered_map<int, vector<int>>& count) {                
        if (index >= s.length()) {
            if (!curr.empty() && isP(curr)) {
                count[curr.length()].push_back(bits);
            }
            return;
        }                
        backtrack(s, index + 1, curr, bits, count);        
        bits |= (1 << index);
        backtrack(s, index + 1, curr + s[index], bits, count);
    }
    
    bool isP(string& s) {
        int left = 0, right = (int)s.length() - 1;
        while (left < right && s[left] == s[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
};