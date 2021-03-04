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