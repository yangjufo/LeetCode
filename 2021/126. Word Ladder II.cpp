class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<vector<string>> paths;
        vector<string> visited;
        vector<vector<string>> res;
        
        int minLen = wordList.size() + 2;
        int len = 1;
        
        paths.push({ beginWord });
        
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > len) {
                for (string word : visited) {
                    wordSet.erase(word);
                }
                visited.clear();
                if (path.size() > minLen) {
                    break;
                }
                len = path.size();
            }
            
            string curr = path.back();
            for (int i = 0; i < curr.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    curr[i] = c;
                    if (wordSet.find(curr) != wordSet.end()) {
                        path.push_back(curr);
                        if (curr == endWord) {
                            minLen = len;
                            res.push_back(path);
                        }
                        else {
                            paths.push(path);
                        }   
                        path.pop_back();
                        
                        visited.push_back(curr);
                    }
                    curr[i] = path.back()[i];
                }
            }
        }
        return res;
        
    }
};