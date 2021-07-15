class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> orderIndexes(26, 27);
        for (int i = 0; i < order.length(); i++) {
            orderIndexes[order[i] - 'a'] = i;
        }
        sort(str.begin(), str.end(), [&](char l, char r) {
            return orderIndexes[l - 'a'] < orderIndexes[r - 'a'];
        });
        return str;
    }
};

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> count(26, 0);
        for (char c : str) {
            count[c - 'a']++;
        }
        string res;
        for (char c : order) {
            res += string(count[c - 'a'], c);
            count[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                res += string(count[i], i + 'a');
            }
        }
        return res;
    }
};