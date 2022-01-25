class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> left(seats.size(), 0);
        int prev = -(int)seats.size();
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 0) {
                left[i] = i - prev;
            } else {
                prev = i;
            }
        }
        prev = (int)seats.size() * 2;
        int res = 0;
        for (int i = (int)seats.size() - 1; i >= 0; i--) {
            if (seats[i] == 0) {
                res = max(res, min(left[i], prev - i));
            } else {
                prev = i;
            }
        }
        return res;
    }
};