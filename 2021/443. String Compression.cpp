class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;                      
        int i = 0, start = 0;
        char curr = chars[0];        
        while (i < chars.size()) {     
            int count = 0;
            while (i < chars.size() && chars[i] == curr) {
                count++;
                i++;
            }
            chars[start] = curr;            
            if (i < chars.size()) {
                curr = chars[i];
            }            
            start++;
            if (count >= 1000) {
                chars[start] = count / 1000 + '0';
                start++;                
            }
            if (count >= 100) {
                chars[start] = (count % 1000) / 100 + '0';
                start++;                
            }                
            if (count >= 10) {
                chars[start] = (count % 100) / 10 + '0';
                start++;
            } 
            if (count != 1) {
                chars[start] = (count % 10) + '0';
                start++;
            }      
        }
        return start;
    }
};