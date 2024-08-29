class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            string word;
            while (i < s.length() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        reverse(words.begin(), words.end());
        string res;
        for (string& word : words) {
            res += word + " ";
        }
        return res.substr(0, res.length() - 1);
    }
};

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        reverse(s.begin() + start, s.end());
        int index = 0;
        for (char c : s) {
            if (c != ' ' || (index != 0 && s[index - 1] != ' ')) {
                s[index] = c;
                index += 1;
            }
        }
        if (index > 0 && s[index - 1] == ' ') {
            index--;
        }
        return s.substr(0, index);
    }
};