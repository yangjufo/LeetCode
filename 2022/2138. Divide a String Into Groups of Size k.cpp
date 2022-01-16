class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string curr;
        for (int i = 0; i < s.length(); i++) {
            if (i % k == 0 && i > 0) {
                res.push_back(curr);
                curr = "";
            }
            curr += s[i];
        }
        while (curr.length() < k) {
            curr += fill;
        }
        res.push_back(curr);
        return res;
    }
};