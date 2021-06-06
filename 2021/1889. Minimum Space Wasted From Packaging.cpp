class Solution {
public:
    int mod = 1'000'000'007;
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size(), m = boxes.size();
        sort(packages.begin(), packages.end());
        vector<long long> preSum(n + 1, 0);        
        for (int i = 1; i <= packages.size(); i++) {
            preSum[i] = preSum[i - 1] + (long long)packages[i - 1];
        }
        long long minVal = 1e18;
        for (vector<int>& box : boxes) {
            long long curr = 0, prev = 0;
            sort(box.begin(), box.end());
            if (box.back() < packages.back()) continue;
            for (long long b : box) {
                long long pos = upper_bound(packages.begin(), packages.end(), b) - packages.begin();
                curr += b * (pos - prev) - preSum[pos] + preSum[prev]; 
                prev = pos;                
            }            
            minVal = min(minVal, curr);
        }
        return minVal == 1e18 ? -1 : minVal % mod;
    }
};