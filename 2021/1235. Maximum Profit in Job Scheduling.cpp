class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> intervals;
        for (int i = 0; i < startTime.size(); i++) {
            intervals.push_back({startTime[i], endTime[i], profit[i]});            
        }
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& left, vector<int>& right) { return (left[1] == right[1]) ? left[0] < right[0] : left[1] < right[1]; });        
        vector<int> dp(startTime.size() + 1, 0);
        for (int i = 0; i < intervals.size(); i++) {  
            int index = binarySearch(intervals, 0, i - 1, intervals[i][0]);
            dp[i + 1] = max(dp[i], dp[index + 1] + intervals[i][2]);
        }
        
        return dp.back();
    }
    
    int binarySearch(vector<vector<int>>& intervals, int left, int right, int startTime) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][1] > startTime) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return intervals[left][1] > startTime ? left - 1 : left;
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int, 3>> times;
        for (int i = 0; i < startTime.size(); i++) {
            times.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(times.begin(), times.end(), [](auto& left, auto& right) {
            return left[1] == right[1] ? left[0] < right[0] : left[1] < right[1];
        });
        
        vector<int> dp(times.back()[1] + 1);
        int index = 0;
        
        for (int i = 1; i < dp.size(); i++) {            
            dp[i] = dp[i - 1];
            while (index < times.size() && i == times[index][1]) {
                dp[i] = max(dp[i], dp[times[index][0]] + times[index][2]);
                index++;
            }
        }
        return dp.back();
    }
};