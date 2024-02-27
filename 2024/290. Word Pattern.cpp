class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> pm;
        unordered_map<string, int> sm;
        int pos = 0, prev = -1, index = 0;
        while(pos < s.length() && index < pattern.length()){
            pos = s.find(" ", prev + 1);
            string word = s.substr(prev + 1, pos - prev - 1);
            if (pm.find(pattern[index]) == pm.end()) {
                pm[pattern[index]] = index;
            }
            if (sm.find(word) == sm.end()) {
                sm[word] = index;
            }
            if (pm[pattern[index]] != sm[word]) {
                return false;
            }
            index += 1;
            prev = pos;
        }
        return index >= pattern.length() && pos >= s.length();
    }
};