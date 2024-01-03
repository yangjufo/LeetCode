class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0, si = 0, count = 0;
        while (gi < g.size() && si < s.size()) {
            if (s[si] >= g[gi]) {
                count++;
                si++;
                gi++;
            } else {
                si++;
            }
        }
        return count;
    }
};