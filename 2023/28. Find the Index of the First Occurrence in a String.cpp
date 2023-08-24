class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= (int)haystack.length() - (int)needle.length(); i++) {
            int j = 0;
            while (j < needle.length() && needle[j] == haystack[i + j]) {
                j++;
            }
            if (j >= needle.length()) {
                return i;
            }
        }
        return -1;
    }
};