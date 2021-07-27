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

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int left, int right) {
            string leftStr = to_string(left), rightStr = to_string(right);
            return leftStr + rightStr > rightStr + leftStr;            
        });
        string res;
        for (int n : nums) {
            if (res.empty() && n == 0) continue;
            res += to_string(n);
        }
        return res.empty() ? "0" : res;
    }
};