class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        
        int start = 0, maxLen = 0;
        for (int i = 1; i < nums.size(); i++) {
            while (nums[i] - nums[start] > 1) {                
                start++;
            }
            if (nums[i] - nums[start] == 1) {
                maxLen = max(maxLen, i - start + 1);
            }
        }
        
        return maxLen;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }
        
        int maxLen = 0;
        for (auto& iter : count) {
            if (count.find(iter.first + 1) != count.end())
                maxLen = max(maxLen, iter.second + count[iter.first + 1]);
        }
        return maxLen;
    }
};