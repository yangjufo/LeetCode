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