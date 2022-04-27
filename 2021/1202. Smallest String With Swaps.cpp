class Solution {
public:
    vector<int> parents, ranks;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for (int i = 0; i < s.length(); i++) {
            parents.push_back(i);
            ranks.push_back(0);
        }
        for (vector<int>& pair : pairs) {
            merge(pair[0], pair[1]);
        }

        unordered_map<int, vector<int>> counts;
        for (int i = 0; i < s.length(); i++) {
            parents[i] = find(parents[i]);
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

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void merge(int a, int b) {
        int pA = find(a), pB = find(b);
        if (pA == pB) return;
        if (ranks[pA] > ranks[pB]) {
            parents[pB] = pA;
        } else {
            parents[pA] = pB;
            if (ranks[pA] == ranks[pB]) {
                ranks[pB]++;
            }
        }
    }
};