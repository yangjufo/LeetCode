class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty()) return "";
        if (words.size() == 1) return words[0];
        
        unordered_map<char, int> nodeCount;
        unordered_map<char, unordered_set<char>> edges;        
        
        for (int i = 1; i < words.size(); i++) {
            string word1 = words[i - 1], word2 = words[i];
            for (char c : word1) nodeCount[c] += 0;
            for (char c : word2) nodeCount[c] += 0;     
            int j = 0;
            while (j < word1.length() && j < word2.length() && word1[j] == word2[j])
                j++;
            if (j < word1.length() && j < word2.length() && !edges[word1[j]].count(word2[j])) {
                edges[word1[j]].insert(word2[j]);
                nodeCount[word2[j]] += 1;
            } else if (j < word1.length() && j >= word2.length()) {
                return "";
            }
        }
        
        queue<char> bfsQueue;
        for (auto const& iter : nodeCount) {           
            if (iter.second == 0) {
                bfsQueue.push(iter.first);
            }
        }                  
        
        
        string ans;
        
        while (!bfsQueue.empty()) {
            char node = bfsQueue.front();
            bfsQueue.pop();
            ans += node;
            for (char neigh : edges[node]) {
                nodeCount[neigh]--;
                if (nodeCount[neigh] == 0) {
                    bfsQueue.push(neigh);
                }
            }            
        }                        
        
        return ans.length() < nodeCount.size() ? "" : ans;
    }            
};

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> degrees;
        unordered_map<char, unordered_set<char>> edges;
        for (int i = 0; i < words.size(); i++) {
            int j = 0;
            if (i != 0) {                
                while (j < words[i - 1].length() && j < words[i].length() && words[i - 1][j] == words[i][j]) {
                    degrees[words[i][j]] += 0;                    
                    j++;
                }
                if (j < words[i - 1].length() && j >= words[i].length()) return "";
                if (j < words[i - 1].length() && edges[words[i - 1][j]].find(words[i][j]) == edges[words[i - 1][j]].end()) {
                    edges[words[i - 1][j]].insert(words[i][j]);
                    degrees[words[i][j]] += 1;
                }
            }   
            while (j < words[i].length()) {
                degrees[words[i][j]] += 0;
                j++;
            }            
        }
        string res;
        queue<char> order;
        for (auto& iter : degrees) {
            if (iter.second == 0) {
                order.push(iter.first);
            }
        }
        while (!order.empty()) {
            char curr = order.front();
            res += curr;
            order.pop();
            for (char neigh : edges[curr]) {                
                degrees[neigh]--;
                if (degrees[neigh] == 0) {
                    order.push(neigh);
                }                
            }
        }
        return res.size() < degrees.size() ? "" : res;
    }
};