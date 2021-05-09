class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> p(101, 0);
        int maxYear = 1950;
        for (vector<int>& l : logs) {
            for (int i = l[0]; i < l[1]; i++) {
                p[i - 1950]++;
                if (p[i - 1950] > p[maxYear - 1950] || (p[i - 1950] == p[maxYear - 1950] && i < maxYear)) {
                    maxYear = i;
                }
            }
        }
        return maxYear;
    }
};