class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.erase(beginWord);
        return bfs(wordSet, beginWord, endWord);
    }
    
    int bfs(unordered_set<string>& wordSet, string beginWord, string endWord) {
        queue<string> queue;
        queue.push(beginWord);
        int distance = 1;        
        while (!queue.empty()) {
            distance++;
            int size = queue.size();            
            for (int i = 0; i < size; i++) {
                string currWord = queue.front();
                queue.pop();
                for (string neighbor : getNeighbors(wordSet, currWord)) {
                    if (neighbor == endWord) return distance;
                    queue.push(neighbor);
                    wordSet.erase(neighbor);
                }
            }
        }
        return 0;
    }
    
    vector<string> getNeighbors(unordered_set<string>& wordSet, string word) {
        vector<string> neighbors;
        for (int i = 0; i < word.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                char oldChar = word[i];
                word[i] = c;
                if (c != oldChar && wordSet.find(word) != wordSet.end()) {
                    neighbors.push_back(word);
                }
                word[i] = oldChar;
            }
        }   
        return neighbors;
    }
};