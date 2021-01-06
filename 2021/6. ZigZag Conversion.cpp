class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> rows(numRows, "");
        int curr = 0, delta = 1;    
        for (int i = 0; i < s.length(); i++) {
            rows[curr] += s[i];
            curr += delta;
            if (curr >= numRows) {
                curr -= 2;
                delta = -1;
            } else if (curr < 0) {
                curr += 2;
                delta = 1;
            }
        }
        string ans;
        for (string& str : rows) {
            ans += str;
        }
        return ans;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string ans;
        int n = s.size(), cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ans += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    ans += s[j + cycleLen - i];
                }
            }
        }
        
        return ans;
    }
};