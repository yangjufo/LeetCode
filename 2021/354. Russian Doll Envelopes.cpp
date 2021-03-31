class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto& left, auto& right) {
           return (left[0] == right[0]) ? left[1] < right[1] : left[0] < right[0]; 
        });
        vector<int> dp(envelopes.size(), 1);
        int maxDepth = 1;
        for (int i = 0; i < envelopes.size(); i++) {            
            for (int j = i + 1; j < envelopes.size(); j++) {
                if (envelopes[i][0] < envelopes[j][0] && envelopes[i][1] < envelopes[j][1]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    maxDepth = max(dp[j], maxDepth);
                }
            }
        }        
        return maxDepth;
    }         
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto& left, auto& right) {
           return (left[0] == right[0]) ? left[1] > right[1] : left[0] < right[0]; 
        });
        vector<int> dp;
        for (auto& env : envelopes) {
            int index = binarySearch(dp, env[1]);
            if (index >= dp.size()) {
                dp.push_back(env[1]);
            } else{
                dp[index] = env[1];
            }
        }
        return dp.size();
    }  
    
    int binarySearch(vector<int>& dp, int target) {
        int left = 0, right = dp.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};