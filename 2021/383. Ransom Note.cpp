class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>count(26, 0);
        for (char c : ransomNote) {
            count[c - 'a']++;
        }
        for (char c : magazine) {
            count[c - 'a']--;
        }
        for (int n : count) {
            if (n > 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> mCount;
        for (char c : magazine) {
            mCount[c]++;
        }
        for (char c : ransomNote) {
            mCount[c]--;
            if (mCount[c] < 0) {
                return false;
            }
        }
        return true;
    }
};