class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) 
            return s.empty();
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        
        if (p[1] == '*')
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));        
        else
            return first_match && isMatch(s.substr(1), p.substr(1));                
    }
};