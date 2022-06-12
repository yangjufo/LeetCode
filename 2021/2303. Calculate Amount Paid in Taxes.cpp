class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0.0;
        for (int i = 0; i < brackets.size() && income > 0; i++) {
            if (i == 0) {
                tax += min(income, brackets[i][0]) * brackets[i][1] / 100.0;
                income -= brackets[i][0];
            } else {
                tax += min(income, brackets[i][0] - brackets[i - 1][0]) * brackets[i][1] / 100.0;
                income -= brackets[i][0] - brackets[i - 1][0];
            }
        }
        return tax;
    }
};