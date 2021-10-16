class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aSum = 0, bSum = 0;
        for (int a : aliceSizes) {
            aSum += a;
        }
        for (int b : bobSizes) {
            bSum += b;
        }
        int diff = (aSum - bSum) / 2;
        sort(bobSizes.begin(), bobSizes.end());        
        
        for (int i = 0; i < aliceSizes.size(); i++) {
            auto iter = lower_bound(bobSizes.begin(), bobSizes.end(), aliceSizes[i] - diff);
            if (iter != bobSizes.end() && *iter == aliceSizes[i] - diff) {
                return {aliceSizes[i], *iter};
            }                
        }
        return {-1, -1};
    }
};