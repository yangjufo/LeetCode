class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> indexes;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                indexes.push_back(i);
            }
        }
        if (indexes.empty()) return true;
        if (indexes.size() != 2) return false;
        if (s1[indexes[0]] != s2[indexes[1]] || s1[indexes[1]] != s2[indexes[0]]) return false;
        return true;
    }
};