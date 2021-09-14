class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banSet(banned.begin(), banned.end());
        string word;
        paragraph += " ";
        unordered_map<string, int> counter;
        for (char c : paragraph) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                word += tolower(c);
            } else {
                if (!word.empty() && banSet.find(word) == banSet.end()) {
                    counter[word]++;
                }
                word.clear();
            }
        }
        int maxCount = 0;
        string res;
        for (auto& iter : counter) {
            if (iter.second > maxCount) {
                res = iter.first;
                maxCount = iter.second;
            }
        }
        return res;
    }
};