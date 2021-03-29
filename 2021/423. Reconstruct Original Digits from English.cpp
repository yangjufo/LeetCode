class Solution {
public:
    vector<vector<char>> digitCount = {
        {'z', 'e', 'r', 'o'},
        {'s', 'i', 'x'},
        {'s', 'e', 'v', 'e', 'n'},
        {'e', 'i', 'g', 'h', 't'},
        {'f', 'o', 'u', 'r'},
        {'t', 'w', 'o'},        
        {'t', 'h', 'r', 'e', 'e'},        
        {'f', 'i', 'v', 'e'},        
        {'o', 'n', 'e'},                                              
        {'n', 'i', 'n', 'e'}
    };
    vector<int> nums = {0, 6, 7, 8, 4, 2, 3, 5, 1 ,9};
    string originalDigits(string s) {
        vector<int> count(26, 0);        
        for (char c : s) {
            count[c - 'a']++;
        }        
        
        string digits;        
        for (int i = 0; i <= 9; i++) {
            int j = 0, minCount = s.length();            
            for (; j < digitCount[i].size(); j++) {
                if (count[digitCount[i][j] - 'a'] <= 0) break;  
                minCount = min(minCount, count[digitCount[i][j] - 'a']);
            }            
            
            if (j >= digitCount[i].size()) {                
                for (char c : digitCount[i]) {
                    count[c - 'a'] -= minCount;
                }
                digits += string(minCount, nums[i] + '0');
            }
        }        
        
        sort(digits.begin(), digits.end());
        return digits;
    }
};
