class Solution {
public:
    int sum(vector<int>& p) {
        int total = p[0];
        for (int i = 1; i < p.size(); i++) {
            if ((i == 1 && p[0] == 10) || (i >= 2 && (p[i - 1] == 10 || p[i - 2] == 10))) {
                total += 2 * p[i];
            } else {
                total += p[i];
            }
        }
        return total;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) {
        int total1 = sum(player1), total2 = sum(player2);
        if (total1 > total2) {
            return 1;
        }
        if (total1 == total2) {
            return 0;
        }
        return 2;
    }
};