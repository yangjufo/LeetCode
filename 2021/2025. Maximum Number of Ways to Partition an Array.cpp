class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        vector<long long> preSum;        
        long long sum = 0;
        for (int n : nums) {
            sum += n;
            preSum.push_back(sum);
        }
        unordered_map<long long, long long> preCount;
        vector<long long> ways(nums.size(), 0);        
        long long res = 0;
        for (int i = 1; i < nums.size(); i++) {
            preCount[preSum.back() - preSum[i - 1] - preSum[i - 1]]++;
            ways[i] = preCount[nums[i] - k];
            res = max(ways[i], max(preCount[0], res));
        }
        unordered_map<long long, long long> postCount;
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            postCount[preSum.back() - preSum[i] - preSum[i]]++;
            ways[i] += postCount[k - nums[i]];
            res = max(ways[i], max(postCount[0], res));
        }
        return res;
    }
};