class Solution {
public:
    vector<vector<int>> nums;
    unordered_set<int> visited;
    int m, n;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        nums.resize(m, vector<int>(n, 0));
    }
    
    vector<int> flip() {
        int row, col;
        do {
            row = rand() % m;
            col = rand() % n;
        } while (visited.find(row * n + col) != visited.end());
        visited.insert(row * n + col);
        return {row, col};
    }
    
    void reset() {
        nums.resize(m, vector<int>(n, 0));
        visited.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */