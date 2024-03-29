class Solution {
public:
    long long countVowels(string& word) {
        long long n = word.length();
        long long res = 0;
        for (long long i = 0; i < n; i++) {                        
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                res += (i + 1) * (n - i);
            }   
        }        
        return res;
    }
};