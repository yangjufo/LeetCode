class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string res;
        while (true) {
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j].length() <= i || (j > 0 && strs[j][i] != strs[j - 1][i])) {
                    return res;
                }
            }
            res += strs[0][i];
            i++;
        }
        return res;
    }
};