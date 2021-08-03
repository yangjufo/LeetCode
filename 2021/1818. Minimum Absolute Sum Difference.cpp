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
                    maxGain = max(maxGain, absDiff - abs(*it - nums2[i]));
                }
                if (it != begin(tmp1)) {
                    maxGain = max(maxGain, absDiff - abs(*prev(it) - nums2[i]));
                }
            }
        }        
        absSum -= maxGain;
        return absSum % (1'000'000'007);
    }
};

class Solution {
public:
    int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp1(nums1);
        sort(tmp1.begin(), tmp1.end());
        int sum = 0, maxGain = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int absDiff = abs(nums1[i] - nums2[i]);
            sum = (sum + absDiff) % mod;
            auto iter = lower_bound(tmp1.begin(), tmp1.end(), nums2[i]);
            if (iter != tmp1.end()) {
                maxGain = max(maxGain, absDiff - abs(*iter - nums2[i]));
            }
            if (iter != tmp1.begin()) {
                maxGain = max(maxGain, absDiff - abs(*prev(iter) - nums2[i]));
            }
        }
        return (sum - maxGain + mod) % mod;
    }
};