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