class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxD = 1, prev = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (prev == -1 && i != 0) {
                    maxD = i - prev -1;
                } else {
                    maxD = max(maxD, (i - prev) / 2);
                }
                prev = i;
            }
        }
        maxD = max(maxD, (int)seats.size() - prev - 1);
        return maxD;
    }
};