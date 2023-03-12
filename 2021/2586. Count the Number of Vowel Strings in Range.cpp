class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = left; i <= right; i++) {
            string& w = words[i];
            if (vowels.find(w[0]) != vowels.end() && vowels.find(w.back()) != vowels.end()) {
                count++;
            }
        }
        return count;
    }
};