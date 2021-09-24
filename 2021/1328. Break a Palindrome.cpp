class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.length() <= 1) return "";
        for (int i = 0; i < palindrome.length(); i++) {
            if (palindrome[i] != 'a') {
                if (palindrome.length() % 2 == 0 || i != palindrome.length() / 2) {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }                                            
        }
        palindrome.back() = 'b';
        return palindrome;
    }
};