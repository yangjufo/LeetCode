class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrs;
        for (int n : nums) {
            numStrs.push_back(to_string(n));
        }
        
        sort(numStrs.begin(), numStrs.end(), [](string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        });
        
        if (numStrs.empty() || numStrs[0] == "0") return "0";
        
        string res;
        for (string s : numStrs) {
            res += s;
        }        
        return res;
    }
};