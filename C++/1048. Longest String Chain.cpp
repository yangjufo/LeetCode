class Solution {
public:
    int maxLen;
    void dfs (vector<vector<string>>& dicts, string last, int i, int len) {
        // cout << i << " " << last << " "<< len << endl;
        maxLen = max(maxLen, len);
        for (int j = 0; i < dicts.size() && j < dicts[i].size(); j++) {            
            string now = dicts[i][j];            
            int k = 0, l = 0;            
            while (k < now.length() && l < last.length()) {
                if (now[k] == last[l]) {
                    k++;
                    l++;
                }
                else 
                    k++;                
            }
            if (l == last.length())
                dfs(dicts, now, i + 1, len + 1);            
        }
    }
    
    int longestStrChain(vector<string>& words) {
        maxLen = 0;
        vector<vector<string>> wordicts;        
        for (string word : words) {
            while (word.length() > wordicts.size()) {
                wordicts.push_back(vector<string>{});
            }
            sort(word.begin(), word.end());
            wordicts[word.length() - 1].push_back(word);
        }
        // for (int i = 0; i < wordicts.size(); i++) {
        //     for (int j = 0; j < wordicts[i].size(); j++) {
        //         cout << wordicts[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < wordicts.size(); i++) {              
            if (!wordicts[i].empty()) {
                for (int j = 0; j < wordicts[i].size(); j++) {
                    dfs(wordicts, wordicts[i][j], i + 1, 1);
                }
            }            
        }
            
        return maxLen;
    }
        
};