class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> leftSmall(n), leftLarge(n), rightSmall(n), rightLarge(n);
        for (int i = 0; i < rating.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    leftSmall[i]++;
                    rightLarge[j]++;
                } else if (rating[j] > rating[i]) {
                    leftLarge[i]++;
                    rightSmall[j]++;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += leftSmall[i] * rightLarge[i] + leftLarge[i] * rightSmall[i];
        }
        return total;
    }
};