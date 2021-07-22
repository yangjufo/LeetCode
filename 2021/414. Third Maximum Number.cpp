class Solution {
public:
    int thirdMax(vector<int>& nums) {        
        unordered_set<int> numSet(nums.begin(), nums.end());
        if (numSet.size() < 2) {
            return *numSet.begin();
        }
        if (numSet.size() < 3) {
            return *numSet.begin() > *next(numSet.begin()) ? *numSet.begin() : *next(numSet.begin());
        }
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int n : numSet) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }
        }
        return max3;
    }
};