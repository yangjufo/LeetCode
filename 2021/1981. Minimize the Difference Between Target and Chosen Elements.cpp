class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int minSum = 0, maxSum = 0;
        for (int i = 0; i < mat.size(); i++) {
            sort(mat[i].begin(), mat[i].end());
            minSum += mat[i][0];
            maxSum += mat[i].back();
        }
        if (minSum >= target) {
            return minSum - target;
        }
        if (target >= maxSum) {
            return target - maxSum;
        }
        
        int res = min(abs(minSum - target), abs(maxSum - target));
        unordered_set<int> cand = {0};
        for (int i = 0; i < mat.size(); i++) {
            unordered_set<int> next;            
            for (int c : cand) {
                for (int n : mat[i]) {
                    if (n + c > target && abs(n + c - target) > res) {
                        break;
                    }
                    next.insert(n + c);
                }
            }
            cand = next;
        }
        for (int c : cand) {
            res = min(res, abs(c - target));
        }
        return res;
    }
};

class Solution {
public:
    int dp[71][70 * 70 + 1] = {[0 ... 70][0 ... 70 * 70] = INT_MAX};
    int dfs(vector<set<int>>& m, int i, int sum, int target) {
        if (i >= m.size())
            return abs(sum - target);
        if (dp[i][sum] == INT_MAX)
            for (auto it = begin(m[i]); it != end(m[i]); ++it) {
                int res = min(dp[i][sum], dfs(m, i + 1, sum + *it, target));
                if (res < dp[i][sum])
                    dp[i][sum] = res;
                else
                    break;
            }
        return dp[i][sum];
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<set<int>> m;
        for (auto &v : mat)
            m.push_back(set<int>(begin(v), end(v)));
        return dfs(m, 0, 0, target);
    }
};