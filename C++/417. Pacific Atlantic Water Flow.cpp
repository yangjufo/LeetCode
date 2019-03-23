class Solution {
public:

    vector<pair<int, int>> res;
    vector<int> mark;
    vector<int> visited;
    int O_now, height, width, length;

    void dfs(int start, const vector<vector<int>> &edges) {
        if (visited[start] == O_now)
            return;
        mark[start] += O_now;
        visited[start] = O_now;
        if (mark[start] == 3 && start != length && start != length + 1)
            res.push_back(pair<int, int>(start / width, start % width));
        for (int i = 0; i < edges[start].size(); i++) {
            dfs(edges[start][i], edges);
        }
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return res;
        vector<vector<int>> edges;
        height = static_cast<int>(matrix.size());
        width = static_cast<int>(matrix[0].size());
        length = static_cast<int>(height * width);
        const int P = length;
        const int A = length + 1;
        mark.resize(static_cast<unsigned long>(length + 2), 0);
        visited.resize(static_cast<unsigned long>(length + 2), 0);
        edges.resize(static_cast<unsigned long>(length + 2));
        int i, j;
        i = 0;
        for (j = 0; j < width; j++)
            edges[P].push_back(j);
        for (j = 1; j < width; j++) {
            if (matrix[i][j] <= matrix[i][j - 1])
                edges[j].push_back(j - 1);
            if (matrix[i][j] >= matrix[i][j - 1])
                edges[j - 1].push_back(j);
        }

        i = height - 1;
        for (j = 0; j < width; j++)
            edges[A].push_back(i * width + j);

        if (height > 1) {
            for (j = 1; j < width; j++) {
                if (matrix[i][j] <= matrix[i][j - 1])
                    edges[i * width + j].push_back(i * width + j - 1);
                if (matrix[i][j] >= matrix[i][j - 1])
                    edges[i * width + j - 1].push_back(i * width + j);
            }
        }


        j = 0;
        for (i = 0; i < height; i++)
            edges[P].push_back(i * width);
        for (i = 1; i < height; i++) {
            if (matrix[i][j] <= matrix[i - 1][j])
                edges[i * width + j].push_back((i - 1) * width + j);
            if (matrix[i][j] >= matrix[i - 1][j])
                edges[(i - 1) * width + j].push_back(i * width + j);
        }


        j = width - 1;
        for (i = 0; i < height; i++)
            edges[A].push_back(i * width + j);

        if (width > 1) {
            for (i = 1; i < height; i++) {
                if (matrix[i][j] <= matrix[i - 1][j])
                    edges[i * width + j].push_back((i - 1) * width + j);
                if (matrix[i][j] >= matrix[i - 1][j])
                    edges[(i - 1) * width + j].push_back(i * width + j);
            }
        }

        for (i = 1; i < height - 1; i++) {
            for (j = 1; j < width - 1; j++) {
                if (matrix[i][j] <= matrix[i][j - 1])
                    edges[i * width + j].push_back(i * width + j - 1);
                if (matrix[i][j] >= matrix[i][j - 1])
                    edges[i * width + j - 1].push_back(i * width + j);
                if (matrix[i][j] <= matrix[i - 1][j])
                    edges[i * width + j].push_back((i - 1) * width + j);
                if (matrix[i][j] >= matrix[i - 1][j])
                    edges[(i - 1) * width + j].push_back(i * width + j);
            }
        }

        if (height > 1) {
            i = height - 2;
            for (j = 1; j < width - 1; j++) {
                if (matrix[i][j] <= matrix[i + 1][j])
                    edges[i * width + j].push_back((i + 1) * width + j);
                if (matrix[i][j] >= matrix[i + 1][j])
                    edges[(i + 1) * width + j].push_back(i * width + j);
            }
        }

        if (width > 1) {
            j = width - 2;
            for (i = 1; i < height - 1; i++) {
                if (matrix[i][j] <= matrix[i][j + 1])
                    edges[i * width + j].push_back(i * width + j + 1);
                if (matrix[i][j] >= matrix[i][j + 1])
                    edges[i * width + j + 1].push_back(i * width + j);
            }
        }

        O_now = 1;
        dfs(P, edges);
        O_now = 2;
        dfs(A, edges);
        return res;
    }
};