class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<long> preSum;
        long sum = 0;
        for (int c : candiesCount) {
            sum += c;
            preSum.push_back(sum);
        }
        for (vector<int>& q : queries) {
            long least = q[0] == 0 ? 0 : preSum[q[0] - 1];
            long most = preSum[q[0]];
            if ((least / (long)(q[1] + 1)) >= q[2] || (long)q[1] >= most){
                res.push_back(false);
            } else {
                res.push_back(true);
            }
        }
        return res;
    }
};