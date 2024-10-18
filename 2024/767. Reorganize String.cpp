class Solution {
public:
    string reorganizeString(string s) {
        vector<int> counts(26);
        for (char c : s) {
            counts[c - 'a'] += 1;
        }
        vector<array<int, 2>> sorted_counts(26);
        for (int i = 0; i < 26; i++) {
            sorted_counts[i] = {counts[i], i};
        }
        sort(sorted_counts.begin(), sorted_counts.end(),
             [](array<int, 2>& left, array<int, 2>& right) {
                 return left[0] > right[0];
             });
        string res = s;
        int index = 0;
        for (int i = 0; i < res.size(); i += 2) {
            while (sorted_counts[index][0] <= 0) {
                index += 1;
            }
            sorted_counts[index][0] -= 1;
            res[i] = sorted_counts[index][1] + 'a';
        }
        for (int i = 1; i < res.size(); i += 2) {
            while (sorted_counts[index][0] <= 0) {
                index += 1;
            }
            sorted_counts[index][0] -= 1;
            res[i] = sorted_counts[index][1] + 'a';
            if (i > 0 && res[i] == res[i - 1] ||
                i < res.size() && res[i] == res[i + 1]) {
                return "";
            }
        }
        return res;
    }
};