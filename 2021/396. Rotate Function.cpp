class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long sum = 0, f = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            f += i * A[i];
        }
        
        long long res = f;
        for (int i = A.size() - 1; i >= 0; i--) {
            f = f + sum - A.size() * A[i];
            res = max(res, f);
        }
        return res;
    }
};

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0, f = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            f += i * nums[i];
        }
        
        long long res = f;
        for (int i = nums.size() - 1; i >= 0; i--) {
            f = f + sum - nums.size() * nums[i];
            res = max(res, f);
        }
        
        return res;
    }
};