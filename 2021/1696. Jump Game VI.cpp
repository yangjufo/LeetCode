class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int dp[nums.size()];
        deque<int> maxQueue;
        maxQueue.push_back(0);        
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {            
            dp[i] = nums[i] + dp[maxQueue.front()]; 
            while (!maxQueue.empty() && dp[maxQueue.back()] < dp[i]) {
                maxQueue.pop_back();                
            }
            while (!maxQueue.empty() && maxQueue.front() <= i - k) {                
                maxQueue.pop_front();
            }            
            maxQueue.push_back(i);            
        }
        return dp[nums.size() - 1];
    }
};