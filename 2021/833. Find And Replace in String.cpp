class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        map<int, string> sourceMap, targetMap;
        for (int i = 0; i < indices.size(); i++) {
            sourceMap[indices[i]] = sources[i];
            targetMap[indices[i]] = targets[i];
        }
        string res;
        int i = 0;        
        while (i < s.length()) {
            if (sourceMap.find(i) != sourceMap.end() && s.substr(i, sourceMap[i].length()) == sourceMap[i]) {
                res += targetMap[i];
                i += sourceMap[i].length();
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};