class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {        
        long long absSum = 0;
        vector<int> tmp1 = nums1;
        sort(tmp1.begin(), tmp1.end());        
        int maxGain = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int absDiff = abs(nums1[i] - nums2[i]);            
            absSum += absDiff;
            if (maxGain < absDiff) {
                auto it = lower_bound(tmp1.begin(), tmp1.end(), nums2[i]);
                if (it != end(tmp1)) {
                    maxGain = max(maxGain, abs(absDiff - abs(*it - nums2[i])));
                }
                if (it != begin(tmp1)) {
                    maxGain = max(maxGain, abs(absDiff - abs(*prev(it) - nums2[i])));
                }
            }
        }        
        absSum -= maxGain;
        return absSum % (1'000'000'007);
    }
};