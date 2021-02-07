class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res = 0, pos = 0, neg = 0;        
        for (int n : nums) {
            pos += n;
            neg += n;
            if (pos < 0) pos = 0;
            if (neg > 0) neg = 0;
            res = max(res, max(abs(pos), abs(neg)));
        }
        return res;
    }
};