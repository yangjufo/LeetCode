class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int aLen = nums1.size(), bLen = nums2.size();
        if (aLen > bLen) {
            auto tmpNums = nums2;
            nums2 = nums1;
            nums1 = tmpNums;
            int tmpLen = bLen;
            bLen = aLen;
            aLen = tmpLen;
        }
                
        int halfCount = (aLen + bLen + 1) / 2;
        int aMinCount = 0, aMaxCount = aLen;
        while (aMinCount <= aMaxCount) {
            int aCount = aMinCount + (aMaxCount - aMinCount) / 2;
            int bCount = halfCount - aCount;
            if (aCount > 0 && nums1[aCount - 1] > nums2[bCount]) {
                aMaxCount = aCount - 1;
            } else if (aCount < aLen && nums2[bCount - 1] > nums1[aCount]) {
                aMinCount = aCount + 1;
            } else {
                int leftMax = (aCount == 0)
                    ? nums2[bCount - 1]
                    : ((bCount == 0) ? nums1[aCount - 1] : max(nums1[aCount - 1], nums2[bCount - 1]));
                if (((aLen + bLen) & 0x1) == 1) return leftMax;
                
                int rightMin = (aCount == aLen)
                    ? nums2[bCount]
                    : ((bCount == bLen) ? nums1[aCount] : min(nums1[aCount], nums2[bCount]));
                
                return (leftMax + rightMin) / 2.0;
            }             
        }
        return 0.0;
    }
};