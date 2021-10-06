class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0) {                
                int index = nums[i] - 1;                
                if (nums[index] < 0) {
                    nums[index]--;
                    nums[i] = 0;
                } else {
                    int tmp = nums[index];
                    nums[index] = -1;
                    if (i != index) {
                        nums[i] = tmp;
                    }
                }                
            }            
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < -1) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for (auto num : nums) {
            if (nums[abs(num) - 1] < 0) {
                ans.push_back(abs(num));
            }
            nums[abs(num) - 1] *= -1;
        }
        
        return ans;
        
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {        
            if (nums[i] == -(i + 1)) {
                i++;
                continue;
            }
            int index = nums[i] - 1; 
            if (nums[index] == -(nums[i])) {
                res.push_back(nums[i]);
                nums[i] = 0;                
            } else {
                swap(nums[index], nums[i]);
                nums[index] = -nums[index];                
            }           
            if (nums[i] == 0) {
                i++;
            }
        }
        return res;
    }
};