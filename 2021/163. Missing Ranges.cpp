class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        int left = lower, right = lower;
        for (int i = 0; i < nums.size(); i++) {
            if (left < nums[i]) {
                if (left + 1 == nums[i]) {
                    ranges.push_back(to_string(left));
                } else {
                    ranges.push_back(to_string(left) + "->" + to_string(nums[i] - 1));
                }                
            }            
            left = nums[i] + 1;            
        }    
        if (left <= upper) {
            if (left == upper) {
                ranges.push_back(to_string(left));
            } else {
                ranges.push_back(to_string(left) + "->" + to_string(upper));
            }
        }
        return ranges;
    }
};