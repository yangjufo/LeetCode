class Solution {
    int advance(vector<int>& nums, int curr, int n) {
        curr += nums[curr];
        while (curr < 0) {
            curr += n;
        }
        return curr % n;
    }
    
public:
    bool circularArrayLoop(vector<int>& nums) {        
        int n = nums.size();
        if (n <= 1) return false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int slow = i, fast = advance(nums, i, n);
            while (nums[i] * nums[fast] > 0 && nums[i] * nums[advance(nums, fast, n)] > 0) {                
                if (slow == fast) {
                    if (slow == advance(nums, slow, n)) break;
                    return true;
                }
                slow = advance(nums, slow, n);
                fast = advance(nums, advance(nums, fast, n), n);
            }
            
            slow = i;
            int sign = nums[i];
            while (sign * nums[slow] > 0) {
                int tmp = advance(nums, slow, n);
                nums[slow] = 0;
                slow = tmp;
            }
        }
        return false;
    }
};