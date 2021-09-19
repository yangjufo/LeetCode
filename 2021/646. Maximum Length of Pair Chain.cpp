class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& left, vector<int>& right){
            return left[1] == right[1] ? left[0] < right[0] : left[1] < right[1];
        });
        vector<int> dp(pairs.size(), 1);
        int res = 0;
        for (int i = 0; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);                    
                }                
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& left, vector<int>& right){
            return left[1] == right[1] ? left[0] < right[0] : left[1] < right[1];
        });
        int curr = INT_MIN, ans = 0;
        for (vector<int>& pair : pairs) {
            if (curr < pair[0]) {
                curr = pair[1];
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), 1);
        int res = 1;
        for (int i = 0; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[j] + 1, dp[i]);                    
                }
            }            
        }
        return dp.back();
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& left, vector<int>& right){
            return left[1] == right[1] ? left[0] < right[0] : left[1] < right[1];
        });
        int currEnd = INT_MIN, res = 0;
        for (int i = 0; i < pairs.size(); i++) {
            if (currEnd < pairs[i][0]) {
                currEnd = pairs[i][1];
                res++; 
            }
        }
        return res;
    }
};