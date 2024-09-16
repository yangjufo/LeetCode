class Solution {
public:
    void slidingWindow(string& s, int start, int totalCount,
                       unordered_map<string, int>& wordsCount,
                       vector<int>& res) {
        int wordLen = wordsCount.begin()->first.length();
        int foundCount = 0;
        bool excessWord = false;
        unordered_map<string, int> wordsFound;
        for (int end = start; end <= (int)s.length() - wordLen; end += wordLen) {
            string sub = s.substr(end, wordLen);
            if (wordsCount.find(sub) == wordsCount.end()) {
                wordsFound.clear();
                foundCount = 0;
                excessWord = false;
                start = end + wordLen;
            } else {
                while (end - start == totalCount * wordLen || excessWord) {
                    string leftMostWord = s.substr(start, wordLen);
                    start += wordLen;
                    wordsFound[leftMostWord] -= 1;
                    if (wordsFound[leftMostWord] >= wordsCount[leftMostWord]) {
                        excessWord = false;
                    } else {
                        foundCount -= 1;
                    }
                }
                wordsFound[sub] += 1;
                if (wordsFound[sub] <= wordsCount[sub]) {
                    foundCount += 1;
                } else {
                    excessWord = true;
                }
                if (foundCount == totalCount && !excessWord) {
                    res.push_back(start);
                }
            }
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordsCount;
        for (string& w : words) {
            wordsCount[w] += 1;
        }
        vector<int> res;
        for (int i = 0; i < words[0].length(); i++) {
            slidingWindow(s, i, words.size(), wordsCount,
                          res);
        }
        return res;
    }
};