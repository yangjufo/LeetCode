class Solution {
public:
    bool isPalindrome(string s) {        
        int begin = 0, end = s.length() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (begin < end){
            while (!(s[begin] >= 'a' && s[begin] <= 'z') && !(s[begin] >= '0' && s[begin] <= '9'))
                begin++;
            while (!(s[end] >= 'a' && s[end] <= 'z') && !(s[end] >= '0' && s[end] <= '9'))
                end--;
            if (begin >= end)
                return true;
            if (s[begin] != s[end])
                return false;
            begin++;
            end--;                
        }
        return true;
    }
};