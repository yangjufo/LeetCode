class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(), 0);
        res[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                res[i] =  res[i - 1] + 1;
            } else {
                res[i] = 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                res[i] = max(res[i], res[i + 1] + 1);
            }
        }
        int total = 0;
        for (int r : res) {
            total += r;
        }
        return total;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies.back();
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
};