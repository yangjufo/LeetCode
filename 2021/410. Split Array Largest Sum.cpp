class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size(), sum = 0;
        for (int n : nums) {
            sum += n;
        }
        vector<vector<int>> mem(n, vector<int>(m + 1, INT_MAX));
        return dfs(nums, m - 1, 0, m == 1 ? sum : (sum * 2) / (m - 1), mem);        
    }
    
    int dfs(vector<int>& nums, int m, int index, int totalSum, vector<vector<int>>& mem) {
        if (index >= nums.size()) {
            return 0;
        }        
        if (mem[index][m] < INT_MAX) return mem[index][m];
        int currSum = 0;
        for (int i = index; i + m < nums.size(); i++) {
            currSum += nums[i];               
            if (m > 0) {
                mem[index][m] = min(mem[index][m], max(currSum, dfs(nums, m - 1, i + 1, totalSum, mem)));      
            } else {
                mem[index][m] = currSum;
            }  
            if (m > 0 && currSum > totalSum) {
                break;
            }
        }
        return mem[index][m];
    }
};

#define LL long long
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        LL l = 0, r = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            r += nums[i];
            if (l < nums[i]) {
                l = nums[i];
            }
        }
        LL ans =  r;
        while (l <= r) {
            LL mid = (l + r) >> 1;
            LL sum = 0;
            int cnt = 1;            
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    cnt ++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (cnt <= m) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};