class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        unordered_set<long> candidates;
        candidates.insert((long)pow(10, len) + 1);
        candidates.insert((long)pow(10, len - 1) - 1);
        
        long left = stol(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; i++) {
            string p = to_string(left + i);
            string pp = p + string(p.rbegin() + (len & 0x1), p.rend());
            candidates.insert(stol(pp));              
        }
        long ans = 0, minDiff = LONG_MAX;
        long nLong = stol(n);
        candidates.erase(nLong);
        for (long can : candidates) {
            long diff = abs(can - nLong);
            if (diff < minDiff) {
                minDiff = diff;
                ans = can;
            } else if (diff == minDiff && can < ans) {
                ans = can;
            }
        }
        return to_string(ans);
    }
};