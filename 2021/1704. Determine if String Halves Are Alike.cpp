class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int leftCount = 0, rightCount = 0;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (vowelSet.count(s[i])) leftCount++;
            i++;
            if (vowelSet.count(s[j])) rightCount++;
            j--;
        }
        return leftCount == rightCount;
    }
};

class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool halvesAreAlike(string s) {
        int leftCount = 0, rightCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                if (i >= s.length() / 2) {
                    rightCount++;
                } else {
                    leftCount++;
                }
            }
        }
        return leftCount == rightCount;
    }
};