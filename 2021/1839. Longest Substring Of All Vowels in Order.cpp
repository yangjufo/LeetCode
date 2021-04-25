class Solution {
public:
    unordered_map<char, int> indexes = {
        {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}  
    };
    int longestBeautifulSubstring(string word) {        
        int start = 0, maxLen = 0;
        vector<int> counts(5, 0);
        for (int i = 0; i < word.length(); i++) {            
            counts[indexes[word[i]]]++;
            while (start < i && !valid(counts, indexes[word[i]])) {
                counts[indexes[word[start]]]--;
                start++;
            }            
            if (word[i] == 'u' && 
            valid(counts, indexes[word[i]])) {                
                maxLen = max(maxLen, i - start + 1);
            }
        }
        return maxLen;
    }
    
    bool valid(vector<int>& counts, int index) {
        for (int i = index + 1; i < 5; i++) {
            if (counts[i] != 0) return false;
        }
        if (index == 4) {
            for (int i = 0; i < 5; i++) {
                if (counts[i] == 0) return false;
            }
        }        
        return true;
    }
};
