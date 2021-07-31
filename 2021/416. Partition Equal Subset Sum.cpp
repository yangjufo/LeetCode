class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> count(101, 0);
        int sum = 0;
        for (int n : nums) {
            sum += n;
            count[n]++;
        }
        if (sum % 2 != 0) return false;
        vector<vector<int>> dp(sum / 2 + 1, vector<int>(102, 0));
        count.push_back(1);
        dp[0] = count;        
        for (int i = 0; i <= sum / 2; i++) {            
            for (int j = 0; j <= i; j++) {
                if (dp[j][101] == 1 && i - j <= 100 && dp[j][i - j] > 0) {
                    dp[i] = dp[j];                    
                    dp[i][i - j]--;
                    break;
                }
            }
        }
        return dp[sum / 2][101];
    }
};

class Solution {
public:
    vector<vector<int>> mem;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) return false;        
        mem.resize(nums.size(), vector<int>(sum / 2 + 1, -1));
        return dfs(nums, 0, 0, sum / 2);
    }
    
    bool dfs(vector<int>& nums, int index, int curr, int target) {
        if (curr == target) return true;
        if (index >= nums.size() || curr > target) return false;        
        if (mem[index][curr] >= 0) return mem[index][curr] == 1;
        
        bool res = dfs(nums, index + 1, curr + nums[index], target) || dfs(nums, index + 1, curr, target);
        mem[index][curr] = res;
        return mem[index][curr];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) return false;        
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum / 2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= sum / 2; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || (dp[i - 1][j - nums[i - 1]]);
                }
            }
        }
        return dp[nums.size()][sum / 2];
    }        
};