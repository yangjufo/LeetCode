class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, longest = 0, flip = 0;        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                flip++;                
                while (flip > k && start < nums.size()) {
                    if (nums[start] == 0) {                        
                        flip--;
                    }
                    start++;                    
                }                
            }
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};