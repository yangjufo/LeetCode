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

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, sum = 0, minLen = (int)nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (start <= i && sum - nums[start] >= target) {
                sum -= nums[start];
                start++;
            }        
            if (sum >= target) {
                minLen = min(minLen, i - start + 1);
            }
        }
        return minLen > nums.size() ? 0 : minLen;
    }
};