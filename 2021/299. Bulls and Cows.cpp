class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> countS(10, 0), countG(10, 0);
        int bulls = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                countS[secret[i] - '0']++;
                countG[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; i++) {
            cows += min(countS[i], countG[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};