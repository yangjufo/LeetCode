class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' || i + 1 == s.size()) {
                reverse(s.begin() + start, s.begin() + ((i + 1 == s.size()) ? i + 1 : i));
                start = i + 1;
            }
        }
    }
};

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverseWord(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' || i + 1 == s.size()) {
                reverseWord(s, start, (i + 1 == s.size()) ? i : i - 1);
                start = i + 1;
            }
        }
    }
    
    void reverseWord(vector<char>& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};