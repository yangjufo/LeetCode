class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty()) return needle.empty() ? 0 : -1;
        for (int i = 0; i < haystack.size(); i++) {
            int j = 0;
            while (j < needle.size() && i + j < haystack.size() && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i < m - n + 1; i++) {
            if (haystack.substr(i, n) == needle) return i;
        }
        return -1;
    }
};