class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        bool findOne = false;
        for (int num : nums) {
            if (num == 1) {
                findOne = true;
                break;
            }
        }
        
        if (!findOne) return 1;
        if (n == 1) return 2;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int a = abs(nums[i]);
            
            if (a == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[a] = -abs(nums[a]);
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }
        
        if (nums[0] > 0) return n;
        return n + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] <= 0 || nums[i] > N) {
                nums[i] = 0;
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (nums[i] <= 0 ) continue;
            
            int tmp = nums[i];
            nums[i] = 0;
            while (tmp > 0) {
                int index = tmp - 1;
                tmp = nums[index];                
                nums[index] = -1;                
            }            
        }
        
        for (int i = 0; i < N; i++) {
            if (nums[i] != -1) return i + 1;
        }
        return N + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > n || nums[i] <= 0) {
                nums[i] = -1;
            }            
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) continue;
            int index = nums[i] - 1;
            nums[i] = -1;
            while (index >= 0) {                
                int next = nums[index] - 1;
                nums[index] = -2;
                index = next;
            }
        }
        
        for (int i = 0; i < n; i++) {            
            if (nums[i] == -1) return i + 1;
        }
        return n + 1;        
    }
};