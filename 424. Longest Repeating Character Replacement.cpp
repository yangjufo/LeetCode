class Solution {
public:
    int characterReplacement(string s, int k) {        
        if (s.length() == 0)
            return 0;
        vector<int> map(128, 0);        
        int begin = 0, end = 0, d = 0;
        int max_count = 0;
        while(end < s.length()){                              
            max_count = max(max_count, ++map[s[end]]);
            while (end - begin + 1 - max_count > k){
                map[s[begin]]--;
                begin++;
            }
            d = max(end - begin + 1, d);
            end++;
        }        
        return d;    
    }
};