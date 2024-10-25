class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> indexes;
        for (int i = 0; i < order.length(); i++) {
            indexes[order[i]] = i;
        }
        vector<int> counts(order.size());
        vector<int> remaining(26);
        for (char c : s) {
            if (indexes.find(c) != indexes.end()) {
                counts[indexes[c]] += 1;
            } else {
                remaining[c - 'a'] += 1;
            }
        }
        string res;
        for (int i = 0; i < counts.size(); i++) {
            res += string(counts[i], order[i]);
        }
        for (int i = 0; i < remaining.size(); i++) {
            res += string(remaining[i], i + 'a');
        }
        return res;
    }
};

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> counts(26);
        for (char c : s) {
            counts[c - 'a'] += 1;
        }
        string res;
        for (char c : order) {
            res += string(counts[c - 'a'], c);
            counts[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; i++) {
            res += string(counts[i], i + 'a');
        }
        return res;
    }
};