class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> counts(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                counts[i] |= (1 << (c - 'a'));
            }
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i; j < words.size(); j++) {                            
                if ((counts[i] & counts[j]) == 0) {
                    res = max(res, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return res;
    }
};