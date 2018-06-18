class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.length() - 1;
        while (s[pos] == ' ' && pos > -1){
            pos--;            
        }
        int s_pos = pos;
        while (s[s_pos] != ' ' && s_pos > -1){
            s_pos--;
        }
        return pos - s_pos;
    }
};