class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), count = 0, prev = 0;
        for (int i = 3; i <= n; i++) {
            if (A[i - 1] - A[i - 2] == A[i - 2] - A[i - 3]) {
                count += prev + 1;                
                prev += 1;
            } else {
                prev = 0;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int currDiff = nums[1] - nums[0], total = 0, count = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == currDiff) {
                count++;
            } else {                
                total += (1 + count - 2) * (count - 2) / 2;
                count = 2;
                currDiff = nums[i] - nums[i - 1];
            }
        }
        return total + (1 + count - 2) * (count - 2) / 2;
    }
};