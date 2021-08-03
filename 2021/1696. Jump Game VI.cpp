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

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> maxes; // value, index
        for (int i = 0; i < nums.size(); i++) {
            while (!maxes.empty() && maxes.back().second + k < i) {
                maxes.pop_back();              
            }            
            int currMax = (maxes.empty() ? 0 : maxes.back().first) + nums[i];
            while (!maxes.empty() && maxes.front().first <= currMax) {
                maxes.pop_front();
            }
            maxes.push_front({currMax, i});
        }
        return maxes.front().first;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        deque<int> maxQueue;
        maxQueue.push_front(0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            while (!maxQueue.empty() && maxQueue.front() + k < i) {
                maxQueue.pop_front();
            }
            dp[i] = dp[maxQueue.front()] + nums[i];
            while (!maxQueue.empty() && dp[maxQueue.back()] <= dp[i]) {
                maxQueue.pop_back();
            }
            maxQueue.push_back(i);
        }
        return dp[(int)nums.size() - 1];
    }
};