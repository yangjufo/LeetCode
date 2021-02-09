class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T == 0) return 0;
        sort(clips.begin(), clips.end(), [](auto& left, auto& right) {
            if (left[0] == right[0]) return left[1] < right[1];
            return left[0] < right[0];
        });
        
        int start = 0, count = 0, i = 0;
        while (i < clips.size() && start < T) {
            int curr = start;
            while (i < clips.size() && clips[i][0] <= start) {
                curr = max(curr, clips[i][1]);
                i++;
            }
            if (start == curr) {
                return - 1;
            }               
            start = curr;
            count++;            
        }
        return start >= T ? count : -1;
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, T + 1);
        dp[0] = 0;
        for (int i = 0; i <= T; i++) {
            for (auto& c : clips) {
                if (c[0] <= i && i <= c[1]) {
                    dp[i] = min(dp[i], dp[c[0]] + 1);
                }
            }
        }
        return dp[T] == T + 1 ? -1 : dp[T];
    }
};