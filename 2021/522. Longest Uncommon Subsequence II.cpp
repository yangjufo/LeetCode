class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = 0;
        for (int i = 0; i < strs.size(); i++) {
            int j = 0;
            while (j < strs.size()) {
                if (i != j && isSubSeq(strs[i], strs[j])) {
                    break;
                } 
                j++;
            }
            if (j >= strs.size()) {
                maxLen = max(maxLen, (int)strs[i].length());
            }            
        }        
        return maxLen == 0 ? -1 : maxLen;
    }
    
    bool isSubSeq(string& left, string& right) {
        if (left.length() > right.length()) return false;
        int i = 0, j = 0;
        while (i < left.length() && j < right.length()) {
            if (left[i] == right[j]) {
                i++;
            }
            j++;
        }
        return i >= left.length();
    }
};