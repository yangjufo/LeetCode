class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& left, vector<int>& right) {
            if (left[0] == right[0]) {
                return left[1] < right[1];
            }
            return left[0] < right[0];
        });
        int length = 1, prev1 = 0, prev2 = -1;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > pairs[prev1][1]) {
                length++;
                prev2 = prev1;
                prev1 = i;
            } else if (pairs[i][1] < pairs[prev1][1] && (prev2 == -1 || pairs[i][0] > pairs[prev2][1])) {
                prev1 = i;
            }
        }
        return length++;
    }
};