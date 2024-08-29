class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.length() <= haystack.length(); i++) {
            int j = 0;
            while (j < needle.length() && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j >= needle.length()) {
                return i;
            }
        }
        return -1;
    }
};