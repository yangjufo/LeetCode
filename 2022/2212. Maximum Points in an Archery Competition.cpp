class Solution {
public:
    vector<int> res;
    int maxScore;
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        maxScore = 0;
        res.resize(aliceArrows.size(), 0);
        vector<int> bobArrows(aliceArrows.size(), 0);
        backtrack(aliceArrows, bobArrows, numArrows, 0, 0);
        return res;
    }

    void backtrack(vector<int>& aliceArrows, vector<int>& bobArrows, int numArrows, int score, int index) {
        if (score > maxScore) {
            maxScore = score;
            res = bobArrows;
            if (numArrows > 0) {
                res[0] += numArrows;
            }
        }
        if (index >= bobArrows.size() || numArrows <= 0) {
            return;
        }
        if (numArrows > aliceArrows[index]) {
            bobArrows[index] = aliceArrows[index] + 1;
            backtrack(aliceArrows, bobArrows, numArrows - bobArrows[index], score + index, index + 1);
        }
        bobArrows[index] = 0;
        backtrack(aliceArrows, bobArrows, numArrows, score, index + 1);
    }
};