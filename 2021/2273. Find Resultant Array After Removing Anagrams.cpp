class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string curr;
        for (string& w : words) {
            string tmp = w;
            sort(tmp.begin(), tmp.end());
            if (curr.empty() || tmp != curr) {
                res.push_back(w);
            }
            curr = tmp;
        }
        return res;
    }
};