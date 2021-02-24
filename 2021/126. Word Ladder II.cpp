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

class Solution {
public:    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());        
        queue<vector<string>> paths;
        vector<string> visited;
        vector<vector<string>> res;
        
        int minLen = wordList.size() + 2;        
        int len = 1;
        
        paths.push({beginWord});
        
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            
            if (path.size() > minLen) {
                break;
            }
            
            if (path.size() > len) {
                for (string word : visited) {
                    wordSet.erase(word);
                }
                visited.clear();                                
                len = path.size();                
            }
            
            string curr = path.back();
            for (int i = 0; i < curr.size(); i++) {
                for (auto c = 'a'; c < 'z'; c++) {
                    curr[i] = c;
                    if (wordSet.find(curr) != wordSet.end()) {
                        path.push_back(curr);
                        if (curr == endWord) {
                            minLen = len;
                            res.push_back(path);
                        } else {
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


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<vector<string>> pathQueue;
        vector<vector<string>> res;
        
        int minLen = wordList.size() + 2;
        int len = 1;
        unordered_set<string> visited;
        
        pathQueue.push({ beginWord });
        while (!pathQueue.empty()) {
            vector<string> currPath = pathQueue.front();
            pathQueue.pop();
            
            if (currPath.size() > minLen) {
                break;
            }
            
            if (currPath.size() > len) {
                for (string word : visited) {
                    wordSet.erase(word);
                }
                visited.clear();
                
                len = currPath.size();                
            }
            
            string currWord = currPath.back();
            for (int i = 0; i < currWord.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    currWord[i] = c;
                    if (wordSet.find(currWord) != wordSet.end()) {
                        currPath.push_back(currWord);
                        if (currWord == endWord) {
                            minLen = len;
                            res.push_back(currPath);
                        } else {
                            pathQueue.push(currPath);
                        }
                        
                        currPath.pop_back();
                        visited.insert(currWord);
                    }
                    currWord[i] = currPath.back()[i];
                }
            }
        }
        return res;
    }
};