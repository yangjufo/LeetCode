class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};
        
        unordered_map<int, int> nCount;
        for (int n : changed) {
            nCount[n]++;
        }        
        vector<int> res;
        sort(changed.begin(), changed.end());
        for (int n : changed) {
            if (nCount[n] > 0) {
                if (nCount[2 * n] <= 0) {
                    return {};
                }
                nCount[2 * n]--;                
                nCount[n]--;
                res.push_back(n);
            }
        }
        return res;
    }
};