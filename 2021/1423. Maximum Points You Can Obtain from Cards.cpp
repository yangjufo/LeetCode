class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> preSum = {0};
        int sum = 0;
        for (int p : cardPoints) {
            sum += p;
            preSum.push_back(sum);
        }
        int res = 0;
        for (int i = 0; i <= k; i++) {
            res = max(res, preSum.back() - (preSum[n - k + i] - preSum[i]));
        }
        return res;
    }
};

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> preSum = {0};
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int res = sum;
        for (int i = k - 1; i >= 0; i--) {
            sum -= cardPoints[i];
            sum += cardPoints[n - (k - i)];            
            res = max(res, sum);
        }
        return res;
    }
};