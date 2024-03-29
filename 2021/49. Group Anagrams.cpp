class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anaMap;
        vector<int> count(26, 0);
        for (auto const& s : strs) {
            for (char c : s) {
                count[c - 'a']++;
            }
            
            string index;
            for (int i = 0; i < 26; i++) {
                index += string(count[i], i + 'a');
                count[i] = 0;
            }
            
            anaMap[index].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto const& iter : anaMap) {
            res.push_back(iter.second);
        }
        
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& iter : groups) {
            res.push_back(iter.second);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& iter : groups) {
            res.push_back(iter.second);
        }
        return res;
    }
};