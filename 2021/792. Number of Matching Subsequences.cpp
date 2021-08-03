class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indexes(26);
        for (int i = 0; i < s.length(); i++) {
            indexes[s[i] - 'a'].push_back(i);
        }
        
        int count = 0;
        for (string& word : words) {
            int pos = -1, i = 0;
            for (;i < word.length(); i++) {                
                if (indexes[word[i] - 'a'].empty()) break;
                auto iter = upper_bound(indexes[word[i] - 'a'].begin(), indexes[word[i] - 'a'].end(), pos);
                if (iter == indexes[word[i] - 'a'].end()) break;
                pos = *iter;
            }    
            if (i >= word.length()) {
                count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indexes(26);
        for (int i = 0; i < s.length(); i++) {
            indexes[s[i] - 'a'].push_back(i);
        }
        
        int count = 0;
        for (string& word : words) {
            int pos = -1, i = 0;
            for (; i < word.length(); i++) {
                if (indexes[word[i] - 'a'].empty()) break;
                auto iter = upper_bound(indexes[word[i] - 'a'].begin(), indexes[word[i] - 'a'].end(), pos);
                if (iter == indexes[word[i] - 'a'].end()) break;
                pos = *iter;
            }
            if (i >= word.length()) {
                count++;
            }
        }
        return count;
    }
};