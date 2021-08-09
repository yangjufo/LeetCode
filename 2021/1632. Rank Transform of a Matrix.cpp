class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // link row to col, and link col to row
        unordered_map<int, unordered_map<int, vector<int>>> graphs;
        // graphs[v]: the connection graph of value v
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = matrix[i][j];
                auto& graph = graphs[v];
                // link i to j, and link j to i
                graph[i].push_back(~j);
                graph[~j].push_back(i);
            }
        }

        // put points into `value2index` dict, grouped by connection
        // use ordered map to help us sort the key automatically
        map<int, vector<vector<pair<int, int>>>> value2index;
        // mark whether put into `value2index` or not
        vector<vector<int>> seen(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (seen[i][j] == 1) {
                    continue;
                }
                seen[i][j] = 1;
                int v = matrix[i][j];
                auto graph = graphs[v];
                // store visited row and col
                unordered_set<int> rowcols{i, ~j};
                // start bfs
                queue<int> q;
                q.push(i);
                q.push(~j);
                while (!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    for (int rowcol : graph[node]) {
                        if (rowcols.count(rowcol) == 0) {
                            rowcols.insert(rowcol);
                            q.push(rowcol);
                        }
                    }
                }
                // transform rowcols into points
                vector<pair<int, int>> points;
                for (auto rowcol : rowcols) {
                    for (auto k : graph[rowcol]) {
                        if (k >= 0) {
                            points.push_back({k, ~rowcol});
                            seen[k][~rowcol] = 1;
                        } else {
                            points.push_back({rowcol, ~k});
                            seen[rowcol][~k] = 1;
                        }
                    }
                }
                value2index[v].push_back(points);
            }
        }

        // the required rank matrix
        vector<vector<int>> answer(m, vector<int>(n));
        vector<int> rowMax(m);  // rowMax[i]: the max rank in i row
        vector<int> colMax(n);  // colMax[j]: the max rank in j col
        for (auto v : value2index) {
            // update by connected points with same value
            for (auto points : v.second) {
                int rank = 1;
                for (auto point : points) {
                    rank =
                        max(rank,
                            max(rowMax[point.first], colMax[point.second]) + 1);
                }
                for (auto point : points) {
                    answer[point.first][point.second] = rank;
                    // update rowMax and colMax
                    rowMax[point.first] = max(rowMax[point.first], rank);
                    colMax[point.second] = max(colMax[point.second], rank);
                }
            }
        }
        return answer;
    }
};
