class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int curr = 25;
        string res;
        while (curr >= 0) {
            while (count[curr] > 0) {
                res += string(min(repeatLimit, count[curr]), curr + 'a');
                count[curr] -= repeatLimit;
                if (count[curr] > 0 && curr > 0) {
                    int next = curr - 1;
                    while (next >= 0 && count[next] <= 0) {
                        next--;
                    }
                    if (next < 0) {
                        break;
                    }
                    res += next + 'a';
                    count[next]--;
                } else {
                    break;
                }
            }
            curr--;
        }
        return res;
    }
};
