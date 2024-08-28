class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int index = 0;
        while (true) {
            for (int i = 0; i < strs.size(); i++) {
                if (index >= strs[i].length() || strs[i][index] != strs[0][index]) {
                    return prefix;
                }
            }
            prefix += strs[0][index];
            index += 1;
        }
        return prefix;
    }
};