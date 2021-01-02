class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, start = 0, minLen = nums.size() + 10;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];            
            while (sum >= s) {                
                if (i - start + 1 < minLen) {
                    minLen = i - start + 1;
                }
                sum -= nums[start];
                start++;
            }
        }
        return minLen > nums.size() ? 0 : minLen;
    }
};