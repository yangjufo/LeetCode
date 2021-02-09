class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i <= n; i++) {
            intervals.push_back({i - ranges[i], i + ranges[i]});
        }
        
        sort(intervals.begin(), intervals.end(), [](auto& left, auto& right) {
            if (left.first == right.first) return left.second < right.second;
            return left.first < right.first;
        });
        
        int start = 0, count = 0, i = 0;
        while (i <= n && start < n) {
            int curr = start;
            while (i <= n && intervals[i].first <= start) {
                curr = max(intervals[i].second, curr);
                i++;
            }
            
            if (start == curr) {
                return -1;
            }
            
            start = curr;
            count++;
        }
        
        return start >= n ? count : -1;
    }
};

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {                
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            for (int j = left + 1; j <= right; j++) {
                dp[j] = min(dp[j], dp[left] + 1);
            }
        }
        return dp[n] == n + 2 ? -1 : dp[n];
    }
};