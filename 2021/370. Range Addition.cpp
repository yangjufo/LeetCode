class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> preSum(length + 1, 0);
        for (vector<int>& u : updates) {
            preSum[u[1] + 1] += u[2];
            preSum[u[0]] -= u[2];
        }
        vector<int> res(length, 0);
        int curr = 0;
        for (int i = length - 1; i >= 0; i--) {
            curr += preSum[i + 1];
            res[i] = curr;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> preSum(length + 1, 0);
        for (vector<int>& u : updates) {
            preSum[u[1] + 1] += u[2];
            preSum[u[0]] -= u[2];
        }
        
        vector<int> res(length, 0);
        int curr = 0;
        for (int i = length - 1; i >= 0; i--) {
            curr += preSum[i + 1];
            res[i] = curr;
        }
        return res;
    }
};