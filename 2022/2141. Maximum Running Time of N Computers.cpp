class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        sort(batteries.begin(), batteries.end(), greater<int>());
        vector<long long> lb;
        for (int b : batteries) {
            lb.push_back(b);
        }
        long long sum = 0;
        for (int i = n; i < lb.size(); i++) {
            sum += lb[i];
        }
        int i = n - 1;
        for (; i >= 1 && sum > n - i; i--) {
            long long diff = min(lb[i - 1] - lb[i], sum / (n - i));
            lb[i] += diff;
            sum -= diff * (n - i);
        }
        if (i == 0 || i == n - 1) {
            return lb[i] + sum / n;
        }
        return lb[i + 1] + sum / (n - i);
    }
};