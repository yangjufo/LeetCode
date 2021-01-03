class Solution {
public:
    int waysToSplit(vector<int>& nums) {        
        int mod = 1000000007;
        vector<int> preSum(nums.size(), 0);
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {            
            preSum[i] = preSum[i - 1] + nums[i];
        }
        int count = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = binarySearch(preSum, i, true);
            int right = binarySearch(preSum, i, false);
            if (left != -1 && right != -1) {
                count += (right - left + 1) % mod;
                count %= mod;
            }
        }        
        return count;
    }
    
    int binarySearch(vector<int>& preSum, int left, bool leftSearch) {
        int start = left + 1, end = preSum.size() - 2;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (preSum[left] <= preSum[mid] - preSum[left] && preSum[mid] - preSum[left] <= preSum.back() - preSum[mid]) {
                ans = mid;
                if (leftSearch) end = mid - 1;
                else start = mid + 1;
            } else if (preSum[left] > preSum[mid] - preSum[left]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    } 
};

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
         const int MOD = 1000000007;
        int n = nums.size();
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        for(int i = 1; i < n; i++){
            sums[i] = sums[i-1] + nums[i];
        }
        long ans = 0;
        int hi0 = 1, hi1 = 1;
        for(int lo = 0; lo < n - 2; lo++){
            hi0 = max(hi0, lo + 1);
            while(hi0 < n - 1 && sums[hi0] - sums[lo] < sums[lo]){
                hi0++;
            }
            hi1 = max(hi0, hi1);
            while(hi1 < n - 1 && sums[n - 1] - sums[hi1] >= sums[hi1] - sums[lo]){
                hi1++;
            }
            ans += hi1 - hi0;
        }
        return ans % MOD;
    }
};