class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string minS = s, currS = s;
            for (int i = 0; i < s.length(); i++) {
                currS = currS.substr(1) + currS[0];
                minS = min(minS, currS);
            }
            return minS;
        }
        sort(s.begin(), s.end());
        return s;
    }
};