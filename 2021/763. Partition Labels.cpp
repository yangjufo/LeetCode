class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> firstIndex(26, -1), lastIndex(26, -1);
        for (int i = 0; i < s.length(); i++) {
            if (firstIndex[s[i] - 'a'] < 0) {
                firstIndex[s[i] - 'a'] = i;
            }
            lastIndex[s[i] - 'a'] = i;
        }        
        vector<int> res;
        int start = 0, end = 0;
        while (start < s.length()) {
            int i = start, end = lastIndex[s[i] - 'a'];
            while (i < end) {
                end = max(end, lastIndex[s[i] - 'a']);
                i++;
            }            
            res.push_back(end - start + 1);
            start = end + 1;
        }
        return res;
    }
};