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
    int read(char *buf, int n) {
        char buf4[4];
        int index = 0;
        while (index < n) {
            int count = read4(buf4);            
            if (count == 0) {
                return index;
            }            
            for (int i = 0; i < count && index + i < n; i++ ) {
                buf[index + i] = buf4[i];
            }    
            index += count;
        }                
        return n;
    }
};