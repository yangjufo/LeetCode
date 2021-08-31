class Solution {
public:
    int repeatedStringMatch(string a, string b) {        
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == b[0]) {
                int j = 0, k = 0;
                while (k < b.length() && a[(i + j) % a.length()] == b[k]) {
                    k++;
                    j++;
                }
                if (k >= b.length()) {
                    return ( i + j + a.length() - 1) / a.length();
                }
            }
        }
        return -1;
    }
};