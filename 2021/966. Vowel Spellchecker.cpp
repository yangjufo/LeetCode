class Solution {
public:    
    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, int> capMap, vowelMap;
        
        for (int i = 0; i < wordList.size(); i++) {
            string lower = toLowerCase(wordList[i]);
            if (capMap.find(lower) == capMap.end()) {
                capMap[lower] = i;
            }
            string deVowelStr = deVowel(lower);
            if (vowelMap.find(deVowelStr) == vowelMap.end()) {
                vowelMap[deVowelStr] = i;
            }
        }
        
        vector<string> res;
        for (string& query : queries) {            
            string lower = toLowerCase(query), deVowelStr = deVowel(lower);  
            if (wordSet.find(query) != wordSet.end()) {
                res.push_back(query);
            } else if (capMap.find(lower) != capMap.end()) {                
                res.push_back(wordList[capMap[lower]]);
            } else if (vowelMap.find(deVowelStr) != vowelMap.end()) {
                res.push_back(wordList[vowelMap[deVowelStr]]);
            } else {
                res.push_back("");
            }
        }
        return res;            
    }
    
    string toLowerCase(string& original) {
        string lower;
        for (auto c : original) {
            lower += tolower(c);
        }
        return lower;
    }      
    
    string deVowel(string& original) {
        string deVowelStr;
        for (auto c : original) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                deVowelStr += '*';
            } else {
                deVowelStr += c;
            }
        }
        return deVowelStr;
    }
};