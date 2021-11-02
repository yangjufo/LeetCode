class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < nums.size()) {
            twoSum(nums, i + 1, nums.size() - 1, nums[i], ans);
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;            
        }
        return ans;
    }
    
    void twoSum(vector<int>& nums, int left, int right, int firstNum, vector<vector<int>>& ans) {        
        while (left < right) {
            if (nums[left] + nums[right] + firstNum == 0) {
                ans.push_back({firstNum, nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;                
            } else if (nums[left] + nums[right] + firstNum > 0) {
                right--;
            } else {
                left++;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> two = twoSum(nums, -nums[i], i + 1);
            for (vector<int>& t : two) {
                t.push_back(nums[i]);
                res.push_back(t);
            }            
        }
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int left) {
        int right = (int)nums.size() - 1;
        vector<vector<int>> res;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                res.push_back({nums[left], nums[right]});
                while (left > 0 && left < right && nums[left + 1] == nums[left]) {
                    left++;
                }
                while (right > left && right < (int)nums.size() && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // [-4, -1, -1, 0, 1, 2]
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {            
            if (i != 0 && nums[i] == nums[i - 1]) { //[1,1,1,2,3]
                continue;
            }
            vector<vector<int>> twos = twoSum(nums, i + 1, -nums[i]);
            for (vector<int>& t : twos) {
                t.push_back(nums[i]);
                res.push_back(t);
            }
        }
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> res;
        int left = start, right = (int)nums.size() - 1;
        while (left < right) {                                    
            if (nums[left] + nums[right] == target) {
                res.push_back({nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }  
                left++;
                right--;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
    
    //[1,2,3,4,5,6,7]
};