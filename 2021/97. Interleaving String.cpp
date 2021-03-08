class Solution {
public:
    vector<vector<int>> mem;
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        mem.resize(s1.length(), vector<int>(s2.length(), -1));
        return isInterleave(s1, 0, s2, 0, s3, 0);
    }
    
    bool isInterleave(string& s1, int start1, string& s2, int start2, string& s3, int start3) {        
        if (start1 == s1.length()) return s2.substr(start2) == s3.substr(start3);
        if (start2 == s2.length()) return s1.substr(start1) == s3.substr(start3);
        
        if (mem[start1][start2] != -1) return mem[start1][start2] == 1 ? true : false;
        
        mem[start1][start2] = ((s1[start1] == s3[start3] && isInterleave(s1, start1 + 1, s2, start2, s3, start3 + 1)) || (s2[start2] == s3[start3] && isInterleave(s1, start1, s2, start2 + 1, s3, start3 + 1))) ? 1: 0;
        
        return mem[start1][start2] == 1 ? true : false;
    }
};