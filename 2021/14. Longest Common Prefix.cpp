class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        int i = 0;
        while (i < strs[0].length()) {            
            char c = strs[0][i];
            int k = 1;
            for (; k < strs.size(); k++) {
                if (i >= strs[k].length() || strs[k][i] != c) {
                    break;
                }
            }
            if (k != strs.size()) {
                break;
            }
            i++;
        }
        return strs[0].substr(0, i);
    }
};