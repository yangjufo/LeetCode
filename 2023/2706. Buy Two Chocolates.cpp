class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int p : prices) {
            if (p < min1) {
                min2 = min1;
                min1 = p;
            } else if (p < min2) {
                min2 = p;
            }
        }
        int leftover = money - min1 - min2;
        return leftover < 0 ? money : leftover;
    }
};