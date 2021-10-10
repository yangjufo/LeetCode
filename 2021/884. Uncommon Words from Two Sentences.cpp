class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {        
        unordered_map<string, int> count;
        split(s1, count);
        split(s2, count);
        vector<string> res;
        for (auto& iter : count) {
            if (iter.second == 1) {
                res.push_back(iter.first);
            }
        }
        return res;
    }
    
    void split(string& s, unordered_map<string, int>& count) {        
        int i = 0;
        while (i < s.length()) {
            int next = s.find(" ", i);
            count[s.substr(i, next - i)]++;
            if (next == string::npos) {
                break;
            }
            i = next + 1;            
        }      
    }
};