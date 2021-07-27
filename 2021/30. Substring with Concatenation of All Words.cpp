class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {        
        unordered_map<string, int> counts;
        vector<int> indexes;        
        int num = words.size(), len = words[0].length(), n = s.length();
        for (string w : words) {
            counts[w]++;
        }
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string curr = s.substr(i + j * len, len); 
                if (counts.find(curr) == counts.end() || seen[curr] + 1 > counts[curr]) {
                    break;
                }
                seen[curr]++;
            }
            if (j == num) {
                indexes.push_back(i);
            }
        }
        return indexes;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int num = words.size(), len = words[0].length(), n = s.length();
        unordered_map<string, int> counts;        
        for (string& w : words) {
            counts[w]++;
        }
        
        vector<int> indexes;
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string curr = s.substr(i + j * len, len);
                if (counts.find(curr) == counts.end() || seen[curr] + 1 > counts[curr]) {
                    break;
                }
                seen[curr]++;
            }
            if (j == num) {
                indexes.push_back(i);
            }
        }
        return indexes;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size(), n = words[0].length();
        unordered_map<string, int> wordMap;
        for (string w : words) {
            wordMap[w]++;
        }        
        vector<int> res;
        for (int i = 0; i < (int)s.length() - m * n + 1; i++) {
            if (wordMap.find(s.substr(i, n)) != wordMap.end()) {
                int j = i, count = 0;
                unordered_map<string, int> wordCount;
                while (j < s.length() && count < m) {
                    string w = s.substr(j, n);                    
                    if (wordCount[w] < wordMap[w]) {
                        wordCount[w]++;
                        count++;
                    } else {
                        break;
                    }
                    j += n;
                }
                if (count >= m) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};