class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1, tmp = 0;
        for (int i = 0; i <= n; i++) {
            tmp ^= i;
            if (i < n && (i & 0x1 == 1)) {
                tmp ^= encoded[i];
            }
        }        
        vector<int> res = { tmp };
        for (int i = 0; i < n - 1; i++) {
            tmp ^= encoded[i];
            res.push_back(tmp);            
        }
        return res;
    }
};