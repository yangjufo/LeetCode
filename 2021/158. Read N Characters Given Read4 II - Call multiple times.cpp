/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char* buf4 = new char[4];
    int index = 0, bytes = 0;
    int read(char *buf, int n) {        
        int count = 0, i = 0;
        while (count < n) {
            if (index == bytes) {
                index = 0;
                bytes = read4(buf4);                
                if (bytes == 0){
                    return count;
                }                
            }
            while (index < bytes && count < n) {
                buf[i] = buf4[index];
                index++;
                count++;
                i++;
            }      
        }
        return count;
    }        
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int starIdx = -1, sTmpIdx = -1;
        int sIdx = 0, pIdx = 0;
        while (sIdx < s.length()) {
            if (pIdx < p.length() && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            } else if (pIdx < p.length() && p[pIdx] == '*') {
                starIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++;
            } else if (starIdx == -1) {
                return false;
            } else {
                pIdx = starIdx + 1;
                sIdx = sTmpIdx + 1;
                sTmpIdx = sIdx;
            }
        }
        
        for (int i = pIdx; i < p.length(); i++) {
            if (p[i] != '*') return false;
        }
        
        return true;
    }
};