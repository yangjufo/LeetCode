class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size(), sum = 0;
        vector<int> candiesLeft(N, 1), candiesRight(N, 1);
        for (int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candiesLeft[i] = candiesLeft[i - 1] + 1;
            }
        }
        for (int i = N - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candiesRight[i] = candiesRight[i + 1] + 1;
            }
        }
        for (int i = 0; i < N; i++) {
            sum += max(candiesLeft[i], candiesRight[i]);
        }
        return sum;
    }
};