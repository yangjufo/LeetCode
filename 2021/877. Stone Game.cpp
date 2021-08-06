class Solution {
public:    
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> mem(piles.size(), vector<int>(piles.size(), 0));
        int sum = 0;
        for (int p : piles) {
            sum += p;
        }
        pick(piles, 0, (int)piles.size() - 1, mem);
        return mem[0][(int)piles.size() - 1] > sum / 2;
    }
    
    int pick(vector<int>& piles, int left, int right, vector<vector<int>>& mem) {
        if (left > right) return 0;
        if (mem[left][right] > 0) return mem[left][right];
        int leftScore = pick(piles, left + 1, right, mem) + piles[left];
        int rightScore = pick(piles, left, right - 1, mem) + piles[right];
        mem[left][right] = max(leftScore, rightScore);
        return mem[left][right];
    }
};