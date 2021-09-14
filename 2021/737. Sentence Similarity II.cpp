class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& a, vector<string>& b, vector<vector<string>>& similarPairs) {
      if (a.size() != b.size()) return false;
        unordered_map<string, string> m;
        for (auto& p : similarPairs) {
            string parent1 = find(m, p[0]), parent2 = find(m, p[1]);
            if (parent1 != parent2) m[parent1] = parent2;
        }

        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && find(m, a[i]) != find(m, b[i])) return false;

        return true;
    }

private:
    string find(unordered_map<string, string>& m, string s) {
        return !m.count(s) ? m[s] = s : (m[s] == s ? s : find(m, m[s]));
    }
};