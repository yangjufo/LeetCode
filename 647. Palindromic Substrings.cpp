class Solution {   
    int count;
public:
    int countSubstrings(string s) {
        count = 0;
        for(int i = 0; i < s.length(); i++){
            countSubstrings(s, i, i);
            countSubstrings(s, i, i + 1);
        }
        return count;
    } 
    
private:
    void countSubstrings(string s, int left, int right){
        while(left > -1 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
    }
};