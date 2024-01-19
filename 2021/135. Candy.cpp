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

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        int total = 0;
        for (int i = 0; i < ratings.size(); i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
            if (i + 1 < ratings.size() && ratings[i] > ratings[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
        }
        for (int i = ratings.size() - 1; i >= 0; i--) {
            if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
            if (i + 1 < ratings.size() && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
            total += candies[i];
        }
        return total;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        int total = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = max(candies[i], candies[i - 1] + 1);
            }
        }
        total = candies.back();
        for (int i = (int)ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            total += candies[i];
        }
        return total;
    }
};