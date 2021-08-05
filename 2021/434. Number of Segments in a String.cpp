class Solution {
public:
    int countSegments(string s) {
        int count = 0, i = 0;
        while (i < s.length()) {
            int start = i;
            while (i < s.length() && s[i] != ' ') {
                i++;
            }
            count += (i > start ? 1 : 0);
            i++;
        }
        return count;
    }
};