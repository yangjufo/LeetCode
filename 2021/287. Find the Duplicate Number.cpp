class Solution {
public:
    int findDuplicate(vector<int>& nums) {        
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while(tortoise != hare);
        
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size(), dup = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = smallerOrEqual(nums, mid);
            if (count > mid) {
                dup = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return dup;
    }
    
    int smallerOrEqual(vector<int>& nums, int curr) {
        int count = 0;
        for (int n : nums) {
            if (n <= curr) {
                count++;
            }
        }
        return count;
    }
};