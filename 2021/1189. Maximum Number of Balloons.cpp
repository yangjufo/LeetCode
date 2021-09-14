class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
        for (char c : text) {
            count[c - 'a']++; 
        }        
        return min(min(count['b' - 'a'], count['a' - 'a']), min(min(count['l' - 'a'] / 2, count['o' - 'a'] / 2), count['n' - 'a']));        
    }
};