class Solution {
    int changeCount;
public:
    bool validPalindrome(string s) {
        changeCount = 0;
        if (s.empty()){
            return true;
        }
        return validPalindrome(s, 0, s.length() - 1);
    }
    
private:
    bool validPalindrome(string s, int start, int end)
    {
        int i = start;
        int j = end;
        while (s[i] == s[j] && i < j){            
            i++;
            j--;
        }
        if (i >= j){
            return true;
        }
        if (s[i] == s[j - 1] && s[i+1] == s[j] && changeCount == 0){
            changeCount = 1;
            return validPalindrome(s, i, j - 1) || validPalindrome(s, i+1, j);
        }        
        else if (s[i] == s[j - 1] && changeCount == 0){
            changeCount = 1;
            return validPalindrome(s, i, j - 1);
        }
        else if (s[i+1] == s[j] && changeCount == 0){
            changeCount = 1;
            return validPalindrome(s, i + 1, j);
        }
        return false;
    }
    
};