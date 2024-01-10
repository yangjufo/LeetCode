class Solution {
public:
    int find(unordered_map<int, int>& parents, int x) {
        if (parents[x] != x) {
            parents[x] = find(parents, parents[x]);
        }
        return parents[x];
    }

    void merge(unordered_map<int, int>& parents, unordered_map<int, int>& ranks, int x, int y) {
        int px = find(parents, x), py = find(parents, y);
        if (px == py) {
            return;
        }
        if (ranks[px] > ranks[py]) {
            parents[py] = px;
            ranks[px] += ranks[py];
        } else {
            parents[px] = py;
            ranks[py] += ranks[px];
        }
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> parents, ranks;
        for (int n : nums) {
            parents[n] = n;
            ranks[n] = 1;
        }
        for (int n : nums) {
            if (ranks.find(n - 1) != ranks.end()) {
                merge(parents, ranks, n, n - 1);
            }
            if (ranks.find(n + 1) != ranks.end()) {
                merge(parents, ranks, n, n + 1);
            }
        }
        int ans = 0;
        for (int n : nums) {
            ans = max(ans, ranks[n]);
        }
        return ans;
    }
};