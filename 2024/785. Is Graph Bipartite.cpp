class Solution {
public:
    int find(vector<int>& parents, int x) {
        if (parents[x] != x) {
            parents[x] = find(parents, parents[x]);
        }
        return parents[x];
    }

    void merge(vector<int>& parents, vector<int>& ranks, int x, int y) {
        int px = find(parents, x), py = find(parents, y);
        if (px == py) {
            return;
        }
        if (ranks[px] > ranks[py]) {
            parents[py] = px;
        } else {
            parents[px] = py;
            if (ranks[px] == ranks[py]) {
                ranks[py] += 1;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> parents(n, 0), ranks(n, 0);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int n : graph[i]) {
                if (find(parents, i) == find(parents, n)) {
                    return false;
                }
                merge(parents, ranks, graph[i][0], n);
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        for (int i = 0; i < n; i++) {
            if (colors[i] != 0) {
                continue;
            }
            colors[i] = 1;
            queue<int> queue;
            queue.push(i);
            while (!queue.empty()) {
                int curr = queue.front();
                queue.pop();
                for (int neigh : graph[curr]) {
                    if (colors[neigh] == 0) {
                        colors[neigh] = 3 - colors[curr];
                        queue.push(neigh);
                    } else if (colors[neigh] == colors[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};