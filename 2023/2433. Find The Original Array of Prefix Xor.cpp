class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        for (int i = pref.size() - 1; i > 0; i--) {
            res.push_back(pref[i] ^ pref[i - 1]);
        }
        res.push_back(pref[0]);
        reverse(res.begin(), res.end());
        return res;
    }
};