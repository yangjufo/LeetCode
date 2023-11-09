class Solution {
public:
    int find(vector<int>& parents, int v) {
        if (parents[v] != v) {
            parents[v] = find(parents, parents[v]);
        }
        return parents[v];
    }

    void merge(vector<int>& parents, vector<int>& ranks, int x, int y) {
        int px = find(parents, x), py = find(parents, y);
        if (px != py) {
            if (ranks[px] > ranks[py]) {
                parents[py] = px;
            } else {
                parents[px] = py;
                if (ranks[px] == ranks[py]) {
                    ranks[py] += 1;
                }
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> parents, ranks;
        for (int i = 0; i < s.length(); i++) {
            parents.push_back(i);
            ranks.push_back(0);
        }
        for (vector<int>& p : pairs) {
            merge(parents, ranks, p[0], p[1]);
        }
        unordered_map<int, vector<int>> counts;
        for (int i = 0; i < s.length(); i++) {
            parents[i] = find(parents, parents[i]);
            if (counts.find(parents[i]) == counts.end()) {
                counts[parents[i]].resize(26);
            }
            counts[parents[i]][s[i] - 'a']++;
        }
        string res;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 26; j++) {
                if (counts[parents[i]][j] > 0) {
                    res += j + 'a';
                    counts[parents[i]][j]--;
                    break;
                }
            }
        }
        return res;
    }
};