class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ns;
        for (int n : nums) {
            ns.push_back(to_string(n));
        }
        sort(ns.begin(), ns.end(), [](string& left, string& right) {
            return left + right > right + left;
        });
        string res;
        for (int i = 0; i < ns.size(); i++) {
            if (res.empty() && ns[i] == "0") {
                continue;
            }
            res += ns[i];
        }
        return res.empty() ? "0" : res;
    }
};