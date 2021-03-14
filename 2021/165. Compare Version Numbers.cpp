class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.length() || j < version2.length()) {
            int v1 = 0, v2 = 0;
            if (i < version1.length()) {
                int dot = version1.find(".", i);
                if (dot == string::npos) {
                    v1 = stoi(version1.substr(i));
                    i = version1.length();
                } else {
                    v1 = stoi(version1.substr(i, dot - i));
                    i = dot + 1;
                }                
            }
            if (j < version2.length()) {
                int dot = version2.find(".", j);
                if (dot == string::npos) {
                    v2 = stoi(version2.substr(j));
                    j = version2.length();
                } else {                    
                    v2 = stoi(version2.substr(j, dot - j));
                    j = dot + 1;
                }                
                
            }
            if (v1 != v2) return v1 > v2 ? 1 : -1;
        }
        return 0;
    }
};