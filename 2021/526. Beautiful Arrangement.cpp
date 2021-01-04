class Solution {
public:
    int countArrangement(int n) {
        vector<bool> taken(n + 1, false);
        int count = 0;
        backtrack(taken, 1, n, count);
        return count;        
    }
    
    void backtrack(vector<bool>& taken, int index, int n, int& count) {          
        if (index == n + 1) {
            count++;
            return;
        }
        for (int i = 1; i <= n; i++) {            
            if (taken[i] == false && (i % index == 0 || index % i == 0)) {
                taken[i] = true;
                backtrack(taken, index + 1, n, count);
                taken[i] = false;
            }
        }
    }
};

class Solution {
public:
    int countArrangement(int n) {
        vector<int> nums(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            nums[i] = i;
        }
        int count = 0;
        backtrack(nums, 1, n, count);
        return count;
    }
    
    void backtrack(vector<int>& nums, int start, int n, int& count) {
        if (start == n + 1) {
            count++;
            return;
        }
        for (int i = start; i <= n; i++) {
            if (nums[i] % start == 0 || start % nums[i] == 0) {
                swap(nums, start, i);
                
                backtrack(nums, start + 1, n, count);
                
                swap(nums, start, i);
            }
        }
    }
    
    void swap(vector<int>& nums, int left, int right) {
        if (left != right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
    }
};