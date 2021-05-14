class Solution {
public:    
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;        
        for (int i = 1; i < s.length() - 2; i++) {
            vector<string> first;
            if (isValidLeft(s, 1, i)) {
                first.push_back(s.substr(0, i + 1));
            }
            if (isValidRight(s, i)) {
                for (int j = 1; j < i && isValidLeft(s, 1, j); j++) {
                    first.push_back(s.substr(0, j + 1) + "." + s.substr(j + 1, i - j));
                }
            }            
            if (isValidLeft(s, i + 1, s.length() - 2)) {
                for (string sl : first){
                    res.push_back(sl + ", " + s.substr(i + 1));
                }
            }
            if (isValidRight(s, s.length() - 2)) {
                for (int j = i + 1; j < s.length() - 2 && isValidLeft(s, i + 1, j); j++) {                
                    for (string sl : first) {
                        res.push_back(sl + ", " + s.substr(i + 1, j - i) + "." + s.substr(j + 1));
                    }
                }            
            }            
        }
        return res;
    }
    
    bool isValidLeft(string& s, int start, int end) {
        return s[start] != '0' || start == end;
    }
    
    bool isValidRight(string& s, int end) {
        return s[end] != '0';
    }        
};