class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.length();
        long long res = 0;
        vector<int> count(10, 0), pre(1024, 0);        
        pre[0] = 1;
        for (int i = 0; i < word.length(); i++) {            
            count[word[i] - 'a']++;
            int curr = 0;
            for (int j = 0; j < 10; j++) {                
                curr = (curr << 1) + ((count[j] & 0x1) == 1 ? 1 : 0);                
            }           
            res += pre[curr];
            for (int j = 0; j < 10; j++) {
                res += pre[curr ^ (1U << j)];
            }                         
            pre[curr]++;            
        }
        return res;
    }
};