class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](vector<int>& left, vector<int>& right) {
           return left[0] > right[0]; 
        });
        pair<int, int> max1 = {INT_MIN, INT_MIN}, max2 = {INT_MIN, INT_MIN};
        int count = 0;
        for (int i = 0; i < p.size(); i++) {
            if ((max1.first > p[i][0] && max1.second > p[i][1]) || (max2.first > p[i][0] && max2.second > p[i][1])) {
                count++;
            }
            if (p[i][1] > max1.second) {
                if (max1.first != p[i][0]) {
                    max2 = max1;
                }
                max1 = {p[i][0], p[i][1]};                
            } else if (p[i][1] > max2.second) {
                if (max1.first != p[i][0]) {
                    max2 = {p[i][0], p[i][1]};
                }
            }
        }
        return count;
    }
};