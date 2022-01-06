class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       unordered_map<int, int> picks, drops;
        for (vector<int>& t : trips) {
            picks[t[1]] += t[0];
            drops[t[2]] += t[0];
        }
        int curr = 0;
        for (int i = 0; i <= 1000 && curr <= capacity; i++) {
            curr = curr + picks[i] - drops[i];
        }
        return curr <= capacity;
    }
};